//==============================================================================
#ifndef _FLOW_DIRECTOR_H
#define _FLOW_DIRECTOR_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "FlowDirector_Types.h"
#include "FlowDirector/Controls/FlowDirector_Motor.h"
#include "FlowDirector/Controls/FlowDirector_Sensors.h"
//==============================================================================
xResult FlowDirectorInit(FlowDirectorT* device, void* parent, FlowDirectorTerminalT* terminal);
void FlowDirectorHandler(FlowDirectorT* device);
void FlowDirectorTimeSynchronization(FlowDirectorT* device);

xResult FlowDirectorStop(FlowDirectorT* device);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif
