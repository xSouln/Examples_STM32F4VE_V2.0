//==============================================================================
#ifndef _BREW_GROUP_SENSORS_TYPES_H
#define _BREW_GROUP_SENSORS_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "BrewGroup_SensorsConfig.h"
#include "BrewGroup/Adapters/BrewGroup_SensorsAdapterBase.h"
//==============================================================================
typedef enum
{
	BrewGroupSensorClose = 1 << 0,
	BrewGroupSensorOpen = 1 << 1,
	BrewGroupSensorOvercurrent = 1 << 2
	
} BrewGroupSensors;
//------------------------------------------------------------------------------
typedef union
{
	struct
	{
		uint8_t Close : 1;
		uint8_t Open : 1;
		uint8_t Overcurrent : 1;
	};
	
	BrewGroupSensors Value;
	
} BrewGroupSensorsStateT;
//------------------------------------------------------------------------------
typedef struct
{
	OBJECT_HEADER;
	
	BrewGroupSensorsAdapterBaseT Adapter;
	
	BrewGroupSensorsStateT State;
	BrewGroupSensorsStateT LastState;
	
} BrewGroupSensorsT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif
