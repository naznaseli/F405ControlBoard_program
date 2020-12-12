#pragma once

class Led
{
public:
    Led(GPIO& gpio);
    ~Led();

    void on(void);
    void off(void);
    void light(int sw);

    void toggle(void);

private:

};
