//==============================================================================
#ifndef _OV2640_ADAPTER_TYPES_H
#define _OV2640_ADAPTER_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "OV2640_AdapterConfig.h"
#include "OV2640/OV2640_Driver.h"
#include "Common/xTxTransfer.h"
//==============================================================================
#define OV2640_SNAPSHOT_BUFFER_TYPE uint32_t
//==============================================================================
typedef union
{
	struct
	{
		uint32_t JPEG_Request : 1;
	};
	uint32_t Value;
	
} OV2640_AdapterHandleT;
//------------------------------------------------------------------------------
typedef struct
{
	char* Description;
	void* Parent;
	
	void* Camera;
	OV2640_DriverT Driver;
	
	OV2640_AdapterHandleT Handle;
	
	I2C_HandleTypeDef* HandleI2C;
	void* HandleDCMI;
	
	GPIO_TypeDef* HardwareResetPort;
	uint16_t HardwareResetPin;
	
	GPIO_TypeDef* PowerDownPort;
	uint16_t PowerDownPin;
	
} OV2640_AdapterT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* _OV2640_ADAPTER_TYPES_H */
