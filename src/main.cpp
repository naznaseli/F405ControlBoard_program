#include "./hardware/F405ControlBoard.hpp"
#include <stddef.h>
//#include "machine.hpp"

//TODO: 割り込み処理のRTOS化
//THINK: タイムスタンプほしいな

int main(void)
{
    //ペリフェラルセットアップ
    F405ControlBoard::getInstance()->setupPeripheral();
    F405ControlBoard::getInstance()->setupInterface();

    led[0].write(1);
    led[1].write(1);
    led[2].write(1);
    led[3].write(1);
    //buzzerPin.write(1);
    buzzer.write(1);
    for(int i = 0; i < 100000; i++);
    for(int i = 0; i < 100000; i++);
    for(int i = 0; i < 100000; i++);
    for(int i = 0; i < 100000; i++);
    for(int i = 0; i < 100000; i++);
    led[0].write(1);
    led[1].write(1);
    led[2].write(1);
    led[3].write(1);
    buzzer.write(0);

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
        F405ControlBoard::getInstance()->cycle();

        if(button[0].read()) led[0].write(1);
        else led[0].write(0);
        if(button[1].read()) led[1].write(1);
        else led[1].write(0);
        if(button[2].read()) led[2].write(1);
        else led[2].write(0);
        if(button[3].read()) led[3].write(1);
        else led[3].write(0);

        //目標値反映
        //can送信、local反映
        //actuator::update();

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
    //sensor::update();

    //Machine::getInstance()->update();


    //目標値変更
    //制御こ↑こ↓

}
