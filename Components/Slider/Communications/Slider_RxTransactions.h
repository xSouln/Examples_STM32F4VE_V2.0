//==============================================================================
#ifndef _SLIDER_RX_TRANSACTIONS_H
#define _SLIDER_RX_TRANSACTIONS_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Common/xRxTransaction.h"
#include "Common/xTx.h"
#include "Slider/Controls/Slider.h"
#include "Slider/Slider_Info.h"
//==============================================================================
typedef enum
{
  SLIDER_GET_FIRMWARE_VERSION = 100,
	SLIDER_GET_STATUS,
	SLIDER_GET_OPTIONS,

	SLIDER_SET = 1000,
	SLIDER_SET_OPTIONS,

	SLIDER_TRY = 2000,
	SLIDER_TRY_OPEN,
	SLIDER_TRY_CLOSE,
	SLIDER_TRY_STOP,
	SLIDER_TRY_DROP_POD,
	SLIDER_TRY_SET_POSITION,

	SLIDER_EVT = 10000,
	SLIDER_EVT_OPEN,
	SLIDER_EVT_CLOSE,
	SLIDER_EVT_OVERCURRENT,
	SLIDER_EVT_STATUS_CHANGED
	
} SLIDER_TRANSACTIONS;
//==============================================================================
typedef SliderMoveRequestT SliderRequestTryOpenT;
//------------------------------------------------------------------------------
typedef struct
{
	uint32_t TimeOut;
	
} SliderRequestTryCloseT;
//------------------------------------------------------------------------------
typedef struct
{
	uint32_t OpenTime;
	
} RequestTryDropPodT;
//------------------------------------------------------------------------------
typedef struct
{
	SliderStatusT Slider;
	SliderSensorsStateT Sensors;
	SliderMotorStatusT Motor;
	
} ResponseGetStatusT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

