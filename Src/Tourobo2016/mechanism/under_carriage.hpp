#pragma once
#include <Eigen/Geometry>

//足回り抽象クラス
//ポリモーフィズム意識
//足回りとして最低限の内容のみ
//速度ベクトル入れたら動くみたいな
//Eigen::Vector2d

//:**********************************************************************
//UnderCarriage* a;
//a = new FourWheel();  //4輪タイヤ
//a = new TwoWheel();   //2輪タイヤ
typedef struct
{
    //座標
    double x;//機体のx座標
    double y;//機体のy座標
    Eigen::Vector2d machinePos;

    //速度
    double vx;//機体のx方向の速度
    double vy;//機体のy方向の速度
    double v;//機体の速度
    double direct;//機体の進行方向
    Eigen::Vector2d machineVel;

    //加速度
    double a;//加速度
    Eigen::Vector2d machineAccel;

    //:**************************************************

    //角度
    double angle;//機体の角度
    Eigen::Vector2d machineAngle;

    //角速度
    double w;//機体の角速度
    Eigen::Vector2d machineAngularVel;

    //各加速度
    double dw;//機体の角加速度
    Eigen::Vector2d machineAngularAccel;

    double length;//機体の進んだ距離
}tagLocalization;

//抽象クラス？
class UnderCarriage
{
public:
    UnderCarriage();
    ~UnderCarriage();
    virtual void moveVel(Eigen::Vector2d vel);

    //自己位置推定
	//CDeadReckoning* getDeadRec(){ return &m_deadRec; }
protected:
	CEncoder *m_encoder_x;
	CEncoder *m_encoder_y;
	tagTgtRoboMove m_tgtRoboMove;
private:

	DeadReckoning m_deadRec;
	};

//
class Mecanum : public UnderCarriage
{
public:
    Mecanum(
        WheelUnit* wheelUnitFL, WheelUnit* wheelUnitFR,
        WheelUnit* wheelUnitRL, WheelUnit* wheelUnitRR,
        Encoder* encX, Encoder* encY);

    ~Mecanum();

    void moveVel(Eigen::Vector2d vel);
private:
    //接地エンコーダ
    //TODO: 角度変えて設置できるように
    Encoder* encX;
    Encoder* encY;

    //タイヤ
    WheelUnit *m_wheelFL;
    WheelUnit *m_wheelFR;
    WheelUnit *m_wheelRL;
    WheelUnit *m_wheelRR;


};

class SwerveDrive : public UnderCarriage
{
public:
        ~SwerveDrive();

private:
    Encoder* encX;
    Encoder* encY;

    //ステアリング用
    WheelUnit *m_steeringFL;
    WheelUnit *m_steeringFR;
    WheelUnit *m_steeringBL;
    WheelUnit *m_steeringBR;
    //駆動用
    WheelUnit *m_driveFL;
    WheelUnit *m_driveFR;
    WheelUnit *m_driveBL;
    WheelUnit *m_driveBR;

};

//差動2輪
class TwoWheel : public UnderCarriage
{
public:
private:
    Encoder* encL;
    Encoder* encR;
    WheelUnit *m_wheelUnitL;
    WheelUnit *m_wheelUnitR;

};

//差動4輪
class FourWheel : public UnderCarriage
{
public:

private:
};
