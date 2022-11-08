//==============================================================================
#ifndef _CAMERA_TRANSACTIONS_H
#define _CAMERA_TRANSACTIONS_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Common/xRxTransaction.h"
#include "Common/xTx.h"
//==============================================================================
typedef enum
{
  CAMERA_GET_FIRMWARE_VERSION = 100,
	CAMERA_GET_SNAPSHOT_RGB565,
	CAMERA_GET_SNAPSHOT_JPEG,
	CAMERA_GET_OPTIONS,
	CAMERA_GET_STATUS,

	CAMERA_SET = 1000,
	CAMERA_SET_OPTIONS,
	CAMERA_SET_OUTPUT_FORMAT,
	CAMERA_SET_RESOLUTION,
	CAMERA_SET_SATURATION,
	CAMERA_SET_CONTRAST,
	CAMERA_SET_BRIGHTNESS,
	CAMERA_SET_LIGHTMODE,
	CAMERA_SET_SPECIALEFFECT,
	CAMERA_SET_QUANTIZATION,
	CAMERA_SET_GAIN,
	CAMERA_SET_CONFIGURATION,

	CAMERA_TRY = 2000,

	CAMERA_EVT = 10000,
	
	CAMERA_EVT_RGB565_TRANSFER_START,
	CAMERA_EVT_RGB565_TRANSFER,
	CAMERA_EVT_RGB565_TRANSFER_END,
	
	CAMERA_EVT_JPEG_TRANSFER_START,
	CAMERA_EVT_JPEG_TRANSFER,
	CAMERA_EVT_JPEG_TRANSFER_END,
	
} CAMERA_TRANSACTIONS;
//==============================================================================
xResult CameraTransmitEvent(xTxT* tx, CAMERA_TRANSACTIONS transaction, xObject data, uint16_t data_size);

extern const xRxRequestT CameraRequests[];
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* _CAMERA_TRANSACTIONS_H */

