#include "sensor.hpp"

namespace sensor
{
void update(void)
{
    for(int i = 0; i < ENCODER_NUM; i++)
    {
        encoder[i].update();
    }
    for(int i = 0; i < POTENTIO_NUM; i++)
    {
        potentio[i].update();
    }
    for(int i = 0; i < LIMITSW_NUM; i++)
    {
        limitSw[i].update();
    }

    mpu6050.update();
    sixaxis3.update();
}

}//namespace
