//==============================================================================
#ifndef _BREW_GROUP_SENSORS_H
#define _BREW_GROUP_SENSORS_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "BrewGroup/Controls/BrewGroup_Types.h"
//==============================================================================
xResult BrewGroupSensorsInit(BrewGroupT* adapter);
extern void BrewGroupSensorsHandler(BrewGroupT* device);
extern void BrewGroupSensorsTimeSynchronization(BrewGroupT* device);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif
