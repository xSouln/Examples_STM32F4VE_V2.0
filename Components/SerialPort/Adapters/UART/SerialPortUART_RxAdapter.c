//==============================================================================
#include "SerialPortUART_RxAdapter.h"
//==============================================================================
static void Handler(xRxT* rx)
{
	SerialPortUART_AdapterT* adapter = rx->Adapter;
	
	adapter->RxCircleBuffer.TotalIndex = (adapter->RxCircleBuffer.SizeMask + 1) - adapter->RxDMA->NDTR;
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
	SerialPortUART_AdapterT* adapter = rx->Adapter;
	
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
	SerialPortUART_AdapterT* adapter = rx->Adapter;
	
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
		default : return xResultRequestIsNotFound;
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
int SerialPortUART_RxAdapterInit(SerialPortT* serial_port, SerialPortUART_AdapterT* adapter)
{
	if (serial_port && adapter)
	{
		adapter->RxReceiver.Interface = &rx_receiver_interface;
		
		xRxInit(&serial_port->Rx, serial_port, adapter, &rx_interface);
		
		adapter->Usart->Control1.ReceiverEnable = true;
		adapter->Usart->Control3.DMA_EnableReceiver = true;
		
		if (adapter->RxDMA)
		{
			adapter->RxDMA->CR &= DMA_SxCR_EN;
			
			adapter->RxDMA->CR |= adapter->RxDMA_Channel << DMA_SxCR_CHSEL_Pos;
			adapter->RxDMA->CR &= ~DMA_SxCR_DBM;
			
			adapter->RxDMA->CR |= DMA_SxCR_CIRC;
			adapter->RxDMA->CR |= DMA_SxCR_MINC;
			adapter->RxDMA->CR |= DMA_SxCR_PL_0;
			
			adapter->RxDMA->NDTR = adapter->RxCircleBuffer.SizeMask + 1;
			adapter->RxDMA->PAR = (uint32_t)&adapter->Usart->Data;
			adapter->RxDMA->M0AR = (uint32_t)adapter->RxCircleBuffer.Buffer;
			
			adapter->RxDMA->CR |= DMA_SxCR_EN;
		}
		
		return SerialPortAdapterResultAccept;
	}
	
	return SerialPortAdapterResultError;
}
//==============================================================================
