//==============================================================================
#include "Common/xMemory.h"
#include "SerialPort.h"
//==============================================================================
void SerialPort_Handler(SerialPortT* serial_port)
{
	xRxHandler(&serial_port->Rx);
  xTxHandler(&serial_port->Tx);
}
//------------------------------------------------------------------------------
SerialPortResult SerialPort_Init(SerialPortT* serial_port, void* parent, SerialPortInterfaceT* interface)
{
	if (serial_port && interface)
	{
		serial_port->Description = "SerialPortT";
		serial_port->Parent = parent;
		
		serial_port->Interface = interface;
	}
	return SerialPortResultError;
}
//==============================================================================
