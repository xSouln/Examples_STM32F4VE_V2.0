//==============================================================================
#include "TCPServer_Components.h"
//==============================================================================
#define RX_BUF_SIZE 0x100
#define RX_RECEIVER_BUF_SIZE 0x200
//------------------------------------------------------------------------------
static uint8_t rx_buf[RX_BUF_SIZE];
static uint8_t rx_receiver_buf[RX_RECEIVER_BUF_SIZE];
//------------------------------------------------------------------------------
extern void RequestListener(xRxT* rx, uint8_t* data, uint32_t size);
//------------------------------------------------------------------------------
TCPServerT TCPServerWIZspi;

static TCPServerWIZspi_AdapterT Adapter;
//==============================================================================
void HardwareResetOn()
{
}
//------------------------------------------------------------------------------
void HardwareResetOff()
{
}
//------------------------------------------------------------------------------
uint8_t ReceiveByte()
{
	return 0;
}
//------------------------------------------------------------------------------
void TransmiteByte()
{
	
}
//------------------------------------------------------------------------------
static void EventListener(TCPServerT* server, TCPServerEventSelector selector, uint32_t args, uint32_t count)
{
	switch ((uint8_t)selector)
	{
		case TCPServerEventEndLine :
			//xRxDeclareRequest(&serial_port->Rx, xRxRequestClearBuffer, 0, 0);
			RequestListener(&server->Rx, (uint8_t*)args, count);
			break;
		
		case TCPServerEventReceiverBufferIsFull :
			//xRxDeclareRequest(&serial_port->Rx, xRxRequestClearBuffer, 0, 0);
			RequestListener(&server->Rx, (uint8_t*)args, count);
			break;
	}
}
//==============================================================================
static TCPServerInterfaceT Interface =
{
	.EventListener = (TCPServerEventListener)EventListener
};
//==============================================================================
int TCPServerWIZspi_ComponentInit(void* parent)
{
	extern xDataBufferT MainResponseBuffer;
	Adapter.ResponseBuffer = &MainResponseBuffer;
	
	Adapter.Server = &TCPServerWIZspi;
	
	Adapter.BusInterface.HardwareResetOn = HardwareResetOn;
	Adapter.BusInterface.HardwareResetOff = HardwareResetOff;
	Adapter.BusInterface.ReceiveByte = ReceiveByte;
	Adapter.BusInterface.TransmiteByte = TransmiteByte;
	
	Adapter.RxBuffer = rx_buf;
	Adapter.RxBufferSize = sizeof(rx_buf);
	
	xRxReceiverInit(&Adapter.RxReceiver,
									&TCPServerWIZspi.Rx,
									0,
									rx_receiver_buf,
									sizeof(rx_receiver_buf));
	
	TCPServer_Init(&TCPServerWIZspi, parent, &Interface);
	TCPServerWIZspi_AdapterInit(&TCPServerWIZspi, &Adapter);
	
  return 0;
}
//==============================================================================
