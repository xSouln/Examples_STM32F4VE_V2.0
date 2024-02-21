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
	AHT10_HandleStateRequestWaitReceive,
	AHT10_HandleStateRequestWaitConvertation,

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

static AHT10_T* privateDriver;
//==============================================================================
//functions:

void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c)
{
	AHT10_HAL_AdapterT* adapter = privateDriver->Adapter.Content;

	if(hi2c == adapter->Handle)
	{
		adapter->Content.TransmitionIsComplited = true;
	}

}
//------------------------------------------------------------------------------

void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c)
{
	AHT10_HAL_AdapterT* adapter = privateDriver->Adapter.Content;

	if(hi2c == adapter->Handle)
	{
		adapter->Content.TransmitionIsComplited = true;
		/*
		// Convert to Humidity in °C
		uint32_t AHT10_ADC_Raw = (((uint32_t)AHT10_RX_Data[1]  << 16\
						| ((uint16_t)AHT10_RX_Data[2] << 8)\
						| (AHT10_RX_Data[3]))) >> 4;
		adapterContent.AHT10_Humidity = ((float)AHT10_ADC_Raw / 1048576) * 100;

		// Convert to Temperature in °C
		AHT10_ADC_Raw = (((uint32_t)AHT10_RX_Data[3] & 0x0f) << 16 )
						| ((uint16_t)AHT10_RX_Data[4] << 8)
						| AHT10_RX_Data[5];
		adapterContent.AHT10_Temperature = (float)AHT10_ADC_Raw * 200 / 1048576 - 50;
		StatusReceive = StatusReceiveDone;*/
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

	if (adapter->Content.OpereationTimeout && !adapter->Content.TransmitionIsComplited)
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
			else
			{
				break;
			}
		}

		case AHT10_HandleStateRequestStartMeasurment:
		{
			memcpy(adapter->Content.TranseiverBuffer, (uint8_t[]){ 0xAC, 0x33, 0x00 }, 3);

			int8_t result = HAL_I2C_Master_Transmit_IT(adapter->Handle, AHT10_ADDRESS, adapter->Content.TranseiverBuffer, 3);
			if(result != HAL_OK)
			{
				adapter->Content.ConvertationError = true;
				adapter->Content.State = AHT10_HandleStateIdle;

				driver->EventListener(driver, AHT10_EventMeasurementError, 0, NULL);
				break;
			}

			adapter->Content.OpereationTimeout = 300;
			adapter->Content.State = AHT10_HandleStateRequestWaitTransmit;

			break;
		}

		case AHT10_HandleStateRequestWaitTransmit:
		{
			if (adapter->Content.TransmitionIsComplited)
			{
				adapter->Content.State = AHT10_HandleStateRequestWaitConvertation;
				adapter->Content.OpereationTimeout = 100;
			}
			else
			{
				adapter->Content.ConvertationError = true;
				adapter->Content.State = AHT10_HandleStateIdle;

				driver->EventListener(driver, AHT10_EventMeasurementError, 0, NULL);
			}

			break;
		}

		case AHT10_HandleStateRequestWaitConvertation:
		{
			memset(adapter->Content.TranseiverBuffer, 0, sizeof(adapter->Content.TranseiverBuffer));

			int8_t result = HAL_I2C_Master_Receive_IT(adapter->Handle, AHT10_ADDRESS | 0x01, adapter->Content.TranseiverBuffer, 6);
			if(result != HAL_OK)
			{
				adapter->Content.ConvertationError = true;
				adapter->Content.State = AHT10_HandleStateIdle;

				driver->EventListener(driver, AHT10_EventMeasurementError, 0, NULL);
				break;
			}

			adapter->Content.State = AHT10_HandleStateRequestWaitReceive;
			adapter->Content.OpereationTimeout = 100;

			break;
		}

		case AHT10_HandleStateRequestWaitReceive:
		{
			if (adapter->Content.TransmitionIsComplited)
			{
				adapter->Content.State = AHT10_HandleStateIdle;

				uint32_t AHT10_ADC_Raw = (((uint32_t)adapter->Content.TranseiverBuffer[1]  << 16\
										| ((uint16_t)adapter->Content.TranseiverBuffer[2] << 8)\
										| (adapter->Content.TranseiverBuffer[3]))) >> 4;

				adapter->Content.AHT10_Humidity = ((float)AHT10_ADC_Raw / 1048576) * 100;

				// Convert to Temperature in °C
				AHT10_ADC_Raw = (((uint32_t)adapter->Content.TranseiverBuffer[3] & 0x0f) << 16 )
								| ((uint16_t)adapter->Content.TranseiverBuffer[4] << 8)
								| adapter->Content.TranseiverBuffer[5];
				adapter->Content.AHT10_Temperature = (float)AHT10_ADC_Raw * 200 / 1048576 - 50;

				adapter->Content.ConvertationComplited = true;

				AHT10_EventMeasurementComplitedArgT arg = { 0 };
				arg.Humidity = adapter->Content.AHT10_Humidity;
				arg.Temperature = adapter->Content.AHT10_Temperature;
				driver->EventListener(driver, AHT10_EventMeasurementComplited, 0, &arg);
			}
			else
			{
				adapter->Content.ConvertationError = true;
				adapter->Content.State = AHT10_HandleStateIdle;

				driver->EventListener(driver, AHT10_EventMeasurementError, 0, NULL);
				break;
			}
		}
		/*
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
			}
			else
			{
				adapter->Content.State = AHT10_HandleStateIdle;
			}



			break;
		}		*/
	}

	adapter->Content.TransmitionIsComplited = false;
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

	privateDriver = driver;
	adapter->Content.State = AHT10_HandleStateIdle;

	return 0;
}
//==============================================================================
