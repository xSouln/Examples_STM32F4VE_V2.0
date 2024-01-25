################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: arm-gnu-toolchain-13.2
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/can.c \
C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/crc.c \
C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/dma.c \
C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/freertos.c \
C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/gpio.c \
C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/i2c.c \
C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/main.c \
C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/rng.c \
C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/spi.c \
C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/stm32f4xx_hal_msp.c \
C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/stm32f4xx_hal_timebase_tim.c \
C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/stm32f4xx_it.c \
../Application/User/Core/syscalls.c \
../Application/User/Core/sysmem.c \
C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/tim.c \
C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/usart.c 

OBJS += \
./Application/User/Core/can.o \
./Application/User/Core/crc.o \
./Application/User/Core/dma.o \
./Application/User/Core/freertos.o \
./Application/User/Core/gpio.o \
./Application/User/Core/i2c.o \
./Application/User/Core/main.o \
./Application/User/Core/rng.o \
./Application/User/Core/spi.o \
./Application/User/Core/stm32f4xx_hal_msp.o \
./Application/User/Core/stm32f4xx_hal_timebase_tim.o \
./Application/User/Core/stm32f4xx_it.o \
./Application/User/Core/syscalls.o \
./Application/User/Core/sysmem.o \
./Application/User/Core/tim.o \
./Application/User/Core/usart.o 

C_DEPS += \
./Application/User/Core/can.d \
./Application/User/Core/crc.d \
./Application/User/Core/dma.d \
./Application/User/Core/freertos.d \
./Application/User/Core/gpio.d \
./Application/User/Core/i2c.d \
./Application/User/Core/main.d \
./Application/User/Core/rng.d \
./Application/User/Core/spi.d \
./Application/User/Core/stm32f4xx_hal_msp.d \
./Application/User/Core/stm32f4xx_hal_timebase_tim.d \
./Application/User/Core/stm32f4xx_it.d \
./Application/User/Core/syscalls.d \
./Application/User/Core/sysmem.d \
./Application/User/Core/tim.d \
./Application/User/Core/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Core/can.o: C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/can.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DconfigAPPLICATION_ALLOCATED_HEAP=1 -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/Compiler" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/NetworkInterface" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/crc.o: C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/crc.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DconfigAPPLICATION_ALLOCATED_HEAP=1 -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/Compiler" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/NetworkInterface" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/dma.o: C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/dma.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DconfigAPPLICATION_ALLOCATED_HEAP=1 -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/Compiler" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/NetworkInterface" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/freertos.o: C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/freertos.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DconfigAPPLICATION_ALLOCATED_HEAP=1 -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/Compiler" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/NetworkInterface" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/gpio.o: C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/gpio.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DconfigAPPLICATION_ALLOCATED_HEAP=1 -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/Compiler" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/NetworkInterface" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/i2c.o: C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/i2c.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DconfigAPPLICATION_ALLOCATED_HEAP=1 -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/Compiler" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/NetworkInterface" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/main.o: C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/main.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DconfigAPPLICATION_ALLOCATED_HEAP=1 -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/Compiler" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/NetworkInterface" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/rng.o: C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/rng.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DconfigAPPLICATION_ALLOCATED_HEAP=1 -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/Compiler" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/NetworkInterface" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/spi.o: C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/spi.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DconfigAPPLICATION_ALLOCATED_HEAP=1 -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/Compiler" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/NetworkInterface" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/stm32f4xx_hal_msp.o: C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/stm32f4xx_hal_msp.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DconfigAPPLICATION_ALLOCATED_HEAP=1 -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/Compiler" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/NetworkInterface" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/stm32f4xx_hal_timebase_tim.o: C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/stm32f4xx_hal_timebase_tim.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DconfigAPPLICATION_ALLOCATED_HEAP=1 -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/Compiler" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/NetworkInterface" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/stm32f4xx_it.o: C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/stm32f4xx_it.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DconfigAPPLICATION_ALLOCATED_HEAP=1 -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/Compiler" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/NetworkInterface" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/%.o Application/User/Core/%.su Application/User/Core/%.cyclo: ../Application/User/Core/%.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DconfigAPPLICATION_ALLOCATED_HEAP=1 -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/Compiler" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/NetworkInterface" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/tim.o: C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/tim.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DconfigAPPLICATION_ALLOCATED_HEAP=1 -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/Compiler" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/NetworkInterface" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/usart.o: C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/Core/Src/usart.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DconfigAPPLICATION_ALLOCATED_HEAP=1 -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/Compiler" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-TCP/NetworkInterface" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/include" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/FreeRTOS-Plus-MQTT/interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-Core

clean-Application-2f-User-2f-Core:
	-$(RM) ./Application/User/Core/can.cyclo ./Application/User/Core/can.d ./Application/User/Core/can.o ./Application/User/Core/can.su ./Application/User/Core/crc.cyclo ./Application/User/Core/crc.d ./Application/User/Core/crc.o ./Application/User/Core/crc.su ./Application/User/Core/dma.cyclo ./Application/User/Core/dma.d ./Application/User/Core/dma.o ./Application/User/Core/dma.su ./Application/User/Core/freertos.cyclo ./Application/User/Core/freertos.d ./Application/User/Core/freertos.o ./Application/User/Core/freertos.su ./Application/User/Core/gpio.cyclo ./Application/User/Core/gpio.d ./Application/User/Core/gpio.o ./Application/User/Core/gpio.su ./Application/User/Core/i2c.cyclo ./Application/User/Core/i2c.d ./Application/User/Core/i2c.o ./Application/User/Core/i2c.su ./Application/User/Core/main.cyclo ./Application/User/Core/main.d ./Application/User/Core/main.o ./Application/User/Core/main.su ./Application/User/Core/rng.cyclo ./Application/User/Core/rng.d ./Application/User/Core/rng.o ./Application/User/Core/rng.su ./Application/User/Core/spi.cyclo ./Application/User/Core/spi.d ./Application/User/Core/spi.o ./Application/User/Core/spi.su ./Application/User/Core/stm32f4xx_hal_msp.cyclo ./Application/User/Core/stm32f4xx_hal_msp.d ./Application/User/Core/stm32f4xx_hal_msp.o ./Application/User/Core/stm32f4xx_hal_msp.su ./Application/User/Core/stm32f4xx_hal_timebase_tim.cyclo ./Application/User/Core/stm32f4xx_hal_timebase_tim.d ./Application/User/Core/stm32f4xx_hal_timebase_tim.o ./Application/User/Core/stm32f4xx_hal_timebase_tim.su ./Application/User/Core/stm32f4xx_it.cyclo ./Application/User/Core/stm32f4xx_it.d ./Application/User/Core/stm32f4xx_it.o ./Application/User/Core/stm32f4xx_it.su ./Application/User/Core/syscalls.cyclo ./Application/User/Core/syscalls.d ./Application/User/Core/syscalls.o ./Application/User/Core/syscalls.su ./Application/User/Core/sysmem.cyclo ./Application/User/Core/sysmem.d ./Application/User/Core/sysmem.o ./Application/User/Core/sysmem.su ./Application/User/Core/tim.cyclo ./Application/User/Core/tim.d ./Application/User/Core/tim.o ./Application/User/Core/tim.su ./Application/User/Core/usart.cyclo ./Application/User/Core/usart.d ./Application/User/Core/usart.o ./Application/User/Core/usart.su

.PHONY: clean-Application-2f-User-2f-Core

