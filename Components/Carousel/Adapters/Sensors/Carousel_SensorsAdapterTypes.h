//==============================================================================
#ifndef _CAROUSEL_SENSORS_ADAPTER_TYPES_H
#define _CAROUSEL_SENSORS_ADAPTER_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "Carousel/Controls/Carousel_SensorsBase.h"
#include "Carousel_SensorsAdapterConfig.h"
//==============================================================================
typedef struct
{
	GPIO_TypeDef* SensorOvercurrentPort;
	uint32_t SensorOvercurrentPin;
	
	GPIO_TypeDef* SensorZeroMarkPort;
	uint32_t SensorZeroMarkPin;
	
	struct
	{
		uint8_t SensorZeroMarkOnStateLogicLevel : 1;
		uint8_t SensorOvercurrentOnStateLogicLevel : 1;
	};
	
} CarouselSensorsAdapterT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

