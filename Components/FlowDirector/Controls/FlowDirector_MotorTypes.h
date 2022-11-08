//==============================================================================
#ifndef _FLOW_DIRECTOR_MOTOR_TYPES_H
#define _FLOW_DIRECTOR_MOTOR_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "Components_Types.h"
#include "FlowDirector_MotorConfig.h"
#include "FlowDirector/Adapters/FlowDirector_MotorAdapterBase.h"
//==============================================================================
typedef enum
{
	FlowDirectorMotionNoError,
	FlowDirectorMotionTimeout,
	FlowDirectorMotionOvercurrent,
	
} FlowDirectorMotionResult;
//------------------------------------------------------------------------------
typedef enum
{
	FlowDirectorMotionStateStopped,
	FlowDirectorMotionStateMoving,
	
} FlowDirectorMotionStatus;
//==============================================================================
typedef struct
{
	float Acceleration;
	float Deceleration;
	
	float StartSpeed;
	float StopSpeed;
	
	uint32_t TimeOut;
	
} FlowDirectorMotorOptionsT;
//------------------------------------------------------------------------------
typedef struct
{
	float Angle;
	float Speed;
	
} FlowDirectorRequestSetPositionT;
//------------------------------------------------------------------------------
typedef union
{
	struct
	{
		uint32_t Motion : 4;
		uint32_t MotionResult : 4;
		
		uint32_t IsEnable : 1;
		uint32_t TimerSynchronization : 1;
		uint32_t TimeIsUpdate : 1;
	};
	
	uint32_t Value;
	
} FlowDirectorMotorStatusT;
//------------------------------------------------------------------------------
typedef struct
{
	uint32_t AccelerationTime;
	uint32_t DecelerationTime;
	
} FlowDirectorDebugT;
//------------------------------------------------------------------------------
typedef struct
{
	OBJECT_HEADER;
	
	FlowDirectorMotorAdapterBaseT Adapter;
	
	FlowDirectorMotorOptionsT Options;
	FlowDirectorMotorStatusT Status;
	
	FlowDirectorDebugT Debug;
	
	float RequestAngle;
	float TotalAngle;
	float HandlerAngle;
	
	float RequestSpeed;
	float TotalSpeed;
	
	float AccelerationIncrement;
	float DecelerationIncrement;
	int8_t Direction;
	
	int AccelerationEndTime;
	int DecelerationStartTime;
	
	uint32_t TimeOut;
	
	uint32_t MoveTime;
	
} FlowDirectorMotorT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif