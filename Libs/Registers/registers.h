/*
 *
 */ 
//==============================================================================
#ifndef REGISTERS_H_
#define REGISTERS_H_
//==============================================================================
#include <stdint.h>
#include <stdbool.h>
//==============================================================================
#ifdef STM32H743xx

#include "registers_stm32h7xx/registers_stm32h7xx_spi.h"
#include "registers_stm32h7xx/registers_stm32h7xx_timer.h"
#include "registers_stm32h7xx/registers_stm32h7xx_uart.h"
#include "registers_stm32h7xx/registers_stm32h7xx_dma.h"

#elif STM32F103xB

#include "registers_stm32f1xx/registers_stm32f1xx_spi.h"
#include "registers_stm32f1xx/registers_stm32f1xx_timer.h"
#include "registers_stm32f1xx/registers_stm32f1xx_uart.h"
#include "registers_stm32f1xx/registers_stm32f1xx_i2c.h"

#elif STM32F407xx

#include "registers_stm32f4xx/registers_stm32f4xx_spi.h"
#include "registers_stm32f4xx/registers_stm32f4xx_timer.h"
#include "registers_stm32f4xx/registers_stm32f4xx_uart.h"
#include "registers_stm32f4xx/registers_stm32f4xx_i2c.h"

#elif STM32F429xx

#include "registers_stm32f4xx/registers_stm32f4xx_spi.h"
#include "registers_stm32f4xx/registers_stm32f4xx_timer.h"
#include "registers_stm32f4xx/registers_stm32f4xx_uart.h"
#include "registers_stm32f4xx/registers_stm32f4xx_i2c.h"

#endif
//==============================================================================
#endif /* X_REGISTERS_H_ */
