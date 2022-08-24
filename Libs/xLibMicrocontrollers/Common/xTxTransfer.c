//==============================================================================
#include "xTxTransfer.h"
//==============================================================================
void xTxTransferHandler(xTxTransferT* layer)
{
	if (layer && layer->Interface && layer->Interface->Handler)
	{
		layer->Interface->Handler(layer);
	}
}
//==============================================================================
xResult xTxTransferTransmit(xTxTransferT* layer,
														void* data,
														uint32_t data_size)
{
	if (!layer)
	{
		return xResultError;
	}
	
	if (!data || !data_size)
	{
		return xResultError;
	}
	
	if (layer->Status.Transfer == xTxTransferStatusFree || layer->Status.Transfer == xTxTransferStatusComplite)
	{
		layer->Data = (uint8_t*)data;
		layer->DataSize = data_size;
		layer->DataTransferred = 0;
		
		layer->Status.Transfer = xTxTransferStatusBeginning;
		
		return xResultAccept;
	}
	
	return xResultError;
}
//==============================================================================
void xTransferAbort(xTxTransferT* layer)
{
	
}
//==============================================================================
xResult xTxTransferInit(xTxTransferT* layer,
												uint32_t min_packet_size,
												uint32_t max_packet_size,
												float buffer_filling)
{
	if (layer && min_packet_size && buffer_filling)
	{
		layer->Description = "xTxTransferT";
		
		layer->MinPacketSize = min_packet_size;
		layer->MaxPacketSize = max_packet_size;
		layer->BufferFilling = buffer_filling;
		
		return xResultAccept;
	}
	return xResultError;
}
//==============================================================================
