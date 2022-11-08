//==============================================================================
#ifndef _FLOW_METER_ADAPTER_BASE_H
#define _FLOW_METER_ADAPTER_BASE_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "FlowMeter_AdapterConfig.h"
//==============================================================================
typedef enum
{
	FlowMeterEventIdle,
	FlowMeterEventTimeSynchronization
	
} FlowMeterEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	FlowMeterRequestIdle,
	FlowMeterRequestEnable,
	FlowMeterRequestDisable,
	FlowMeterRequestUpdateCounter,
	FlowMeterRequestResetCounter,
	
} FlowMeterRequestSelector;
//------------------------------------------------------------------------------
typedef enum
{
	FlowMeterValueIdle,
	
} FlowMeterValueSelector;
//------------------------------------------------------------------------------
typedef void (*FlowMeterHandlerT)(void* device);

typedef void (*FlowMeterEventListenerT)(void* device, FlowMeterEventSelector selector, uint32_t args, uint32_t count);
typedef xResult (*FlowMeterRequestListenerT)(void* device, FlowMeterRequestSelector selector, uint32_t args, uint32_t count);
//==============================================================================
typedef struct
{
	OBJECT_HEADER;
	
	void* Child;
	
	FlowMeterHandlerT Handler;
	
	FlowMeterEventListenerT EventListener;
	FlowMeterRequestListenerT RequestListener;
	
} FlowMeterAdapterBaseT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

