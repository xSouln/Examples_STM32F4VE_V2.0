//==============================================================================
#include "BrewGroup_FlowMeterAdapter.h"
//==============================================================================
static void PrivateFlowMeterHandler(FlowMeterT* device)
{
	
}
//------------------------------------------------------------------------------
static xResult PrivateFlowMeterRequestListener(FlowMeterT* device,
																								FlowMeterRequestSelector selector,
																								uint32_t args,
																								uint32_t count)
{
	BrewGroupFlowMeterAdapterT* adapter = device->Adapter.Child;
	
	switch ((int)selector)
	{
		case FlowMeterRequestUpdateCounter:
			device->Counter += adapter->Data.Register->Counter;
			adapter->Data.Register->Counter = 0;
			break;
		
		case FlowMeterRequestResetCounter:
			adapter->Data.Register->Counter = 0;
			break;
		
		case FlowMeterRequestEnable:
			adapter->Data.Register->Control1.CounterEnable = true;
			break;
		
		case FlowMeterRequestDisable:
			adapter->Data.Register->Control1.CounterEnable = false;
			break;
		
		default: return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
static void PrivateFlowMeterEventListener(FlowMeterT* device,
																								FlowMeterEventSelector selector,
																								uint32_t args,
																								uint32_t count)
{
	switch ((int)selector)
	{
		default: break;
	}
}
//==============================================================================
xResult BrewGroupFlowMeterAdapterInit(FlowMeterT* device, BrewGroupFlowMeterAdapterT* adapter)
{
	if (device && adapter)
	{
		device->Adapter.Description = "BrewGroupFlowMeterAdapterT";
		device->Adapter.Parent = device;
		device->Adapter.Child = adapter;
		
		adapter->Data.Register = (REG_TIM_T*)adapter->Timer->Instance;
		
		device->Adapter.Handler = (FlowMeterHandlerT)PrivateFlowMeterHandler;
		device->Adapter.EventListener = (FlowMeterEventListenerT)PrivateFlowMeterEventListener;
		device->Adapter.RequestListener = (FlowMeterRequestListenerT)PrivateFlowMeterRequestListener;
		
		return xResultAccept;
	}
	return xResultInvalidParameter;
}
//==============================================================================
