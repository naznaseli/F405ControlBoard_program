#pragma once

//センサの個数をどこに入れるか
class LineSensor
{
public:
    LineSensor();
    setup();
private:
    ADC12* m_adc12;

};
