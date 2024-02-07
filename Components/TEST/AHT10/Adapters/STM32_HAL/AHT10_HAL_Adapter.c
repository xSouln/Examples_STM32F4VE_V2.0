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

	switch ((uint32_t)selector)
	{

		default : return xResultNotSupported;
	}

	return xResultAccept;
}
//------------------------------------------------------------------------------

HAL_StatusTypeDef result;
//------------------------------------------------------------------------------
static void privateHandler(AHT10_T* driver)
{
	uint16_t AHT10_RX_Data[6];
	uint32_t AHT10_ADC_Raw_1;
	uint32_t AHT10_ADC_Raw_2;
	uint8_t AHT10_TmpHum_Cmd = 0xAC;


	AHT10_HAL_AdapterT* adapter = driver->Adapter.Content;
	uint32_t time = xSystemGetTime();

	if (time - adapter->Content.TimeStamp > 1000)
	{
		adapter->Content.TimeStamp  = time;
		HAL_I2C_Master_Transmit(&hi2c2, AHT10_ADDRESS, &AHT10_TmpHum_Cmd, 1, 150);
		HAL_Delay(100); // Delay must be > 75 ms
		result =  HAL_I2C_Master_Transmit(&hi2c2, AHT10_ADDRESS, &AHT10_TmpHum_Cmd, 1, 150);

		HAL_I2C_Master_Receive(&hi2c2, AHT10_ADDRESS, (uint8_t*)AHT10_RX_Data, 6, 150);
		result = HAL_I2C_Master_Receive(&hi2c2, AHT10_ADDRESS, (uint8_t*)AHT10_RX_Data, 6, 150);

		/* Convert to Humidity in °C */
	    AHT10_ADC_Raw_1 = ((uint32_t)AHT10_RX_Data[1]  << 12) | ((uint16_t)AHT10_RX_Data[2] << 8) | AHT10_RX_Data[3] >> 4;
	    adapter->Content.AHT10_Humidity = (float)((AHT10_ADC_Raw_1  / 1048576) * 100) ;

		/* Convert to Temperature in °C */
		AHT10_ADC_Raw_2 = (((uint32_t)AHT10_RX_Data[3] & 15) << 16 )| ((uint16_t)AHT10_RX_Data[4] << 8) | AHT10_RX_Data[5];
		adapter->Content.AHT10_Temperature = (float)(AHT10_ADC_Raw_2 * 200 / 1048576) - 50;
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
