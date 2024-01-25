################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: arm-gnu-toolchain-13.2
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Afhib/Desktop/Projects/xLibs/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_Adapter.c \
C:/Users/Afhib/Desktop/Projects/xLibs/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_RxAdapter.c \
C:/Users/Afhib/Desktop/Projects/xLibs/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_TxAdapter.c 

OBJS += \
./xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_Adapter.o \
./xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_RxAdapter.o \
./xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_TxAdapter.o 

C_DEPS += \
./xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_Adapter.d \
./xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_RxAdapter.d \
./xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_TxAdapter.d 


# Each subdirectory must supply rules for building sources it contributes
xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_Adapter.o: C:/Users/Afhib/Desktop/Projects/xLibs/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_Adapter.c xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_RxAdapter.o: C:/Users/Afhib/Desktop/Projects/xLibs/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_RxAdapter.c xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_TxAdapter.o: C:/Users/Afhib/Desktop/Projects/xLibs/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_TxAdapter.c xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-xLib-2f-Templates-2f-SerialPort-2f-Adapters-2f-STM32H7xx-2f-UART

clean-xLib-2f-Templates-2f-SerialPort-2f-Adapters-2f-STM32H7xx-2f-UART:
	-$(RM) ./xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_Adapter.cyclo ./xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_Adapter.d ./xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_Adapter.o ./xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_Adapter.su ./xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_RxAdapter.cyclo ./xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_RxAdapter.d ./xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_RxAdapter.o ./xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_RxAdapter.su ./xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_TxAdapter.cyclo ./xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_TxAdapter.d ./xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_TxAdapter.o ./xLib/Templates/SerialPort/Adapters/STM32H7xx/UART/SerialPort_UART_TxAdapter.su

.PHONY: clean-xLib-2f-Templates-2f-SerialPort-2f-Adapters-2f-STM32H7xx-2f-UART

