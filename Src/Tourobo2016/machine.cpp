#include "machine.hpp"

using namespace sensor;
using namespace actuator;

//シングルトン
AmazingAdventureOfMecanumTheRide4A3S::AmazingAdventureOfMecanumTheRide4A3S()
{
    //sensor
    encoder[0]->setup(tim1);
    encoder[1]->setup(tim2);
    encoder[2]->setup(can0, 0x010);
    encoder[3]->setup(can0, 0x010);
    encoder[4]->setup(can0, 0x011);
    encoder[5]->setup(can0, 0x011);
    encoder[6]->setup(can0, 0x012);
    potentio[0]->setup(can0, 0x050);
    limitSw[0]->setup(can0, 0x060);
    limitSw[1]->setup(can0, 0x060);

    //actuator
    dcMotor[0]->setup(can0, 0x100);
    dcMotor[1]->setup(can0, 0x100);
    dcMotor[2]->setup(can0, 0x101);
    dcMotor[3]->setup(can0, 0x101);
    dcMotor[4]->setup(can0, 0x102);
    cylinder[0]->setup(can0, 0x200);
    cylinder[1]->setup(can0, 0x200);
    cylinder[3]->setup(can0, 0x200);
    cylinder[3]->setup(can0, 0x200);
    cylinder[4]->setup(can0, 0x200);
    cylinder[5]->setup(can0, 0x200);
    cylinder[6]->setup(can0, 0x200);
    cylinder[7]->setup(can0, 0x200);
    servoMotor[0]->setup(can0, 0x150);

    //wheelunit別にいらんかもな、ペアがわかりやすい？
    wheelUnit = new WheelUnit[4];
    wheelUnit[0]->setup(dcMotor[0], encoder[2]);
    wheelUnit[1]->setup(dcMotor[1], encoder[3]);
    wheelUnit[2]->setup(dcMotor[2], encoder[4]);
    wheelUnit[3]->setup(dcMotor[3], encoder[5]);
    mecanum = new Mecanum(wheelUnit[0], wheelUnit[1], wheelUnit[2], wheelUnit[3], encoder[0], encoder[1], mpu6050);  //4輪と接地(とIMU)
    sliderZ = new SliderZ(dcMotor[4], encoder[4], potentio[0]);
    handCircle = new Hand(cylinder[0], cylinder[1]);
    handTriangle = new Hand(cylinder[2], cylinder[3]);
    handSquare1 = new Hand(cylinder[4], cylinder[5]);
    handSquare2 = new Hand(cylinder[6], cylinder[8]);
}

AmazingAdventureOfMecanumTheRide4A3S::~AmazingAdventureOfMecanumTheRide4A3S()
{
    delete mecanum;
    delete sliderZ;
    delete handCircle;
    delete handTriangle;
    delete handSquare1;
    delete handSquare2;
}

void AmazingAdventureOfMecanumTheRide4A3S::stateTransition(void)
{
    //モード変更(状態遷移)
    //コントローラ
    if(m_state == NODEFINITE)
    {
        //if() m_state++;
        //else break;
    }
    if(psCon.pressButton(Circle))
    {
        m_state++;
    }


}

void AmazingAdventureOfMecanumTheRide4A3S::updateTarget(void)
{

    switch(m_machineState)
    {
    case INDEFINITE:
        //m_mode++;
        break;
    case INITIALIZING:
        //initialize();
        break;
    case MANUAL:
        manual();
        break;
    case MATCH:
        match();
        break;
    case STOP:
        break;
    case EMERGENCY_STOP:
        //遷移不能
        break;
    default:
        m_mode = EMERGENCY_STOP;
        break;
    }
}

//! @param out
//!     終了:0  処理中:1
bool AmazingAdventureOfMecanumTheRide4A3S::manual(void)
{
    //psコンの値に従い各モータの目標値を決定

    return false;
}

////! @param out
////!     終了:0  処理中:1
//bool AmazingAdventureOfMecanumTheRide4A3S::change(void)
//{
//
//    return false;
//}

//! @param out
//!     終了:0  処理中:1
bool AmazingAdventureOfMecanumTheRide4A3S::autoRed(void)
{
    switch(m_autoState)
    {

    default:
        break;
    }

    return false;
}

bool AmazingAdventureOfMecanumTheRide4A3S::match()
{
    switch(m_matchState)
    {
    case NOT_MATCH:
        return true;
        break;
    case SETTING:
        setting();
    case AUTO_MOVE0:
        //スタート
        break;
    case MANUAL_MOVE0:
        break;
    case GET_OBJECT0:
        break;
    case CHANGE:
        change();
        break;
    case AUTO:
        //if()        autoRed();
        //else if()   autoBlue();
        break;
    case END:
        //PSコン
        //if() return true;
        break;
    default:
        break;
    }
}