#pragma once
#include "hardware/peripheral/GPIO.hpp"
#include "../parts.hpp"
#include <stdint.h>

//01エアシリンダ
//ローカル/通信(CANとか)対応
class AirCylinder
{
public:
    typedef enum
    {
        OPEN, CLOSE
    }STATE;
    setup(GPIO* gpio);
    setup(bxCAN* can, uint16_t address);
    ~AirCylinder();
    void setupGpio(GPIO* gpio);
    void setupCan(bxCan* can, uint16_t address);

    void extension(void);
    void retruction(void);
    void move(STATE state);
    void changeState(void);
private:
    PartsType m_partsType;
    int sign = 1;
    STATE m_state;

    //初期化後の状態
    STATE defaultState = OPEN;

    //LOCAL
    GPIO* gpio;

    //CAN
    uint16_t m_address;

};
