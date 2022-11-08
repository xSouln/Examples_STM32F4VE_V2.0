//==============================================================================
#include "Carousel_RxRequests.h"
#include "Carousel/Carousel_Info.h"
//==============================================================================
extern const xRxTransactionT CarouselTransactions[];

static const PacketHeaderT TransactionRequestHeader =
{
	.Identificator = { .Value = TRANSACTION_REQUEST_IDENTIFICATOR },
	.DeviceKey = CAROUSEL_DEVICE_KEY
};
//----------------------------------------------------------------------------
const xRxRequestT CarouselRequests[] =
{
  {
		.Header = (void*)&TransactionRequestHeader,
		.HeaderLength = sizeof(TransactionRequestHeader),
		.Action = (xRxRequestReceiverT)xRxTransactionRequestReceiver,
		.Content = (void*)&CarouselTransactions
	},
	
  { 0 }
};
//==============================================================================
