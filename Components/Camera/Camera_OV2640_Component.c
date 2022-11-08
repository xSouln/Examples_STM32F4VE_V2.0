//==============================================================================
#include "Camera_OV2640_Component.h"
#include "main.h"
#include "dcmi.h"
#include "i2c.h"
//==============================================================================
#define CAMERA_SNAPSHOT_BUFFER_SIZE 0xffff

uint32_t camera_snapshot_buffer[CAMERA_SNAPSHOT_BUFFER_SIZE / sizeof(CameraBufferT)];
//------------------------------------------------------------------------------
extern const xRxRequestT CameraRequests[];

CameraT CameraOV2640;
//==============================================================================
static void EventListener(CameraT* camera, CameraEventSelector event, uint32_t args, uint32_t count)
{
	switch ((uint8_t)event)
	{
		case CameraEventSnapshotComplite:
			xTxTransferStart(&camera->TransferLayer,
												camera->SnapshotBuffer,
												camera->SnapshotSize);
			break;
		
		default : return;
	}
}
//------------------------------------------------------------------------------
static xResult RequestListener(CameraT* camera, CameraRequestSelector event, uint32_t args, uint32_t count)
{
	switch ((uint8_t)event)
	{
		case CameraRequestDelay :
			HAL_Delay(args);
			break;
		
		default : return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//==============================================================================
CameraInterfaceT CameraInterface =
{
	.EventListener = (CameraEventListenerT)EventListener,
	.RequestListener = (CameraRequestListenerT)RequestListener
};
//------------------------------------------------------------------------------
CameraOV2640AdapterT CameraOV2640Adapter =
{
	.PowerDownPin = CAMERA_PWDN_Pin,
	.PowerDownPort = CAMERA_PWDN_GPIO_Port,
	
	.HardwareResetPin = CAMERA_RESET_Pin,
	.HardwareResetPort = CAMERA_RESET_GPIO_Port,
	
	.HandleDCMI = &hdcmi,
	.HandleI2C = &hi2c1,
};
//==============================================================================
xResult CameraOV2640ComponentInit(void* parent)
{
	xResult result = xResultAccept;
	
	result = CameraInit(&CameraOV2640, parent, &CameraInterface);
	
	if (result != xResultAccept) { goto end; }
	
	CameraOV2640.SnapshotBuffer = camera_snapshot_buffer;
	CameraOV2640.SnapshotBufferSize = sizeof(camera_snapshot_buffer);
	
	result = CameraOV2640AdapterInit(&CameraOV2640, &CameraOV2640Adapter);
	
	CameraOV2640.Requests = (xRxRequestT*)CameraRequests;
	
	xTxTransferInit(&CameraOV2640.TransferLayer, 100, 2000, 0.8);
	
	end:;
  return result;
}
//==============================================================================
