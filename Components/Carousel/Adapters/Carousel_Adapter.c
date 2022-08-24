//==============================================================================
#include <string.h>
#include <stdbool.h>
#include "Adapters/Carousel_Adapter.h"
#include "main.h"
#include "tim.h"
//==============================================================================
//==============================================================================
static Carousel_Result SetMotorState(MotorDriverT* driver, MotorDriver_State state)
{
	switch((uint8_t)state)
	{
		case MotorDriver_StateEnable:
			//HAL_TIM_Base_Start_IT(&htim2);
			break;
			
		case MotorDriver_StateDisable:
			//HAL_TIM_Base_Stop_IT(&htim2);
			break;
	}
	
	return Carousel_ResultAccept;
}
//==============================================================================
static Carousel_Result SetDriverState(MotorDriverT* driver, MotorDriver_State state)
{
	switch((uint8_t)state)
	{
		case MotorDriver_StateEnable:
			//SERVO_ENABLE_GPIO_Port->ODR &= ~SERVO_ENABLE_Pin;
			HAL_TIM_Base_Start_IT(&htim2);
			break;
		
		case MotorDriver_StateDisable:
			//SERVO_ENABLE_GPIO_Port->ODR |= SERVO_ENABLE_Pin;
			HAL_TIM_Base_Stop_IT(&htim2);
			break;
	}
	return Carousel_ResultAccept;
}
//==============================================================================
static void PWM_Handler(MotorDriverT* driver)
{
	TIM3->CCR1 = TIM3->ARR - (driver->Position * 2000 / 18000 + 500);
}
//==============================================================================
static void Handler(MotorDriverT* driver)
{
	
}
//==============================================================================
static Carousel_Result SetLockState(MotorDriverT* driver, MotorDriver_MotorState state)
{
	
	return Carousel_ResultAccept;
}
//==============================================================================
static Carousel_Result Delay(MotorDriverT* driver, uint32_t ms)
{
	HAL_Delay(ms);
	return Carousel_ResultAccept;
}
//==============================================================================
static Carousel_Result SetSpeed(MotorDriverT* driver, float speed)
{
	//const uint16_t base_period;
	//htim3.Instance->CCR2 = (uint16_t)((htim3.Instance->ARR + 1) * speed) - 1;
	//htim3.Instance->CCR3 = (uint16_t)((htim3.Instance->ARR + 1) * speed) - 1;
	return Carousel_ResultAccept;
}
//==============================================================================
static float GetSpeed(void* driver)
{
	return 0.0;
}
//==============================================================================
static Carousel_Result SetFrequency(MotorDriverT* driver, float frequency)
{
	return Carousel_ResultAccept;
}
//==============================================================================
static float GetFrequency(void* driver)
{
	return 0.0;
}
//==============================================================================
static Carousel_Result SetPosition(MotorDriverT* driver, int position)
{
	
	return Carousel_ResultAccept;
}
//==============================================================================
static int GetPosition(MotorDriverT* driver)
{
	return (int)driver->CalculatedValues.Steps;
}
//==============================================================================
static MOTOR_DRIVER_CONTROL_LAYER_DEF(Adapter,
	SetMotorState,
	SetSpeed,
	GetSpeed,
	SetFrequency,
	GetFrequency,
	SetDriverState,
	GetPosition,
	SetPosition,
	PWM_Handler,
	Handler,
	SetLockState,
	Delay
);
//==============================================================================
Carousel_Result Carousel_Init(CarouselT* adapter, void* parent)
{
	if (adapter)
	{
		if (!adapter->Description) { adapter->Description = "CarouselT"; }
		adapter->Parent = parent;
		
		adapter->Driver.Options.HandlerUpdateFrequency = 1000;
		
		adapter->Driver.Options.StartSpeed = 1000;
		adapter->Driver.Options.StopSpeed = 1000;
		
		adapter->Driver.Options.Acceleration = 2000;
		adapter->Driver.Options.Deceleration = 2000;
		
		adapter->Driver.Options.EnableDelay = 1000;
		adapter->Driver.Options.DisableDelay = 1000;
		
		return MotorDriver_Init(&adapter->Driver,
														adapter,
														&AdapterControl,
														0);
	}
	return Carousel_ResultNullPointer;
}
//==============================================================================
//==============================================================================
