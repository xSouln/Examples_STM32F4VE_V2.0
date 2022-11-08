//==============================================================================
#include "CupsController/Controls/CupsController.h"
//==============================================================================
extern const xRxTransactionT CupsControllerTransactions[];

static const PacketHeaderT TransactionRequestHeader =
{
	.Identificator = { .Value = TRANSACTION_REQUEST_IDENTIFICATOR },
	.DeviceKey = CUPS_CONTROLLER_DEVICE_KEY
};
//------------------------------------------------------------------------------
const xRxRequestT CupsControllerRxRequests[] =
{
  {
		.Header = (void*)&TransactionRequestHeader,
		.HeaderLength = sizeof(TransactionRequestHeader),
		.Action = (xRxRequestReceiverT)xRxTransactionRequestReceiver,
		.Content = (void*)&CupsControllerTransactions
	},
  { 0 }
};
//==============================================================================
