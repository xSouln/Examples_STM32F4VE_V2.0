//==============================================================================
#ifndef __OV2640_TRANSACTIONS_H
#define __OV2640_TRANSACTIONS_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Common/xTransaction.h"
#include "Common/xTx.h"
//==============================================================================
typedef enum
{
  OV2640_GET_FIRMWARE_VERSION = 100,
	OV2640_GET_SNAPSHOT_RGB565,
	OV2640_GET_SNAPSHOT_JPEG,
	OV2640_GET_OPTIONS,
	OV2640_GET_STATUS,

	OV2640_SET = 1000,
	OV2640_SET_OPTIONS,
	OV2640_SET_OUTPUT_FORMAT,
	OV2640_SET_RESOLUTION,
	OV2640_SET_SATURATION,
	OV2640_SET_CONTRAST,
	OV2640_SET_BRIGHTNESS,
	OV2640_SET_LIGHTMODE,
	OV2640_SET_SPECIALEFFECT,
	OV2640_SET_QUANTIZATION,
	OV2640_SET_AGC_GAIN,
	OV2640_SET_CONFIGURATION,

	OV2640_TRY = 2000,

	OV2640_EVT = 10000,
	
	OV2640_EVT_RGB565_TRANSFER_START,
	OV2640_EVT_RGB565_TRANSFER,
	OV2640_EVT_RGB565_TRANSFER_END,
	
	OV2640_EVT_JPEG_TRANSFER_START,
	OV2640_EVT_JPEG_TRANSFER,
	OV2640_EVT_JPEG_TRANSFER_END,
	
} OV2640_TRANSACTIONS;
//==============================================================================
#define OV2640_DEVICE_KEY 0x63171134

static uint32_t OV2640_PACKET_DEVICE_KEY = OV2640_DEVICE_KEY;
//------------------------------------------------------------------------------
static PacketIdentificatorT OV2640_RESPONSE_IDENTIFICATOR = 
{
	.Value = (uint32_t)(PACKET_HEADER_IDENTIFICATOR | (PACKET_HEADER_DESCRIPTION_RESPONSE << 8))
};
//------------------------------------------------------------------------------
static PacketIdentificatorT OV2640_EVENT_IDENTIFICATOR = 
{
	.Value = (uint32_t)(PACKET_HEADER_IDENTIFICATOR | (PACKET_HEADER_DESCRIPTION_EVENT << 8))
};
//------------------------------------------------------------------------------
static PacketHeaderT OV2640_REQUEST_HEADER =
{
	.Identificator =
	{
		.Value = (uint32_t)(PACKET_HEADER_IDENTIFICATOR | (PACKET_HEADER_DESCRIPTION_REQUEST << 8))
	},
	.DeviceKey = OV2640_DEVICE_KEY,
};
//------------------------------------------------------------------------------
static char OV2640_PACKET_END[] = "\r";
//==============================================================================
int OV2640_TransmitEvent(xTxT* tx, OV2640_TRANSACTIONS transaction, xObject data, uint16_t data_size);
void OV2640_RequestTransaction(xRxT* rx, xRequestT* request, uint8_t* object, uint16_t size);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* __OV2640_TRANSACTIONS_H */

