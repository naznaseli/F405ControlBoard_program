#include "F405ControlBoard.hpp"

#define ADC_MODE   1
#define BUZZER_SCALE_MODE 0

namespace F405ControlBoard
{
GPIO ledPin[4];
GPIO buttonPin[4];
#if !BUZZER_SCALE_MODE
GPIO buzzerPin;
#endif
GPIO ue_sw, ue_a, ue_b;
GPIO limitSwPin[4];
GPIO lcd_rs, lcd_e, lcd_db4, lcd_db5, lcd_db6, lcd_db7;
//GPIO swdio, swclk;
//GPIO limitSwPin[4];
//USART usart1, usart2, usart3, uart4, uart5;
TIM tim6, tim7;
TIM tim9, tim10;    //代わり
TIM tim3, tim4;     //エンコーダ
TIM ue_red, ue_green, ue_blue;   //ユーザエンコーダ
UART usart2, uart4, uart5;
#if BUZZER_SCALE_MODE
TIM tim11;
#endif
//TIM tim1, tim2, tim3, tim4, tim5, tim6, tim10, tim13, tim14;
//bxCAN can1;

//size_t m_elapsedTime = 0;
uint32_t m_delayCnt = 0;

void setup(void)
{
    //クロック設定
    RCC_Setup();

    //GPIO設定
    GPIO_Setup();

    //TIM設定
    TIM_Setup();

    //USART設定
    USART_Setup();

    //ADC設定
    ADC_Setup();

    //CAN設定
    bxCAN_Setup();

    //IWDG設定
    //IWDG_Setup();
}

void RCC_Setup(void)
{
    //TODO: セットアップ関数中身実装
    //TODO: グローバル禁止？
    clock::setup_168MHz_HSE();
    //clock::setup_168MHz_HSI();

    //clock::setPLLM(6);
    //clock::setPLLN(168);
    //clock::setPLLP(2);
    //clock::setPLLQ(4);
    //clock::setAHBPrescaler(1);
    //clock::setAPB1Prescaler(4);
    //clock::setAPB2Prescaler(2);
    //clock::setPowerVoltage(3.3);
    //clock::setup_PLLCLK_HSE();

}

void GPIO_Setup(void)
{
    ledPin[0].setup(PC9, GPIO::PUSHPULL, GPIO::SUPERHIGH_SPEED);
    //ledPin[0].setup(PC9, GPIO::PUSHPULL_AF, GPIO::SUPERHIGH_SPEED);   //for MCO2
    ledPin[1].setup(PC8, GPIO::PUSHPULL, GPIO::SUPERHIGH_SPEED);
    ledPin[2].setup(PA10, GPIO::PUSHPULL, GPIO::SUPERHIGH_SPEED);
    ledPin[3].setup(PB3, GPIO::PUSHPULL, GPIO::SUPERHIGH_SPEED);

    buttonPin[0].setup(PB12, GPIO::FLOATING);
    buttonPin[1].setup(PB13, GPIO::FLOATING);
    buttonPin[2].setup(PB14, GPIO::FLOATING);
    buttonPin[3].setup(PB15, GPIO::FLOATING);

#if !BUZZER_SCALE_MODE
    buzzerPin.setup(PB9, GPIO::PUSHPULL);
#endif

    ue_sw.setup(PC3, GPIO::FLOATING);
    ue_a.setup(PA4, GPIO::FLOATING);
    ue_b.setup(PA5, GPIO::FLOATING);

    //ue_sw.setup(PC3, GPIO::FLOATING);
    //ue_a.setup(PA4, GPIO::FLOATING);
    //ue_b.setup(PA5, GPIO::FLOATING);

    lcd_rs.setup(PC2, GPIO::PUSHPULL);
    lcd_e.setup(PC1, GPIO::PUSHPULL);
    lcd_db4.setup(PC15, GPIO::PUSHPULL);
    lcd_db5.setup(PC0, GPIO::PUSHPULL);
    lcd_db6.setup(PC13, GPIO::PUSHPULL);
    lcd_db7.setup(PC14, GPIO::PUSHPULL);

#if !ADC_MODE
    limitSwPin[0].setup(PC4, GPIO::INPUT_PU);
    limitSwPin[1].setup(PC5, GPIO::INPUT_PU);
    limitSwPin[2].setup(PB0, GPIO::INPUT_PU);
    limitSwPin[3].setup(PB1, GPIO::INPUT_PU);
#endif

    //swdio, swclk
    //swdio.setup(PA13, GPIO::);
    //swclk.setup(PA14, GPIO::);

}

void TIM_Setup(void)
{
    //タイマ
    //tim6.setSourceFreq(apb1);
    tim6.setup(TIM6, 12, 1000000);
    tim6.enableCount();

    //tim7.setSourceFreq(apb1);
    tim7.setup(TIM7, 12, 1000000);
    tim7.enableCount();

    //tim9.setSourceFreq(apb2);
    tim9.setup(TIM9, 12, 1000000);
    tim9.enableCount();

    //tim10.setSourceFreq(apb2);
    tim10.setup(TIM10, 12, 1000000);
    tim10.enableCount();

    //エンコーダ
    //tim4.setup(TIM4, PB6, PB7, 65535);
    //tim4.enableCount();
    //tim3.setup(TIM3, );
    //tim8.setup(TIM8, );
    //tim5.setup(TIM5, );

    //ユーザエンコーダ
    //ue_red.setup(TIM10, 12, 1000000);
    //ue_green.setup(TIM13, 12, 1000000);
    //ue_blue.setup(TIM14, 12, 1000000);

    //ブザー
#if BUZZER_SCALE_MODE
    //tim11.setup(TIM11, PB9, 10000);
#endif
}

void USART_Setup(void)
{

    //microUSB
    usart2.setup(USART2, PA2, PA3, 115200);

    //microUSB
    //usart3.setup(USART3, PB10, PB11, 115200);

    //XA
    uart4.setup(UART4, PC10, PC11, 115200);

    //XA
    uart5.setup(UART5, PC12, PD2, 115200);

    //SBDBT
    //usart6.setup(USART6, PC6, PC7, 115200);

}

void ADC_Setup(void)
{
#if ADC_MODE
    //adcPin[0].setup(PC4, );
    //adcPin[1].setup(PC5, );
    //adcPin[2].setup(PB0, );
    //adcPin[3].setup(PB1, );
#endif
    
}

void bxCAN_Setup(void)
{
    //can1.setup(CAN1, PA11, PA12, 500);

}

void IWDG_Setup(void)
{
    iwdg::setup_ms(500);
    iwdg::start();
}

void cycle(void)
{
    iwdg::reset();

    //static uint16_t cnt = 0;
    //if(++cnt >= 50000)
    //{
    //    cnt = 0;
    //    ledPin[0].toggle();
    //}
}

void interrupt_1ms(void)
{
    //m_elapsedTime++;
    //if(m_delayCnt) m_delayCnt--;

    //static int cnt = 0;
    //if(++cnt >= 1000)
    //{
    //    cnt = 0;
    //    ledPin[0].toggle();
    //}
}

void interrupt_10ms(void)
{
    //static int cnt = 0;
    //if(++cnt >= 100)
    //{
    //    //led2.toggle();
    //    ;
    //}
}

//size_t millis(void)
//{
//    return m_elapsedTime;
//}

void delay_us(uint32_t time)
{
    while(time--)
    {
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        asm("NOP");
    }
}

void delay_ms(uint32_t time)
{
    //m_delayCnt = time;
    //while(m_delayCnt);
    delay_us(time*1000);
}

}//namespace
