//==============================================================================
#ifndef CONTROL_H
#define CONTROL_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Types.h"
#include "Info.h"
#include "Config.h"
#include "RxTransactions.h"
#include "RxRequests.h"
#include "SerialPort/SerialPort_Component.h"
#include "RGBCups/RGBCups_Component.h"
#include "Camera/Camera_Component.h"
#include "TCPServer/TCPServer_Component.h"
//==============================================================================
typedef struct
{
	OBJECT_HEADER;
	
	xRxRequestManagerT RequestManager;
	
} ControlT;
//==============================================================================
extern ControlT Control;
//------------------------------------------------------------------------------
ActionResults ControlInit(void* parent);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* CONTROL_H */
