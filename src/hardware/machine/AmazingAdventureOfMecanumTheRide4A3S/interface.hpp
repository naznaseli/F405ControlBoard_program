#pragma once
#include "../../circuit/F405ControlBoard.hpp"
#include "../parts/interface/led.hpp"
#include "../parts/interface/button.hpp"
#include "../parts/interface/buzzer.hpp"
#include "../parts/interface/user_encoder.hpp"
#include "../parts/interface/clcd.hpp"

namespace interface
{
void setup(void);

Led led[4];
Button button[4];
Buzzer buzzer;
//UserEncoder userEncoder;
//CharacterLcd clcd;
//Serial* pc;
//Controller* sixaxis3;
}
