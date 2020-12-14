#include "actuator.hpp"

namespace actuator
{
void update(void)
{
    for(int i = 0; i < DC_MOTOR_NUM; i++)
    {
        dcMotor[i].update();
    }
    for(int i = 0; i < AIRCYLINDER_NUM; i++)
    {
        airCylinder[i].update();
    }
    for(int i = 0; i < SERVO_MOTOR_NUM; i++)
    {
        servoMotor[i].update();
    }
}

}//namespace
