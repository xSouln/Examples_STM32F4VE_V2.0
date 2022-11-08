//==============================================================================
#ifndef _CUPS_CONTROLLER_CONFIG_H
#define _CUPS_CONTROLLER_CONFIG_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "WS2812/WS2812.h"
//==============================================================================
#define CUPS_CONTROLLER_LED_PIXELS_COUNT_CUP1 8
#define CUPS_CONTROLLER_LED_PIXELS_COUNT_CUP2 8
#define CUPS_CONTROLLER_LED_PIXELS_COUNT_CUP3 8
#define CUPS_CONTROLLER_LED_PIXELS_COUNT_CUP4 8

#define CUPS_CONTROLLER_LED_SYNC_START_DATA_COUNT 50
#define CUPS_CONTROLLER_LED_SYNC_END_DATA_COUNT 1

#define CUPS_CONTROLLER_LED_DATA_BUFFER_SIZE_CUP1 (CUPS_CONTROLLER_LED_PIXELS_COUNT_CUP1 * WS2812_BITS_IN_PIXEL)
#define CUPS_CONTROLLER_LED_DATA_BUFFER_SIZE_CUP2 (CUPS_CONTROLLER_LED_PIXELS_COUNT_CUP2 * WS2812_BITS_IN_PIXEL)
#define CUPS_CONTROLLER_LED_DATA_BUFFER_SIZE_CUP3 (CUPS_CONTROLLER_LED_PIXELS_COUNT_CUP2 * WS2812_BITS_IN_PIXEL)
#define CUPS_CONTROLLER_LED_DATA_BUFFER_SIZE_CUP4 (CUPS_CONTROLLER_LED_PIXELS_COUNT_CUP2 * WS2812_BITS_IN_PIXEL)

#define CUPS_CONTROLLER_DRAW_MANAGER_UPDATE_TIME 10
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif
