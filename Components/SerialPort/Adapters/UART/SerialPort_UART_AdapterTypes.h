//==============================================================================
#ifndef SERIAL_PORT_UART_ADAPTER_TYPES_H
#define SERIAL_PORT_UART_ADAPTER_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Components_Config.h"
#include "Common/xRxReceiver.h"
#include "SerialPort_UART_AdapterInfo.h"
#include "SerialPort_UART_AdapterConfig.h"
//==============================================================================
typedef struct
{
	REG_UART_T* Usart;
	
	DMA_HandleTypeDef* RxDMA;
	
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
