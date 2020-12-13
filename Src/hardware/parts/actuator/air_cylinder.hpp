#pragma once
#include "hardware/peripheral/GPIO.hpp"

//01エアシリンダ
//ローカル/通信(CANとか)対応
class AirCylinder
{
public:
    AirCylinder();
    ~AirCylinder();
    void open(void);
    void close(void);
private:
    GPIO* gpio;

};
