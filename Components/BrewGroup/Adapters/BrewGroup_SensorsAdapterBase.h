//==============================================================================
#ifndef _BREW_GROUP_SENSORS_ADAPTER_BASE_H
#define _BREW_GROUP_SENSORS_ADAPTER_BASE_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "BrewGroup_SensorsAdapterConfig.h"
//==============================================================================
typedef enum
{
	BrewGroupSensorsEventIdle,
	BrewGroupSensorsEventTimeSynchronization
	
} BrewGroupSensorsEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	BrewGroupSensorsRequestIdle,
	BrewGroupSensorsRequestUpdateState
	
} BrewGroupSensorsRequestSelector;
//------------------------------------------------------------------------------
typedef enum
{
	BrewGroupSensorsValueIdle,
	
} BrewGroupSensorsValueSelector;
//------------------------------------------------------------------------------
typedef void (*BrewGroupSensorsHandlerT)(void* device);
typedef xResult (*BrewGroupSensorsRequestListenerT)(void* device, BrewGroupSensorsRequestSelector selector, uint32_t args, uint32_t count);
typedef void (*BrewGroupSensorsEventListenerT)(void* device, BrewGroupSensorsEventSelector selector, uint32_t args, uint32_t count);
//==============================================================================
typedef struct
{
	OBJECT_HEADER;
	
	void* Child;
	
	BrewGroupSensorsHandlerT Handler;
	BrewGroupSensorsRequestListenerT RequestListener;
	BrewGroupSensorsEventListenerT EventListener;
	
} BrewGroupSensorsAdapterBaseT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

