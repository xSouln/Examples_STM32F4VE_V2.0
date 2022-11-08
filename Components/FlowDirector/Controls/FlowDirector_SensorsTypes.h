//==============================================================================
#ifndef _FLOW_DIRECTOR_SENSORS_TYPES_H
#define _FLOW_DIRECTOR_SENSORS_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "Components_Includes.h"
#include "FlowDirector_SensorsConfig.h"
#include "FlowDirector/Adapters/FlowDirector_SensorsAdapterBase.h"
//==============================================================================
typedef enum
{
	FlowDirectorSensorLimit,
	FlowDirectorSensorOvercurrent,
	FlowDirectorSensorsCount
	
} FlowDirectorSensors;
//------------------------------------------------------------------------------
typedef enum
{
	FlowDirectorSensorMaskLimit = 1 << FlowDirectorSensorLimit,
	FlowDirectorSensorMaskOvercurrent = 1 << FlowDirectorSensorOvercurrent
	
} FlowDirectorSensorMask;
//------------------------------------------------------------------------------
typedef union
{
	struct
	{
		uint8_t Limit : 1;
		uint8_t Overcurrent : 1;
	};
	
	FlowDirectorSensorMask Value;
	
} FlowDirectorSensorsStateT;
//------------------------------------------------------------------------------
typedef struct
{
	OBJECT_HEADER;
	
	FlowDirectorSensorsAdapterBaseT Adapter;
	
	FlowDirectorSensorsStateT State;
	FlowDirectorSensorsStateT LastState;
	
} FlowDirectorSensorsT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif
