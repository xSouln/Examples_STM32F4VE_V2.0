//==============================================================================
#include "Carousel_SensorsBase.h"
#include "Carousel.h"
//==============================================================================
static void Handler(void* device)
{
	
}
//------------------------------------------------------------------------------
static xResult RequestListener(void* device, CarouselSensorsRequestSelector selector, uint32_t args, uint32_t count)
{
	switch ((int)selector)
	{
		default : return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//==============================================================================
void CarouselSensorsHandler(CarouselT* device)
{
	device->Sensors.Interface.Handler(device);
}
//==============================================================================
xResult CarouselSensorsBaseInit(CarouselSensorsBaseT* adapter, void* parent)
{
	if (adapter)
	{
		adapter->Description = "CarouselWaterPumpBaseT";
		adapter->Parent = parent;
		adapter->Child = 0;
		
		adapter->Interface.Handler = Handler;
		adapter->Interface.RequestListener = RequestListener;
		
		return xResultAccept;
	}
	
	return xResultLinkError;
}
//==============================================================================