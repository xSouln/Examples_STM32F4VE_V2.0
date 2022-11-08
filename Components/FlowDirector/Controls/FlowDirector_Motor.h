//==============================================================================
#ifndef _FLOW_DIRECTOR_MOTOR_H
#define _FLOW_DIRECTOR_MOTOR_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "FlowDirector/Controls/FlowDirector_Types.h"
//==============================================================================
xResult FlowDirectorMotorInit(FlowDirectorT* device);

void FlowDirectorMotorHandler(FlowDirectorT* device);
void FlowDirectorMotorTimeSynchronization(FlowDirectorT* device);
	
xResult FlowDirectorMotorSetPosition(FlowDirectorT* device, FlowDirectorRequestSetPositionT* request);
void FlowDirectorMotorStop(FlowDirectorT* device);
xResult FlowDirectorMotorEnable(FlowDirectorT* device);
void FlowDirectorMotorDisable(FlowDirectorT* device);
xResult FlowDirectorSetMotorOptions(FlowDirectorT* device, FlowDirectorMotorOptionsT* request);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif