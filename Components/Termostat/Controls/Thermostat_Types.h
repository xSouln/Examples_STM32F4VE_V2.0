//==============================================================================
#ifndef _TERMOSTAT_TYPES_H
#define _TERMOSTAT_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "Components_Config.h"
#include "Termostat/Adapters/Thermostat_AdapterBase.h"
//==============================================================================
typedef union
{
	struct
	{
		uint32_t HeaterIsEnable : 1;
		uint32_t MeasureIsEnable : 1;
	};
	
	uint32_t Value;
	
} TermostatStatusT;
//------------------------------------------------------------------------------
typedef struct
{
	uint16_t TemperatureUpdatePeriod;
	
} TermostatOptionsT;
//------------------------------------------------------------------------------
typedef struct
{
	OBJECT_HEADER;
	
	TermostatAdapterBaseT Adapter;
	
	TermostatStatusT Status;
	TermostatOptionsT Options;
	TermostatPointT Points[TERMOSTAT_POINTS_BUFFER_SIZE];
	uint32_t AverageFromPoints;
	
	float TotalTemperature;
	float RequestTemperature;
	
	uint16_t TemperatureUpdateTime;
	
} TermostatT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif