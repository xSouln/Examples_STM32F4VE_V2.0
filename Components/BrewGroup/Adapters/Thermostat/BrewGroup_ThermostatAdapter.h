//==============================================================================
#ifndef _BREW_GROUP_TERMOSTAT_ADAPTER_H
#define _BREW_GROUP_TERMOSTAT_ADAPTER_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "BrewGroup/Controls/BrewGroup_Types.h"
#include "Termostat/Controls/Thermostat.h"
#include "adc.h"
//==============================================================================
typedef struct
{
	uint16_t UpdateTime;
	
} BrewGroupTermostatAdapterDataT;
//------------------------------------------------------------------------------
typedef struct
{
	ADC_HandleTypeDef* Adc;
	
	GPIO_TypeDef* HeaterPort;
	uint32_t HeaterPin;
	
	BrewGroupTermostatAdapterDataT Data;
	uint16_t AdcUpdateTime;
	
	struct
	{
		uint8_t HeaterOnStateLogicLevel : 1;
	};
	
} BrewGroupTermostatAdapterT;
//==============================================================================
xResult BrewGroupTermostatAdapterInit(TermostatT* device, BrewGroupTermostatAdapterT* adapter);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

