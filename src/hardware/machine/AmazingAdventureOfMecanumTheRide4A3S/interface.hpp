#pragma once
#include "../../circuit/F405ControlBoard.hpp"
#include "../parts/interface/led.hpp"
#include "../parts/interface/button.hpp"
#include "../parts/interface/buzzer.hpp"
#include "../parts/interface/user_encoder.hpp"
#include "../parts/interface/clcd.hpp"
#include "../../circuit/utils/serial.hpp"

#define LED_NUM 4
#define BUTTON_NUM 4

namespace interface
{
extern Led led[LED_NUM];
extern Button button[BUTTON_NUM];
extern Buzzer buzzer;
extern CharacterLcd clcd;
//UserEncoder userEncoder;
//CharacterLcd clcd;
extern Serial* pcDebug;
//Serial* pc;
//Controller* sixaxis3;

void setup(void);
//void interrupt_1ms(void);
}//namespace
