//==============================================================================
#include "Camera/Controls/Camera.h"
#include "Common/xMemory.h"
//==============================================================================
void CameraHandler(CameraT* camera)
{
	camera->Adapter.Interface->Handler(camera);
	
	xTxTransferHandler(&camera->TransferLayer);
}
//------------------------------------------------------------------------------
xResult CameraGetSnapshot(CameraT* camera)
{
	return camera->Adapter.Interface->RequestListener(camera, CameraAdapterRequestGetSnapshot, 0, 0);
}
//==============================================================================
xResult CameraSetConfiguration(CameraT* camera, uint8_t* data, uint16_t data_size)
{
	return camera->Adapter.Interface->RequestListener(camera, CameraAdapterRequestSetConfiguration, (uint32_t)data, data_size);
}
//------------------------------------------------------------------------------
xResult CameraSetOptions(CameraT* camera, CameraOptionsT* options)
{
	xResult result = camera->Adapter.Interface->RequestListener(camera, CameraAdapterRequestSetOptions, (uint32_t)options, 0);
	
	if (result == xResultAccept)
	{
		xMemoryCopy(&camera->Options, options, sizeof(camera->Options));
	}
	return result;
}
//==============================================================================
xResult CameraSetContrast(CameraT* camera, CameraContrastT value)
{
	xResult result = camera->Adapter.Interface->SetValue(camera, CameraAdapterValueContrast, value);
	
	if (result == xResultAccept)
	{
		camera->Options.Contrast = value;
	}
	
	return result;
}
//------------------------------------------------------------------------------
xResult CameraSetBrightness(CameraT* camera, CameraBrightnessT value)
{
	xResult result = camera->Adapter.Interface->SetValue(camera, CameraAdapterValueBrightnes, value);
	
	if (result == xResultAccept)
	{
		camera->Options.Brightness = value;
	}
	
	return result;
}
//------------------------------------------------------------------------------
xResult CameraSetGain(CameraT* camera, CameraGainT value)
{
	xResult result = camera->Adapter.Interface->SetValue(camera, CameraAdapterValueGain, value);
	
	if (result == xResultAccept)
	{
		camera->Options.Gain = value;
	}
	
	return result;
}
//------------------------------------------------------------------------------
xResult CameraSetLightMode(CameraT* camera, CameraLightModeT value)
{
	xResult result = camera->Adapter.Interface->SetValue(camera, CameraAdapterValueLightMode, value);
	
	if (result == xResultAccept)
	{
		camera->Options.LightMode = value;
	}
	
	return result;
}
//------------------------------------------------------------------------------
xResult CameraSetOutputFormat(CameraT* camera, CameraOutputFormatT value)
{
	xResult result = camera->Adapter.Interface->SetValue(camera, CameraAdapterValueOutputFormat, value);
	
	if (result == xResultAccept)
	{
		camera->Options.OutputFormat = value;
	}
	
	return result;
}
//------------------------------------------------------------------------------
xResult CameraSetQuantization(CameraT* camera, CameraQuantizationT value)
{
	xResult result = camera->Adapter.Interface->SetValue(camera, CameraAdapterValueQuantization, value);
	
	if (result == xResultAccept)
	{
		camera->Options.Quantization = value;
	}
	
	return result;
}
//------------------------------------------------------------------------------
xResult CameraSetResolution(CameraT* camera, CameraResolutionT value)
{
	xResult result = camera->Adapter.Interface->SetValue(camera, CameraAdapterValueResolution, value);
	
	if (result == xResultAccept)
	{
		camera->Options.Resolution = value;
	}
	
	return result;
}
//------------------------------------------------------------------------------
xResult CameraSetSaturation(CameraT* camera, CameraSaturationT value)
{
	xResult result = camera->Adapter.Interface->SetValue(camera, CameraAdapterValueSaturation, value);
	
	if (result == xResultAccept)
	{
		camera->Options.Saturation = value;
	}
	
	return result;
}
//------------------------------------------------------------------------------
xResult CameraSetSpecialEffect(CameraT* camera, CameraSpecialEffectT value)
{
	xResult result = camera->Adapter.Interface->SetValue(camera, CameraAdapterValueSpecialEffect, value);
	
	if (result == xResultAccept)
	{
		camera->Options.SpecialEffect = value;
	}
	
	return result;
}
//==============================================================================
xResult CameraInit(CameraT* camera, void* parent, CameraInterfaceT* interface)
{
	if (camera && interface)
	{
		camera->Description = "CameraT";
		camera->Parent = parent;
		camera->Interface = interface;
		
		camera->Status.InitResult = xResultAccept;
		
		return xResultAccept;
	}
	
	return xResultLinkError;
}
//==============================================================================
