#include "./hardware/circuit/F405ControlBoard.hpp"
#include "./hardware/circuit/function/delay.hpp"
#include "./hardware/machine/AmazingAdventureOfMecanumTheRide4A3S/interface.hpp"
#include "./hardware/machine/AmazingAdventureOfMecanumTheRide4A3S/sensor.hpp"
#include <stddef.h>

//TODO: 割り込み処理のRTOS化
//THINK: タイムスタンプほしいな

using namespace interface;

int main(void)
{
    //ペリフェラルセットアップ
    F405ControlBoard::setup();

    interface::setup();
    sensor::setup();
    //actuator::setup();

    led[1].write(1);
    //F405ControlBoard::delay_ms(500);
    delay_ms(500);
    led[1].write(0);

    clcd.cursor(0, 0);
    clcd.printf("test");

    buzzer.beep(30);

    while(1)
    {
        F405ControlBoard::cycle();

        if(button[0].read()) led[0].write(1);
        else led[0].write(0);
        if(button[1].read()) led[1].write(1);
        else led[1].write(0);

        //目標値反映
        //can送信、local反映
        //actuator::update();
    }
}

//! 1ms割り込み
void interrupt_1ms(void)
{
    F405ControlBoard::interrupt_1ms();

    static int cnt1 = 0;
    if(++cnt1 >= 100)
    {
        cnt1 = 0;
        led[2].toggle();
    }
}

//! 10ms割り込み
void interrupt_10ms(void)
{
    //sensor::update();

    //Machine::getInstance()->update();

    static int cnt2 = 0;
    if(++cnt2 >= 10)
    {
        cnt2 = 0;
        led[3].toggle();
    }

    //目標値変更
    //制御こ↑こ↓

}
