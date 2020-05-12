#include "sensor.hpp"

Sensor::Sensor()
{
    //各種センサクラスセットアップ
    //ローカル(制御基板上)orCAN
    //enc[] = new Encoder(ENC_NUM);
    //Potentio potentio[POTENTIO_NUM];
    //LimitSw limitSw[LIMITSW_NUM];
}

Sensor::~Sensor()
{

}

void Sensor::input(void)
{
    //ローカルのエンコーダx4
    //ローカルのADCx4
    //

}
