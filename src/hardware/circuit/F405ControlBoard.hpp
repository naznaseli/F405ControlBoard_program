#pragma once
#include <stddef.h>
#include <stdint.h>
#include "./peripheral/RCC.hpp"
#include "./peripheral/GPIO.hpp"
#include "./peripheral/TIM.hpp"
//#include "./peripheral/USART.hpp"
//#include "./peripheral/bxCAN.hpp"
//#include "./peripheral/SPI.hpp"
//#include "./peripheral/IWDG.hpp"


extern GPIO ledPin[4];
extern GPIO buttonPin[4];
extern GPIO buzzerPin;

//extern Led led[4];
//extern Button button[4];
//extern Buzzer buzzer;

//基板の機能、設定
//センサアクチュエータなし？
//大会で使用するマシン構成(センサアクチュエータの数)とは切り離す？(使用する全センサアクチュエータ)>(この基板で読み取るセンサアクチュエータ)
//基板1枚に対して1つだけ→シングルトン
class F405ControlBoard
{
private:
    F405ControlBoard();
    ~F405ControlBoard(){};
    static F405ControlBoard m_instance;
public:
    static F405ControlBoard* getInstance(void){
        return &m_instance;
    }

    //! setup
    void setup(void);
    //void setupInterface(void);

    //! 周期関数
    void cycle(void);
    void interrupt_1ms(void);
    void interrupt_10ms(void);

    size_t millis(void);
    void delay_us(uint16_t time);
    void delay_ms(uint16_t time);

private:
    size_t m_elapsedTime = 0;
    uint16_t m_delayCnt = 0;

    //! setup中身
    void RCC_Setup(void);
    void GPIO_Setup(void);
    void TIM_Setup(void);
    void USART_Setup(void);
    void ADC_Setup(void);
    void bxCAN_Setup(void);
    void IWDG_Setup(void);
};

