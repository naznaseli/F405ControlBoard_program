#include "button.hpp"

Button::Button(GPIO* gpio)
{
    m_gpio = gpio;
}

int Button::read(void)
{
    //return m_gpio->read();
    return 0;
}
