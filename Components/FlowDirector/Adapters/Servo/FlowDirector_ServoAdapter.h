//==============================================================================
#ifndef _FLOW_DIRECTOR_SERVO_ADAPTER_H
#define _FLOW_DIRECTOR_SERVO_ADAPTER_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "FlowDirector/Controls/FlowDirector_Motor.h"
#include "tim.h"
//==============================================================================
typedef struct
{
	uint32_t PWM_OutputEnableMask;
	volatile uint32_t* PWM_Period;
	
	uint32_t Min;
	uint32_t Max;
	uint32_t Width;
	
} FlowDirectorServoAdapterDataT;
//------------------------------------------------------------------------------
typedef struct
{
	REG_TIM_T* PWM_Timer;
	float MaxAngle;
	
	FlowDirectorServoAdapterDataT Data;
	
	struct
	{
		uint8_t PWM_Channel : 2;
	};
	
} FlowDirectorServoAdapterT;
//==============================================================================
xResult FlowDirectorServoAdapterInit(FlowDirectorMotorT* device, FlowDirectorServoAdapterT* adapter);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

