
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

	float AHT10_Temperature;
	float AHT10_Humidity;

	struct
	{
		//включение логики опроса
		uint8_t ConversationIsEnable : 1;
		uint8_t ConversationRequestUpdate : 1;
		uint8_t ConversationStarted : 1;
		uint8_t ConversationComplited : 1;
		uint8_t ConversationError : 1;
	};

	uint8_t State;
	uint16_t OpereationTimeout;

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
