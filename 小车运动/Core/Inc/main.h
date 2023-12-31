/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

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
#define GM2_Pin GPIO_PIN_13
#define GM2_GPIO_Port GPIOC
#define IN5_Pin GPIO_PIN_12
#define IN5_GPIO_Port GPIOB
#define IN6_Pin GPIO_PIN_13
#define IN6_GPIO_Port GPIOB
#define IN7_Pin GPIO_PIN_14
#define IN7_GPIO_Port GPIOB
#define IN8_Pin GPIO_PIN_15
#define IN8_GPIO_Port GPIOB
#define GM1_Pin GPIO_PIN_8
#define GM1_GPIO_Port GPIOA
#define L2_Pin GPIO_PIN_9
#define L2_GPIO_Port GPIOA
#define L1_Pin GPIO_PIN_10
#define L1_GPIO_Port GPIOA
#define R1_Pin GPIO_PIN_11
#define R1_GPIO_Port GPIOA
#define R2_Pin GPIO_PIN_12
#define R2_GPIO_Port GPIOA
#define IN1_Pin GPIO_PIN_3
#define IN1_GPIO_Port GPIOB
#define IN2_Pin GPIO_PIN_4
#define IN2_GPIO_Port GPIOB
#define IN3_Pin GPIO_PIN_5
#define IN3_GPIO_Port GPIOB
#define IN4_Pin GPIO_PIN_6
#define IN4_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
