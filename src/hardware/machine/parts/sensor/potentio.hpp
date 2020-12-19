#pragma once
//#include "../../../circuit/peripheral/ADC12.hpp"
#include <stdint.h>

class Potentio
{
public:
    uint16_t read(void);
    void setMinVal(uint16_t min);
    void setMaxVal(uint16_t max);

private:
    //ADC12* m_adc12;
    int m_sign = 1;
    uint16_t m_valMin = 0;
    uint16_t m_valMax = -1;
    
};
