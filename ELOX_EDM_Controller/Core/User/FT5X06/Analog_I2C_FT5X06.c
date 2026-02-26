#include "Analog_I2C_FT5X06.h"

uint8_t FT5X06_I2C_Read(uint8_t devAddr, uint8_t reg, uint8_t *data, uint16_t len) {
    if (HAL_I2C_Mem_Read(&hi2c1, devAddr << 1, reg, I2C_MEMADD_SIZE_8BIT, data, len, 100) == HAL_OK) {
        return 0;
    }
    return 1;
}

uint8_t FT5X06_I2C_Write(uint8_t devAddr, uint8_t reg, uint8_t *data, uint16_t len) {
    if (HAL_I2C_Mem_Write(&hi2c1, devAddr << 1, reg, I2C_MEMADD_SIZE_8BIT, data, len, 100) == HAL_OK) {
        return 0;
    }
    return 1;
}
