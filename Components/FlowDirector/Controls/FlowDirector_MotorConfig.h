//==============================================================================
#ifndef _FLOW_DIRECTOR_MOTOR_CONFIG_H
#define _FLOW_DIRECTOR_MOTOR_CONFIG_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "FlowDirector_Config.h"
//==============================================================================
#define FLOW_DIRECTOR_MOTOR_DEFAULT_MOVE_STAR_SPEED 50.0 //angle / sec
#define FLOW_DIRECTOR_MOTOR_DEFAULT_MOVE_STOP_SPEED 50.0 //angle / sec
	
#define FLOW_DIRECTOR_MOTOR_DEFAULT_MOVE_ACCELERATION 50.0
#define FLOW_DIRECTOR_MOTOR_DEFAULT_MOVE_DECELERATION 50.0

#define FLOW_DIRECTOR_MOTOR_DEFAULT_TIMEOUT 7000

#define FLOW_DIRECTOR_MOTOR_MAXIMUM_TURNING_ANGLE 180.0
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif