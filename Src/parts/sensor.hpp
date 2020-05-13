#pragma once

#include <stdint.h>

#define ENC_NUM 16
#define POTENTIO_NUM    16
#define LIMITSW_NUM 16

class Sensor
{
public:
    Sensor();
    ~Sensor();

    void input(void);

    //Encoder* enc;
    //Potentio* potentio;
    //LimitSw* limitSw;


private:

};
