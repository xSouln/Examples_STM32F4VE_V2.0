//==============================================================================
#ifndef _CAROUSEL_SENSORS_BASE_H
#define _CAROUSEL_SENSORS_BASE_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "Common/xTypes.h"
#include "Components_Config.h"
//==============================================================================
typedef enum
{
	CarouselSensorspEventIdle,
	
} CarouselSensorsEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	CarouselSensorsRequestIdle,
	CarouselSensorsRequestUpdateState
	
} CarouselSensorsRequestSelector;
//------------------------------------------------------------------------------
typedef enum
{
	CarouselSensorsValueIdle,
	
} CarouselSensorsValueSelector;
//------------------------------------------------------------------------------
typedef void (*CarouselSensorsHandlerT)(void* device);
typedef xResult (*CarouselSensorsRequestListenerT)(void* device, CarouselSensorsRequestSelector selector, uint32_t args, uint32_t count);
//------------------------------------------------------------------------------
typedef struct
{
	CarouselSensorsHandlerT Handler;
	CarouselSensorsRequestListenerT RequestListener;
	
} CarouselSensorsInterfaceT;
//------------------------------------------------------------------------------
typedef enum
{
	CarouselSensorZeroMark = 1 << 0,
	CarouselSensorOvercurrent = 1 << 1
	
} CarouselSensors;
//------------------------------------------------------------------------------
typedef union
{
	struct
	{
		uint8_t ZeroMark : 1;
		uint8_t Overcurrent : 1;
	};
	
	uint8_t Value;
	
} CarouselSensorsT;
//------------------------------------------------------------------------------
typedef struct
{
	OBJECT_HEADER;
	
	void* Child;
	CarouselSensorsInterfaceT Interface;
	
	CarouselSensorsT State;
	CarouselSensorsT LastState;
	
} CarouselSensorsBaseT;
//==============================================================================
xResult CarouselSensorsBaseInit(CarouselSensorsBaseT* adapter, void* parent);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif