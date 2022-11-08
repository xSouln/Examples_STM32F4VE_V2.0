//==============================================================================
#ifndef _SLIDER_SENSORS_BASE_H
#define _SLIDER_SENSORS_BASE_H
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
	SliderSensorspEventIdle,
	
} SliderSensorsEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	SliderSensorsRequestIdle,
	SliderSensorsRequestUpdateState
	
} SliderSensorsRequestSelector;
//------------------------------------------------------------------------------
typedef enum
{
	SliderSensorsValueIdle,
	
} SliderSensorsValueSelector;
//------------------------------------------------------------------------------
typedef void (*SliderSensorsHandlerT)(void* device);
typedef xResult (*SliderSensorsRequestListenerT)(void* device, SliderSensorsRequestSelector selector, uint32_t args, uint32_t count);
//------------------------------------------------------------------------------
typedef struct
{
	SliderSensorsHandlerT Handler;
	SliderSensorsRequestListenerT RequestListener;
	
} SliderSensorsInterfaceT;
//------------------------------------------------------------------------------
typedef enum
{
	SliderSensorClose = 1 << 0,
	SliderSensorOpen = 1 << 1,
	SliderSensorOvercurrent = 1 << 2
	
} SliderSensors;
//------------------------------------------------------------------------------
typedef union
{
	struct
	{
		uint8_t Close : 1;
		uint8_t Open : 1;
		uint8_t Overcurrent : 1;
	};
	
	SliderSensors Value;
	
} SliderSensorsStateT;
//------------------------------------------------------------------------------
typedef struct
{
	OBJECT_HEADER;
	
	void* Child;
	SliderSensorsInterfaceT Interface;
	
	SliderSensorsStateT State;
	SliderSensorsStateT LastState;
	
} SliderSensorsBaseT;
//==============================================================================
xResult SliderSensorsBaseInit(SliderSensorsBaseT* adapter, void* parent);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif
