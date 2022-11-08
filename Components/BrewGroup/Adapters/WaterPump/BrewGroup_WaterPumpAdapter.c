//==============================================================================
#include "BrewGroup_WaterPumpAdapter.h"
//==============================================================================
static void PrivateWaterPumpHandler(WaterPumpT* device)
{
	
}
//------------------------------------------------------------------------------
static void PrivateWaterPumpEventListener(WaterPumpT* device, WaterPumpEventSelector selector, uint32_t args, uint32_t count)
{
	switch ((int)selector)
	{
		default : break;
	}
}
//------------------------------------------------------------------------------
static xResult PrivateWaterPumpRequestListener(WaterPumpT* device, WaterPumpRequestSelector selector, uint32_t args, uint32_t count)
{
	BrewGroupWaterPumpAdapterT* adapter = device->Adapter.Child;

	switch ((int)selector)
	{
		case WaterPumpRequestEnable:
			if (adapter->ControlOnStateLogicLevel) { adapter->ControlPort->ODR |= adapter->ControlPin; }
			else { adapter->ControlPort->ODR &= ~adapter->ControlPin; }
			break;

		case WaterPumpRequestDisable:
			if (adapter->ControlOnStateLogicLevel) { adapter->ControlPort->ODR &= ~adapter->ControlPin; }
			else { adapter->ControlPort->ODR |= adapter->ControlPin; }
			break;

		default : return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//==============================================================================
xResult BrewGroupWaterPumpAdapterInit(WaterPumpT* device, BrewGroupWaterPumpAdapterT* adapter)
{
	if (device && adapter)
	{
		device->Adapter.Description = "BrewGroupWaterPumpAdapterT";
		device->Adapter.Parent = device;
		device->Adapter.Child = adapter;
		
		device->Adapter.Handler = (WaterPumpHandlerT)PrivateWaterPumpHandler;
		device->Adapter.EventListener = (WaterPumpEventListenerT)PrivateWaterPumpEventListener;
		device->Adapter.RequestListener = (WaterPumpRequestListenerT)PrivateWaterPumpRequestListener;
		
		return xResultAccept;
	}
	return xResultInvalidParameter;
}
//==============================================================================
