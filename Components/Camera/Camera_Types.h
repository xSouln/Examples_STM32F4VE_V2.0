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
