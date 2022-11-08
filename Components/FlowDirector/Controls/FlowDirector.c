//==============================================================================
#include "FlowDirector.h"
//==============================================================================
void FlowDirectorHandler(FlowDirectorT* device)
{
	FlowDirectorSensorsHandler(device);
	FlowDirectorMotorHandler(device);
}
//------------------------------------------------------------------------------
void FlowDirectorTimeSynchronization(FlowDirectorT* device)
{
	FlowDirectorSensorsTimeSynchronization(device);
	FlowDirectorMotorTimeSynchronization(device);
}
//==============================================================================

//==============================================================================
xResult FlowDirectorInit(FlowDirectorT* device, void* parent, FlowDirectorTerminalT* terminal)
{
	if (device && terminal)
	{
		device->Description = "FlowDirectorT";
		device->Parent = parent;
		device->Terminal = terminal;
		
		return xResultAccept;
	}
	return xResultLinkError;
}
//==============================================================================
