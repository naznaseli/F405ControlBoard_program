#include "delay.hpp"

void delay_us(uint16_t time)
{
    F405ControlBoard::delay_us(time);
}

void delay_ms(uint16_t time)
{
    F405ControlBoard::delay_ms(time);
}
