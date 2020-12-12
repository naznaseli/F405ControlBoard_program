#pragma once

//ローカルのエンコーダと通信で得られるエンコーダを隠す
class Encoder
{
public:
    //直、通信形式、選択
    Encoder(SensorType type);

private:
    SensorType m_type;
};
