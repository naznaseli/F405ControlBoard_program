#include "TIM.hpp"


void TIM::setup(TIM_TypeDef* TIMx, uint16_t prescaler, uint32_t interruptTime)
{
    setup(TIMx, TimMode::TIMER);

    //更新割り込みリクエスト許可
    TIMx->DIER = TIM_DIER_UIE;

    TIMx->PSC = prescaler - 1;
    TIMx->ARR = (TIMXCLK * interruptTime) / (prescaler * 1000) - 1;
    resetCount();
    //enableCount();

}

void TIM::setup(TIM_TypeDef* TIMx, TimMode timMode)
{
    m_TIMx = TIMx;
    m_timMode = timMode;

    if(TIMx == TIM1)
    {
        //writeBit();
    }
    if(TIMx == TIM2)
    {

    }
    if(TIMx == TIM3)
    {

    }
    if(TIMx == TIM4)
    {

    }
}
