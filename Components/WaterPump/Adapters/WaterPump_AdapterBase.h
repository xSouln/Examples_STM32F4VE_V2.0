//==============================================================================
#ifndef _WATER_PUMP_ADAPTER_BASE_H
#define _WATER_PUMP_ADAPTER_BASE_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "WaterPump_AdapterConfig.h"
//==============================================================================
typedef enum
{
	WaterPumpEventIdle,
	WaterPumpEventTimeSynchronization
	
} WaterPumpEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	WaterPumpRequestIdle,
	WaterPumpRequestEnable,
	WaterPumpRequestDisable,
	
} WaterPumpRequestSelector;
//------------------------------------------------------------------------------
typedef enum
{
	WaterPumpValueIdle,
	
} WaterPumpValueSelector;
//------------------------------------------------------------------------------
typedef void (*WaterPumpHandlerT)(void* device);

typedef void (*WaterPumpEventListenerT)(void* device, WaterPumpEventSelector selector, uint32_t args, uint32_t count);
typedef xResult (*WaterPumpRequestListenerT)(void* device, WaterPumpRequestSelector selector, uint32_t args, uint32_t count);
//==============================================================================
typedef struct
{
	OBJECT_HEADER;
	
	void* Child;
	
	WaterPumpHandlerT Handler;
	
	WaterPumpEventListenerT EventListener;
	WaterPumpRequestListenerT RequestListener;
	
} WaterPumpAdapterBaseT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

