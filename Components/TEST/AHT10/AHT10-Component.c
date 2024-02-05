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

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void AHT10_ComponentHandler()
{
	AHT10_Handler(&AHT10);

}
//------------------------------------------------------------------------------
void AHT10_ComponentTimeSynchronization()
{

}
//==============================================================================
//initializations:

static AHT10_HAL_AdapterT  privateAdapter;


//==============================================================================
//initialization:

xResult AHT10_ComponentInit(void* parent)
{

	AHT10_HAL_AdapterInitT adapterInit;
	adapterInit.LED_Port =  LED_1_GPIO_Port;
	adapterInit.LED_Pin = 6;
	AHT10_HAL_AdapterInit(&AHT10, &privateAdapter, &adapterInit);

	AHT10InitT init;
	init.Address = 0x38;
	init.Parent = "Parent";
	AHT10_Init(&AHT10, &init);


	return xResultAccept;
}
//==============================================================================

