//==============================================================================
#include "Carousel_SensorsAdapter.h"
#include "Carousel/Controls/Carousel.h"
//==============================================================================
static void Handler(CarouselT* device)
{
	CarouselSensorsAdapterT* adapter = device->Sensors.Child;
	CarouselSensorsT sensors_state;
	
	device->Sensors.LastState.Value = device->Sensors.State.Value;
	
	sensors_state.ZeroMark = (adapter->SensorZeroMarkPort->IDR & adapter->SensorZeroMarkPin) > 0;
	sensors_state.ZeroMark = sensors_state.ZeroMark == adapter->SensorZeroMarkOnStateLogicLevel;
	
	sensors_state.Overcurrent = (adapter->SensorOvercurrentPort->IDR & adapter->SensorOvercurrentPin) > 0;
	sensors_state.Overcurrent = sensors_state.Overcurrent == adapter->SensorOvercurrentOnStateLogicLevel;
	
	device->Sensors.State.Value = sensors_state.Value;
}
//------------------------------------------------------------------------------
static xResult RequestListener(CarouselT* device, CarouselSensorsRequestSelector selector, uint32_t args, uint32_t count)
{
	switch ((int)selector)
	{
		case CarouselSensorsRequestUpdateState:
			Handler(device);
			break;
			
		default : return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//==============================================================================
xResult CarouselSensorsAdapterInit(CarouselT* device, CarouselSensorsAdapterT* adapter)
{
	if (device && adapter)
	{
		device->Sensors.Description = "CarouselSensorsAdapterT";
		device->Sensors.Parent = device;
		device->Sensors.Child = adapter;
		
		device->Sensors.Interface.Handler = (CarouselSensorsHandlerT)Handler;
		device->Sensors.Interface.RequestListener = (CarouselSensorsRequestListenerT)RequestListener;
		
		return xResultAccept;
	}
	return xResultInvalidParameter;
}
//==============================================================================
