#pragma once
#include "../../peripheral/GPIO.hpp"

class Button
{
public:
    Button(){};
    Button(GPIO* gpio, int sign = 1);
    ~Button(){};
    void setup(GPIO* gpio, int sign = 1);

    uint8_t read(void);

private:
    GPIO* m_gpio;
    int m_sign = 1;
};
