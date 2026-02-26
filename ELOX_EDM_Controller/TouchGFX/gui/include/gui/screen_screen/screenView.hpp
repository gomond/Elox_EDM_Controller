#ifndef SCREENVIEW_HPP
#define SCREENVIEW_HPP


#include <gui_generated/screen_screen/screenViewBase.hpp>
#include <gui/screen_screen/screenPresenter.hpp>
#include <gui/common/CustomKeyboard.hpp>

class screenView : public screenViewBase
{
public:
    screenView();
    virtual ~screenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
    virtual void Cut_Interval_Change_Value();
    virtual void Upper_Ram_Limit_Change_Value();
	virtual void Retract_Distance_Change_Value();
	virtual void Finish_Depth_Change_Value();
	//virtual void Update_Z_DRO_Value();
	virtual void OK_Pressed();
	virtual void Zero_Z_Encoder_Value();
protected:

	CustomKeyboard keyboard;
	int textBox_ID = 0;
};

#endif // SCREENVIEW_HPP
