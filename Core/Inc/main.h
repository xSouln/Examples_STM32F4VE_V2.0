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
#define CAROUSEL_MOTOR_CURRENT_ADC_Pin GPIO_PIN_0
#define CAROUSEL_MOTOR_CURRENT_ADC_GPIO_Port GPIOC
#define SLIDER_MOTOR_CURRENT_ADC_Pin GPIO_PIN_1
#define SLIDER_MOTOR_CURRENT_ADC_GPIO_Port GPIOC
#define BREW_GROUP_MOTOR_CURRENT_ADC_Pin GPIO_PIN_2
#define BREW_GROUP_MOTOR_CURRENT_ADC_GPIO_Port GPIOC
#define FLOW_DIR_NOTOR_CURRENT_ADC_Pin GPIO_PIN_3
#define FLOW_DIR_NOTOR_CURRENT_ADC_GPIO_Port GPIOC
#define CAROUSEL_MOTOR_ENCODER_A_Pin GPIO_PIN_0
#define CAROUSEL_MOTOR_ENCODER_A_GPIO_Port GPIOA
#define CAROUSEL_MOTOR_ENCODER_B_Pin GPIO_PIN_1
#define CAROUSEL_MOTOR_ENCODER_B_GPIO_Port GPIOA
#define FLOW_DIR_MOTOR_PWM1_Pin GPIO_PIN_2
#define FLOW_DIR_MOTOR_PWM1_GPIO_Port GPIOA
#define FLOW_DIR_MOTOR_PWM2_Pin GPIO_PIN_3
#define FLOW_DIR_MOTOR_PWM2_GPIO_Port GPIOA
#define LED_1_Pin GPIO_PIN_6
#define LED_1_GPIO_Port GPIOA
#define LED_2_Pin GPIO_PIN_7
#define LED_2_GPIO_Port GPIOA
#define TRASH_TANK_SENSOR1_Pin GPIO_PIN_4
#define TRASH_TANK_SENSOR1_GPIO_Port GPIOC
#define TRASH_TANK_SENSOR2_Pin GPIO_PIN_5
#define TRASH_TANK_SENSOR2_GPIO_Port GPIOC
#define BREW_GROUP_THERMOCOUPLE_Pin GPIO_PIN_0
#define BREW_GROUP_THERMOCOUPLE_GPIO_Port GPIOB
#define BREW_GROUP_WATER_PUMP_Pin GPIO_PIN_1
#define BREW_GROUP_WATER_PUMP_GPIO_Port GPIOB
#define BREW_GROUP_WATER_HEATER_Pin GPIO_PIN_2
#define BREW_GROUP_WATER_HEATER_GPIO_Port GPIOB
#define SLIDER_SENSOR_OPEN_Pin GPIO_PIN_7
#define SLIDER_SENSOR_OPEN_GPIO_Port GPIOE
#define SLIDER_SENSOR_CLOSE_Pin GPIO_PIN_8
#define SLIDER_SENSOR_CLOSE_GPIO_Port GPIOE
#define BREW_GROUP_MOTOR_OVERCURRENT_SENSOR_Pin GPIO_PIN_9
#define BREW_GROUP_MOTOR_OVERCURRENT_SENSOR_GPIO_Port GPIOE
#define FLOW_DIR_MOTOR_OVERCURRENT_SENSOR_Pin GPIO_PIN_10
#define FLOW_DIR_MOTOR_OVERCURRENT_SENSOR_GPIO_Port GPIOE
#define WS2812_LED_PANEL_Pin GPIO_PIN_11
#define WS2812_LED_PANEL_GPIO_Port GPIOE
#define WS2812_CUPS_12_Pin GPIO_PIN_13
#define WS2812_CUPS_12_GPIO_Port GPIOE
#define WS2812_CUPS_34_Pin GPIO_PIN_14
#define WS2812_CUPS_34_GPIO_Port GPIOE
#define OUT1_Pin GPIO_PIN_12
#define OUT1_GPIO_Port GPIOB
#define OUT2_Pin GPIO_PIN_13
#define OUT2_GPIO_Port GPIOB
#define OUT3_Pin GPIO_PIN_14
#define OUT3_GPIO_Port GPIOB
#define OUT4_Pin GPIO_PIN_15
#define OUT4_GPIO_Port GPIOB
#define IN1_Pin GPIO_PIN_8
#define IN1_GPIO_Port GPIOD
#define IN2_Pin GPIO_PIN_9
#define IN2_GPIO_Port GPIOD
#define IN3_Pin GPIO_PIN_10
#define IN3_GPIO_Port GPIOD
#define CAROUSEL_SENSOR_ZERO_MARK_Pin GPIO_PIN_11
#define CAROUSEL_SENSOR_ZERO_MARK_GPIO_Port GPIOD
#define BREW_GROUP_MOTOR_PWM1_Pin GPIO_PIN_12
#define BREW_GROUP_MOTOR_PWM1_GPIO_Port GPIOD
#define BREW_GROUP_MOTOR_PWM2_Pin GPIO_PIN_13
#define BREW_GROUP_MOTOR_PWM2_GPIO_Port GPIOD
#define SLIDER_MOTOR_PWM1_Pin GPIO_PIN_14
#define SLIDER_MOTOR_PWM1_GPIO_Port GPIOD
#define SLIDER_MOTOR_PWM2_Pin GPIO_PIN_15
#define SLIDER_MOTOR_PWM2_GPIO_Port GPIOD
#define CAROUSEL_MOTOR_PWM1_Pin GPIO_PIN_6
#define CAROUSEL_MOTOR_PWM1_GPIO_Port GPIOC
#define CAROUSEL_MOTOR_PWM2_Pin GPIO_PIN_7
#define CAROUSEL_MOTOR_PWM2_GPIO_Port GPIOC
#define BREW_GROUP_FLOW_METER_Pin GPIO_PIN_2
#define BREW_GROUP_FLOW_METER_GPIO_Port GPIOD
#define CAROUSEL_MOTOR_OVERCURRENT_SENSOR_Pin GPIO_PIN_3
#define CAROUSEL_MOTOR_OVERCURRENT_SENSOR_GPIO_Port GPIOD
#define SLIDER_MOTOR_OVERCURRENT_SENSOR_Pin GPIO_PIN_4
#define SLIDER_MOTOR_OVERCURRENT_SENSOR_GPIO_Port GPIOD
#define BREW_GROUP_MOTOR_OVERCURRENT_SENSORD5_Pin GPIO_PIN_5
#define BREW_GROUP_MOTOR_OVERCURRENT_SENSORD5_GPIO_Port GPIOD
#define FLOW_DIR_MOTOR_OVERCURRENT_SENSORD6_Pin GPIO_PIN_6
#define FLOW_DIR_MOTOR_OVERCURRENT_SENSORD6_GPIO_Port GPIOD
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
