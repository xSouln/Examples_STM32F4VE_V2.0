//==============================================================================
#ifndef _CAROUSEL_RX_TRANSACTIONS_H
#define _CAROUSEL_RX_TRANSACTIONS_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Common/xRxTransaction.h"
#include "Common/xTx.h"
#include "Carousel/Controls/Carousel.h"
//==============================================================================
typedef enum
{
  CAROUSEL_GET_FIRMWARE_VERSION = 100,
	CAROUSEL_GET_STATUS,
	CAROUSEL_GET_POSITION,
	CAROUSEL_GET_OPTIONS,
	CAROUSEL_GET_MOTION_STATE,
	CAROUSEL_GET_CALIBRATION,

	CAROUSEL_SET = 1000,
	CAROUSEL_SET_POSITION,
	CAROUSEL_SET_OPTIONS,
	CAROUSEL_SET_CALIBRATION,
	CAROUSEL_SET_POD,

	CAROUSEL_TRY = 2000,
	CAROUSEL_TRY_STOP,
	CAROUSEL_TRY_RESET_POSITION,
	CAROUSEL_TRY_CALIBRATE,

	CAROUSEL_EVT = 10000,
	CAROUSEL_EVT_STATUS_CHANGED
	
} CAROUSEL_TRANSACTIONS;
//==============================================================================
typedef struct
{
	float TotalAngle;
	float RequestAngle;
	
	int EncoderPosition;
	
} CarouselResponseGetPositionT;
//------------------------------------------------------------------------------
typedef struct
{
	CarouselStatusT Status;
	
	float TotalAngle;
	float RequestAngle;
	
	float Power;
	
	int MoveTime;
	
	int EncoderPosition;
	
} CarouselResponseGetMotionStateT;
//------------------------------------------------------------------------------
typedef CarouselResponseGetPositionT CarouselResponseTryClearPositionT;
typedef CarouselResponseGetPositionT CarouselResponseSetPositionT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

