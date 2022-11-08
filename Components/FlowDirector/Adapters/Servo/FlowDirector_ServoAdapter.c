//==============================================================================
#include "FlowDirector_ServoAdapter.h"
//==============================================================================
static void FlowDirectorServoHandler(FlowDirectorMotorT* device)
{
	
}
//------------------------------------------------------------------------------
static void FlowDirectorServoEventListener(FlowDirectorMotorT* device, FlowDirectorMotorEventSelector selector, uint32_t args, uint32_t count)
{
	switch ((int)selector)
	{
		case FlowDirectorMotorEventTimeSynchronization:
			break;
		
		default : break;
	}
}
//------------------------------------------------------------------------------
static void FlowDirectorServoSetAngle(FlowDirectorMotorT* device, float angle)
{
	FlowDirectorServoAdapterT* adapter = device->Adapter.Child;
	uint32_t width = adapter->Data.Max - adapter->Data.Min;
	
	*adapter->Data.PWM_Period = adapter->Data.Min + (uint32_t)(angle / 180.0 * width);
}
//------------------------------------------------------------------------------
static xResult FlowDirectorServoRequestListener(FlowDirectorMotorT* device, FlowDirectorMotorRequestSelector selector, uint32_t args, uint32_t count)
{
	FlowDirectorServoAdapterT* adapter = device->Adapter.Child;
	
	switch ((int)selector)
	{
		case FlowDirectorMotorRequestSetAngle:
			FlowDirectorServoSetAngle(device, device->TotalAngle);
			break;
		
		case FlowDirectorMotorRequestEnable:
			adapter->PWM_Timer->CaptureCompareOutput.Value |= adapter->Data.PWM_OutputEnableMask;
			break;
		
		case FlowDirectorMotorRequestDisable:
			adapter->PWM_Timer->CaptureCompareOutput.Value &= ~adapter->Data.PWM_OutputEnableMask;
			break;
		
		default : return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//==============================================================================
xResult FlowDirectorServoAdapterInit(FlowDirectorMotorT* device, FlowDirectorServoAdapterT* adapter)
{
	if (device && adapter)
	{
		device->Adapter.Description = "FlowDirectorServoAdapterT";
		device->Adapter.Parent = device;
		device->Adapter.Child = adapter;
		
		device->Adapter.Handler = (FlowDirectorMotorHandlerT)FlowDirectorServoHandler;
		device->Adapter.EventListener = (FlowDirectorMotorEventListenerT)FlowDirectorServoEventListener;
		device->Adapter.RequestListener = (FlowDirectorMotorRequestListenerT)FlowDirectorServoRequestListener;
		
		adapter->Data.PWM_OutputEnableMask = (1 << (adapter->PWM_Channel * 4));
		adapter->Data.PWM_Period = &adapter->PWM_Timer->CaptureCompare1Value + adapter->PWM_Channel;
		
		adapter->PWM_Timer->BreakAndDeadTime.MainOutputEnable = true;
		adapter->PWM_Timer->Control1.CounterEnable = true;
		
		adapter->Data.Min = adapter->PWM_Timer->Period / 20;
		adapter->Data.Max = adapter->Data.Min * 2;
		
		*adapter->Data.PWM_Period = adapter->Data.Min;
		
		adapter->PWM_Timer->CaptureCompareOutput.Value |= adapter->Data.PWM_OutputEnableMask;
		
		return xResultAccept;
	}
	return xResultInvalidParameter;
}
//==============================================================================
