#pragma once

#include <stdint.h>
#include "../parts.hpp"

//直読みと通信両対応
class Encoder
{
public:
    uint16_t read(void);
    void set(uint16_t count);
    void reset(void);

private:
    PartsType m_partsType;
    int sign = 1;

    //LOCAL
    TIM* m_tim;

    //CAN
    bxCAN* m_can;
    uint16_t m_address;
    uint16_t m_offset;

};
