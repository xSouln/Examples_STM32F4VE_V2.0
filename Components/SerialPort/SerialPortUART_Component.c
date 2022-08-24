//==============================================================================
#include "SerialPort_Component.h"
//==============================================================================
#define RX_CIRCLE_BUF_SIZE_MASK 0x1ff
#define RX_OBJECT_BUF_SIZE 0x200
#define TX_CIRCLE_BUF_SIZE_MASK 0x3ff
//------------------------------------------------------------------------------
static uint8_t rx_circle_buf[RX_CIRCLE_BUF_SIZE_MASK + 1];
static uint8_t rx_object_buf[RX_OBJECT_BUF_SIZE];
static uint8_t tx_circle_buf[TX_CIRCLE_BUF_SIZE_MASK + 1];
//------------------------------------------------------------------------------
extern void RequestListener(xRxT* rx, uint8_t* data, uint32_t size);

SerialPortT SerialPortUART;
//==============================================================================
static SerialPortUART_AdapterT Adapter =
{
	.Usart = (volatile REG_UART_T*)USART1,
		
	.RxDMA = DMA2_Stream2,
	.RxDMA_Channel = 4
};
//==============================================================================
static void EventListener(SerialPortT* serial_port, SerialPortEventSelector selector, uint32_t args, uint32_t count)
{
	SerialPortUART_AdapterT* adapter = serial_port->Adapter;

	switch ((uint8_t)selector)
	{
		case SerialPortEventEndLine :
			//xRxDeclareRequest(&serial_port->Rx, xRxRequestClearBuffer, 0, 0);
			RequestListener(&serial_port->Rx, (uint8_t*)args, count);
			break;
		
		case SerialPortEventReceiverBufferIsFull :
			//xRxDeclareRequest(&serial_port->Rx, xRxRequestClearBuffer, 0, 0);
			RequestListener(&serial_port->Rx, (uint8_t*)args, count);
			break;
	}
}
//==============================================================================
static SerialPortInterfaceT Interface =
{
	.EventListener = (SerialPortEventListener)EventListener
};
//==============================================================================
int SerialPortUART_ComponentInit(void* parent)
{
	extern xDataBufferT MainResponseBuffer;
	Adapter.ResponseBuffer = &MainResponseBuffer;
	
	xCircleBufferInit(&Adapter.RxCircleBuffer,
										&SerialPortUART.Rx,
										rx_circle_buf,
										RX_CIRCLE_BUF_SIZE_MASK);
	
	xCircleBufferInit(&Adapter.TxCircleBuffer,
										&SerialPortUART.Tx,
										tx_circle_buf,
										TX_CIRCLE_BUF_SIZE_MASK);
	
	xRxReceiverInit(&Adapter.RxReceiver,
									&SerialPortUART.Rx,
									0,
									rx_object_buf,
									RX_OBJECT_BUF_SIZE);
	
	SerialPort_Init(&SerialPortUART, parent, &Interface);
	SerialPortUART_AdapterInit(&SerialPortUART, &Adapter);
  
  return 0;
}
//==============================================================================
