//==============================================================================
#include "FlowDirector_Sensors.h"
//==============================================================================
inline void FlowDirectorSensorsHandler(FlowDirectorT* device)
{
	device->Sensors.Adapter.Handler(&device->Sensors);
}
//------------------------------------------------------------------------------
inline void FlowDirectorSensorsTimeSynchronization(FlowDirectorT* device)
{
	device->Sensors.Adapter.EventListener(&device->Sensors, FlowDirectorSensorsEventTimeSynchronization, 0, 0);
}
//==============================================================================
xResult FlowDirectorSensorsInit(FlowDirectorT* device)
{
	if (device)
	{
		device->Sensors.Description = "FlowDirectorSensorsT";
		device->Sensors.Parent = device;
		
		return xResultAccept;
	}
	
	return xResultLinkError;
}
//==============================================================================