/*
 *
 */
//==============================================================================
#include "Carousel_RxTransactions.h"
//==============================================================================
static void GetStatus(xRxRequestManagerT* manager)
{
	CarouselT* carousel = manager->Device;
	
	xRxPutInResponseBuffer(manager->RxLine, &carousel->Status, sizeof(carousel->Status));
}
//----------------------------------------------------------------------------
static void GetOptions(xRxRequestManagerT* manager)
{
	CarouselT* carousel = manager->Device;
	
	xRxPutInResponseBuffer(manager->RxLine, &carousel->Motor.Options, sizeof(carousel->Motor.Options));
}
//----------------------------------------------------------------------------
static void GetPosition(xRxRequestManagerT* manager)
{
	CarouselT* carousel = manager->Device;
	
	CarouselResponseGetPositionT response =
	{
		.RequestAngle = carousel->RequestAngle,
		.TotalAngle = carousel->TotalAngle,
		.EncoderPosition = carousel->Motor.Interface->GetValue(carousel, CarouselMotorValueEncoderPosition)
	};
	
	xRxPutInResponseBuffer(manager->RxLine, &response, sizeof(response));
}
//----------------------------------------------------------------------------
static void GetMotionState(xRxRequestManagerT* manager)
{
	CarouselT* carousel = manager->Device;
	
	CarouselResponseGetMotionStateT response =
	{
		.Status = carousel->Status,
		.RequestAngle = carousel->RequestAngle,
		.TotalAngle = carousel->TotalAngle,
		.Power = carousel->Motor.TotalPower,
		
		.MoveTime = carousel->Motor.MoveTime,
		
		.EncoderPosition = carousel->Motor.Interface->GetValue(carousel, CarouselMotorValueEncoderPosition)
	};
	
	xRxPutInResponseBuffer(manager->RxLine, &response, sizeof(response));
}
//----------------------------------------------------------------------------
static void GetCalibration(xRxRequestManagerT* manager)
{
	CarouselT* carousel = manager->Device;
	
	xRxPutInResponseBuffer(manager->RxLine, &carousel->Calibration, sizeof(carousel->Calibration));
}
//==============================================================================
static void SetPosition(xRxRequestManagerT* manager, CarouselRequestSetPositionT* request)
{
	CarouselT* carousel = manager->Device;
	int16_t result = CarouselSetPosition(carousel, request);
	carousel->RxLine = manager->RxLine;
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
	xRxPutInResponseBuffer(manager->RxLine, &carousel->Status, sizeof(carousel->Status));
}
//----------------------------------------------------------------------------
static void SetOptions(xRxRequestManagerT* manager, CarouselRequestSetOptionsT* request)
{
	CarouselT* carousel = manager->Device;
	int16_t result = CarouselSetOptions(carousel, request);
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
	xRxPutInResponseBuffer(manager->RxLine, &carousel->Motor.Options, sizeof(carousel->Motor.Options));
}
//----------------------------------------------------------------------------
static void SetCalibration(xRxRequestManagerT* manager, CarouselCalibrationT* request)
{
	CarouselT* carousel = manager->Device;
	int16_t result = CarouselSetColibration(carousel, request);
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
}
//----------------------------------------------------------------------------
static void SetPod(xRxRequestManagerT* manager, uint8_t* request)
{
	CarouselT* carousel = manager->Device;
	int16_t result = CarouselSetPod(carousel, *request);
	carousel->RxLine = manager->RxLine;
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
}
//==============================================================================
static void TryResetPosition(xRxRequestManagerT* manager)
{
	CarouselT* carousel = manager->Device;
	int16_t result = CarouselResetPosition(carousel);
	
	CarouselResponseTryClearPositionT response =
	{
		.RequestAngle = carousel->RequestAngle,
		.TotalAngle = carousel->TotalAngle,
		.EncoderPosition = carousel->Motor.Interface->GetValue(carousel, CarouselMotorValueEncoderPosition)
	};
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
	xRxPutInResponseBuffer(manager->RxLine, &response, sizeof(response));
}
//----------------------------------------------------------------------------
static void TryStop(xRxRequestManagerT* manager)
{
	CarouselT* carousel = manager->Device;
	int16_t result = CarouselStop(carousel);
	carousel->RxLine = manager->RxLine;
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
	xRxPutInResponseBuffer(manager->RxLine, &carousel->Status, sizeof(carousel->Status));
}
//----------------------------------------------------------------------------
static void TryCalibrate(xRxRequestManagerT* manager)
{
	CarouselT* carousel = manager->Device;
	int16_t result = CarouselCalibrateAsync(carousel);
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
	xRxPutInResponseBuffer(manager->RxLine, &carousel->Status, sizeof(carousel->Status));
}
//==============================================================================
const xRxTransactionT CarouselTransactions[] =
{
	//----------------------------------------------------------------------------
	//GET
	{
		.Id = CAROUSEL_GET_STATUS,
		.Action = (xRxTransactionAction)GetStatus,
	},
	
	{
		.Id = CAROUSEL_GET_OPTIONS,
		.Action = (xRxTransactionAction)GetOptions,
	},
	
	{
		.Id = CAROUSEL_GET_POSITION,
		.Action = (xRxTransactionAction)GetPosition,
	},
	
	{
		.Id = CAROUSEL_GET_MOTION_STATE,
		.Action = (xRxTransactionAction)GetMotionState,
	},
	
	{
		.Id = CAROUSEL_GET_CALIBRATION,
		.Action = (xRxTransactionAction)GetCalibration,
	},
	//----------------------------------------------------------------------------
	//SET
	{
		.Id = CAROUSEL_SET_POSITION,
		.Action = (xRxTransactionAction)SetPosition,
	},
	
	{
		.Id = CAROUSEL_SET_OPTIONS,
		.Action = (xRxTransactionAction)SetOptions,
	},
	
	{
		.Id = CAROUSEL_SET_CALIBRATION,
		.Action = (xRxTransactionAction)SetCalibration,
	},
	
	{
		.Id = CAROUSEL_SET_POD,
		.Action = (xRxTransactionAction)SetPod,
	},
	//----------------------------------------------------------------------------
	//TRY
	{
		.Id = CAROUSEL_TRY_RESET_POSITION,
		.Action = (xRxTransactionAction)TryResetPosition,
	},
	
	{
		.Id = CAROUSEL_TRY_STOP,
		.Action = (xRxTransactionAction)TryStop,
	},
	
	{
		.Id = CAROUSEL_TRY_CALIBRATE,
		.Action = (xRxTransactionAction)TryCalibrate,
	},
	//----------------------------------------------------------------------------
	// end of transactions marker
  { .Id = -1 }
};
//==============================================================================
