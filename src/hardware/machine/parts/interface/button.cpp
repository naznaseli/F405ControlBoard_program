#include "button.hpp"
#include <stdio.h>

Button::Button(GPIO* gpio, int sign)
{
    setup(gpio, sign);
}

Button::~Button()
{
    m_gpio = NULL;
}

void Button::setup(GPIO* gpio, int sign)
{
    m_gpio = gpio;
    m_sign = sign;
}

uint8_t Button::read(void)
{
    uint8_t ret = m_gpio->read();;
    if(m_sign == 1) return ret;
    else return !ret;
}
