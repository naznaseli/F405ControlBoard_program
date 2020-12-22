#include "interface.hpp"

using namespace F405ControlBoard;

namespace interface
{
Led led[4];
Button button[4];
Buzzer buzzer;
CharacterLcd clcd;
UserEncoder userEnc;
Serial* pcDebug;

void setup(void)
{
    //入出力ユーザインタフェース
    led[0].setup(&ledPin[0]);
    led[1].setup(&ledPin[1]);
    led[2].setup(&ledPin[2]);
    led[3].setup(&ledPin[3]);
    button[0].setup(&buttonPin[0], -1);
    button[1].setup(&buttonPin[1], -1);
    button[2].setup(&buttonPin[2], -1);
    button[3].setup(&buttonPin[3], -1);
    buzzer.setup(&buzzerPin);
    //userEnc.setup(&ue_sw, &ue_a, &ue_b, &ue_red, &ue_blue, &ue_green);
    userEnc.setup(&ue_sw, &ue_a, &ue_b);
    clcd.setup(&lcd_rs, &lcd_e, &lcd_db4, &lcd_db5, &lcd_db6, &lcd_db7);

    //通信系
    //sixaxis1.setup(USART6);
    //sixaxis2.setup(UART4);
    //sixaxis3 = new Controller(&usart6);
    //pc = new PC(&usart3);
    pcDebug = new Serial(&usart2);
}

//void interrupt_1ms(void)
//{
//}

}//namespace
