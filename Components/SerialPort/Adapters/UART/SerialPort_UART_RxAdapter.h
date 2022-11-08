//==============================================================================
#ifndef SERIAL_PORT_UART_RX_ADAPTER_H
#define SERIAL_PORT_UART_RX_ADAPTER_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "SerialPort_UART_AdapterTypes.h"
#include "SerialPort/SerialPort_Types.h"
//==============================================================================
xResult SerialPortUART_RxAdapterInit(SerialPortT* serial_port, SerialPortUART_AdapterT* adapter);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* SERIAL_PORT_UART_RX_ADAPTER_H */

