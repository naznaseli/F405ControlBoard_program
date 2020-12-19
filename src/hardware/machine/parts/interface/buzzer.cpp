#include "buzzer.hpp"
#include <stdio.h>

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

void Buzzer::beep(uint16_t beepTime)
{
    m_beepTime = beepTime;
}

void Buzzer::write(int val)
{
    m_gpio->write(val);
}
