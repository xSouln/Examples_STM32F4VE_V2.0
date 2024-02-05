//==============================================================================
//header:

#ifndef _CLIENT_DEVICE_ADAPTER_H_
#define _CLIENT_DEVICE_ADAPTER_H_
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif 
//==============================================================================
//includes:

#include "Abstractions/xDevice/xDevice.h"
#include "Abstractions/xPort/xPort.h"
#include "Abstractions/xTransferLayer/xTransferLayer-Types.h"
#include "Common/xCircleBuffer.h"
#include "Services/Common/ServiceCommon.h"
//==============================================================================
//types:

typedef struct
{
	uint32_t OperationTimeStamp;
	uint16_t OperationTimeOut;
	uint16_t Operation;

	uint16_t RxPacketHandlerIndex;
	xCircleBufferT* PortRxCircleBuffer;

} ClientDeviceAdapterContentT;
//------------------------------------------------------------------------------
typedef struct
{
	uint32_t Id;
	xListT Subscribers;

} ServiceSubscriptionT;
//------------------------------------------------------------------------------
xListTypeDefination(ServiceSubscriptions, ServiceSubscriptionT*);
//xListTypeDefination(LogicElementListeners, xDeviceLogicElementListenerT*);
//------------------------------------------------------------------------------
typedef struct
{
	ClientDeviceAdapterContentT Content;

	ServiceSubscriptionsListT Subscriptions;

	xListT LogicElementListeners;

	xPortT* Port;
	xTransferLayerT* TransferLayer;

} ClientDeviceAdapterT;
//------------------------------------------------------------------------------
typedef struct
{
	xPortT* Port;
	xTransferLayerT* TransferLayer;

} ClientDeviceAdapterInitT;
//==============================================================================
//functions:

xResult ClientDeviceAdapterInit(xDeviceT* device, ClientDeviceAdapterT* adapter, ClientDeviceAdapterInitT* init);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif //_CLIENT_DEVICE_ADAPTER_H_
