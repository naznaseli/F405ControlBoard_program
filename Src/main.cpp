#include "F405ControlBoard.hpp"

F405ControlBoard* board;
//Controller* controller;

int main(void)
{
    //ペリフェラルセットアップ
    //controlBoard->setupPeripheral();
    //インタフェースセットアップ
    //controlBoard->setupInterface();

    //Sensor sensor();
    //Actuator actuator();

    //タイマ割り込み開始
    //tim3.enableCount();
    //tim4.enableCount();

    while(1)
    {
        board->cycle();
        //control->cycle();
    }
}

void interrupt_1ms(void)
{
    //多重割り込み禁止
    //ProtectInterrupt pi;

    board->interrupt_1ms();

}

void interrupt_10ms(void)
{

    board->interrupt_10ms();

    //センサ更新
    //sensor.input();

    //**********************************************************************
    //制御
    //**********************************************************************

    //アクチュエータ更新
    ////board->canOutput();
    //actuator.output();
}
