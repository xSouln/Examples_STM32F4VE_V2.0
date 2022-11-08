//==============================================================================
#include "Slider_DCMotorAdapter.h"
#include "Slider/Controls/Slider.h"
//==============================================================================
static void DisablePWMOutputs(SliderDCMotorAdapterT* adapter)
{
	adapter->PWM_ForwardTimer->CaptureCompareOutput.Value &= ~adapter->Values.PWM_Forward.OutputEnableMask;
	adapter->PWM_BackwardTimer->CaptureCompareOutput.Value &= ~adapter->Values.PWM_Backward.OutputEnableMask;
}
//==============================================================================
static void Handler(SliderT* device)
{
	SliderDCMotorAdapterT* adapter = device->Motor.Child;
	
	if (adapter->PWM_ForwardTimer->CaptureCompareOutput.Value & adapter->Values.PWM_Forward.OutputEnableMask)
	{
		device->Motor.Status.Motion = SliderMotionStateOpening;
	}
	else if (adapter->PWM_BackwardTimer->CaptureCompareOutput.Value & adapter->Values.PWM_Backward.OutputEnableMask)
	{
		device->Motor.Status.Motion = SliderMotionStateClosing;
	}
	else
	{
		device->Motor.Status.Motion = SliderMotionStateStopped;
	}
	
}
//------------------------------------------------------------------------------
static void EventListener(SliderT* device, SliderMotorEventSelector selector, uint32_t args, uint32_t count)
{
	SliderDCMotorAdapterT* adapter = device->Motor.Child;
	
	switch ((int)selector)
	{
		default : break;
	}
}
//------------------------------------------------------------------------------
static xResult SliderMotorSetPosition(SliderT* device, SliderMoveRequestT* request)
{
	extern void SliderMotorBaseSetPosition(SliderT* device, SliderMoveRequestT* request);
	
	SliderDCMotorAdapterT* adapter = device->Motor.Child;
	
	SliderMotorBaseSetPosition(device, request);
	
	switch ((uint8_t)request->Position)
	{
		case SliderPositionOpen:
			adapter->Values.SelectedPWM = &adapter->Values.PWM_Forward;
			break;
		
		case SliderPositionClose:
			adapter->Values.SelectedPWM = &adapter->Values.PWM_Backward;
			break;
		
		default : break;
	}
	
	uint16_t power = (uint16_t)(device->Motor.TotalPower / 100 * adapter->Values.SelectedPWM->Timer->Period);
	*adapter->Values.SelectedPWM->CompareValue = power;
	adapter->Values.SelectedPWM->Timer->CaptureCompareOutput.Value |= adapter->Values.SelectedPWM->OutputEnableMask;
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
static xResult RequestListener(SliderT* device, SliderMotorRequestSelector selector, uint32_t args, uint32_t count)
{
	SliderDCMotorAdapterT* adapter = device->Motor.Child;
	
	switch ((int)selector)
	{
		case SliderMotorRequestSetPower:
			if (adapter->Values.SelectedPWM)
			{
				*adapter->Values.SelectedPWM->CompareValue = (uint16_t)((device->Motor.TotalPower / 100 * adapter->Values.SelectedPWM->Timer->Period) - 1);
			}
			break;
		
		case SliderMotorRequestMoveStart:
			return SliderMotorSetPosition(device, (SliderMoveRequestT*)args);
		
		case SliderMotorRequestMoveStope:
			DisablePWMOutputs(adapter);
			break;
		
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
};
//==============================================================================
xResult SliderDCMotorAdapterInit(SliderT* Slider, SliderDCMotorAdapterT* adapter)
{
	if (Slider && adapter)
	{
		Slider->Motor.Description = "SliderDCMotorAdapterT";
		Slider->Motor.Parent = Slider;
		Slider->Motor.Child = adapter;
		Slider->Motor.Interface = &Interface;
		
		adapter->Values.PWM_Backward.Timer = adapter->PWM_BackwardTimer;
		adapter->Values.PWM_Backward.OutputEnableMask = (1 << (adapter->PWM_BackwardChannel * 4));
		adapter->Values.PWM_Backward.CompareValue = &adapter->PWM_BackwardTimer->CaptureCompare1Value + adapter->PWM_BackwardChannel;
		
		adapter->Values.PWM_Forward.Timer = adapter->PWM_ForwardTimer;
		adapter->Values.PWM_Forward.OutputEnableMask = (1 << (adapter->PWM_ForwardChannel * 4));
		adapter->Values.PWM_Forward.CompareValue = &adapter->PWM_ForwardTimer->CaptureCompare1Value + adapter->PWM_ForwardChannel;
		
		adapter->PWM_BackwardTimer->BreakAndDeadTime.MainOutputEnable = true;
		adapter->PWM_ForwardTimer->BreakAndDeadTime.MainOutputEnable = true;
		
		adapter->PWM_BackwardTimer->Control1.CounterEnable = true;
		adapter->PWM_ForwardTimer->Control1.CounterEnable = true;
		
		return xResultAccept;
	}
	return xResultInvalidParameter;
}
//==============================================================================
