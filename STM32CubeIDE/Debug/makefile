################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: arm-gnu-toolchain-13.2
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include xLib/Peripherals/xUSART/Communications/subdir.mk
-include xLib/Peripherals/xUSART/Adapters/STM32F4xx/subdir.mk
-include xLib/Peripherals/xUSART/subdir.mk
-include xLib/Peripherals/xTimer/Communications/subdir.mk
-include xLib/Peripherals/xTimer/subdir.mk
-include xLib/Peripherals/xSPI/Communications/subdir.mk
-include xLib/Peripherals/xSPI/subdir.mk
-include xLib/Peripherals/xGPIO/Communications/subdir.mk
-include xLib/Peripherals/xGPIO/subdir.mk
-include xLib/Peripherals/xADC/Communications/subdir.mk
-include xLib/Peripherals/xADC/subdir.mk
-include xLib/Peripherals/CAN/Communications/subdir.mk
-include xLib/Peripherals/CAN/subdir.mk
-include xLib/Components/USART-Ports/Adapters/STM32F4xx/subdir.mk
-include xLib/Components/USART-Ports/subdir.mk
-include xLib/Components/Terminal/Communication/subdir.mk
-include xLib/Components/Terminal/Adapters/subdir.mk
-include xLib/Components/Terminal/subdir.mk
-include xLib/Components/CAN-Ports/Adapters/STM32F4xx/subdir.mk
-include xLib/Components/CAN-Ports/subdir.mk
-include xLib/Common/subdir.mk
-include xLib/Abstractions/xWiFi/Communications/subdir.mk
-include xLib/Abstractions/xWiFi/subdir.mk
-include xLib/Abstractions/xTransferLayer/subdir.mk
-include xLib/Abstractions/xTerminal/subdir.mk
-include xLib/Abstractions/xSystem/subdir.mk
-include xLib/Abstractions/xRequestControl/subdir.mk
-include xLib/Abstractions/xPort/subdir.mk
-include xLib/Abstractions/xNet/Communications/subdir.mk
-include xLib/Abstractions/xNet/subdir.mk
-include xLib/Abstractions/xMQTT/Communications/subdir.mk
-include xLib/Abstractions/xMQTT/subdir.mk
-include xLib/Abstractions/xDispatcher/subdir.mk
-include xLib/Abstractions/xDevice/Communication/subdir.mk
-include xLib/Abstractions/xDevice/subdir.mk
-include Middlewares/FreeRTOS/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Components/Interfaces/subdir.mk
-include Components/subdir.mk
-include Application/User/Startup/subdir.mk
-include Application/User/Core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Board_STM32F4VE_V2.0
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Board_STM32F4VE_V2.0.elf \

MAP_FILES += \
Board_STM32F4VE_V2.0.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Board_STM32F4VE_V2.0.list \


# All Target
all: main-build

# Main-build Target
main-build: Board_STM32F4VE_V2.0.elf secondary-outputs

# Tool invocations
Board_STM32F4VE_V2.0.elf Board_STM32F4VE_V2.0.map: $(OBJS) $(USER_OBJS) C:\Users\Afhib\Desktop\Projects\Board_STM32F4VE_V2.0\STM32CubeIDE\STM32F407VETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Board_STM32F4VE_V2.0.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\Afhib\Desktop\Projects\Board_STM32F4VE_V2.0\STM32CubeIDE\STM32F407VETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Board_STM32F4VE_V2.0.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Board_STM32F4VE_V2.0.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Board_STM32F4VE_V2.0.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Board_STM32F4VE_V2.0.elf Board_STM32F4VE_V2.0.list Board_STM32F4VE_V2.0.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
