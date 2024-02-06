//==============================================================================
//includes:

#include "AHT10_HAL_Adapter.h"
#include "Abstractions/xSystem/xSystem.h"

//==============================================================================
//defines:
#define AHT10_ADDRESS  (0x38 << 1)


//==============================================================================
//types:


//==============================================================================
//variables:
uint16_t AHT10_RX_Data[6];
uint64_t AHT10_ADC_Raw;
float AHT10_Humidity;
float AHT10_Temperature;
uint8_t AHT10_TmpHum_Cmd[3] = {0xAC, 0x33, 0x00};



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
	if (time - adapter->Content.TimeStamp > 1000)
	{
		adapter->Content.TimeStamp = time;
		//adapter->LED_Port->ODR ^= (1 << adapter->LED_Pin);

		  HAL_I2C_Master_Transmit(&hi2c2, AHT10_ADDRESS, AHT10_TmpHum_Cmd, 3, 150);
		  HAL_Delay(100); // Delay must be > 75 ms
		  HAL_I2C_Master_Receive(&hi2c2, AHT10_ADDRESS, (uint8_t*)AHT10_RX_Data, 6, 150);
		  /* Convert to Humidity in °C */
	       AHT10_ADC_Raw = ((uint32_t)AHT10_RX_Data[1]  << 16) | ((uint16_t)AHT10_RX_Data[4] << 8) | AHT10_RX_Data[5];
		   AHT10_Humidity = (float)((AHT10_ADC_Raw  / 1048576) * 100) ;
		  /* Convert to Temperature in °C */
		  AHT10_ADC_Raw = (((uint32_t)AHT10_RX_Data[3] & 15) << 16 )| ((uint16_t)AHT10_RX_Data[2] << 8) | AHT10_RX_Data[3] >> 4;
		  AHT10_Temperature = (float)(AHT10_ADC_Raw * 200 / 1048576) - 50;
		  HAL_Delay(80);
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
