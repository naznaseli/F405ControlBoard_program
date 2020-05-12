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

class Encoder
{
public:
    uint16_t read(void);
    void set(uint16_t count);
    void reset(void);

};

class Potentio
{
public:
    uint16_t read(void);
    
};

class LimitSw
{
public:
    bool read(void);

};
