//==============================================================================
#include <string.h>
#include "Communications/OV2640_TransferLayer.h"
#include "Adapters/OV2640_Adapter.h"
#include "dcmi.h"
//==============================================================================
extern OV2640_AdapterT OV2640;
//==============================================================================
void OV2640_RequestGetSnapshotRGB565(xRxT* rx, xDataBufferT* data_buffer)
{
	uint16_t result = RESULT_BUSY;
	
	if (OV2640.Handle.JPEG_Request)
	{
		goto end;
	}
	
	if (OV2640.TransferLayer.Status == xTransferLayerStatusFree
			|| OV2640.TransferLayer.Status == xTransferLayerStatusComplite)
	{
		OV2640.TransferLayer.Control->Handle = rx->Tx;
		memset((uint8_t*)OV2640.SnapshotBuffer, 0, sizeof(OV2640.SnapshotBuffer));
		
		HAL_DCMI_Suspend(&hdcmi);
		HAL_DCMI_Stop(&hdcmi);
		HAL_DCMI_Start_DMA(&hdcmi,
												DCMI_MODE_SNAPSHOT,
												(uint32_t)OV2640.SnapshotBuffer,
												sizeof(OV2640.SnapshotBuffer) / sizeof(OV2640.SnapshotBuffer[0]));
		
		result = RESULT_ACCEPT;
	}
	
	end:;
	xDataBufferAdd(data_buffer, &result, sizeof(result));
}
//------------------------------------------------------------------------------
void OV2640_RequestGetSnapshotJPEG(xRxT* rx, xDataBufferT* data_buffer)
{
	uint16_t result = RESULT_BUSY;
	
	if (DCMI->CR & DCMI_CR_CAPTURE)
	{
		goto end;
	}
	
	if (OV2640.TransferLayer.Status == xTransferLayerStatusFree
			|| OV2640.TransferLayer.Status == xTransferLayerStatusComplite)
	{
		OV2640_JPEG_TransferLayerControl.Handle = rx->Tx;
		memset((uint8_t*)OV2640.SnapshotBuffer, 0, sizeof(OV2640.SnapshotBuffer));
		
		HAL_DCMI_Suspend(&hdcmi);
		HAL_DCMI_Stop(&hdcmi);
		HAL_DCMI_Start_DMA(&hdcmi,
												DCMI_MODE_SNAPSHOT,
												(uint32_t)OV2640.SnapshotBuffer,
												sizeof(OV2640.SnapshotBuffer));
		
		OV2640.Handle.JPEG_Request = true;
		
		result = RESULT_ACCEPT;
	}
	
	end:;
	xDataBufferAdd(data_buffer, &result, sizeof(result));
}
//==============================================================================
void OV2640_RequestGetOptions(xRxT* rx, xDataBufferT* data_buffer)
{
	xDataBufferAdd(data_buffer, &OV2640.Driver.Options, sizeof(OV2640.Driver.Options));
}
//------------------------------------------------------------------------------
void OV2640_RequestSetOptions(xRxT* rx, xDataBufferT* data_buffer, OV2640_DriverOptionsT* options)
{
	int16_t result = OV2640_DriverSetOptions(&OV2640.Driver, options);
	
	xDataBufferAdd(data_buffer, &result, sizeof(result));
	xDataBufferAdd(data_buffer, &OV2640.Driver.Options, sizeof(OV2640.Driver.Options));
}
//==============================================================================
void OV2640_RequestSetOutputFormat(xRxT* rx, xDataBufferT* data_buffer, OV2640_OutputFormats* output_format)
{
	int16_t result = OV2640_DriverSetOutputFormat(&OV2640.Driver, *((uint8_t*)output_format));
	
	xDataBufferAdd(data_buffer, &result, sizeof(result));
	xDataBufferAdd(data_buffer, &OV2640.Driver.Options.OutputFormat, sizeof(OV2640.Driver.Options.OutputFormat));
}
//------------------------------------------------------------------------------
void OV2640_RequestSetResolution(xRxT* rx, xDataBufferT* data_buffer, OV2640_Resolutions* resolution)
{
	int16_t result = OV2640_DriverSetResolution(&OV2640.Driver, *((uint8_t*)resolution));
	
	xDataBufferAdd(data_buffer, &result, sizeof(result));
	xDataBufferAdd(data_buffer, &OV2640.Driver.Options.Resolution, sizeof(OV2640.Driver.Options.Resolution));
}
//------------------------------------------------------------------------------
void OV2640_RequestSetSaturation(xRxT* rx, xDataBufferT* data_buffer, OV2640_Saturations* saturation)
{
	int16_t result = OV2640_DriverSetSaturation(&OV2640.Driver, *((uint8_t*)saturation));
	
	xDataBufferAdd(data_buffer, &result, sizeof(result));
	xDataBufferAdd(data_buffer, &OV2640.Driver.Options.Saturation, sizeof(OV2640.Driver.Options.Saturation));
}
//------------------------------------------------------------------------------
void OV2640_RequestSetContrast(xRxT* rx, xDataBufferT* data_buffer, OV2640_Contrasts* contrast)
{
	int16_t result = OV2640_DriverSetContrast(&OV2640.Driver, *((uint8_t*)contrast));
	
	xDataBufferAdd(data_buffer, &result, sizeof(result));
	xDataBufferAdd(data_buffer, &OV2640.Driver.Options.Contrast, sizeof(OV2640.Driver.Options.Contrast));
}
//------------------------------------------------------------------------------
void OV2640_RequestSetBrightness(xRxT* rx, xDataBufferT* data_buffer, OV2640_Brightnesses* brightness)
{
	int16_t result = OV2640_DriverSetBrightness(&OV2640.Driver, *((uint8_t*)brightness));
	
	xDataBufferAdd(data_buffer, &result, sizeof(result));
	xDataBufferAdd(data_buffer, &OV2640.Driver.Options.Brightness, sizeof(OV2640.Driver.Options.Brightness));
}
//------------------------------------------------------------------------------
void OV2640_RequestSetLightMode(xRxT* rx, xDataBufferT* data_buffer, OV2640_LightModes* light_mode)
{
	int16_t result = OV2640_DriverSetLightMode(&OV2640.Driver, *((uint8_t*)light_mode));
	
	xDataBufferAdd(data_buffer, &result, sizeof(result));
	xDataBufferAdd(data_buffer, &OV2640.Driver.Options.LightMode, sizeof(OV2640.Driver.Options.LightMode));
}
//------------------------------------------------------------------------------
void OV2640_RequestSetSpecialEffect(xRxT* rx, xDataBufferT* data_buffer, OV2640_SpecialEffects* special_effect)
{
	int16_t result = OV2640_DriverSetSpecialEffect(&OV2640.Driver, *((uint8_t*)special_effect));
	
	xDataBufferAdd(data_buffer, &result, sizeof(result));
	xDataBufferAdd(data_buffer, &OV2640.Driver.Options.SpecialEffect, sizeof(OV2640.Driver.Options.SpecialEffect));
}
//------------------------------------------------------------------------------
void OV2640_RequestSetQuantization(xRxT* rx, xDataBufferT* data_buffer, OV2640_Quantizations* quantization)
{
	int16_t result = OV2640_DriverSetQuantization(&OV2640.Driver, *((uint8_t*)quantization));
	
	xDataBufferAdd(data_buffer, &result, sizeof(result));
	xDataBufferAdd(data_buffer, &OV2640.Driver.Options.Quantization, sizeof(OV2640.Driver.Options.Quantization));
}
//------------------------------------------------------------------------------
void OV2640_RequestSetAGC_Gain(xRxT* rx, xDataBufferT* data_buffer, uint8_t* gain)
{
	int16_t result = OV2640_DriverSetAGC_Gain(&OV2640.Driver, *gain);
	
	xDataBufferAdd(data_buffer, &result, sizeof(result));
	xDataBufferAdd(data_buffer, &OV2640.Driver.Options.AGC_Gain, sizeof(OV2640.Driver.Options.AGC_Gain));
}
//------------------------------------------------------------------------------
void OV2640_RequestSetConfiguration(xRxT* rx, xDataBufferT* data_buffer, uint8_t* data, uint16_t data_size)
{
	int16_t result = OV2640_DriverSetConfiguration(&OV2640.Driver, data, data_size);
	
	xDataBufferAdd(data_buffer, &result, sizeof(result));
}
//------------------------------------------------------------------------------
void OV2640_RequestGetStatus(xRxT* rx, xDataBufferT* data_buffer)
{
	xDataBufferAdd(data_buffer, &OV2640.Driver.Status, sizeof(OV2640.Driver.Status));
}
//==============================================================================
