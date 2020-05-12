#pragma once

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

    //!
    void cycle(void);
    void interrupt_1ms(void);
    void interrupt_10ms(void);

    void delay_us(uint16_t us);
    void delay_ms(uint16_t ms);


private:
    unsigned int m_delayCnt = 0;
    unsigned int m_buzzerCnt = 0;

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
    void flash(uint8_t red, uint8_t green, uint8_t blue);
    void interrupt(void);
    void cycle(void);
    void isPushed(void);
};
