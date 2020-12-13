#include "hardware/F405ControlBoard.hpp"
#include "machine.hpp"

//TODO: 割り込み処理のRTOS化
//THINK: タイムスタンプほしいな


int main(void)
{
    //ペリフェラルセットアップ
    //controlBoard->setupPeripheral();
    //インタフェースセットアップ
    //controlBoard->setupInterface();
    //sixaxis3 = new Sixaxis(&usart4);
    //mpu6050 = new Gyro(&usart3, IMU_TYPE_MPU6050);

    //ここシングルトン
    //sensor = new Sensor();
    //actuator = new Actuator();

    //タイマ割り込み開始
    //tim3.enableCount();
    //tim4.enableCount();

    while(1)
    {
        board->cycle();

        //目標値反映
        //can送信、local反映
        actuator::update();
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
}

//! 10ms割り込み
void interrupt_10ms(void)
{
    sensor::update();


    //目標値変更
    //制御こ↑こ↓

}
