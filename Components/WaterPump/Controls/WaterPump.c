//==============================================================================
#include "WaterPump.h"
//==============================================================================
inline void WaterPumpHandler(WaterPumpT* device)
{
	device->Adapter.Handler(device);
}
//------------------------------------------------------------------------------
inline void WaterPumpTimeSynchronization(WaterPumpT* device)
{
	device->Adapter.EventListener(device, WaterPumpEventTimeSynchronization, 0, 0);
}
//------------------------------------------------------------------------------
void WaterPumpEnable(WaterPumpT* device)
{
	if (device->Adapter.RequestListener(device, WaterPumpRequestEnable, 0, 0))
	{
		device->Status.IsEnable = true;
	}
}
//------------------------------------------------------------------------------
void WaterPumpDisable(WaterPumpT* device)
{
	device->Adapter.RequestListener(device, WaterPumpRequestDisable, 0, 0);
	device->Status.IsEnable = false;
}
//==============================================================================
xResult WaterPumpInit(WaterPumpT* device, void* parent)
{
	if (device)
	{
		device->Description = "WaterPumpT";
		device->Parent = parent;
		
		return xResultAccept;
	}
	
	return xResultLinkError;
}
//==============================================================================