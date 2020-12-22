#pragma once
#include <stdio.h>
#include <stdarg.h>

//場所　interface？
//せっかくCAN使ってるんだからデバッグとかデータ表示基板はそれで1枚ほしいよね
//制御基板とは分けたい
//ただデータ集めて出力だけする基板

//メニュー一覧
typedef struct
{
    const char title[20];   //項目名
    void (*func)(void);     //ジャンプ先関数
    //COLOR24 color;          //UserEncoderの色
}MenuList;

//メニューデータ
typedef struct 
{
    const char menuTitle[20];   //タイトル
    int listNumber;             //項目数
    const MenuList* menu;       //一覧
}RotaryMenu;



//void showRotaryMenu(const Menu* menu);
//
    //・USARTCOMで出力
    //・TFTに出力
    //・LCDに出力
    //→最低限に。たくさん出力は別基板に任せる
class MenuBase
{
public:
    MenuBase(){};
    virtual ~MenuBase(){};

    void showRotaryMenu(const RotaryMenu* menu);
    bool cycle(const RotaryMenu* menu);


private:
    virtual bool inputReturn(void) = 0;
    virtual bool inputCancel(void) = 0;
    virtual bool inputRight(void) = 0;
    virtual bool inputLeft(void) = 0;
    //virtual int printf(const char* format, ...) = 0;
    //virtual void setCursorPos(uint16_t x, uint16_t y) = 0;
    virtual void showMenu(const RotaryMenu* menu, int cursor) = 0;
};

