//==============================================================================
#ifndef _CUPS_CONTROLLER_TEMPLATE_H
#define _CUPS_CONTROLLER_TEMPLATE_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "Components_Types.h"
#include "Components_Config.h"
#include "WS2812/WS2812.h"
//==============================================================================
typedef enum
{
	CupTemplateIdIdle,

} CupTemplateIdSelector;
//==============================================================================
typedef WS2812_DrawManagerBaseT CupsControllerDrawManagerBaseT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif
