#pragma once
#include "GPIO.hpp"

class Button
{
public:
    Button(GPIO& gpio);
    ~Button(){};
    int read(void);

private:
    GPIO* m_gpio;
};
