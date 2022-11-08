//==============================================================================
#ifndef _CAMERA_ADAPTER_BASE_H
#define _CAMERA_ADAPTER_BASE_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "Common/xTypes.h"
//==============================================================================
typedef enum
{
	CameraAdapterEventIdle,
	CameraAdapterEventIRQ,
	
} CameraAdapterEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	CameraAdapterRequestIdle,
	CameraAdapterRequestGetSnapshot,
	CameraAdapterRequestSetConfiguration,
	CameraAdapterRequestSetOptions,
	
} CameraAdapterRequestSelector;
//------------------------------------------------------------------------------
typedef enum
{
	CameraAdapterValueIdle,
	CameraAdapterValueTransmitterStatus,
	CameraAdapterValueOutputFormat,
	CameraAdapterValueResolution,
	CameraAdapterValueContrast,
	CameraAdapterValueSaturation,
	CameraAdapterValueBrightnes,
	CameraAdapterValueLightMode,
	CameraAdapterValueSpecialEffect,
	CameraAdapterValueQuantization,
	CameraAdapterValueGain,
	
} CameraAdapterValueSelector;
//------------------------------------------------------------------------------
typedef void (*CameraAdapterHandlerT)(void* device);

typedef void (*CameraAdapterEventListenerT)(void* device, CameraAdapterEventSelector selector, uint32_t args, uint32_t count);
typedef xResult (*CameraAdapterRequestListenerT)(void* device, CameraAdapterRequestSelector selector, uint32_t args, uint32_t count);

typedef uint32_t (*CameraAdapterActionGetValueT)(void* device, CameraAdapterValueSelector selector);
typedef xResult (*CameraAdapterActionSetValueT)(void* device, CameraAdapterValueSelector selector, uint32_t value);
//------------------------------------------------------------------------------
typedef struct
{
	CameraAdapterHandlerT Handler;
	
	CameraAdapterEventListenerT EventListener;
	CameraAdapterRequestListenerT RequestListener;
	
	CameraAdapterActionGetValueT GetValue;
	CameraAdapterActionSetValueT SetValue;
	
} CameraAdapterInterfaceT;
//------------------------------------------------------------------------------
typedef struct
{
	OBJECT_HEADER;
	
	void* Child;
	CameraAdapterInterfaceT* Interface;
	
} CameraAdapterBaseT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif