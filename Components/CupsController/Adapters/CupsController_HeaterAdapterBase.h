//==============================================================================
#ifndef _CUPS_CONTROLLER_HEATER_ADAPTER_BASE_H
#define _CUPS_CONTROLLER_HEATER_ADAPTER_BASE_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "CupsController_HeaterAdapterConfig.h"
//==============================================================================
typedef enum
{
	CupsControllerHeaterEventIdle,
	CupsControllerHeaterEventTimeSynchronization
	
} CupsControllerHeaterEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	CupsControllerHeaterRequestIdle,
	CupsControllerHeaterRequestUpdateState
	
} CupsControllerHeaterRequestSelector;
//------------------------------------------------------------------------------
typedef enum
{
	CupsControllerHeaterValueIdle,
	
} CupsControllerHeaterValueSelector;
//------------------------------------------------------------------------------
typedef void (*CupsControllerHeaterHandlerT)(void* device);
typedef xResult (*CupsControllerHeaterRequestListenerT)(void* device, CupsControllerHeaterRequestSelector selector, uint32_t args, uint32_t count);
typedef void (*CupsControllerHeaterEventListenerT)(void* device, CupsControllerHeaterEventSelector selector, uint32_t args, uint32_t count);
//==============================================================================
typedef struct
{
	OBJECT_HEADER;
	
	void* Child;
	
	CupsControllerHeaterHandlerT Handler;
	CupsControllerHeaterRequestListenerT RequestListener;
	CupsControllerHeaterEventListenerT EventListener;
	
} CupsControllerHeaterAdapterBaseT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

