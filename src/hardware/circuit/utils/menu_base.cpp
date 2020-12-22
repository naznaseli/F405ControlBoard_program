#include "menu_base.hpp"
#include "delay.hpp"
#include "../F405ControlBoard.hpp"

//表示のポリモーフィズム
bool MenuBase::cycle(const RotaryMenu* menu)
{
    //int cursorNow = 0, cursorOld = 0;
    static int cursor = 0;
    static bool show = true;
    static bool jump = false;

    if(inputLeft() && !show && !jump)
    {
        //前
        cursor = (cursor+menu->listNumber-1) % menu->listNumber;
        show = true;
    }
    if(inputRight() && !show && !jump)
    {
        //次
        cursor = (cursor+menu->listNumber+1) % menu->listNumber;
        show = true;
    }
    if(inputReturn() && !show && !jump)
    {
        //決定
        menu->menu[cursor].func();    //指定関数へジャンプ
        jump = true;
        //show = true;
    }
    if(inputCancel() && !show && !jump)
    {
        //キャンセル
        return true;
    }
    if(show)
    {
        showMenu(menu, cursor);
        show = false;
    }
    return false;
    //while(inputReturn() || inputCancel() || inputLeft() || inputRight());
    //delay_ms(10);
}

//表示のポリモーフィズム
void MenuBase::showRotaryMenu(const RotaryMenu* menu)
{
    //UserEncoder enc(0, menu->listNumber-1, 0, true);
    //int encVal = enc.calc();
    //int encVal_old = encVal;
    //setEncoderColor(&(menu->menu[encVal_old]).color);

    //int cursorNow = 0, cursorOld = 0;
    int cursor = 0;
    bool show = false;

    showMenu(menu, cursor);
    while(inputReturn() || inputCancel() || inputLeft() || inputRight());

    while(1)
    {
        if(inputLeft())
        {
            //前
            cursor = (cursor--) % menu->listNumber;
            show = true;
        }
        if(inputRight())
        {
            //次
            cursor = (cursor++) % menu->listNumber;
            show = true;
        }
        if(inputReturn())
        {
            //決定
            menu->menu[cursor].func();    //指定関数へジャンプ
            show = true;
        }
        if(inputCancel())
        {
            //キャンセル
            return;
        }
        if(show)
        {
            showMenu(menu, cursor);
            show = false;
        }
        while(inputReturn() || inputCancel() || inputLeft() || inputRight());
        delay_ms(10);
    }
}


//bool Menu::inputReturn(void)
//{
//    button[0].read();
//}
//
////表示のポリモーフィズム
//void Menu::showRotaryMenu(const Menu* menu)
//{
//    UserEncoder enc(0, menu->listNumber-1, 0, true);
//    int encVal = enc.calc();
//    int encVal_old = encVal;
//    setEncoderColor(&(menu->menu[encVal_old]).color);
//    clcd.line(0);
//    clcd.printf(menu->menuTitle);   //タイトル表示
//    clcd.line(1);
//    clcd.printf(menu->menu[encVal_old].title);   //項目表示
//
//    while(button[0].read() || button[1].read() || button[2].read() || button[3].read());
//
//    while(1)
//    {
//        encVal = enc.calc();
//        if(button[2].read())
//        {
//            //前
//
//        }
//        if(button[3].read())
//        {
//            //次
//
//        }
//        if(button[0].read())
//        {
//            //決定
//            setEncoderColor(&COLOR24_BLACK);
//            menu->menu[encVal_old].func();    //指定関数へジャンプ
//
//            enc.resetDiff();
//            setEncoderColor(&(menu->menu[encVal_old]).color);
//            clcd.line(0);
//            clcd.printf(menu->menuTitle);
//            clcd.line(1);
//            clcd.printf(menu->menu[encVal_old].title);
//            while(button[0].read() || button[1].read() || button[2].read() || button[3].read());
//        }
//        if(button[1].read())
//        {
//            //キャンセル
//            return;
//        }
//        delay_ms(10);
//    }
//