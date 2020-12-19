#pragma once
#include "../../../circuit/peripheral/GPIO.hpp"

class LimitSw
{
public:
    LimitSw(){};
    LimitSw(GPIO* gpio);
    LimitSw(GPIO* gpio, bool sign);
    ~LimitSw();
    void setup(GPIO* gpio);
    void setup(GPIO* gpio, bool sign);
    bool read(void);
private:
    GPIO* m_gpio;
    bool m_sign = true;
};
