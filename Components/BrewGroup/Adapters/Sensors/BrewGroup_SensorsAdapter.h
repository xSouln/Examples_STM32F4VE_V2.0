//==============================================================================
#ifndef _BREW_GROUP_SENSORS_ADAPTER_H
#define _BREW_GROUP_SENSORS_ADAPTER_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "BrewGroup/Controls/BrewGroup_Types.h"
//==============================================================================
typedef struct
{
	GPIO_TypeDef* SensorClosePort;
	uint32_t SensorClosePin;
	
	GPIO_TypeDef* SensorOpenPort;
	uint32_t SensorOpenPin;
	
	GPIO_TypeDef* SensorOvercurrentPort;
	uint32_t SensorOvercurrentPin;
	
	struct
	{
		uint8_t SensorCloseOnStateLogicLevel : 1;
		uint8_t SensorOpenOnStateLogicLevel : 1;
		uint8_t SensorOvercurrentOnStateLogicLevel : 1;
	};
	
} BrewGroupSensorsAdapterT;
//==============================================================================
xResult BrewGroupSensorsAdapterInit(BrewGroupSensorsT* device, BrewGroupSensorsAdapterT* adapter);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

