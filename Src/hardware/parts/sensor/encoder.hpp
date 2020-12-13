#pragma once

#include <stdint.h>

//直読みと通信両対応
class Encoder
{
public:
    uint16_t read(void);
    void set(uint16_t count);
    void reset(void);

private:
    int sign = 1;

};
