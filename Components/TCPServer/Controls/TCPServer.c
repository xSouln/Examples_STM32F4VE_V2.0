//==============================================================================
#include "Common/xMemory.h"
#include "TCPServer.h"
//==============================================================================
void TCPServer_Handler(TCPServerT* server)
{
	xRxHandler(&server->Rx);
  xTxHandler(&server->Tx);
}
//------------------------------------------------------------------------------
TCPServerResult TCPServer_Init(TCPServerT* server, void* parent, TCPServerInterfaceT* interface)
{
	if (server && interface)
	{
		server->Description = "TCPServerT";
		server->Parent = parent;
		server->Interface = interface;
		
		return TCPServerResultAccept;
	}
	return TCPServerResultError;
}
//==============================================================================
