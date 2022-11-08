//==============================================================================
#ifndef CUPS_CONTROLLER_LED_ADAPTER_TYPES_H
#define CUPS_CONTROLLER_LED_ADAPTER_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif
//==============================================================================
#include "WS2812/WS2812.h"
//==============================================================================
typedef struct
{
	void* Timer;
	void* DMA;
	
	//WS2812_T Driver;
	
	uint8_t PWM_Channel;
	
	WS2812_BufT* DrawMemory;
	uint32_t DrawMemorySize;
	
} CupsControllerLEDAdapterT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif