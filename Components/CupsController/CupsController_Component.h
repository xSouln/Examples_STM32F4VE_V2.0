//==============================================================================
#ifndef _CUPS_CONTROLLER_COMPONENT_H
#define _CUPS_CONTROLLER_COMPONENT_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "CupsController/Controls/CupsController.h"
//==============================================================================
int CupsControllerComponentInit(void* parent);
extern void CupsControllerComponentHandler();
extern void CupsControllerComponentTimeSynchronization();
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* RGB_CUP_COMPONENT_H */
