#include "air_cylinder.hpp"

AirCylinder::setup(GPIO* gpio)
{
    m_partsType = LOCAL;
    setupLocal(gpio);
}

AirCylinder::setup(bxCAN* can, uint16_t address)
{
    m_partsType = CAN;
    setupCan(can, address);
}

void AirCylinder::setupGpio(GPIO* gpio)
{
    m_gpio = gpio;
}

void AirCylinder::setupCan(bxCan* can, uint16_t address)
{
    m_can = can;
    m_address = address;
}

void AirCylinder::open(void)
{
    switch(m_partsType)
    {
    case LOCAL:
        //if(sign == 1) m_gpio->turnOn();
        //else if(sign == -1) m_gpio->turnOff();
        break;
    case CAN:
        break;
    default:
        break;
    }
}

void AirCylinder::close(void)
{
    switch(m_partsType)
    {
    case LOCAL:
        //if(sign == 1) m_gpio->turnOff();
        //else if(sign == -1) m_gpio->turnOn();
        break;
    case CAN:
        break;
    default:
        break;
    }
}

void AirCylinder::move(STATE state)
{
    if(state == OPEN)
    {
        open();
    }
    else if(state == CLOSE)
    {
        close();
    }
}

//反転
void AirCylinder::changeState(void)
{
    //if()
}