//==============================================================================
#ifndef CAROUSEL_TRANSACTIONS_H
#define CAROUSEL_TRANSACTIONS_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Common/xTransaction.h"
#include "Common/xTx.h"
#include "Controls/Carousel_Control.h"
//==============================================================================
typedef enum
{
  CAROUSEL_GET_FIRMWARE_VERSION = 100,

	CAROUSEL_SET = 1000,

	CAROUSEL_TRY = 2000,

	CAROUSEL_EVT = 10000,
	
} CAROUSEL_TRANSACTIONS;
//==============================================================================
static uint32_t CAROUSEL_PACKET_DEVICE_KEY = CAROUSEL_DEVICE_KEY;
//------------------------------------------------------------------------------
static PacketIdentificatorT CAROUSEL_RESPONSE_IDENTIFICATOR = 
{
	.Value = (uint32_t)(PACKET_HEADER_IDENTIFICATOR | (PACKET_HEADER_DESCRIPTION_RESPONSE << 8))
};
//------------------------------------------------------------------------------
static PacketIdentificatorT CAROUSEL_EVENT_IDENTIFICATOR = 
{
	.Value = (uint32_t)(PACKET_HEADER_IDENTIFICATOR | (PACKET_HEADER_DESCRIPTION_EVENT << 8))
};
//------------------------------------------------------------------------------
static PacketHeaderT CAROUSEL_REQUEST_HEADER =
{
	.Identificator =
	{
		.Value = (uint32_t)(PACKET_HEADER_IDENTIFICATOR | (PACKET_HEADER_DESCRIPTION_REQUEST << 8))
	},
	.DeviceKey = CAROUSEL_DEVICE_KEY,
};
//------------------------------------------------------------------------------
static char CAROUSEL_PACKET_END[] = "\r";
//==============================================================================
int Carousel_TransmitEvent(xTxT* tx, CAROUSEL_TRANSACTIONS transaction, xObject data, uint16_t data_size);
void Carousel_RequestTransaction(xRxT* rx, xRequestT* request, uint8_t* object, uint16_t size);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* CAROUSEL_TRANSACTIONS_H */

