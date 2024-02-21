//==============================================================================
//includes:

#include "AHT10-Component.h"
#include "Adapters/STM32_HAL/AHT10_HAL_Adapter.h"

//==============================================================================
//defines:



//==============================================================================
//import:


//==============================================================================
//variables:

AHT10_T AHT10;
AHT10_EventMeasurementComplitedArgT  AHT10_MeasurementResult;
//==============================================================================
//functions:

void AHT10_ComponentHandler()
{
	AHT10_Handler(&AHT10);
}
//------------------------------------------------------------------------------

void AHT10_ComponentTimeSynchronization()
{
	AHT10_TimeSynchronization(&AHT10);
}
//------------------------------------------------------------------------------

static void privateEventListener(AHT10_T* driver, int selector, uint32_t description, void* arg)
{
	switch(selector)
	{
		case AHT10_EventMeasurementComplited:
		{
			memcpy(&AHT10_MeasurementResult, arg, sizeof(AHT10_EventMeasurementComplitedArgT));
			break;
		}

		case AHT10_EventMeasurementError:
		{

			break;
		}
	}
}
//==============================================================================
//initializations:

static AHT10_HAL_AdapterT privateAdapter;
//==============================================================================
//initialization:

xResult AHT10_ComponentInit(void* parent)
{
	AHT10_HAL_AdapterInitT adapterInit;
	adapterInit.LED_Port =  LED_1_GPIO_Port;
	adapterInit.LED_Pin = 6;
	adapterInit.Handle = &hi2c2;
	AHT10_HAL_AdapterInit(&AHT10, &privateAdapter, &adapterInit);

	AHT10InitT init;
	init.Address = 0x38;
	init.Parent = "Parent";
	init.EventListener = (void*)privateEventListener;
	AHT10_Init(&AHT10, &init);


	return xResultAccept;
}
//==============================================================================

