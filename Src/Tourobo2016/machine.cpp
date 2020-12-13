#include "machine.hpp"

//シングルトン

AmazingAdventureOfMecanumTheRide4A3S::AmazingAdventureOfMecanumTheRide4A3S()
{

    mecanum = new Mecanum(/* モータユニットx4、エンコーダx2 */);
    sliderZ = new SliderZ(/* モータユニットx1 */);
    handCircle = new Hand(/* シリンダx2 */);
    handTriangle= new Hand(/* シリンダx2 */);
    handSquare1 = new Hand(/* シリンダx2 */);
    handSquare2 = new Hand(/* シリンダx2 */);
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
        if() m_state++;
        else break;

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