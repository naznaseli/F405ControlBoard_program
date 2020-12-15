#include "slider.hpp"

SliderMechanism::SliderMechanism(Motor* motor, Encoder* encoder, Potentio* potentio, LimitSw* limitSwMin, LimitSw* limitSwMax)
{
    m_motor = motor;
    m_encoder = encoder;
    m_potentio = potentio;
    m_limitSwMin = limitSwMin;
    m_limitSwMax = limitSwMax;
}

SliderMechanism::SliderMechanism(Motor* motor, Encoder* encoder, Potentio* potentio, LimitSw* limitSwMin)
{
    m_motor = motor;
    m_encoder = encoder;
    m_potentio = potentio;
    m_limitSwMin = limitSwMin;
}

SliderMechanism::SliderMechanism(Motor* motor, Encoder* encoder, Potentio* potentio)
{
    m_motor = motor;
    m_encoder = encoder;
    m_potentio = potentio;
}

SliderMechanism::SliderMechanism(Motor* motor, Encoder* encoder, LimitSw* limitSwMin, LimitSw* limitSwMax)
{
    m_motor = motor;
    m_encoder = encoder;
    m_limitSwMin = limitSwMin;
    m_limitSwMax = limitSwMax;
}

SliderMechanism::SliderMechanism(Motor* motor, Potentio* potentio)
{

    m_motor = motor;
    m_potentio = potentio;
}

bool SliderMechanism::findLimitVal(void)
{
    m_motor->pwm(30.0);
    //当たったら少し戻す
    //if()

    //ゆっくり近づける
    m_motor->pwm(10.0);

    //当たったら終了
    //if(m_limitSwMin->) return true;
}
