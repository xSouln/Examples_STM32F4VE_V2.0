//==============================================================================
#include "BrewGroup_RxRequests.h"
#include "BrewGroup/Controls/BrewGroup_Info.h"
//==============================================================================
extern const xRxTransactionT BrewGroupTransactions[];

static const PacketHeaderT TransactionRequestHeader =
{
	.Identificator = { .Value = TRANSACTION_REQUEST_IDENTIFICATOR },
	.DeviceKey = BREW_GROUP_DEVICE_KEY
};
//----------------------------------------------------------------------------
const xRxRequestT BrewGroupRequests[] =
{
  {
		.Header = (void*)&TransactionRequestHeader,
		.HeaderLength = sizeof(TransactionRequestHeader),
		.Action = (xRxRequestReceiverT)xRxTransactionRequestReceiver,
		.Content = (void*)&BrewGroupTransactions
	},
	
  { 0 }
};
//==============================================================================
