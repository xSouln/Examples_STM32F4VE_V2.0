//==============================================================================
#ifndef _X_TYPES_CONFIG_H_
#define _X_TYPES_CONFIG_H_
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
//includes:

#include "Components-PrivateConfig.h"

#include "FreeRTOS.h"
#include "cmsis_os2.h"
#include "task.h"
#include "semphr.h"

#include "stm32f4xx_hal.h"
#include "Registers/registers.h"
#include "Common/xDevice-CommonTypes.h"
//==============================================================================
//defines:

#define OS_TYPE_NON 0
#define OS_TYPE_FREERTOS 1

#ifdef FREERTOS_CONFIG_H
#define FREERTOS_USED 1
#define OS_TYPE OS_TYPE_FREERTOS
#endif

#ifndef OS_TYPE
#define OS_TYPE OS_TYPE_NON
#endif

#define PACKED_PREFIX __packed
//==============================================================================
//types:

REG_GPIO_PORT_TYPEDEF(A,
		Pin0,
		Pin1,
		Pin2,
		Pin3,
		Pin4,
		Pin5,
		LED1,
		LED2,
		Pin8,
		USART1_TX,
		USART1_RX,
		USB_FS_DM,
		USB_FS_DP,
		SWDIO,
		SWDCLK,
		Pin15);

REG_GPIO_PORT_TYPEDEF(B,
		WS25Q16_CS,
		Pin1,
		Pin2,
		SPI1_SCK,
		SPI1_MISO,
		SPI1_MOSI,
		NRF_CE,
		NRF_CS,
		NRF_IRQ,
		Pin9,
		I2C2_SCL,
		I2C2_SDA,
		Pin12,
		Pin13,
		Pin14,
		Pin15);

REG_GPIO_PORT_TYPEDEF(C,
		Pin0,
		Pin1,
		Pin2,
		Pin3,
		Pin4,
		Pin5,
		Pin6,
		Pin7,
		SDIO_D0,
		SDIO_D1,
		SDIO_D2,
		SDIO_D3,
		SDIO_CK,
		Pin13,
		RCC_OSC32_IN,
		RCC_OSC32_OUT);

REG_GPIO_PORT_TYPEDEF(D,
		CAN1_RX,
		CAN1_TX,
		SDIO_CMD,
		Pin3,
		Pin4,
		Pin5,
		Pin6,
		Pin7,
		Pin8,
		Pin9,
		Pin10,
		Pin11,
		Pin12,
		Pin13,
		Pin14,
		Pin15);

REG_GPIO_PORT_TYPEDEF(E,
		Pin0,
		Pin1,
		Pin2,
		BUTTON1,
		BUTTON2,
		Pin5,
		Pin6,
		Pin7,
		Pin8,
		Pin9,
		Pin10,
		Pin11,
		Pin12,
		Pin13,
		Pin14,
		Pin15);

#define PortA ((REG_GPIO_PORT_A_T*)GPIOA)
#define PortB ((REG_GPIO_PORT_B_T*)GPIOB)
#define PortC ((REG_GPIO_PORT_C_T*)GPIOC)
#define PortD ((REG_GPIO_PORT_D_T*)GPIOD)
#define PortE ((REG_GPIO_PORT_E_T*)GPIOE)
//------------------------------------------------------------------------------

typedef struct PACKED_PREFIX
{
	uint16_t Id_1;
	uint16_t Id_2;

	union
	{
		struct
		{
			uint32_t Id_3;
			uint32_t Id_4;
		};

		uint64_t MAC;
	};

} UniqueDeviceID_T;
//==============================================================================
//values:


//==============================================================================
//export:

extern const UniqueDeviceID_T* UniqueDeviceID;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif //_X_TYPES_CONFIG_H_
