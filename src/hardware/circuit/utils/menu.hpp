#pragma once
#include "menu_base.hpp"
#include "../F405ControlBoard.hpp"

extern const RotaryMenu Menu_Main;    //メインメニュー

class Menu : public MenuBase
{
public:
    Menu(){};
    ~Menu(){};

private:
    bool inputReturn(void);
    bool inputCancel(void);
    bool inputRight(void);
    bool inputLeft(void);

    void setCursorPos(uint16_t x, uint16_t y);
    //int printf(const char* format, ...);
    void showMenu(const RotaryMenu* menu, int cursor);
};
