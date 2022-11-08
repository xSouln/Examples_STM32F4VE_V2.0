//==============================================================================
#ifndef _FLOW_DIRECTOR_SENSORS_ADAPTER_H
#define _FLOW_DIRECTOR_SENSORS_ADAPTER_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "FlowDirector/Controls/FlowDirector_Sensors.h"
//==============================================================================
typedef struct
{
	GPIO_TypeDef* OvercurrentSensorPort;
	uint32_t OvercurrentSensorPin;
	
	GPIO_TypeDef* LimitSensorPort;
	uint32_t LimitSensorPin;
	
	struct
	{
		uint8_t OvercurrentSensorOnStateLogicLevel : 1;
		uint8_t LimitSensorOnStateLogicLevel : 1;
	};
	
} FlowDirectorSensorsAdapterT;
//==============================================================================
xResult FlowDirectorSensorsAdapterInit(FlowDirectorSensorsT* device, FlowDirectorSensorsAdapterT* adapter);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

