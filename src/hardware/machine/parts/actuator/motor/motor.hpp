#pragma once
#include <stdint.h>
#include "TIM.hpp"
#include "bxCAN.hpp"
#include "parts.hpp"

//MD基板内部のクラスと併用
class Motor
{
public:
    Motor();
    void setup(PartsType type);
    void setup(TIM* tim);
    void setup(bxCAN* can, uint16_t address);
    ~Motor();
    void setupTim(TIM* tim);
    void setupCan(bxCAN* can, uint16_t address);

    void setPwmTarget(double pwm);
    void setVel(double vel);
    void free(void) = 0;

    //getter
    void getPwm() const { return m_pwm; };

private:
    double m_pwmTarget;
    double m_pwm;
    uint16_t pos;
    PartsType m_partsType;

    //LOCAL
    TIM* m_tim;

    //CAN
    bxCAN* m_can;
    uint16_t m_address;

};