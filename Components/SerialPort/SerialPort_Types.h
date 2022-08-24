//==============================================================================
#ifndef SERIAL_PORT_TYPES_H
#define SERIAL_PORT_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "main.h"
#include "Common/xTx.h"
#include "Common/xRx.h"
#include "SerialPort_Config.h"
#include "SerialPort_Info.h"
//==============================================================================
typedef enum
{
	SerialPortResultAccept,
	SerialPortResultError
	
} SerialPortResult;
//------------------------------------------------------------------------------
typedef enum
{
	SerialPortEventEndLine,
	SerialPortEventReceiverBufferIsFull,
	
} SerialPortEventSelector;
//==============================================================================
typedef void (*SerialPortEventListener)(void* rx, SerialPortEventSelector event, uint32_t args, uint32_t count);
//------------------------------------------------------------------------------
typedef struct
{
	SerialPortEventListener EventListener;
	  
} SerialPortAdapterInterfaceT;
//------------------------------------------------------------------------------
typedef struct
{
	SerialPortEventListener EventListener;
	  
} SerialPortInterfaceT;
//------------------------------------------------------------------------------
typedef struct
{
	OBJECT_HEADER;
	
	void* Adapter;
	
	SerialPortAdapterInterfaceT* AdapterInterface;
	SerialPortInterfaceT* Interface;

	xRxT Rx;
	xTxT Tx;
	  
} SerialPortT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* SERIAL_PORT_TYPES_H */
