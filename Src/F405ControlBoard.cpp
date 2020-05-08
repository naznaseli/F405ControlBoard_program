#include "F405ControlBoard.hpp"
#include "sensor.hpp"
#include "actuator.hpp"

//GPIO led[0], button[4], limitSw[4];
//GPIO swdio, swclk;
//USART usart1, usart2, usart3, uart4, uart5;
//TIM
//bxCAN
//SPI microSD;
//Characterlcd clcd;

//PCCom* pccom;
//Sixaxis* sixaxis;

//Sensor sensor;
//Actuator actuator;

F405ControlBoard::F405ControlBoard()
{

}

F405ControlBoard::~F405ControlBoard()
{

}

void F405ControlBoard::setupPeripheral(void)
{
    //クロック設定
    RCC_Setup();

    //GPIO設定
    GPIO_Setup();

    //TIM設定
    TIM_Setup();

    //USART設定
    USART_Setup();

    //SPI設定
    SPI_Setup();

    //CAN設定
    bxCAN_Setup();

    //IWDG設定
    IWDG_Setup();

}

void F405ControlBoard::RCC_Setup(void)
{
    //TODO: セットアップ関数中身実装
    //TODO: グローバル禁止？
    RCC_Setup_72MHz();
}

void F405ControlBoard::GPIO_Setup(void)
{
    //led[0].setup(, GPIO::PUSHPULL);
    //led[1].setup(, GPIO::PUSHPULL);
    //led[2].setup(, GPIO::PUSHPULL);
    //led[3].setup(, GPIO::PUSHPULL);

    //button[0].setup(, GPIO::OPENDRAIN);
    //button[1].setup(, GPIO::OPENDRAIN);
    //button[2].setup(, GPIO::OPENDRAIN);
    //button[3].setup(, GPIO::OPENDRAIN);

    //limitSw[0].setup(, GPIO::OPENDRAIN);
    //limitSw[1].setup(, GPIO::OPENDRAIN);
    //limitSw[2].setup(, GPIO::OPENDRAIN);
    //limitSw[3].setup(, GPIO::OPENDRAIN);

    //swdio, swclk

}

void F405ControlBoard::TIM_Setup(void)
{

}

void F405ControlBoard::USART_Setup(void)
{
    //usart1.setup();
    //usart2.setup();
    //usart3.setup();
    //usart4.setup();

}

void F405ControlBoard::SPI_Setup(void)
{

}

void F405ControlBoard::bxCAN_Setup(void)
{

}

void F405ControlBoard::IWDG_Setup(void)
{

}

void F405ControlBoard::setupInterface(void)
{
    //キャラクタ液晶設定

    //コントローラ設定

    //PC通信設定

}

void F405ControlBoard::cycle(void)
{
    //ウォッチドッグタイマ

}

void F405ControlBoard::interrupt_1ms(void)
{
    static int cnt = 0;
    if(++cnt >= 100)
    {
        //led0.toggle();
        ;
    }
    if(m_delayCnt) m_delayCnt--;
    if(m_buzzerCnt) m_buzzerCnt--;

}

void F405ControlBoard::interrupt_10ms(void)
{
    static int cnt = 0;
    if(++cnt >= 100)
    {
        //led1.toggle();
        ;
    }

}

void F405ControlBoard::delay_us(uint16_t us)
{
    //nop();
}

void F405ControlBoard::delay_ms(uint16_t ms)
{
    m_delayCnt = ms;
    while(m_delayCnt);
}
