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
	CameraAdapterEventEndLine,
	CameraAdapterEventReceiverBufferIsFull
	
} CameraAdapterEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	CameraAdapterRequestDelay = 1U,
	
} CameraAdapterRequestSelector;
//------------------------------------------------------------------------------
typedef enum
{
	CameraAdapterValueTransmitterStatus = 1U,
	
} CameraAdapterValueSelector;
//------------------------------------------------------------------------------
typedef void (*CameraAdapterActionHandler)(void* camera);

typedef xResult (*CameraAdapterRequestListener)(void* camera, CameraAdapterRequestSelector selector, uint32_t args, uint32_t count);

typedef int (*CameraAdapterActionGetValue)(void* camera, CameraAdapterValueSelector selector);
typedef xResult (*CameraAdapterActionSetValue)(void* camera, CameraAdapterValueSelector selector, uint32_t value);
//------------------------------------------------------------------------------
typedef struct
{
	CameraAdapterActionHandler Handler;
	
	CameraAdapterRequestListener RequestListener;
	
	CameraAdapterActionGetValue GetValue;
	CameraAdapterActionSetValue SetValue;
	
} CameraAdapterInterfaceT;
//==============================================================================
typedef enum
{
	CameraUpdateState = 1U,
	
} CameraEventSelector;
//------------------------------------------------------------------------------
typedef void (*CameraEventListener)(void* camera, CameraEventSelector event, uint32_t args, uint32_t count);
//------------------------------------------------------------------------------
typedef struct
{
	CameraEventListener EventListener;
	
} CameraInterfaceT;
//------------------------------------------------------------------------------
typedef struct
{
	void* Description;
	void* Parent;
	
	void* Adapter;
	void* Driver;
	
	CameraAdapterInterfaceT AdapterInterface;
	CameraInterfaceT* Interface;
	
} CameraT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* _CAMERA_TYPES_H */
