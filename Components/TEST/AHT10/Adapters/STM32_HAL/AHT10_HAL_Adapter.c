//==============================================================================
//includes:

#include "AHT10_HAL_Adapter.h"
#include "Abstractions/xSystem/xSystem.h"

//==============================================================================
//defines:



//==============================================================================
//types:

static enum
{
	AHT10_HandleStateIdle,
	AHT10_HandleStateRequestStartMeasurment,
	AHT10_HandleStateRequestReadResponse,
	AHT10_HandleStateRequestStartConvertation,
	AHT10_HandleStateRequestWaitTransmit,
	AHT10_HandleStateRequestWaitReceive

};

static enum
{
	StatusTransmitErorr,
	StatusTransmitDone,
	StatusReceiveErorr,
	StatusReceiveDone

};
//==============================================================================
//variables:
uint32_t AHT10_ADC_Raw;
uint8_t AHT10_RX_Data[6] = { 0 };
uint8_t StatusTransmit;
uint8_t StatusReceive;
AHT10_HAL_AdapterContentT adapterContent;
float AHT10_Temperature;
float AHT10_Humidity;


//==============================================================================
//functions:

void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c)
{
	if(hi2c == &hi2c2)
	{
		uint8_t result = HAL_I2C_Master_Receive_IT(&hi2c2, AHT10_ADDRESS | 0x01, (uint8_t*) AHT10_RX_Data, 6);

		if(result != HAL_OK)
		{
			StatusTransmit = StatusTransmitErorr;
		}
		StatusTransmit = StatusTransmitDone;

	}

}

void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c)
{
	if(hi2c == &hi2c2)
	{

		/* Convert to Humidity in °C */
		AHT10_ADC_Raw = (((uint32_t)AHT10_RX_Data[1]  << 16\
						| ((uint16_t)AHT10_RX_Data[2] << 8)\
						| (AHT10_RX_Data[3]))) >> 4;
		adapterContent.AHT10_Humidity = ((float)AHT10_ADC_Raw / 1048576) * 100;

		/* Convert to Temperature in °C */
		AHT10_ADC_Raw = (((uint32_t)AHT10_RX_Data[3] & 0x0f) << 16 )
						| ((uint16_t)AHT10_RX_Data[4] << 8)
						| AHT10_RX_Data[5];
		adapterContent.AHT10_Temperature = (float)AHT10_ADC_Raw * 200 / 1048576 - 50;
		StatusReceive = StatusReceiveDone;
	}


}
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
		case AHT10_AdapterRequestTimeTimeSynchronization:
		{
			if (adapter->Content.OpereationTimeout)
			{
				adapter->Content.OpereationTimeout--;
			}

			break;
		}

		default : return xResultNotSupported;
	}

	return xResultAccept;
}
//------------------------------------------------------------------------------

static void privateHandler(AHT10_T* driver)
{
	AHT10_HAL_AdapterT* adapter = driver->Adapter.Content;
	uint32_t time = xSystemGetTime();

	if (time - adapter->Content.TimeStamp > 1000)
	{
		if (adapter->Content.State == AHT10_HandleStateIdle)
		{
			adapter->Content.ConvertationRequestUpdate = true;
		}
	}

	if (adapter->Content.OpereationTimeout)
	{
		return;
	}

	switch (adapter->Content.State)
	{
		case AHT10_HandleStateIdle:
		{
			if (adapter->Content.ConvertationRequestUpdate)
			{
				adapter->Content.ConvertationError = false;
				adapter->Content.ConvertationComplited = false;
				adapter->Content.ConvertationRequestUpdate = false;

				adapter->Content.State = AHT10_HandleStateRequestStartMeasurment;
			}
			break;
		}

		case AHT10_HandleStateRequestStartMeasurment:
		{
			uint8_t AHT10_TmpHum_Cmd[3] = {0xAC, 0x33, 0x00};
			int8_t result = HAL_I2C_Master_Transmit_IT(&hi2c2, AHT10_ADDRESS, AHT10_TmpHum_Cmd, 3);
			if(result != HAL_OK)
			{
				adapter->Content.ConvertationError = true;
				adapter->Content.State = AHT10_HandleStateIdle;

				driver->EventListener(driver, AHT10_EventMeasurementError, 0, NULL);
				break;
			}

			adapter->Content.State = AHT10_HandleStateRequestWaitTransmit;

			break;
		}

		case AHT10_HandleStateRequestWaitTransmit:
		{

			if(StatusTransmit == StatusTransmitDone)
			{
				adapter->Content.State = AHT10_HandleStateRequestStartConvertation;

			}else{

				adapter->Content.State = AHT10_HandleStateIdle;

			}

			break;

		}
		case AHT10_HandleStateRequestStartConvertation:
		{

			if((StatusReceive = StatusReceiveDone))
			{
				adapter->Content.ConvertationComplited = true;
				AHT10_EventMeasurementComplitedArgT arg = { 0 };
				arg.Humidity = adapterContent.AHT10_Humidity;
				arg.Temperature = adapterContent.AHT10_Temperature;
				driver->EventListener(driver, AHT10_EventMeasurementComplited, 0, &arg);
				adapter->Content.State = AHT10_HandleStateIdle;
			}else{
				adapter->Content.State = AHT10_HandleStateIdle;
			}



			break;
		}
	}
}

//==============================================================================
//initializations:

static AHT10_AdapterInterfaceT privateInterface =
{
	.Handler = (AHT10_AdapterHandlerT)privateHandler,
	.RequestListener = (AHT10_AdapterRequestListenerT)privateRequestListener,

};
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

	adapter->Content.State = AHT10_HandleStateIdle;

	return 0;
}
//==============================================================================
