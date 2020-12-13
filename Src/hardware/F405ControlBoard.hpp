#pragma once

#include <stddef.h>
#include "./peripheral/RCC.hpp"
//#include "./peripheral/GPIO.hpp"
//#include "./peripheral/USART.hpp"
//#include "./peripheral/bxCAN.hpp"
//#include "./peripheral/TIM.hpp"
//#include "./peripheral/SPI.hpp"
//#include "./peripheral/IWDG.hpp"

//シングルトンオブジェクト
F405ControlBoard* m_board;

//基板の機能、設定
//センサアクチュエータなし？
//大会で使用するマシン構成(センサアクチュエータの数)とは切り離す？(使用する全センサアクチュエータ)>(この基板で読み取るセンサアクチュエータ)
//基板1枚に対して1つだけ→シングルトン
class F405ControlBoard
{
private:
    F405ControlBoard();
    ~F405ControlBoard();
public:

    //! setup
    void setupPeripheral(void);
    void setupInterface(void);

    //! 周期関数
    void cycle(void);
    void interrupt_1ms(void);
    void interrupt_10ms(void);

    size_t millis(void);
    void delay_us(uint16_t us);
    void delay_ms(uint16_t ms);

    //基板にある数だけインスタンス化
    //Led* led;
    //Button* button;
    //UserEncoder* userEnc;

private:
    size_t m_elapsedTime;
    unsigned int m_delayCnt;
    unsigned int m_buzzerCnt;

    //! setup中身
    void RCC_Setup(void);
    void GPIO_Setup(void);
    void TIM_Setup(void);
    void USART_Setup(void);
    void ADC_Setup(void);
    void bxCAN_Setup(void);
    void IWDG_Setup(void);
};

extern F405ControlBoard* board;
