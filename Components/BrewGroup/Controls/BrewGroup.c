//==============================================================================
#include "BrewGroup.h"
//==============================================================================
inline void BrewGroupHandler(BrewGroupT* device)
{
	BrewGroupSensorsHandler(device);
	BrewGroupMotorHandler(device);
	
	TermostatHandler(&device->Termostat);
	FlowMeterHandler(&device->FlowMeter);
	WaterPumpHandler(&device->WaterPump);
}
//------------------------------------------------------------------------------
inline void BrewGroupTimeSynchronization(BrewGroupT* device)
{
	BrewGroupSensorsTimeSynchronization(device);
	BrewGroupMotorTimeSynchronization(device);
	
	TermostatTimeSynchronization(&device->Termostat);
	FlowMeterTimeSynchronization(&device->FlowMeter);
	WaterPumpTimeSynchronization(&device->WaterPump);
}
//==============================================================================
xResult BrewGroupClose(BrewGroupT* device)
{
	BrewGroupMoveRequestT request =
	{
		.Power = BREW_GROUP_DEFAULT_MOVE_POWER,
		.Mode = BrewGroupMoveModeCommon,
		.TimeOut = BREW_GROUP_DEFAULT_TIMEOUT,
		.Position = BrewGroupPositionClose
	};
	
	return BrewGroupMotorSetPosition(device, &request);
}
//------------------------------------------------------------------------------
xResult BrewGroupOpen(BrewGroupT* device)
{
	BrewGroupMoveRequestT request =
	{
		.Power = BREW_GROUP_DEFAULT_MOVE_POWER,
		.Mode = BrewGroupMoveModeCommon,
		.TimeOut = BREW_GROUP_DEFAULT_TIMEOUT,
		.Position = BrewGroupPositionOpen
	};
	
	return BrewGroupMotorSetPosition(device, &request);
}
//==============================================================================
xResult BrewGroupInit(BrewGroupT* device, void* parent, BrewGroupTerminalT* terminal)
{
	extern const xRxRequestT BrewGroupRequests[];
	
	if (device && terminal)
	{
		device->Description = "BrewGroupT";
		device->Parent = parent;
		device->Terminal = terminal;
		
		device->Requests = (xRxRequestT*)BrewGroupRequests;
		
		return xResultAccept;
	}
	return xResultLinkError;
}
//==============================================================================
