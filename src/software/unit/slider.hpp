#pragma once
#include "parts/motor.hpp"
#include "parts/encoder.hpp"
#include "parts/potentio.hpp"

//抽象クラス
class SliderMechanism
{
public:
    SliderMechanism(Motor* motor, Encoder* encoder, Potentio* potentio, LimitSw* limitSwMin, LimitSw* limitSwMax);
    SliderMechanism(Motor* motor, Encoder* encoder, Potentio* potentio, LimitSw* limitSwMin);
    SliderMechanism(Motor* motor, Encoder* encoder, Potentio* potentio);
    SliderMechanism(Motor* motor, Encoder* encoder, LimitSw* limitSwMin, LimitSw* limitSwMax);
    SliderMechanism(Motor* motor, Potentio* potentio);

    //定PWMで動かして限界調べる
    void findLimitVal(void);

private:
    Motor* m_motor;
    Encoder* m_encoder;
    Potentio* m_potentio;
    LimitSw* m_limitSwMin;
    LimitSw* m_limitSwMax;
};
