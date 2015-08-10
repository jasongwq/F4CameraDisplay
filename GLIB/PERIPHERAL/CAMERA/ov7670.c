#include "ov7670.h"
#include "delay.h"
//#include "spi.h"
#include "lcd.h"
//#include "lcd_dis24.h"
#include "USART.h"
#include "GPIO.h"
////////////////////////////////////////////////////////////////////////////
#define SCCB_WR_Reg OV_WriteReg
//#define SCCB_RD_Reg OV_ReadReg
//OV7670功能设置
//白平衡设置
//0:自动
//1:太阳sunny
//2,阴天cloudy
//3,办公室office
//4,家里home
void OV7670_Light_Mode(u8 mode)
{
    u8 reg13val = 0XE7; //默认就是设置为自动白平衡
    u8 reg01val = 0;
    u8 reg02val = 0;
    switch (mode)
    {
    case 1://sunny
        reg13val = 0XE5;
        reg01val = 0X5A;
        reg02val = 0X5C;
        break;
    case 2://cloudy
        reg13val = 0XE5;
        reg01val = 0X58;
        reg02val = 0X60;
        break;
    case 3://office
        reg13val = 0XE5;
        reg01val = 0X84;
        reg02val = 0X4c;
        break;
    case 4://home
        reg13val = 0XE5;
        reg01val = 0X96;
        reg02val = 0X40;
        break;
    }
    SCCB_WR_Reg(0X13, reg13val); //COM8设置
    SCCB_WR_Reg(0X01, reg01val); //AWB蓝色通道增益
    SCCB_WR_Reg(0X02, reg02val); //AWB红色通道增益
}
//色度设置
//0:-2
//1:-1
//2,0
//3,1
//4,2
void OV7670_Color_Saturation(u8 sat)
{
    u8 reg4f5054val = 0X80; //默认就是sat=2,即不调节色度的设置
    u8 reg52val = 0X22;
    u8 reg53val = 0X5E;
    switch (sat)
    {
    case 0://-2
        reg4f5054val = 0X40;
        reg52val = 0X11;
        reg53val = 0X2F;
        break;
    case 1://-1
        reg4f5054val = 0X66;
        reg52val = 0X1B;
        reg53val = 0X4B;
        break;
    case 3://1
        reg4f5054val = 0X99;
        reg52val = 0X28;
        reg53val = 0X71;
        break;
    case 4://2
        reg4f5054val = 0XC0;
        reg52val = 0X33;
        reg53val = 0X8D;
        break;
    }
    SCCB_WR_Reg(0X4F, reg4f5054val); //色彩矩阵系数1
    SCCB_WR_Reg(0X50, reg4f5054val); //色彩矩阵系数2
    SCCB_WR_Reg(0X51, 0X00);        //色彩矩阵系数3
    SCCB_WR_Reg(0X52, reg52val);    //色彩矩阵系数4
    SCCB_WR_Reg(0X53, reg53val);    //色彩矩阵系数5
    SCCB_WR_Reg(0X54, reg4f5054val); //色彩矩阵系数6
    SCCB_WR_Reg(0X58, 0X9E);        //MTXS
}
//亮度设置
//0:-2
//1:-1
//2,0
//3,1
//4,2
void OV7670_Brightness(u8 bright)
{
    u8 reg55val = 0X00; //默认就是bright=2
    switch (bright)
    {
    case 0://-2
        reg55val = 0XB0;
        break;
    case 1://-1
        reg55val = 0X98;
        break;
    case 3://1
        reg55val = 0X18;
        break;
    case 4://2
        reg55val = 0X30;
        break;
    }
    SCCB_WR_Reg(0X55, reg55val); //亮度调节
}
//对比度设置
//0:-2
//1:-1
//2,0
//3,1
//4,2
void OV7670_Contrast(u8 contrast)
{
    u8 reg56val = 0X40; //默认就是contrast=2
    switch (contrast)
    {
    case 0://-2
        reg56val = 0X30;
        break;
    case 1://-1
        reg56val = 0X38;
        break;
    case 3://1
        reg56val = 0X50;
        break;
    case 4://2
        reg56val = 0X60;
        break;
    }
    SCCB_WR_Reg(0X56, reg56val); //对比度调节
}
//特效设置
//0:普通模式
//1,负片
//2,黑白
//3,偏红色
//4,偏绿色
//5,偏蓝色
//6,复古
void OV7670_Special_Effects(u8 eft)
{
    u8 reg3aval = 0X04; //默认为普通模式
    u8 reg67val = 0XC0;
    u8 reg68val = 0X80;
    switch (eft)
    {
    case 1://负片
        reg3aval = 0X24;
        reg67val = 0X80;
        reg68val = 0X80;
        break;
    case 2://黑白
        reg3aval = 0X14;
        reg67val = 0X80;
        reg68val = 0X80;
        break;
    case 3://偏红色
        reg3aval = 0X14;
        reg67val = 0Xc0;
        reg68val = 0X80;
        break;
    case 4://偏绿色
        reg3aval = 0X14;
        reg67val = 0X40;
        reg68val = 0X40;
        break;
    case 5://偏蓝色
        reg3aval = 0X14;
        reg67val = 0X80;
        reg68val = 0XC0;
        break;
    case 6://复古
        reg3aval = 0X14;
        reg67val = 0XA0;
        reg68val = 0X40;
        break;
    }
    SCCB_WR_Reg(0X3A, reg3aval); //TSLB设置
    SCCB_WR_Reg(0X68, reg67val); //MANU,手动U值
    SCCB_WR_Reg(0X67, reg68val); //MANV,手动V值
}
//设置图像输出窗口
//对QVGA设置。
void OV7670_Window_Set(u16 sx, u16 sy, u16 width, u16 height)
{
    u16 endx;
    u16 endy;
    u8 temp;
    endx = sx + width * 2; //V*2
    endy = sy + height * 2;
    if (endy > 784)endy -= 784;
    OV_ReadReg(0X03, &temp);            //读取Vref之前的值
    temp &= 0XF0;
    temp |= ((endx & 0X03) << 2) | (sx & 0X03);
    SCCB_WR_Reg(0X03, temp);            //设置Vref的start和end的最低2位
    SCCB_WR_Reg(0X19, sx >> 2);         //设置Vref的start高8位
    SCCB_WR_Reg(0X1A, endx >> 2);       //设置Vref的end的高8位

    OV_ReadReg(0X32, &temp);            //读取Href之前的值
    temp &= 0XC0;
    temp |= ((endy & 0X07) << 3) | (sy & 0X07);
    SCCB_WR_Reg(0X17, sy >> 3);         //设置Href的start高8位
    SCCB_WR_Reg(0X18, endy >> 3);       //设置Href的end的高8位
}

void DCMI_NVIC_Config(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    NVIC_InitStructure.NVIC_IRQChannel = DCMI_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}
vu16 Lcd_Memory[320];
vu16 Lcd_Memory2[320];

void Cam_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    DCMI_InitTypeDef DCMI_InitStructure;
    DMA_InitTypeDef  DMA_InitStructure;

    RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_DCMI, ENABLE);//DCMI
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);//DMA2
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB |
                           RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOE, ENABLE);//使能DCMI的GPIO时钟

    GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_MCO);//MCO1:PA8

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    RCC_MCO1Config(RCC_MCO1Source_PLLCLK, RCC_MCO1Div_5); //F_XCLK = 56MHz

    /****** Configures the DCMI GPIOs ******/
    /*** Connect DCMI pins to AF13 ***/
    /* HSYNC(PA4), PIXCLK(PA6) */
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource4, GPIO_AF_DCMI);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_DCMI);
    /* D5(PB6), VSYNC(PB7) */
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_DCMI);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_DCMI);
    /* D0..1(PC6/7) */
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_DCMI);
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_DCMI);
    /* D2..4,6..7(PE0/1/4/5/6) */
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource0, GPIO_AF_DCMI);
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource1, GPIO_AF_DCMI);
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource4, GPIO_AF_DCMI);
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource5, GPIO_AF_DCMI);
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource6, GPIO_AF_DCMI);
    /*** DCMI GPIOs configuration ***/
    /* HSYNC(PA4), PIXCLK(PA6) */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    /* D5(PB6), VSYNC(PB7) */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    /* D0..1(PC6/7) */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    /* D2..4,6..7(PE0/1/4/5/6) */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6;
    GPIO_Init(GPIOE, &GPIO_InitStructure);

    DCMI_InitStructure.DCMI_CaptureMode = DCMI_CaptureMode_SnapShot;
    DCMI_InitStructure.DCMI_SynchroMode = DCMI_SynchroMode_Hardware;
    DCMI_InitStructure.DCMI_PCKPolarity = DCMI_PCKPolarity_Falling;
    DCMI_InitStructure.DCMI_VSPolarity = DCMI_VSPolarity_High;
    DCMI_InitStructure.DCMI_HSPolarity = DCMI_HSPolarity_High;
    DCMI_InitStructure.DCMI_CaptureRate = DCMI_CaptureRate_All_Frame;
    DCMI_InitStructure.DCMI_ExtendedDataMode = DCMI_ExtendedDataMode_8b;
    DCMI_Init(&DCMI_InitStructure);
        /* OPCJONALNIE */
		
#if DCMI_TO_LCD
//    DCMI_ITConfig(DCMI_IT_FRAME, ENABLE); // Przerwanie generowane po odebraniu jednej ramki obrazu
    DCMI_ITConfig(DCMI_IT_VSYNC, ENABLE);   // Przerwanie generowane przy przejsciu sygnalu VSYNC ze stanu aktywnego do nieaktywnego
//    DCMI_ITConfig(DCMI_IT_LINE, ENABLE);  // Przerwanie generowane po odebraniu jednego wiersza danych obrazu
    //DCMI_ITConfig(DCMI_IT_OVF, ENABLE);
    //DCMI_ITConfig(DCMI_IT_ERR, ENABLE);
#endif
#if DCMI_TO_RAM
    DCMI_ITConfig(DCMI_IT_FRAME, ENABLE); // Przerwanie generowane po odebraniu jednej ramki obrazu
    //DCMI_ITConfig(DCMI_IT_VSYNC, ENABLE);   // Przerwanie generowane przy przejsciu sygnalu VSYNC ze stanu aktywnego do nieaktywnego
    DCMI_ITConfig(DCMI_IT_LINE, ENABLE);  // Przerwanie generowane po odebraniu jednego wiersza danych obrazu
    //DCMI_ITConfig(DCMI_IT_OVF, ENABLE);
    //DCMI_ITConfig(DCMI_IT_ERR, ENABLE);
#endif
    /* OPCJONALNIE */

    DCMI_NVIC_Config();
#if DCMI_TO_LCD
    DMA_DeInit(DMA2_Stream1);
    DMA_InitStructure.DMA_Channel = DMA_Channel_1;
    DMA_InitStructure.DMA_PeripheralBaseAddr = DCMI_DR_ADDRESS;
    DMA_InitStructure.DMA_Memory0BaseAddr =FSMC_LCD_ADDRESS;// (uint32_t)Lcd_Memory;//
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
    DMA_InitStructure.DMA_BufferSize =1;// 320/2  ;//((320)*240/2)/2+80;//
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;//DMA_MemoryInc_Enable;//
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Enable;
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
		#endif
#if DCMI_TO_RAM
    DMA_DeInit(DMA2_Stream1);
    DMA_InitStructure.DMA_Channel = DMA_Channel_1;
    DMA_InitStructure.DMA_PeripheralBaseAddr = DCMI_DR_ADDRESS;
    DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)Lcd_Memory;//FSMC_LCD_ADDRESS;//
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
    DMA_InitStructure.DMA_BufferSize = 320/2  ;//((320)*240/2)/2+80;//1;//
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;//DMA_MemoryInc_Disable;//
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Enable;
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
		#endif
    DMA_Init(DMA2_Stream1, &DMA_InitStructure);
}
u8 OV_ReadID(void)
{
    u8 temp;
    OV_ReadReg(0x0b, &temp);
    return temp;
}
u8 OV7670_Init(void)
{
    u8 i;
    Cam_Init();
    SCCB_Init();
    OV_Reset();
    delay_ms(5);
		#if OV7670_USE_RGB
    for (i = 0; i < OV7670_RGB_REG_NUM; i++)
    {
        if (OV_WriteReg(OV7670_RGB_reg[i][0], OV7670_RGB_reg[i][1]))return 1;
    }
		#endif
		#if OV7670_USE_YUV
    for (i = 0; i < OV7670_YUV_REG_NUM; i++)
    {
        if (OV_WriteReg(OV7670_YUV_reg[i][0], OV7670_YUV_reg[i][1]))return 1;
    }
		#endif
		
    return 0;

}
void Cam_Start(void)
{
    TFT_Window(0, 0, 240, 320);
    DMA_Cmd(DMA2_Stream1, ENABLE);
    DCMI_Cmd(ENABLE);
    DCMI_CaptureCmd(ENABLE);
}

void OV7670_HW(u16 hstart, u16 vstart, u16 hstop, u16 vstop)
{
    u8 v;
    OV_WriteReg(0x17, (hstart >> 3) & 0xff); //HSTART
    OV_WriteReg(0x18, (hstop >> 3) & 0xff); //HSTOP
    OV_ReadReg(0x32, &v);
    v = (v & 0xc0) | ((hstop & 0x7) << 3) | (hstart & 0x7);
    OV_WriteReg(0x32, v); //HREF

    OV_WriteReg(0x19, (vstart >> 2) & 0xff); //VSTART 开始高8位
    OV_WriteReg(0x1a, (vstop >> 2) & 0xff); //VSTOP   结束高8位
    OV_ReadReg(0x03, &v);
    v = (v & 0xf0) | ((vstop & 0x3) << 2) | (vstart & 0x3);
    OV_WriteReg(0x03, v); //VREF
    OV_WriteReg(0x11, 0x00);
}
/////////////////////////////////////
void SCCB_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;  //SCCB_SIC:PE2
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;           //SCCB_SID:PE3
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void SCCB_SID_OUT(void)//设置SCCB_SID为输出
{
    GPIO_InitTypeDef  GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}
void SCCB_SID_IN(void)//设置SCCB_SID为输入
{
    GPIO_InitTypeDef  GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void SCCB_Start(void)
{
    SCCB_SID_H();     //数据线高电平
    delay_us(50);
    SCCB_SIC_H();      //在时钟线高的时候数据线由高至低
    delay_us(50);
    SCCB_SID_L();
    delay_us(50);
    SCCB_SIC_L();    //数据线恢复低电平，单操作函数必要
    delay_us(50);
}

void SCCB_Stop(void)
{
    SCCB_SID_L();
    delay_us(50);
    SCCB_SIC_H();
    delay_us(50);
    SCCB_SID_H();
    delay_us(50);
}

void noAck(void)
{
    SCCB_SID_H();
    delay_us(50);
    SCCB_SIC_H();
    delay_us(50);
    SCCB_SIC_L();
    delay_us(50);
    SCCB_SID_L();
    delay_us(50);
}

u8 SCCB_Write(u8 m_data)
{
    u8 j, tem;

    for (j = 0; j < 8; j++) //循环8次发送数据
    {
        if ((m_data << j) & 0x80)SCCB_SID_H()
            else SCCB_SID_L()
                delay_us(50);
        SCCB_SIC_H();
        delay_us(50);
        SCCB_SIC_L();
        delay_us(50);
    }
    delay_us(10);
    SCCB_DATA_IN;
    delay_us(50);
    SCCB_SIC_H();
    delay_us(10);
    if (SCCB_SID_STATE)tem = 0; //SDA=1发送失败
    else tem = 1; //SDA=0发送成功，返回1
    SCCB_SIC_L();
    delay_us(50);
    SCCB_DATA_OUT;
    return tem;
}

u8 SCCB_Read(void)
{
    u8 read, j;
    read = 0x00;

    SCCB_DATA_IN;
    delay_us(50);
    for (j = 8; j > 0; j--) //循环8次接收数据
    {
        delay_us(50);
        SCCB_SIC_H();
        delay_us(50);
        read = read << 1;
        if (SCCB_SID_STATE)read = read + 1;
        SCCB_SIC_L();
        delay_us(50);
    }
    SCCB_DATA_OUT;
    return read;
}

//写OV7670寄存器
u8 OV_WriteReg(u8 regID, u8 regDat)
{
    SCCB_Start();//发送SCCB 总线开始传输命令
    if (SCCB_Write(0x42) == 0) //写地址
    {
        SCCB_Stop();//发送SCCB 总线停止传输命令
        return 1;//错误返回
    }
    delay_us(10);
    if (SCCB_Write(regID) == 0) //积存器ID
    {
        SCCB_Stop();//发送SCCB 总线停止传输命令
        return 2;//错误返回
    }
    delay_us(10);
    if (SCCB_Write(regDat) == 0) //写数据到积存器
    {
        SCCB_Stop();//发送SCCB 总线停止传输命令
        return 3;//错误返回
    }
    SCCB_Stop();//发送SCCB 总线停止传输命令
    return 0;//成功返回
}

//读OV7660寄存器
u8 OV_ReadReg(u8 regID, u8 *regDat)
{
    //通过写操作设置寄存器地址
    SCCB_Start();
    if (SCCB_Write(0x42) == 0) //写地址
    {
        SCCB_Stop();//发送SCCB 总线停止传输命令
        return 1;//错误返回
    }
    delay_us(10);
    if (SCCB_Write(regID) == 0) //积存器ID
    {
        SCCB_Stop();//发送SCCB 总线停止传输命令
        return 2;//错误返回
    }
    SCCB_Stop();//发送SCCB 总线停止传输命令
    delay_us(10);
    //设置寄存器地址后，才是读
    SCCB_Start();
    if (SCCB_Write(0x43) == 0) //读地址
    {
        SCCB_Stop();//发送SCCB 总线停止传输命令
        return 3;//错误返回
    }
    delay_us(10);
    *regDat = SCCB_Read(); //返回读到的值
    noAck();//发送NACK命令
    SCCB_Stop();//发送SCCB 总线停止传输命令
    return 0;//成功返回
}

void OV_Reset(void)
{
    OV_WriteReg(0x12, 0x80);
}

