//==============================================================================
#ifndef _FLOW_METER_H
#define _FLOW_METER_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "FlowMeter/Controls/FlowMeter_Types.h"
//==============================================================================
xResult FlowMeterInit(FlowMeterT* device, void* parent);

extern void FlowMeterHandler(FlowMeterT* device);
extern void FlowMeterTimeSynchronization(FlowMeterT* device);

xResult FlowMeterEnable(FlowMeterT* device);
void FlowMeterDisable(FlowMeterT* device);

void FlowMeterUpdate(FlowMeterT* device);
void FlowMeterReset(FlowMeterT* device);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif