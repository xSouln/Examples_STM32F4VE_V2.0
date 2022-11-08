//==============================================================================
#ifndef _FLOW_DIRECTOR_RX_TRANSACTIONS_H
#define _FLOW_DIRECTOR_RX_TRANSACTIONS_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Common/xRxTransaction.h"
#include "Common/xTx.h"
#include "FlowDirector/Controls/FlowDirector.h"
//==============================================================================
typedef enum
{
  FLOW_DIRECTOR_GET_FIRMWARE_VERSION = 100,
	FLOW_DIRECTOR_GET_STATUS,

	FLOW_DIRECTOR_SET = 1000,

	FLOW_DIRECTOR_TRY = 2000,
	FLOW_DIRECTOR_TRY_STOP,

	FLOW_DIRECTOR_EVT = 10000,
	
} FLOW_DIRECTOR_TRANSACTIONS;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

