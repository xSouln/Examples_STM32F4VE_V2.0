//==============================================================================
#include "Camera/Adapters/OV2640/OV2640_Adapter.h"
//==============================================================================
void OV2640_Handler(void* camera)
{
	
}
//------------------------------------------------------------------------------
OV2640_Result OV2640_RequestListener(void* camera, OV2640_RequestSelector selector, uint32_t args, uint32_t count)
{
	switch ((uint8_t)selector)
	{
		case OV2640_RequestI2C_Write :
			OV2640_RequestI2C_WriteT* request = (OV2640_RequestI2C_WriteT*)args;
			
			break;
		
		default : return OV2640_ResultNotSupported;
	}
	
	return OV2640_ResultAccept;
}
//------------------------------------------------------------------------------
int OV2640_ActionGetValue(void* camera, OV2640_ValueSelector selector)
{
	switch ((uint8_t)selector)
	{
		default : return 0;
	}
}
//------------------------------------------------------------------------------
OV2640_Result OV2640_ActionSetValue(void* camera, OV2640_ValueSelector selector, uint32_t value)
{
	switch ((uint8_t)selector)
	{
		default : return OV2640_ResultNotSupported;
	}
	
	return OV2640_ResultAccept;
}
//==============================================================================
xResult OV2640_AdapterInit(CameraT* camera, OV2640_AdapterT* adapter, CameraAdapterInterfaceT* interface)
{
	if (camera && adapter && interface)
	{
		camera->Adapter = adapter;
		
		return xResultAccept;
	}
	
	return xResultError;
}
//==============================================================================
