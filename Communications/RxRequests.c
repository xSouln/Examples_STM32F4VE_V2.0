/*
 *
 */
//==============================================================================
#include <string.h>
#include "RxRequests.h"
#include "RxTransactions.h"
#include "Control.h"
//==============================================================================
void RequestGetFirmware(xRxT* rx, xRxRequestT* request, uint8_t* object, uint16_t size)
{
	const char response[] = "firmware: qwerty\r";
	
	if (rx->Tx)
	{
		xTxTransmitData(rx->Tx, (void*)response, SIZE_STRING(response));
	}
}
//==============================================================================
void RequestListener(xRxT* rx, uint8_t* data, uint32_t size)
{
	//if the received data is a transaction:
	//Packet header: [#][Description][:][DeviceKey];
	//Packet info: [RequestId][ActionKey][ContentSize]
	//Packet content: [uint8_t Content[info.ContentSize]]
	//Packet end packet marker: [\r]; - not included in "uint16_t size"
	
	//casting data to package structure
	PacketT* request = (PacketT*)data;
	
	//whether the package is a transaction
  if(size >= sizeof(PacketIdentificatorT)
		&& (request->Header.Identificator.Value & PACKET_HEADER_IDENTIFICATOR_MASK) == PACKET_HEADER_IDENTIFICATOR)
  {
		//size check for minimum transaction length. size - does not include the length of the separator character - '\r'
    if (size < sizeof(PacketT)) { return; }
		
		//content size calculation
    int content_size = (int)size - sizeof(PacketT);
		
		//checking if the package content size matches the actual size, if the size is short
    if(content_size < request->Info.ContentSize) { return; }
		
		//reset size when content exceeds size specified in packet.Info
    if(content_size > request->Info.ContentSize) { return; }
  }
	
	//command identification
	xRxRequestIdentify(rx, &Control.RequestManager, data, size);
	
	xRxDeclareRequest(rx, xRxRequestClearBuffer, 0, 0);
}
//==============================================================================
extern void Device_RequestTransaction(xRxT* rx, xRxRequestT* request, uint8_t* object, uint16_t size);
//------------------------------------------------------------------------------
const xRxRequestT RxRequests[] =
{
  NEW_RX_REQUEST1(DEVICE_REQUEST_HEADER, Device_RequestTransaction),
	NEW_RX_REQUEST0("get fitmware", RequestGetFirmware),
  { 0 }
};
//==============================================================================
