//==============================================================================
#ifndef FLOW_DIRECTOR_TRANSACTIONS_H
#define FLOW_DIRECTOR_TRANSACTIONS_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Common/xTransaction.h"
#include "Common/xTx.h"
#include "Controls/FlowDirector_Control.h"
//==============================================================================
typedef enum
{
  FLOW_DIRECTOR_GET_FIRMWARE_VERSION = 100,

	FLOW_DIRECTOR_SET = 1000,

	FLOW_DIRECTOR_TRY = 2000,

	FLOW_DIRECTOR_EVT = 10000,
	
} FLOW_DIRECTOR_TRANSACTIONS;
//==============================================================================
static uint32_t FLOW_DIRECTOR_PACKET_DEVICE_KEY = FLOW_DIRECTOR_DEVICE_KEY;
//------------------------------------------------------------------------------
static PacketIdentificatorT FLOW_DIRECTOR_RESPONSE_IDENTIFICATOR = 
{
	.Value = (uint32_t)(PACKET_HEADER_IDENTIFICATOR | (PACKET_HEADER_DESCRIPTION_RESPONSE << 8))
};
//------------------------------------------------------------------------------
static PacketIdentificatorT FLOW_DIRECTOR_EVENT_IDENTIFICATOR = 
{
	.Value = (uint32_t)(PACKET_HEADER_IDENTIFICATOR | (PACKET_HEADER_DESCRIPTION_EVENT << 8))
};
//------------------------------------------------------------------------------
static PacketHeaderT FLOW_DIRECTOR_REQUEST_HEADER =
{
	.Identificator =
	{
		.Value = (uint32_t)(PACKET_HEADER_IDENTIFICATOR | (PACKET_HEADER_DESCRIPTION_REQUEST << 8))
	},
	.DeviceKey = FLOW_DIRECTOR_DEVICE_KEY,
};
//------------------------------------------------------------------------------
static char FLOW_DIRECTOR_PACKET_END[] = "\r";
//==============================================================================
int FlowDirector_TransmitEvent(xTxT* tx, FLOW_DIRECTOR_TRANSACTIONS transaction, xObject data, uint16_t data_size);
void FlowDirector_RequestTransaction(xRxT* rx, xRequestT* request, uint8_t* object, uint16_t size);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* FLOW_DIRECTOR_TRANSACTIONS_H */

