#include "led.hpp"

 Led::Led(GPIO* gpio)
 {
     setup(gpio);
 }

void Led::setup(GPIO* gpio, int sign)
{
    m_gpio = gpio;
    m_sign = sign;
}

void Led::write(int val)
{
    m_gpio->write(val);
}

void Led::turnOn(void)
{
    switch(m_partsType)
    {
    case LOCAL:
        //m_gpio->turnOn();
        break;
    case CAN:
        //CAN送信
        break;
    default:
        break;
    }
}

void Led::turnOff(void)
{
    switch(m_partsType)
    {
    case LOCAL:
        //m_gpio->turnOff();
        break;
    case CAN:
        //CAN送信
        break;
    default:
        break;
    }
}
