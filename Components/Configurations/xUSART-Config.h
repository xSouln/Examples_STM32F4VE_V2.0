//==============================================================================
#ifndef _X_USART_CONFIG_H_
#define _X_USART_CONFIG_H_
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
//includes:

#include "xTypes-Config.h"
#include "Registers/registers.h"
//==============================================================================
//defines:

#define USART1_ENABLE 1
#define USART2_ENABLE 0
#define USART3_ENABLE 0
#define USART6_ENABLE 0
//------------------------------------------------------------------------------

typedef enum PACKED_PREFIX
{
#if defined(rUSART1) && USART1_ENABLE == 1
	xUSART1,
#endif

#if defined(rUSART2) && USART2_ENABLE == 1
	xUSART2,
#endif

#if defined(rUSART3) && USART3_ENABLE == 1
	xUSART3,
#endif

#if defined(rUSART4) && USART4_ENABLE == 1
	xUSART4,
#endif

#if defined(rUSART5) && USART5_ENABLE == 1
	xUSART5,
#endif

#if defined(rUSART6) && USART6_ENABLE == 1
	xUSART6,
#endif

	xUSARTsCounts

} xUSART_Numbers;
//------------------------------------------------------------------------------
#define xUSART_HandleT REG_UART_T
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif //_X_USART_CONFIG_H_
