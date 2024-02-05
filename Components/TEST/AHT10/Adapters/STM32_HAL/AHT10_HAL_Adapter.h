
//==============================================================================
//header:

#ifndef _AHT10_HAL_ADAPTER_H_
#define _AHT10_HAL_ADAPTER_H_
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
//includes:

#include "Drivers/AHT10/AHT10.h"
#include "i2c.h"


//==============================================================================
//types:


typedef struct
{
	uint32_t TimeStamp;

} AHT10_HAL_AdapterContentT;
//------------------------------------------------------------------------------
typedef struct
{
	AHT10_HAL_AdapterContentT Content;
	I2C_HandleTypeDef* Handle;
	GPIO_TypeDef* LED_Port;
	uint8_t LED_Pin;

} AHT10_HAL_AdapterT;
//------------------------------------------------------------------------------
typedef struct
{
	I2C_HandleTypeDef* Handle;
	GPIO_TypeDef* LED_Port;
	uint8_t LED_Pin;


} AHT10_HAL_AdapterInitT;
//==============================================================================
//functions:

xResult AHT10_HAL_AdapterInit(AHT10_T* driver, AHT10_HAL_AdapterT* adapter, AHT10_HAL_AdapterInitT* init);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif //_AHT10_HAL_ADAPTER_H_
