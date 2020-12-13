#include "led.hpp"

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
