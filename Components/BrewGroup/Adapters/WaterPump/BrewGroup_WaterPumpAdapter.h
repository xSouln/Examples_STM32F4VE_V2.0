//==============================================================================
#ifndef _BREW_GROUP_WATER_PUMP_ADAPTER_H
#define _BREW_GROUP_WATER_PUMP_ADAPTER_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "BrewGroup/Controls/BrewGroup_Types.h"
#include "WaterPump/Controls/WaterPump.h"
#include "tim.h"
//==============================================================================
typedef struct
{
	GPIO_TypeDef* ControlPort;
	uint32_t ControlPin;
	
	struct
	{
		uint8_t ControlOnStateLogicLevel : 1;
	};
	
} BrewGroupWaterPumpAdapterT;
//==============================================================================
xResult BrewGroupWaterPumpAdapterInit(WaterPumpT* device, BrewGroupWaterPumpAdapterT* adapter);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

