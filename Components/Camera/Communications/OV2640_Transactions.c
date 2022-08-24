/*
 * OV2640_Transaction.c
 *
 *  Created on: 28.09.2021
 *      Author: rekuts
 */
//==============================================================================
#include <string.h>
#include "Communications/OV2640_Transactions.h"
#include "Common/xTx.h"
#include "Common/xRx.h"
#include "Adapters/OV2640_Adapter.h"
#include "Communications/OV2640_Requests.h"
#include "Controls/OV2640_Control.h"
//==============================================================================
#define PACKET_EVENT_IDENTIFICATOR OV2640_EVENT_IDENTIFICATOR
#define PACKET_RESPONSE_IDENTIFICATOR OV2640_RESPONSE_IDENTIFICATOR
#define PACKET_DEVICE_KEY OV2640_PACKET_DEVICE_KEY
#define PACKET_END OV2640_PACKET_END
//==============================================================================
extern const xTransactionT OV2640_Transactions[];
extern xDataBufferT MainDataBuffer;

#define TRANSACTIONS OV2640_Transactions
#define DATA_BUFFER MainDataBuffer
//==============================================================================
int OV2640_TransmitEvent(xTxT* tx, OV2640_TRANSACTIONS transaction, xObject data, uint16_t data_size)
{
	//event array:
	//Header: [#][Description][:][DeviceKey];
	//Info: [RequestId][ActionKey][ContentSize]
	//Content: [uint8_t Content[ContentSize]]
	//End packet marker: [\r]
	
	//filling in the package information structure
	PacketInfoT packet_info = { .ActionKey = transaction, .ContentSize = data_size };
	
	//start transmission logic implementation selected "tx" line
	xTxStartTransmission(tx);
	
	//Packet header start
	xTxTransmitData(tx, &PACKET_EVENT_IDENTIFICATOR, sizeof(PACKET_EVENT_IDENTIFICATOR));
	xTxTransmitData(tx, &PACKET_DEVICE_KEY, sizeof(PACKET_DEVICE_KEY));
	//Packet header end
	
	//Packet info: command "id" and "content_size"
	xTxTransmitData(tx, &packet_info, sizeof(packet_info));
	xTxTransmitData(tx, data, data_size);
	
	//Packet end
	xTxTransmitData(tx, PACKET_END, SIZE_STRING(PACKET_END));
	
	//transmission logic implementation selected "tx" line
	xTxEndTransmission(tx);
	
	return 0;
}
//------------------------------------------------------------------------------
void OV2640_RequestTransaction(xRxT* rx, xRequestT* request, uint8_t* object, uint16_t size)
{
	//request array:
	//Header: [#][Description][:][DeviceKey]; - the "uint8_t* object" is offset by the length of the header because the function is called when the header "PacketHeaderT" matches
	//Info: [RequestId][ActionKey][ContentSize]
	//Content: [uint8_t Content[ContentSize]]
	//End packet marker: [\r]; - not included in "uint16_t size"
	
	//received packet info
	PacketInfoT* info = (PacketInfoT*)object;
	
	//finde result by ActionKey
  xTransactionT* result = xTransactionIdentify((xTransactionT*)TRANSACTIONS, info->ActionKey);
  
  if(result)
  {
		//receiving the transmitter corresponding to the selected receiver
		xTxT* tx = rx->Tx;
		PacketInfoT packet_info;
    
    object += sizeof(PacketInfoT);
    size -= sizeof(PacketInfoT);
    
    if(result->Action)
    {
			//data buffer definition
			xDataBufferT* data_buffer = &DATA_BUFFER;
			//if (rx->Tx && rx->Tx->Objectbuffer) {}
			//clearing the data buffer
			xDataBufferClear(&DATA_BUFFER);
			
			//function call corresponding to the request ActionKey
      result->Action(rx, &DATA_BUFFER, object, size);
			
			if (tx)
			{
				//filling in the package information structure
				packet_info.RequestId = info->RequestId; //must match the request RequestId
				packet_info.ActionKey = result->Id;
				packet_info.ContentSize = DATA_BUFFER.DataSize;
				
				//response array:
				//Header: [#][Description][:][DeviceKey]
				//Info: [RequestId][ActionKey][ContentSize]
				//Content: [uint8_t Content[ContentSize]]
				//End packet marker: [\r]
				
				//start transmission logic implementation selected "tx" line
				xTxStartTransmission(tx);
				
				//Packet header start
				xTxTransmitData(tx, &PACKET_RESPONSE_IDENTIFICATOR, sizeof(PACKET_RESPONSE_IDENTIFICATOR));
				xTxTransmitData(tx, &PACKET_DEVICE_KEY, sizeof(PACKET_DEVICE_KEY));
				//Packet header end
				
				//Packet info: unique request key: "RequestId", command key: "ActionKey" and "content_size"
				xTxTransmitData(tx, &packet_info, sizeof(packet_info));
				xTxTransmitData(tx, DATA_BUFFER.Data, DATA_BUFFER.DataSize);
				
				//Packet end
				xTxTransmitData(tx, PACKET_END, SIZE_STRING(PACKET_END));
				
				//transmission logic implementation selected "tx" line
				xTxEndTransmission(tx);
			}
    }
  }
}
//==============================================================================
const xTransactionT OV2640_Transactions[] =
{
	//----------------------------------------------------------------------------
	//GET
  {
		.Id = OV2640_GET_FIRMWARE_VERSION,
	},
	
	{
		.Id = OV2640_GET_SNAPSHOT_RGB565,
		.Action = (xTransactionAction)OV2640_RequestGetSnapshotRGB565,
	},
	
	{
		.Id = OV2640_GET_SNAPSHOT_JPEG,
		.Action = (xTransactionAction)OV2640_RequestGetSnapshotJPEG,
	},
	
	{
		.Id = OV2640_GET_OPTIONS,
		.Action = (xTransactionAction)OV2640_RequestGetOptions,
	},
	
	{
		.Id = OV2640_GET_STATUS,
		.Action = (xTransactionAction)OV2640_RequestGetStatus,
	},
	//----------------------------------------------------------------------------
	//SET
	{
		.Id = OV2640_SET_BRIGHTNESS,
		.Action = (xTransactionAction)OV2640_RequestSetBrightness,
	},
	
	{
		.Id = OV2640_SET_CONTRAST,
		.Action = (xTransactionAction)OV2640_RequestSetContrast,
	},
	
	{
		.Id = OV2640_SET_LIGHTMODE,
		.Action = (xTransactionAction)OV2640_RequestSetLightMode,
	},
	
	{
		.Id = OV2640_SET_OPTIONS,
		.Action = (xTransactionAction)OV2640_RequestSetOptions,
	},
	
	{
		.Id = OV2640_SET_OUTPUT_FORMAT,
		.Action = (xTransactionAction)OV2640_RequestSetOutputFormat,
	},
	
	{
		.Id = OV2640_SET_QUANTIZATION,
		.Action = (xTransactionAction)OV2640_RequestSetQuantization,
	},
	
	{
		.Id = OV2640_SET_RESOLUTION,
		.Action = (xTransactionAction)OV2640_RequestSetResolution,
	},
	
	{
		.Id = OV2640_SET_SATURATION,
		.Action = (xTransactionAction)OV2640_RequestSetSaturation,
	},
	
	{
		.Id = OV2640_SET_SPECIALEFFECT,
		.Action = (xTransactionAction)OV2640_RequestSetSpecialEffect,
	},
	
	{
		.Id = OV2640_SET_AGC_GAIN,
		.Action = (xTransactionAction)OV2640_RequestSetAGC_Gain,
	},
	
	{
		.Id = OV2640_SET_CONFIGURATION,
		.Action = (xTransactionAction)OV2640_RequestSetConfiguration,
	},
	//----------------------------------------------------------------------------
	//TRY
	
	//----------------------------------------------------------------------------
	// end of transactions marker
  { .Id = -1 }
};
//==============================================================================
