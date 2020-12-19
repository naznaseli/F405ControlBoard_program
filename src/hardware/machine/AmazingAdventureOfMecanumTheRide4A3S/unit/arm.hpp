#pragma once
//#include "../../mechanism/cylinder.hpp"

//4方向アーム
class Arm
{
public:
    //Arm(Cylinder* cylinderArm, Cylinder* cylinderHand);
    ~Arm();

    void catchHand(void);
    void releaseHand(void);

    void extension(void);   //伸
    void contraction(void); //縮


    //bool getHandState(void);
    //bool getArmState(void);
    bool isArmExtention(void);
    bool isArmContraction(void);

    bool isHandCatch(void);
    bool isHandRelease(void);

private:
    //Cylinder* m_arm;
    //Cylinder* m_hand;

};
