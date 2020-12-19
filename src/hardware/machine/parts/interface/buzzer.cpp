#include "buzzer.hpp"
#include <stdio.h>
#include "../../../circuit/F405ControlBoard.hpp"

Buzzer::Buzzer(GPIO* gpio)
{
  m_partsType = LOCAL;
  setup(gpio);
}

Buzzer::~Buzzer()
{
    m_gpio = NULL;
}

void Buzzer::setup(GPIO* gpio)
{
    m_gpio = gpio;
}

void Buzzer::beep(uint16_t time)
{
    m_gpio->write(1);
    F405ControlBoard::delay_ms(time);
    //for(int i = 0; i < 10000; i++);
    //for(int i = 0; i < 10000; i++);
    //for(int i = 0; i < 10000; i++);
    //for(int i = 0; i < 10000; i++);
    //for(int i = 0; i < 10000; i++);
    //for(int i = 0; i < 10000; i++);
    //for(int i = 0; i < 10000; i++);
    //for(int i = 0; i < 10000; i++);
    m_gpio->write(0);
}

void Buzzer::write(int val)
{
    m_gpio->write(val);
}
