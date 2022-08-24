//==============================================================================
#ifndef FLOW_DIRECTORE_ADAPTER_H
#define FLOW_DIRECTORE_ADAPTER_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Adapters/FlowDirector_Config.h" // override default macroses
#include "MotorDriver/MotorDriver.h"
//==============================================================================
#ifndef FlowDirector_Result
#define FlowDirector_Result int8_t
#endif
//------------------------------------------------------------------------------
#ifndef FlowDirector_ResultAccept
#define FlowDirector_ResultAccept 0
#endif
//------------------------------------------------------------------------------
#ifndef FlowDirector_ResultError
#define FlowDirector_ResultError -1
#endif
//------------------------------------------------------------------------------
#ifndef FlowDirector_ResultBusy
#define FlowDirector_ResultBusy -2
#endif
//------------------------------------------------------------------------------
#ifndef FlowDirector_ResultNullPointer
#define FlowDirector_ResultNullPointer -3
#endif
//------------------------------------------------------------------------------
#ifndef FlowDirector_ResultInvalidParameter
#define FlowDirector_ResultInvalidParameter -4
#endif
//==============================================================================
typedef struct
{
	char* Description;
	void* Parent;
	
	MotorDriverT Driver;
	
} FlowDirectorT;
//==============================================================================
FlowDirector_Result FlowDirector_Init(FlowDirectorT* adapter, void* parent);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* FLOW_DIRECTORE_ADAPTER_H */

