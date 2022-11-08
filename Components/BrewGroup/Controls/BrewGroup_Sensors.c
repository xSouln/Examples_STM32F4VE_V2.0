//==============================================================================
#include "BrewGroup_Sensors.h"
//==============================================================================
inline void BrewGroupSensorsHandler(BrewGroupT* device)
{
	device->Sensors.Adapter.Handler(&device->Sensors);
}
//------------------------------------------------------------------------------
inline void BrewGroupSensorsTimeSynchronization(BrewGroupT* device)
{
	device->Sensors.Adapter.EventListener(&device->Sensors, BrewGroupSensorsEventTimeSynchronization, 0, 0);
}
//==============================================================================
xResult BrewGroupSensorsInit(BrewGroupT* device)
{
	if (device)
	{
		device->Sensors.Description = "BrewGroupSensorsT";
		device->Sensors.Parent = device;
		
		return xResultAccept;
	}
	
	return xResultLinkError;
}
//==============================================================================