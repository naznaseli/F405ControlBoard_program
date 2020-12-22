#include "menu_base.hpp"
#include "delay.hpp"
#include "../F405ControlBoard.hpp"

int MenuBase::m_recursion = 0;

//表示のポリモーフィズム
bool MenuBase::cycle(const RotaryMenu* menu)
{
    static int cursor[3] = {0};
    static bool show[3] = {true, true, true};
    static bool jump[3] = {false, false, false};

    if(!show[m_recursion] && !jump[m_recursion])
    {
        if(inputSelect())
        {
            //決定
            //F405ControlBoard::uart5.printf("return\n");
            jump[m_recursion] = true;
        }
        if(inputCancel())
        {
            //キャンセル
            //F405ControlBoard::uart5.printf("cancel\n");
            show[m_recursion] = true;   //次戻ってきたとき再表示するため
            return true;
        }
        if(inputLeft())
        {
            //前
            //F405ControlBoard::uart5.printf("left\n");
            cursor[m_recursion] = (cursor[m_recursion] + menu->listNumber - 1) % menu->listNumber;
            show[m_recursion] = true;
        }
        if(inputRight())
        {
            //次
            //F405ControlBoard::uart5.printf("right\n");
            cursor[m_recursion] = (cursor[m_recursion] + menu->listNumber + 1) % menu->listNumber;
            show[m_recursion] = true;
        }
    }

    if(jump[m_recursion])
    {
        m_recursion++;
        bool ret = menu->menu[cursor[m_recursion-1]].func();    //指定関数へジャンプ
        m_recursion--;
        if(ret)
        {
            jump[m_recursion] = false;
            show[m_recursion] = true;
        }
    }
    if(show[m_recursion])
    {
        showMenu(menu, cursor[m_recursion]);
        show[m_recursion] = false;
    }
    return false;
}
