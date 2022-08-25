//==============================================================================
#ifndef _CAMERA_TYPES_H
#define _CAMERA_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Camera_Config.h"
#include "Common/xTypes.h"
#include "Common/xTxTransfer.h"
//==============================================================================
typedef enum
{
  CameraResultAccept = 0U,
	CameraResultError,
	CameraResultParametersError,
	CameraResultNotInit,
	CameraResultBusy,
	CameraResultNotSupported,
	CameraResultValueIsNotFound,
	CameraResultRequestIsNotFound,
	CameraResultTimeOut
	
} CameraResult;
//==============================================================================
typedef enum
{
	CameraAdapterEventUpdateState = 1U,
	
	CameraAdapterEventSnapshotComplite,
	
} CameraAdapterEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	CameraAdapterRequestDelay = 1U,
	CameraAdapterRequestGetSnapshot
	
} CameraAdapterRequestSelector;
//------------------------------------------------------------------------------
typedef enum
{
	CameraAdapterValueTransmitterStatus = 1U,
	
} CameraAdapterValueSelector;
//------------------------------------------------------------------------------
typedef void (*CameraAdapterHandlerT)(void* camera);

typedef xResult (*CameraAdapterRequestListenerT)(void* camera, CameraAdapterRequestSelector selector, uint32_t args, uint32_t count);

typedef int (*CameraAdapterActionGetValueT)(void* camera, CameraAdapterValueSelector selector);
typedef xResult (*CameraAdapterActionSetValueT)(void* camera, CameraAdapterValueSelector selector, uint32_t value);
//------------------------------------------------------------------------------
typedef struct
{
	CameraAdapterHandlerT Handler;
	
	CameraAdapterRequestListenerT RequestListener;
	
	CameraAdapterActionGetValueT GetValue;
	CameraAdapterActionSetValueT SetValue;
	
} CameraAdapterInterfaceT;
//==============================================================================
typedef enum
{
	CameraUpdateState = 1U,
	
} CameraEventSelector;
//------------------------------------------------------------------------------
typedef void (*CameraEventListenerT)(void* camera, CameraEventSelector event, uint32_t args, uint32_t count);
//------------------------------------------------------------------------------
typedef struct
{
	CameraEventListenerT EventListener;
	
} CameraInterfaceT;
//------------------------------------------------------------------------------
typedef enum
{
	CameraResolution_160x120,
	CameraResolution_320x240,
	CameraResolution_640x480,
	CameraResolution_800x600,
	CameraResolution_1024x768,
	CameraResolution_1280x960,
	
} CameraResolutions;
//------------------------------------------------------------------------------
typedef enum
{
	CameraOutputFormat_JPEG,
	CameraOutputFormat_YUV422,
	CameraOutputFormat_RGB565,
	CameraOutputFormat_RAW,
	
} CameraOutputFormats;
//------------------------------------------------------------------------------
typedef enum
{
	CameraSpecialEffect_Normal,
	
} CameraSpecialEffects;
//------------------------------------------------------------------------------
typedef enum
{
	CameraLightMode_Auto,
	CameraLightMode_Sunny,
	CameraLightMode_Cloudy,
	CameraLightMode_Office,
	CameraLightMode_Home,
	
} CameraLightModes;
//------------------------------------------------------------------------------
typedef int8_t CameraSaturations;
typedef int8_t CameraContrasts;
typedef int8_t CameraBrightnesses;
typedef uint8_t CameraQuantizations;
//------------------------------------------------------------------------------
typedef struct
{
	CameraOutputFormats OutputFormat;
	CameraResolutions Resolution;
	
	CameraContrasts Contrast;
	CameraSaturations Saturation;
	CameraBrightnesses Brightnes;
	
	CameraLightModes LightMode;
	CameraSpecialEffects SpecialEffect;
	CameraQuantizations Quantization;
	
	uint8_t AGC_Gain;
	
} CameraOptionsT;
//------------------------------------------------------------------------------
typedef struct
{
	void* Description;
	void* Parent;
	
	void* Adapter;
	void* Driver;
	
	CameraAdapterInterfaceT AdapterInterface;
	CameraInterfaceT* Interface;
	
	xTxTransferT TransferLayer;
	
	CameraBufferT* SnapshotBuffer;
	uint32_t SnapshotBufferSize;
	uint32_t SnapshotSize;
	
} CameraT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* _CAMERA_TYPES_H */
