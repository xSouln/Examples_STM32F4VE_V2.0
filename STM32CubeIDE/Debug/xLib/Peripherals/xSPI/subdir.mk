################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: arm-gnu-toolchain-13.2
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Afhib/Desktop/Projects/xLibs/Peripherals/xSPI/xSPI.c 

OBJS += \
./xLib/Peripherals/xSPI/xSPI.o 

C_DEPS += \
./xLib/Peripherals/xSPI/xSPI.d 


# Each subdirectory must supply rules for building sources it contributes
xLib/Peripherals/xSPI/xSPI.o: C:/Users/Afhib/Desktop/Projects/xLibs/Peripherals/xSPI/xSPI.c xLib/Peripherals/xSPI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DconfigAPPLICATION_ALLOCATED_HEAP=1 -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/Compiler" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/NetworkInterface" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-xLib-2f-Peripherals-2f-xSPI

clean-xLib-2f-Peripherals-2f-xSPI:
	-$(RM) ./xLib/Peripherals/xSPI/xSPI.cyclo ./xLib/Peripherals/xSPI/xSPI.d ./xLib/Peripherals/xSPI/xSPI.o ./xLib/Peripherals/xSPI/xSPI.su

.PHONY: clean-xLib-2f-Peripherals-2f-xSPI

