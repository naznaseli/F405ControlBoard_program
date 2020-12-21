#pragma once

#ifdef __cplusplus
extern "C"{
#endif
//extern void TIM1_IRQHandler(void);
//extern void TIM2_IRQHandler(void);
//extern void TIM3_IRQHandler(void);
//extern void TIM4_IRQHandler(void);
extern void TIM6_DAC_IRQHandler(void);
extern void TIM7_IRQHandler(void);
extern void TIM1_BRK_TIM9_IRQHandler(void);
extern void TIM1_UP_TIM10_IRQHandler(void);
#ifdef __cplusplus
}
#endif

//! 多重割り込み禁止
class ProtectInterrupt
{
public:
    ProtectInterrupt()
    {
        //__disable_irq();
    };

    ~ProtectInterrupt()
    {
        //__enable_irq();
    };
};
