################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: arm-gnu-toolchain-13.2
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Afhib/Desktop/Projects/xLibs/Templates/SerialPort/Templates/USB/SerialPort_USB_Component.c 

OBJS += \
./xLib/Templates/SerialPort/Templates/USB/SerialPort_USB_Component.o 

C_DEPS += \
./xLib/Templates/SerialPort/Templates/USB/SerialPort_USB_Component.d 


# Each subdirectory must supply rules for building sources it contributes
xLib/Templates/SerialPort/Templates/USB/SerialPort_USB_Component.o: C:/Users/Afhib/Desktop/Projects/xLibs/Templates/SerialPort/Templates/USB/SerialPort_USB_Component.c xLib/Templates/SerialPort/Templates/USB/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-xLib-2f-Templates-2f-SerialPort-2f-Templates-2f-USB

clean-xLib-2f-Templates-2f-SerialPort-2f-Templates-2f-USB:
	-$(RM) ./xLib/Templates/SerialPort/Templates/USB/SerialPort_USB_Component.cyclo ./xLib/Templates/SerialPort/Templates/USB/SerialPort_USB_Component.d ./xLib/Templates/SerialPort/Templates/USB/SerialPort_USB_Component.o ./xLib/Templates/SerialPort/Templates/USB/SerialPort_USB_Component.su

.PHONY: clean-xLib-2f-Templates-2f-SerialPort-2f-Templates-2f-USB

