//==============================================================================
#ifndef _TERMINAL_H
#define _TERMINAL_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Terminal/Terminal_Types.h"
#include "Terminal/Adapters/Terminal_Adapters.h"
#include "Common/xRxRequest.h"
//==============================================================================
typedef struct
{
	OBJECT_HEADER;
	
	xRxRequestManagerT RequestManager;
	TerminalInterfaceT Interface;
	
} TerminalT;
//==============================================================================
xResult TerminalInit(void* parent);
void TerminalHandler();
void TerminalTimerUpdateEvent();
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif
