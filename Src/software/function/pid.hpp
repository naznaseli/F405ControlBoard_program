#pragma once

class Pid
{
public:
    Pid(double dp, double ki, double kd);
    reset(void);
private:
    double m_kp;
    double m_ki;
    double m_kd;
};
