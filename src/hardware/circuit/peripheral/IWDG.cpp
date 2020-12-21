#include "IWDG.hpp"
#include "RCC.hpp"

//PR,RLRは書き込み保護あり

namespace iwdg
{
void setup_us(uint16_t division)
{
    IWDG->KR = 0x5555;  //アクセス保護解除

    //書き込み後の自動リセットでなぜか止まる(ハードウェアリセットを書けると通る)
    //while(IWDG->SR & IWDG_SR_PVU);  //プリスケーラ値が更新中でないことを確認
    //while(IWDG->SR & IWDG_SR_RVU);  //再ロード値が更新中でないことを確認

    if(division > 125 && division <= 250)
    {
        IWDG->PR = 0;
        IWDG->RLR = (uint16_t)(0xFFF * (double)(division / 512));
    }
    else if(division > 250 && division <= 500)
    {
        IWDG->PR = 1;
        IWDG->RLR = (uint16_t)(0xFFF * (double)(division / 1024));
    }
    else if(division > 500 && division <= 1000)
    {
        IWDG->PR = 2;
        IWDG->RLR = (uint16_t)(0xFFF * (double)(division / 2048));
    }
    else return;

    //while(IWDG->SR & IWDG_SR_PVU);  //プリスケーラ値更新完了を確認
    //while(IWDG->SR & IWDG_SR_RVU);  //再ロード値更新完了を確認

    //コア停止時に独立型ウォッチドッグを停止
    DBGMCU->APB1FZ |= DBGMCU_APB1_FZ_DBG_IWDG_STOP;
}

void setup_ms(uint16_t division)
{
    IWDG->KR = 0x5555;  //アクセス保護解除

    //書き込み後の自動リセットでなぜか止まる(ハードウェアリセットを書けると通る)
    //while((IWDG->SR & IWDG_SR_PVU) == IWDG_SR_PVU);  //プリスケーラ値が更新中でないことを確認
    //while((IWDG->SR & IWDG_SR_RVU) == IWDG_SR_RVU);  //再ロード値が更新中でないことを確認

    if(division > 1 && division <= 4096)
    {
        IWDG->PR = 3;
        IWDG->RLR = (uint16_t)((double)division/1-1) & IWDG_RLR_RL;
    }
    else if(division > 4096 && division <= 8192)
    {
        IWDG->PR = 4;
        IWDG->RLR = (uint16_t)((double)division/2-1) & IWDG_RLR_RL;
    }
    else if(division > 8192 && division <= 16384)
    {
        IWDG->PR = 5;
        IWDG->RLR = (uint16_t)((double)division/4-1) & IWDG_RLR_RL;
    }
    else if(division > 16384 && division <= 32768)
    {
        IWDG->PR = 6;
        IWDG->RLR = (uint16_t)((double)division/8-1) & IWDG_RLR_RL;
    }
    else return;

    //while(IWDG->SR & IWDG_SR_PVU);  //プリスケーラ値更新完了を確認
    //while(IWDG->SR & IWDG_SR_RVU);  //再ロード値更新完了を確認

    //コア停止時に独立型ウォッチドッグを停止
    DBGMCU->APB1FZ |= DBGMCU_APB1_FZ_DBG_IWDG_STOP;

}

void reset(void)
{
    IWDG->KR = 0xAAAA;
}

void start(void)
{
    IWDG->KR = 0xCCCC;
}

}//namespace
