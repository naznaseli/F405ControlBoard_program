#include "F405ControlBoard.hpp"

//TODO: 割り込み処理のRTOS化
//THINK: タイムスタンプほしいな

int main(void)
{
    //ペリフェラルセットアップ
    //controlBoard->setupPeripheral();
    //インタフェースセットアップ
    //controlBoard->setupInterface();

    //ここシングルトン
    //sensor = new Sensor();
    //actuator = new Actuator();

    //タイマ割り込み開始
    //tim3.enableCount();
    //tim4.enableCount();

    while(1)
    {
        board->cycle();
        //control->cycle();

        //目標値反映
        //can送信
    }
}

//! 1ms割り込み
void interrupt_1ms(void)
{
    //シングルトン
    //ローカル/更新頻度高いセンサ更新
    //sensor.update_1ms();

    //ローカルのアクチュエータ/更新頻度高いアクチュエータ更新
    //actuator.update_1ms();

    //コントローラ更新

}

#define INTERRUPT_PERIOD_SEC    0.01

//! 10ms割り込み
void interrupt_10ms(void)
{
    //sensor.update_10ms();
    //actuator.update_10ms();

    //コントローラ読み取り

    //目標値変更
    //制御こ↑こ↓

}
