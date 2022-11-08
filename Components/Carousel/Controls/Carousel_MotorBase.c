//==============================================================================
#include "Carousel_MotorBase.h"
#include "Carousel.h"
//==============================================================================
static void Handler(void* device)
{
	
}
//------------------------------------------------------------------------------
static void EventListener(void* device, CarouselMotorEventSelector selector, uint32_t args, uint32_t count)
{
	switch ((int)selector)
	{
		default : break;
	}
}
//------------------------------------------------------------------------------
static xResult RequestListener(void* device, CarouselMotorRequestSelector selector, uint32_t args, uint32_t count)
{
	switch ((int)selector)
	{
		default : return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
static uint32_t GetValue(void* device, CarouselMotorValueSelector selector)
{
	switch ((int)selector)
	{
		default : break;
	}
	
	return 0;
}
//------------------------------------------------------------------------------
static xResult SetValue(void* device, CarouselMotorValueSelector selector, uint32_t value)
{
	switch ((int)selector)
	{
		default : return xResultValueIsNotFound;
	}
	
	return xResultAccept;
}
//==============================================================================
void CarouselMotorDisable(CarouselT* device)
{
	device->Motor.Interface->RequestListener(device, CarouselMotorRequestMoveStope, 0, 0);
	device->Status.Motion = CarouselMotionStateStopped;
}
//------------------------------------------------------------------------------
xResult CarouselMotorBaseSetPosition(CarouselT* device, CarouselMotorRequestT* request)
{
	device->Motor.TimeSynchronizationEnable = false;

	device->Motor.MoveTime = 0;
	device->Motor.TimeOut = request->TimeOut;
	device->Motor.TotalPower = device->Motor.Options.StartPower;
	device->Motor.RequestPower = request->Power;
	device->Motor.RequestEncoderPosition = request->Position;
	device->Motor.Mode = request->Mode;
	device->Motor.AccelerationIncrement = device->Motor.Options.Acceleration / 1000;
	device->Status.MotionResult = CarouselMotionNoError;
	device->Status.Motion = CarouselMotionStateStopped;
	
	device->Motor.EncoderPosition = device->Motor.Interface->GetValue(device, CarouselMotorValueEncoderPosition);
	
	if (device->Motor.EncoderPosition < request->Position)
	{
		device->Status.Motion = CarouselMotionStateMovingForward;
	}
	else if (device->Motor.EncoderPosition > request->Position)
	{
		device->Status.Motion = CarouselMotionStateMovingBackward;
	}
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
void CarouselMotorHandler(CarouselT* device)
{
	device->Motor.EncoderPosition = device->Motor.Interface->GetValue(device, CarouselMotorValueEncoderPosition);
	
	if (device->Sensors.State.Overcurrent)
	{
		if (device->Status.Motion != CarouselMotionStateStopped)
		{
			CarouselMotorDisable(device);
			
			device->Status.MotionResult = CarouselMotionOvercurrent;
			device->Interface->EventListener(device, CarouselEventOvercurrent, 0, 0);
		}
		return;
	}
	
	if (device->Status.Motion == CarouselMotionStateStopped)
	{
		return;
	}
	
	if (device->Sensors.State.ZeroMark)
	{
		if ((device->Motor.Mode == CarouselMotorModeStopAtZeroMark)
		|| ((device->Motor.Mode == CarouselMotorModeFindZeroMark) && !device->Sensors.LastState.ZeroMark))
		{
			CarouselMotorDisable(device);
			device->Interface->EventListener(device, CarouselEventZeroMark, 0, 0);
		}
	}
	else if ((device->Motor.Mode == CarouselMotorModeMoveOutAtZeroMark) && device->Sensors.LastState.ZeroMark)
	{
		CarouselMotorDisable(device);
		device->Interface->EventListener(device, CarouselEventZeroMark, 0, 0);
	}
	
	if ((device->Status.Motion == CarouselMotionStateMovingForward && device->Motor.EncoderPosition >= device->Motor.RequestEncoderPosition)
		|| (device->Status.Motion == CarouselMotionStateMovingBackward && device->Motor.EncoderPosition <= device->Motor.RequestEncoderPosition))
	{
		CarouselMotorDisable(device);
		device->Interface->EventListener(device, CarouselEventPositionIsSet, 0, 0);
		return;
	}
	
	if (device->Status.Motion != CarouselMotionStateStopped)
	{
		//device->Motor.MoveTime++;
		
		if (device->Motor.MoveTime >= device->Motor.TimeOut)
		{
			CarouselMotorDisable(device);
			
			device->Status.MotionResult = CarouselMotionTimeout;
			device->Interface->EventListener(device, CarouselEventTimeout, 0, 0);
			return;
		}
		/*
		if (device->Motor.TotalPower < device->Motor.RequestPower)
		{
			device->Motor.TotalPower += device->Motor.AccelerationIncrement;
			device->Motor.Interface->RequestListener(device, CarouselMotorRequestSetPower, 0, 0);
		}
		*/
		device->Motor.Interface->RequestListener(device, CarouselMotorRequestSetPower, 0, 0);
	}
}
//------------------------------------------------------------------------------
void CarouselMotorTimeSynchronization(CarouselT* device)
{
	if (device->Status.Motion != CarouselMotionStateStopped && device->Motor.TimeSynchronizationEnable)
	{
		device->Motor.MoveTime++;
		
		if (device->Motor.TotalPower < device->Motor.RequestPower)
		{
			device->Motor.TotalPower += device->Motor.AccelerationIncrement;
		}
	}
}
//==============================================================================
static CarouselMotorInterfaceT Interface =
{
	.Handler = (CarouselMotorHandlerT)Handler,
	.EventListener = (CarouselMotorEventListenerT)EventListener,
	.RequestListener = (CarouselMotorRequestListenerT)RequestListener,
	.GetValue = (CarouselMotorActionGetValueT)GetValue,
	.SetValue = (CarouselMotorActionSetValueT)SetValue,
};
//------------------------------------------------------------------------------
xResult CarouselMotorBaseInit(CarouselMotorBaseT* adapter)
{
	if (adapter)
	{
		adapter->Interface = &Interface;
	}
	return xResultAccept;
}
//==============================================================================
