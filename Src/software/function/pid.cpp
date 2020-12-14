#include "pid.hpp"

double Pid::calcPid(Wheel* wheel, double limit)
{
    double p, i, d;
    //差分
    p = wheel->tgtV - wheel->v;
    //積分
    i = wheel->pid.integral + (p + wheel->pid.oldP) * INTERRUPT_SEC * 0.5;

    //微分
    d = (p - wheel->pid.oldP) / INTERRUPT_SEC;

    
}