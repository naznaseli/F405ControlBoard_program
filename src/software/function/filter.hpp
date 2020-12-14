#pragma once

namespace filter
{
double lpf(double new);
double hpf(double new);
double ekf(double val);
double madgwick();

}//namespace
