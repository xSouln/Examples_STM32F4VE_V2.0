//==============================================================================
#include <string.h>
#include "Communications/OV2640_TransferLayer.h"
#include "Communications/OV2640_Transactions.h"
//==============================================================================
#define PACKET_EVENT_IDENTIFICATOR OV2640_EVENT_IDENTIFICATOR
#define PACKET_DEVICE_KEY OV2640_PACKET_DEVICE_KEY
#define PACKET_END OV2640_PACKET_END
//==============================================================================
//------------------------------------------------------------------------------
static xResult JPEG_StartTransfer(xTransferLayerT* layer)
{
	PacketInfoT packet_info;
	uint32_t free_size = xTxGetFreeSize(layer->Control->Handle);
	if (free_size > (20))
	{
		packet_info.ActionKey = OV2640_EVT_JPEG_TRANSFER_START;
		
		xTxTransmitData(layer->Control->Handle, &PACKET_EVENT_IDENTIFICATOR, sizeof(PACKET_EVENT_IDENTIFICATOR));
		xTxTransmitData(layer->Control->Handle, &PACKET_DEVICE_KEY, sizeof(PACKET_DEVICE_KEY));
		xTxTransmitData(layer->Control->Handle, &packet_info, sizeof(packet_info));
		xTxTransmitData(layer->Control->Handle, PACKET_END, SIZE_STRING(PACKET_END));
		
		return xResultAccept;
	}
	return xResultError;
}
//------------------------------------------------------------------------------
static xResult JPEG_Transfer(xTransferLayerT* layer, uint8_t* data, uint32_t data_size)
{
	PacketInfoT packet_info;
	uint32_t free_size = xTxGetFreeSize(layer->Control->Handle);
	if (free_size > (data_size + 20))
	{
		packet_info.ActionKey = OV2640_EVT_JPEG_TRANSFER;
		packet_info.ContentSize = data_size;
		
		while (xTxTransmitData(layer->Control->Handle, &PACKET_EVENT_IDENTIFICATOR, sizeof(PACKET_EVENT_IDENTIFICATOR)) != xResultAccept) {}
		while (xTxTransmitData(layer->Control->Handle, &PACKET_DEVICE_KEY, sizeof(PACKET_DEVICE_KEY)) != xResultAccept) {}
		while (xTxTransmitData(layer->Control->Handle, &packet_info, sizeof(packet_info)) != xResultAccept) {}
		while (xTxTransmitData(layer->Control->Handle, data, data_size) != xResultAccept) {}
		while (xTxTransmitData(layer->Control->Handle, PACKET_END, SIZE_STRING(PACKET_END)) != xResultAccept) {}
		
		return xResultAccept;
	}
	return xResultError;
}
//------------------------------------------------------------------------------
static xResult JPEG_EndTransfer(xTransferLayerT* layer)
{
	PacketInfoT packet_info;
	uint32_t free_size = xTxGetFreeSize(layer->Control->Handle);
	if (free_size > (20))
	{
		packet_info.ActionKey = OV2640_EVT_JPEG_TRANSFER_END;
		
		xTxTransmitData(layer->Control->Handle, &PACKET_EVENT_IDENTIFICATOR, sizeof(PACKET_EVENT_IDENTIFICATOR));
		xTxTransmitData(layer->Control->Handle, &PACKET_DEVICE_KEY, sizeof(PACKET_DEVICE_KEY));
		xTxTransmitData(layer->Control->Handle, &packet_info, sizeof(packet_info));
		xTxTransmitData(layer->Control->Handle, PACKET_END, SIZE_STRING(PACKET_END));
		
		return xResultAccept;
	}
	return xResultError;
}
//==============================================================================
//------------------------------------------------------------------------------
static xResult RGB565_StartTransfer(xTransferLayerT* layer)
{
	PacketInfoT packet_info;
	if (xTxGetFreeSize(layer->Control->Handle) > (20))
	{
		packet_info.ActionKey = OV2640_EVT_RGB565_TRANSFER_START;
		
		xTxTransmitData(layer->Control->Handle, &PACKET_EVENT_IDENTIFICATOR, sizeof(PACKET_EVENT_IDENTIFICATOR));
		xTxTransmitData(layer->Control->Handle, &PACKET_DEVICE_KEY, sizeof(PACKET_DEVICE_KEY));
		xTxTransmitData(layer->Control->Handle, &packet_info, sizeof(packet_info));
		xTxTransmitData(layer->Control->Handle, PACKET_END, SIZE_STRING(PACKET_END));
		
		return xResultAccept;
	}
	return xResultError;
}
//------------------------------------------------------------------------------
static xResult RGB565_Transfer(xTransferLayerT* layer, uint8_t* data, uint32_t data_size)
{
	PacketInfoT packet_info;
	if (xTxGetFreeSize(layer->Control->Handle) > (data_size + 20))
	{
		packet_info.ActionKey = OV2640_EVT_RGB565_TRANSFER;
		packet_info.ContentSize = data_size;
		
		xTxTransmitData(layer->Control->Handle, &PACKET_EVENT_IDENTIFICATOR, sizeof(PACKET_EVENT_IDENTIFICATOR));
		xTxTransmitData(layer->Control->Handle, &PACKET_DEVICE_KEY, sizeof(PACKET_DEVICE_KEY));
		xTxTransmitData(layer->Control->Handle, &packet_info, sizeof(packet_info));
		xTxTransmitData(layer->Control->Handle, data, data_size);
		xTxTransmitData(layer->Control->Handle, PACKET_END, SIZE_STRING(PACKET_END));
		
		return xResultAccept;
	}
	return xResultError;
}
//------------------------------------------------------------------------------
static xResult RGB565_EndTransfer(xTransferLayerT* layer)
{
	PacketInfoT packet_info;
	if (xTxGetFreeSize(layer->Control->Handle) > (20))
	{
		packet_info.ActionKey = OV2640_EVT_RGB565_TRANSFER_END;
		
		xTxTransmitData(layer->Control->Handle, &PACKET_EVENT_IDENTIFICATOR, sizeof(PACKET_EVENT_IDENTIFICATOR));
		xTxTransmitData(layer->Control->Handle, &PACKET_DEVICE_KEY, sizeof(PACKET_DEVICE_KEY));
		xTxTransmitData(layer->Control->Handle, &packet_info, sizeof(packet_info));
		xTxTransmitData(layer->Control->Handle, PACKET_END, SIZE_STRING(PACKET_END));
		
		return xResultAccept;
	}
	return xResultError;
}
//==============================================================================
//------------------------------------------------------------------------------
xTransferLayerControlT OV2640_RGB565_TransferLayerControl =
{
	.StartTransfer = (xTransferLayerActionStartTransfer)RGB565_StartTransfer,
	.Transfer = (xTransferLayerActionTransfer)RGB565_Transfer,
	.EndTransfer = (xTransferLayerActionEndTransfer)RGB565_EndTransfer,
};
//------------------------------------------------------------------------------
xTransferLayerControlT OV2640_JPEG_TransferLayerControl =
{
	.StartTransfer = (xTransferLayerActionStartTransfer)JPEG_StartTransfer,
	.Transfer = (xTransferLayerActionTransfer)JPEG_Transfer,
	.EndTransfer = (xTransferLayerActionEndTransfer)JPEG_EndTransfer,
};
//==============================================================================
