#include "sensor.hpp"

namespace sensor
{
Encoder encoder[ENCODER_NUM];
//Potentio potentio;
LimitSw limitSw[LIMITSW_NUM];
//Imu* mpu9250;
//Controller* sixaxis3;

void setup(void)
{
    encoder[0].setup(&tim4);
    encoder[1].setup(&tim3);
    //encoder[2]->setup(can0, 0x110, 8);
    //encoder[3]->setup(can0, 0x110, 8);
    //encoder[4]->setup(can0, 0x110, 8);
    //encoder[5]->setup(can0, 0x110, 8);
    //encoder[6]->setup(can0, 0x110, 8);
    //potentio = new Potentio[1];
    //potentio[0]->setup(adc12);
    limitSw[0].setup(&limitSwPin[0]);
    limitSw[1].setup(&limitSwPin[1]);
    //mpu9250 = new Imu(&usart3, ImuType::MPU9250);

}

//void delete(void)
//{
//    //delete[] encoder;
//    //delete[] potentio;
//    //delete[] limitSw;
//
//}

void update(void)
{
    //for(int i = 0; i < ENCODER_NUM; i++) encoder[i].update();
    //for(int i = 0; i < POTENTIO_NUM; i++) potentio[i].update();
    //for(int i = 0; i < LIMITSW_NUM; i++) limitSw[i].update();
    //mpu9250->update();
    //sixaxis3->update();

}

}
