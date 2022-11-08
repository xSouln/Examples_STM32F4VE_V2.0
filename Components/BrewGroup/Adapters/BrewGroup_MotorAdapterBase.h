//==============================================================================
#ifndef _BREW_GROUP_MOTOR_ADAPTER_BASE_H
#define _BREW_GROUP_MOTOR_ADAPTER_BASE_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "BrewGroup_MotorAdapterConfig.h"
//==============================================================================
typedef enum
{
	BrewGroupMotorEventIdle,
	BrewGroupMotorEventTimeSynchronization
	
} BrewGroupMotorEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	BrewGroupMotorRequestIdle,
	BrewGroupMotorRequestUpdateSensors,
	BrewGroupMotorRequestOpen,
	BrewGroupMotorRequestClose,
	BrewGroupMotorRequestMoveStope,
	BrewGroupMotorRequestSetPower,
	
} BrewGroupMotorRequestSelector;
//------------------------------------------------------------------------------
typedef enum
{
	BrewGroupMotorValueIdle,
	BrewGroupMotorValueMoveDiraction
	
} BrewGroupMotorValueSelector;
//------------------------------------------------------------------------------
typedef void (*BrewGroupMotorHandlerT)(void* device);

typedef void (*BrewGroupMotorEventListenerT)(void* device, BrewGroupMotorEventSelector selector, uint32_t args, uint32_t count);
typedef xResult (*BrewGroupMotorRequestListenerT)(void* device, BrewGroupMotorRequestSelector selector, uint32_t args, uint32_t count);
//==============================================================================
typedef struct
{
	OBJECT_HEADER;
	
	void* Child;
	
	BrewGroupMotorHandlerT Handler;
	
	BrewGroupMotorEventListenerT EventListener;
	BrewGroupMotorRequestListenerT RequestListener;
	
} BrewGroupMotorAdapterBaseT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

