//==============================================================================
//header:

#ifdef _AHT10_HAL_ADAPTER_H_
//==============================================================================
//includes:

#include "AHT10_HAL_Adapter.h"
#include "Abstractions/xSystem/xSystem.h"

//==============================================================================
//defines:


//==============================================================================
//types:


//==============================================================================
//variables:


//==============================================================================
//functions:


//------------------------------------------------------------------------------
static xResult privateRequestListener(AHT10_T* driver,
		int selector,
		uint32_t description,
		void* in,
		void* out)
{
	 AHT10_HAL_AdapterT* adapter = driver->Adapter.Content;



	switch ((uint32_t)selector)
	{

		default : return xResultNotSupported;
	}

	return xResultAccept;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
static void privateHandler(AHT10_T* driver)
{
	AHT10_HAL_AdapterT* adapter = driver->Adapter.Content;
	uint32_t time = xSystemGetTime();
	if (time - adapter->Content.TimeStamp > 300)
	{
		adapter->Content.TimeStamp = time;
		adapter->LED_Port->ODR ^= (1 << adapter->LED_Pin);
	}
	//DigitalOutputsServiceAdapterT* adapter = service->Base.Adapter.Content;
}
//==============================================================================
//initializations:

static AHT10_AdapterInterfaceT privateInterface =
{
	.Handler = (AHT10_AdapterHandlerT)privateHandler,
	.RequestListener = (AHT10_AdapterRequestListenerT)privateRequestListener,

};
//------------------------------------------------------------------------------

//==============================================================================

xResult AHT10_HAL_AdapterInit(AHT10_T* driver, AHT10_HAL_AdapterT* adapter, AHT10_HAL_AdapterInitT* init)
{
	driver->Adapter.Content = adapter;
	driver->Adapter.Interface = &privateInterface;
	driver->Adapter.Description = "1";

	if(init != NULL)
	{

		adapter->LED_Pin  = init->LED_Pin;
		adapter->LED_Port = init->LED_Port;
		adapter->Handle = init->Handle;

	}
	return 0;
}
//==============================================================================
#endif //_AHT10_HAL_ADAPTER_H_
