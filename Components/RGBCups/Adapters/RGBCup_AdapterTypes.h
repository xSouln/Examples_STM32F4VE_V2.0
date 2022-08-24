//==============================================================================
#ifndef RGB_CUP_ADAPTER_TYPES_H
#define RGB_CUP_ADAPTER_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif
//==============================================================================
#include "RGBCups/RGBCups_Types.h"
//==============================================================================
typedef struct
{
	volatile void* DMA;
	volatile void* Timer;
	
	uint8_t PWM_Channel;
	
	WS2812_BufT* DrawMemory;
	uint32_t DrawMemorySize;
	
} RGBCupAdapterT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* RGB_CUP_ADAPTER_TYPES_H */