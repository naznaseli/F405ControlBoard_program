#pragma once
#include "undercarriage.hpp"
#include "../parts/actuator/motor.hpp"
#include "../parts/sensor/encoder.hpp"

//センサ更新、出力は別
//取得したセンサ情報を元に目標値を決めるところまで
class Mecanum : public UnderCarriage
{
public:
    //Mecanum(
    //    Motor* motorFL, Encoder* encFL,
    //    Motor* motorFR, Encoder* encFR,
    //    Motor* motorRL, Encoder* encRL,
    //    Motor* motorRR, Encoder* encRR);

    void update(void);

    //速度角速度指定移動、ベクトル指定
    void moveVelocity();

    //フリー状態、手で動かしやすい(ギヤ、モータを傷めないよう注意)
    void free(void);

private:
    //Motor* m_motorFL;
    //Motor* m_motorFR;
    //Motor* m_motorRL;
    //Motor* m_motorRR;
    //Encoder* m_encFL;
    //Encoder* m_encFR;
    //Encoder* m_encRL;
    //Encoder* m_encRR;

};
