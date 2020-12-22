#include "user_encoder.hpp"
#include "../../../circuit/F405ControlBoard.hpp" //tmp

void UserEncoder::sample(void)
{
    //1変化
    static const int8_t dir[] = {0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0};
    static uint8_t i = 0;
    //i = (i << 2) | ((m_gpioB->read() << 1) | m_gpioA->read());
    i = (i << 2) | ((F405ControlBoard::ue_b.read() << 1) | F405ControlBoard::ue_a.read());
    m_rawValue += dir[i & 0x0F];
}

UserEncoder::UserEncoder(GPIO* gpioSw, GPIO* gpioA, GPIO* gpioB, TIM* timR, TIM* timG, TIM* timB)
{
    setup(gpioSw, gpioA, gpioB, timR, timG, timB);
}

void UserEncoder::setup(GPIO* gpioSw, GPIO* gpioA, GPIO* gpioB, TIM* timR, TIM* timG, TIM* timB)
{
    m_gpioSw = gpioSw;
    m_gpioA = gpioA;
    m_gpioB = gpioB;
    m_timR = timR;
    m_timG = timG;
    m_timB = timB;
}

void UserEncoder::setup(GPIO* gpioSw, GPIO* gpioA, GPIO* gpioB)
{
    m_gpioSw = gpioSw;
    m_gpioA = gpioA;
    m_gpioB = gpioB;
}

UserEncoder::~UserEncoder()
{
    delete m_gpioSw;
    delete m_gpioA;
    delete m_gpioB;
    delete m_timR;
    delete m_timG;
    delete m_timB;
}
