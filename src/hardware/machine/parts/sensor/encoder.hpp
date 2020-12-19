#pragma once

#include <stdint.h>
#include "../parts.hpp"
#include "../../../circuit/peripheral/TIM.hpp"
#include "../../../circuit/peripheral/bxCAN.hpp"

//直読みと通信両対応
class Encoder
{
public:
    Encoder(){};
    Encoder(TIM* tim, bool sign = true);
    Encoder(TIM* tim, bool sign, uint16_t resolution);
    ~Encoder();
    void setup(TIM* tim, bool sign = true);
    void setup(TIM* tim, bool sign, uint16_t resolution);
    uint16_t read(void);
    void set(uint16_t count);
    void reset(void);

private:
    PartsType m_partsType;
    bool m_sign = true;
    uint16_t m_resolution;    //P/R

    //LOCAL
    TIM* m_tim;

    //CAN
    bxCAN* m_can;
    uint16_t m_address;
    uint16_t m_offset;

};
