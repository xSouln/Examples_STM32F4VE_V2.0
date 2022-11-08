//==============================================================================
#include "Slider_SensorsAdapter.h"
#include "Slider/Controls/Slider.h"
//==============================================================================
static void Handler(SliderT* device)
{
	SliderSensorsAdapterT* adapter = device->Sensors.Child;
	SliderSensorsStateT sensors_state = { 0 };
	
	device->Sensors.LastState.Value = device->Sensors.State.Value;
	
	sensors_state.Open = (adapter->SensorOpenPort->IDR & adapter->SensorOpenPin) > 0;
	sensors_state.Open = sensors_state.Open == adapter->SensorOpenOnStateLogicLevel;
	
	sensors_state.Close = (adapter->SensorClosePort->IDR & adapter->SensorClosePin) > 0;
	sensors_state.Close = sensors_state.Close == adapter->SensorCloseOnStateLogicLevel;
	
	sensors_state.Overcurrent = (adapter->SensorOvercurrentPort->IDR & adapter->SensorOvercurrentPin) > 0;
	sensors_state.Overcurrent = sensors_state.Overcurrent == adapter->SensorOvercurrentOnStateLogicLevel;
	
	device->Sensors.State.Value = sensors_state.Value;
}
//------------------------------------------------------------------------------
static xResult RequestListener(SliderT* device, SliderSensorsRequestSelector selector, uint32_t args, uint32_t count)
{
	switch ((int)selector)
	{
		case SliderSensorsRequestUpdateState:
			Handler(device);
			break;
			
		default : return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//==============================================================================
xResult SliderSensorsAdapterInit(SliderT* device, SliderSensorsAdapterT* adapter)
{
	if (device && adapter)
	{
		device->Sensors.Description = "SliderSensorsAdapterT";
		device->Sensors.Parent = device;
		device->Sensors.Child = adapter;
		
		device->Sensors.Interface.Handler = (SliderSensorsHandlerT)Handler;
		device->Sensors.Interface.RequestListener = (SliderSensorsRequestListenerT)RequestListener;
		
		return xResultAccept;
	}
	return xResultInvalidParameter;
}
//==============================================================================
