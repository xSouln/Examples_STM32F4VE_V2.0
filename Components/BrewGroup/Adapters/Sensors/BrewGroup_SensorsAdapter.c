//==============================================================================
#include "BrewGroup_SensorsAdapter.h"
#include "BrewGroup/Controls/BrewGroup.h"
//==============================================================================
static void PrivateSensorsHandler(BrewGroupSensorsT* device)
{
	BrewGroupSensorsAdapterT* adapter = device->Adapter.Child;
	BrewGroupSensorsStateT sensors_state = { 0 };
	
	device->LastState.Value = device->State.Value;
	
	sensors_state.Open = (adapter->SensorOpenPort->IDR & adapter->SensorOpenPin) > 0;
	sensors_state.Open = sensors_state.Open == adapter->SensorOpenOnStateLogicLevel;
	
	sensors_state.Close = (adapter->SensorClosePort->IDR & adapter->SensorClosePin) > 0;
	sensors_state.Close = sensors_state.Close == adapter->SensorCloseOnStateLogicLevel;
	
	sensors_state.Overcurrent = (adapter->SensorOvercurrentPort->IDR & adapter->SensorOvercurrentPin) > 0;
	sensors_state.Overcurrent = sensors_state.Overcurrent == adapter->SensorOvercurrentOnStateLogicLevel;
	
	device->State.Value = sensors_state.Value;
}
//------------------------------------------------------------------------------
static xResult PrivateSensorsRequestListener(BrewGroupSensorsT* device, BrewGroupSensorsRequestSelector selector, uint32_t args, uint32_t count)
{
	switch ((int)selector)
	{
		case BrewGroupSensorsRequestUpdateState:
			PrivateSensorsHandler(device);
			break;
			
		default : return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
static void PrivateSensorsEventListener(BrewGroupSensorsT* device, BrewGroupSensorsEventSelector selector, uint32_t args, uint32_t count)
{
	switch ((int)selector)
	{
		case BrewGroupSensorsEventTimeSynchronization:
			break;
	}
}
//==============================================================================
xResult BrewGroupSensorsAdapterInit(BrewGroupSensorsT* device, BrewGroupSensorsAdapterT* adapter)
{
	if (device && adapter)
	{
		device->Adapter.Description = "BrewGroupSensorsAdapterT";
		device->Adapter.Parent = device;
		device->Adapter.Child = adapter;
		
		device->Adapter.Handler = (BrewGroupSensorsHandlerT)PrivateSensorsHandler;
		device->Adapter.RequestListener = (BrewGroupSensorsRequestListenerT)PrivateSensorsRequestListener;
		device->Adapter.EventListener = (BrewGroupSensorsEventListenerT)PrivateSensorsEventListener;
		
		return xResultAccept;
	}
	return xResultInvalidParameter;
}
//==============================================================================
