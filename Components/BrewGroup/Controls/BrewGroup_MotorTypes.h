//==============================================================================
#ifndef _BREW_GROUP_MOTOR_TYPES_H_
#define _BREW_GROUP_MOTOR_TYPES_H_
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "BrewGroup_MotorConfig.h"
#include "BrewGroup/Adapters/BrewGroup_MotorAdapterBase.h"
//==============================================================================
typedef enum
{
	BrewGroupMotionNoError,
	BrewGroupMotionTimeout,
	BrewGroupMotionOvercurrent,
	
} BrewGroupMotionResult;
//------------------------------------------------------------------------------
typedef enum
{
	BrewGroupPositionClose,
	BrewGroupPositionOpen,
	
} BrewGroupPositions;
//------------------------------------------------------------------------------
typedef enum
{
	BrewGroupMotionStateStopped,
	BrewGroupMotionStateOpening,
	BrewGroupMotionStateClosing
	
} BrewGroupMotionStatus;
//------------------------------------------------------------------------------
typedef enum
{
	BrewGroupMoveModeCommon,
	BrewGroupMoveModeMoveOffTheSensor,
	
} BrewGroupMoveModes;
//------------------------------------------------------------------------------
typedef union
{
	struct
	{
		uint8_t Motion : 4;
		uint8_t MotionResult : 4;
	};
	
	uint8_t Value;
	
} BrewGroupMotorStatusT;
//------------------------------------------------------------------------------
typedef struct
{
	uint8_t Open : 1;
	uint8_t Close : 1;
	
} BrewGroupMotorTriggersT;
//------------------------------------------------------------------------------
typedef struct
{
	float Acceleration;
	float StartPower;
	
	float Power;
	
} BrewGroupMotorOptionsT;
//------------------------------------------------------------------------------
typedef struct
{
	float Power;
	uint32_t TimeOut;
	BrewGroupMoveModes Mode;
	BrewGroupPositions Position;
	
} BrewGroupMoveRequestT;
//------------------------------------------------------------------------------
typedef struct
{
	OBJECT_HEADER;
	
	BrewGroupMotorAdapterBaseT Adapter;
	
	BrewGroupMotorOptionsT Options;
	BrewGroupMotorStatusT Status;
	BrewGroupMotorTriggersT Triggers;
	BrewGroupMoveModes Mode;
	
	float AccelerationIncrement;
	float TotalPower;
	float RequestPower;
	
	struct
	{
		uint32_t TimeSynchronizationEnable : 1;
	};
	
	uint32_t MoveTime;
	uint32_t TimeOut;
	
} BrewGroupMotorT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif