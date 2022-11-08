//==============================================================================
#ifndef _SLIDER_SENSORS_ADAPTER_TYPES_H
#define _SLIDER_SENSORS_ADAPTER_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "Slider/Controls/Slider_SensorsBase.h"
#include "Slider_SensorsAdapterConfig.h"
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
	
} SliderSensorsAdapterT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

