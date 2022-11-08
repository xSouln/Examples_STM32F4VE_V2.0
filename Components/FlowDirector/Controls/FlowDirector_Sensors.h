//==============================================================================
#ifndef _FLOW_DIRECTOR_SENSORS_H
#define _FLOW_DIRECTOR_SENSORS_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "FlowDirector/Controls/FlowDirector_Types.h"
//==============================================================================
xResult FlowDirectorSensorsInit(FlowDirectorT* device);
extern void FlowDirectorSensorsHandler(FlowDirectorT* device);
extern void FlowDirectorSensorsTimeSynchronization(FlowDirectorT* device);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif
