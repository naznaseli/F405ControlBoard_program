#include "F405ControlBoard.hpp"
//#include "./parts/sensor.hpp"
//#include "./parts/actuator.hpp"

//シングルトンインスタンス
F405ControlBoard F405ControlBoard::m_instance;

#define GPIO_MODE   1

GPIO ledPin[4];
GPIO buttonPin[4];
GPIO buzzerPin;
GPIO limitSwPin[4];
//GPIO swdio, swclk;
//GPIO limitSwPin[4];
//USART usart1, usart2, usart3, uart4, uart5;
TIM tim6, tim7;
TIM tim9, tim10;    //代わり
TIM tim3, tim4;     //エンコーダ
//TIM tim1, tim2, tim3, tim4, tim5, tim6, tim10, tim13, tim14;
//bxCAN can1;

//Led led[4];
//Button button[4];
//Buzzer buzzer;
//Clcd clcd;
//
//PC* pc;
//
//Controller* sixaxis3;
//Imu* r1070;
//Imu* mpu6050;

F405ControlBoard::F405ControlBoard()
{
    m_elapsedTime = 0;
    m_delayCnt = 0;
}

void F405ControlBoard::setup(void)
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
    IWDG_Setup();

}

//void F405ControlBoard::setupInterface(void)
//{
//    led[0].setup(&ledPin[0]);
//    led[1].setup(&ledPin[1]);
//    led[2].setup(&ledPin[2]);
//    led[3].setup(&ledPin[3]);
//    button[0].setup(&buttonPin[0], -1);
//    button[1].setup(&buttonPin[1], -1);
//    button[2].setup(&buttonPin[2], -1);
//    button[3].setup(&buttonPin[3], -1);
//    buzzer.setup(&buzzerPin);
//
//    //ユーザエンコーダクラス
//    //userEnc = new UserEncoder;
//
//    //キャラクタ液晶設定
//    //clcd.setup(ピン名);
//
//    //通信系
//    //コントローラ設定x2
//    //sixaxis1.setup(USART6);
//    //sixaxis2.setup(UART4);
//
//    //通信を何で使うか決める
//    //sixaxis = new SIXAXIS(&usart6);
//    //pc = new PC(&usart3);
//    //r1070 = new IMU(&usart1, IMU_TYPE_R1070);
//}



void F405ControlBoard::RCC_Setup(void)
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

void F405ControlBoard::GPIO_Setup(void)
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

    buzzerPin.setup(PB9, GPIO::PUSHPULL);

    //ue_sw.setup(PC3, GPIO::FLOATING);
    //ue_a.setup(PA4, GPIO::FLOATING);
    //ue_b.setup(PA5, GPIO::FLOATING);

    //lcd_db7.setup(PC14, GPIO::PUSHPULL);
    //lcd_db6.setup(PC13, GPIO::PUSHPULL);
    //lcd_db5.setup(PC0, GPIO::PUSHPULL);
    //lcd_db4.setup(PC15, GPIO::PUSHPULL);
    //lcd_e.setup(PC1, GPIO::PUSHPULL);
    //lcd_rs.setup(PC2, GPIO::PUSHPULL);

#if GPIO_MODE
    limitSwPin[0].setup(PC4, GPIO::INPUT_PU);
    limitSwPin[1].setup(PC5, GPIO::INPUT_PU);
    limitSwPin[2].setup(PB0, GPIO::INPUT_PU);
    limitSwPin[3].setup(PB1, GPIO::INPUT_PU);
#endif

    //swdio, swclk
    //swdio.setup(PA13, GPIO::);
    //swclk.setup(PA14, GPIO::);

}

void F405ControlBoard::TIM_Setup(void)
{
    int apb1 = clock::getAPB1TimerClock();
    int apb2 = clock::getAPB2TimerClock();

    //タイマ
    tim6.setSourceFreq(apb1);
    tim6.setup(TIM6, 12, 1000000);
    tim6.enableCount();

    tim7.setSourceFreq(apb1);
    tim7.setup(TIM7, 12, 1000000);
    tim7.enableCount();

    tim9.setSourceFreq(apb2);
    tim9.setup(TIM9, 12, 1000000);
    tim9.enableCount();

    tim10.setSourceFreq(apb2);
    tim10.setup(TIM10, 12, 1000000);
    tim10.enableCount();

    //エンコーダ
    //tim4.setup(TIM4, );
    //tim3.setup(TIM3, );
    //tim8.setup(TIM8, );
    //tim5.setup(TIM5, );

    //ユーザエンコーダ
    //tim10.setup(TIM10, );
    //tim13.setup(TIM13, );
    //tim14.setup(TIM14, );
}

void F405ControlBoard::USART_Setup(void)
{

    //microUSB
    //usart2.setup(USART2, PA2, PA3, 115200);

    //microUSB
    //usart3.setup(USART3, PB10, PB11, 115200);

    //XA
    //usart4.setup(UART4, PC10, PC11, 115200);

    //XA
    //uart5.setup(UART5, PC12, PD2, 115200);

    //SBDBT
    //usart6.setup(USART6, PC6, PC7, 115200);

}

void F405ControlBoard::ADC_Setup(void)
{
    //pc4, pc5, pb0, pb1
    //adcPin[0].setup(PC4, );
    //adcPin[1].setup(PC5, );
    //adcPin[2].setup(PB0, );
    //adcPin[3].setup(PB1, );
    
}

void F405ControlBoard::bxCAN_Setup(void)
{
    //can1.setup(CAN1, PA11, PA12, 500);

}

void F405ControlBoard::IWDG_Setup(void)
{

}

void F405ControlBoard::cycle(void)
{
    //ウォッチドッグタイマ
    //IWDG_Reset();

    //static uint16_t cnt = 0;
    //if(++cnt >= 50000)
    //{
    //    cnt = 0;
    //    ledPin[0].toggle();
    //}
}

void F405ControlBoard::interrupt_1ms(void)
{
    //static int cnt = 0;
    //if(++cnt >= 100)
    //{
    //    //led1.toggle();
    //    ;
    //}
    m_elapsedTime++;
    if(m_delayCnt > 0) m_delayCnt--;
}

void F405ControlBoard::interrupt_10ms(void)
{
    static int cnt = 0;
    if(++cnt >= 100)
    {
        //led2.toggle();
        ;
    }
}

size_t F405ControlBoard::millis(void)
{
    return m_elapsedTime;
}

void F405ControlBoard::delay_us(uint16_t time)
{
    //while(us--)
    //{
    //    asm("NOP");
    //}
}

void F405ControlBoard::delay_ms(uint16_t time)
{
    m_delayCnt = time;
    while(m_delayCnt);
}
