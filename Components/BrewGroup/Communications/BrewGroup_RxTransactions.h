//==============================================================================
#ifndef _BREW_GROUP_RX_TRANSACTIONS_H
#define _BREW_GROUP_RX_TRANSACTIONS_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Common/xRxTransaction.h"
#include "Common/xTx.h"
#include "BrewGroup/Controls/BrewGroup.h"
//==============================================================================
typedef enum
{
  BREW_GROUP_GET_FIRMWARE_VERSION = 100,
	BREW_GROUP_GET_STATUS,

	BREW_GROUP_SET = 1000,

	BREW_GROUP_TRY = 2000,
	BREW_GROUP_TRY_STOP,

	BREW_GROUP_EVT = 10000,
	
} BREW_GROUP_TRANSACTIONS;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

