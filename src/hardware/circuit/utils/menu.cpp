#include "menu.hpp"
#include "../../machine/AmazingAdventureOfMecanumTheRide4A3S/interface.hpp"

#define SIZEOFARRAY(array) (sizeof(array)/sizeof((array)[0]))
#define INTERVAL_CNT    100

using namespace F405ControlBoard;
    //interface::clcd.printf(menu->menuTitle);
    //interface::clcd.line(1);
    //interface::clcd.printf(menu->menu[cursor].title);

void showCircuitMenu(void);

const MenuList List_Main[] =
{
    //{"CircuitMenu"      ,showCircuitMenu        ,{255,255,255}}
    {"Menu1"            ,showCircuitMenu        },
    {"Menu2"            ,showCircuitMenu        },
    {"Menu3"            ,showCircuitMenu        },
    {"CircuitMenu"      ,showCircuitMenu        }
};

const RotaryMenu Menu_Main =
{
    {'R', 'o', 'b', 'o', 'm', 'i', 'n', 't', 'o', 'n'},
    SIZEOFARRAY(List_Main),
    List_Main
};

bool Menu::inputReturn(void)
{
    static int interval = 0;
    if(!buttonPin[0].read())
    {
        if(interval == 0)
        {
            interval = INTERVAL_CNT;
            return true;
        }
    }
    else
    {
        if(interval > 0) interval--;
    }

    //if(/*psコン入力*/) return true;       //PSコン○
    //if() return true;     //ユーザエンコーダスイッチ
    return false;
}

bool Menu::inputCancel(void)
{
    static int interval = 0;
    if(!buttonPin[1].read())
    {
        if(interval == 0)
        {
            interval = INTERVAL_CNT;
            return true;
        }
    }
    else
    {
        if(interval > 0) interval--;
    }
    return false;
}

bool Menu::inputLeft(void)
{
    static int interval = 0;
    if(!buttonPin[2].read())
    {
        if(interval == 0)
        {
            interval = INTERVAL_CNT;
            return true;
        }
    }
    else
    {
        if(interval > 0) interval--;
    }

    //if(!buttonPin[2].read()) return true;   //タクトスイッチ緑
    //if() return true;     //psコン←
    //if() return true;     //ユーザエンコーダ反時計回り回転
    return false;
}

bool Menu::inputRight(void)
{
    static int interval = 0;
    if(!buttonPin[3].read())
    {
        if(interval == 0)
        {
            interval = INTERVAL_CNT;
            return true;
        }
    }
    else
    {
        if(interval > 0) interval--;
    }
    //if() return true;     //PSコン→
    //if() return true;     //ユーザエンコーダ時計回り回転
    return false;
}


//void Menu::setCursorPos(uint16_t x, uint16_t y)
//{
//    //clcd.cursor(x, y);
//}

//int Menu::printf(const char* format, ...)
//{
//    uart5.printf(format);
//}

//メニューを表示
void Menu::showMenu(const RotaryMenu* menu, int cursor)
{
    //clcd
    interface::clcd.line(0);
    interface::clcd.printf(menu->menuTitle);
    interface::clcd.line(1);
    interface::clcd.printf(menu->menu[cursor].title);

    //serial
    //uart4.printf("\033[2J");
    //uart4.printf("\033[2;H");
    //uart4.printf(menu->menu[cursor].title);
    //uart4.printf("\n------------------------------------------------");
    //for(int i = 0; i < 8; i++){
    //    if(i >= menu->listNumber)break;
    //    if((i+8) < menu->listNumber)
    //        uart4.printf("\033[%d;H%c%s\033[%d;25H%c%s", i+4, (cursor == i)? '>' : ' ', menu->menu[i].title, i+4, (enc_val == i+8)? '>' : ' ', menu->menu[i+8].title);
    //    else
    //        uart4.printf("\033[%d;H%c%s", i+4, (cursor == i)? '>' : ' ', menu->menu[i].title);
    //}
    //uart4.printf("\033[16;H");
    //uart4.printf(menu->menuTitle);
    //uart4.printf("\033[16;29H");
    //uart4.printf("[\033[31mR\033[39m:move on \033[34mB\033[39m:return]");
}
