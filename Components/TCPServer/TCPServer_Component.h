//==============================================================================
#ifndef TCP_SERVER_COMPONENT_H
#define TCP_SERVER_COMPONENT_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Components_Config.h"
#include "TCPServer/Controls/TCPServer.h"
//==============================================================================
extern TCPServerT TCPServerWIZspi;

xResult TCPServerWIZspiComponentInit(void* parent);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* TCP_SERVER_COMPONENT_H */
