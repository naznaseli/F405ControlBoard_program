#pragma once

namespace func
{
double deg2rad(double x)
{
    return (x*M_PI/180.0);
}
double rad2deg(double x)
{
    return (x*180.0/M_PI);
}
}
