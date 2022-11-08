//==============================================================================
#ifndef _FLOW_DIRECTOR_SENSORS_ADAPTER_BASE_H
#define _FLOW_DIRECTOR_SENSORS_ADAPTER_BASE_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "Components_Types.h"
#include "FlowDirector_SensorsAdapterConfig.h"
//==============================================================================
typedef enum
{
	FlowDirectorSensorsEventIdle,
	FlowDirectorSensorsEventTimeSynchronization
	
} FlowDirectorSensorsEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	FlowDirectorSensorsRequestIdle,
	FlowDirectorSensorsRequestUpdateState
	
} FlowDirectorSensorsRequestSelector;
//------------------------------------------------------------------------------
typedef enum
{
	FlowDirectorSensorsValueIdle,
	
} FlowDirectorSensorsValueSelector;
//------------------------------------------------------------------------------
typedef void (*FlowDirectorSensorsHandlerT)(void* device);
typedef xResult (*FlowDirectorSensorsRequestListenerT)(void* device, FlowDirectorSensorsRequestSelector selector, uint32_t args, uint32_t count);
typedef void (*FlowDirectorSensorsEventListenerT)(void* device, FlowDirectorSensorsEventSelector selector, uint32_t args, uint32_t count);
//==============================================================================
typedef struct
{
	OBJECT_HEADER;
	
	void* Child;
	
	FlowDirectorSensorsHandlerT Handler;
	FlowDirectorSensorsRequestListenerT RequestListener;
	FlowDirectorSensorsEventListenerT EventListener;
	
} FlowDirectorSensorsAdapterBaseT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

