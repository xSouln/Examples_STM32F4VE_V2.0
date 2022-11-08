//==============================================================================
#ifndef _WATER_PUMP_H
#define _WATER_PUMP_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "WaterPump_Types.h"
//==============================================================================
xResult WaterPumpInit(WaterPumpT* device, void* parent);

extern void WaterPumpHandler(WaterPumpT* device);
extern void WaterPumpTimeSynchronization(WaterPumpT* device);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif