#pragma once
#include "menu_base.hpp"
#include "../F405ControlBoard.hpp"
#include "serial.hpp"
#include "../../machine/AmazingAdventureOfMecanumTheRide4A3S/interface.hpp"

extern const RotaryMenu Menu_Main;    //メインメニュー

class Menu : public MenuBase
{
private:
    Menu(){};
    //Menu(Serial* serial)
    //{
    //    m_serial = serial;
    //};
    ~Menu(){};
    static Menu m_instance;
public:
    static Menu* getInstance(void)
    {
        //setSerial(interface::pcDebug);
        return &m_instance;
    }
    //void setSerial(Serial* serial);

private:
    bool inputSelect(void);
    bool inputCancel(void);
    bool inputRight(void);
    bool inputLeft(void);

    void showMenu(const RotaryMenu* menu, int cursor);

    //for Serial
    void showMenuFrameForSerial(void);
    
};
