#ifndef _NRF24L01_CONFIG_H_
#define _NRF24L01_CONFIG_H_
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

/***24L01配置***/
/*使用硬件SPI 1 or 2*/
//#define NRF24L01_SPI1
//#define NRF24L01_SPI2
/*使用软件SPI*/
#define NRF24L01_SPI0

#define RX_PLOAD_WIDTH  32
#define TX_PLOAD_WIDTH  32
#define TX_ADR_WIDTH    5
#define RX_ADR_WIDTH    5


#define NRF24l01_CE_Init  PA2_OUT
#define NRF24l01_CSN_Init PA5_OUT
#define NRF24l01_IQR_Init PC1_In

#define SPI_CE_H()   Set_A2
#define SPI_CE_L()   Clr_A2
#define SPI_CSN_H()  Set_A5
#define SPI_CSN_L()  Clr_A5

u8  TX_ADDRESS[TX_ADR_WIDTH] = {0xE1, 0xE2, 0xE3, 0x44, 0xE5}; //本地地址
u8  RX_ADDRESS[RX_ADR_WIDTH] = {0xE1, 0xE2, 0xE3, 0x44, 0xE5}; //接收地址
#endif
/*
黑板 黄板
CE  PB11
CSN PC6
IRQ PC7
*/
