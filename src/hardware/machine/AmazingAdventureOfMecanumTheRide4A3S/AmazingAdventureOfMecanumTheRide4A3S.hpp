#pragma once

class Machine
{
private:
    Machine();
    ~Machine(){};
    static Machine m_instance;
public:
    static Machine* getInstance(void){return &m_instance;}

    //! setup
    void setup(void);
    void update(void);

//:******************************
    //! メカユニット
    //:******************************
    //mechanismのインスタンス作成
    //特殊なメカユニットに対しては必要に応じて継承

    //! 足回りメカナム
    //Mecanum* mecanum;

    //! 接地エンコーダ
    //Odometri* odometri;

    //! 上下スライダ
    //Slider* sliderZ;

    //! 4方向アーム
    //Arm* armFront;
    //Arm* armRear;
    //Arm* armLeft;
    //Arm* armRight;

    //! 回るキネクト
    //Rotattion* rotateKinect;


};
