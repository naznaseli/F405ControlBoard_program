#pragma once

#define ENCODER_NUM     7   //接地2輪、タイヤ4輪、Zスライダ
#define POTENTIO_NUM    1   //Zスライダ
#define LIMITSW_NUM     2   //Zスライダ上下

namespace sensor
{
Encoder encoder[ENCODER_NUM];
Potentio potentio[POTENTIO_NUM];
LimitSw limitSw[LIMITSW_NUM];
Imu mpu6050;
Controller sixaxis3;

}
