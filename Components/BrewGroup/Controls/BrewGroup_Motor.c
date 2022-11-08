//==============================================================================
#include "BrewGroup/Controls/BrewGroup_Types.h"
#include "BrewGroup_Sensors.h"
#include <string.h>
//==============================================================================
void BrewGroupMotorDisable(BrewGroupT* device)
{
	device->Motor.Adapter.RequestListener(&device->Motor, BrewGroupMotorRequestMoveStope, 0, 0);
	device->Motor.Status.Motion = BrewGroupMotionStateStopped;
}
//------------------------------------------------------------------------------
void BrewGroupMotorStop(BrewGroupT* device)
{
	BrewGroupMotorDisable(device);
	device->Motor.Status.MotionResult = BrewGroupMotionNoError;
}
//------------------------------------------------------------------------------
xResult BrewGroupMotorSetPosition(BrewGroupT* device, BrewGroupMoveRequestT* request)
{
	BrewGroupSensorsHandler(device);
	
	if (device->Sensors.State.Overcurrent)
	{
		device->Motor.Status.MotionResult = BrewGroupMotionOvercurrent;
		return xResultError;
	}
	
	if ((device->Sensors.State.Close && request->Position == BrewGroupPositionClose)
	|| (device->Sensors.State.Open && request->Position == BrewGroupPositionOpen))
	{
		return xResultAccept;
	}
	
	BrewGroupMotorDisable(device);
	
	device->Motor.TotalPower = device->Motor.Options.StartPower;
	device->Motor.RequestPower = request->Power;
	device->Motor.Status.MotionResult = BrewGroupMotionNoError;
	device->Motor.TimeOut = request->TimeOut;
	device->Motor.MoveTime = 0;
	device->Motor.Mode = request->Mode;
	device->Motor.AccelerationIncrement = device->Motor.Options.Acceleration / 1000;
	
	if (device->Motor.RequestPower > 100.0)
	{
		device->Motor.RequestPower = 100.0;
	}
	
	if (device->Motor.TotalPower > device->Motor.RequestPower)
	{
		device->Motor.TotalPower = device->Motor.RequestPower;
	}
	
	xResult result = xResultError;
	
	switch ((uint8_t)request->Position)
	{
		case BrewGroupPositionOpen:
			device->Motor.Triggers.Open = false;
			device->Motor.Status.Motion = BrewGroupMotionStateOpening;
			result = device->Motor.Adapter.RequestListener(&device->Motor, BrewGroupMotorRequestOpen, 0, 0);
			break;
		
		case BrewGroupPositionClose:
			device->Motor.Triggers.Close = false;
			device->Motor.Status.Motion = BrewGroupMotionStateClosing;
			result = device->Motor.Adapter.RequestListener(&device->Motor, BrewGroupMotorRequestClose, 0, 0);
			break;
		
		default : break;
	}
	
	return result;
}
//==============================================================================
void BrewGroupMotorHandler(BrewGroupT* device)
{
	device->Motor.Adapter.Handler(&device->Motor);
	
	if (device->Sensors.State.Overcurrent)
	{
		BrewGroupMotorDisable(device);
		
		if (device->Motor.Status.MotionResult != BrewGroupMotionOvercurrent)
		{
			device->Motor.Status.MotionResult = BrewGroupMotionOvercurrent;
			device->Terminal->EventListener(device, BrewGroupEventOvercurrent, 0, 0);
		}
	}
	
	if (device->Motor.Status.Motion == BrewGroupMotionStateOpening)
	{
		if (!device->Sensors.State.Close && device->Motor.Mode == BrewGroupMoveModeMoveOffTheSensor)
		{
			BrewGroupMotorDisable(device);
		}
		else if (device->Sensors.State.Open)
		{
			BrewGroupMotorDisable(device);
		
			if (!device->Motor.Triggers.Open)
			{
				device->Motor.Triggers.Open = true;
				device->Terminal->EventListener(device, BrewGroupEventOpen, 0, 0);
			}
		}
	}
	else if (device->Motor.Status.Motion == BrewGroupMotionStateClosing)
	{
		if (device->Sensors.State.Close || (!device->Sensors.State.Open && device->Motor.Mode == BrewGroupMoveModeMoveOffTheSensor))
		{
			BrewGroupMotorDisable(device);
		
			if (!device->Motor.Triggers.Close)
			{
				device->Motor.Triggers.Close = true;
				device->Terminal->EventListener(device, BrewGroupEventClose, 0, 0);
			}
		}
	}
	
	if (device->Motor.Status.Motion != BrewGroupMotionStateStopped)
	{
		if (device->Motor.MoveTime >= device->Motor.TimeOut)
		{
			BrewGroupMotorDisable(device);
			
			device->Motor.Status.MotionResult = BrewGroupMotionTimeout;
			device->Terminal->EventListener(device, BrewGroupEventTimeout, 0, 0);
			return;
		}
		
		device->Motor.Adapter.RequestListener(&device->Motor, BrewGroupMotorRequestSetPower, 0, 0);
	}
}
//------------------------------------------------------------------------------
void BrewGroupMotorTimeSynchronization(BrewGroupT* device)
{
	device->Motor.Adapter.EventListener(&device->Motor, BrewGroupMotorEventTimeSynchronization, 0, 0);
	
	if (device->Motor.Status.Motion != BrewGroupMotionStateStopped && device->Motor.TimeSynchronizationEnable)
	{
		device->Motor.MoveTime++;

		if (device->Motor.TotalPower < device->Motor.RequestPower)
		{
			device->Motor.TotalPower += device->Motor.AccelerationIncrement;
		}
	}
}
//------------------------------------------------------------------------------
xResult BrewGroupSetMotorOptions(BrewGroupT* device, BrewGroupMotorOptionsT* request)
{
	if (device->Motor.Status.Motion == BrewGroupMotionStateStopped)
	{
		memcpy(&device->Motor.Options, request, sizeof(device->Motor.Options));
		return xResultAccept;
	}
	return xResultBusy;
}
//------------------------------------------------------------------------------
xResult BrewGroupMotorInit(BrewGroupT* device)
{
	if (device)
	{
		device->Motor.Description = "BrewGroupMotorT";
		device->Motor.Parent = device;
	}
	return xResultAccept;
}
//==============================================================================
