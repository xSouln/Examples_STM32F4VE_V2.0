//==============================================================================
#ifndef _CUPS_CONTROLLER_LED_ADAPTER_BASE_H
#define _CUPS_CONTROLLER_LED_ADAPTER_BASE_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "CupsController_LEDAdapterConfig.h"
//==============================================================================
typedef enum
{
	CupsControllerLEDEventIdle,
	CupsControllerLEDEventTimeSynchronization
	
} CupsControllerLEDEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	CupsControllerLEDRequestIdle,
	CupsControllerLEDRequestUpdateState
	
} CupsControllerLEDRequestSelector;
//------------------------------------------------------------------------------
typedef enum
{
	CupsControllerLEDValueIdle,
	
} CupsControllerLEDValueSelector;
//------------------------------------------------------------------------------
typedef void (*CupsControllerLEDHandlerT)(void* device);
typedef xResult (*CupsControllerLEDRequestListenerT)(void* device, CupsControllerLEDRequestSelector selector, uint32_t args, uint32_t count);
typedef void (*CupsControllerLEDEventListenerT)(void* device, CupsControllerLEDEventSelector selector, uint32_t args, uint32_t count);
//==============================================================================
typedef struct
{
	OBJECT_HEADER;
	
	void* Child;
	
	CupsControllerLEDHandlerT Handler;
	CupsControllerLEDRequestListenerT RequestListener;
	CupsControllerLEDEventListenerT EventListener;
	
} CupsControllerLEDAdapterBaseT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

