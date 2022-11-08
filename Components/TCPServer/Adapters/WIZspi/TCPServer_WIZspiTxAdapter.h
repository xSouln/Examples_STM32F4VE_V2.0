//==============================================================================
#ifndef TCP_SERVER_WIZ_SPI_TX_ADAPTER_H
#define TCP_SERVER_WIZ_SPI_TX_ADAPTER_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "TCPServer_WIZspiAdapterTypes.h"
#include "TCPServer/TCPServer_Types.h"
//==============================================================================
xResult TCPServerWIZspiTxAdapterInit(TCPServerT* server, TCPServerWIZspiAdapterT* adapter);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* TCP_SERVER_WIZ_SPI_TX_ADAPTER_H */

