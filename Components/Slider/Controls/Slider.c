//==============================================================================
#include <string.h>
#include "Slider.h"
//==============================================================================
extern void SliderMotorHandler(SliderT* device);
extern void SliderSensorsHandler(SliderT* device);
extern void SliderMotorDisable(SliderT* device);
xResult SliderSetPosition(SliderT* device, SliderMoveRequestT* request);
//==============================================================================
void SliderHandler(SliderT* device)
{
	SliderSensorsHandler(device);
	SliderMotorHandler(device);
	
	if ((device->Motor.Status.Motion != SliderMotionStateStopped)
		|| (device->Status.State == SliderStateIdle)
		|| (device->Status.State == SliderStateRealised)
		|| (device->Status.Result != SliderResultNoError))
	{
		return;
	}
	
	if (device->Motor.Status.MotionResult != SliderMotionNoError)
	{
		device->Status.Result = device->Motor.Status.MotionResult;
		device->Interface->EventListener(device, SliderEventStatusChanged, 0, 0);
		return;
	}
	
	if (device->Status.State == SliderStateIsOpen && device->OpenTime)
	{
		device->OpenTime--;
		return;
	}
	
	SliderMoveRequestT request;
	
	switch (device->Status.State)
	{
		case SliderStateOpening:
			device->Status.State = SliderStateIsOpen;
			device->Interface->EventListener(device, SliderEventStatusChanged, 0, 0);
			break;
		
		case SliderStateIsOpen:
			request.Power = device->Motor.Options.Power;
			request.TimeOut = SLIDER_DEFAULT_TIMEOUT;
			request.Mode = SliderMoveModeCommon;
			request.Position = SliderPositionClose;
		
			SliderSetPosition(device, &request);
			device->Status.State = SliderStateClosing;
			device->Interface->EventListener(device, SliderEventStatusChanged, 0, 0);
			break;
			
		case SliderStateClosing:
			request.Power = 5.0;
			request.TimeOut = SLIDER_DEFAULT_TIMEOUT;
			request.Mode = SliderMoveModeMoveOffTheSensor;
			request.Position = SliderPositionOpen;
		
			SliderSetPosition(device, &request);
			device->Status.State = SliderStateMoveOffTheSensor;
			device->Interface->EventListener(device, SliderEventStatusChanged, 0, 0);
			break;
				
		case SliderStateMoveOffTheSensor:
			device->Status.State = SliderStateRealised;
			device->Status.Result = SliderResultNoError;
			device->Interface->EventListener(device, SliderEventStatusChanged, 0, 0);
			break;
	}
}
//==============================================================================
xResult SliderSetOptions(SliderT* device, SliderMotorOptionsT* request)
{
	if (device->Motor.Status.Motion == SliderMotionStateStopped
		&& (device->Status.State == SliderStateIdle || device->Status.State == SliderStateRealised))
	{
		memcpy(&device->Motor.Options, request, sizeof(device->Motor.Options));
		return xResultAccept;
	}
	return xResultBusy;
}
//------------------------------------------------------------------------------
void SliderStop(SliderT* device)
{
	SliderMotorDisable(device);
	device->Motor.Status.MotionResult = SliderMotionNoError;
	
	if (device->Status.State != SliderStateIdle && device->Status.State != SliderStateRealised)
	{
		device->Status.State = SliderStateIdle;
		device->Status.Result = SliderResultBreak;
		return;
	}
	
	device->Status.Result = SliderResultNoError;
}
//------------------------------------------------------------------------------
xResult SliderSetPosition(SliderT* device, SliderMoveRequestT* request)
{
	device->Sensors.Interface.Handler(device);
	
	if (device->Sensors.State.Overcurrent)
	{
		device->Motor.Status.MotionResult = SliderMotionOvercurrent;
		return xResultError;
	}
	
	if ((device->Sensors.State.Close && request->Position == SliderPositionClose)
		|| (device->Sensors.State.Open && request->Position == SliderPositionOpen))
	{
		return xResultAccept;
	}
	
	SliderMotorDisable(device);
	
	return device->Motor.Interface->RequestListener(device, SliderMotorRequestMoveStart, (uint32_t)request, 0);
}
//------------------------------------------------------------------------------
xResult SliderClose(SliderT* device)
{
	SliderMoveRequestT request =
	{
		.Power = SLIDER_DEFAULT_MOVE_POWER,
		.Mode = SliderMoveModeCommon,
		.TimeOut = SLIDER_DEFAULT_TIMEOUT,
		.Position = SliderPositionClose
	};

	device->Status.State = SliderStateClosing;
	
	return SliderSetPosition(device, &request);
}
//------------------------------------------------------------------------------
xResult SliderOpen(SliderT* device)
{
	SliderMoveRequestT request =
	{
		.Power = SLIDER_DEFAULT_MOVE_POWER,
		.Mode = SliderMoveModeCommon,
		.TimeOut = SLIDER_DEFAULT_TIMEOUT,
		.Position = SliderPositionOpen
	};
	
	return SliderSetPosition(device, &request);
}
//------------------------------------------------------------------------------
xResult SliderDropPod(SliderT* device, uint32_t open_time)
{
	if (!device || !open_time)
	{
		return xResultInvalidParameter;
	}
	
	if (device->Sensors.State.Overcurrent)
	{
		return xResultError;
	}
	
	device->Status.Result = SliderMotionNoError;
	device->OpenTime = open_time;
	device->Status.State = SliderStateOpening;
	
	SliderMoveRequestT request;
	request.Power = device->Motor.Options.Power;
	request.TimeOut = SLIDER_DEFAULT_TIMEOUT;
	request.Mode = SliderMoveModeCommon;
	request.Position = SliderPositionOpen;
	
	xResult result = SliderSetPosition(device, &request);
	
	device->Interface->EventListener(device, SliderEventStatusChanged, 0, 0);
	
	return result;
}
//==============================================================================
xResult SliderInit(SliderT* Slider, void* parent, SliderInterfaceT* interface)
{
	extern const xRxRequestT SliderRequests[];
	
	if (Slider && interface)
	{
		Slider->Description = "SliderT";
		Slider->Parent = parent;
		Slider->Interface = interface;
		
		Slider->Motor.Options.StartPower = SLIDER_DEFAULT_MOVE_STAR_POWER;
		Slider->Motor.Options.Acceleration = SLIDER_DEFAULT_MOVE_ACCELERATION;
		Slider->Motor.Options.Power = SLIDER_DEFAULT_MOVE_POWER;
		
		Slider->Requests = (xRxRequestT*)SliderRequests;
		
		return xResultAccept;
	}
	return xResultLinkError;
}
//==============================================================================
