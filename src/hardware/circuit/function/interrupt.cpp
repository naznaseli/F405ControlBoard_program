#include "interrupt.hpp"
#include "../F405ControlBoard.hpp"

#define CAN_SID_MD0 0x100
#define CAN_SID_MD1 0x102
#define CAN_SID_MD2 0x104
#define CAN_SID_MD3 0x106
#define CAN_SID_MD4 0x108
#define CAN_SID_MD5 0x10A
#define CAN_SID_MD6 0x10C
#define CAN_SID_MD7 0x10E

#define CAN_SID_IO0 0x200
#define CAN_SID_IO1 0x202
#define CAN_SID_IO2 0x204
#define CAN_SID_IO3 0x206
#define CAN_SID_IO4 0x208
#define CAN_SID_IO5 0x20A
#define CAN_SID_IO6 0x20C
#define CAN_SID_IO7 0x20E

typedef struct
{
    uint8_t sid;
    uint8_t length;
    uint8_t data[8];
}CanData;

void TIM1_IRQHandler(void)
{

}

void TIM2_IRQHandler(void)
{

}

//1ms interrupt
void TIM3_IRQHandler(void)
{
    //多重割り込み禁止
    //ProtectInterrupt pi;

    //board->interrupt_1ms();
}

//10ms interrupt
void TIM4_IRQHandler(void)
{
    //board->interrupt_10ms();

    //センサ更新
    //sensor.input();

    //**********************************************************************
    //制御
    //**********************************************************************

    //アクチュエータ更新
    //actuator.output();

}

void CAN1_TX_IRQHandler(void)
{

}

void CAN1_RX0_IRQHandler(void)
{
    //static CanData canData;
    //usart1.printf("received0");
    if(CAN1->RF0R & CAN_RF1R_FMP1)
    {
        //usart1.printf("FMP");
        //usart1.printf("%u\n", (uint32_t)(CAN1->RF0R & 0x03));

        //キューに入れる

        //その場で解析
        //calcCanPacket(&canData);
    }
}

void CAN1_RX1_IRQHandler(void)
{
    //usart1.printf("received1");
}

void CAN1_SCE_IRQHandler(void)
{

}

void calcCanPacket()
{
    //switch(canData->SID)
    switch(1)
    {
    //MD
    case CAN_SID_MD0:
    case CAN_SID_MD1:
    case CAN_SID_MD2:
    case CAN_SID_MD3:
    case CAN_SID_MD4:
    case CAN_SID_MD5:
    case CAN_SID_MD6:
    case CAN_SID_MD7:
        for(int i = 0; i < 2; i++)
        {
            //Encoder[i] = (uint8_t)(canData->data[i] | (uint8_t)(canData->data[i]) << 8);
            //Potentio[i] = (uint8_t)(canData->data[i]) | (uint8_t)(canData->data[i] << 8);
            //LimitSw[i] = (uint8_t)(canData->data[i]) | (uint8_t)(canData->data[i] << 8);
        }
        break;
    
    //IO_Board
    case CAN_SID_IO0:
    case CAN_SID_IO1:
    case CAN_SID_IO2:
    case CAN_SID_IO3:
    case CAN_SID_IO4:
    case CAN_SID_IO5:
    case CAN_SID_IO6:
    case CAN_SID_IO7:
        for(int i = 0; i < 2; i++)
        {

        }
        break;

    default:
        break;

    }
}
