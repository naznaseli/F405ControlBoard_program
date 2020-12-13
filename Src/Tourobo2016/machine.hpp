#pragma once

#include "mechanism/under_carriage.hpp"
#include "mechanism/slider_z.hpp"
#include "mechanism/hand.hpp"

//回路関連
//SIXAXIS sixaxis3;
//Imu mpu6050;

//マシン関連

//マシン全体管理みたいな？
//非常停止？
typedef enum
{
    ERROR = -1, NONE, INITIALIZE, MANUAL, AUTO
}MACHINE_STATE;

typedef enum
{
    RED, BLUE
}ZONE;

typedef enum
{
    START, CHANGE, MANUAL, AUTO
}AREA;

class AmazingAdventureOfMecanumTheRide4A3S
{
private:
    //ステートマシンで紙に書いて考察→実装
    typedef enum
    {
        INDEFINITE,     //不定、電源投入後
        INITIALIZING,   //初期化中
        MANUAL,         //手動操作、基本コントローラ依存
        AUTO,
        STOP,           //動力停止状態
        EMERGENCY_STOP  //緊急停止、リセット以外なし
    }MACHINE_MODE;
    MACHINE_MODE m_machineState = NONE_INIT;
    typedef enum
    {
        STEP0,
        STEP1,
        STEP2,
        STEP3,
        STEP4,
        STEP5
    }MACHINE_AUTOSTATE; //自動時のステート
    MACHINE_AUTOSTATE m_autoState = STEP0;
    typedef enum
    {
        NOT_MATCH,      //試合じゃない
        SETTING,        //セッティング中、スタート前
        AUTO_MOVE0,     //△へ
        MANUAL_MOVE0,   
        GET_OBJETC0,
        AUTO_MOVE1,     //□へ
        MANUAL_MOVE1,   
        GET_OBJETC1,
        AUTO_MOVE2,     //○へ
        MANUAL_MOVE2,
        GET_OBJETC2,
        AUTO_MOVE3,     //□へ
        MANUAL_MOVE3,
        GET_OBJETC3,
        TO_CHANGE,      //チェンジゾーンへ
        CHANGE,
        AUTO,
        END
    }MACHINE_MATCHSTEP;    //試合ステップ
    MACHINE_MATCHSTEP m_matchStep = NOT_MATCH;

public:
    void manual(void);
    void auto(void);
    void initialize(void);


private:
    //:******************************
    //! machine
    //:******************************
    //足回り
    //Mecanum* mecanum;
    //上部
    //SliderZ* slider;
    //Hand* handCircle(/*使うシリンダユニットのポインタ*/);
    //Hand* handTriangle;
    //Hand* handSquare1;
    //Hand* handSquare2;

    //別ファイル分けてもいいかもね
    //:******************************
    //! circuit
    //:******************************
    //Led* m_ledCircuit;
    //Led* m_ledRound;
    //Button* m_buttonCircuit;
    //Button* m_buttonIOBoard;
    //UserEncoder* m_userEnc;

};
