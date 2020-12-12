#include "F405ControlBoard.hpp"

//TODO: 割り込み処理のRTOS化

int main(void)
{
    //ペリフェラルセットアップ
    //controlBoard->setupPeripheral();
    //インタフェースセットアップ
    //controlBoard->setupInterface();

    //sensor = new Sensor();
    //actuator = new Actuator();

    //タイマ割り込み開始
    //tim3.enableCount();
    //tim4.enableCount();

    while(1)
    {
        board->cycle();
        //control->cycle();
    }
}

//! 1ms割り込み
void interrupt_1ms(void)
{

}

#define INTERRUPT_PERIOD_SEC    0.01

//! 10ms割り込み
void interrupt_10ms(void)
{

}
