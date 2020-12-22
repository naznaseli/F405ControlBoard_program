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
    bool (*func)(void);     //ジャンプ先関数
    //COLOR24 color;          //UserEncoderの色
}MenuList;

//メニューデータ
typedef struct 
{
    const char menuTitle[20];   //タイトル
    int listNumber;             //項目数
    const MenuList* menu;       //一覧
}RotaryMenu;

class MenuBase
{
public:
    MenuBase(){};
    virtual ~MenuBase(){};

    void showRotaryMenu(const RotaryMenu* menu);
    bool cycle(const RotaryMenu* menu);

protected:
    static int m_recursion;
private:
    virtual void update(void) = 0;
    virtual bool inputSelect(void) = 0;
    virtual bool inputCancel(void) = 0;
    virtual bool inputRight(void) = 0;
    virtual bool inputLeft(void) = 0;
    virtual void showMenu(const RotaryMenu* menu, int cursor) = 0;
};

