################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: arm-gnu-toolchain-13.2
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Afhib/Desktop/Projects/xLibs/Drivers/OV2640/OV2640_Driver.c 

OBJS += \
./xLib/Drivers/OV2640/OV2640_Driver.o 

C_DEPS += \
./xLib/Drivers/OV2640/OV2640_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
xLib/Drivers/OV2640/OV2640_Driver.o: C:/Users/Afhib/Desktop/Projects/xLibs/Drivers/OV2640/OV2640_Driver.c xLib/Drivers/OV2640/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Afhib/Desktop/Projects/xLibs" -I"C:/Users/Afhib/Desktop/Projects/xLibs/Components" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources/CAN_Local" -I"C:/Users/Afhib/Desktop/Projects/Repositories-SintezElectro/Sources" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components" -I"C:/Users/Afhib/Desktop/Projects/Board_STM32F4VE_V2.0/STM32CubeIDE/../Components/Configurations" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-xLib-2f-Drivers-2f-OV2640

clean-xLib-2f-Drivers-2f-OV2640:
	-$(RM) ./xLib/Drivers/OV2640/OV2640_Driver.cyclo ./xLib/Drivers/OV2640/OV2640_Driver.d ./xLib/Drivers/OV2640/OV2640_Driver.o ./xLib/Drivers/OV2640/OV2640_Driver.su

.PHONY: clean-xLib-2f-Drivers-2f-OV2640

