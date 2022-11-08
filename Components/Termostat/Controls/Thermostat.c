//==============================================================================
#include "Thermostat.h"
//==============================================================================
//==============================================================================
inline void TermostatHandler(TermostatT* device)
{
	device->Adapter.Handler(device);
	
	if (!device->TemperatureUpdateTime)
	{
		device->TemperatureUpdateTime = device->Options.TemperatureUpdatePeriod;
		
		uint32_t value = 0;
		
		for (uint16_t i = 0; i < TERMOSTAT_POINTS_BUFFER_SIZE; i++)
		{
			value += device->Points[i];
		}
		
		device->AverageFromPoints = value / TERMOSTAT_POINTS_BUFFER_SIZE;
		
		device->TotalTemperature = 1.0 * device->AverageFromPoints;
	}
}
//------------------------------------------------------------------------------
inline void TermostatTimeSynchronization(TermostatT* device)
{
	device->Adapter.EventListener(device, TermostatEventTimeSynchronization, 0, 0);
	
	if (device->TemperatureUpdateTime)
	{
		device->TemperatureUpdateTime--;
	}
}
//------------------------------------------------------------------------------
xResult TermostatStartMeasurement(TermostatT* device)
{
	xResult result = device->Adapter.RequestListener(device, TermostatRequestStartMeasurement, 0, 0);
	
	if (result == xResultAccept)
	{
		device->Status.MeasureIsEnable = true;
	}
	
	return result;
}
//------------------------------------------------------------------------------
void TermostatStoptMeasurement(TermostatT* device)
{
	device->Adapter.RequestListener(device, TermostatRequestStopMeasurement, 0, 0);
	device->Status.MeasureIsEnable = false;
}
//------------------------------------------------------------------------------
xResult TermostatHeaterEnable(TermostatT* device)
{
	xResult result = device->Adapter.RequestListener(device, TermostatRequestHeaterEnable, 0, 0);
	
	if (result == xResultAccept)
	{
		device->Status.HeaterIsEnable = true;
	}
	
	return result;
}
//------------------------------------------------------------------------------
void TermostatHeaterDisable(TermostatT* device)
{
	device->Adapter.RequestListener(device, TermostatRequestHeaterDisable, 0, 0);
	device->Status.HeaterIsEnable = false;
}
//==============================================================================
xResult TermostatInit(TermostatT* device, void* parent)
{
	if (device)
	{
		device->Description = "TermostatT";
		device->Parent = parent;
		device->Options.TemperatureUpdatePeriod = TERMOSTAT_TEMPERATURE_UPDATE_PERIOD;
		
		return xResultAccept;
	}
	
	return xResultLinkError;
}
//==============================================================================