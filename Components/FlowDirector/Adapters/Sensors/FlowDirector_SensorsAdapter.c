//==============================================================================
#include "FlowDirector_SensorsAdapter.h"
//==============================================================================
static void PrivateSensorsHandler(FlowDirectorSensorsT* device)
{
	FlowDirectorSensorsAdapterT* adapter = device->Adapter.Child;
	FlowDirectorSensorsStateT sensors_state = { 0 };
	
	device->LastState.Value = device->State.Value;
	
	sensors_state.Limit = (adapter->LimitSensorPort->IDR & adapter->LimitSensorPin) > 0;
	sensors_state.Limit = sensors_state.Limit == adapter->LimitSensorOnStateLogicLevel;
	
	sensors_state.Overcurrent = (adapter->OvercurrentSensorPort->IDR & adapter->OvercurrentSensorPin) > 0;
	sensors_state.Overcurrent = sensors_state.Overcurrent == adapter->OvercurrentSensorOnStateLogicLevel;
	
	device->State.Value = sensors_state.Value;
}
//------------------------------------------------------------------------------
static xResult PrivateSensorsRequestListener(FlowDirectorSensorsT* device, FlowDirectorSensorsRequestSelector selector, uint32_t args, uint32_t count)
{
	switch ((int)selector)
	{
		case FlowDirectorSensorsRequestUpdateState:
			PrivateSensorsHandler(device);
			break;
			
		default : return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
static void PrivateSensorsEventListener(FlowDirectorSensorsT* device, FlowDirectorSensorsEventSelector selector, uint32_t args, uint32_t count)
{
	switch ((int)selector)
	{
		case FlowDirectorSensorsEventTimeSynchronization:
			break;
	}
}
//==============================================================================
xResult FlowDirectorSensorsAdapterInit(FlowDirectorSensorsT* device, FlowDirectorSensorsAdapterT* adapter)
{
	if (device && adapter)
	{
		device->Adapter.Description = "FlowDirectorSensorsAdapterT";
		device->Adapter.Parent = device;
		device->Adapter.Child = adapter;
		
		device->Adapter.Handler = (FlowDirectorSensorsHandlerT)PrivateSensorsHandler;
		device->Adapter.RequestListener = (FlowDirectorSensorsRequestListenerT)PrivateSensorsRequestListener;
		device->Adapter.EventListener = (FlowDirectorSensorsEventListenerT)PrivateSensorsEventListener;
		
		return xResultAccept;
	}
	return xResultInvalidParameter;
}
//==============================================================================
