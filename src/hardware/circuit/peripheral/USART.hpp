#pragma once
#include "stm32f405xx.h"
#include "GPIO.hpp"
#include <stdint.h>

class UART
{
public:
    UART(){};
    UART(USART_TypeDef* UARTx, GPIO_TypeDef* gpioTx, uint8_t pinTx, GPIO_TypeDef* gpioRx, uint8_t pinRx, uint32_t baudrate);
    ~UART();
    void setup(USART_TypeDef* UARTx, GPIO_TypeDef* gpioTx, uint8_t pinTx, GPIO_TypeDef* gpioRx, uint8_t pinRx, uint32_t baudrate);
    void enableClock(void);
    void setBaudrate(uint32_t baudrate);

    void setAlternate(void);

    void enableUART(void);
    void enableTx(void);
    void enableRx(void);

    int _putchar(uint8_t c);
    int _getchar(void);
    int write(const uint8_t* data, int size);
    int read(uint8_t* data, int size);
    int printf(const char* format, ...);

private:
    USART_TypeDef* m_UARTx;
    GPIO* m_gpioTx;
    GPIO* m_gpioRx;

};
