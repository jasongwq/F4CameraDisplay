#ifndef __FSMC_TFT_H
#define __FSMC_TFT_H

#include "sys.h"


#define TFT_DATA_ADD       ((uint32_t)(BAS_ADD | USEADD))     //数据地址
#define TFT_REG_ADD        ((uint32_t)BAS_ADD)	              //寄存器地址
#define FSMC_WR_REG(x);    FSMC_WRITE_REG(x);      
#define FSMC_WR_DATA(x);   FSMC_WRITE_DATA(x);
#define FSMC_WR_CMD(x,y);  {*(__IO uint16_t *)TFT_REG_ADD= x; *(__IO uint16_t *)TFT_DATA_ADD= y;}


#define RS_USE  16   // 14 表示  A16  对应IO可看下面
#define CS_USE  1    // 1  表示  NE1  对应IO可看下面
//      RD           // PD4  NOE 
//      WR           // PD5  NWE

/*  RS_USE 选择                            CS_USE  选择
ADD0   PF0               D0    PD14        NE1  PD7     0x6000 0000
ADD1   PF1               D1    PD15        NE2  PG9     0x6400 0000
ADD2   PF2               D2    PD0         NE3  PG10    0x6800 0000
ADD3   PF3               D3    PD1         NE4  PG12    0x6C00 0000
ADD4   PF4               D4    PE7
ADD5   PF5               D5    PE8
ADD6   PF12              D6    PE9
ADD7   PF13              D7    PE10
ADD8   PF14              D8    PE11
ADD9   PF15              D9    PE12
ADD10  PG0               D10   PE13
ADD11  PG1               D11   PE14
ADD12  PG2               D12   PE15
ADD13  PG3               D13   PD8
ADD14  PG4               D14   PD9
ADD15  PG5               D15   PD10
ADD16  PD11           
ADD17  PD12              NOE   PD4
ADD18  PD13              NWE   PD5
ADD19  PE3               NWAIT PD6
ADD20  PE4               
ADD21  PE5              
ADD22  PE6  
ADD23  PE2
ADD24  PG13
ADD25  PG14
     			 

*/

#if CS_USE==1              // PD7
    #define BAS_ADD   0x60000000
#elif CS_USE==2            // PG9
    #define BAS_ADD   0x64000000
#elif CS_USE==3            // PG10
    #define BAS_ADD   0x68000000
#elif CS_USE==4            // PG12
    #define BAS_ADD   0x6C000000
#endif

#if RS_USE==0              // PF0
   #define USEADD   0X2
#elif RS_USE==1            // PF1
    #define USEADD   0X4
#elif RS_USE==2            // PF2
    #define USEADD   0X8
#elif RS_USE==3            // PF3
    #define USEADD   0X10
#elif RS_USE==4            // PF4
    #define USEADD   0X20
#elif RS_USE==5            // PF5
    #define USEADD   0X40
#elif RS_USE==6            // PF12
    #define USEADD   0X80
#elif RS_USE==7            // PF13
    #define USEADD   0X100
#elif RS_USE==8            // PF14
    #define USEADD   0X200
#elif RS_USE==9            // PF15
    #define USEADD   0X400
#elif RS_USE==10           // PG0
    #define USEADD   0X800
#elif RS_USE==11           // PG1
    #define USEADD   0X1000
#elif RS_USE==12           // PG2    
    #define USEADD   0X2000
#elif RS_USE==13           // PG3
    #define USEADD   0X4000
#elif RS_USE==14           // PG4
    #define USEADD   0X8000
#elif RS_USE==15           // PG5
    #define USEADD   0X10000
#elif RS_USE==16           // PD11
    #define USEADD   0X20000
#elif RS_USE==17           // PD12
    #define USEADD   0X40000
#elif RS_USE==18           // PD13
    #define USEADD   0X80000
#elif RS_USE==19           // PE3
    #define USEADD   0X100000
#elif RS_USE==20           // PE4
    #define USEADD   0X200000
#elif RS_USE==21           // PE5
    #define USEADD   0X400000
#elif RS_USE==22           // PE6
    #define USEADD   0X800000
#elif RS_USE==23           // PE2
    #define USEADD   0X1000000
#elif RS_USE==24           // PG13
    #define USEADD   0X2000000
#elif RS_USE==25           // PG14
    #define USEADD   0X4000000
#endif

void FSMC_LCD_Init(void);
void Fsmc_D_16_Init(void);
void FSMC_RS_CS_Init(void);
void FSMC_WRITE_REG(u16 x);
void FSMC_WRITE_DATA(u16 x);

#endif
