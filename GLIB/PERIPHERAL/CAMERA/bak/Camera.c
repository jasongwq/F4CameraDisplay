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
//#define MT9D111_I2C   I2C1      // Interfejs szeregowy kamery podlaczony do szyny I2C1

//void RCC_GPIO_Config()
//{
//    /* Enable GPIOs clock */
//    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB |
//                           RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOD |
//                           RCC_AHB1Periph_GPIOE, ENABLE);
//}


//void DCMI_NVIC_Configuration(u8 PriorityGroup,u8 PreemptionPriority,u8 SubPriority)
//{
//	NVIC_InitTypeDef NVIC_InitStructure;

//    if(PriorityGroup==0)NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
//	else if(PriorityGroup==1)NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
//	else if(PriorityGroup==2)NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
//	else if(PriorityGroup==3)NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3);
//	else if(PriorityGroup==4)NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
//	else {}
//  
//    /* Enable and set DCMI Interrupts to the (0,0) priority level  */
//    NVIC_InitStructure.NVIC_IRQChannel = DCMI_IRQn;
//    if(PreemptionPriority!=0)NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = PreemptionPriority;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = SubPriority;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);
//}

//void I2C_Config()
//{
//    I2C_InitTypeDef  I2C_InitStructure;
//    /*** Configures the I2C to communicate with MT9D111 camera module ***/
//		
//    /* Enable I2C1 clock */
//    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
//    /* I2C DeInit */
//    I2C_DeInit(MT9D111_I2C);

//    /* I2C configuration */
//    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
//    I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
//    I2C_InitStructure.I2C_OwnAddress1 = 0x00;
//    I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
//    I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
//    I2C_InitStructure.I2C_ClockSpeed = 400000;  // 400kHz
//    I2C_Init(MT9D111_I2C, &I2C_InitStructure);

//    /* Enable I2C */
//    I2C_Cmd(MT9D111_I2C, ENABLE);
//}

//static void MCO_Init(void)
//{
//		GPIO_InitTypeDef GPIO_InitStructure;
//    /****** Configures the XCLK signal used as input clock for MT9D111 camera module ******/

//    /*** Connect MCO1 pin to AF0 ***/
//    GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_MCO);

//    /*** MCO1 GPIO configuration ***/
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//    GPIO_Init(GPIOA, &GPIO_InitStructure);

//    /* Configure MCO1 output clock */
//    RCC_MCO1Config(RCC_MCO1Source_PLLCLK, RCC_MCO1Div_3); //F_XCLK = 56MHz
//}
//static void GPIO_DCMI_Config(void)
//{
//    GPIO_InitTypeDef GPIO_InitStructure;
//    /****** Configures the DCMI GPIOs ******/

//    /*** Connect DCMI pins to AF13 ***/
//    /* HSYNC(PA4), PIXCLK(PA6) */
//    GPIO_PinAFConfig(GPIOA, GPIO_PinSource4, GPIO_AF_DCMI);
//    GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_DCMI);
//    /* D5(PB6), VSYNC(PB7) */
//    GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_DCMI);
//    GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_DCMI);
//    /* D0..1(PC6/7) */
//    GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_DCMI);
//    GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_DCMI);
//    /* D2..4,6..7(PE0/1/4/5/6) */
//    GPIO_PinAFConfig(GPIOE, GPIO_PinSource0, GPIO_AF_DCMI);
//    GPIO_PinAFConfig(GPIOE, GPIO_PinSource1, GPIO_AF_DCMI);
//    GPIO_PinAFConfig(GPIOE, GPIO_PinSource4, GPIO_AF_DCMI);
//    GPIO_PinAFConfig(GPIOE, GPIO_PinSource5, GPIO_AF_DCMI);
//    GPIO_PinAFConfig(GPIOE, GPIO_PinSource6, GPIO_AF_DCMI);

//    /*** DCMI GPIOs configuration ***/
//    /* HSYNC(PA4), PIXCLK(PA6) */
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_6;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
//    GPIO_Init(GPIOA, &GPIO_InitStructure);
//    /* D5(PB6), VSYNC(PB7) */
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
//    GPIO_Init(GPIOB, &GPIO_InitStructure);
//    /* D0..1(PC6/7) */
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
//    GPIO_Init(GPIOC, &GPIO_InitStructure);
//    /* D2..4,6..7(PE0/1/4/5/6) */
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6;
//    GPIO_Init(GPIOE, &GPIO_InitStructure);
//}
//static void GPIO_I2c_Config()
//{
//    GPIO_InitTypeDef GPIO_InitStructure;

//    /****** Configures the I2C2 GPIOs ******/

//    /*** Connect I2C1 pins to AF4 ***/
//    GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_I2C1);
//    GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_I2C1);

//    /*** I2C1 GPIOs configuration ***/
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
//    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
//    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//    GPIO_Init(GPIOB, &GPIO_InitStructure);
//}

//#define DCMI_DR_ADDRESS   0x50050028
//#define FSMC_LCD_ADDRESS  0x60020000



//void DCMI_Config()
//{
//    DCMI_InitTypeDef DCMI_InitStructure;
//    DMA_InitTypeDef  DMA_InitStructure;
//    /* Enable DCMI clock */
//    RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_DCMI, ENABLE);

//    /*** Configures the DCMI to receive data from MT9D111 ***/
//    DCMI_DeInit();

//    /* DCMI configuration */
//    DCMI_InitStructure.DCMI_CaptureMode = DCMI_CaptureMode_Continuous;
//    DCMI_InitStructure.DCMI_SynchroMode = DCMI_SynchroMode_Hardware;
//    DCMI_InitStructure.DCMI_PCKPolarity = DCMI_PCKPolarity_Rising;        // Read data on rising edge of PIXCLK
//    DCMI_InitStructure.DCMI_VSPolarity  = DCMI_VSPolarity_Low;            // Data valid on VSYNC high
//    DCMI_InitStructure.DCMI_HSPolarity  = DCMI_HSPolarity_Low;            // Data valid on HSYNC high
//    DCMI_InitStructure.DCMI_CaptureRate = DCMI_CaptureRate_All_Frame;
//    DCMI_InitStructure.DCMI_ExtendedDataMode = DCMI_ExtendedDataMode_8b;  // 8-bit data interface
//    DCMI_Init(&DCMI_InitStructure);

//    /* Enable interrupts from DCMI interface */
//    /* OPCJONALNIE */
//    //DCMI_ITConfig(DCMI_IT_FRAME, ENABLE); // Przerwanie generowane po odebraniu jednej ramki obrazu
//    DCMI_ITConfig(DCMI_IT_VSYNC, ENABLE); // Przerwanie generowane przy przejsciu sygnalu VSYNC ze stanu aktywnego do nieaktywnego
//    //DCMI_ITConfig(DCMI_IT_LINE, ENABLE);  // Przerwanie generowane po odebraniu jednego wiersza danych obrazu
//    //DCMI_ITConfig(DCMI_IT_OVF, ENABLE);
//    //DCMI_ITConfig(DCMI_IT_ERR, ENABLE);
//    /* OPCJONALNIE */

//    

//    /*** Configures the DMA2 to transfer data from DCMI ***/
//		
//		/* Enable DMA2 clock */
//    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);
//    /* DMA2 Stream1 DeInit */
//    DMA_DeInit(DMA2_Stream1);
//    while (DMA_GetCmdStatus(DMA2_Stream1) != DISABLE);

//    /* DMA2 Stream1 configuration */
//    DMA_InitStructure.DMA_Channel = DMA_Channel_1;
//    DMA_InitStructure.DMA_PeripheralBaseAddr = DCMI_DR_ADDRESS;               // Rejestr 32-bitowy
//    DMA_InitStructure.DMA_Memory0BaseAddr = FSMC_LCD_ADDRESS;                 // Rejestry 16-bitowe
//    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;                   // DCMI ---> Buffer
//    DMA_InitStructure.DMA_BufferSize = 1;
//    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
//    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;
//    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;   // 32-bit
//    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;       // 16-bit
//    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
//    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
//    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Enable;
//    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
//    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
//    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
//    DMA_Init(DMA2_Stream1, &DMA_InitStructure);

//    /* Enable DMA2 Stream 1 */
//    DMA_Cmd(DMA2_Stream1, ENABLE);
//    while (DMA_GetCmdStatus(DMA2_Stream1) != ENABLE);
//}

//void Camera_Ov7670_Init(void)
//{
//RCC_GPIO_Config();
//DCMI_NVIC_Configuration(1,0,0);
//MCO_Init();
//GPIO_DCMI_Config();
//DCMI_Config();
//GPIO_I2c_Config();
//I2C_Config();	
//delay_ms(100);

//MT9D111_WriteReg(PAGE_SELECT_REG, 0x0); // Select Page 0 - Sensor Core
//    int val;
//    val = MT9D111_ReadReg(0x00);
//    if (val == 0x1519)
//    {
//        // Camera MT9D111 detected
//        sprintf(camera_state_info, " MT9D111 not connected. ");
//    }
//    else
//    {
//        // Camera MT9D111 not detected
//        sprintf(camera_state_info, " MT9D111 connected. ");
//    }
//    MT9D111_WriteReg(PAGE_SELECT_REG, 0x1);               // Select Page 1 - IFP
//    regVal = MT9D111_ReadReg(UC_BOOT_MODE_REG);
//    MT9D111_WriteReg(UC_BOOT_MODE_REG, (regVal | 0x01));  // Reset microcontroller
//    delay_ms(100);                                            // Wait 100 ms

//    MT9D111_Init();                                       // Inicjalizacja kamery
//    LCD_ShowNum(10, 30, val, 5, 16);
//    LCD_ShowString(10, 10, 160, 16, 16, camera_state_info);
//    //LCD_DrawCurve_Init();
//    /*
//        LCD_Clear(WHITE);
//    delay_ms(1000);
//    LCD_Clear(BLACK);
//    delay_ms(1000);
//    LCD_Clear(WHITE);
//    delay_ms(1000);
//    LCD_Clear(BLACK);
//    */
//    //LCD_SetDisplayWindow(0,0, 240,320);
//    LCD_Scan_Dir(0);
//    LCD_SetCursor(0, 0);

//    LCD_WriteRAM_Prepare();                   // Prepare to write GRAM
//    MT9D111_WriteReg(PAGE_SELECT_REG, 0x0);   // Select Page 0 - Sensor Core
//    MT9D111_WriteReg(SHUTTER_WIDTH_REG, 700); // Ustawienie wartosci przeslony

//    DCMI_Cmd(DISABLE);                        // Wylacz DCMI
//    DCMI->CR &= 0xFFFD;                       // Wybierz tryb podgladu
//    DCMI_Cmd(ENABLE);                         // Wlacz DCMI
//    DCMI_CaptureCmd(ENABLE);    
//}








