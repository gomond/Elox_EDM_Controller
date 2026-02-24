/* USER CODE BEGIN Header */
/* USER CODE END Header */

#include <TouchGFXHAL.hpp>

/* USER CODE BEGIN TouchGFXHAL.cpp */
void TouchGFXHAL::initialize()
{
	TouchGFXGeneratedHAL::initialize();
}

void TouchGFXHAL::disableInterrupts()
{
	TouchGFXGeneratedHAL::disableInterrupts();
}

void TouchGFXHAL::enableInterrupts()
{
	TouchGFXGeneratedHAL::enableInterrupts();
}

void TouchGFXHAL::configureInterrupts()
{
	TouchGFXGeneratedHAL::configureInterrupts();
}

void TouchGFXHAL::enableLCDControllerInterrupt()
{
	TouchGFXGeneratedHAL::enableLCDControllerInterrupt();
}

void TouchGFXHAL::flushFrameBuffer(const touchgfx::Rect& rect)
{
	TouchGFXGeneratedHAL::flushFrameBuffer(rect);
}

bool TouchGFXHAL::blockCopy(void* RESTRICT dest, const void* RESTRICT src, uint32_t numBytes)
{
	return TouchGFXGeneratedHAL::blockCopy(dest, src, numBytes);
}

uint16_t* TouchGFXHAL::getTFTFrameBuffer() const
{
	return TouchGFXGeneratedHAL::getTFTFrameBuffer();
}

void TouchGFXHAL::setTFTFrameBuffer(uint16_t* adr)
{
	TouchGFXGeneratedHAL::setTFTFrameBuffer(adr);
}
/* USER CODE END TouchGFXHAL.cpp */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
