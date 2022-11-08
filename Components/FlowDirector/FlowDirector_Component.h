//==============================================================================
#ifndef _FLOW_DIRECTOR_COMPONENT_H
#define _FLOW_DIRECTOR_COMPONENT_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "FlowDirector/Controls/FlowDirector.h"
//==============================================================================
extern FlowDirectorT FlowDirector;
extern void FlowDirectorComponentHandler();
extern void FlowDirectorComponentTimeSynchronization();

xResult FlowDirectorComponentInit(void* parent);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

