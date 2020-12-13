#pragma once
#include "parts/actuator/air_cylinder.hpp"

//シリンダx2
//4本分
class Arm
{
public:
    Arm(AirCylinder cylinderArm, AirCylinder cylinderHand);
    void stretchArm(void);
    void shrinkArm(void);
    void catch(void);
    void release(void);

private:
    AirCylinder m_cylinderArm;   //横に伸ばすシリンダ
    AirCylinder m_cylinderHand;  //掴む放すシリンダ
};
