//==============================================================================
#ifndef _CUPS_CONTROLLER_HEATER_TYPES_H
#define _CUPS_CONTROLLER_HEATER_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "CupsController_HeaterConfig.h"
#include "CupsController/Adapters/CupsController_HeaterAdapterBase.h"
//==============================================================================

//------------------------------------------------------------------------------
typedef struct
{
	OBJECT_HEADER;

	CupsControllerHeaterAdapterBaseT Adapter;


} CupsControllerHeaterT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif
