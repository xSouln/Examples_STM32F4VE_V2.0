//==============================================================================
#include "Slider_Component.h"
#include "Slider/Adapters/DCMotor/Slider_DCMotorAdapter.h"
#include "Slider/Adapters/Sensors/Slider_SensorsAdapter.h"
#include "Communications/Slider_RxTransactions.h"
//==============================================================================
SliderT Slider;
//==============================================================================

//==============================================================================
static void EventListener(SliderT* Slider, SliderEventSelector event, uint32_t args, uint32_t count)
{
	ResponseGetStatusT response =
	{
		.Slider = Slider->Status,
		.Sensors = Slider->Sensors.State,
		.Motor = Slider->Motor.Status
	};
	
	switch ((uint8_t)event)
	{
		case SliderEventOpen:
			if (Slider->RxLine)
			{
				xRxTransactionTransmitEvent(Slider->RxLine->Tx,
																	SLIDER_DEVICE_KEY,
																	SLIDER_EVT_OPEN,
																	&response,
																	sizeof(response));
			}
			break;
		
		case SliderEventClose:
			if (Slider->RxLine)
			{
				xRxTransactionTransmitEvent(Slider->RxLine->Tx,
																		SLIDER_DEVICE_KEY,
																		SLIDER_EVT_CLOSE,
																		&response,
																		sizeof(response));
			}
			break;
			
		case SliderEventOvercurrent:
			if (Slider->RxLine)
			{
				xRxTransactionTransmitEvent(Slider->RxLine->Tx,
																		SLIDER_DEVICE_KEY,
																		SLIDER_EVT_OVERCURRENT,
																		&response,
																		sizeof(response));
			}
			break;
			
		case SliderEventStatusChanged:
			if (Slider->RxLine)
			{
				xRxTransactionTransmitEvent(Slider->RxLine->Tx,
																		SLIDER_DEVICE_KEY,
																		SLIDER_EVT_STATUS_CHANGED,
																		&response,
																		sizeof(response));
			}
			break;
		
		default : return;
	}
}
//------------------------------------------------------------------------------
static xResult RequestListener(SliderT* Slider, SliderRequestSelector event, uint32_t args, uint32_t count)
{
	switch ((uint8_t)event)
	{
		case SliderRequestDelay :
			HAL_Delay(args);
			break;
		
		default : return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
const static SliderInterfaceT Interface =
{
	.EventListener = (SliderEventListenerT)EventListener,
	.RequestListener = (SliderRequestListenerT)RequestListener,
};
//------------------------------------------------------------------------------
SliderDCMotorAdapterT SliderDCMotorAdapter =
{
	.PWM_ForwardTimer = (REG_TIM_T*)TIM4,
	.PWM_BackwardTimer = (REG_TIM_T*)TIM4,
	
	.PWM_ForwardChannel = 2,
	.PWM_BackwardChannel = 3,
};
//------------------------------------------------------------------------------
SliderSensorsAdapterT SliderSensorsAdapter =
{
	.SensorClosePort = SLIDER_SENSOR_CLOSE_GPIO_Port,
	.SensorClosePin = SLIDER_SENSOR_CLOSE_Pin,
	.SensorCloseOnStateLogicLevel = 0,
	
	.SensorOpenPort = SLIDER_SENSOR_OPEN_GPIO_Port,
	.SensorOpenPin = SLIDER_SENSOR_OPEN_Pin,
	.SensorOpenOnStateLogicLevel = 0,
	
	.SensorOvercurrentPort = SLIDER_SENSOR_OVERCURRENT_GPIO_Port,
	.SensorOvercurrentPin = SLIDER_SENSOR_OVERCURRENT_Pin,
	.SensorOvercurrentOnStateLogicLevel = 0,
};
//==============================================================================
xResult SliderComponentInit(void* parent)
{
	SliderInit(&Slider, parent, (SliderInterfaceT*)&Interface);
	SliderSensorsAdapterInit(&Slider, &SliderSensorsAdapter);
	SliderDCMotorAdapterInit(&Slider, &SliderDCMotorAdapter);
	
  return xResultAccept;
}
//==============================================================================
