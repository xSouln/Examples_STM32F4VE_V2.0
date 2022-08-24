//==============================================================================
#include "Camera/Adapters/OV2640/OV2640_Adapter.h"
#include "Camera/Camera_Types.h"
//==============================================================================
void OV2640_Handler(OV2640_DriverT* driver)
{
	
}
//------------------------------------------------------------------------------
OV2640_Result OV2640_RequestListener(OV2640_DriverT* driver, OV2640_RequestSelector selector, uint32_t args, uint32_t count)
{
	OV2640_AdapterT* adapter = driver->Adapter;
	
	switch ((uint8_t)selector)
	{
		case OV2640_RequestI2C_Write :
			return HAL_I2C_Mem_Write(adapter->HandleI2C,
												((OV2640_RequestI2C_WriteT*)args)->Address,
												((OV2640_RequestI2C_WriteT*)args)->Register,
												I2C_MEMADD_SIZE_8BIT,
												&((OV2640_RequestI2C_WriteT*)args)->Value,
												1,
												100) > 0;
			
		case OV2640_RequestI2C_Read :
			return HAL_I2C_Mem_Read(adapter->HandleI2C,
												((OV2640_RequestI2C_ReadT*)args)->Address,
												((OV2640_RequestI2C_ReadT*)args)->Register,
												I2C_MEMADD_SIZE_8BIT,
												((OV2640_RequestI2C_ReadT*)args)->Value,
												1,
												100) > 0;
			
		case OV2640_RequestDelay :
			HAL_Delay(args);
			break;
		
		default : return OV2640_ResultNotSupported;
	}
	
	return OV2640_ResultAccept;
}
//------------------------------------------------------------------------------
int OV2640_ActionGetValue(OV2640_DriverT* driver, OV2640_ValueSelector selector)
{
	OV2640_AdapterT* adapter = driver->Adapter;
	
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
OV2640_Result OV2640_ActionSetValue(OV2640_DriverT* driver, OV2640_ValueSelector selector, uint32_t value)
{
	OV2640_AdapterT* adapter = driver->Adapter;
	
	switch ((uint8_t)selector)
	{
		case OV2640_ValueHardwareResetState :
			if (value == OV2640_StateEnable) { adapter->HardwareResetPort->ODR &= ~adapter->HardwareResetPin; }
			else { adapter->HardwareResetPort->ODR |= adapter->HardwareResetPin;  }
			break;
			
		case OV2640_ValuePowerDownState :
			if (value == OV2640_StateEnable) { adapter->PowerDownPort->ODR |= adapter->PowerDownPin; }
			else { adapter->PowerDownPort->ODR &= ~adapter->PowerDownPin;  }
			break;
		
		default : return OV2640_ResultNotSupported;
	}
	
	return OV2640_ResultAccept;
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
void CameraHandler(CameraT* camera)
{
	
}
//------------------------------------------------------------------------------
xResult CameraRequestListener(CameraT* camera, CameraAdapterRequestSelector selector, uint32_t args, uint32_t count)
{
	switch ((uint8_t)selector)
	{
		default : return xResultNotSupported;
	}
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
int CameraActionGetValue(CameraT* camera, CameraAdapterValueSelector selector)
{
	switch ((uint8_t)selector)
	{
		default : return 0;
	}
}
//------------------------------------------------------------------------------
xResult CameraActionSetValue(CameraT* camera, CameraAdapterValueSelector selector, uint32_t value)
{
	switch ((uint8_t)selector)
	{
		default : return xResultNotSupported;
	}
	
	return xResultAccept;
}
//==============================================================================
xResult OV2640_AdapterInit(CameraT* camera, OV2640_AdapterT* adapter)
{
	if (camera && adapter)
	{
		adapter->Description = "OV2640_AdapterT";
		adapter->Parent = camera;
		
		camera->Adapter = adapter;
		camera->Driver = &adapter->Driver;
		adapter->Camera = camera;
		
		camera->AdapterInterface.Handler = (CameraAdapterHandlerT)CameraHandler;
		camera->AdapterInterface.RequestListener = (CameraAdapterRequestListenerT)CameraRequestListener;
		camera->AdapterInterface.GetValue = (CameraAdapterActionGetValueT)CameraActionGetValue;
		camera->AdapterInterface.SetValue = (CameraAdapterActionSetValueT)CameraActionSetValue;
		
		OV2640_DriverInit(camera->Driver,
											adapter,
											adapter,
											(OV2640_InterfaceT*)&OV2640_Interface,
											(OV2640_DriverOptionsT*)&OV2640_Options);
		
		return xResultAccept;
	}
	
	return xResultError;
}
//==============================================================================
