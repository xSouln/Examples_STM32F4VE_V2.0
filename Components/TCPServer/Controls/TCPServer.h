//==============================================================================
#ifndef TCP_SERVER_H
#define TCP_SERVER_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "TCPServer/TCPServer_Types.h"
#include "TCPServer/Adapters/TCPServer_Adapters.h"
//==============================================================================
void TCPServerHandler(TCPServerT* server);

xResult TCPServerInit(TCPServerT* server, void* parent, TCPServerInterfaceT* interface);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* TCP_SERVER_H */
