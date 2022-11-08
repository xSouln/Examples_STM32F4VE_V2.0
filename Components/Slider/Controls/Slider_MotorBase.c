//==============================================================================
#include "Slider_MotorBase.h"
#include "Slider.h"
//==============================================================================
static void Handler(void* device)
{
	
}
//------------------------------------------------------------------------------
static void EventListener(void* device, SliderMotorEventSelector selector, uint32_t args, uint32_t count)
{
	switch ((int)selector)
	{
		default : break;
	}
}
//------------------------------------------------------------------------------
static xResult RequestListener(void* device, SliderMotorRequestSelector selector, uint32_t args, uint32_t count)
{
	switch ((int)selector)
	{
		default : return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//==============================================================================
static SliderMotorInterfaceT Interface =
{
	.Handler = (SliderMotorHandlerT)Handler,
	.EventListener = (SliderMotorEventListenerT)EventListener,
	.RequestListener = (SliderMotorRequestListenerT)RequestListener,
	//.GetValue = (SliderMotorActionGetValueT)GetValue,
	//.SetValue = (SliderMotorActionSetValueT)SetValue,
};
//==============================================================================
void SliderMotorDisable(SliderT* device)
{
	device->Motor.Interface->RequestListener(device, SliderMotorRequestMoveStope, 0, 0);
	device->Motor.Status.Motion = SliderMotionStateStopped;
}
//------------------------------------------------------------------------------
void SliderMotorBaseSetPosition(SliderT* device, SliderMoveRequestT* request)
{
	switch ((uint8_t)request->Position)
	{
		case SliderPositionOpen:
			device->Motor.Triggers.Open = false;
			device->Motor.Status.Motion = SliderMotionStateOpening;
			break;
		
		case SliderPositionClose:
			device->Motor.Triggers.Close = false;
			device->Motor.Status.Motion = SliderMotionStateClosing;
			break;
		
		default : break;
	}
	
	device->Motor.TotalPower = device->Motor.Options.StartPower;
	device->Motor.RequestPower = request->Power;
	device->Motor.Status.MotionResult = SliderMotionNoError;
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
}
//==============================================================================
void SliderMotorHandler(SliderT* device)
{
	device->Motor.Interface->Handler(device);
	
	if (device->Sensors.State.Overcurrent)
	{
		SliderMotorDisable(device);
		
		if (device->Motor.Status.MotionResult != SliderMotionOvercurrent)
		{
			device->Motor.Status.MotionResult = SliderMotionOvercurrent;
			device->Interface->EventListener(device, SliderEventOvercurrent, 0, 0);
		}
	}
	
	if (device->Motor.Status.Motion == SliderMotionStateOpening)
	{
		if (!device->Sensors.State.Close && device->Motor.Mode == SliderMoveModeMoveOffTheSensor)
		{
			SliderMotorDisable(device);
		}
		else if (device->Sensors.State.Open)
		{
			SliderMotorDisable(device);
		
			if (!device->Motor.Triggers.Open)
			{
				device->Motor.Triggers.Open = true;
				device->Interface->EventListener(device, SliderEventOpen, 0, 0);
			}
		}
	}
	else if (device->Motor.Status.Motion == SliderMotionStateClosing)
	{
		if (device->Sensors.State.Close || (!device->Sensors.State.Open && device->Motor.Mode == SliderMoveModeMoveOffTheSensor))
		{
			SliderMotorDisable(device);
		
			if (!device->Motor.Triggers.Close)
			{
				device->Motor.Triggers.Close = true;
				device->Interface->EventListener(device, SliderEventClose, 0, 0);
			}
		}
	}
	
	if (device->Motor.Status.Motion != SliderMotionStateStopped)
	{
		device->Motor.MoveTime++;
		
		if (device->Motor.MoveTime >= device->Motor.TimeOut)
		{
			SliderMotorDisable(device);
			
			device->Motor.Status.MotionResult = SliderMotionTimeout;
			device->Interface->EventListener(device, SliderEventTimeout, 0, 0);
			return;
		}
		
		if (device->Motor.TotalPower < device->Motor.RequestPower)
		{
			device->Motor.TotalPower += device->Motor.AccelerationIncrement;
			device->Motor.Interface->RequestListener(device, SliderMotorRequestSetPower, 0, 0);
		}
	}
}
//------------------------------------------------------------------------------
xResult SliderMotorBaseInit(SliderMotorBaseT* adapter)
{
	if (adapter)
	{
		adapter->Interface = &Interface;
	}
	return xResultAccept;
}
//==============================================================================
