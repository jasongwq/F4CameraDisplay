#include "Camera.h"
/****************************************/
/***IIC***/
/**********************************************
***********************************************\
 * I2C1_SMBA  |   PB5    |          |          *
 * I2C1_SCL   |   PB6    |   PB8    |          *
 * I2C1_SDA   |   PB7    |   PB9    |          *
 * ******************************************* *
 * I2C2_SCL   |   PB10   |   PF1    |   PH4    *
 * I2C2_SDA   |   PB11   |   PF0    |   PH5    *
 * I2C2_SMBA  |   PB12   |   PF2    |   PH6    *
 * ******************************************* *
 * I2C3_SCL   |   PA8    |   PH7    |          *
 * I2C3_SDA   |   PC9    |   PH8    |          *
 * I2C3_SMBA  |   PA9    |   PH9    |          *
 * ******************************************* *
\**********************************************/
/**
  * @brief  Reads a word from a specific Camera register
  * @param  Addr: MT9D111 register address.
  * @retval data word from the specific register or
  *         0xFFFF if timeout condition occured (device not connected or bus error).
  */
ushort MT9D111_ReadReg(uchar regAddr)
{
    unsigned int timeout = I2C_TIMEOUT_MAX;
    unsigned short regVal = 0;

    /* Generate the START Condition */
    I2C_GenerateSTART(MT9D111_I2C, ENABLE);

    /* Test on I2C EV5 and clear it */
    timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
    while (!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_MODE_SELECT))
    {
        // If the timeout delay is exceeded, exit with error code
        if ((timeout--) == 0)
            return 0xFF;
    }

    /* Send slave device address with write mode selected */
    I2C_Send7bitAddress(MT9D111_I2C, MT9D111_DEVICE_WRITE_ADDRESS, I2C_Direction_Transmitter);

    /* Test on I2C EV6 and clear it */
    timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
    while (!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
    {
        // If the timeout delay is exceeded, exit with error code
        if ((timeout--) == 0)
            return 0xFF;
    }

    /* Send register address byte */
    I2C_SendData(MT9D111_I2C, regAddr);

    /* Test on I2C EV8 and clear it */
    timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
    while (!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
    {
        // If the timeout delay is exceeded, exit with error code
        if ((timeout--) == 0)
            return 0xFF;
    }

    /* Clear AF flag if arised */
    MT9D111_I2C->SR1 |= (uint16_t)0x0400;

    /* Generate the START Condition */
    I2C_GenerateSTART(MT9D111_I2C, ENABLE);

    /* Test on I2C EV6 and clear it */
    timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
    while (!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_MODE_SELECT))
    {
        // If the timeout delay is exceeded, exit with error code
        if ((timeout--) == 0)
            return 0xFF;
    }

    /* Send slave device address with read mode selected */
    I2C_Send7bitAddress(MT9D111_I2C, MT9D111_DEVICE_READ_ADDRESS, I2C_Direction_Receiver);

    /* Test on I2C EV6 and clear it */
    timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
    while (!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
    {
        // If the timeout delay is exceeded, exit with error code
        if ((timeout--) == 0)
            return 0xFF;
    }

    /* Prepare an ACK for the next data received */
    I2C_AcknowledgeConfig(MT9D111_I2C, ENABLE);

    /* Test on I2C EV7 and clear it */
    timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
    while (!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_BYTE_RECEIVED))
    {
        // If the timeout delay is exceeded, exit with error code
        if ((timeout--) == 0)
            return 0xFF;
    }

    regVal = ((unsigned short) I2C_ReceiveData(MT9D111_I2C)) << 8;

    /* Prepare an NACK for the next data received */
    I2C_AcknowledgeConfig(MT9D111_I2C, DISABLE);

    /* Test on I2C EV7 and clear it */
    timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
    while (!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_BYTE_RECEIVED))
    {
        // If the timeout delay is exceeded, exit with error code
        if ((timeout--) == 0)
            return 0xFF;
    }

    /* Prepare STOP after receiving data */
    I2C_GenerateSTOP(MT9D111_I2C, ENABLE);

    /* Receive the Data */
    regVal += I2C_ReceiveData(MT9D111_I2C);

    while (((MT9D111_I2C->CR1) & 0x0200) != 0);

    /* Return the read data */
    return regVal;
}

/**
  * @brief  Writes a word at a specific Camera register
  * @param  Addr: MT9D111 register address
  * @param  Data: data to be written to the specific register
  * @retval 0x00 if write operation is OK
  *         0xFFFF if timeout condition occured (device not connected or bus error).
  */
uchar MT9D111_WriteReg(uchar regAddr, ushort regVal)
{
    unsigned int timeout = I2C_TIMEOUT_MAX;

    /* Generate the START Condition */
    I2C_GenerateSTART(MT9D111_I2C, ENABLE);

    /* Test on I2C EV5 and clear it */
    timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
    while (!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_MODE_SELECT))
    {
        // If the timeout delay is exceeded, exit with error code
        if ((timeout--) == 0)
        {
            return 0xFF;
        }
    }

    /* Send slave device address with write mode selected */
    I2C_Send7bitAddress(MT9D111_I2C, MT9D111_DEVICE_WRITE_ADDRESS, I2C_Direction_Transmitter);

    /* Test on I2C EV6 and clear it */
    timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
    while (!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
    {
        // If the timeout delay is exceeded, exit with error code
        if ((timeout--) == 0)
        {
            return 0xFF;
        }
    }

    /* Send register address byte */
    I2C_SendData(MT9D111_I2C, regAddr);

    /* Test on I2C EV8 and clear it */
    timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
    while (!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
    {
        // If the timeout delay is exceeded, exit with error code
        if ((timeout--) == 0)
            return 0xFF;
    }

    /* Send register data MSB */
    I2C_SendData(MT9D111_I2C, (regVal >> 8) & 0xFF);

    /* Test on I2C EV8 and clear it */
    timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
    while (!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
    {
        // If the timeout delay is exceeded, exit with error code
        if ((timeout--) == 0)
            return 0xFF;
    }

    /* Send register data LSB */
    I2C_SendData(MT9D111_I2C, regVal & 0xFF);

    /* Test on I2C EV8 and clear it */
    timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
    while (!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
    {
        // If the timeout delay is exceeded, exit with error code
        if ((timeout--) == 0)
            return 0xFF;
    }

    /* Generate the STOP condition */
    I2C_GenerateSTOP(MT9D111_I2C, ENABLE);
    while (((MT9D111_I2C->CR1) & 0x0200) != 0);

    /* If operation is OK, return 0 */
    return 0;
}






