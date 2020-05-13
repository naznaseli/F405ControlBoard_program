#pragma once

#include <stdint.h>

class Encoder
{
public:
    uint16_t read(void);
    void set(uint16_t count);
    void reset(void);

};
