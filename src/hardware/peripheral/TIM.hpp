#pragma once
#include "stm32f405xx.h"
#include "GPIO.hpp"

class TIM
{
public:
    typedef enum
    {
        TIMER, PWMOUT, COMP_PWMOUT, ENCODER
    }TimMode;

    TIM(){};
    ~TIM(){};

    void enableClock(void);
    void disableClock(void);
    bool isEnable(void);
    void enableCount(void);
    void disableCount(void);
    void setCount(uint16_t count);
    uint16_t getCount(void) const;
    void resetCount(void);
    bool isCountEnable(void);

    //エンコーダ
    //void setupEncoder();
    void setup(TIM_TypeDef* tim, GPIO_TypeDef* gpioA, uint8_t pinA, GPIO_TypeDef* gpioB, uint8_t pinB, uint16_t period);
    //PWM出力
    void setupPwmOut();
    //タイマ
    void setup(TIM_TypeDef* tim, uint16_t prescaler, uint32_t interruptTime);

    class Channel
    {
    public:
        Channel(){};
        ~Channel(){};
        Channel(GPIO_TypeDef* gpio, uint8_t pin, GPIO::PinMode pinMode);

        //ピンにPWMを出力
        void pwm();

    private:
        GPIO* m_gpio;
    };
    Channel* ch1;
    Channel* ch1n;
    Channel* ch2;
    Channel* ch2n;
    Channel* ch3;
    Channel* ch3n;
    Channel* ch4;
private:
    TIM_TypeDef* m_TIMx;
    TimMode m_timMode;

    void setup(TIM_TypeDef* TIMx, TimMode timMode);
};
