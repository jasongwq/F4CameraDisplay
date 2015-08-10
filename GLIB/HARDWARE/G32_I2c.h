#ifndef __G32_I2c_H
#define __G32_I2c_H
#include "sys.h"
#include "delay.h"

/*
2013/7/19
*/
//#define true  1
//#define false 0
//#define bool  u8

//#define TRUE   0
//#define FALSE -1

#define true 1
#define false 0 
#define bool  uint8_t

#define TRUE  0
#define FALSE -1
/*I2c*/
void I2c_Init (void);
bool I2c_Write(u8 addr, u8 reg, u8 data);
bool I2c_WriteBuffer(u8 addr, u8 reg, u8 len , u8 *data);
bool I2c_ReadBuffer (u8 addr, u8 reg, u8 len , u8 *data);

/***MUP6050 I2c***/
int8_t i2cwrite(uint8_t addr, uint8_t reg, uint8_t len, uint8_t *data);
int8_t i2cread (uint8_t addr, uint8_t reg, uint8_t len, uint8_t *data);
//int8_t i2c_read(uint8_t addr, uint8_t reg, uint8_t *data, uint8_t len);

/***MUP6050 I2c***/
#endif
