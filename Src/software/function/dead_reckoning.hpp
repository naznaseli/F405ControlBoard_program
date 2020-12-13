#pragma once

typedef struct 
{
    double x;       //機体のx座標
    double y;       //機体のy座標
    double vx;      //機体のx方向の速度
    double vy;      //機体のy方向の速度
    double v;       //機体の速度
    double direct;  //機体の進行方向
    double angle;   //機体の角度
    double w;       //機体の角速度
    double length;  //機体の進んだ距離
    double a;       //加速度
    double dw;      //機体の角加速度
}tagLocalization;

//ベクトル表記
typedef struct 
{
    //Vector machinPos;
    //Vector machinVel;
    //Vector machineW;
    //Vector 
}tagLocalizationVector;


class DeadReckoning
{
public:
    DeadReckoning();
    ~DeadReckoning();

    //情報の更新
    void update(double dx, double dy, double w);

    //! getter
    double getX(void) const {return m_localization.x};
    double getY(void) const {return m_localization.y};
    double getVx(void) const { return m_localization.vx; }
    double getVy(void) const { return m_localization.vy; }
    double getV(void) const { return m_localization.v; }
    double getDirection(void) const { return m_localization.direct; }
    double getAngle(void) const { return m_localization.angle; }
    double getW(void) const { return m_localization.w; }
    double getLength(void) const { return m_localization.length; }
    double getA(void) const { return m_localization.a; }
    double getDw(void) const { return m_localization.dw; }

    //! setter
    void setX(double x){};
    void setY(double x){};
    void setAngle(double angle);
    void setLength(double length);


private:
    tagLocalization m_localization;
};
