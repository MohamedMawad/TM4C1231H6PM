################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
mcal/port_driver/%.obj: ../mcal/port_driver/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/M_Moawad/workspace_v8/GPIO_TM4C" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.4.LTS/include" --define=ccs="ccs" --define=PART_TM4C1231H6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="mcal/port_driver/$(basename $(<F)).d_raw" --obj_directory="mcal/port_driver" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


