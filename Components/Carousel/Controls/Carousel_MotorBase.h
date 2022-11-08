//==============================================================================
#ifndef _CAROUSEL_MOTOR_BASE_H
#define _CAROUSEL_MOTOR_BASE_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "Common/xTypes.h"
//==============================================================================
typedef enum
{
	CarouselMotorEventIdle,
	CarouselMotorEventPositionIsSet
	
} CarouselMotorEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	CarouselMotorRequestIdle,
	CarouselMotorRequestMoveStart,
	CarouselMotorRequestMoveStope,
	CarouselMotorRequestSetPower,
	
} CarouselMotorRequestSelector;
//------------------------------------------------------------------------------
typedef enum
{
	CarouselMotorValueIdle,	
	CarouselMotorValueEncoderPosition,
	CarouselMotorValueMoveDiraction
	
} CarouselMotorValueSelector;
//------------------------------------------------------------------------------
typedef enum
{
	CarouselMotorMoveStopped,
	CarouselMotorMoveForward,
	CarouselMotorMoveBackward
	
} CarouselMotorMoveDiraction;
//------------------------------------------------------------------------------
typedef void (*CarouselMotorHandlerT)(void* device);

typedef void (*CarouselMotorEventListenerT)(void* device, CarouselMotorEventSelector selector, uint32_t args, uint32_t count);
typedef xResult (*CarouselMotorRequestListenerT)(void* device, CarouselMotorRequestSelector selector, uint32_t args, uint32_t count);

typedef uint32_t (*CarouselMotorActionGetValueT)(void* device, CarouselMotorValueSelector selector);
typedef xResult (*CarouselMotorActionSetValueT)(void* device, CarouselMotorValueSelector selector, uint32_t value);
//------------------------------------------------------------------------------
typedef struct
{
	CarouselMotorHandlerT Handler;
	
	CarouselMotorEventListenerT EventListener;
	CarouselMotorRequestListenerT RequestListener;
	
	CarouselMotorActionGetValueT GetValue;
	CarouselMotorActionSetValueT SetValue;
	
} CarouselMotorInterfaceT;
//------------------------------------------------------------------------------
typedef enum
{
	CarouselMotionNoError,
	CarouselMotionTimeout,
	CarouselMotionOvercurrent,
	
} CarouselMotionResult;
//------------------------------------------------------------------------------
typedef enum
{
	CarouselMotionStateStopped,
	CarouselMotionStateMovingForward,
	CarouselMotionStateMovingBackward,
	
} CarouselMotionStatus;
//------------------------------------------------------------------------------
typedef enum
{
	CarouselMotorModeCommom,
	CarouselMotorModeStopAtZeroMark,
	CarouselMotorModeMoveOutAtZeroMark,
	CarouselMotorModeFindZeroMark,
	
} CarouselMotorModes;
//------------------------------------------------------------------------------
typedef enum
{
	CarouselMotorDiractionForward,
	CarouselMotorDiractionBackward,
	
} CarouselMotorDiractions;
//------------------------------------------------------------------------------
typedef struct
{
	float Power;
	int Position;
	uint32_t TimeOut;
	uint32_t Mode;
	
} CarouselMotorRequestT;
//------------------------------------------------------------------------------
typedef struct
{
	float Acceleration;
	float Deceleration;
	
	float StartPower;
	float StopPower;
	
	float Power;
	
} CarouselMotorOptionsT;
//------------------------------------------------------------------------------
typedef struct
{
	OBJECT_HEADER;
	
	void* Child;
	CarouselMotorInterfaceT* Interface;
	
	CarouselMotorOptionsT Options;
	float AccelerationIncrement;
	
	float TotalPower;
	float RequestPower;
	
	uint32_t Mode;
	
	CarouselMotorDiractions Diraction;
	
	int EncoderPosition;
	int RequestEncoderPosition;
	
	struct
	{
		uint32_t TimeSynchronizationEnable : 1;
	};

	uint32_t MoveTime;
	uint32_t TimeOut;
	
} CarouselMotorBaseT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif
