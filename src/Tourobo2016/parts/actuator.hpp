#pragma once
#include "parts/parts.hpp"

#define DC_MOTOR_NUM        5   //足回り4、上下スライダ
#define AIRCYLINDER_NUM     8   //アームとハンドが4方向
#define SERVO_MOTOR_NUM     1   //上部キネクト回転用

namespace actuator
{
DcMotor dcMotor[DC_MOTOR_NUM];
AirCylinder airCylinder[AIRCYLINDER_NUM];
ServoMotor servoMotor[SERVO_MOTOR_NUM];
}
