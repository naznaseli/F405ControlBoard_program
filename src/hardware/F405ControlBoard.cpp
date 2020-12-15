#include "F405ControlBoard.hpp"
//#include "./parts/sensor.hpp"
//#include "./parts/actuator.hpp"

//シングルトンインスタンス
F405ControlBoard F405ControlBoard::m_instance;

GPIO ledPin[4];
//GPIO buttonPin[4]
//GPIO limitSwPin[4];
//GPIO buzzerPin;
//GPIO swdio, swclk;
//USART usart1, usart2, usart3, uart4, uart5;
//TIM tim1, tim2, tim3, tim4, tim5, tim6, tim10, tim13, tim14;
//bxCAN can1;
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
    //m_delayCnt = 0;
    //m_buzzerCnt = 0;
}

void F405ControlBoard::setupPeripheral(void)
{
    //クロック設定
    RCC_Setup();

    //GPIO設定
    GPIO_Setup();

    //TIM設定
//    TIM_Setup();
//
//    //USART設定
//    USART_Setup();
//
//    //ADC設定
//    ADC_Setup();
//
//    //CAN設定
//    bxCAN_Setup();
//
//    //IWDG設定
//    IWDG_Setup();

}

void F405ControlBoard::RCC_Setup(void)
{
    //TODO: セットアップ関数中身実装
    //TODO: グローバル禁止？
    //RCC_Setup_72MHz();
    RCC_Setup_168MHz();
}

void F405ControlBoard::GPIO_Setup(void)
{
    ledPin[0].setup(PC9, GPIO::PUSHPULL, GPIO::SUPERHIGH_SPEED);
    ledPin[1].setup(PC8, GPIO::PUSHPULL);
    ledPin[2].setup(PA10, GPIO::PUSHPULL);
    ledPin[3].setup(PB3, GPIO::PUSHPULL);

    //buttonPin[0].setup(PB12, GPIO::FLOATING);
    //buttonPin[1].setup(PB13, GPIO::FLOATING);
    //buttonPin[2].setup(PB14, GPIO::FLOATING);
    //buttonPin[3].setup(PB15, GPIO::FLOATING);

    //buzzer
    //buzzerPin.setup(PB9, GPIO::PUSHPULL);

    //ユーザエンコーダのスイッチ
    //ue_sw.setup(PC3, GPIO::FLOATING);
    //ue_a.setup(PA4, GPIO::FLOATING);
    //ue_b.setup(PA5, GPIO::FLOATING);

    //lcd
    //lcd_db7.setup(PC14, GPIO::PUSHPULL);
    //lcd_db6.setup(PC13, GPIO::PUSHPULL);
    //lcd_db5.setup(PC0, GPIO::PUSHPULL);
    //lcd_db4.setup(PC15, GPIO::PUSHPULL);
    //lcd_e.setup(PC1, GPIO::PUSHPULL);
    //lcd_rs.setup(PC2, GPIO::PUSHPULL);

    //ADC or IOで条件分岐
    //limitSw[0].setup(PC4, GPIO::INPUT_PU);
    //limitSw[1].setup(PC5, GPIO::INPUT_PU);
    //limitSw[2].setup(PB0, GPIO::INPUT_PU);
    //limitSw[3].setup(PB1, GPIO::INPUT_PU);

    //swdio, swclk
    //swdio.setup(PA13, GPIO::);
    //swclk.setup(PA14, GPIO::);

}

void F405ControlBoard::TIM_Setup(void)
{
    //エンコーダ0
    //tim4

    //エンコーダ1
    //tim3

    //エンコーダ2
    //tim8

    //エンコーダ3
    //tim5

    //ユーザエンコーダ
    //tim10, tim13, tim14

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
    
}

void F405ControlBoard::bxCAN_Setup(void)
{
    //can1.setup(CAN1, PA11, PA12, 500);

}

void F405ControlBoard::IWDG_Setup(void)
{

}

void F405ControlBoard::setupInterface(void)
{
    //setupPeripheralで設定したペリフェラルを用いた機能の設定

    //led = new Led[4];
    //button = new Button[4];

    //ユーザエンコーダクラス
    //userEnc = new UserEncoder;

    //キャラクタ液晶設定
    //clcd.setup(ピン名);

    //通信系
    //コントローラ設定x2
    //sixaxis1.setup(USART6);
    //sixaxis2.setup(UART4);

    //通信を何で使うか決める
    //sixaxis = new SIXAXIS(&usart6);
    //pc = new PC(&usart3);
    //r1070 = new IMU(&usart1, IMU_TYPE_R1070);
}

void F405ControlBoard::cycle(void)
{
    //ウォッチドッグタイマ
    //IWDG_Reset();

    static uint16_t cnt = 0;
    if(++cnt >= 10000)
    {
        cnt = 0;
        ledPin[0].toggle();
    }
}

void F405ControlBoard::interrupt_1ms(void)
{
    static int cnt = 0;
    if(++cnt >= 100)
    {
        //led1.toggle();
        ;
    }
    m_elapsedTime++;
    if(m_delayCnt) m_delayCnt--;
    //if(m_buzzerCnt) m_buzzerCnt--;

    //ユーザエンコーダの読み取り

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

void F405ControlBoard::delay_us(uint16_t us)
{
    //while(us--)
    //{
    //    asm("NOP");
    //}
}

void F405ControlBoard::delay_ms(uint16_t ms)
{
    m_delayCnt = ms;
    while(m_delayCnt);
}
