/*****************************************************************************
* | File      	:   GT911.c
* | Author      :   Waveshare team
* | Function    :   GT911 driver
* | Info        :
*               GT911 driver and data processing
*----------------
* |	This version:   V1.0
* | Date        :   2019-3-5
* | Info        :

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#include "GT911.h"


UWORD x[CT_MAX_TOUCH] = {0}, y[CT_MAX_TOUCH] = {0}, z=0;
UWORD temp=0;
GT911_Dev Dev_Now,Dev_Backup;

/******************************************************************************
function:	GT911 reset
******************************************************************************/
static void GT911_Reset()
{
	GPIO_InitTypeDef GPIO_InitStruct;

	DEV_Set_GPIOMode(DEV_INT_PIN, 0);
	
	HAL_GPIO_WritePin(DEV_RST_PIN, GPIO_PIN_RESET);    
	DEV_Delay_ms(100);
	HAL_GPIO_WritePin(DEV_INT_PIN, GPIO_PIN_RESET);    
	DEV_Delay_ms(100);
	HAL_GPIO_WritePin(DEV_RST_PIN, GPIO_PIN_SET);    
	DEV_Delay_ms(200);
	
	GPIO_InitStruct.Pin = INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(INT_GPIO_Port, &GPIO_InitStruct);
	
	DEV_Delay_ms(100);
}

/******************************************************************************
function:	Write data to the GT911 register
parameter:
    reg   :   Register address
		buf		��	Data to send
		len		��	Length of data sent
******************************************************************************/
static uint8_t GT911_WR_Reg(uint16_t reg,uint8_t *buf,uint8_t len)
{
	uint8_t i;
	uint8_t ret=0;
	I2C_Start();	
  I2C_Send_Byte(CT_CMD_WR);   
	I2C_Wait_Ack();
	I2C_Send_Byte(reg>>8);   	
	I2C_Wait_Ack(); 	 										  		   
	I2C_Send_Byte(reg&0XFF);   	
	I2C_Wait_Ack();  
	for(i=0;i<len;i++)
	{	   
    I2C_Send_Byte(buf[i]);  
		ret=I2C_Wait_Ack();
		if(ret)break;  
	}
  I2C_Stop();					
	return ret; 
}

/******************************************************************************
function:	Read data from the GT911 register
parameter:
    reg   :   Register address
		buf		��	Read data
		len		��	Read the length of the data
******************************************************************************/
static void GT911_RD_Reg(uint16_t reg,uint8_t *buf,uint8_t len)
{
	uint8_t i;
 	I2C_Start();	
 	I2C_Send_Byte(CT_CMD_WR);  
	I2C_Wait_Ack();
 	I2C_Send_Byte(reg>>8);   
	I2C_Wait_Ack(); 	 										  		   
 	I2C_Send_Byte(reg&0XFF);   	
	I2C_Wait_Ack();  
 	I2C_Stop();  
	
 	I2C_Start();  	 	   
	I2C_Send_Byte(CT_CMD_RD);     
	I2C_Wait_Ack();	   
	for(i=0;i<len;i++)
	{	   
		buf[i]=I2C_Read_Byte(i==(len-1)?0:1); 
	} 
  I2C_Stop();   
}

/******************************************************************************
function:	Read the ID of the GT911
******************************************************************************/
static uint8_t GT911_Read_ID(void)
{
	uint8_t buf[4];
	GT911_RD_Reg(GT911_PRODUCT_ID_REG, (uint8_t *)&buf[0], 3);
	GT911_RD_Reg(GT911_CONFIG_REG, (uint8_t *)&buf[3], 1);
	printf("TouchPad_ID:%c,%c,%c\r\nTouchPad_Config_Version:%2x\r\n",buf[0],buf[1],buf[2],buf[3]);
	return buf[3];
}

/******************************************************************************
function:	Read the firmware version of the GT911
******************************************************************************/
static uint16_t GT911_Read_FirmwareVersion(void)
{
	uint8_t buf[2];

	GT911_RD_Reg(GT911_FIRMWARE_VERSION_REG, buf, 2);

	printf("FirmwareVersion:%2x\r\n",(((uint16_t)buf[1] << 8) + buf[0]));
	return ((uint16_t)buf[1] << 8) + buf[0];
}

/******************************************************************************
function:	Read the firmware version of the GT911
******************************************************************************/


void GT911_Init(void)
{
	printf("GT911_Init\r\n");
	GT911_Reset();
	GT911_Read_ID();
	GT911_Read_FirmwareVersion();
}

void GT911_touchGFX(int32_t *x_0, int32_t  *y_0, int8_t *touchOnOff)
{
	uint8_t buf[41];
    uint8_t Clearbuf = 0;
	uint8_t i;

	//Determine if the interruption is generated
	if (Dev_Now.Touch == 1)
	{

		GT911_RD_Reg(GT911_READ_XY_REG, buf, 1);

		if ((buf[0]&0x80) == 0x00)
		{
			GT911_WR_Reg(GT911_READ_XY_REG, (uint8_t *)&Clearbuf, 1);
			DEV_Delay_ms(10);
		}
		else
		{
			Dev_Now.TouchpointFlag = buf[0];
			Dev_Now.TouchCount = buf[0]&0x0f;
			if (Dev_Now.TouchCount > 5 || Dev_Now.TouchCount  == 0)
			{
				GT911_WR_Reg(GT911_READ_XY_REG, (uint8_t *)&Clearbuf, 1);
				Dev_Now.Touch = 0;
				return ;
			}

			if(temp < 5){//Prevent misjudgment
				temp = 1 + temp;
				if(temp == 4)
					Dev_Now.Touch = 0;
				return;
			}

			GT911_RD_Reg(GT911_READ_XY_REG+1, &buf[1], Dev_Now.TouchCount*8);
			GT911_WR_Reg(GT911_READ_XY_REG, (uint8_t *)&Clearbuf, 1);

			Dev_Now.Touchkeytrackid[0] = buf[1];
			Dev_Now.X[0] = ((uint16_t)buf[3] << 8) + buf[2];
			Dev_Now.Y[0] = ((uint16_t)buf[5] << 8) + buf[4];
			Dev_Now.S[0] = ((uint16_t)buf[7] << 8) + buf[6];
			//Get coordinates and display coordinates
			*x_0  = Dev_Now.X[0];
			*y_0  = Dev_Now.Y[0];
			z = Dev_Now.TouchCount;
			*touchOnOff = 0x1;
		}
		Dev_Now.Touch = 0;

	}
	else
	{
		*touchOnOff = 0x0;
	}


}
