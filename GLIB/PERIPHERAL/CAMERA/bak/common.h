#ifndef __COMMOM_H
#define __COMMOM_H

#include "stm32f4xx.h"
//#include "tm_stm32f4_ili9341.h"

#define DMA_CameraToRAM_Stream   		    DMA2_Stream7
#define DMA_Camera_Channel         		  DMA_Channel_1
#define DMA_Camera_STREAM_CLOCK    		  RCC_AHB1Periph_DMA2
#define DMA_Camera_STREAM_IRQ      		  DMA2_Stream7_IRQn
#define DMA_Camera_IT_TCIF         		  DMA_IT_TCIF7
#define DMA_Camera_STREAM_IRQHANDLER    DMA2_Stream7_IRQHandler

#define picture_x 320
#define picture_y 240

extern __IO uint16_t RAM_Buffer[picture_x * picture_y];

/*----------OV7670 DCMI º¯Êý---------*/
u8 OV7670_Init(void);
void Cam_Init(void);
void GPIO_Configuration(void);
void DCMI_NVIC_Config(void);

void SCCB_Init(void);
void SCCB_SID_DATA_OUT(void);
void SCCB_SID_DATA_IN(void);
void OV_Reset(void);
u8 OV_WriteReg(u8 regID, u8 regDat);
void SCCB_Start(void);
void SCCB_Stop(void);
u8 SCCB_Write(u8 m_data);
u8 OV_ReadID(void);
u8 OV_ReadReg(u8 regID, u8 *regDat);
void noAck(void);
u8 SCCB_Read(void);
void OV7670_HW(u16 hstart,u16 vstart,u16 hstop,u16 vstop);
void Cam_Start(void);
void OV7670_config_window(u16 startx,u16 starty,u16 width,u16 height);

#endif
