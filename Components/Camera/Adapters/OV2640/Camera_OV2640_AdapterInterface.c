//==============================================================================
#include "Camera/Adapters/OV2640/Camera_OV2640_Adapter.h"
#include "Camera/Camera_Types.h"
#include "Common/xMemory.h"
#include <string.h>
//==============================================================================
static const OV2640_DriverOptionsT OV2640_Options =
{
	.Quantization = OV2640_Quantization_Default,
	.Resolution = OV2640_Resolution_1280x960
};
//==============================================================================
static void Handler(CameraT* camera)
{
	CameraOV2640AdapterT* adapter = camera->Adapter.Child;
	
	camera->Status.IsCapture = (adapter->HandleDCMI->Instance->CR & DCMI_CR_CAPTURE);
	
	if (!camera->Status.IsCapture)
	{
		if (camera->Status.Snapshot == CameraSnapshotCapture)
		{
			DMA_Stream_TypeDef* DMA = adapter->HandleDCMI->DMA_Handle->Instance;
			
			camera->Status.Snapshot = CameraSnapshotComplite;
			camera->SnapshotSize = camera->SnapshotBufferSize - (DMA->NDTR * sizeof(camera->SnapshotBuffer[0]));
			
			camera->Interface->EventListener(camera,
																				CameraEventSnapshotComplite,
																				(uint32_t)camera->SnapshotBuffer,
																				camera->SnapshotSize);
			
			camera->Status.Snapshot = CameraSnapshotIdle;
		}
	}
}
//------------------------------------------------------------------------------
static xResult Snapshot(CameraT* camera)
{
	CameraOV2640AdapterT* adapter = camera->Adapter.Child;
	
	if (camera->Status.IsCapture)
	{
		return xResultBusy;
	}
	
	HAL_DCMI_Suspend(adapter->HandleDCMI);
	HAL_DCMI_Stop(adapter->HandleDCMI);
	memset(camera->SnapshotBuffer, 0, camera->SnapshotBufferSize);
	
	xResult result = HAL_DCMI_Start_DMA(adapter->HandleDCMI,
																			DCMI_MODE_SNAPSHOT,
																			(uint32_t)camera->SnapshotBuffer,
																			camera->SnapshotBufferSize / sizeof(camera->SnapshotBuffer[0]))
																			== HAL_OK ? xResultAccept : xResultError;
	
	if (result == xResultAccept)
	{
		camera->Status.Snapshot = CameraSnapshotCapture;
		goto end;
	}
	
	camera->Status.Snapshot = CameraSnapshotError;
	
	end:;
	return result;
}
//------------------------------------------------------------------------------
static void EventListener(CameraT* camera, CameraAdapterEventSelector selector, uint32_t args, uint32_t count)
{
	CameraOV2640AdapterT* adapter = camera->Adapter.Child;
	
	switch ((uint8_t)selector)
	{
		case CameraAdapterEventIRQ :
			
			break;
		
		default : return;
	}
}
//------------------------------------------------------------------------------
static xResult RequestListener(CameraT* camera, CameraAdapterRequestSelector selector, uint32_t args, uint32_t count)
{
	CameraOV2640AdapterT* adapter = camera->Adapter.Child;
	
	switch ((uint8_t)selector)
	{
		case  CameraAdapterRequestGetSnapshot :
			return Snapshot(camera);
		
		case CameraAdapterRequestSetConfiguration :
			return OV2640_DriverSetConfiguration(&adapter->Driver, (uint8_t*)args, count);
		
		case CameraAdapterRequestSetOptions :
			return OV2640_DriverSetOptions(&adapter->Driver, (OV2640_DriverOptionsT*)args);
		
		default : return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
static int GetValue(CameraT* camera, CameraAdapterValueSelector selector)
{
	CameraOV2640AdapterT* adapter = camera->Adapter.Child;
	
	switch ((uint8_t)selector)
	{
		case CameraAdapterValueBrightnes :
			return adapter->Driver.Options.Brightness;
		
		case CameraAdapterValueContrast :
			return adapter->Driver.Options.Contrast;
		
		case CameraAdapterValueGain :
			return adapter->Driver.Options.Gain;
		
		case CameraAdapterValueLightMode :
			return adapter->Driver.Options.LightMode;
		
		case CameraAdapterValueOutputFormat :
			return adapter->Driver.Options.OutputFormat;
		
		case CameraAdapterValueQuantization :
			return adapter->Driver.Options.Quantization;
		
		case CameraAdapterValueResolution :
			return adapter->Driver.Options.Resolution;
		
		case CameraAdapterValueSaturation :
			return adapter->Driver.Options.Saturation;
		
		case CameraAdapterValueSpecialEffect :
			return adapter->Driver.Options.SpecialEffect;
		
		default : return 0;
	}
}
//------------------------------------------------------------------------------
static xResult SetValue(CameraT* camera, CameraAdapterValueSelector selector, uint32_t value)
{
	CameraOV2640AdapterT* adapter = camera->Adapter.Child;
	
	switch ((uint8_t)selector)
	{
		case CameraAdapterValueBrightnes :
			return OV2640_DriverSetBrightness(&adapter->Driver, value);
		
		case CameraAdapterValueContrast :
			return OV2640_DriverSetContrast(&adapter->Driver, value);
		
		case CameraAdapterValueGain :
			return OV2640_DriverSetGain(&adapter->Driver, value);
		
		case CameraAdapterValueLightMode :
			return OV2640_DriverSetLightMode(&adapter->Driver, value);
		
		case CameraAdapterValueOutputFormat :
			return OV2640_DriverSetOutputFormat(&adapter->Driver, value);
		
		case CameraAdapterValueQuantization :
			return OV2640_DriverSetQuantization(&adapter->Driver, value);
		
		case CameraAdapterValueResolution :
			return OV2640_DriverSetResolution(&adapter->Driver, value);
		
		case CameraAdapterValueSaturation :
			return OV2640_DriverSetSaturation(&adapter->Driver, value);
		
		case CameraAdapterValueSpecialEffect :
			return OV2640_DriverSetSpecialEffect(&adapter->Driver, value);
		
		default : return xResultNotSupported;
	}
	
	return xResultAccept;
}
//==============================================================================
static CameraAdapterInterfaceT Interface =
{
	.Handler = (CameraAdapterHandlerT)Handler,
	.EventListener = (CameraAdapterEventListenerT)EventListener,
	.RequestListener = (CameraAdapterRequestListenerT)RequestListener,
	.GetValue = (CameraAdapterActionGetValueT)GetValue,
	.SetValue = (CameraAdapterActionSetValueT)SetValue,
};
//==============================================================================
xResult OV2640_AdapterInterfaceInit(CameraAdapterBaseT* adapter)
{
	if (adapter)
	{
		adapter->Interface = &Interface;
		
		return xResultAccept;
	}
	
	return xResultLinkError;
}
//==============================================================================
