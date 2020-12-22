#include "menu_circuit.hpp"
#include "../../machine/AmazingAdventureOfMecanumTheRide4A3S/interface.hpp"
#include "../../machine/AmazingAdventureOfMecanumTheRide4A3S/sensor.hpp"

#define SIZEOFARRAY(array) (sizeof(array)/sizeof((array)[0]))

bool showEncoder(void);
bool showPotentio(void);
bool testMotor(void);

const MenuList List_Circuit[] =
{
    {"Enocder"      ,showEncoder            },
    {"Potentio"     ,showPotentio           },
    //{"show IMU"     ,testEmv                },
    {"Motor"        ,testMotor              },
    //{"Test EMV"     ,testEmv                },
    //{"Test Controller"     ,testEmv                },
    //{"Test EMV"     ,testEmv                },
    //{"Test EMV"     ,testEmv                },
};

const RotaryMenu Menu_Circuit =
{
    {'C', 'i', 'r', 'c', 'u', 'i', 't', 'M', 'e', 'n', 'u'},
    SIZEOFARRAY(List_Circuit),
    List_Circuit
};

bool showCircuitMenu(void)
{
    bool ret = Menu::getInstance()->cycle(&Menu_Circuit);
    return ret;
}

bool showEncoder(void)
{
    static bool initFlag = true;
    if(initFlag)
    {
        interface::pcDebug->setColor(Serial::White);
        interface::pcDebug->clear();
        interface::pcDebug->setCursor(1, 2);
        interface::pcDebug->printf("------------------------------------------------");
        interface::pcDebug->setCursor(30, 12);
        interface::pcDebug->printf("[");
        interface::pcDebug->setColor(Serial::Red);
        interface::pcDebug->printf("R");
        interface::pcDebug->setColor(Serial::White);
        interface::pcDebug->printf(":select ");
        interface::pcDebug->setColor(Serial::Blue);
        interface::pcDebug->printf("B");
        interface::pcDebug->setColor(Serial::White);
        interface::pcDebug->printf(":return]");
        //printf("[\033[31mR\033[39m:move on \033[34mB\033[39m:return]");

        interface::pcDebug->setCursor(1, 1);
        interface::pcDebug->printf("Encoder");
        for(int i = 0; i < ENCODER_NUM; i++)
        {
            interface::pcDebug->setCursor(1, i + 3);
            interface::pcDebug->printf("Encoder[%2d] = ", i);
        }
        initFlag = false;
    }
    for(int i = 0; i < ENCODER_NUM; i++)
    {
        interface::pcDebug->setCursor(15, i + 3);
        //interface::pcDebug->printf("%5d", Encoder[i]);
        interface::pcDebug->printf("65535");
    }

    static bool endFlag = false;
    if(interface::button[1].read()) endFlag = true;
    if(!interface::button[1].read() && endFlag)
    {
        endFlag = false;
        initFlag = true;
        return true;
    }
    return false;
}

bool showPotentio(void)
{
    return true;
}

bool testMotor(void)
{
    return true;
}
