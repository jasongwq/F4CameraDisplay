#include "MT9D111.h"
#include "delay.h"

#define Delay(n) delay_ms(n*10)
struct MT9D111_REG_STRUCT MT9D111_InitStructure[] = {
  //************************
  // Konfiguracja bloku PLL
  //************************
#if (XCLK == HSE_8MHz)
  #if (PIXCLK == F_10MHz)
  //***************************
  // Fin  = 8  MHz
  // Fpfd = 4  MHz
  // Fvco = 80 MHz
  // Fout = 10 MHz
  //***************************
  {0, 0x65, 0xA000},  //Clock: <15> PLL BYPASS = 1 --- make sure that PLL is bypassed
  {0, 0x65, 0xE000},  //Clock: <14> PLL OFF = 1 --- make sure that PLL is powered-down
  {0, 0x66, 0x1401},  //PLL Control 1: <15:8> M = 20, <5:0> N = 1
  {0, 0x67, 0x0503},  //PLL Control 2: <6:0> P = 3
  {0, 0x65, 0xA000},  //Clock: <14> PLL OFF = 0 --- PLL is powered-up
  {MT9D111_DELAY,0,10},//Delay 10 ms
  {0, 0x65, 0x2000},  //Clock: <15> PLL BYPASS = 0 --- enable PLL as master clock

  #elif (PIXCLK == F_20MHz)
  //***************************
  // Fin  = 8   MHz
  // Fpfd = 4   MHz
  // Fvco = 160 MHz
  // Fout = 20  MHz
  //***************************
  {0, 0x65, 0xA000},  //Clock: <15> PLL BYPASS = 1 --- make sure that PLL is bypassed
  {0, 0x65, 0xE000},  //Clock: <14> PLL OFF = 1 --- make sure that PLL is powered-down
  {0, 0x66, 0x2801},  //PLL Control 1: <15:8> M = 40, <5:0> N = 1
  {0, 0x67, 0x0503},  //PLL Control 2: <6:0> P = 3
  {0, 0x65, 0xA000},  //Clock: <14> PLL OFF = 0 --- PLL is powered-up
  {MT9D111_DELAY,0,10},//Delay 10 ms
  {0, 0x65, 0x2000},  //Clock: <15> PLL BYPASS = 0 --- enable PLL as master clock
  
  #elif (PIXCLK == F_25MHz)
  //***************************
  // Fin  = 8   MHz
  // Fpfd = 4   MHz
  // Fvco = 200 MHz
  // Fout = 25  MHz
  //***************************
  {0, 0x65, 0xA000},  //Clock: <15> PLL BYPASS = 1 --- make sure that PLL is bypassed
  {0, 0x65, 0xE000},  //Clock: <14> PLL OFF = 1 --- make sure that PLL is powered-down
  {0, 0x66, 0x3201},  //PLL Control 1: <15:8> M = 50, <5:0> N = 1
  {0, 0x67, 0x0503},  //PLL Control 2: <6:0> P = 3
  {0, 0x65, 0xA000},  //Clock: <14> PLL OFF = 0 --- PLL is powered-up
  {MT9D111_DELAY,0,10},//Delay 10 ms
  {0, 0x65, 0x2000},  //Clock: <15> PLL BYPASS = 0 --- enable PLL as master clock

  #endif

#elif (XCLK == PLL_33MHz)
  #if (PIXCLK == F_22MHz)
  //***************************
  // Fin  = 33.6 MHz
  // Fpfd = 5.6  MHz
  // Fvco = 224  MHz
  // Fout = 22.4 MHz
  //***************************
  {0, 0x65, 0xA000},  //Clock: <15> PLL BYPASS = 1 --- make sure that PLL is bypassed
  {0, 0x65, 0xE000},  //Clock: <14> PLL OFF = 1 --- make sure that PLL is powered-down
  {0, 0x66, 0x1E05},  //PLL Control 1: <15:8> M = 30, <5:0> N = 5
  {0, 0x67, 0x0502},  //PLL Control 2: <6:0> P = 2
  {0, 0x65, 0xA000},  //Clock: <14> PLL OFF = 0 --- PLL is powered-up
  {MT9D111_DELAY,0,10},//Delay 10 ms
  {0, 0x65, 0x2000},  //Clock: <15> PLL BYPASS = 0 --- enable PLL as master clock*/

  #endif

#elif (XCLK == PLL_56MHz)
  #if (PIXCLK == F_25MHz)
  //***************************
  // Fin  = 56  MHz
  // Fpfd = 8   MHz
  // Fvco = 200 MHz
  // Fout = 25  MHz
  //***************************
  {0, 0x65, 0xA000},  //Clock: <15> PLL BYPASS = 1 --- make sure that PLL is bypassed
  {0, 0x65, 0xE000},  //Clock: <14> PLL OFF = 1 --- make sure that PLL is powered-down
  {0, 0x66, 0x1906},  //PLL Control 1: <15:8> M = 25, <5:0> N = 6
  {0, 0x67, 0x0503},  //PLL Control 2: <6:0> P = 3
  {0, 0x65, 0xA000},  //Clock: <14> PLL OFF = 0 --- PLL is powered-up
  {MT9D111_DELAY,0,10},//Delay 10 ms
  {0, 0x65, 0x2000},  //Clock: <15> PLL BYPASS = 0 --- enable PLL as master clock

  #elif (PIXCLK == F_40MHz)
  //***************************
  // Fin  = 56  MHz
  // Fpfd = 8   MHz
  // Fvco = 232 MHz
  // Fout = 37.3MHz
  //***************************
  {0, 0x65, 0xA000},  //Clock: <15> PLL BYPASS = 1 --- make sure that PLL is bypassed
  {0, 0x65, 0xE000},  //Clock: <14> PLL OFF = 1 --- make sure that PLL is powered-down
  {0, 0x66, 0x1C06},  //PLL Control 1: <15:8> M = 28, <5:0> N = 6
  {0, 0x67, 0x0502},  //PLL Control 2: <6:0> P = 2
  {0, 0x65, 0xA000},  //Clock: <14> PLL OFF = 0 --- PLL is powered-up
  {MT9D111_DELAY,0,10},//Delay 10 ms
  {0, 0x65, 0x2000},  //Clock: <15> PLL BYPASS = 0 --- enable PLL as master clock

  #endif
#endif

  //****************************************
  // Konfiguracja pozycji i wymiarow obrazu
  //****************************************
#if (RESOLUTION == QVGA)
  {0, 0x01, 0x01FC},  //Row Start = 508
  {0, 0x02, 0x02AC},  //Column Start = 684
  {0, 0x03, 0x00F0},  //Row Width = 240
  {0, 0x04, 0x0140},  //Column Width = 320

  {1, 0x08, 0x00F8},  //Decimator disabled

#elif (RESOLUTION == SVGA)
  {0, 0x01, 0x0148},  //Row Start = 328
  {0, 0x02, 0x01BC},  //Column Start = 444
  {0, 0x03, 0x0258},  //Row Width = 600
  {0, 0x04, 0x0320},  //Column Width = 800

  {1, 0x08, 0x01F8},  //Decimator enabled
  {1, 0x12, 0x0320},  //X1 Coordinate for Crop Window +1; width = 800
  {1, 0x14, 0x0258},  //Y1 Coordinate for Crop Window +1; height = 600
  {1, 0x16, 0x0334},  //Weight for H Decimation = 820
  {1, 0x17, 0x0334},  //Weight for V Decimation = 820

#elif (RESOLUTION == UXGA)
  {0, 0x01, 0x001C},  //Row Start = 28
  {0, 0x02, 0x002C},  //Column Start = 44
  {0, 0x03, 0x04B0},  //Row Width = 1200
  {0, 0x04, 0x0640},  //Column Width = 1600

  {1, 0x08, 0x01F8},  //Decimator enabled
  {1, 0x12, 0x0640},  //X1 Coordinate for Crop Window +1; width = 1600
  {1, 0x14, 0x04B0},  //Y1 Coordinate for Crop Window +1; height = 1200
  {1, 0x16, 0x019A},  //Weight for H Decimation = 410
  {1, 0x17, 0x019A},  //Weight for V Decimation = 410
#endif

  //******************************************
  // Konfiguracja parametrow wykonania obrazu
  //******************************************
  {0, 0x09, 0x02BC},  //Shutter Width = 700 --- Ustawienie wartosci przeslony
  {0, 0x20, 0x0300},  //Read Mode (B): binning disabled, use both ADCs, normal UXGA size, column/row skip disabled
  {0, 0x21, 0x0000},  //Read Mode (A): binning disabled, use both ADCs, column/row skip disabled

  //**********************************************
  // Konfiguracja formatu obrazu wyjsciowego
  //**********************************************
  {1, 0x09, 0x0009},  //Factory bypass: Data from SOC going to Dout pads
  {1, 0x97, 0x0022},  //Output Format Config: RGB output, swap odd/even bytes

  {MT9D111_TERM,0,0}
};

int MT9D111_SetRegs(struct MT9D111_REG_STRUCT *init){
  u32 curReg = 0;
  u16 regVal;
  int status = 0;
  int curPage = -1;
 
  while( init[curReg].page != MT9D111_TERM ){
    if (curPage != init[curReg].page){
      if (init[curReg].page == 0){
        regVal = 0;
        status = (MT9D111_WriteReg(0xF0, regVal) == 0) ? 0 : -EIO;
      }
      if (init[curReg].page == 1){
        regVal = 1;
        status = (MT9D111_WriteReg(0xF0, regVal) == 0) ? 0 : -EIO;
      }
      if (init[curReg].page == 2){
        regVal = 2;
        status = (MT9D111_WriteReg(0xF0, regVal) == 0) ? 0 : -EIO;
      }

      curPage = init[curReg].page;
    }

    if (init[curReg].page == MT9D111_DELAY){
      Delay(init[curReg].value/10);
      curReg++;
      continue;
    }
 
    regVal = init[curReg].value;
    MT9D111_WriteReg(init[curReg].subaddr, init[curReg].value);

    curReg++;
  }
  return status;
}

void MT9D111_Init(){
  MT9D111_SetRegs(MT9D111_InitStructure);
}

/** Soft Reset
  * 1. Bypass the PLL, R0x65:0=0xA000, if it is currently used
  * 2. Perform MCU reset by setting R0xC3:1=0x0501
  * 3. Enable soft reset by setting R0x0D:0=0x0021. Bit 0 is used for
  *    the sensor core reset while bit 5 refers to SOC reset.
  * 4. Disable soft reset by setting R0x0D:0=0x0000
  * 5. Wait 24 clock cycles before using the two-wire serial interface
  */
void MT9D111_SoftReset(){
	MT9D111_WriteReg(PAGE_SELECT_REG , 0x0   ); // PAGE 0
	MT9D111_WriteReg(CLOCK_REG       , 0xA000); // Bypass the PLL
	MT9D111_WriteReg(PAGE_SELECT_REG , 0x1   ); // PAGE 1
	MT9D111_WriteReg(UC_BOOT_MODE_REG, 0x0501); // Perform MCU Reset
  MT9D111_WriteReg(UC_BOOT_MODE_REG, 0x0500);
	MT9D111_WriteReg(PAGE_SELECT_REG , 0x0   ); // PAGE 0
	MT9D111_WriteReg(RESET_REG       , 0x0021); // Enable Soft Reset
	MT9D111_WriteReg(RESET_REG       , 0x0000); // Disable Soft Reset
	Delay(1);                                   // Wait 10 ms
}

/**
  * @brief  Reads a word from a specific Camera register
  * @param  Addr: MT9D111 register address.
  * @retval data word from the specific register or
  *         0xFFFF if timeout condition occured (device not connected or bus error).
  */
ushort MT9D111_ReadReg(uchar regAddr){
  unsigned int timeout = I2C_TIMEOUT_MAX;
  unsigned short regVal = 0;

  /* Generate the START Condition */
  I2C_GenerateSTART(MT9D111_I2C, ENABLE);

  /* Test on I2C EV5 and clear it */
  timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
  while(!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_MODE_SELECT))
  {
    // If the timeout delay is exceeded, exit with error code
    if((timeout--) == 0)
      return 0xFF;
  }
  
  /* Send slave device address with write mode selected */
  I2C_Send7bitAddress(MT9D111_I2C, MT9D111_DEVICE_WRITE_ADDRESS, I2C_Direction_Transmitter);
 
  /* Test on I2C EV6 and clear it */
  timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
  while(!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
  {
    // If the timeout delay is exceeded, exit with error code
    if((timeout--) == 0)
      return 0xFF;
  }

  /* Send register address byte */
  I2C_SendData(MT9D111_I2C, regAddr);

  /* Test on I2C EV8 and clear it */
  timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
  while(!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
  {
    // If the timeout delay is exceeded, exit with error code
    if((timeout--) == 0)
      return 0xFF;
  } 
  
  /* Clear AF flag if arised */
  MT9D111_I2C->SR1 |= (uint16_t)0x0400;

  /* Generate the START Condition */
  I2C_GenerateSTART(MT9D111_I2C, ENABLE);
  
  /* Test on I2C EV6 and clear it */
  timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
  while(!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_MODE_SELECT))
  {
    // If the timeout delay is exceeded, exit with error code
    if((timeout--) == 0)
      return 0xFF;
  } 
  
  /* Send slave device address with read mode selected */
  I2C_Send7bitAddress(MT9D111_I2C, MT9D111_DEVICE_READ_ADDRESS, I2C_Direction_Receiver);

  /* Test on I2C EV6 and clear it */
  timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
  while(!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
  {
    // If the timeout delay is exceeded, exit with error code
    if((timeout--) == 0)
      return 0xFF;
  }
 
  /* Prepare an ACK for the next data received */
  I2C_AcknowledgeConfig(MT9D111_I2C, ENABLE);

  /* Test on I2C EV7 and clear it */
  timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
  while(!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_BYTE_RECEIVED))
  {
    // If the timeout delay is exceeded, exit with error code
    if((timeout--) == 0)
      return 0xFF;
  }
	
	regVal = ((unsigned short) I2C_ReceiveData(MT9D111_I2C)) << 8;

  /* Prepare an NACK for the next data received */
  I2C_AcknowledgeConfig(MT9D111_I2C, DISABLE);

  /* Test on I2C EV7 and clear it */
  timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
  while(!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_BYTE_RECEIVED))
  {
    // If the timeout delay is exceeded, exit with error code
    if((timeout--) == 0)
      return 0xFF;
  }

  /* Prepare STOP after receiving data */
  I2C_GenerateSTOP(MT9D111_I2C, ENABLE);

  /* Receive the Data */
  regVal += I2C_ReceiveData(MT9D111_I2C);
  
  while(((MT9D111_I2C->CR1)&0x0200) != 0);

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
uchar MT9D111_WriteReg(uchar regAddr, ushort regVal){
  unsigned int timeout = I2C_TIMEOUT_MAX;

  /* Generate the START Condition */
  I2C_GenerateSTART(MT9D111_I2C, ENABLE);

  /* Test on I2C EV5 and clear it */
  timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
  while(!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_MODE_SELECT))
  {
    // If the timeout delay is exceeded, exit with error code
    if((timeout--) == 0){
      return 0xFF;
    }
  }
   
  /* Send slave device address with write mode selected */
  I2C_Send7bitAddress(MT9D111_I2C, MT9D111_DEVICE_WRITE_ADDRESS, I2C_Direction_Transmitter);

  /* Test on I2C EV6 and clear it */
  timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
  while(!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
  {
    // If the timeout delay is exceeded, exit with error code
    if((timeout--) == 0){
      return 0xFF;
    }
  }

  /* Send register address byte */
  I2C_SendData(MT9D111_I2C, regAddr);

  /* Test on I2C EV8 and clear it */
  timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
  while(!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
  {
    // If the timeout delay is exceeded, exit with error code
    if((timeout--) == 0)
      return 0xFF;
  }

  /* Send register data MSB */
  I2C_SendData(MT9D111_I2C, (regVal>>8)&0xFF);

  /* Test on I2C EV8 and clear it */
  timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
  while(!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
  {
    // If the timeout delay is exceeded, exit with error code
    if((timeout--) == 0)
      return 0xFF;
  }

  /* Send register data LSB */
  I2C_SendData(MT9D111_I2C, regVal&0xFF);

  /* Test on I2C EV8 and clear it */
  timeout = I2C_TIMEOUT_MAX;  // Initialize timeout value
  while(!I2C_CheckEvent(MT9D111_I2C, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
  {
    // If the timeout delay is exceeded, exit with error code
    if((timeout--) == 0)
      return 0xFF;
  }

  /* Generate the STOP condition */
  I2C_GenerateSTOP(MT9D111_I2C, ENABLE);
  while(((MT9D111_I2C->CR1)&0x0200) != 0);

  /* If operation is OK, return 0 */
  return 0;
}

ushort MT9D111_ReadVar(uchar driverID, uchar varOffset, uchar varSize){
  ushort varAddr, varData;

  varAddr = (varSize == 1 ? 0x8000 : 0x0) + (1 << 13);
  varAddr += ( ((ushort) driverID) << 8) + varOffset;

  MT9D111_WriteReg(PAGE_SELECT_REG, 0x01);
  MT9D111_WriteReg(UC_VAR_ADDR_REG, varAddr);
  varData = MT9D111_ReadReg(UC_VAR_DATA_REG);

  return varData;
}

uchar MT9D111_WriteVar(uchar driverID, uchar varOffset, uchar varSize, ushort varData){
  ushort varAddr;

  varAddr = (varSize == 1 ? 0x8000 : 0x0) + (1 << 13);
  varAddr += ( ((ushort) driverID) << 8) + varOffset;
  
  if(varSize == 1)
    varData &= 0xFF;

  MT9D111_WriteReg(PAGE_SELECT_REG, 0x01);
  MT9D111_WriteReg(UC_VAR_ADDR_REG, varAddr);
  MT9D111_WriteReg(UC_VAR_DATA_REG, varData);

  return 0;
}
