#pragma once
#include "../../circuit/F405ControlBoard.hpp"
#include "../parts/sensor/encoder.hpp"
#include "../parts/sensor/limit_sw.hpp"

#define ENCODER_NUM 7
#define LIMITSW_NUM 4

namespace sensor
{
extern Encoder encoder[ENCODER_NUM];
//Potentio* potentio;
extern LimitSw limitSw[LIMITSW_NUM];
//extern Imu* mpu9250;
//extern Controller* sixaxis3;

void update(void);
void setup(void);

}//namespace
