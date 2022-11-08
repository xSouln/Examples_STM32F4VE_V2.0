//==============================================================================
#include "Slider_SensorsBase.h"
#include "Slider.h"
//==============================================================================
static void Handler(void* device)
{
}
//------------------------------------------------------------------------------
static xResult RequestListener(void* device, SliderSensorsRequestSelector selector, uint32_t args, uint32_t count)
{
	switch ((int)selector)
	{
		default : return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//==============================================================================
void SliderSensorsHandler(SliderT* device)
{
	device->Sensors.Interface.Handler(device);
}
//==============================================================================
xResult SliderSensorsBaseInit(SliderSensorsBaseT* adapter, void* parent)
{
	if (adapter)
	{
		adapter->Description = "SliderSensorsBaseT";
		adapter->Parent = parent;
		adapter->Child = 0;
		
		adapter->Interface.Handler = Handler;
		adapter->Interface.RequestListener = RequestListener;
		
		return xResultAccept;
	}
	
	return xResultLinkError;
}
//==============================================================================