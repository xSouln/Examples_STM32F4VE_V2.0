//==============================================================================
#include "Camera_AdapterBase.h"
//==============================================================================
static void Handler(void* device)
{
	
}
//------------------------------------------------------------------------------
static void EventListener(void* device, CameraAdapterEventSelector selector, uint32_t args, uint32_t count)
{
	switch ((int)selector)
	{
		default : break;
	}
}
//------------------------------------------------------------------------------
static xResult RequestListener(void* device, CameraAdapterRequestSelector selector, uint32_t args, uint32_t count)
{
	switch ((int)selector)
	{
		default : return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
static uint32_t GetValue(void* device, CameraAdapterValueSelector selector)
{
	switch ((int)selector)
	{
		default : break;
	}
	
	return 0;
}
//------------------------------------------------------------------------------
static xResult SetValue(void* device, CameraAdapterValueSelector selector, uint32_t value)
{
	switch ((int)selector)
	{
		default : return xResultValueIsNotFound;
	}
	
	return xResultAccept;
}
//==============================================================================
static CameraAdapterInterfaceT Interface =
{
	.Handler = (CameraAdapterHandlerT)Handler,
	.EventListener = (CameraAdapterEventListenerT)EventListener,
	.RequestListener = (CameraAdapterRequestListenerT)RequestListener,
	.GetValue = (CameraAdapterActionGetValueT)GetValue,
	.SetValue = (CameraAdapterActionSetValueT)SetValue,
};
//------------------------------------------------------------------------------
xResult CameraAdapterBaseInit(CameraAdapterBaseT* adapter)
{
	if (adapter)
	{
		adapter->Interface = &Interface;
	}
	return xResultAccept;
}
//==============================================================================