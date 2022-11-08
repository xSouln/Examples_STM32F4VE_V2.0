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
#include "Common/xRxTransaction.h"
#include "Controls/Camera_AdapterBase.h"
//==============================================================================
typedef enum
{
	CameraEventIdle,
	CameraEventSnapshotComplite,
	
} CameraEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	CameraRequestIdle,
	CameraRequestDelay = 1U,
	
} CameraRequestSelector;
//------------------------------------------------------------------------------
typedef void (*CameraEventListenerT)(void* camera, CameraEventSelector event, uint32_t args, uint32_t count);
typedef xResult (*CameraRequestListenerT)(void* camera, CameraRequestSelector selector, uint32_t args, uint32_t count);
//------------------------------------------------------------------------------
typedef struct
{
	CameraEventListenerT EventListener;
	CameraRequestListenerT RequestListener;
	
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
	
} CameraResolutionT;
//------------------------------------------------------------------------------
typedef enum
{
	CameraOutputFormat_JPEG,
	CameraOutputFormat_YUV422,
	CameraOutputFormat_RGB565,
	CameraOutputFormat_RAW,
	
} CameraOutputFormatT;
//------------------------------------------------------------------------------
typedef enum
{
	CameraSpecialEffect_Normal,
	
} CameraSpecialEffectT;
//------------------------------------------------------------------------------
typedef enum
{
	CameraLightMode_Auto,
	CameraLightMode_Sunny,
	CameraLightMode_Cloudy,
	CameraLightMode_Office,
	CameraLightMode_Home,
	
} CameraLightModeT;
//------------------------------------------------------------------------------
typedef int8_t CameraSaturationT;
typedef int8_t CameraContrastT;
typedef int8_t CameraBrightnessT;
typedef uint8_t CameraQuantizationT;
typedef uint8_t CameraGainT;
//------------------------------------------------------------------------------
typedef struct
{
	CameraOutputFormatT OutputFormat;
	CameraResolutionT Resolution;
	
	CameraContrastT Contrast;
	CameraSaturationT Saturation;
	CameraBrightnessT Brightness;
	
	CameraLightModeT LightMode;
	CameraSpecialEffectT SpecialEffect;
	CameraQuantizationT Quantization;
	
	CameraGainT Gain;
	
} CameraOptionsT;
//------------------------------------------------------------------------------
typedef enum
{
	CameraSnapshotIdle,
	CameraSnapshotCapture,
	CameraSnapshotComplite,
	CameraSnapshotError,
	
} CameraSnapshotStatus;
//------------------------------------------------------------------------------
typedef enum
{
	CameraSnapshotResultNoError,
	CameraSnapshotResultTimeOut,
	CameraSnapshotResultOutOfRange
	
} CameraSnapshotResults;
//------------------------------------------------------------------------------
typedef union
{
	struct
	{
		uint32_t IsCapture : 1;
		
		uint32_t Snapshot : 2;
		uint32_t SnapshotResult : 2;
		
		uint32_t InitResult : 4;
		uint32_t DriverInitResult : 4;
		uint32_t AdapterInitResult : 4;
	};
	uint32_t Value;
	
} CameraStatusT;
//------------------------------------------------------------------------------
typedef struct
{
	OBJECT_HEADER;
	
	CameraAdapterBaseT Adapter;
	CameraInterfaceT* Interface;
	
	CameraStatusT Status;
	CameraOptionsT Options;
	
	xRxRequestT* Requests;
	xTxTransferT TransferLayer;
	
	uint32_t TimeOut;
	
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
