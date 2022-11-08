//==============================================================================
#ifndef SERIAL_PORT_UART_COMPONENT_H
#define SERIAL_PORT_UART_COMPONENT_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "SerialPort/Controls/SerialPort.h"
#include "SerialPort/Adapters/UART/SerialPort_UART_Adapter.h"
//==============================================================================
extern SerialPortT SerialPortUART;

xResult SerialPortUARTComponentInit(void* parent);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif