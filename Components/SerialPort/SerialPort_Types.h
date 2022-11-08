//==============================================================================
#ifndef SERIAL_PORT_TYPES_H
#define SERIAL_PORT_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Components_Config.h"
#include "Common/xTx.h"
#include "Common/xRx.h"
#include "SerialPort_Config.h"
#include "SerialPort_Info.h"
//==============================================================================
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
typedef union
{
	struct
	{
		xResult InitResult : 4;
		xResult AdapterInitResult : 4;
		xResult RxInitResult : 4;
		xResult TxInitResult : 4;
		
		
	};
	uint32_t Value;
	  
} SerialPortStatusT;
//------------------------------------------------------------------------------
typedef struct
{
	OBJECT_HEADER;
	
	void* Adapter;
	
	SerialPortInterfaceT* Interface;
	
	SerialPortStatusT Status;

	xRxT Rx;
	xTxT Tx;
	  
} SerialPortT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* SERIAL_PORT_TYPES_H */
