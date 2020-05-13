#include "F405ControlBoard.hpp"

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
