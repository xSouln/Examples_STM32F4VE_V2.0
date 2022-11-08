//==============================================================================
#include "FlowMeter.h"
//==============================================================================
void FlowMeterUpdate(FlowMeterT* device)
{
	device->Adapter.RequestListener(device, FlowMeterRequestUpdateCounter, 0, 0);
	
	device->TotalVolume = device->Counter * device->Calibration.k0;
}
//------------------------------------------------------------------------------
void FlowMeterReset(FlowMeterT* device)
{
	device->Adapter.RequestListener(device, FlowMeterRequestResetCounter, 0, 0);
	
	device->TotalVolume = 0;
}
//------------------------------------------------------------------------------
xResult FlowMeterEnable(FlowMeterT* device)
{
	xResult result = device->Adapter.RequestListener(device, FlowMeterRequestEnable, 0, 0);
	
	if (result == xResultAccept)
	{
		device->Status.IsEnable = true;
	}
	
	return result;
}
//------------------------------------------------------------------------------
void FlowMeterDisable(FlowMeterT* device)
{
	device->Adapter.RequestListener(device, FlowMeterRequestDisable, 0, 0);
	device->Status.IsEnable = false;
}
//==============================================================================
inline void FlowMeterHandler(FlowMeterT* device)
{
	device->Adapter.Handler(device);
	
	if (!device->UpdateTime)
	{
		device->UpdateTime = device->Options.UpdateTime;
		
		FlowMeterUpdate(device);
	}
}
//------------------------------------------------------------------------------
inline void FlowMeterTimeSynchronization(FlowMeterT* device)
{
	device->Adapter.EventListener(device, FlowMeterEventTimeSynchronization, 0, 0);
	
	if (device->UpdateTime)
	{
		device->UpdateTime--;
	}
}
//==============================================================================
xResult FlowMeterInit(FlowMeterT* device, void* parent)
{
	if (device)
	{
		device->Description = "FlowMeterT";
		device->Parent = parent;
		
		device->Options.UpdateTime = FLOW_METER_UPDATE_TIME;
		device->Calibration.k0 = FLOW_METER_DEFAULT_CALIBRATION_VALUE_K0;
		
		return xResultAccept;
	}
	
	return xResultLinkError;
}
//==============================================================================