#include "encoder.hpp"
#include <stdio.h>

Encoder::Encoder(TIM* tim, bool sign)
{
    setup(tim, sign);
}

Encoder::Encoder(TIM* tim, bool sign, uint16_t resolution)
{
    setup(tim, sign, resolution);
}

Encoder::~Encoder()
{
    m_tim = NULL;
    m_can = NULL;
}

void Encoder::setup(TIM* tim, bool sign)
{
    m_tim = tim;
    m_sign = sign;
}

void Encoder::setup(TIM* tim, bool sign, uint16_t resolution)
{
    m_tim = tim;
    m_sign = sign;
    m_resolution = resolution;
}