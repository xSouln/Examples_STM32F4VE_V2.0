//==============================================================================
#ifndef _WATER_PUMP_COMPONENT_H
#define _WATER_PUMP_COMPONENT_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif 
//==============================================================================
#include "WaterPump/Controls/WaterPump.h"
//==============================================================================
extern WaterPumpT WaterPump;

xResult WaterPumpComponentInit(void* parent);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

