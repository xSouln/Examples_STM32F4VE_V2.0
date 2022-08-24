//==============================================================================
#include "Camera_Component.h"
//==============================================================================
#define CAMERA_SNAPSHOT_BUFFER_SIZE 0xffff

CameraBufferT camera_snapshot_buffer[CAMERA_SNAPSHOT_BUFFER_SIZE / sizeof(CameraBufferT)];
//------------------------------------------------------------------------------
CameraT CameraOV2640;
//==============================================================================
void CameraEventListener(void* camera, CameraEventSelector event, uint32_t args, uint32_t count)
{
	switch ((uint8_t)event)
	{
		default : return;
	}
}
//==============================================================================
CameraInterfaceT CameraInterface =
{
	.EventListener = CameraEventListener
};
//------------------------------------------------------------------------------
OV2640_AdapterT Adapter =
{
	.HandleI2C = &hi2c2
};
//==============================================================================
int CameraOV2640_ComponentInit(void* parent)
{
	CameraInit(&CameraOV2640, parent, &CameraInterface);
	
	CameraOV2640.SnapshotBuffer = camera_snapshot_buffer;
	CameraOV2640.SnapshotBufferSize = CAMERA_SNAPSHOT_BUFFER_SIZE;
	
	OV2640_AdapterInit(&CameraOV2640, &Adapter);
	
  return 0;
}
//==============================================================================
