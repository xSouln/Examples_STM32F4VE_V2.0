//==============================================================================
#include "FlowDirector_RxRequests.h"
#include "FlowDirector/FlowDirector_Types.h"
//==============================================================================
extern const xRxTransactionT FlowDirectorTransactions[];

static const PacketHeaderT TransactionRequestHeader =
{
	.Identificator = { .Value = TRANSACTION_REQUEST_IDENTIFICATOR },
	.DeviceKey = FLOW_DIRECTOR_DEVICE_KEY
};
//----------------------------------------------------------------------------
const xRxRequestT FlowDirectorRequests[] =
{
  {
		.Header = (void*)&TransactionRequestHeader,
		.HeaderLength = sizeof(TransactionRequestHeader),
		.Action = (xRxRequestReceiverT)xRxTransactionRequestReceiver,
		.Content = (void*)&FlowDirectorTransactions
	},
	
  { 0 }
};
//==============================================================================
