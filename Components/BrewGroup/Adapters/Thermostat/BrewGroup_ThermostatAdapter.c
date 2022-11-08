//==============================================================================
#include "BrewGroup_ThermostatAdapter.h"
//==============================================================================
static void PrivateTermostatHandler(TermostatT* device)
{
	BrewGroupTermostatAdapterT* adapter = device->Adapter.Child;
	
	if (device->Status.MeasureIsEnable && !adapter->Data.UpdateTime)
	{
		adapter->Data.UpdateTime = adapter->AdcUpdateTime;
		HAL_ADC_Start(adapter->Adc);
	}
}
//------------------------------------------------------------------------------
static xResult PrivateTermostatRequestListener(TermostatT* device,
												TermostatRequestSelector selector,
												uint32_t args,
												uint32_t count)
{
	BrewGroupTermostatAdapterT* adapter = device->Adapter.Child;
	
	switch ((int)selector)
	{
		case TermostatRequestHeaterEnable:
			if (adapter->HeaterOnStateLogicLevel) { adapter->HeaterPort->ODR |= adapter->HeaterPin; }
			else { adapter->HeaterPort->ODR &= ~adapter->HeaterPin; }
			break;
			
		case TermostatRequestHeaterDisable:
			if (adapter->HeaterOnStateLogicLevel) { adapter->HeaterPort->ODR &= ~adapter->HeaterPin; }
			else { adapter->HeaterPort->ODR |= adapter->HeaterPin; }
			break;
		
		case TermostatRequestStartMeasurement:
			HAL_ADC_Start_DMA(adapter->Adc, (uint32_t*)device->Points, TERMOSTAT_POINTS_BUFFER_SIZE);
			break;
		
		case TermostatRequestStopMeasurement:
			HAL_ADC_Stop_DMA(adapter->Adc);
			break;
		
		default: return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
static void PrivateTermostatEventListener(TermostatT* device,
											TermostatEventSelector selector,
											uint32_t args,
											uint32_t count)
	{
	BrewGroupTermostatAdapterT* adapter = device->Adapter.Child;
	
	switch ((int)selector)
	{
		case TermostatEventTimeSynchronization:
			if(adapter->Data.UpdateTime)
			{
				adapter->Data.UpdateTime--;
			}
			break;
		
		default: break;
	}
}
//==============================================================================
xResult BrewGroupTermostatAdapterInit(TermostatT* device, BrewGroupTermostatAdapterT* adapter)
{
	if (device && adapter)
	{
		device->Adapter.Description = "BrewGroupTermostatAdapterT";
		device->Adapter.Parent = device;
		device->Adapter.Child = adapter;
		
		device->Adapter.Handler = (TermostatHandlerT)PrivateTermostatHandler;
		device->Adapter.EventListener = (TermostatEventListenerT)PrivateTermostatEventListener;
		device->Adapter.RequestListener = (TermostatRequestListenerT)PrivateTermostatRequestListener;
		
		return xResultAccept;
	}
	return xResultInvalidParameter;
}
//==============================================================================
