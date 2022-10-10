/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Common/xTypes.h"
#include "Registers/registers.h"
#include "xAdapters.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BUTTON_1_Pin GPIO_PIN_3
#define BUTTON_1_GPIO_Port GPIOE
#define BUTTON_2_Pin GPIO_PIN_4
#define BUTTON_2_GPIO_Port GPIOE
#define HEATER_CUP_1_Pin GPIO_PIN_0
#define HEATER_CUP_1_GPIO_Port GPIOC
#define HEATER_CUP_2_Pin GPIO_PIN_1
#define HEATER_CUP_2_GPIO_Port GPIOC
#define HEATER_CUP_3_Pin GPIO_PIN_2
#define HEATER_CUP_3_GPIO_Port GPIOC
#define HEATER_CUP_4_Pin GPIO_PIN_3
#define HEATER_CUP_4_GPIO_Port GPIOC
#define CAROUSEL_MOTOR_ENCODER_A_Pin GPIO_PIN_0
#define CAROUSEL_MOTOR_ENCODER_A_GPIO_Port GPIOA
#define CAROUSEL_MOTOR_ENCODER_B_Pin GPIO_PIN_1
#define CAROUSEL_MOTOR_ENCODER_B_GPIO_Port GPIOA
#define CAROUSEL_MOTOR_CH1_Pin GPIO_PIN_2
#define CAROUSEL_MOTOR_CH1_GPIO_Port GPIOA
#define CAROUSEL_MOTOR_CH2_Pin GPIO_PIN_3
#define CAROUSEL_MOTOR_CH2_GPIO_Port GPIOA
#define WATER_FLOW_METER_Pin GPIO_PIN_5
#define WATER_FLOW_METER_GPIO_Port GPIOA
#define LED_1_Pin GPIO_PIN_6
#define LED_1_GPIO_Port GPIOA
#define LED_2_Pin GPIO_PIN_7
#define LED_2_GPIO_Port GPIOA
#define CAROUSEL_MOTOR_CH1B0_Pin GPIO_PIN_0
#define CAROUSEL_MOTOR_CH1B0_GPIO_Port GPIOB
#define CAROUSEL_MOTOR_CH2B1_Pin GPIO_PIN_1
#define CAROUSEL_MOTOR_CH2B1_GPIO_Port GPIOB
#define WS2812_LED_PANEL_Pin GPIO_PIN_11
#define WS2812_LED_PANEL_GPIO_Port GPIOE
#define WS2812_CUPS_12_Pin GPIO_PIN_13
#define WS2812_CUPS_12_GPIO_Port GPIOE
#define WS2812_CUPS_34_Pin GPIO_PIN_14
#define WS2812_CUPS_34_GPIO_Port GPIOE
#define BREW_MOTOR_CH1_Pin GPIO_PIN_12
#define BREW_MOTOR_CH1_GPIO_Port GPIOD
#define BREW_MOTOR_CH2_Pin GPIO_PIN_13
#define BREW_MOTOR_CH2_GPIO_Port GPIOD
#define POD_RELEASE_MOTOR_CH1_Pin GPIO_PIN_14
#define POD_RELEASE_MOTOR_CH1_GPIO_Port GPIOD
#define POD_RELEASE_MOTOR_CH2_Pin GPIO_PIN_15
#define POD_RELEASE_MOTOR_CH2_GPIO_Port GPIOD
#define FLOW_DIR_MOTOR_CH1_Pin GPIO_PIN_6
#define FLOW_DIR_MOTOR_CH1_GPIO_Port GPIOC
#define FLOW_DIR_MOTOR_CH2_Pin GPIO_PIN_7
#define FLOW_DIR_MOTOR_CH2_GPIO_Port GPIOC
#define NRF_CE_Pin GPIO_PIN_6
#define NRF_CE_GPIO_Port GPIOB
#define NRF_CS_Pin GPIO_PIN_7
#define NRF_CS_GPIO_Port GPIOB
#define NRF_IRQ_Pin GPIO_PIN_8
#define NRF_IRQ_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
