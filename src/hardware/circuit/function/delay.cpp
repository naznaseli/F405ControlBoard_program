#include "delay.hpp"

void delay_us(uint16_t time)
{
    F405ControlBoard::getInstance()->delay_us(time);
}

void delay_ms(uint16_t time)
{
    F405ControlBoard::getInstance()->delay_ms(time);
}
