/*
/****************************************Copyright (c)****************************************************
**                                      
**                        http://www.powermcu.com & http://www.hotmcu.com
**
**--------------File Info---------------------------------------------------------------------------------
*/
#warning "Including FT5X06 header: checking typedef visibility"
#ifndef FT5X06_DEV_TYPEDEF_CHECK
#define FT5X06_DEV_TYPEDEF_CHECK
#endif
#ifndef FT5X06_H
#define FT5X06_H

#include <stdint.h>


extern struct event ts_event; 
extern int touch_type;

int ft5x0x_read_data(void);
void touchpanel_init(void);


typedef struct {
	uint8_t Touch;
	uint16_t X;
	uint16_t Y;
	uint8_t Event;
} FT5X06_Dev;

extern volatile FT5X06_Dev FT5X06_Dev_Now;

void FT5X06_Init(void);
void FT5X06_ReadTouch(FT5X06_Dev *dev);


void ft5x0x_report_value(void);

#endif // FT5X06_H

/************************ (C) COPYRIGHT HAOYU Electronics *****END OF FILE****/
