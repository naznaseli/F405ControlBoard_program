#include "serial.hpp"
#include "../F405ControlBoard.hpp"
#include "../peripheral/USART.hpp"

Serial::Serial(UART* usart)
{
    m_usart = usart;
}

//extern int __io_putchar(int ch);
//extern int __io_getchar(void);
//int __io_putchar(int ch)
//{
//    F405ControlBoard::uart5._putchar(ch);
//}
//
//int __io_getchar(void)
//{
//
//}

int Serial::putchar_(uint8_t c)
{

}

int Serial::getchar_(void)
{

}

int Serial::write(const uint8_t* data, int size)
{

}

int Serial::read(uint8_t* data, int size)
{

}

//int Serial::printf(const char* format, ...)
//{

//}

int Serial::printf(const char* format, ...)
{
    m_usart->printf(format);
}

void Serial::clear(void)
{
    printf("\033[2J");
}

void Serial::setCursor(int x, int y)
{
    printf("\033[%d;%dH", y+1, x+1);
}



void Serial::setColor(Color color)
{
    printf("\033[%dm", color);
}