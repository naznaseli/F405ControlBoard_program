#include "buzzer.hpp"

Buzzer::Buzzer(PartsType partsType, GPIO* gpio)
{
    m_partsType = partsType;
    setupGPIO(gpio);
}

Buzzer::~Buzzer()
{
    m_gpio = NULL;
}

void Buzzer::setupGPIO(GPIO* gpio)
{
    m_gpio = gpio;
}

void Buzzer::beep(uint16_t beepTime)
{
    m_beepTime = beepTime;
}