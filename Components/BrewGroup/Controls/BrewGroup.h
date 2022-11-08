//==============================================================================
#ifndef _BREW_GROUP_H
#define _BREW_GROUP_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "BrewGroup_Types.h"
#include "BrewGroup_Motor.h"
#include "BrewGroup_Sensors.h"
#include "Termostat/Controls/Thermostat.h"
#include "FlowMeter/Controls/FlowMeter.h"
#include "WaterPump/Controls/WaterPump.h"
//==============================================================================
xResult BrewGroupInit(BrewGroupT* BrewGroup, void* parent, BrewGroupTerminalT* terminal);
void BrewGroupHandler(BrewGroupT* BrewGroup);
void BrewGroupTimeSynchronization(BrewGroupT* device);

xResult BrewGroupSetMotorOptions(BrewGroupT* device, BrewGroupMotorOptionsT* request);

void BrewGroupStop(BrewGroupT* device);
xResult BrewGroupOpen(BrewGroupT* device);
xResult BrewGroupClose(BrewGroupT* device);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif
