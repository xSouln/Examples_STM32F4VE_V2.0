/*
 * FlowDirectorTransactions.c
 *
 *  Created on: 28.09.2021
 *      Author: rekuts
 */
//==============================================================================
#include <string.h>
#include "Communications/FlowDirector_Transactions.h"
#include "Communications/FlowDirector_Requests.h"
#include "Adapters/FlowDirector_Adapter.h"
#include "Controls/FlowDirector_Control.h"
//==============================================================================
#define DATA_BUFFER_SIZE 1024

#define PACKET_EVENT_IDENTIFICATOR FLOW_DIRECTOR_EVENT_IDENTIFICATOR
#define PACKET_RESPONSE_IDENTIFICATOR FLOW_DIRECTOR_RESPONSE_IDENTIFICATOR
#define PACKET_DEVICE_KEY FLOW_DIRECTOR_PACKET_DEVICE_KEY
#define PACKET_END FLOW_DIRECTOR_PACKET_END
//==============================================================================
extern const xTransactionT FlowDirectorTransactions[];
extern xDataBufferT MainDataBuffer;

#define TRANSACTIONS FlowDirectorTransactions
#define DATA_BUFFER MainDataBuffer
//==============================================================================
int FlowDirector_TransmitEvent(xTxT* tx, FLOW_DIRECTOR_TRANSACTIONS transaction, xObject data, uint16_t data_size)
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
void FlowDirector_RequestTransaction(xRxT* rx, xRequestT* request, uint8_t* object, uint16_t size)
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
//------------------------------------------------------------------------------
const xTransactionT FlowDirectorTransactions[] =
{
	//----------------------------------------------------------------------------
	//GET
	
	//----------------------------------------------------------------------------
	//SET
	
	//----------------------------------------------------------------------------
	//TRY
	
	//----------------------------------------------------------------------------
	// end of transactions marker
  { .Id = -1 }
};
//==============================================================================
