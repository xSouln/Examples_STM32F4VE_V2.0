//==============================================================================
#include "Carousel_DCMotorAdapter.h"
//==============================================================================
static void DisablePWMOutputs(CarouselDCMotorAdapterT* adapter)
{
	adapter->PWM_ForwardTimer->CaptureCompareOutput.Value &= ~adapter->Values.PWM_Forward.OutputEnableMask;
	adapter->PWM_BackwardTimer->CaptureCompareOutput.Value &= ~adapter->Values.PWM_Backward.OutputEnableMask;
}
//------------------------------------------------------------------------------
static void Handler(CarouselT* device)
{
	CarouselDCMotorAdapterT* adapter = device->Motor.Child;
	int position_total = adapter->EncoderTimer->Counter;
	
	device->Motor.EncoderPosition = position_total;
	
	if (adapter->PWM_ForwardTimer->CaptureCompareOutput.Value & adapter->Values.PWM_Forward.OutputEnableMask)
	{
		device->Status.Motion = CarouselMotionStateMovingForward;
		device->Motor.TotalPower = (float)*adapter->Values.PWM_Forward.CompareValue / adapter->PWM_ForwardTimer->Period * 100.0;
	}
	else if (adapter->PWM_BackwardTimer->CaptureCompareOutput.Value & adapter->Values.PWM_Backward.OutputEnableMask)
	{
		device->Status.Motion = CarouselMotionStateMovingBackward;
		device->Motor.TotalPower = (float)*adapter->Values.PWM_Backward.CompareValue / adapter->PWM_BackwardTimer->Period * 100.0;
	}
	else
	{
		device->Status.Motion = CarouselMotionStateStopped;
	}
}
//------------------------------------------------------------------------------
static void EventListener(CarouselT* device, CarouselMotorEventSelector selector, uint32_t args, uint32_t count)
{
	switch ((int)selector)
	{
		default : break;
	}
}
//------------------------------------------------------------------------------
static xResult CarouselMotorSetPosition(CarouselT* device, CarouselMotorRequestT* request)
{
	CarouselDCMotorAdapterT* adapter = device->Motor.Child;
	
	extern  xResult CarouselMotorBaseSetPosition(CarouselT* device, CarouselMotorRequestT* request);
	
	CarouselMotorBaseSetPosition(device, request);
	
	switch (device->Status.Motion)
	{
		case CarouselMotionStateMovingForward:
			adapter->Values.SelectedPWM = &adapter->Values.PWM_Forward;
			break;
		
		case CarouselMotionStateMovingBackward:
			adapter->Values.SelectedPWM = &adapter->Values.PWM_Backward;
			break;
		
		default : return xResultInvalidParameter;
	}
	
	uint16_t power = (uint16_t)(device->Motor.TotalPower / 100 * adapter->Values.SelectedPWM->Timer->Period);
	*adapter->Values.SelectedPWM->CompareValue = power;
	adapter->Values.SelectedPWM->Timer->CaptureCompareOutput.Value |= adapter->Values.SelectedPWM->OutputEnableMask;
	
	device->Motor.TimeSynchronizationEnable = true;

	return xResultAccept;
}
//------------------------------------------------------------------------------
static xResult RequestListener(CarouselT* device, CarouselMotorRequestSelector selector, uint32_t args, uint32_t count)
{
	CarouselDCMotorAdapterT* adapter = device->Motor.Child;
	
	switch ((int)selector)
	{
		case CarouselMotorRequestSetPower:
			if (adapter->Values.SelectedPWM)
			{
				*adapter->Values.SelectedPWM->CompareValue = (uint16_t)(device->Motor.TotalPower / 100 * adapter->Values.SelectedPWM->Timer->Period);
			}
			break;
		
		case CarouselMotorRequestMoveStart:
			return CarouselMotorSetPosition(device, (CarouselMotorRequestT*)args);
		
		case CarouselMotorRequestMoveStope:
			DisablePWMOutputs(adapter);
			break;
		
		default : return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
static CarouselMotorMoveDiraction GetMoveDiraction(CarouselDCMotorAdapterT* adapter)
{
	if (adapter->PWM_ForwardTimer->CaptureCompareOutput.Value & adapter->Values.PWM_Forward.OutputEnableMask)
	{
		return CarouselMotorMoveForward;
	}
	else if (adapter->PWM_BackwardTimer->CaptureCompareOutput.Value & adapter->Values.PWM_Backward.OutputEnableMask)
	{
		return CarouselMotorMoveBackward;
	}
	else
	{
		return CarouselMotorMoveStopped;
	}
}
//------------------------------------------------------------------------------
static uint32_t GetValue(CarouselT* device, CarouselMotorValueSelector selector)
{
	CarouselDCMotorAdapterT* adapter = device->Motor.Child;
	
	switch ((int)selector)
	{
		case CarouselMotorValueEncoderPosition:
			return adapter->EncoderTimer->Counter;
		
		case CarouselMotorValueMoveDiraction:
			return GetMoveDiraction(adapter);
		
		default : break;
	}
	
	return 0;
}
//------------------------------------------------------------------------------
static xResult SetValue(CarouselT* device, CarouselMotorValueSelector selector, uint32_t value)
{
	CarouselDCMotorAdapterT* adapter = device->Motor.Child;
	
	switch ((int)selector)
	{
		case CarouselMotorValueEncoderPosition:
			adapter->EncoderTimer->Counter = value;
			break;
		
		default : return xResultValueIsNotFound;
	}
	
	return xResultAccept;
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
//==============================================================================
xResult CarouselDCMotorAdapterInit(CarouselT* carousel, CarouselDCMotorAdapterT* adapter)
{
	extern xResult CarouselDCMotorAdapterInterfaceInit(CarouselMotorBaseT* adapter);
	
	if (carousel && adapter)
	{
		carousel->Motor.Description = "CarouselDCMotorAdapterT";
		carousel->Motor.Parent = carousel;
		carousel->Motor.Child = adapter;
		carousel->Motor.Interface = &Interface;
		
		adapter->Values.PWM_Backward.Timer = adapter->PWM_BackwardTimer;
		adapter->Values.PWM_Backward.OutputEnableMask = (1 << (adapter->PWM_BackwardChannel * 4));
		adapter->Values.PWM_Backward.CompareValue = &adapter->PWM_BackwardTimer->CaptureCompare1Value + adapter->PWM_BackwardChannel;
		
		adapter->Values.PWM_Forward.Timer = adapter->PWM_ForwardTimer;
		adapter->Values.PWM_Forward.OutputEnableMask = (1 << (adapter->PWM_ForwardChannel * 4));
		adapter->Values.PWM_Forward.CompareValue = &adapter->PWM_ForwardTimer->CaptureCompare1Value + adapter->PWM_ForwardChannel;
		
		adapter->PWM_BackwardTimer->BreakAndDeadTime.MainOutputEnable = true;
		adapter->PWM_ForwardTimer->BreakAndDeadTime.MainOutputEnable = true;
		
		adapter->EncoderTimer->Control1.CounterEnable = true;
		adapter->PWM_BackwardTimer->Control1.CounterEnable = true;
		adapter->PWM_ForwardTimer->Control1.CounterEnable = true;
		
		return xResultAccept;
	}
	return xResultInvalidParameter;
}
//==============================================================================
