#pragma once
#include "hardware/peripheral/GPIO.hpp"

class LimitSw
{
public:
    bool read(void);
private:
    GPIO* gpio;

};
