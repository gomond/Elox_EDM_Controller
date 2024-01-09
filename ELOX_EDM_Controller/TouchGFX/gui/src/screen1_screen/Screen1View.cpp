#include <gui/screen1_screen/Screen1View.hpp>
#include "gpio.h"

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

//void screenView::Cut_Interval_Change_Value()
//{
//	keyboard.setPosition(150,760,320,240);
//	keyboard.setVisible(true);  // Show keyboard
//	keyboard.invalidate();
//	OK.setVisible(true);
//	OK.invalidate();
//	KB_Exit.setVisible(true);
//	KB_Exit.invalidate();
//	textBox_ID = 1;
//
//}

//void Screen1View::
//{
//	HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_4 );
//}
