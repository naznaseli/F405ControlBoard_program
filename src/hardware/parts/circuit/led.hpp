#pragma once
//#include "src/hardware/peripheral/GPIO.hpp"
#include "../../peripheral/GPIO.hpp"
#include "../parts.hpp"

//ポリモーフィズム意識
//ローカル/リモート(e.g.IO基板接続してとか)対応
class Led
{
public:
    Led(){};
    Led(GPIO* gpio);
    ~Led(){};

    //void setup(GPIO* gpio);
    void setup(GPIO* gpio, int sign = 1);

    void write(int val);
    void turnOn(void);
    void turnOff(void);

    void toggle(void);

private:
    PartsType m_partsType;

    //LOCAL
    GPIO* m_gpio;
    int m_sign = 1;

    //CAN
    uint16_t m_address;

};
