/*
 *
 */
//==============================================================================
#include "Camera_Transactions.h"
#include "Camera_Requests.h"
#include "Common/xTx.h"
#include "Common/xRx.h"
#include "Camera/Controls/Camera.h"
#include "Common/xRxTransaction.h"
//==============================================================================
void CameraTransactionGetSnapshotRGB565(xRxRequestManagerT* manager)
{
	
}
//------------------------------------------------------------------------------
void CameraTransactionGetSnapshotJPEG(xRxRequestManagerT* manager)
{
	static const xRxTransactionTransferAdapterT TransferAdapter =
	{
		.DeviceId = CAMERA_DEVICE_KEY,
		.EventTransferStart = CAMERA_EVT_JPEG_TRANSFER_START,
		.EventTransfer = CAMERA_EVT_JPEG_TRANSFER,
		.EventTransferEnd = CAMERA_EVT_JPEG_TRANSFER_END
	};
	
	CameraT* camera = manager->Device;
	
	if (camera->Options.OutputFormat != CameraOutputFormat_JPEG)
	{
		CameraSetOutputFormat(camera, CameraOutputFormat_JPEG);
	}
	
	if (CameraGetSnapshot(camera) == xResultAccept)
	{
		xRxTransactionTransferAdapterInit(&camera->TransferLayer, (xRxTransactionTransferAdapterT*)&TransferAdapter);
		xTxTransferSetTxLine(&camera->TransferLayer, manager->RxLine->Tx);
	}
}
//==============================================================================
void CameraTransactionGetOptions(xRxRequestManagerT* manager)
{
	CameraT* camera = manager->Device;
	
	xRxPutInResponseBuffer(manager->RxLine, &camera->Options, sizeof(camera->Options));
}
//------------------------------------------------------------------------------
void CameraTransactionSetOptions(xRxRequestManagerT* manager, CameraOptionsT* options)
{
	CameraT* camera = manager->Device;
	int16_t result = CameraSetOptions(camera, options);
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
	xRxPutInResponseBuffer(manager->RxLine, &camera->Options, sizeof(camera->Options));
}
//==============================================================================
void CameraTransactionSetOutputFormat(xRxRequestManagerT* manager, CameraOutputFormatT* output_format)
{
	CameraT* camera = manager->Device;
	int16_t result = CameraSetOutputFormat(camera, *output_format);
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
	xRxPutInResponseBuffer(manager->RxLine, &camera->Options.OutputFormat, sizeof(camera->Options.OutputFormat));
}
//------------------------------------------------------------------------------
void CameraTransactionSetResolution(xRxRequestManagerT* manager, CameraResolutionT* resolution)
{
	CameraT* camera = manager->Device;
	int16_t result = CameraSetResolution(camera, *resolution);
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
	xRxPutInResponseBuffer(manager->RxLine, &camera->Options.Resolution, sizeof(camera->Options.Resolution));
}
//------------------------------------------------------------------------------
void CameraTransactionSetSaturation(xRxRequestManagerT* manager, CameraSaturationT* saturation)
{
	CameraT* camera = manager->Device;
	int16_t result = CameraSetSaturation(camera, *saturation);
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
	xRxPutInResponseBuffer(manager->RxLine, &camera->Options.Saturation, sizeof(camera->Options.Saturation));
}
//------------------------------------------------------------------------------
void CameraTransactionSetContrast(xRxRequestManagerT* manager, CameraContrastT* contrast)
{
	CameraT* camera = manager->Device;
	int16_t result = CameraSetContrast(camera, *contrast);
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
	xRxPutInResponseBuffer(manager->RxLine, &camera->Options.Contrast, sizeof(camera->Options.Contrast));
}
//------------------------------------------------------------------------------
void CameraTransactionSetBrightness(xRxRequestManagerT* manager, CameraBrightnessT* brightness)
{
	CameraT* camera = manager->Device;
	int16_t result = CameraSetBrightness(camera, *brightness);
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
	xRxPutInResponseBuffer(manager->RxLine, &camera->Options.Brightness, sizeof(camera->Options.Brightness));
}
//------------------------------------------------------------------------------
void CameraTransactionSetLightMode(xRxRequestManagerT* manager, CameraLightModeT* light_mode)
{
	CameraT* camera = manager->Device;
	int16_t result = CameraSetLightMode(camera, *light_mode);
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
	xRxPutInResponseBuffer(manager->RxLine, &camera->Options.LightMode, sizeof(camera->Options.LightMode));
}
//------------------------------------------------------------------------------
void CameraTransactionSetSpecialEffect(xRxRequestManagerT* manager, CameraSpecialEffectT* special_effect)
{
	CameraT* camera = manager->Device;
	int16_t result = CameraSetSpecialEffect(camera, *special_effect);
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
	xRxPutInResponseBuffer(manager->RxLine, &camera->Options.SpecialEffect, sizeof(camera->Options.SpecialEffect));
}
//------------------------------------------------------------------------------
void CameraTransactionSetQuantization(xRxRequestManagerT* manager, CameraQuantizationT* quantization)
{
	CameraT* camera = manager->Device;
	int16_t result = CameraSetQuantization(camera, *quantization);
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
	xRxPutInResponseBuffer(manager->RxLine, &camera->Options.Quantization, sizeof(camera->Options.Quantization));
}
//------------------------------------------------------------------------------
void CameraTransactionSetGain(xRxRequestManagerT* manager, uint8_t* gain)
{
	CameraT* camera = manager->Device;
	int16_t result = CameraSetGain(camera, *gain);
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
	xRxPutInResponseBuffer(manager->RxLine, &camera->Options.Gain, sizeof(camera->Options.Gain));
}
//------------------------------------------------------------------------------
void CameraTransactionSetConfiguration(xRxRequestManagerT* manager, uint8_t* data, uint16_t data_size)
{
	CameraT* camera = manager->Device;
	int16_t result = CameraSetConfiguration(camera, data, data_size);
	
	xRxPutInResponseBuffer(manager->RxLine, &result, sizeof(result));
}
//------------------------------------------------------------------------------
void CameraTransactionGetStatus(xRxRequestManagerT* manager)
{
	CameraT* camera = manager->Device;
	
	xRxPutInResponseBuffer(manager->RxLine, &camera->Status, sizeof(camera->Status));
}
//==============================================================================
const xRxTransactionT CameraTransactions[] =
{
	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------
	//GET
  {
		.Id = CAMERA_GET_FIRMWARE_VERSION,
	},
	
	{
		.Id = CAMERA_GET_SNAPSHOT_RGB565,
		.Action = (xRxTransactionAction)CameraTransactionGetSnapshotRGB565,
	},
	
	{
		.Id = CAMERA_GET_SNAPSHOT_JPEG,
		.Action = (xRxTransactionAction)CameraTransactionGetSnapshotJPEG,
	},
	
	{
		.Id = CAMERA_GET_OPTIONS,
		.Action = (xRxTransactionAction)CameraTransactionGetOptions,
	},
	
	{
		.Id = CAMERA_GET_STATUS,
		.Action = (xRxTransactionAction)CameraTransactionGetStatus,
	},
	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------
	//SET
	{
		.Id = CAMERA_SET_BRIGHTNESS,
		.Action = (xRxTransactionAction)CameraTransactionSetBrightness,
	},
	
	{
		.Id = CAMERA_SET_CONTRAST,
		.Action = (xRxTransactionAction)CameraTransactionSetContrast,
	},
	
	{
		.Id = CAMERA_SET_LIGHTMODE,
		.Action = (xRxTransactionAction)CameraTransactionSetLightMode,
	},
	
	{
		.Id = CAMERA_SET_OPTIONS,
		.Action = (xRxTransactionAction)CameraTransactionSetOptions,
	},
	
	{
		.Id = CAMERA_SET_OUTPUT_FORMAT,
		.Action = (xRxTransactionAction)CameraTransactionSetOutputFormat,
	},
	
	{
		.Id = CAMERA_SET_QUANTIZATION,
		.Action = (xRxTransactionAction)CameraTransactionSetQuantization,
	},
	
	{
		.Id = CAMERA_SET_RESOLUTION,
		.Action = (xRxTransactionAction)CameraTransactionSetResolution,
	},
	
	{
		.Id = CAMERA_SET_SATURATION,
		.Action = (xRxTransactionAction)CameraTransactionSetSaturation,
	},
	
	{
		.Id = CAMERA_SET_SPECIALEFFECT,
		.Action = (xRxTransactionAction)CameraTransactionSetSpecialEffect,
	},
	
	{
		.Id = CAMERA_SET_GAIN,
		.Action = (xRxTransactionAction)CameraTransactionSetGain,
	},
	
	{
		.Id = CAMERA_SET_CONFIGURATION,
		.Action = (xRxTransactionAction)CameraTransactionSetConfiguration,
	},
	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------
	//TRY
	
	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------
	// end of transactions marker
  { .Id = -1 }
};
//==============================================================================
