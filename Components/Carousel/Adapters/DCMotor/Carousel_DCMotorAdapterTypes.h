//==============================================================================
#ifndef _CAROUSEL_DC_MOTOR_ADAPTER_TYPES_H
#define _CAROUSEL_DC_MOTOR_ADAPTER_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "Components_Config.h"
#include "Carousel/Controls/Carousel_MotorBase.h"
#include "Carousel_DCMotorAdapterConfig.h"
//==============================================================================
typedef struct
{
	REG_TIM_T* Timer;
	uint32_t OutputEnableMask;
	volatile uint32_t* CompareValue;
	
} CarouselDCMotorAdapterPWM_T;
//------------------------------------------------------------------------------
typedef struct
{
	CarouselDCMotorAdapterPWM_T PWM_Forward;
	CarouselDCMotorAdapterPWM_T PWM_Backward;
	
	CarouselDCMotorAdapterPWM_T* SelectedPWM;
	
} CarouselDCMotorAdapterValuesT;
//------------------------------------------------------------------------------
typedef struct
{
	REG_TIM_T* PWM_ForwardTimer;
	REG_TIM_T* PWM_BackwardTimer;
	
	REG_TIM_T* EncoderTimer;
	
	CarouselDCMotorAdapterValuesT Values;
	
	struct
	{
		uint8_t PWM_ForwardChannel : 2;
		uint8_t PWM_BackwardChannel : 2;
	};
	
} CarouselDCMotorAdapterT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

