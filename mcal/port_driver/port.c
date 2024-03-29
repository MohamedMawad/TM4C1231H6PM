
/*
 * port.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Mustafa Sayed
 */
#define MAX_NUM_OF_CH_IN_PORT       8

#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"
#include "../../config/port_cfg.h"
#include "../mcu_hw.h"
#include "port_types.h"
#include "port.h"

extern Port_CfgType PortCfgArr[];

void PORT_init(void)
{
    uint8 i;
    Port_IdType PortId;
    Port_ChIdType ChId;
    PORTA_REG_SET = 0xFFFFFFFF;
    volatile PORT_RegType* PORT_Addr;
    for (i = 0; i < PORT_NUM_OF_ACTIVATED_CH; ++i)
    {
        PortId = i/ MAX_NUM_OF_CH_IN_PORT;
        ChId = i % MAX_NUM_OF_CH_IN_PORT;

        switch (PortId)
        {
        case Port_Id_A:
            PORT_Addr = &PORTA_REG;
            break;
        case Port_Id_B:
            PORT_Addr = &PORTB_REG;
            break;
        case Port_Id_C:
            PORT_Addr = &PORTC_REG;
            break;
        case Port_Id_D:
            /*TODO: Assign PORTD address to PORT_Addr variable ///Done/// */
            PORT_Addr = &PORTD_REG;
            break;
        case Port_Id_E:
            PORT_Addr = &PORTE_REG;
            break;
        case Port_Id_F:
            PORT_Addr = &PORTF_REG;
            break;
        }

        /*TODO: set channel direction ///Done/// */

            if(PortCfgArr[i].Dir == port_Dir_Output)
            {
               SET_BIT(PORT_Addr->GPIODIR, ChId);
            }
            else
            {
                CLR_BIT(PORT_Addr->GPIODIR, ChId);
            }

        /*TODO: set channel mode ///Need to be completed/// */
            if(PortCfgArr[i].Mode == PORT_MODE_PIN_X_DIO)
            {
                CLR_BIT(PORT_Addr->GPIOAFSEL, ChId);
            }
            else
            {
                /* Continue Configuration*/
            }

        /*TODO: set Interrupt configuration //Done// */
            if(PortCfgArr[i].Interrupt == Port_IntDisable)
            {
                CLR_BIT(PORT_Addr->GPIOIM, ChId);
            }
            else
            {
                /* SET_BIT(PORT_Addr->GPIOIM, ChId);*/
                /* Continue Configuration*/
            }

        /*TODO: set Internal Attachment configuration //Done// */
            if(PortCfgArr[i].AttachedRes == Port_InternalAttach_PullUpRes)
            {
                SET_BIT(PORT_Addr->GPIOPUR, ChId);
            }
            else if (PortCfgArr[i].AttachedRes == Port_InternalAttach_PullDownRes)
            {
                SET_BIT(PORT_Addr->GPIOPDR, ChId);
            }
            else if (PortCfgArr[i].AttachedRes == Port_InternalAttach_OpenDrain)
            {
                SET_BIT(PORT_Addr->GPIOODR, ChId);
            }
            else
            {
                CLR_BIT(PORT_Addr->GPIOPUR, ChId);
                CLR_BIT(PORT_Addr->GPIOPDR, ChId);
                CLR_BIT(PORT_Addr->GPIOODR, ChId);
            }


        /*TODO: set current strength configuration //Done// */
            if(PortCfgArr[i].CurrentDrive == Port_CurrDrive_2mA)
            {
                SET_BIT(PORT_Addr->GPIODR2R, ChId);
            }
            else if (PortCfgArr[i].AttachedRes == Port_CurrDrive_4mA)
            {
                SET_BIT(PORT_Addr->GPIODR4R, ChId);
            }
            else
            {
                SET_BIT(PORT_Addr->GPIODR8R, ChId);
            }


        /*Check if analog functionality is required*/
        if(PortCfgArr[i].Mode != Port_Mode_AIN )
        {
            /*TODO: enable digital and disable ADC  //Done// */
            SET_BIT(PORT_Addr->GPIODEN, ChId);
            CLR_BIT(PORT_Addr->GPIOADCCTL, ChId);
        }
        else
        {
            /*TODO: disable digital and enable ADC //Done// */
            SET_BIT(PORT_Addr->GPIOADCCTL, ChId);
            CLR_BIT(PORT_Addr->GPIODEN, ChId);
        }
    }
}
