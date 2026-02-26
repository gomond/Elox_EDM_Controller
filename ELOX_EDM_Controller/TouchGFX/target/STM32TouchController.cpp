/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : STM32TouchController.cpp
  ******************************************************************************
  * This file was created by TouchGFX Generator 4.23.0. This file is only
  * generated once! Delete this file from your project and re-generate code
  * using STM32CubeMX or change this file manually to update it.
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

/* USER CODE BEGIN STM32TouchController */

#include <STM32TouchController.hpp>

#if defined(DISPLAY_TFT7)
extern "C" {
#include "../../Core/User/GT911/GT911.h"
}
#elif defined(DISPLAY_TFT10)
extern "C" {
#include "../../Core/User/FT5X06/ft5x06.h"
}
#endif


void STM32TouchController::init()
{
  /**
   * Initialize touch controller and driver
   */
#if defined(DISPLAY_TFT7)
  GT911_Init();
#elif defined(DISPLAY_TFT10)
  FT5X06_Init();
#endif
}

bool STM32TouchController::sampleTouch(int32_t& x, int32_t& y)
{
  /**
   * By default sampleTouch returns false,
   * return true if a touch has been detected, otherwise false.
   * Coordinates are passed to the caller by reference by x and y.
   * This function is called by the TouchGFX framework.
   * By default sampleTouch is called every tick, this can be adjusted by HAL::setTouchSampleRate(int8_t);
   */
#if defined(DISPLAY_TFT7)
  int8_t OnOff = 0;
  int32_t x_0 = 0;
  int32_t y_0 = 0;
  GT911_touchGFX(&x_0,&y_0, &OnOff);
  if(OnOff == 1){
    x = x_0;
    y = y_0;
    return true;
  }
  return false;
#elif defined(DISPLAY_TFT10)
  FT5X06_Dev dev = {0};
  FT5X06_ReadTouch(&dev);
  if(dev.Touch){
    x = dev.X;
    y = dev.Y;
    return true;
  }
  return false;
#endif
}



/* USER CODE END STM32TouchController */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
