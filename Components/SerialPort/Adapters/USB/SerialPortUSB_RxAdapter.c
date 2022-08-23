//==============================================================================
#include "SerialPortUSB_RxAdapter.h"
//#include "SerialPort/Controls/SerialPort_Types.h"
//==============================================================================
static void Handler(xRxT* rx)
{
	SerialPortUSB_AdapterT* adapter = rx->Adapter;
	
	xRxReceiverRead(&adapter->RxReceiver, &adapter->RxCircleBuffer);
}
//------------------------------------------------------------------------------
static void EventListener(xRxT* rx, xRxEventSelector event, uint32_t args, uint32_t count)
{
	switch ((uint32_t)event)
	{
		default : break;
	}
}
//------------------------------------------------------------------------------
static xResult RequestListener(xRxT* rx, xRxRequestSelector selector, uint32_t args, uint32_t count)
{
	SerialPortUSB_AdapterT* adapter = rx->Adapter;
	
	switch ((uint32_t)selector)
	{
		case xRxRequestClearBuffer :
			adapter->RxReceiver.BytesReceived = 0;
			break;
		
		case xRxRequestPutInResponseBuffer :
			xDataBufferAdd(adapter->ResponseBuffer, (void*)args, count);
			break;
		
		case xRxRequestClearResponseBuffer :
			xDataBufferClear(adapter->ResponseBuffer);
			break;
		
		default : return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
static int GetValue(xRxT* rx, xRxValueSelector selector)
{
	SerialPortUSB_AdapterT* adapter = rx->Adapter;
	
	switch ((uint32_t)selector)
	{
		case xRxValueResponseData :
			return (int)adapter->ResponseBuffer->Data;
		
		case xRxValueResponseDataSize :
			return (int)adapter->ResponseBuffer->DataSize;
		
		default : return 0;
	}
}
//------------------------------------------------------------------------------
static xResult SetValue(xRxT* rx, xRxValueSelector selector, uint32_t value)
{
	switch ((uint32_t)selector)
	{
		default : return xResultValueIsNotFound;
	}
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
static void RxReceiverEventListener(xRxReceiverT* receiver, xRxReceiverEventSelector event, uint32_t args, uint32_t count)
{
	SerialPortT* serial_port = receiver->Parent->Parent;
	
	switch ((uint8_t)event)
	{
		case xRxReceiverEventEndLine:
			serial_port->Interface->EventListener(serial_port, SerialPortEventEndLine, args, count);
			break;
		
		case xRxReceiverEventBufferIsFull:
			serial_port->Interface->EventListener(serial_port, SerialPortEventReceiverBufferIsFull, args, count);
			break;
	}
}
//==============================================================================
static xRxInterfaceT rx_interface =
{
	.Handler = (xRxActionHandler)Handler,
	.EventListener = (xRxEventListener)EventListener,
	.RequestListener = (xRxRequestListener)RequestListener,
	.GetValue = (xRxActionGetValue)GetValue,
	.SetValue = (xRxActionSetValue)SetValue
};
//------------------------------------------------------------------------------
static xRxReceiverInterfaceT rx_receiver_interface =
{
	.EventListener = (xRxReceiverEventListener)RxReceiverEventListener
};
//==============================================================================
int SerialPortUSB_RxAdapterInit(SerialPortT* serial_port, SerialPortUSB_AdapterT* adapter)
{
	if (serial_port && adapter)
	{
		adapter->RxReceiver.Interface = &rx_receiver_interface;
		
		xRxInit(&serial_port->Rx, serial_port, adapter, &rx_interface);
		
		return SerialPortAdapterResultAccept;
	}
	
	return SerialPortAdapterResultError;
}
//==============================================================================
