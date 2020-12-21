#include "menu.hpp"

//const MenuList main[] =
//{
//    {"Circuit Menu",        CircuitMenu,    {255, 255, 255}},
//};

#define SIZEOFARRAY(array) (sizeof(array)/sizeof((array)[0]))

//const ManuList List_Main[] =
//{
//    {"CircuitMenu"      ,showCircuitMenu        ,{255,255,255}}
//};

//const Menu Menu_Main =
//{
//    {"Robominton"},
//    SIZEOFARRAY(List_Main),
//    List_Main
//};

//表示のポリモーフィズム
//void showRotaryMenu(const Menu* menu)
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
//}

void showCircuitMenu(void)
{

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