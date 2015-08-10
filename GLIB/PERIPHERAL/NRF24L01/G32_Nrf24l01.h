#ifndef _NRF24L01_H_
#define _NRF24L01_H_
#include "sys.h"

/****************************************/
/***USART***/
/********************************************
***********************************************\
 * _________________ *
 * |8 IQR    7 MISO| *c1  c2
 * |               | *
 * |6 MOSI   5 SCK | *c3  a0
 * |               | *
 * |4 CSN    3 CE  | *a5  a2
 * |       --------| *
 * |2 VCC  | 1 GND | *
 * ----------------- *
\**********************************************/


enum{
MODEL_RX  = 1,//普通接收
MODEL_TX  = 2,//普通发送
MODEL_RX2 = 3,//接收模式2,用于双向传输
MODEL_TX2 = 4 //发送模式2,用于双向传输
};


extern  u8  NRF24L01_RXDATA[];    //nrf24l01接收到的数据
extern  u8  NRF24L01_TXDATA[];    //nrf24l01需要发送的数据
extern  u8  NRF24L01_TXDATA_RC[]; //nrf24l01需要发送的数据
void Nrf24l01_Init(u8 model, u8 ch);                //初始化,model=1/2/3/4,ch为实用的通道号
void NRF_TxPacket(uint8_t* tx_buf, uint8_t len);    //发送数据包,用于model 2/4
void NRF_TxPacket_AP(uint8_t* tx_buf, uint8_t len); //发送数据包,用于model 3
uint8_t NRF_Read_Reg(uint8_t reg);
uint8_t NRF_Write_Reg(uint8_t reg, uint8_t value);
uint8_t NRF_Read_Buf(uint8_t reg, uint8_t* pBuf, uint8_t uchars);
uint8_t Nrf24l01_Check(void);
void Nrf_Check_Event(void);
u8 Nrf_Get_Sta(void);
u8 Nrf_Get_FIFOSta(void);
#endif
/*
黑板 黄板
CE  PB11
CSN PC6
IRQ PC7
*/
