#ifndef __SYS_H
#define __SYS_H	
#include "stm32f4xx.h"

//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32开发板		   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/8/18
//版本：V1.7
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved
////////////////////////////////////////////////////////////////////////////////// 	 

#define DEBUG 0
																	    
//位带操作,实现51类似的GPIO控制功能
//具体实现思想,参考<<CM3权威指南>>第五章(87页~92页).
//IO口操作宏定义
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 
//IO口地址映射 //根据 F4 ODR IDR 地址 作相应修改
#define GPIOA_ODR_Addr    (GPIOA_BASE+0x14) //0x4001080C 
#define GPIOB_ODR_Addr    (GPIOB_BASE+0x14) //0x40010C0C 
#define GPIOC_ODR_Addr    (GPIOC_BASE+0x14) //0x4001100C 
#define GPIOD_ODR_Addr    (GPIOD_BASE+0x14) //0x4001140C 
#define GPIOE_ODR_Addr    (GPIOE_BASE+0x14) //0x4001180C 
#define GPIOF_ODR_Addr    (GPIOF_BASE+0x14) //0x40011A0C    
#define GPIOG_ODR_Addr    (GPIOG_BASE+0x14) //0x40011E0C    

#define GPIOA_IDR_Addr    (GPIOA_BASE+0x10) //0x40010808 
#define GPIOB_IDR_Addr    (GPIOB_BASE+0x10) //0x40010C08 
#define GPIOC_IDR_Addr    (GPIOC_BASE+0x10) //0x40011008 
#define GPIOD_IDR_Addr    (GPIOD_BASE+0x10) //0x40011408 
#define GPIOE_IDR_Addr    (GPIOE_BASE+0x10) //0x40011808 
#define GPIOF_IDR_Addr    (GPIOF_BASE+0x10) //0x40011A08 
#define GPIOG_IDR_Addr    (GPIOG_BASE+0x10) //0x40011E08 
 
//IO口操作,只对单一的IO口!
//确保n的值小于16!
#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)  //输出 
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)  //输入 

#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)  //输出 
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)  //输入 

#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  //输出 
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  //输入 

#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)  //输出 
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)  //输入 

#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)  //输出 
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)  //输入

#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)  //输出 
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)  //输入

#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)  //输出 
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)  //输入

#define BYTE0(dwTemp)       (* (char *)(&(dwTemp)))
#define BYTE1(dwTemp)       (*((char *)(&(dwTemp)) + 1))
#define BYTE2(dwTemp)       (*((char *)(&(dwTemp)) + 2))
#define BYTE3(dwTemp)       (*((char *)(&(dwTemp)) + 3))

#define WORD0(dwTemp)       (* (int16_t *)(&dwTemp))
#define WORD1(dwTemp)       (*((int16_t *)(&dwTemp) + 1))

#define Set_Bit(Bety,n)  ((Bety)|= (1<<(n)))
#define Clr_Bit(Bety,n)  ((Bety)&=!(1<<(n)))
#define Read_Bit(Bety,n) (((Bety)>>(n))&(1))

//#define false FALSE
//#define true TRUE
//#define bool BOOL
//typedef enum{FALSE = -1,TRUE =0}BOOL;

void NVIC_Configuration(void);

#if DEBUG
#define Dprintf printf
#else
#define Dprintf /\
/Dprintf
#endif

#endif
