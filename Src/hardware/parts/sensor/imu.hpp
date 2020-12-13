#pragma once

typedef enum
{
    R1350, R1070, MPU6050, MPU9250
}ImuType;

//通信、アナログ
class Imu
{
public:
    Imu();
    ~Imu();

private:
    ImuType m_imuType;
};
