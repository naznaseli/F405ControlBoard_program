#pragma once
#include "../peripheral/USART.hpp"

class Serial
{
public:
    int putchar_(uint8_t c);
    int getchar_(void);
    int write(const uint8_t* data, int size);
    int read(uint8_t* data, int size);
    int printf(const char* format, ...);
private:

};
