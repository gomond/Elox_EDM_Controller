#include <gui/screen_screen/screenView.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <touchgfx/Color.hpp>
#include <touchgfx/Unicode.hpp>

#include "tim.h"

static uint32_t counter = 0;

screenView::screenView()
{
	keyboard.setPosition (80, 16, 320, 240);
	add(keyboard);
	keyboard.setVisible(false);
	keyboard.invalidate();
}

void screenView::setupScreen()
{
    screenViewBase::setupScreen();
}

void screenView::tearDownScreen()
{
    screenViewBase::tearDownScreen();
}

void screenView::handleTickEvent()
{
	counter = __HAL_TIM_GET_COUNTER(&htim3);
	Unicode::snprintf(Current_Live_Position_TextBuffer,CURRENT_LIVE_POSITION_TEXT_SIZE ,"%d",counter/2);
	Current_Live_Position_Text.invalidate();

}

void screenView::Cut_Interval_Change_Value()
{
	keyboard.setPosition(150,760,320,240);
	keyboard.setVisible(true);  // Show keyboard
	keyboard.invalidate();
	OK.setVisible(true);
	OK.invalidate();
	KB_Exit.setVisible(true);
	KB_Exit.invalidate();
	textBox_ID = 1;

}

void screenView::Upper_Ram_Limit_Change_Value()
{
	keyboard.setPosition(150,760,320,240);
	keyboard.setVisible(true);  // Show keyboard
	keyboard.invalidate();
	OK.setVisible(true);
	OK.invalidate();
	KB_Exit.setVisible(true);
	KB_Exit.invalidate();
	textBox_ID = 2;
}

void screenView::Retract_Distance_Change_Value()
{
	keyboard.setPosition(150,760,320,240);
	keyboard.setVisible(true);  // Show keyboard
	keyboard.invalidate();
	OK.setVisible(true);
	OK.invalidate();
	KB_Exit.setVisible(true);
	KB_Exit.invalidate();
	textBox_ID = 3;
}

void screenView::Finish_Depth_Change_Value()
{
	keyboard.setPosition(150,760,320,240);
	keyboard.setVisible(true);  // Show keyboard
	keyboard.invalidate();
	OK.setVisible(true);
	OK.invalidate();
	KB_Exit.setVisible(true);
	KB_Exit.invalidate();
	textBox_ID = 4;
}


void screenView::KB_Exit_Pressed()
{
	keyboard.setVisible(false);  // Hide keyboard
	keyboard.invalidate();
	OK.setVisible(false);
	OK.invalidate();
	KB_Exit.setVisible(false);
	KB_Exit.invalidate();
	textBox_ID = 0;
}

void screenView::OK_Pressed()
{
	keyboard.setVisible(false);  // Hide keyboard
	keyboard.invalidate();
	OK.setVisible(false);
	OK.invalidate();
	KB_Exit.setVisible(false);
	KB_Exit.invalidate();

	switch (textBox_ID) {
		case 1:
			Unicode::strncpy(Cut_Interval_TextBuffer, keyboard.getBuffer(), 10);
			Cut_Interval_Text.invalidate();
			break;
		case 2:
			Unicode::strncpy(Upper_Ram_limit_TextBuffer, keyboard.getBuffer(), 10);
			Upper_Ram_limit_Text.invalidate();
			break;
		case 3:
			Unicode::strncpy(Retract_Distance_TextBuffer, keyboard.getBuffer(), 10);
			Retract_Distance_Text.invalidate();
			break;
		case 4:
			Unicode::strncpy(Finish_Depth_TextBuffer, keyboard.getBuffer(), 10);
			Finish_Depth_Text.invalidate();
			break;
		default:
			break;
	}
	keyboard.clearBuffer();
}

void screenView::Zero_Z_Encoder_Value()
{
	HAL_TIM_Encoder_Stop_IT(&htim3, TIM_CHANNEL_ALL);
	//HAL_TIM_Encoder_Init(&htim3, &sConfig);
	MX_TIM3_Init();
	HAL_TIM_Encoder_Start_IT(&htim3,TIM_CHANNEL_ALL);
}



