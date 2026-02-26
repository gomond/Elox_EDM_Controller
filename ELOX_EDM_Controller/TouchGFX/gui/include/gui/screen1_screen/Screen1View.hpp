#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    // Relay 1 is now used for servo direction
    virtual void toggleRelay1();
    // Relay 2 is used for ram lock
    virtual void toggleRelay2();
    virtual void toggleRelay3();
    // Relay 4 is now used for Servo Active or move
    virtual void toggleRelay4();
protected:

};

#endif // SCREEN1VIEW_HPP
