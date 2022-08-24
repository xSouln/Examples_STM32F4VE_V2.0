/*
 *
 */
#ifndef TRANSACTION_TRANSFER_ADAPTER_H
#define TRANSACTION_TRANSFER_ADAPTER_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif 
//==============================================================================
#include "Common/xTypes.h"
#include "Common/xTxTransfer.h"
#include "Common/xTx.h"
#include "Common/xRxTransaction.h"
//==============================================================================
typedef struct
{
	xTxT* Tx;
	
	PacketIdentificatorT* EventIdentificator;
	
	
} TransactionTransferAdapterT;
//==============================================================================
xResult TransactionAdapterInit(xTxTransferT* layer, xTxT* adapter);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* TRANSACTION_TRANSFER_ADAPTER_H */
