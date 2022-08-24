//==============================================================================
#include "Common/xTxTransfer.h"
//==============================================================================
static void Handler(xTxTransferT* layer)
{
	xTxT* adapter = layer->Adapter;
	//adapter->Status.Transmitter = xTxGetValue(adapter, xTxValueTransmitterStatus);
	uint32_t free_size = xTxGetValue(adapter, xTxValueFreeBufferSize);
	uint32_t packet_size;
	
	if (adapter->Status.Transmitter != xTxStatusFree)
	{
		return;
	}
	
	switch ((uint8_t)layer->Status.Transfer)
	{
		case xTxTransferStatusBeginning:
			if (xTxTransmitString(adapter, "xTxTransferStatusBeginning\r") != xResultAccept)
			{
				return;
			}
			layer->Status.Transfer = xTxTransferStatusTransmits;
			
		case xTxTransferStatusTransmits:
			packet_size = layer->DataSize - layer->DataTransferred;
		
			if (packet_size > free_size)
			{
				packet_size = free_size;
			}
		
			if (packet_size > layer->MaxPacketSize)
			{
				packet_size = layer->MaxPacketSize;
			}
			
			if (packet_size)
			{
				if (xTxTransmitData(adapter, layer->Data + layer->DataTransferred, packet_size) == xResultAccept)
				{
					layer->DataTransferred += packet_size;
				}
				return;
			}
			else
			{
				layer->Status.Transfer = xTxTransferStatusEnding;
			}
			
		case xTxTransferStatusEnding:
			if (xTxTransmitString(adapter, "xTxTransferStatusEnding\r") != xResultAccept)
			{
				return;
			}
			layer->Status.Transfer = xTxTransferStatusComplite;
			break;
			
		default: return;
	}
}
//------------------------------------------------------------------------------
static xResult RequestListener(xTxTransferT* layer, xTxTransferRequestSelector selector, uint32_t args, uint32_t count)
{
	switch ((uint8_t)selector)
	{
		default : return xResultNotSupported;
	}
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
static int GetValue(xTxTransferT* layer, xTxTransferValueSelector selector)
{
	switch ((uint8_t)selector)
	{
		default : return 0;
	}
}
//==============================================================================
static const xTxTransferInterfaceT Interface = 
{
	.Handler = (xTxTransferHandlerT)Handler,
	.RequestListener = (xTxTransferRequestListenerT)RequestListener,
	.GetValue = (xTxTransferActionGetValueT)GetValue
};
//==============================================================================
xResult TransactionAdapterInit(xTxTransferT* layer, xTxT* adapter)
{
	if (layer && adapter)
	{
		layer->Adapter = adapter;
		layer->Interface = (xTxTransferInterfaceT*)&Interface;
		
		return xResultAccept;
	}
	return xResultError;
}
//==============================================================================
