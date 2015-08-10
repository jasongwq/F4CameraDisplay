#include "FSMC_TFT.h"

void FSMC_LCD_Init(void)
{

    FSMC_NORSRAMInitTypeDef        FSMC_NORSRAMInitStructure;
    FSMC_NORSRAMTimingInitTypeDef  readWriteTiming, writeTiming;

    /*-- FSMC Configuration ------------------------------------------------------*/

    RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FSMC, ENABLE);

    readWriteTiming.FSMC_AddressSetupTime = 4;//0x01;          //地址建立时间（ADDSET）为2个HCLK 1/36M=27ns
    readWriteTiming.FSMC_AddressHoldTime = 0x00;           //地址保持时间（ADDHLD）模式A未用到
    readWriteTiming.FSMC_DataSetupTime = 0x0f;             // 数据保存时间为16个HCLK,因为液晶驱动IC的读数据的时候，速度不能太快，尤其对1289这个IC。
    readWriteTiming.FSMC_BusTurnAroundDuration = 0x00;
    readWriteTiming.FSMC_CLKDivision = 0x00;
    readWriteTiming.FSMC_DataLatency = 0x00;
    readWriteTiming.FSMC_AccessMode = FSMC_AccessMode_A; //模式A

    writeTiming.FSMC_AddressSetupTime = 4;             //地址建立时间（ADDSET）为1个HCLK
    writeTiming.FSMC_AddressHoldTime = 0x00;               //地址保持时间（A
    writeTiming.FSMC_DataSetupTime = 0x08;                 //数据保存时间为4个HCLK
    writeTiming.FSMC_BusTurnAroundDuration = 0x00;
    writeTiming.FSMC_CLKDivision = 0x00;
    writeTiming.FSMC_DataLatency = 0x00;
    writeTiming.FSMC_AccessMode = FSMC_AccessMode_A;       //模式A
    //
#if CS_USE==1              // PD7
    FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM1;
#elif CS_USE==2            // PG9
    FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM2;
#elif CS_USE==3            // PG10
    FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM3;
#elif CS_USE==4            // PG12
    FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM4;
#endif
    FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;// 不复用数据地址
    FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_SRAM;// FSMC_MemoryType_SRAM;  //SRAM
    FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;//存储器数据宽度为16bit
    FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;

    FSMC_NORSRAMInitStructure.FSMC_AsynchronousWait = FSMC_AsynchronousWait_Disable;//f4

    FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
    FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;
    FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
    FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;//  存储器写使能
    FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
    FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Enable; // 读写使用不同的时序
    FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;
    FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &readWriteTiming;
    FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &writeTiming;

    FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure);

#if CS_USE==1              // PD7
    FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM1, ENABLE);
#elif CS_USE==2            // PG9
    FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM2, ENABLE);
#elif CS_USE==3            // PG10
    FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM3, ENABLE);
#elif CS_USE==4            // PG12
    FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM4, ENABLE);
#endif


    FSMC_RS_CS_Init();
    Fsmc_D_16_Init();
}
void Fsmc_D_16_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    //  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE , ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOE,   ENABLE);

    //PORTD复用推挽输出
    /* GPIOD configuration */
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource0, GPIO_AF_FSMC);//D2
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource1, GPIO_AF_FSMC);//D3
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource4, GPIO_AF_FSMC);//NOE
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource5, GPIO_AF_FSMC);//NWE
    //    GPIO_PinAFConfig(GPIOD, GPIO_PinSource7, GPIO_AF_FSMC);//NE1
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource8, GPIO_AF_FSMC);//D13
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource9, GPIO_AF_FSMC);//D14
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource10, GPIO_AF_FSMC);//D15
    //    GPIO_PinAFConfig(GPIOD, GPIO_PinSource11, GPIO_AF_FSMC);//A16 RS
    //GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_FSMC);//
    //GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_FSMC);//
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_FSMC);//D0
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_FSMC);//D1

    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_14 | GPIO_Pin_15 | GPIO_Pin_0 | GPIO_Pin_1;   // D0 D1 D2 D3
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    /* GPIOE configuration */
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource7 , GPIO_AF_FSMC);//D4
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource8 , GPIO_AF_FSMC);//D5
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource9 , GPIO_AF_FSMC);//D6
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource10 , GPIO_AF_FSMC);//D7
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource11 , GPIO_AF_FSMC);//D8
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource12 , GPIO_AF_FSMC);//D9
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource13 , GPIO_AF_FSMC);//D10
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource14 , GPIO_AF_FSMC);//D11
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource15 , GPIO_AF_FSMC);//D12

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 |    // D4  D5  D6   D7
                                  GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | // D8  D9  D10  D11
                                  GPIO_Pin_15;                                            // D12
    GPIO_Init(GPIOE, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 ;                 // D13 D14 D15
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 ;                               // NOE NWE
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    //D少 7 11
}
void Fsmc_D_8_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    //  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE , ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOE,   ENABLE);

    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_14 | GPIO_Pin_15 | GPIO_Pin_0 | GPIO_Pin_1;   // D0 D1 D2 D3
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 ;    // D4 D5 D6 D7                                           // D12
    GPIO_Init(GPIOE, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 ;                               // NOE NWE
    GPIO_Init(GPIOD, &GPIO_InitStructure);
}
void FSMC_RS_CS_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    //  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE
    //                       | RCC_APB2Periph_GPIOF | RCC_APB2Periph_GPIOG  , ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOE
                           | RCC_AHB1Periph_GPIOF | RCC_AHB1Periph_GPIOG  ,   ENABLE);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    //GPIO_Init(GPIOD, &GPIO_InitStructure);

#if RS_USE==0              // PF0
    {
        GPIO_PinAFConfig(GPIOF, GPIO_PinSource0, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0;
        GPIO_Init(GPIOF, &GPIO_InitStructure);
    }
#elif RS_USE==1            // PF1
    {
        GPIO_PinAFConfig(GPIOF, GPIO_PinSource1, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_1;
        GPIO_Init(GPIOF, &GPIO_InitStructure);
    }
#elif RS_USE==2            // PF2
    {
        GPIO_PinAFConfig(GPIOF, GPIO_PinSource2, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_2;
        GPIO_Init(GPIOF, &GPIO_InitStructure);
    }
#elif RS_USE==3            // PF3
    {
        GPIO_PinAFConfig(GPIOF, GPIO_PinSource3, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_3;
        GPIO_Init(GPIOF, &GPIO_InitStructure);
    }
#elif RS_USE==4            // PF4
    {
        GPIO_PinAFConfig(GPIOF, GPIO_PinSource4, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_4;
        GPIO_Init(GPIOF, &GPIO_InitStructure);
    }
#elif RS_USE==5            // PF5
    {
        GPIO_PinAFConfig(GPIOF, GPIO_PinSource5, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_5;
        GPIO_Init(GPIOF, &GPIO_InitStructure);
    }
#elif RS_USE==6            // PF12
    {
        GPIO_PinAFConfig(GPIOF, GPIO_PinSource12, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_12;
        GPIO_Init(GPIOF, &GPIO_InitStructure);
    }
#elif RS_USE==7            // PF13
    {
        GPIO_PinAFConfig(GPIOF, GPIO_PinSource13, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_13;
        GPIO_Init(GPIOF, &GPIO_InitStructure);
    }
#elif RS_USE==8            // PF14
    {
        GPIO_PinAFConfig(GPIOF, GPIO_PinSource14, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_14;
        GPIO_Init(GPIOF, &GPIO_InitStructure);
    }
#elif RS_USE==9            // PF15
    {
        GPIO_PinAFConfig(GPIOF, GPIO_PinSource15, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_15;
        GPIO_Init(GPIOF, &GPIO_InitStructure);
    }
#elif RS_USE==10           // PG0
    {
        GPIO_PinAFConfig(GPIOG, GPIO_PinSource0, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0;
        GPIO_Init(GPIOG, &GPIO_InitStructure);
    }
#elif RS_USE==11           // PG1
    {
        GPIO_PinAFConfig(GPIOG, GPIO_PinSource1, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_1;
        GPIO_Init(GPIOG, &GPIO_InitStructure);
    }
#elif RS_USE==12           // PG2
    {
        GPIO_PinAFConfig(GPIOG, GPIO_PinSource2, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_2;
        GPIO_Init(GPIOG, &GPIO_InitStructure);
    }
#elif RS_USE==13           // PG3
    {
        GPIO_PinAFConfig(GPIOG, GPIO_PinSource3, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_3;
        GPIO_Init(GPIOG, &GPIO_InitStructure);
    }
#elif RS_USE==14           // PG4
    {
        GPIO_PinAFConfig(GPIOG, GPIO_PinSource4, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_4;
        GPIO_Init(GPIOG, &GPIO_InitStructure);
    }
#elif RS_USE==15           // PG5
    {
        GPIO_PinAFConfig(GPIOG, GPIO_PinSource5, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_5;
        GPIO_Init(GPIOG, &GPIO_InitStructure);
    }
#elif RS_USE==16           // PD11
    {
        GPIO_PinAFConfig(GPIOD, GPIO_PinSource11, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_11;
        GPIO_Init(GPIOD, &GPIO_InitStructure);
    }
#elif RS_USE==17           // PD12
    {
        GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_12;
        GPIO_Init(GPIOD, &GPIO_InitStructure);
    }
#elif RS_USE==18           // PD13
    {
        GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_13;
        GPIO_Init(GPIOD, &GPIO_InitStructure);
    }
#elif RS_USE==19           // PE3
    {
        GPIO_PinAFConfig(GPIOE, GPIO_PinSource3, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_3;
        GPIO_Init(GPIOE, &GPIO_InitStructure);
    }
#elif RS_USE==20           // PE4
    {
        GPIO_PinAFConfig(GPIOE, GPIO_PinSource4, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_4;
        GPIO_Init(GPIOE, &GPIO_InitStructure);
    }
#elif RS_USE==21           // PE5
    {
        GPIO_PinAFConfig(GPIOE, GPIO_PinSource5, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_5;
        GPIO_Init(GPIOE, &GPIO_InitStructure);
    }
#elif RS_USE==22           // PE6
    {
        GPIO_PinAFConfig(GPIOE, GPIO_PinSource6, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6;
        GPIO_Init(GPIOE, &GPIO_InitStructure);
    }
#elif RS_USE==23           // PE2
    {
        GPIO_PinAFConfig(GPIOE, GPIO_PinSource2, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_2;
        GPIO_Init(GPIOE, &GPIO_InitStructure);
    }
#elif RS_USE==24           // PG13 
    {
        GPIO_PinAFConfig(GPIOG, GPIO_PinSource13, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_13;
        GPIO_Init(GPIOG, &GPIO_InitStructure);
    }
#elif RS_USE==24           // PG14 
    {
        GPIO_PinAFConfig(GPIOG, GPIO_PinSource14, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_14;
        GPIO_Init(GPIOG, &GPIO_InitStructure);
    }
#endif


#if CS_USE==1
    {
        GPIO_PinAFConfig(GPIOD, GPIO_PinSource7, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_7;
        GPIO_Init(GPIOD, &GPIO_InitStructure);
    }
#elif CS_USE==2
    {
        GPIO_PinAFConfig(GPIOG, GPIO_PinSource9, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_9;
        GPIO_Init(GPIOG, &GPIO_InitStructure);
    }
#elif CS_USE==3
    {
        GPIO_PinAFConfig(GPIOG, GPIO_PinSource10, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10;
        GPIO_Init(GPIOG, &GPIO_InitStructure);
    }
#elif CS_USE==4
    {
        GPIO_PinAFConfig(GPIOG, GPIO_PinSource12, GPIO_AF_FSMC);
        GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_12;
        GPIO_Init(GPIOG, &GPIO_InitStructure);
    }
#endif
}
void FSMC_WRITE_REG(u16 x)
{
    *(__IO uint16_t *)TFT_REG_ADD = x;
}
void FSMC_WRITE_DATA(u16 x)
{
    *(__IO uint16_t *)TFT_DATA_ADD = x;
}



