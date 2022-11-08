//==============================================================================
#include "BrewGroup_DCMotorAdapter.h"
//==============================================================================
static void PrivateDisablePWMOutputs(BrewGroupDCMotorAdapterT* adapter)
{
	adapter->PWM_ForwardTimer->CaptureCompareOutput.Value &= ~adapter->Values.PWM_Forward.OutputEnableMask;
	adapter->PWM_BackwardTimer->CaptureCompareOutput.Value &= ~adapter->Values.PWM_Backward.OutputEnableMask;
}
//==============================================================================
static void PrivateHandler(BrewGroupMotorT* device)
{
	BrewGroupDCMotorAdapterT* adapter = device->Adapter.Child;
	
	if (adapter->PWM_ForwardTimer->CaptureCompareOutput.Value & adapter->Values.PWM_Forward.OutputEnableMask)
	{
		device->Status.Motion = BrewGroupMotionStateOpening;
	}
	else if (adapter->PWM_BackwardTimer->CaptureCompareOutput.Value & adapter->Values.PWM_Backward.OutputEnableMask)
	{
		device->Status.Motion = BrewGroupMotionStateClosing;
	}
	else
	{
		device->Status.Motion = BrewGroupMotionStateStopped;
	}
	
}
//------------------------------------------------------------------------------
static void PrivateEventListener(BrewGroupMotorT* device, BrewGroupMotorEventSelector selector, uint32_t args, uint32_t count)
{
	BrewGroupDCMotorAdapterT* adapter = device->Adapter.Child;
	
	switch ((int)selector)
	{
		default : break;
	}
}
//------------------------------------------------------------------------------
static xResult PrivateBrewGroupOpen(BrewGroupMotorT* device)
{
	BrewGroupDCMotorAdapterT* adapter = device->Adapter.Child;
	
	adapter->Values.SelectedPWM = &adapter->Values.PWM_Forward;
	
	uint16_t power = (uint16_t)(device->TotalPower / 100 * adapter->Values.SelectedPWM->Timer->Period);
	*adapter->Values.SelectedPWM->CompareValue = power;
	adapter->Values.SelectedPWM->Timer->CaptureCompareOutput.Value |= adapter->Values.SelectedPWM->OutputEnableMask;
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
static xResult PrivateBrewGroupClose(BrewGroupMotorT* device)
{
	BrewGroupDCMotorAdapterT* adapter = device->Adapter.Child;
	
	adapter->Values.SelectedPWM = &adapter->Values.PWM_Backward;
	
	uint16_t power = (uint16_t)(device->TotalPower / 100 * adapter->Values.SelectedPWM->Timer->Period);
	*adapter->Values.SelectedPWM->CompareValue = power;
	adapter->Values.SelectedPWM->Timer->CaptureCompareOutput.Value |= adapter->Values.SelectedPWM->OutputEnableMask;
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
static xResult PrivateRequestListener(BrewGroupMotorT* device, BrewGroupMotorRequestSelector selector, uint32_t args, uint32_t count)
{
	BrewGroupDCMotorAdapterT* adapter = device->Adapter.Child;
	
	switch ((int)selector)
	{
		case BrewGroupMotorRequestSetPower:
			if (adapter->Values.SelectedPWM)
			{
				*adapter->Values.SelectedPWM->CompareValue = (uint16_t)((device->TotalPower / 100 * adapter->Values.SelectedPWM->Timer->Period) - 1);
			}
			break;
		
		case BrewGroupMotorRequestOpen:
			return PrivateBrewGroupOpen(device);
		
		case BrewGroupMotorRequestClose:
			return PrivateBrewGroupClose(device);
		
		case BrewGroupMotorRequestMoveStope:
			PrivateDisablePWMOutputs(adapter);
			break;
		
		default : return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//==============================================================================
xResult BrewGroupDCMotorAdapterInit(BrewGroupMotorT* device, BrewGroupDCMotorAdapterT* adapter)
{
	if (device && adapter)
	{
		device->Adapter.Description = "BrewGroupDCMotorAdapterT";
		device->Adapter.Parent = device;
		device->Adapter.Child = adapter;
		device->Adapter.Handler = (BrewGroupMotorHandlerT)PrivateHandler;
		device->Adapter.EventListener = (BrewGroupMotorEventListenerT)PrivateEventListener;
		device->Adapter.RequestListener = (BrewGroupMotorRequestListenerT)PrivateRequestListener;
		
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
