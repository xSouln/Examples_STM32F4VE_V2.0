//==============================================================================
#ifndef _BREW_GROUP_MOTOR_H_
#define _BREW_GROUP_MOTOR_H_
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "BrewGroup/Controls/BrewGroup_Types.h"
//==============================================================================
xResult BrewGroupMotorInit(BrewGroupT* device);
extern void BrewGroupMotorHandler(BrewGroupT* device);
extern void BrewGroupMotorTimeSynchronization(BrewGroupT* device);

xResult BrewGroupSetMotorOptions(BrewGroupT* device, BrewGroupMotorOptionsT* request);
xResult BrewGroupMotorSetPosition(BrewGroupT* device, BrewGroupMoveRequestT* request);

void BrewGroupMotorStop(BrewGroupT* device);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif