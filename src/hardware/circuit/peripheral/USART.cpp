#include "USART.hpp"
#include "RCC.hpp"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define writeBit(PERIPH, REG, SYM, VAL) (PERIPH->REG)=((PERIPH->REG)&(~PERIPH##_##REG##_##SYM##_Msk))|(VAL<<PERIPH##_##REG##_##SYM##_Pos)
#define writeReg(PERIPH, REG, VAL)      (PERIPH->REG)
#define readBit(PERIPH, REG, SYM)       (((PERIPH->REG)&PERIPH##_##REG##_##SYM##_Msk)>>PERIPH##_##REG##_##SYM##_Pos)
#define readReg(PERIPH, REG)  ()

UART::UART(USART_TypeDef* UARTx, GPIO_TypeDef* gpioTx, uint8_t pinTx, GPIO_TypeDef* gpioRx, uint8_t pinRx, uint32_t baudrate)
{
    setup(UARTx, gpioTx, pinTx, gpioRx, pinRx, baudrate);
}

UART::~UART()
{
    delete m_gpioTx;
    delete m_gpioRx;
}

void UART::setup(USART_TypeDef* UARTx, GPIO_TypeDef* gpioTx, uint8_t pinTx, GPIO_TypeDef* gpioRx, uint8_t pinRx, uint32_t baudrate)
{
    m_UARTx = UARTx;
    m_gpioTx = new GPIO(gpioTx, pinTx, GPIO::PUSHPULL_AF, GPIO::SUPERHIGH_SPEED);
    m_gpioRx = new GPIO(gpioRx, pinRx, GPIO::FLOATING, GPIO::SUPERHIGH_SPEED);

    enableClock();
    setBaudrate(baudrate);
    setAlternate();

    enableUART();
    enableTx();
    enableRx();
}

void UART::enableClock(void)
{
    if(m_UARTx == USART1) RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    if(m_UARTx == USART2) RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    if(m_UARTx == USART3) RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
    if(m_UARTx == UART4) RCC->APB1ENR |= RCC_APB1ENR_UART4EN;
    if(m_UARTx == UART5) RCC->APB1ENR |= RCC_APB1ENR_UART5EN;
    if(m_UARTx == USART6) RCC->APB1ENR |= RCC_APB2ENR_USART6EN;

    //if(UARTx == USART1) writeBit(RCC, APB2ENR, USART1EN, 1);   
    //if(UARTx == USART2) writeBit(RCC, APB1ENR, USART2EN, 1);   
    //if(UARTx == USART3) writeBit(RCC, APB1ENR, USART3EN, 1);   
    //if(UARTx == UART4) writeBit(RCC, APB1ENR, UART4EN, 1);   
    //if(UARTx == UART5) writeBit(RCC, APB1ENR, UART5EN, 1);   
    //if(UARTx == USART6) writeBit(RCC, APB2ENR, USART6EN, 1);   
}

void UART::setBaudrate(uint32_t baudrate)
{
    if(m_UARTx == USART2 || m_UARTx == USART3 || m_UARTx == UART4 || m_UARTx == UART5)
    {
        //APB1
        //uint16_t clock = clock::getAPB1PeripheralClock();

        //42MHzのときの115200
        //m_UARTx->BRR = 0x16B;
        //m_UARTx->BRR = 0b0001011011000100; 
        //m_UARTx->BRR = 0b101100010; 
        m_UARTx->BRR = 0x16D;

        //84MHz
        //m_UARTx->BRR = 0x2D9;
    }
    if(m_UARTx == USART1 || m_UARTx == USART6)
    {
        //APB2
        //uint16_t clock = clock::getapb2PeripheralClock();
    }
}

void UART::setAlternate(void)
{
    if(m_UARTx == USART1 || m_UARTx == USART2 || m_UARTx == USART3)
    {
        m_gpioTx->setAlternate(AF7);
        m_gpioRx->setAlternate(AF7);
    }
    else if(m_UARTx == UART4 || m_UARTx == UART5 || m_UARTx == USART6)
    {
        m_gpioTx->setAlternate(AF8);
        m_gpioRx->setAlternate(AF8);
    }
}

void UART::enableUART(void)
{
    m_UARTx->CR1 |= USART_CR1_UE;
}

void UART::enableTx(void)
{
    m_UARTx->CR1 |= USART_CR1_TE;
}
void UART::enableRx(void)
{
    m_UARTx->CR1 |= USART_CR1_RE;
}

int UART::_putchar(uint8_t c)
{
    while((m_UARTx->SR & USART_SR_TC) == 0);
    m_UARTx->DR = c;
    while((m_UARTx->SR & USART_SR_TXE) == 0);
    
    return (int)c;
}

int UART::_getchar(void)
{

    return 0;
}

int UART::write(const uint8_t* data, int size)
{
    const uint8_t* p = data;
    int cnt = 0;
    
    if(p == NULL) return 0;
    while(size > 0)
    {
        _putchar(*(p++));
        size--;
        cnt++;
    }
    return cnt;
}

int UART::read(uint8_t* data, int size)
{
    int cnt = 0;
    while(size > 0)
    {
        _getchar();
        size--;
        cnt++;
    }
    return cnt;
}

int UART::printf(const char* format, ...)
{
    char buffer[128];
    va_list ap;
    int len;
    va_start(ap, format);
    len = vsprintf(buffer, format, ap);
    va_end(ap);
    return write((uint8_t*)buffer, len);
}
