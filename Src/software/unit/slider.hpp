#pragma once
#include "parts/motor.hpp"
#include "parts/encoder.hpp"
#include "parts/potentio.hpp"

class Slider
{
public:
    Slider(Motor* motor, Encoder* encoder, Potentio* potentio, LimitSw* limitSwMin, LimitSw* limitSwMax);
    Slider(Motor* motor, Encoder* encoder, Potentio* potentio, LimitSw* limitSwMin);
    Slider(Motor* motor, Encoder* encoder, Potentio* potentio);
    Slider(Motor* motor, Encoder* encoder, LimitSw* limitSwMin, LimitSw* limitSwMax);
    Slider(Motor* motor, Potentio* potentio);

    //定PWMで動かして限界調べる
    void findLimitVal(void);

private:
    Motor* m_motor;
    Encoder* m_encoder;
    Potentio* m_potentio;
    LimitSw* m_limitSwMin;
    LimitSw* m_limitSwMax;
};
