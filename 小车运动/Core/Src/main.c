/* USER CODE BEGIN Header */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 *      * * * *     * * * *    * *     * *    * * * *      	  * * *
 *      *	   *    *	   *   *  *   *  *    *      *       *
 *		* * * *     * * * *    *   * *   *    * * * *      **
 *		*      *    *  *       *    *    *    *      *     *
 *		*       *   *   *      *         *    *       *    **
 *		*      *    *    *     *         *    *      *     	 *
 *		* * * *     *     *    *         *    * * * *         * * *
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "motor.h"
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

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
uint8_t n=0,m=0;
uint16_t a=0,b=0,c=0,d=0,g=0,s=0;
int t=0,x=0,y=0,l=0;
uint8_t buff;
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)//串口接收中断
{
	if(huart==&huart2)
	{
		switch(buff)
		{
			case 0x61:
			{
				car_go_left(999);
				break;
			}
			case 0x64:
			{
				car_go_right(999);
				break;
			}
			case 0x67:
			{
				DJ_go();
				break;
			}
			case 0x68:
			{
				DJ_stop();
				break;
			}
			case 0x72:
			{
				car_track_left(1499);
				break;
			}
			case 0x73:
			{
				car_go_stop();
				break;
			}
			case 0x74:
			{
				car_go_redright(1499);
				break;
			}
			case 0x77:
			{
				car_go_straight(1699);
				break;
			}
		}
//		if(buff==0x61)
//			car_go_left(999);
//		else if(buff==0x64)
//			car_go_right(999);
//		else if(buff==0x72)
//			car_track_left(899);
//		else if(buff==0x73)
//			car_go_stop();
//		else if(buff==0x77)
//			car_go_straight(1999);
//		else if(buff==0x68)
//			DJ_stop();
//		else if(buff==0x67)
//			DJ_go();
//		else
//		{
//			car_go_straight(1999);
//		}
	}
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)//计时并定时前进
{   
	if(htim == &htim4)
    {
		t=t+1;
		if(t>44)
		{
			car_go_straight(1499);
		}
    }
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_USART2_UART_Init();
  MX_TIM4_Init();
  PWM_INIT();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */
  
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
    /* USER CODE BEGIN 3 */
//	  car_track_left(1499);
//	  car_go_straight(1099);
//	  HAL_Delay(1000);
//	  car_go_stop();
//	  HAL_Delay(100);
//	  car_go_straight(1999);
//	  HAL_Delay(1000);
//	  car_go_stop();
//	  car_go_straight(599);
//	  HAL_Delay(1000);
//	  car_go_stop();
//	  car_go_left(1499);
//	  car_go_right(1499);
//	  HAL_Delay(1000);
//	  car_go_stop();
// 	  DJ_go();
	a=HAL_GPIO_ReadPin(L2_GPIO_Port,L2_Pin);
	b=HAL_GPIO_ReadPin(L1_GPIO_Port,L1_Pin);
	c=HAL_GPIO_ReadPin(R1_GPIO_Port,R1_Pin);
	d=HAL_GPIO_ReadPin(R2_GPIO_Port,R2_Pin);
	g=HAL_GPIO_ReadPin(GM1_GPIO_Port,GM1_Pin);
	s=HAL_GPIO_ReadPin(GM2_GPIO_Port,GM2_Pin);
	if(n==0&&g==0)//非接触启动(视觉)
	{
		HAL_GPIO_DeInit(GM1_GPIO_Port,GM1_Pin);
		n=1;
		l=1;
	}
	if(n==0&&s==0)//非接触启动(固定)
	{
		HAL_GPIO_DeInit(GM2_GPIO_Port,GM2_Pin);
		n=1;
		l=2;
	}
	if(n==1&&m==0)//进场
	{
		HAL_TIM_Base_Start_IT(&htim4);
		car_go_straight(1399);
		HAL_Delay(510);
		car_go_stop();
		HAL_Delay(10);
		car_go_right(1299);
		HAL_Delay(500);
		car_go_stop();
		HAL_Delay(10);
		car_go_straight(999);
		HAL_Delay(200);
		n=2;
	}
	else if(n==2&&m==0)//循迹
	{
		if((HAL_GPIO_ReadPin(L2_GPIO_Port,L2_Pin)==1)&&(HAL_GPIO_ReadPin(L1_GPIO_Port,L1_Pin)==0)&&(HAL_GPIO_ReadPin(R1_GPIO_Port,R1_Pin)==0))
		{
			car_go_straight(999);
		}
		else if((HAL_GPIO_ReadPin(L2_GPIO_Port,L2_Pin)==1)&&(HAL_GPIO_ReadPin(L1_GPIO_Port,L1_Pin)==1)&&(HAL_GPIO_ReadPin(R1_GPIO_Port,R1_Pin)==0))
		{
			car_go_right(999);
		}
		else if((HAL_GPIO_ReadPin(L2_GPIO_Port,L2_Pin)==1)&&(HAL_GPIO_ReadPin(L1_GPIO_Port,L1_Pin)==0)&&(HAL_GPIO_ReadPin(R1_GPIO_Port,R1_Pin)==1))
		{
			car_go_left(999);
		}
		else if((HAL_GPIO_ReadPin(L2_GPIO_Port,L2_Pin)==0)&&(HAL_GPIO_ReadPin(L1_GPIO_Port,L1_Pin)==0)&&(HAL_GPIO_ReadPin(R1_GPIO_Port,R1_Pin)==0))
		{
			car_go_after(1649);
			HAL_Delay(1);
			car_track_left(1499);
		}
		else if((HAL_GPIO_ReadPin(L2_GPIO_Port,L2_Pin)==0)&&(HAL_GPIO_ReadPin(L1_GPIO_Port,L1_Pin)==1)&&(HAL_GPIO_ReadPin(R1_GPIO_Port,R1_Pin)==1)&&t<5)
		{
			car_go_left(1499);
		}
		else if((HAL_GPIO_ReadPin(L2_GPIO_Port,L2_Pin)==1)&&(HAL_GPIO_ReadPin(L1_GPIO_Port,L1_Pin)==1)&&(HAL_GPIO_ReadPin(R1_GPIO_Port,R1_Pin)==1)&&t>36)//进场扎气球
		{
			HAL_TIM_Base_Stop_IT(&htim4);
			car_go_straight(999);
			HAL_Delay(130);
			car_go_left(1499);
			HAL_Delay(700);
			car_go_stop();
			HAL_Delay(1);
			car_go_straight(1499);
			HAL_Delay(260);
			car_go_stop();
			HAL_Delay(10);
			HAL_TIM_Base_Start_IT(&htim4);
			m=1;
		}
	}
	else if(m==1&&l==1)//视觉扎气球
	{
//		HAL_UART_Receive_IT(&huart2,&buff,sizeof(buff));
		if(a==0||b==0)
		{
			HAL_TIM_Base_Stop_IT(&htim4);
			car_go_after(1299);
			HAL_Delay(190);
			car_go_right(1499);
			HAL_Delay(740);
			car_go_stop();
			HAL_TIM_Base_Start_IT(&htim4);
		}
		else if(c==0||d==0)
		{
			HAL_TIM_Base_Stop_IT(&htim4);
			car_go_after(1299);
			HAL_Delay(190);
			car_go_left(1499);
			HAL_Delay(740);
			car_go_stop();
			HAL_TIM_Base_Start_IT(&htim4);
		}
		else
		{
			HAL_UART_Receive_IT(&huart2,&buff,sizeof(buff));
		}
	}
	else if(m==1&&l==2)//固定扎气球
	{
		DJ_go();
		if(a==0||b==0)
		{
			HAL_TIM_Base_Stop_IT(&htim4);
			car_go_after(1299);
			HAL_Delay(150);
			car_go_right(1499);
			HAL_Delay(740);
			car_go_stop();
			HAL_TIM_Base_Start_IT(&htim4);
		}
		else if(c==0||d==0)
		{
			HAL_TIM_Base_Stop_IT(&htim4);
			car_go_after(1299);
			HAL_Delay(150);
			car_go_left(1499);
			HAL_Delay(740);
			car_go_stop();
			HAL_TIM_Base_Start_IT(&htim4);
		}
	}
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
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
