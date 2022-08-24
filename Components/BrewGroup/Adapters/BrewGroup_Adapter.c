//==============================================================================
#include <string.h>
#include <stdbool.h>
#include "Adapters/BrewGroup_Adapter.h"
#include "main.h"
#include "tim.h"
//==============================================================================
//==============================================================================
static BrewGroup_Result SetMotorState(MotorDriverT* driver, MotorDriver_State state)
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
	
	return BrewGroup_ResultAccept;
}
//==============================================================================
static BrewGroup_Result SetDriverState(MotorDriverT* driver, MotorDriver_State state)
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
	return BrewGroup_ResultAccept;
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
static BrewGroup_Result SetLockState(MotorDriverT* driver, MotorDriver_MotorState state)
{
	
	return BrewGroup_ResultAccept;
}
//==============================================================================
static BrewGroup_Result Delay(MotorDriverT* driver, uint32_t ms)
{
	HAL_Delay(ms);
	return BrewGroup_ResultAccept;
}
//==============================================================================
static BrewGroup_Result SetSpeed(MotorDriverT* driver, float speed)
{
	//const uint16_t base_period;
	//htim3.Instance->CCR2 = (uint16_t)((htim3.Instance->ARR + 1) * speed) - 1;
	//htim3.Instance->CCR3 = (uint16_t)((htim3.Instance->ARR + 1) * speed) - 1;
	return BrewGroup_ResultAccept;
}
//==============================================================================
static float GetSpeed(void* driver)
{
	return 0.0;
}
//==============================================================================
static BrewGroup_Result SetFrequency(MotorDriverT* driver, float frequency)
{
	return BrewGroup_ResultAccept;
}
//==============================================================================
static float GetFrequency(void* driver)
{
	return 0.0;
}
//==============================================================================
static BrewGroup_Result SetPosition(MotorDriverT* driver, int position)
{
	
	return BrewGroup_ResultAccept;
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
BrewGroup_Result BrewGroup_Init(BrewGroupT* adapter, void* parent)
{
	if (adapter)
	{
		if (!adapter->Description) { adapter->Description = "BrewGroupT"; }
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
	return BrewGroup_ResultNullPointer;
}
//==============================================================================
//==============================================================================
