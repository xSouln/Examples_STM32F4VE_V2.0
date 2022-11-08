/*
 *
 */
//==============================================================================
#include "SLIDER_RxTransactions.h"
//==============================================================================
static void GetStatus(xRxRequestManagerT* manager)
{
	SliderT* Slider = manager->Device;
	
	ResponseGetStatusT response =
	{
		.Slider = Slider->Status,
		.Sensors = Slider->Sensors.State,
		.Motor = Slider->Motor.Status
	};
	
	xRxPutInResponseBuffer(manager->RxLine, &response, sizeof(response));
}
//----------------------------------------------------------------------------
static void GetOptions(xRxRequestManagerT* manager)
{
	SliderT* Slider = manager->Device;
	
	xRxPutInResponseBuffer(manager->RxLine, &Slider->Motor.Options, sizeof(Slider->Motor.Options));
}
//==============================================================================
static void SetOptions(xRxRequestManagerT* manager, SliderMotorOptionsT* request)
{
	SliderT* Slider = manager->Device;
	int16_t result = SliderSetOptions(Slider, request);
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
	xRxPutInResponseBuffer(manager->RxLine, &Slider->Motor.Options, sizeof(Slider->Motor.Options));
}
//==============================================================================
static void TrySetPosition(xRxRequestManagerT* manager, SliderRequestTryOpenT* request)
{
	SliderT* Slider = manager->Device;
	Slider->RxLine = manager->RxLine;
	
	int16_t result = SliderSetPosition(Slider, request);
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
	GetStatus(manager);
}
//----------------------------------------------------------------------------
static void TryOpen(xRxRequestManagerT* manager)
{
	SliderT* Slider = manager->Device;
	Slider->RxLine = manager->RxLine;
	
	int16_t result = SliderOpen(Slider);
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
	GetStatus(manager);
}
//----------------------------------------------------------------------------
static void TryClose(xRxRequestManagerT* manager)
{
	SliderT* Slider = manager->Device;
	Slider->RxLine = manager->RxLine;
	
	int16_t result = SliderClose(Slider);
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
	GetStatus(manager);
}
//----------------------------------------------------------------------------
static void TryStop(xRxRequestManagerT* manager)
{
	SliderT* Slider = manager->Device;
	int16_t result = xResultAccept;
	SliderStop(Slider);
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
	GetStatus(manager);
}
//----------------------------------------------------------------------------
static void TryDropPod(xRxRequestManagerT* manager, RequestTryDropPodT* request)
{
	SliderT* Slider = manager->Device;
	int16_t result = xResultAccept;
	SliderDropPod(Slider, request->OpenTime);
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
	GetStatus(manager);
}
//==============================================================================
const xRxTransactionT SliderTransactions[] =
{
	//----------------------------------------------------------------------------
	//GET
	{
		.Id = SLIDER_GET_STATUS,
		.Action = (xRxTransactionAction)GetStatus,
	},
	
	{
		.Id = SLIDER_GET_OPTIONS,
		.Action = (xRxTransactionAction)GetOptions,
	},
	//----------------------------------------------------------------------------
	//SET
	{
		.Id = SLIDER_SET_OPTIONS,
		.Action = (xRxTransactionAction)SetOptions,
	},
	//----------------------------------------------------------------------------
	//TRY
	{
		.Id = SLIDER_TRY_OPEN,
		.Action = (xRxTransactionAction)TryOpen,
	},
	
	{
		.Id = SLIDER_TRY_CLOSE,
		.Action = (xRxTransactionAction)TryClose,
	},
	
	{
		.Id = SLIDER_TRY_SET_POSITION,
		.Action = (xRxTransactionAction)TrySetPosition,
	},
	
	{
		.Id = SLIDER_TRY_STOP,
		.Action = (xRxTransactionAction)TryStop,
	},
	
	{
		.Id = SLIDER_TRY_DROP_POD,
		.Action = (xRxTransactionAction)TryDropPod,
	},
	//----------------------------------------------------------------------------
	// end of transactions marker
  { .Id = -1 }
};
//==============================================================================
