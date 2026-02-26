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
//	textBox_ID = 1;
//
//}

// Relay 1 is now used for servo direction
void Screen1View::toggleRelay1()
{
	// Toggle servo direction relay
	HAL_GPIO_TogglePin(Relay1_GPIO_Port,Relay1_Pin );
}

// Relay 2 is used for ram lock (causes ram to jolt when active/released)
void Screen1View::toggleRelay2()
{
	// Toggle ram lock relay
	HAL_GPIO_TogglePin(Relay2_GPIO_Port,Relay2_Pin );
}

void Screen1View::toggleRelay3()
{
	HAL_GPIO_TogglePin(Relay3_GPIO_Port,Relay3_Pin );
}

// Relay 4 is now used for Servo Active or move
void Screen1View::toggleRelay4()
{
	// Toggle Servo Active relay
	HAL_GPIO_TogglePin(Relay4_GPIO_Port,Relay4_Pin );
}
