//==============================================================================
#include "Slider_RxRequests.h"
#include "Slider/Slider_Types.h"
//==============================================================================
extern const xRxTransactionT SliderTransactions[];

static const PacketHeaderT TransactionRequestHeader =
{
	.Identificator = { .Value = TRANSACTION_REQUEST_IDENTIFICATOR },
	.DeviceKey = SLIDER_DEVICE_KEY
};
//----------------------------------------------------------------------------
const xRxRequestT SliderRequests[] =
{
  {
		.Header = (void*)&TransactionRequestHeader,
		.HeaderLength = sizeof(TransactionRequestHeader),
		.Action = (xRxRequestReceiverT)xRxTransactionRequestReceiver,
		.Content = (void*)&SliderTransactions
	},
	
  { 0 }
};
//==============================================================================
