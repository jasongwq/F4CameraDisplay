#include "G32_I2c.h"
#include "stm32_config.h"

/*
2013/7/19
*/
#define SCL_H GPIO_SetBits(I2C_SCL_GPIO,I2C_SCL_PIN)
#define SCL_L GPIO_ResetBits(I2C_SCL_GPIO,I2C_SCL_PIN)

#define SDA_H GPIO_SetBits(I2C_SDA_GPIO,I2C_SDA_PIN)
#define SDA_L GPIO_ResetBits(I2C_SDA_GPIO,I2C_SDA_PIN)

#define SCL_Read GPIO_ReadInputDataBit(I2C_SCL_GPIO,I2C_SCL_PIN)
#define SDA_Read GPIO_ReadInputDataBit(I2C_SDA_GPIO,I2C_SDA_PIN)

void I2c_Init(void)
{
    GPIO_InitTypeDef I2C_GPIO;
	  RCC_APB2PeriphClockCmd(RCC_I2C_SCL, ENABLE); //使能Px端口时钟
    I2C_GPIO.GPIO_Pin = I2C_SCL_PIN;
    I2C_GPIO.GPIO_Speed = GPIO_Speed_10MHz;
    I2C_GPIO.GPIO_Mode = GPIO_Mode_Out_OD;
    GPIO_Init(I2C_SCL_GPIO, &I2C_GPIO);
	
	  RCC_APB2PeriphClockCmd(RCC_I2C_SDA, ENABLE); //使能Px端口时钟
    I2C_GPIO.GPIO_Pin = I2C_SDA_PIN;
	  I2C_GPIO.GPIO_Speed = GPIO_Speed_10MHz;
    I2C_GPIO.GPIO_Mode = GPIO_Mode_Out_OD;
    GPIO_Init(I2C_SDA_GPIO, &I2C_GPIO);
}

static void I2c_Delay(void)
{
    volatile s8 i = 7;
    while (i)
    	i--;
}

static bool I2c_Start(void)
{
    SDA_H;
    SCL_H;
    I2c_Delay();
    if (!SDA_Read)
        return false;
    SDA_L;
    I2c_Delay();
    if (SDA_Read)
        return false;
    SDA_L;
    I2c_Delay();
    return true;
}

static void I2c_Stop(void)
{
    SCL_L;
    I2c_Delay();
    SDA_L;
    I2c_Delay();
    SCL_H;
    I2c_Delay();
    SDA_H;
    I2c_Delay();
}
static void I2c_Ack(void)
{
    SCL_L;
    I2c_Delay();
    SDA_L;
    I2c_Delay();
    SCL_H;
    I2c_Delay();
    SCL_L;
    I2c_Delay();
}

static void I2c_NoAck(void)
{
    SCL_L;
    I2c_Delay();
    SDA_H;
    I2c_Delay();
    SCL_H;
    I2c_Delay();
    SCL_L;
    I2c_Delay();
}

static bool I2c_WaitAck(void)
{
    SCL_L;
    I2c_Delay();
    SDA_H;
    I2c_Delay();
    SCL_H;
    I2c_Delay();
    if (SDA_Read)
    {
        SCL_L;
			I2c_Delay();
        return false;
    }
    SCL_L;
		I2c_Delay();
    return true;
}

static void I2c_SendBety(u8 byte)
{
    u8 i = 8;
    while (i--)
    {
        SCL_L;
        I2c_Delay();
        if (byte & 0x80)
            SDA_H;
        else
            SDA_L;
        byte <<= 1;
        I2c_Delay();
        SCL_H;
        I2c_Delay();
    }
    SCL_L;
}

static u8 I2c_ReceiveBety(void)
{
    u8 i = 8;
    u8 byte = 0;

    SDA_H;
    while (i--)
    {
        byte <<= 1;
        SCL_L;
        I2c_Delay();
        SCL_H;
        I2c_Delay();
        if (SDA_Read)
            byte |= 0x01;
    }
    SCL_L;
    return byte;
}
/******************************************************************************
/ 函数功能:单字节写入
/ 修改日期:none
/ 输入参数:
/   @arg SlaveAddress   从器件地址
/   @arg REG_Address    寄存器地址
/   @arg data       欲写入的字节数据
/ 输出参数: 读出的字节数据
/ 使用说明:这时一个完整的单字节读取函数
******************************************************************************/
bool I2c_Write(u8 SlaveAddress, u8 REG_Address, u8 data)
{
    if (!I2c_Start())
        return false;
    I2c_SendBety(SlaveAddress);
    if (!I2c_WaitAck())
    {
        I2c_Stop();
        return false;
    }
    I2c_SendBety(REG_Address);
    I2c_WaitAck();
    I2c_SendBety(data);
		if (!I2c_WaitAck())
    {
        I2c_Stop();
        return false;
    }
    I2c_Stop();
    return true;
}

bool I2c_WriteBuffer(u8 addr, u8 reg, u8 len , u8 *data)
{
    s8 i;
    if (!I2c_Start())
        return false;
    I2c_SendBety(addr);
    if (!I2c_WaitAck())
    {
        I2c_Stop();
        return false;
    }
    I2c_SendBety(reg);
    I2c_WaitAck();
    for (i = 0; i < len; i++)
    {
        I2c_SendBety(data[i]);
        if (!I2c_WaitAck())
        {
            I2c_Stop();
            return false;
        }
    }
    I2c_Stop();
    return true;
}
bool I2c_ReadBuffer(u8 addr, u8 reg, u8 len , u8 *data)
{
    if (!I2c_Start())
        return false;
    I2c_SendBety(addr);
    if (!I2c_WaitAck())
    {
        I2c_Stop();
        return false;
    }
    I2c_SendBety(reg);
    I2c_WaitAck();

    if (!I2c_Start())return false;
    I2c_SendBety(addr+1);
    if (!I2c_WaitAck())
    {
        I2c_Stop();
        return false;
    }
    while (len)
    {
        *data = I2c_ReceiveBety();
        if (len == 1)
            I2c_NoAck();
        else
            I2c_Ack();
        data++;
        len--;
    }
    I2c_Stop();
    return true;
}

/***MUP6050 I2c***/
int8_t i2cwrite(uint8_t addr, uint8_t reg, uint8_t len, uint8_t *data)
{
    s8 i;
    if (!I2c_Start())
        return FALSE;
    I2c_SendBety(addr << 1 | 0x00);
    if (!I2c_WaitAck())
    {
        I2c_Stop();
        return FALSE;
    }
    I2c_SendBety(reg);
    I2c_WaitAck();
    for (i = 0; i < len; i++)
    {
        I2c_SendBety(data[i]);
        if (!I2c_WaitAck())
        {
            I2c_Stop();
            return FALSE;
        }
    }
    I2c_Stop();
    return TRUE;
}
int8_t i2cread(uint8_t addr, uint8_t reg, uint8_t len, uint8_t *data)
{
    if (!I2c_Start())
        return FALSE;
    I2c_SendBety(addr << 1 | 0x00);
    if (!I2c_WaitAck())
    {
        I2c_Stop();
        return FALSE;
    }
    I2c_SendBety(reg);
    I2c_WaitAck();

    if (!I2c_Start())return FALSE;
    I2c_SendBety(addr << 1 | 0x01);
    if (!I2c_WaitAck())
    {
        I2c_Stop();
        return FALSE;
    }
    while (len)
    {
        *data = I2c_ReceiveBety();
        if (len == 1)
            I2c_NoAck();
        else
            I2c_Ack();
        data++;
        len--;
    }
    I2c_Stop();
    return TRUE;
}
//int8_t i2c_read(uint8_t addr, uint8_t reg, uint8_t *data, uint8_t len)
//{
//    if (!I2c_Start())
//        return FALSE;
//    I2c_SendBety(addr << 1 | 0x00);
//    if (!I2c_WaitAck())
//    {
//        I2c_Stop();
//        return FALSE;
//    }
//    I2c_SendBety(reg);
//    I2c_WaitAck();

//    if (!I2c_Start())return FALSE;
//    I2c_SendBety(addr << 1 | 0x01);
//    if (!I2c_WaitAck())
//    {
//        I2c_Stop();
//        return FALSE;
//    }
//    while (len)
//    {
//        *data = I2c_ReceiveBety();
//        if (len == 1)
//            I2c_NoAck();
//        else
//            I2c_Ack();
//        data++;
//        len--;
//    }
//    I2c_Stop();
//    return TRUE;
//}
/***MUP6050 I2c***/
