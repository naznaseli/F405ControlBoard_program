#include "under_carriage.hpp"

Mecanum::Mecanum(
    WheelUnit* wheelUnitFL, WheelUnit* wheelUnitFR,
    WheelUnit* wheelUnitRL, WheelUnit* wheelUnitRR,
    Encoder* encX, Encoder* encY)
{
    this->m_wheelUnit_FL = wheelUnitFL;
    this->m_wheelUnit_FR = wheelUnitFR;
    this->m_wheelUnit_RL = wheelUnitRL;
    this->m_wheelUnit_RR = wheelUnitRR;
    this->m_encX = encX;
    this->m_encY = encY;
}

//速度、角速度入力
//そのまま変換
void Mecanum::moveVel(Eigen::VectorXd vel, Eigen::Vector2d angularVel)
{
    //各タイヤ速度に変換
    //これオムニです
    //m_wheelFL = - vel(0) * sin(angularVel) - vel(1) * cos(angularVel);
    //m_wheelFR = + vel(0) * sin(angularVel) - vel(1) * cos(angularVel);
    //m_wheelRL = + vel(0) * sin(angularVel) + vel(1) * cos(angularVel);
    //m_wheelRR = - vel(0) * sin(angularVel) + vel(1) * cos(angularVel);
    //convertWheelVel(vel, angularVel);
    //convertWheelVel(vel, angularVel);
    //convertWheelVel(vel, angularVel);
    //convertWheelVel(vel, angularVel);
}

void Omni::moveVel(Eigen::VectorXd vel, Eigen::Vector2d angularVel)
{
    //4輪タイヤ速度に変換
    //m_wheelFL = - vel(0) * sin(angularVel) - vel(1) * cos(angularVel);
    //m_wheelFR = + vel(0) * sin(angularVel) - vel(1) * cos(angularVel);
    //m_wheelRL = + vel(0) * sin(angularVel) + vel(1) * cos(angularVel);
    //m_wheelRR = - vel(0) * sin(angularVel) + vel(1) * cos(angularVel);

    //各タイヤユニット内部でモータ速度に変換
}