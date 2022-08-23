//==============================================================================
#ifndef TCP_SERVER_WIZ_SPI_RX_ADAPTER_H
#define TCP_SERVER_WIZ_SPI_RX_ADAPTER_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "TCPServerWIZspi_AdapterTypes.h"
#include "TCPServer/TCPServer_Types.h"
//==============================================================================
int TCPServerWIZspi_RxAdapterInit(TCPServerT* server, TCPServerWIZspi_AdapterT* adapter);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* TCP_SERVER_WIZ_SPI_RX_ADAPTER_H */

