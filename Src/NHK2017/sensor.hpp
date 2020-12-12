#pragma once

#define ENCODER_NUM 12  //足回り4+上下+
#define POTENTIO_NUM    1   //上下
//#define LIMIT_NUM

//自基板か通信基板か
typedef enum
{
    Self, CAN, USART, SPI, I2C
}sensorType;

//センサのポリモーフィズム実現
//実基板から直接読み取るもの
//通信で取得するもの
//いろいろあるものをまとめて制御班にわたす
//シングルトン？
class Sensor
{
public:

    Sensor();

    void update_1ms(void);
    void update_10ms(void);

private:
    Encoder* encoder;
    Potentio* potentio;
    LimitSw* limitSw;

};
