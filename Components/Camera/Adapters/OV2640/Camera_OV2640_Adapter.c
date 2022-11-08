//==============================================================================
#include "Camera/Adapters/OV2640/Camera_OV2640_Adapter.h"
#include "Camera/Camera_Types.h"
#include "Common/xMemory.h"
//==============================================================================
static void OV2640_Handler(OV2640_DriverT* driver)
{
	
}
//------------------------------------------------------------------------------
static xResult OV2640_RequestListener(OV2640_DriverT* driver, OV2640_RequestSelector selector, uint32_t args, uint32_t count)
{
	CameraOV2640AdapterT* adapter = driver->Adapter;
	CameraT* camera = adapter->Camera;
	
	switch ((uint8_t)selector)
	{
		case OV2640_RequestI2C_Write :
			return HAL_I2C_Mem_Write(adapter->HandleI2C,
												((OV2640_RequestI2C_WriteT*)args)->Address,
												((OV2640_RequestI2C_WriteT*)args)->Register,
												I2C_MEMADD_SIZE_8BIT,
												&((OV2640_RequestI2C_WriteT*)args)->Value,
												1,
												100) == HAL_OK ? xResultAccept : xResultError;
			
		case OV2640_RequestI2C_Read :
			return HAL_I2C_Mem_Read(adapter->HandleI2C,
												((OV2640_RequestI2C_ReadT*)args)->Address,
												((OV2640_RequestI2C_ReadT*)args)->Register,
												I2C_MEMADD_SIZE_8BIT,
												((OV2640_RequestI2C_ReadT*)args)->Value,
												1,
												100) == HAL_OK ? xResultAccept : xResultError;
			
		case OV2640_RequestDelay :
			camera->Interface->RequestListener(camera, CameraRequestDelay, args, 0);
			break;
		
		default : return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
static int OV2640_ActionGetValue(OV2640_DriverT* driver, OV2640_ValueSelector selector)
{
	CameraOV2640AdapterT* adapter = driver->Adapter;
	
	switch ((uint8_t)selector)
	{
		case OV2640_ValueHardwareResetState :
			return (adapter->HardwareResetPort->ODR & adapter->HardwareResetPin) ? OV2640_StateDisable : OV2640_StateEnable;
		
		case OV2640_ValuePowerDownState :
			return (adapter->PowerDownPort->ODR & adapter->PowerDownPin) ? OV2640_StateEnable : OV2640_StateDisable;
		
		default : return 0;
	}
}
//------------------------------------------------------------------------------
static xResult OV2640_ActionSetValue(OV2640_DriverT* driver, OV2640_ValueSelector selector, uint32_t value)
{
	CameraOV2640AdapterT* adapter = driver->Adapter;
	
	switch ((uint8_t)selector)
	{
		case OV2640_ValueHardwareResetState :
			if (value == OV2640_StateEnable) { adapter->HardwareResetPort->ODR &= ~adapter->HardwareResetPin; }
			else { adapter->HardwareResetPort->ODR |= adapter->HardwareResetPin; }
			break;
			
		case OV2640_ValuePowerDownState :
			if (value == OV2640_StateEnable) { adapter->PowerDownPort->ODR |= adapter->PowerDownPin; }
			else { adapter->PowerDownPort->ODR &= ~adapter->PowerDownPin; }
			break;
		
		default : return xResultNotSupported;
	}
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
static const OV2640_InterfaceT  OV2640_Interface =
{
	.Handler = (OV2640_HandlerT)OV2640_Handler,
	.RequestListener = (OV2640_RequestListenerT)OV2640_RequestListener,
	.GetValue = (OV2640_ActionGetValueT)OV2640_ActionGetValue,
	.SetValue = (OV2640_ActionSetValueT)OV2640_ActionSetValue
};
//------------------------------------------------------------------------------
static const OV2640_DriverOptionsT OV2640_Options =
{
	.Quantization = OV2640_Quantization_Default,
	.Resolution = OV2640_Resolution_1280x960
};
//==============================================================================
xResult CameraOV2640AdapterInit(CameraT* camera, CameraOV2640AdapterT* adapter)
{
	extern xResult OV2640_AdapterInterfaceInit(CameraAdapterBaseT* adapter);
	
	if (camera && adapter)
	{
		camera->Adapter.Description = "OV2640_AdapterT";
		camera->Adapter.Parent = camera;
		camera->Adapter.Child = adapter;
		adapter->Camera = camera;
		OV2640_AdapterInterfaceInit(&camera->Adapter);
		
		if (xMemoryCheckLincs(camera->Interface, sizeof(CameraInterfaceT)) != 0)
		{
			camera->Status.AdapterInitResult = xResultLinkError;
			goto end;
		}
		camera->Status.AdapterInitResult = xResultAccept;
		
		camera->Status.DriverInitResult = OV2640_DriverInit(&adapter->Driver,
																												camera,
																												adapter,
																												(OV2640_InterfaceT*)&OV2640_Interface,
																												(OV2640_DriverOptionsT*)&OV2640_Options);
		
		end:;
		return camera->Status.AdapterInitResult;
	}
	
	return xResultLinkError;
}
//==============================================================================
