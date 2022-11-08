//==============================================================================
#ifndef _BREW_GROUP_DC_MOTOR_ADAPTER_TYPES_H
#define _BREW_GROUP_DC_MOTOR_ADAPTER_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "Components_Config.h"
#include "BrewGroup/Controls/BrewGroup_MotorBase.h"
#include "BrewGroup_DCMotorAdapterConfig.h"
//==============================================================================
typedef struct
{
	REG_TIM_T* Timer;
	uint32_t OutputEnableMask;
	volatile uint32_t* CompareValue;
	
} BrewGroupDCMotorAdapterPWM_T;
//------------------------------------------------------------------------------
typedef struct
{
	BrewGroupDCMotorAdapterPWM_T PWM_Forward;
	BrewGroupDCMotorAdapterPWM_T PWM_Backward;
	
	BrewGroupDCMotorAdapterPWM_T* SelectedPWM;
	
	union
	{
		struct
		{
			uint32_t Open : 1;
			uint32_t Close : 1;
		};
		
		uint32_t Value;
		
	} Triggers;
	
} BrewGroupDCMotorAdapterValuesT;
//------------------------------------------------------------------------------
typedef struct
{
	REG_TIM_T* PWM_ForwardTimer;
	REG_TIM_T* PWM_BackwardTimer;
	
	BrewGroupDCMotorAdapterValuesT Values;
	
	struct
	{
		uint8_t PWM_ForwardChannel : 2;
		uint8_t PWM_BackwardChannel : 2;
	};
	
} BrewGroupDCMotorAdapterT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

