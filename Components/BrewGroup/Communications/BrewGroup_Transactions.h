//==============================================================================
#ifndef BREW_GROUP_TRANSACTIONS_H
#define BREW_GROUP_TRANSACTIONS_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Common/xTransaction.h"
#include "Common/xTx.h"
#include "Controls/BrewGroup_Control.h"
//==============================================================================
typedef enum
{
  BREW_GROUP_GET_FIRMWARE_VERSION = 100,

	BREW_GROUP_SET = 1000,

	BREW_GROUP_TRY = 2000,

	BREW_GROUP_EVT = 10000,
	
} BREW_GROUP_TRANSACTIONS;
//==============================================================================
static uint32_t BREW_GROUP_PACKET_DEVICE_KEY = BREW_GROUP_DEVICE_KEY;
//------------------------------------------------------------------------------
static PacketIdentificatorT BREW_GROUP_RESPONSE_IDENTIFICATOR = 
{
	.Value = (uint32_t)(PACKET_HEADER_IDENTIFICATOR | (PACKET_HEADER_DESCRIPTION_RESPONSE << 8))
};
//------------------------------------------------------------------------------
static PacketIdentificatorT BREW_GROUP_EVENT_IDENTIFICATOR = 
{
	.Value = (uint32_t)(PACKET_HEADER_IDENTIFICATOR | (PACKET_HEADER_DESCRIPTION_EVENT << 8))
};
//------------------------------------------------------------------------------
static PacketHeaderT BREW_GROUP_REQUEST_HEADER =
{
	.Identificator =
	{
		.Value = (uint32_t)(PACKET_HEADER_IDENTIFICATOR | (PACKET_HEADER_DESCRIPTION_REQUEST << 8))
	},
	.DeviceKey = BREW_GROUP_DEVICE_KEY,
};
//------------------------------------------------------------------------------
static char BREW_GROUP_PACKET_END[] = "\r";
//==============================================================================
int BrewGroup_TransmitEvent(xTxT* tx, BREW_GROUP_TRANSACTIONS transaction, xObject data, uint16_t data_size);
void BrewGroup_RequestTransaction(xRxT* rx, xRequestT* request, uint8_t* object, uint16_t size);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* BREW_GROUP_TRANSACTIONS_H */

