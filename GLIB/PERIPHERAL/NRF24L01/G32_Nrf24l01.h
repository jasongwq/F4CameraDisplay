#ifndef _NRF24L01_H_
#define _NRF24L01_H_
#include "stm32f10x.h"
#include "stm32_config.h"
//#include "spi.h"    //nrf24l01需要spi.h中的u8 Spi_RW(u8 dat)函数

///*使用硬件SPI 1 or 2*/
////#define NRF24L01_SPI1
//#define NRF24L01_SPI2
///*使用软件SPI*/
////#define NRF24L01_SPISOFT

///*配置SPI_NRF_SPI的CE引脚*/
//#define NRF24l01_CE_RCC  RCC_APB2Periph_GPIOB
//#define NRF24l01_CE_GPIO GPIOB
//#define NRF24l01_CE_PIN  GPIO_Pin_11
///*配置SPI_NRF_SPI的 CSN 引脚*/
//#define NRF24l01_CSN_RCC  RCC_APB2Periph_GPIOC
//#define NRF24l01_CSN_GPIO GPIOC
//#define NRF24l01_CSN_PIN  GPIO_Pin_6
///*配置SPI_NRF_SPI的IRQ引脚*/
//#define NRF24l01_IQR_RCC  RCC_APB2Periph_GPIOC
//#define NRF24l01_IQR_GPIO GPIOC
//#define NRF24l01_IQR_PIN  GPIO_Pin_7

//#ifdef NRF24L01_SPISOFT
//	/*配置SPI_NRF_SPI的 MOSI 引脚*/
//	#define NRF24l01_MOSI_RCC  RCC_APB2Periph_GPIOB
//	#define NRF24l01_MOSI_GPIO GPIOB
//	#define NRF24l01_MOSI_PIN  GPIO_Pin_15
//	/*配置SPI_NRF_SPI的 SIMO 引脚*/
//	#define NRF24l01_SIMO_RCC  RCC_APB2Periph_GPIOB
//	#define NRF24l01_SIMO_GPIO GPIOB
//	#define NRF24l01_SIMO_PIN  GPIO_Pin_14
//	/*配置SPI_NRF_SPI的 SCL(SCK) 引脚*/
//	#define NRF24l01_SCL_RCC   RCC_APB2Periph_GPIOB
//	#define NRF24l01_SCL_GPIO  GPIOB
//	#define NRF24l01_SCL_PIN   GPIO_Pin_13
//#endif


#ifdef NRF24L01_SPISOFT
	#define NRF24l01_SPI_SCL_H   GPIO_SetBits  (NRF24l01_SCL_GPIO, NRF24l01_SCL_PIN);
	#define NRF24l01_SPI_SCL_L   GPIO_ResetBits(NRF24l01_SCL_GPIO, NRF24l01_SCL_PIN);
	#define NRF24l01_SPI_MOSI_H  GPIO_SetBits  (NRF24l01_MOSI_GPIO, NRF24l01_MOSI_PIN);
	#define NRF24l01_SPI_MOSI_L  GPIO_ResetBits(NRF24l01_MOSI_GPIO, NRF24l01_MOSI_PIN);
	#define NRF24l01_SPI_SIMO    GPIO_ReadInputDataBit(NRF24l01_SIMO_GPIO,NRF24l01_SCL_PIN);
#endif
#define SPI_CE_H()   GPIO_SetBits  (NRF24l01_CE_GPIO, NRF24l01_CE_PIN)
#define SPI_CE_L()   GPIO_ResetBits(NRF24l01_CE_GPIO, NRF24l01_CE_PIN)
#define SPI_CSN_H()  GPIO_SetBits  (NRF24l01_CSN_GPIO, NRF24l01_CSN_PIN)
#define SPI_CSN_L()  GPIO_ResetBits(NRF24l01_CSN_GPIO, NRF24l01_CSN_PIN)

//***************************************NRF24L01寄存器指令*******************************************************
#define NRF_READ_REG    0x00  // 读寄存器指令
#define NRF_WRITE_REG   0x20    // 写寄存器指令
#define R_RX_PL_WID     0x60
#define RD_RX_PLOAD     0x61  // 读取接收数据指令
#define WR_TX_PLOAD     0xA0  // 写待发数据指令
#define FLUSH_TX        0xE1    // 冲洗发送 FIFO指令
#define FLUSH_RX        0xE2  // 冲洗接收 FIFO指令
#define REUSE_TX_PL     0xE3  // 定义重复装载数据指令
#define NOP             0xFF  // 保留
//*************************************SPI(nRF24L01)寄存器地址****************************************************
#define CONFIG          0x00  // 配置收发状态，CRC校验模式以及收发状态响应方式
#define EN_AA           0x01  // 自动应答功能设置
#define EN_RXADDR       0x02  // 可用信道设置
#define SETUP_AW        0x03  // 收发地址宽度设置
#define SETUP_RETR      0x04  // 自动重发功能设置
#define RF_CH           0x05  // 工作频率设置
#define RF_SETUP        0x06  // 发射速率、功耗功能设置
#define NRFRegSTATUS    0x07  // 状态寄存器
#define OBSERVE_TX      0x08  // 发送监测功能
#define CD              0x09  // 地址检测           
#define RX_ADDR_P0      0x0A  // 频道0接收数据地址
#define RX_ADDR_P1      0x0B  // 频道1接收数据地址
#define RX_ADDR_P2      0x0C  // 频道2接收数据地址
#define RX_ADDR_P3      0x0D  // 频道3接收数据地址
#define RX_ADDR_P4      0x0E  // 频道4接收数据地址
#define RX_ADDR_P5      0x0F  // 频道5接收数据地址
#define TX_ADDR         0x10  // 发送地址寄存器
#define RX_PW_P0        0x11  // 接收频道0接收数据长度
#define RX_PW_P1        0x12  // 接收频道1接收数据长度
#define RX_PW_P2        0x13  // 接收频道2接收数据长度
#define RX_PW_P3        0x14  // 接收频道3接收数据长度
#define RX_PW_P4        0x15  // 接收频道4接收数据长度
#define RX_PW_P5        0x16  // 接收频道5接收数据长度
#define FIFO_STATUS     0x17  // FIFO栈入栈出状态寄存器设置
//*********************************************NRF24L01*************************************
#define RX_DR   6       //中断标志
#define TX_DS   5
#define MAX_RT  4

#define MODEL_RX    1   //普通接收
#define MODEL_TX    2   //普通发送
#define MODEL_RX2   3   //接收模式2,用于双向传输
#define MODEL_TX2   4   //发送模式2,用于双向传输

#define RX_PLOAD_WIDTH  32
#define TX_PLOAD_WIDTH  32
#define TX_ADR_WIDTH    5
#define RX_ADR_WIDTH    5

extern  u8  NRF24L01_RXDATA[RX_PLOAD_WIDTH];    //nrf24l01接收到的数据
extern  u8  NRF24L01_TXDATA[RX_PLOAD_WIDTH];    //nrf24l01需要发送的数据
extern  u8  NRF24L01_TXDATA_RC[RX_PLOAD_WIDTH]; //nrf24l01需要发送的数据
void Nrf24l01_Init(u8 model, u8 ch);                //初始化,model=1/2/3/4,ch为实用的通道号
void NRF_TxPacket(uint8_t* tx_buf, uint8_t len);    //发送数据包,用于model 2/4
void NRF_TxPacket_AP(uint8_t* tx_buf, uint8_t len); //发送数据包,用于model 3
uint8_t NRF_Read_Reg(uint8_t reg);
uint8_t NRF_Write_Reg(uint8_t reg, uint8_t value);
uint8_t NRF_Read_Buf(uint8_t reg, uint8_t* pBuf, uint8_t uchars);
uint8_t Nrf24l01_Check(void);
extern u8 SPI1_ReadWriteByte(u8 TxData);
extern u8 SPI2_ReadWriteByte(u8 TxData);

#endif
/*
黑板 黄板
CE  PB11
CSN PC6
IRQ PC7
*/
