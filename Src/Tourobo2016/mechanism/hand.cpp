#include "hand.hpp"

Arm::Arm(AirCylinder cylinderArm, AirCylinder cylinderHand)
{
    m_cylinderArm = cylinderArm;
    m_cylinderHand = cylinderHand;
}

void Arm::stretchArm(void)
{

}

void Arm::shrinkArm(void)
{

}

void Arm::catch(void)
{
    m_cylinderHand->turnOf();
}

void Arm::release(void)
{

}