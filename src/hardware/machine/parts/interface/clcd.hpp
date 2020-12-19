#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include "../../../circuit/peripheral/GPIO.hpp"

//Local only?
class CharacterLcd
{
public:
    CharacterLcd(){};
    ~CharacterLcd();
    void setup(GPIO* rs, GPIO* e, GPIO* db4, GPIO* db5, GPIO* db6, GPIO* db7);

    void dataOut(uint8_t ascii);
    void command(uint8_t cmd);

    void cursor(int x, int y);
    void line(int y);
    void clear(void);
    int printf(const char* format, ...);

private:
    GPIO* m_rs;
    GPIO* m_e;
    GPIO* m_db4;
    GPIO* m_db5;
    GPIO* m_db6;
    GPIO* m_db7;
    void pinOut(uint8_t code, int rsmode);
    void pinOut(uint8_t data);

    void strOut(const uint8_t* str);
    static const uint8_t m_LineHeadAddress[];
    static const uint8_t m_ColumnNumber;

};
