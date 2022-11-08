//==============================================================================
#ifndef _SLIDER_MOTOR_BASE_H_
#define _SLIDER_MOTOR_BASE_H_
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "Common/xTypes.h"
//==============================================================================
typedef enum
{
	SliderMotorEventIdle,
	
} SliderMotorEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	SliderMotorRequestIdle,
	SliderMotorRequestUpdateSensors,
	SliderMotorRequestMoveStart,
	SliderMotorRequestMoveStope,
	SliderMotorRequestSetPower,
	
} SliderMotorRequestSelector;
//------------------------------------------------------------------------------
typedef enum
{
	SliderMotorValueIdle,
	SliderMotorValueMoveDiraction
	
} SliderMotorValueSelector;
//------------------------------------------------------------------------------
typedef void (*SliderMotorHandlerT)(void* device);

typedef void (*SliderMotorEventListenerT)(void* device, SliderMotorEventSelector selector, uint32_t args, uint32_t count);
typedef xResult (*SliderMotorRequestListenerT)(void* device, SliderMotorRequestSelector selector, uint32_t args, uint32_t count);

//typedef uint32_t (*SliderMotorActionGetValueT)(void* device, SliderMotorValueSelector selector);
//typedef xResult (*SliderMotorActionSetValueT)(void* device, SliderMotorValueSelector selector, uint32_t value);
//------------------------------------------------------------------------------
typedef struct
{
	SliderMotorHandlerT Handler;
	
	SliderMotorEventListenerT EventListener;
	SliderMotorRequestListenerT RequestListener;
	
	//SliderMotorActionGetValueT GetValue;
	//SliderMotorActionSetValueT SetValue;
	
} SliderMotorInterfaceT;
//------------------------------------------------------------------------------
typedef enum
{
	SliderMotionNoError,
	SliderMotionTimeout,
	SliderMotionOvercurrent,
	
} SliderMotionResult;
//------------------------------------------------------------------------------
typedef enum
{
	SliderPositionClose,
	SliderPositionOpen,
	
} SliderPositions;
//------------------------------------------------------------------------------
typedef enum
{
	SliderMotionStateStopped,
	SliderMotionStateOpening,
	SliderMotionStateClosing
	
} SliderMotionStatus;
//------------------------------------------------------------------------------
typedef enum
{
	SliderMoveModeCommon,
	SliderMoveModeMoveOffTheSensor,
	
} SliderMoveModes;
//------------------------------------------------------------------------------
typedef union
{
	struct
	{
		uint8_t Motion : 4;
		uint8_t MotionResult : 4;
	};
	
	uint8_t Value;
	
} SliderMotorStatusT;
//------------------------------------------------------------------------------
typedef struct
{
	uint8_t Open : 1;
	uint8_t Close : 1;
	
} SliderMotorTriggersT;
//------------------------------------------------------------------------------
typedef struct
{
	float Acceleration;
	float StartPower;
	
	float Power;
	
} SliderMotorOptionsT;
//------------------------------------------------------------------------------
typedef struct
{
	float Power;
	uint32_t TimeOut;
	SliderMoveModes Mode;
	SliderPositions Position;
	
} SliderMoveRequestT;
//------------------------------------------------------------------------------
typedef struct
{
	OBJECT_HEADER;
	
	void* Child;
	SliderMotorInterfaceT* Interface;
	
	SliderMotorOptionsT Options;
	SliderMotorStatusT Status;
	SliderMotorTriggersT Triggers;
	SliderMoveModes Mode;
	
	float AccelerationIncrement;
	float TotalPower;
	float RequestPower;
	
	uint32_t MoveTime;
	uint32_t TimeOut;
	
} SliderMotorBaseT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif