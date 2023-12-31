/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32h7xx_hal.h"

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
#define DISP_Pin GPIO_PIN_8
#define DISP_GPIO_Port GPIOI
#define RST_Pin GPIO_PIN_6
#define RST_GPIO_Port GPIOF
#define SCL_Pin GPIO_PIN_7
#define SCL_GPIO_Port GPIOF
#define SDA_Pin GPIO_PIN_8
#define SDA_GPIO_Port GPIOF
#define Relay1_Pin GPIO_PIN_4
#define Relay1_GPIO_Port GPIOA
#define Relay2_Pin GPIO_PIN_5
#define Relay2_GPIO_Port GPIOA
#define Relay3_Pin GPIO_PIN_6
#define Relay3_GPIO_Port GPIOA
#define Relay4_Pin GPIO_PIN_7
#define Relay4_GPIO_Port GPIOA
#define INT_Pin GPIO_PIN_7
#define INT_GPIO_Port GPIOD
#define INT_EXTI_IRQn EXTI9_5_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
