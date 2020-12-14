#pragma once

//方向単語指定  上レイヤ    front back left right
//角度指定  下レイヤ        0~2*M_PI[rad](0~360[度])
//数値指定  最下層レイヤ    0~1023
class KinectRotate
{
public:
    KinectRotate(ServoMotor* servoMotor);
    void faceFront(void);
    void faceBack(void);
    void faceRight(void);
    void faceLeft(void);

private:
    //THINK: モータポリモーフィズム？
    ServoMotor* m_servoMotor;
    //Motor* m_motor;

    //基準点1点
    uint16_t m_standard;

};
