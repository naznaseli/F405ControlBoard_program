#pragma once

//ポリモーフィズム意識
//ローカル/リモート(e.g.IO基板接続してとか)対応
class Led
{
public:
    Led(GPIO* gpio);
    ~Led();

    void on(void);
    void off(void);
    void light(int sw);

    void toggle(void);

private:
    GPIO* m_gpio;

};
