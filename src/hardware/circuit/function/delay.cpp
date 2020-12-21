#include "delay.hpp"

void delay_us(uint32_t time)
{
    F405ControlBoard::delay_us(time);
}

void delay_ms(uint32_t time)
{
    F405ControlBoard::delay_ms(time);
}
