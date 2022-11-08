//==============================================================================
#include "Carousel_Component.h"
#include "Carousel/Controls/Carousel.h"
#include "Adapters/DCMotor/Carousel_DCMotorAdapter.h"
#include "Adapters/Sensors/Carousel_SensorsAdapter.h"
#include "Carousel/Communications/Carousel_RxTransactions.h"
//==============================================================================
CarouselT Carousel;
//==============================================================================
static void EventListener(CarouselT* carousel, CarouselEventSelector event, uint32_t args, uint32_t count)
{
	switch ((uint8_t)event)
	{
		case CarouselEventStatusChanged:
			if (carousel->RxLine)
			{
				xRxTransactionTransmitEvent(carousel->RxLine->Tx,
																		CAROUSEL_DEVICE_KEY,
																		CAROUSEL_EVT_STATUS_CHANGED,
																		&carousel->Status,
																		sizeof(carousel->Status));
			}
			break;
		
		default : return;
	}
}
//------------------------------------------------------------------------------
static xResult RequestListener(CarouselT* carousel, CarouselRequestSelector event, uint32_t args, uint32_t count)
{
	switch ((uint8_t)event)
	{
		case CarouselRequestDelay :
			HAL_Delay(args);
			break;
		
		default : return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
const static CarouselInterfaceT Interface =
{
	.EventListener = (CarouselEventListenerT)EventListener,
	.RequestListener = (CarouselRequestListenerT)RequestListener,
};
//------------------------------------------------------------------------------
CarouselDCMotorAdapterT CarouselDCMotorAdapter =
{
	.PWM_ForwardTimer = (REG_TIM_T*)TIM4,
	.PWM_BackwardTimer = (REG_TIM_T*)TIM4,
	.EncoderTimer = (REG_TIM_T*)TIM2,
	
	.PWM_ForwardChannel = 1,
	.PWM_BackwardChannel = 0,
};
//------------------------------------------------------------------------------
CarouselSensorsAdapterT CarouselSensorsAdapter =
{
	.SensorZeroMarkPort = CAROUSEL_SENSOR_ZERO_MARK_GPIO_Port,
	.SensorZeroMarkPin = CAROUSEL_SENSOR_ZERO_MARK_Pin,
	.SensorZeroMarkOnStateLogicLevel = 1,
	
	.SensorOvercurrentPort = CAROUSEL_MOTOR_OVERCURRENT_SENSOR_GPIO_Port,
	.SensorOvercurrentPin = CAROUSEL_MOTOR_OVERCURRENT_SENSOR_Pin,
	.SensorOvercurrentOnStateLogicLevel = 0,
};
//==============================================================================
xResult CarouselComponentInit(void* parent)
{
	CarouselInit(&Carousel, parent, (CarouselInterfaceT*)&Interface);
	CarouselSensorsAdapterInit(&Carousel, &CarouselSensorsAdapter);
	CarouselDCMotorAdapterInit(&Carousel, &CarouselDCMotorAdapter);
	
  return 0;
}
//==============================================================================
