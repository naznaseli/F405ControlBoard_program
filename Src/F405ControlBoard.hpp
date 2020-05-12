#pragma once

#include <stddef.h>
#include "./peripheral/RCC.hpp"
//#include "./peripheral/GPIO.hpp"
//#include "./peripheral/USART.hpp"
//#include "./peripheral/bxCAN.hpp"
//#include "./peripheral/TIM.hpp"
//#include "./peripheral/SPI.hpp"
//#include "./peripheral/IWDG.hpp"

class F405ControlBoard
{
public:
    F405ControlBoard();
    ~F405ControlBoard();

    //! setup
    void setupPeripheral(void);
    void setupInterface(void);

    void RCC_Setup(void);
    void GPIO_Setup(void);
    void TIM_Setup(void);
    void USART_Setup(void);
    void ADC_Setup(void);
    void bxCAN_Setup(void);
    void IWDG_Setup(void);

    //! 周期関数
    void cycle(void);
    void interrupt_1ms(void);
    void interrupt_10ms(void);

    size_t millis(void);
    void delay_us(uint16_t us);
    void delay_ms(uint16_t ms);

private:
    size_t m_elapsedTime;
    unsigned int m_delayCnt;
    unsigned int m_buzzerCnt;

};

//! 多重割り込み禁止
class ProtectInterrupt
{
public:
    ProtectInterrupt()
    {
        //__disable_irq();
    };

    ~ProtectInterrupt()
    {
        //__enable_irq();
    };
};

class UserEncoder
{
public:
    UserEncoder();
    //UserEncoder(GPIO* pinSw, GPIO* pinA, GPIO* pinB, TIM* timR, TIM* timG, TIM* timB);
    ~UserEncoder();

    void flash(uint8_t red, uint8_t green, uint8_t blue);
    void interrupt(void);
    void cycle(void);
    void isPushed(void);
private:
    //ピンx3
    //PWMピンx3
};
