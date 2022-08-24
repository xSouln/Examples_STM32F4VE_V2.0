/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Control.h"
#include "Adapters/TransactionTransferAdapter.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
//==============================================================================
#define MAIN_RESPONSE_BUFFER_SIZE 1024
static uint8_t main_response_buffer_memory[MAIN_RESPONSE_BUFFER_SIZE];

xDataBufferT MainResponseBuffer =
{
	.Data = main_response_buffer_memory,
	.Size = MAIN_RESPONSE_BUFFER_SIZE
};
//------------------------------------------------------------------------------
uint8_t time_5ms;
uint8_t time_10ms;
uint8_t time_100ms;
uint16_t time_1000ms;
uint16_t time_5000ms;
uint32_t time_ms;
//------------------------------------------------------------------------------
xTxTransferT TransferLayer;
//------------------------------------------------------------------------------
struct
{
	uint32_t SelectNewTemplate : 1;
	
} Handle;
//==============================================================================
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
WS2812_PixelT Color =
{
	.Green = 1,
	.Red = 1,
	.Blue = 1
};
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
const char* string_out = "111111111111111111111111\r111111111111111111111111\r111111111111111111111111\r111111111111111111111111\r111111111111111111111111\r111111111111111111111111\r111111111111111111111111\r";
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
	
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_SPI1_Init();
  MX_USART1_UART_Init();
  MX_TIM4_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM8_Init();
  MX_TIM3_Init();
  MX_TIM5_Init();
  MX_TIM14_Init();
  MX_I2C2_Init();
  /* USER CODE BEGIN 2 */
	ControlInit("main");
	
	TransactionAdapterInit(&TransferLayer, &SerialPortUART.Tx);
	xTxTransferInit(&TransferLayer, 1, 20, 1.0);
	
	RGBCups_DrawingStart(RGBCup1, (RGBCupDrawManagerBaseT*)&DrawManager1);
	//RGBCups_DrawManagerEx1Init(RGBCup1, &DrawManager1);
	
	//HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		if (!time_5ms)
		{
			time_5ms = 4;
			
			SerialPort_Handler(&SerialPortUART);
			SerialPort_Handler(&SerialPortUSB);
			
			xTxTransferHandler(&TransferLayer);
		}
		
		if (!time_1000ms)
		{
			time_1000ms = 999;
			
			LED_1_GPIO_Port->ODR ^= LED_1_Pin;
			
			//LED_2_GPIO_Port->ODR ^= LED_2_Pin;
			RGBCups_SetColor(RGBCup1, Color);
			
			//xTxTransmitString(&SerialPortUART.Tx, "qwerty\r");
			xTxTransmitString(&SerialPortUSB.Tx, "qwerty\r");
			
			xTxTransferTransmit(&TransferLayer, (uint8_t*)string_out, strlen(string_out));
		}
		
		if (!time_10ms)
		{
			time_10ms = 99;
			
			if (Handle.SelectNewTemplate && RGBCups[RGBCupNumber1].Status.DrawManager == RGBCupDrawManageStateCycleStart)
			{
				Handle.SelectNewTemplate = false;
				
				if (RGBCups[RGBCupNumber1].DrawManagerPattern == (RGBCupDrawManagerBaseT*)&DrawManager3)
				{
					RGBCups_DrawingStart(RGBCup1, (RGBCupDrawManagerBaseT*)&DrawManager1);
				}
				else
				{
					RGBCups_DrawingStart(RGBCup1, (RGBCupDrawManagerBaseT*)&DrawManager3);
				}
			}
			
			RGBCups_Draw(RGBCup1|RGBCup2);
			RGBCups_UpdateLayout(RGBCup1|RGBCup2, 1000);
		}
		
		if (!time_5000ms)
		{
			time_5000ms = 4999;
			Handle.SelectNewTemplate = true;
		}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 120;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 5;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
