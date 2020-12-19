#include "./hardware/circuit/F405ControlBoard.hpp"
#include "./hardware/circuit/function/delay.hpp"
#include <stddef.h>
//#include "machine.hpp"

//TODO: 割り込み処理のRTOS化
//THINK: タイムスタンプほしいな

int main(void)
{
    //ペリフェラルセットアップ
    F405ControlBoard::getInstance()->setup();
    //F405ControlBoard::getInstance()->setupInterface();

    //ledPin[0].write(1);
    ledPin[1].write(1);
    ////delay_ms(1000);
    //F405ControlBoard::getInstance()->delay_ms(1000);
    ////buzzerPin.write(1);
    ////buzzer.write(1);
    //ledPin[0].write(0);
    ledPin[1].write(0);
    //buzzer.write(0);

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

        //if(buttonPin[0].read()) ledPin[0].write(1);
        //else ledPin[0].write(0);
        //if(buttonPin[1].read()) ledPin[1].write(1);
        //else ledPin[1].write(0);
        //if(buttonPin[2].read()) ledPin[2].write(1);
        //else ledPin[2].write(0);
        //if(buttonPin[3].read()) ledPin[3].write(1);
        //else ledPin[3].write(0);

        //目標値反映
        //can送信、local反映
        //actuator::update();

    }
}

//! 1ms割り込み
void interrupt_1ms(void)
{
    F405ControlBoard::getInstance()->interrupt_1ms();

    static int cnt = 0;
    if(++cnt >= 100)
    {
        cnt = 0;
        ledPin[2].toggle();
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
        ledPin[3].toggle();
    }

    //目標値変更
    //制御こ↑こ↓

}
