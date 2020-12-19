#include "limit_sw.hpp"
LimitSw::LimitSw(GPIO* gpio)
{
    setup(gpio);
}

LimitSw::LimitSw(GPIO* gpio, bool sign)
{
    setup(gpio, sign);
}

LimitSw::~LimitSw()
{
    delete m_gpio;
}

void LimitSw::setup(GPIO* gpio)
{
    m_gpio = gpio;
}

void LimitSw::setup(GPIO* gpio, bool sign)
{
    m_gpio = gpio;
    m_sign = sign;
}

bool LimitSw::read(void)
{
    uint8_t pinState = m_gpio->read();
    if(pinState == 0 && m_sign) return false;
    if(pinState == 0 && !m_sign) return true;
    if(pinState == 1 && m_sign) return true;
    if(pinState == 1 && !m_sign) return false;
}
