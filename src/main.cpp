#include "./hardware/circuit/F405ControlBoard.hpp"
#include "./hardware/circuit/utils/delay.hpp"
#include "./hardware/machine/AmazingAdventureOfMecanumTheRide4A3S/interface.hpp"
#include "./hardware/machine/AmazingAdventureOfMecanumTheRide4A3S/sensor.hpp"
#include <stdio.h>

//TODO: 割り込み処理のRTOS化
//THINK: タイムスタンプほしいな

//int __io_putchar(int ch)
//{
//    return (F405ControlBoard::uart5._putchar(ch));
//}
//
//int __io_getchar(void)
//{
//
//}

using namespace interface;

int main(void)
{
    //ペリフェラルセットアップ
    F405ControlBoard::setup();

    setbuf(stdout, NULL);

    interface::setup();
    sensor::setup();
    //actuator::setup();

    led[1].write(1);
    delay_ms(500);
    led[1].write(0);

    clcd.cursor(0, 0);
    clcd.printf("F405ControlBoard");

    buzzer.beep(30);
    F405ControlBoard::uart5.printf("F405ControlBoard\n");
    F405ControlBoard::uart4.printf("F405ControlBoard\n");
    F405ControlBoard::uart5.printf("%f\n", 1.234);
    setbuf(stdout, NULL);
    printf("f405");

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
