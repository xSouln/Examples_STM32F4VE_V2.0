//==============================================================================
#include "Camera/Controls/Camera.h"
#include "Camera_Requests.h"
//==============================================================================
extern const xRxTransactionT CameraTransactions[];

static const PacketHeaderT TransactionRequestHeader =
{
	.Identificator = { .Value = TRANSACTION_REQUEST_IDENTIFICATOR },
	.DeviceKey = CAMERA_DEVICE_KEY
};
//----------------------------------------------------------------------------
const xRxRequestT CameraRequests[] =
{
  {
		.Header = (void*)&TransactionRequestHeader,
		.HeaderLength = sizeof(TransactionRequestHeader),
		.Action = (xRxRequestReceiverT)xRxTransactionRequestReceiver,
		.Content = (void*)&CameraTransactions
	},
	
  { 0 }
};
//==============================================================================
