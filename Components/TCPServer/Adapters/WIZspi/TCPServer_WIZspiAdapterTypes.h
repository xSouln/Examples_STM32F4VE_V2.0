//==============================================================================
#ifndef TCP_SERVER_WIZ_SPI_ADAPTER_TYPES_H
#define TCP_SERVER_WIZ_SPI_ADAPTER_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Components_Config.h"
#include "TCPServer/Adapters/TCPServer_AdaptersTypes.h"
#include "TCPServer_WIZspiAdapterInfo.h"
#include "TCPServer_WIZspiAdapterConfig.h"
//==============================================================================
typedef struct
{
	void (*HardwareResetOn)();
	void (*HardwareResetOff)();
	
	void (*SelectChip)();
	void (*DeselectChip)();
	
	void (*TransmiteByte)(uint8_t byte);
	uint8_t (*ReceiveByte)();
	  
} TCPServerWIZspiBusInterfaceT;
//==============================================================================
typedef struct
{
	void* Server;
	
	REG_SPI_T* SPI;
	TCPServerWIZspiBusInterfaceT BusInterface;
	
	xDataBufferT* ResponseBuffer;
	xRxReceiverT RxReceiver;
	
	uint8_t* RxBuffer;
	uint16_t RxBufferSize;
	  
} TCPServerWIZspiAdapterT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* TCP_SERVER_WIZ_SPI_ADAPTER_TYPES_H */
