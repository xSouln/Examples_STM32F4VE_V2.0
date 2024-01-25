################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: arm-gnu-toolchain-13.2
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Components/FreeRTOS-Plus-TCP/BufferManagement/BufferAllocation_1.c \
C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Components/FreeRTOS-Plus-TCP/BufferManagement/BufferAllocation_2.c 

OBJS += \
./Components/FreeRTOS-Plus-TCP/BufferManagement/BufferAllocation_1.o \
./Components/FreeRTOS-Plus-TCP/BufferManagement/BufferAllocation_2.o 

C_DEPS += \
./Components/FreeRTOS-Plus-TCP/BufferManagement/BufferAllocation_1.d \
./Components/FreeRTOS-Plus-TCP/BufferManagement/BufferAllocation_2.d 


# Each subdirectory must supply rules for building sources it contributes
Components/FreeRTOS-Plus-TCP/BufferManagement/BufferAllocation_1.o: C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Components/FreeRTOS-Plus-TCP/BufferManagement/BufferAllocation_1.c Components/FreeRTOS-Plus-TCP/BufferManagement/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DconfigAPPLICATION_ALLOCATED_HEAP=1 -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/Compiler" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/NetworkInterface" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Components/FreeRTOS-Plus-TCP/BufferManagement/BufferAllocation_2.o: C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Components/FreeRTOS-Plus-TCP/BufferManagement/BufferAllocation_2.c Components/FreeRTOS-Plus-TCP/BufferManagement/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DconfigAPPLICATION_ALLOCATED_HEAP=1 -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/Compiler" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/NetworkInterface" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Components-2f-FreeRTOS-2d-Plus-2d-TCP-2f-BufferManagement

clean-Components-2f-FreeRTOS-2d-Plus-2d-TCP-2f-BufferManagement:
	-$(RM) ./Components/FreeRTOS-Plus-TCP/BufferManagement/BufferAllocation_1.cyclo ./Components/FreeRTOS-Plus-TCP/BufferManagement/BufferAllocation_1.d ./Components/FreeRTOS-Plus-TCP/BufferManagement/BufferAllocation_1.o ./Components/FreeRTOS-Plus-TCP/BufferManagement/BufferAllocation_1.su ./Components/FreeRTOS-Plus-TCP/BufferManagement/BufferAllocation_2.cyclo ./Components/FreeRTOS-Plus-TCP/BufferManagement/BufferAllocation_2.d ./Components/FreeRTOS-Plus-TCP/BufferManagement/BufferAllocation_2.o ./Components/FreeRTOS-Plus-TCP/BufferManagement/BufferAllocation_2.su

.PHONY: clean-Components-2f-FreeRTOS-2d-Plus-2d-TCP-2f-BufferManagement

