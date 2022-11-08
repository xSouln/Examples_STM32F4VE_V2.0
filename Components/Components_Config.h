//==============================================================================
#ifndef _COMPONENTS_CONFIG_H
#define _COMPONENTS_CONFIG_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "main.h"
#include "Common/xTypes.h"
#include "Common/xRxTransaction.h"
#include "Registers/registers.h"
//==============================================================================
#define BREW_GROUP_MOTOR_TIMER_PWM1 TIM4
#define BREW_GROUP_MOTOR_TIMER_PWM1_CHANNEL 0

#define BREW_GROUP_MOTOR_TIMER_PWM2 TIM4
#define BREW_GROUP_MOTOR_TIMER_PWM2_CHANNEL 1

#define BREW_GROUP_FLOW_METER_HTIMER htim3
//------------------------------------------------------------------------------
#define SLIDER_MOTOR_TIMER_PWM1 TIM4
#define SLIDER_MOTOR_TIMER_PWM1_CHANNEL 2

#define SLIDER_MOTOR_TIMER_PWM2 TIM4
#define SLIDER_MOTOR_TIMER_PWM2_CHANNEL 3
//------------------------------------------------------------------------------
#define FLOW_DIR_MOTOR_TIMER_PWM1 TIM5
#define FLOW_DIR_MOTOR_TIMER_PWM1_CHANNEL 2

#define FLOW_DIR_MOTOR_TIMER_PWM2 TIM5
#define FLOW_DIR_MOTOR_TIMER_PWM2_CHANNEL 3
//------------------------------------------------------------------------------
#define CAROUSEL_MOTOR_TIMER_PWM1 TIM8
#define CAROUSEL_MOTOR_TIMER_PWM1_CHANNEL 0

#define CAROUSEL_MOTOR_TIMER_PWM2 TIM8
#define CAROUSEL_MOTOR_TIMER_PWM2_CHANNEL 1
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

