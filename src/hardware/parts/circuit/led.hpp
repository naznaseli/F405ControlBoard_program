#pragma once
#include "GPIO.hpp"
#include "parts.hpp"

//ポリモーフィズム意識
//ローカル/リモート(e.g.IO基板接続してとか)対応
class Led
{
public:
    Led(GPIO* gpio);
    ~Led();

    void turnOn(void);
    void turnOff(void);

    void toggle(void);

private:
    PartsType m_partsType;

    //LOCAL
    GPIO* m_gpio;

    //CAN
    uint16_t m_address;

};
