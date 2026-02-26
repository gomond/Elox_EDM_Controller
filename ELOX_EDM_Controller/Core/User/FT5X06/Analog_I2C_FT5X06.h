#ifndef ANALOG_I2C_FT5X06_H
#define ANALOG_I2C_FT5X06_H

#include <stdint.h>
#include "stm32h7xx_hal.h"

// Change this to your actual I2C handle
extern I2C_HandleTypeDef hi2c1;

uint8_t FT5X06_I2C_Read(uint8_t devAddr, uint8_t reg, uint8_t *data, uint16_t len);
uint8_t FT5X06_I2C_Write(uint8_t devAddr, uint8_t reg, uint8_t *data, uint16_t len);

#endif // ANALOG_I2C_FT5X06_H
