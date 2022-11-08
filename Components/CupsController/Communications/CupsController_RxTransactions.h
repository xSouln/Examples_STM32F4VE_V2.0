//==============================================================================
#ifndef _CUPS_CONTROLLER_RX_TRANSACTIONS_H
#define _CUPS_CONTROLLER_RX_TRANSACTIONS_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Common/xRxTransaction.h"
#include "CupsController/Controls/CupsController.h"
//==============================================================================
typedef enum
{
	CUPS_CONTROLLER_GET_FIRMWARE_VERSION = 100,
	CUPS_CONTROLLER_GET_PIXELS,
	CUPS_CONTROLLER_GET_STATUS,
	CUPS_CONTROLLER_GET_TEMPLATE_ID,
	
	CUPS_CONTROLLER_SET = 1000,
	CUPS_CONTROLLER_SET_PIXELS,
	CUPS_CONTROLLER_SET_PIXELS_STATE,
	CUPS_CONTROLLER_SET_COLOR,
	CUPS_CONTROLLER_SET_TEMPLATE,
	CUPS_CONTROLLER_SET_TEMPLATE_BY_ID,

	CUPS_CONTROLLER_TRY = 2000,
	CUPS_CONTROLLER_TRY_DRAWING_START,
	CUPS_CONTROLLER_TRY_DRAWING_STOP,

	CUPS_CONTROLLER_EVT = 10000,
	
} CUPS_CONTROLLER_TRANSACTIONS;
//==============================================================================
typedef struct
{
	uint8_t Selector;
	
	CupLEDColorT Color;
	
} CupsControllerRequestSetColorT;
//------------------------------------------------------------------------------
typedef struct
{
	CupSelector CupSelector;
	CupTemplateIdSelector TemplaetIdSelector;
	
} CupsControllerRequestSetTemplaetByIdT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* CUPS_CONTROLLER_RX_TRANSACTIONS_H */

