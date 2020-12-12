#pragma once

class Motor
{
public:
    //ローカル用
    Motor();
    //通信用
    //Motor();

    void setPwm(double pwm);

    //位置制御用
    void setPos();

    //速度制御用
    void setSpeed();

    //setter
    //getter

private:

};
