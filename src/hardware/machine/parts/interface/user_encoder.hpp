#pragma once
#include <stdint.h>
#include "../../../circuit/peripheral/GPIO.hpp"
#include "../../../circuit/peripheral/TIM.hpp"


class UserEncoder
{
public:
    UserEncoder(){};
    UserEncoder(GPIO* gpioSw, GPIO* gpioA, GPIO* gpioB, TIM* timR, TIM* timG, TIM* timB);
    ~UserEncoder();

    typedef struct
    {
        uint8_t r;
        uint8_t g;
        uint8_t b;
    }COLOR24;

    void setup(GPIO* gpioSw, GPIO* gpioA, GPIO* gpioB, TIM* timR, TIM* timG, TIM* timB);
    void setup(GPIO* gpioSw, GPIO* gpioA, GPIO* gpioB);
    void sample(void);
    uint16_t getRawValue(void) const {return m_rawValue;};
    //void flash(uint8_t red, uint8_t green, uint8_t blue);
    //void interrupt(void);
    //void cycle(void);
    //void isPushed(void);

    void setColor(const COLOR24* color);
private:
    GPIO* m_gpioSw;
    GPIO* m_gpioA;
    GPIO* m_gpioB;
    TIM* m_timR;
    TIM* m_timG;
    TIM* m_timB;
    int16_t m_rawValue = 0;
};
