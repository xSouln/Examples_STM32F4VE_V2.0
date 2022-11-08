//==============================================================================
#ifndef _SLIDER_DC_MOTOR_ADAPTER_TYPES_H
#define _SLIDER_DC_MOTOR_ADAPTER_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "Slider/Controls/Slider_MotorBase.h"
#include "Slider_DCMotorAdapterConfig.h"
//==============================================================================
typedef struct
{
	REG_TIM_T* Timer;
	uint32_t OutputEnableMask;
	volatile uint32_t* CompareValue;
	
} SliderDCMotorAdapterPWM_T;
//------------------------------------------------------------------------------
typedef struct
{
	SliderDCMotorAdapterPWM_T PWM_Forward;
	SliderDCMotorAdapterPWM_T PWM_Backward;
	
	SliderDCMotorAdapterPWM_T* SelectedPWM;
	
	union
	{
		struct
		{
			uint32_t Open : 1;
			uint32_t Close : 1;
		};
		
		uint32_t Value;
		
	} Triggers;
	
} SliderDCMotorAdapterValuesT;
//------------------------------------------------------------------------------
typedef struct
{
	REG_TIM_T* PWM_ForwardTimer;
	REG_TIM_T* PWM_BackwardTimer;
	
	SliderDCMotorAdapterValuesT Values;
	
	struct
	{
		uint8_t PWM_ForwardChannel : 2;
		uint8_t PWM_BackwardChannel : 2;
	};
	
} SliderDCMotorAdapterT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

