//==============================================================================
#ifndef _CUPS_CONTROLLER_LED_TYPES_H
#define _CUPS_CONTROLLER_LED_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "CupsController_LEDConfig.h"
#include "CupsController/Adapters/CupsController_LEDAdapterBase.h"
//==============================================================================
typedef WS2812_ColorT CupLEDColorT;
//------------------------------------------------------------------------------
typedef struct
{
	OBJECT_HEADER;
	
	CupsControllerLEDAdapterBaseT Adapter;
	
	CupLEDColorT Color;

} CupsControllerLED_T;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif
