#pragma once

typedef struct
{
    double direct;  //目標進行方向[rad]
    double v;       //目標速度[mm/s]
    double w;       //目標角速度[rad/s]
}tagTgtRobotMove;

//足回り抽象クラス
//ポリモーフィズム意識
//足回りとして最低限の内容のみ
//速度ベクトル入れたら動くみたいな

//:**********************************************************************
//UnderCarriage* a;
//a = new FourWheel();  //4輪タイヤ
//a = new TwoWheel();   //2輪タイヤ
//:**********************************************************************

class UnderCarriage
{
public:
    virtual ~UnderCarriage(){};
    virtual void update() = 0;

protected:
    //TyreUnit* m_tyreUnit_FL;
    //WheelUnit* m_wheelUnit_FL;
    //WheelUnit* m_wheelUnit_FR;
    //WheelUnit* m_wheelUnit_RL;
    //WheelUnit* m_wheelUnit_RR;

private:

};

//どうせエンコーダついてるから
//ユニットについてるでしょ
class FourWheel : public UnderCarriage
{
public:
    FourWheel(WheelUnit* wheelUnit_FL, WheelUnit* wheelUnit_FR, WheelUnit* wheelUnit_RL, WheelUnit* wheelUnit_RR);

    void update(void);

private:

};
