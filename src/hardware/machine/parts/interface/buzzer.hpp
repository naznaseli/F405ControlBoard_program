#pragma once
#include "../parts.hpp"
#include "../../../circuit/peripheral/GPIO.hpp"
#include <stdint.h>

class Buzzer
{
public:
    Buzzer(){};
    Buzzer(GPIO* gpio);
    ~Buzzer();
    void setup(GPIO* gpio);
    void beep(uint16_t time);
    void write(int val);

private:
    PartsType m_partsType;

    //LOCAL
    GPIO* m_gpio;   //器のみ。delete禁止

    //CAN
    //ビープ時間送信？
};
