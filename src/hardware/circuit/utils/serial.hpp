#pragma once
#include "../peripheral/USART.hpp"

class Serial
{
public:
    Serial();
    Serial(UART* usart);
    int putchar_(uint8_t c);
    int getchar_(void);
    int write(const uint8_t* data, int size);
    int read(uint8_t* data, int size);
    int printf(const char* format, ...);

    void clear(void);
    void setCursor(int x, int y);
    typedef enum
    {
        White = 39, Red = 31, Blue = 34
    }Color;
    void setColor(Color color);
private:
    UART* m_usart;

};
