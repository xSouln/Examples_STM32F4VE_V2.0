//==============================================================================
#ifndef _CUPS_CONTROLLER_H
#define _CUPS_CONTROLLER_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Components_Config.h"
#include "CupsController_Types.h"
#include "CupsController/Controls/CupsController_DrawManager.h"
//------------------------------------------------------------------------------
extern CupsControllerT CupsController;
//extern RGBCupT CupsController[CupsControllerCount];
//==============================================================================
void CupsControllerHandler();
void CupsControllerTimeSynchronization();
xResult CupsControllerInit(void* parent, CupsControllerInterfaceT* interface);

extern xResult CupsControllerSetColor(CupSelector cups, CupLEDColorT pixel);
extern xResult CupsControllerUpdateLayout(CupSelector cups, uint32_t time_out);

extern xResult CupsControllerDrawingStart(CupSelector cups, void* template_request);
extern xResult CupsControllerDrawingStop(CupSelector cups);
extern void CupsControllerDraw(CupSelector cups);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif
