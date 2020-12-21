#pragma once
#include <stdint.h>
#include <stddef.h>
#include "./peripheral/RCC.hpp"
#include "./peripheral/GPIO.hpp"
#include "./peripheral/TIM.hpp"
#include "./peripheral/USART.hpp"
//#include "./peripheral/bxCAN.hpp"
//#include "./peripheral/SPI.hpp"
#include "./peripheral/IWDG.hpp"

#define ONBOARD_LED_NUM     4
#define ONBOARD_BUTTON_NUM  4
#define ONBOARD_LIMITSW_NUM 4

namespace F405ControlBoard
{
extern GPIO ledPin[ONBOARD_LED_NUM];
extern GPIO buttonPin[ONBOARD_BUTTON_NUM];
extern GPIO buzzerPin;
extern GPIO limitSwPin[ONBOARD_LIMITSW_NUM];
extern GPIO lcd_rs, lcd_e, lcd_db4, lcd_db5, lcd_db6, lcd_db7;
extern TIM tim3, tim4;
extern UART uart4, uart5;

//基板の機能、設定
//センサアクチュエータなし？
//大会で使用するマシン構成(センサアクチュエータの数)とは切り離す？(使用する全センサアクチュエータ)>(この基板で読み取るセンサアクチュエータ)

//! setup
void setup(void);

//! 周期関数
void cycle(void);
void interrupt_1ms(void);
void interrupt_10ms(void);

size_t millis(void);
void delay_us(uint32_t time);
void delay_ms(uint32_t time);

//private:
//extern size_t m_elapsedTime;
//extern uint16_t m_delayCnt;

//! setup中身
void RCC_Setup(void);
void GPIO_Setup(void);
void TIM_Setup(void);
void USART_Setup(void);
void ADC_Setup(void);
void bxCAN_Setup(void);
void IWDG_Setup(void);
}//namespace
