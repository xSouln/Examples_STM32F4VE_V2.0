//==============================================================================
#ifndef SERIAL_PORT_UART_ADAPTER_TYPES_H
#define SERIAL_PORT_UART_ADAPTER_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "SerialPort/Adapters/SerialPort_AdaptersTypes.h"
#include "SerialPortUART_AdapterInfo.h"
#include "SerialPortUART_AdapterConfig.h"
//==============================================================================
typedef struct
{
	volatile REG_UART_T* Usart;
	volatile DMA_Stream_TypeDef* RxDMA;
	uint8_t RxDMA_Channel;
	
	xDataBufferT* ResponseBuffer;
	
	xCircleBufferT RxCircleBuffer;
	xRxReceiverT RxReceiver;
	
	xCircleBufferT TxCircleBuffer;
	  
} SerialPortUART_AdapterT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* SERIAL_PORT_UART_ADAPTER_TYPES_H */