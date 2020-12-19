#pragma once
#include "../../../circuit/peripheral/USART.hpp"

typedef enum
{
    R1350N, R1070, MPU6050, MPU9250
}ImuType;

//通信、アナログ
class Imu
{
public:
    Imu(USART* usart, ImuType);
    //Imu(bxCAN* can, uint16_t address, ImuType);
    ~Imu();
    void calcPacket();

private:
    ImuType m_imuType;
};
