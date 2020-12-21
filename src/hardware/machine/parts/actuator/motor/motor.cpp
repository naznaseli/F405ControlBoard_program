#include "motor.hpp"

Motor::setup(PartsType partsType)
{
    m_partsType = partsType;
}

//Motor::setup(PartsType partsType, TIM* tim)
Motor::setup(TIM* tim)
{
    //m_partsType = partsType;
    m_partsType = LOCAL;
    setupTim(tim);
}

//Motor::setup(PartsType partsType, bxCAN* can, uint16_t address)
Motor::setup(bxCAN* can, uint16_t address)
{
    m_partsType = CAN;
    setupCan(can, address);
}

Motor::~Motor()
{
    m_tim = NULL;
    m_can = NULL;
}

void Motor::setupTim(TIM* tim)
{
    m_tim = tim;
}

void Motor::setupCan(bxCAN* can, uint16_t address)
{
    m_can = can;
    m_address = address;
}

void Motor::setPwmTarget(double pwm)
{
    m_pwmTarget = pwm;
}

void Motor::free(void)
{
    switch(m_partsType)
    {
    case LOCAL:
        m_tim->free();
        break;
    case CAN:
        //アドレスのfree場所に値を入れる
        break;
    default:
        break;
    }
}
