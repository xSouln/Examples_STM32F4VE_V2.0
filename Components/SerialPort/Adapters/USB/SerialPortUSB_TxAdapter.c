//==============================================================================
#include "SerialPortUSB_TxAdapter.h"
//==============================================================================
static void EventListener(xTxT *tx, xTxEventSelector event, uint32_t args, uint32_t count)
{
	SerialPortUSB_AdapterT* adapter = tx->Adapter;
	
	switch ((uint32_t)event)
	{		
		default : break;
	}
}
//------------------------------------------------------------------------------
static xResult RequestListener(xTxT* tx, xTxRequestSelector selector, uint32_t args, uint32_t count)
{
	SerialPortUSB_AdapterT* adapter = tx->Adapter;
	
	switch ((uint32_t)selector)
	{
		case xTxRequestTransmitData :
			xCircleBufferAdd(&adapter->TxCircleBuffer, (uint8_t*)args, count);
			break;
		
		case xTxRequestEnableTransmitter: break;
		
		case xTxRequestStartTransmission :
			/*
			adapter->TxCircleBuffer.TotalIndex = 0;
			adapter->TxCircleBuffer.HandlerIndex = 0;
		*/
			break;
		
		case xTxRequestStopTransmission :
			/*
			CDC_Transmit_FS(adapter->TxCircleBuffer.Buffer, adapter->TxCircleBuffer.TotalIndex);
			adapter->TxCircleBuffer.TotalIndex = 0;
			adapter->TxCircleBuffer.HandlerIndex = 0;
		*/
			break;
			
		default : return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
static int GetValue(xTxT* tx, xTxValueSelector selector)
{
	SerialPortUSB_AdapterT* adapter = tx->Adapter;
	
	switch ((uint32_t)selector)
	{
		case xTxValueTransmitterStatus :
			return adapter->Handle->TxState == 0 ? xTxStatusFree : xTxStatusIsTransmits;
		
		default : return -1;
	}
}
//------------------------------------------------------------------------------
static xResult SetValue(xTxT* tx, xTxValueSelector selector, uint32_t value)
{
	SerialPortUSB_AdapterT* adapter = tx->Adapter;
	
	switch ((uint32_t)selector)
	{
		default : return xResultValueIsNotFound;
	}
	
	return xResultValueIsNotFound;
}
//------------------------------------------------------------------------------
static void Handler(xTxT *tx)
{
	SerialPortUSB_AdapterT* adapter = tx->Adapter;
	
	if (adapter->TxCircleBuffer.HandlerIndex != adapter->TxCircleBuffer.TotalIndex
		&& !adapter->Status.IsTransmit
		&& adapter->Handle)
	{
		uint16_t buffer_size = adapter->TxCircleBuffer.SizeMask + 1;
		uint16_t data_size = (adapter->TxCircleBuffer.TotalIndex - adapter->TxCircleBuffer.HandlerIndex)
								& adapter->TxCircleBuffer.SizeMask;
		
		uint16_t packet_size = data_size + adapter->TxCircleBuffer.HandlerIndex;
		
		if (packet_size > buffer_size)
		{
			data_size = buffer_size - adapter->TxCircleBuffer.HandlerIndex;
		}
		
		adapter->Status.IsTransmit = true;
		
		HAL_PCD_EP_Transmit(adapter->hUsbDeviceFS->pData,
												CDC_IN_EP,
												adapter->TxCircleBuffer.Buffer + adapter->TxCircleBuffer.HandlerIndex,
												data_size);
		
		adapter->TxCircleBuffer.HandlerIndex += data_size;
		adapter->TxCircleBuffer.HandlerIndex &= adapter->TxCircleBuffer.SizeMask;
	}
}
//------------------------------------------------------------------------------
static xTxInterfaceT interface =
{
	.Handler = (xTxActionHandler)Handler,
	.EventListener = (xTxEventListener)EventListener,
	.RequestListener = (xTxRequestListener)RequestListener,
	.GetValue = (xTxActionGetValue)GetValue,
	.SetValue = (xTxActionSetValue)SetValue
};
//==============================================================================
int SerialPortUSB_TxAdapterInit(SerialPortT* serial_port, SerialPortUSB_AdapterT* adapter)
{
	if (serial_port && adapter)
	{
		return xTxInit(&serial_port->Tx, serial_port, adapter, &interface);
	}
	
	return SerialPortAdapterResultError;
}
//==============================================================================
