//==============================================================================
#ifndef SERIAL_PORT_H_
#define SERIAL_PORT_H_
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
//#include "SerialPort/Adapters/SerialPort_Adapters.h"
#include "SerialPort/SerialPort_Types.h"
//==============================================================================
void SerialPortHandler(SerialPortT* serial_port);

xResult SerialPortInit(SerialPortT* serial_port, void* parent, SerialPortInterfaceT* interface);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* SERIAL_PORT_H_ */
