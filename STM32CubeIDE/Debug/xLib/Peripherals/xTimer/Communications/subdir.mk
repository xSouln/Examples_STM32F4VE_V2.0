################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: arm-gnu-toolchain-13.2
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Afhib/Desktop/Projects/xLibs/Peripherals/xTimer/Communications/xTimer-RxTransactions.c 

OBJS += \
./xLib/Peripherals/xTimer/Communications/xTimer-RxTransactions.o 

C_DEPS += \
./xLib/Peripherals/xTimer/Communications/xTimer-RxTransactions.d 


# Each subdirectory must supply rules for building sources it contributes
xLib/Peripherals/xTimer/Communications/xTimer-RxTransactions.o: C:/Users/Afhib/Desktop/Projects/xLibs/Peripherals/xTimer/Communications/xTimer-RxTransactions.c xLib/Peripherals/xTimer/Communications/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DconfigAPPLICATION_ALLOCATED_HEAP=1 -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/Compiler" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/NetworkInterface" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-xLib-2f-Peripherals-2f-xTimer-2f-Communications

clean-xLib-2f-Peripherals-2f-xTimer-2f-Communications:
	-$(RM) ./xLib/Peripherals/xTimer/Communications/xTimer-RxTransactions.cyclo ./xLib/Peripherals/xTimer/Communications/xTimer-RxTransactions.d ./xLib/Peripherals/xTimer/Communications/xTimer-RxTransactions.o ./xLib/Peripherals/xTimer/Communications/xTimer-RxTransactions.su

.PHONY: clean-xLib-2f-Peripherals-2f-xTimer-2f-Communications

