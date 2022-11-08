//==============================================================================
#ifndef _TERMOSTAT_ADAPTER_BASE_H
#define _TERMOSTAT_ADAPTER_BASE_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "Thermostat_AdapterConfig.h"
//==============================================================================
typedef enum
{
	TermostatEventIdle,
	TermostatEventTimeSynchronization
	
} TermostatEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	TermostatRequestIdle,
	TermostatRequestHeaterEnable,
	TermostatRequestHeaterDisable,
	TermostatRequestStartMeasurement,
	TermostatRequestStopMeasurement,
	
	TermostatRequestSetUpdateTime
	
} TermostatRequestSelector;
//------------------------------------------------------------------------------
typedef enum
{
	TermostatValueIdle,
	
} TermostatValueSelector;
//------------------------------------------------------------------------------
typedef void (*TermostatHandlerT)(void* device);

typedef void (*TermostatEventListenerT)(void* device, TermostatEventSelector selector, uint32_t args, uint32_t count);
typedef xResult (*TermostatRequestListenerT)(void* device, TermostatRequestSelector selector, uint32_t args, uint32_t count);
//==============================================================================
typedef struct
{
	OBJECT_HEADER;
	
	void* Child;
	
	TermostatHandlerT Handler;
	
	TermostatEventListenerT EventListener;
	TermostatRequestListenerT RequestListener;
	
} TermostatAdapterBaseT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

