#pragma once

#include <stdint.h>

//MD基板内部のクラスと併用
class Motor
{
public:
    enum Mode
    {
        Local, CAN
    };
    Motor();
    Motor(Mode mode);
    ~Motor();
    void setup();

    void setPwm();
    void getPwm();
    void free();

private:
    double pwm;
    uint16_t pos;

};