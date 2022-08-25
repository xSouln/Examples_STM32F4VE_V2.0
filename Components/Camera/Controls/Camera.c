//==============================================================================
#include "Camera/Controls/Camera.h"
//==============================================================================
xResult CameraGetSnapshot(CameraT* camera)
{
	return camera->AdapterInterface.RequestListener(camera, CameraAdapterRequestGetSnapshot, 0, 0);
}
//==============================================================================
xResult CameraInit(CameraT* camera, void* parent, CameraInterfaceT* interface)
{
	if (camera && interface)
	{
		camera->Description = "CameraT";
		camera->Parent = parent;
		camera->Interface = interface;
		
		return xResultAccept;
	}
	
	return xResultError;
}
//==============================================================================
