//==============================================================================
#ifndef _BREW_GROUP_COMPONENT_H
#define _BREW_GROUP_COMPONENT_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Components_Config.h"
#include "BrewGroup/Controls/BrewGroup.h"
//==============================================================================
extern BrewGroupT BrewGroup;

xResult BrewGroupComponentInit(void* parent);

extern void BrewGroupComponentHandler();
extern void BrewGroupComponentTimeSynchronization();
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

