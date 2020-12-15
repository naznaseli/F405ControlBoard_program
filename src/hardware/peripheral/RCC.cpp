#include "RCC.hpp"

//PERIPH->REGにのビットをVALにする
#define writeBit(PERIPH, REG, SYM, VAL) (PERIPH->REG)=((PERIPH->REG)&(~PERIPH##_##REG##_##SYM##_Msk))|(VAL<<PERIPH##_##REG##_##SYM##_Pos)
#define writeReg(PERIPH, REG, VAL)      ()
#define readBit(PERIPH, REG, SYM)       (((PERIPH->REG)&PERIPH##_##REG##_##SYM##_Msk)>>PERIPH##_##REG##_##SYM##_Pos)
#define readReg(PERIPH, REG)            ()

void RCC_Setup_72MHz(void)
{

}

void RCC_Setup_144MHz(void)
{

}

void RCC_Setup_168MHz(void)
{
    //:**********************************************************************
    //!
    //! AHB
    //! FCLK    :MHz
    //! APB1 Peripheral clock    :MHz
    //! APB1 Timer clock    :MHz
    //! APB2 Peripheral clock(PCLK2) :MHz
    //! APB2 Timer clock    :MHz
    //! FLIT
    //!
    //:**********************************************************************
    //writeBit(RCC, CR, PLLON, 0);
    //while(readBit(RCC, CR, PLLRDY) == 1);   //PLL停止待ち

    //writeBit(RCC, CR, HSEON, 1);
    //while(readBit(RCC, CR, HSERDY) == 0);   //HSE動作待ち
    //writeBit(RCC, CFGR, PLLMULL, 0x4);      //PLLx6=72MHz
    ////writeBit(RCC, CFGR, PLLMULL, 0x7);      //PLLx9=72MHz
    //writeBit(RCC, CFGR, PLLSRC, 1);         //PLLソースにHSE
    //writeBit(RCC, CFGR, PPRE1, 0x4);        //2分周
    //writeBit(RCC, CFGR, SW, 0x2);           //システムクロックにPLL使用
    //writeBit(FLASH, ACR, LATENCY, 4);       //FLASH読み込みの遅延時間設定
    
    //writeBit(RCC, CR, PLLON, 1);
    //while(readBit(RCC, CR, PLLRDY) == 0);   //PLL安定化待ち

    RCC->CR &= ~RCC_CR_PLLON;
    while(RCC->CR & RCC_CR_PLLRDY);	//PLL停止待ち
    //while(!(RCC->CR & RCC_CR_PLLRDY));  //PLL安定化待ち

#if 1
    //HSE文集
    RCC->CR |= RCC_CR_HSEON;  //HSEON
    while((RCC->CR & RCC_CR_HSERDY) == 0);  //HSE動作待ち
    RCC->PLLCFGR = 0x04402A06;
    RCC->CFGR = 0x000C9402;
#endif
#if 0
    //HSI分周
    RCC->CR |= RCC_CR_HSION;    //HSION
    while((RCC->CR & RCC_CR_HSIRDY) == 0);
    RCC->PLLCFGR = 0x04002A08;
    RCC->CFGR = 0x000C9402;
#endif

    FLASH->ACR &= ~FLASH_ACR_LATENCY;  //FLASH読み込みの遅延時間設定
    FLASH->ACR |= FLASH_ACR_LATENCY_5WS;  //FLASH読み込みの遅延時間設定

    RCC->CR |= RCC_CR_PLLON;
    while(!(RCC->CR & RCC_CR_PLLRDY));  //PLL安定化待ち
    //while(RCC->CR & RCC_CR_PLLRDY);	//PLL停止待ち
}
