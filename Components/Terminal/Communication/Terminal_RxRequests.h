/*
 *
 */
#ifndef _TERMINAL_RX_REQUESTS_H
#define _TERMINAL_RX_REQUESTS_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Common/xTx.h"
#include "Common/xRxTransaction.h"
#include "Common/xRxReceiver.h"
//==============================================================================
static const char RECEIVER_REQUEST_GET_FIRMWARE[] = "get firmware";

extern const xRxRequestT TerminalRxRequests[];
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif
