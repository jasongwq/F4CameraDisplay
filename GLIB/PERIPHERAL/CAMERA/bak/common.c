#include "common.h"
#include "fsmc_tft.h"
//#include "numtostr.h"
#include "OV7670_Reg.h"
#include "delay.h"
#include "sys.h"


#define Delay_Nms delay_ms
#define Delay_Nus(n) delay_us(n/10)

//#define DCMI_DR_ADDRESS       	0x50050028 // 0x50000000 + 0x00050000 + 0x00000028

#define SCCB_SIO_C		GPIO_Pin_8	   //CSCL	PB10
#define SCCB_SIO_D		GPIO_Pin_9	   //SDA	PB11

#define SCCB_SIC_H()     GPIOB->BSRRL = SCCB_SIO_C           //SCK   PB10
#define SCCB_SIC_L()     GPIOB->BSRRH = SCCB_SIO_C
#define SCCB_SID_H()     GPIOB->BSRRL = SCCB_SIO_D           //SDA   PB11
#define SCCB_SID_L()     GPIOB->BSRRH = SCCB_SIO_D

#define SCCB_SID_STATE	 GPIOB->IDR&(SCCB_SIO_D)

//__IO uint16_t RAM_Buffer[picture_x * picture_y];

u8 OV7670_Init(void)
{
  unsigned char  i;
  Cam_Init();
	SCCB_Init();
	if(OV_WriteReg(0x12, 0x80)!=0) //Reset SCCB
	{
		return 1 ;//
	}
	Delay_Nms(5);
  
	for(i=0;i<OV7670_REG_NUM;i++)
	{
		if(OV_WriteReg(OV7670_reg[i][0],OV7670_reg[i][1])){return 1;}
	}
	
//	OV7670_HW(184,10,320,240);
	OV7670_config_window(184,10,320,240);
	return 0; 
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
void Cam_Start(void)
{
  	DMA_Cmd(DMA2_Stream1, ENABLE); 
		while (DMA_GetCmdStatus(DMA2_Stream1) != ENABLE);
    DCMI_Cmd(DISABLE);                        // Wylacz DCMI
    DCMI->CR &= 0xFFFD;                       // Wybierz tryb podgladu
    DCMI_Cmd(ENABLE);                         // Wlacz DCMI
    DCMI_CaptureCmd(ENABLE);      
}

void Cam_Init(void)
{
	DCMI_InitTypeDef  DCMI_InitStructure;
	DMA_InitTypeDef   DMA_InitStructure;
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	/*---����DCMIʱ��----*/
	RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_DCMI, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB | 
												 RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOE, ENABLE);//ʹ��DCMI��GPIOʱ��
	
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_MCO);

  /*------------DCMI �ܽ�����------------*/
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_MCO);//MCO1:PA8  ��ΪOV7670��CLK
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;  
	GPIO_Init(GPIOA, &GPIO_InitStructure);	    	 
//	RCC_MCO1Config(RCC_MCO1Source_PLLCLK, RCC_MCO1Div_3); 
//	RCC_MCO1Config(RCC_MCO1Source_HSE, RCC_MCO1Div_1); 
	RCC_MCO1Config(RCC_MCO1Source_HSI, RCC_MCO1Div_1); 

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource4, GPIO_AF_DCMI);//DCMI_HSYNC   *****
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_DCMI);//DCMI_PIXCLK  *****
	
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_DCMI);//DCMI_D5 			  
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_DCMI);//DCMI_VSYNC 
	
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource5, GPIO_AF_DCMI);//DCMI_D6 
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource6, GPIO_AF_DCMI);//DCMI_D7    *****			  
//D6 D7 yuan pb8 pb9 gai pe5 pe6
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_DCMI);//DCMI_D0 
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_DCMI);//DCMI_D1 	
	
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource0, GPIO_AF_DCMI);//DCMI_D2 	 //.......
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource1, GPIO_AF_DCMI);//DCMI_D3 
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource4, GPIO_AF_DCMI);//DCMI_D4 		//PC11
//D4 yuan:pc11 gai pe4
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1| GPIO_Pin_4|GPIO_Pin_5 | GPIO_Pin_6;          // 
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	DCMI_DeInit();
	DCMI_InitStructure.DCMI_CaptureMode = DCMI_CaptureMode_Continuous; //DCMI_CaptureMode_SnapShot;   //DCMI_CaptureMode_Continuous; //����ģʽ		  ֻ��������ģʽ
	DCMI_InitStructure.DCMI_SynchroMode = DCMI_SynchroMode_Hardware;	 //Ӳ��
	DCMI_InitStructure.DCMI_PCKPolarity = DCMI_PCKPolarity_Falling;	 //�½�����
	DCMI_InitStructure.DCMI_VSPolarity = DCMI_VSPolarity_High;		 //���Ը�
	DCMI_InitStructure.DCMI_HSPolarity = DCMI_HSPolarity_High;		 //���Ը�
	DCMI_InitStructure.DCMI_CaptureRate = DCMI_CaptureRate_All_Frame;	 //��������Ƶ��	  ALL��ʱ�� �ٶ����
	DCMI_InitStructure.DCMI_ExtendedDataMode = DCMI_ExtendedDataMode_8b;		 //ֻ��8B ��Ϊ������ ȫ����
	DCMI_Init(&DCMI_InitStructure);
	DCMI_ITConfig(DCMI_IT_FRAME,ENABLE);//DCMI ��������ж�
	DCMI_NVIC_Config();	
	
	
	DMA_DeInit(DMA2_Stream1);		 //ֻ��STREAM1��ͨ��1�Ƕ�ӦDCMI��
	DMA_InitStructure.DMA_Channel = DMA_Channel_1;  
	DMA_InitStructure.DMA_PeripheralBaseAddr =  (uint32_t)(&DCMI->DR);     //DCMI_DR_ADDRESS;	
	DMA_InitStructure.DMA_Memory0BaseAddr =(uint32_t) TFT_DATA_ADD;
		//yuan DMA DMA_Memory0BaseAddr wei  RAM_Buffer

/*	
	DMA_InitStructure.DMA_DIR = 1;//DMA_DIR_PeripheralToMemory;
	DMA_InitStructure.DMA_BufferSize =  picture_x * picture_y;									  
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;		    //�������ӣ���Ϊ��ʵʱ��
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;				        //�������ӣ���Ϊ��ʵʱ��
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word; //DCMI �����ݸ�ʽ��32λ��
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;	    //LCD������16λ��
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;						              //�����ֱ��ģʽ��������ʽ���벻����
	DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Enable;
	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;  
*/
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
	DMA_InitStructure.DMA_BufferSize =  1;//picture_x * picture_y * 2 / 4;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable; 
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Enable;
	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
	
	DMA_Init(DMA2_Stream1, &DMA_InitStructure);	
}

/*--------------------SCCB--------------------------------*/
void SCCB_Init(void)
{
  	GPIO_InitTypeDef  GPIO_InitStructure;
  	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

  	GPIO_InitStructure.GPIO_Pin = SCCB_SIO_C|SCCB_SIO_D;  //SCCB_SIC:PB10 ��SCCB_SID:PB11   
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;			
  	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void SCCB_SID_DATA_OUT(void)//����SCCB_SIDΪ���
{
  	GPIO_InitTypeDef  GPIO_InitStructure;

  	GPIO_InitStructure.GPIO_Pin = SCCB_SIO_D;               
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;			
  	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  	GPIO_Init(GPIOB, &GPIO_InitStructure);
}
void SCCB_SID_DATA_IN(void)//����SCCB_SIDΪ����
{
  	GPIO_InitTypeDef  GPIO_InitStructure;

  	GPIO_InitStructure.GPIO_Pin = SCCB_SIO_D;               
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;			
  	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  	GPIO_Init(GPIOB, &GPIO_InitStructure);
}
void SCCB_Start(void)
{
    SCCB_SID_H();     //�����߸ߵ�ƽ
    Delay_Nus(50);
    SCCB_SIC_H();	   //��ʱ���߸ߵ�ʱ���������ɸ�����
    Delay_Nus(50);
    SCCB_SID_L();
    Delay_Nus(50);
    SCCB_SIC_L();	 //�����߻ָ��͵�ƽ��������������Ҫ
    Delay_Nus(50);
}
void SCCB_Stop(void)
{
    SCCB_SID_L();
    Delay_Nus(50);
    SCCB_SIC_H();	
    Delay_Nus(50);  
    SCCB_SID_H();	
    Delay_Nus(50);  
}
u8 SCCB_Write(u8 m_data)
{
	u8 j,tem;

	for(j=0;j<8;j++) //ѭ��8�η�������
	{
		if((m_data<<j)&0x80)
			SCCB_SID_H();
		else SCCB_SID_L();
		Delay_Nus(50);
		SCCB_SIC_H();	
		Delay_Nus(50);
		SCCB_SIC_L();	
		Delay_Nus(50);
	}
	Delay_Nus(10);
	SCCB_SID_DATA_IN();
	Delay_Nus(50);
	SCCB_SIC_H();	
	Delay_Nus(10);
	if(SCCB_SID_STATE)
	tem=0;//SDA=1����ʧ��
	else 
	tem=1;//SDA=0���ͳɹ�������1
	SCCB_SIC_L();	
	Delay_Nus(50);	
  SCCB_SID_DATA_OUT();
	return tem;  
}
u8 SCCB_Read(void)
{
	u8 read,j;
	read=0x00;
	
	SCCB_SID_DATA_IN();
	Delay_Nus(50);
	for(j=8;j>0;j--) //ѭ��8�ν�������
	{		     
		Delay_Nus(50);
		SCCB_SIC_H();
		Delay_Nus(50);
		read=read<<1;
		if(SCCB_SID_STATE)
		read=read+1; 
		SCCB_SIC_L();
		Delay_Nus(50);
	}	
    SCCB_SID_DATA_OUT();
	return read;
}
void noAck(void)	 
{	
	SCCB_SID_H();	
	Delay_Nus(50);	
	SCCB_SIC_H();	
	Delay_Nus(50);	
	SCCB_SIC_L();	
	Delay_Nus(50);	
	SCCB_SID_L();	
	Delay_Nus(50);
}
/*---------------OV ��������----------------------*/
void OV_Reset(void)
{
	OV_WriteReg(0x12,0x80);	  //��λ���� COM7�Ĵ���
}
u8 OV_WriteReg(u8 regID, u8 regDat)
{
	SCCB_Start();//����SCCB ���߿�ʼ��������
	if(SCCB_Write(0x42)==0)//д��ַ
	{
		SCCB_Stop();//����SCCB ����ֹͣ��������
		return 1;//���󷵻�
	}
	Delay_Nus(10);
  	if(SCCB_Write(regID)==0)//������ID
	{
		SCCB_Stop();//����SCCB ����ֹͣ��������
		return 2;//���󷵻�
	}
	Delay_Nus(10);
  	if(SCCB_Write(regDat)==0)//д���ݵ�������
	{
		SCCB_Stop();//����SCCB ����ֹͣ��������
		return 3;//���󷵻�
	}
  	SCCB_Stop();//����SCCB ����ֹͣ��������	
  	return 0;//�ɹ�����
}
u8 OV_ReadID(void)
{
	u8 temp;
	OV_ReadReg(0x0b,&temp);
  	return temp;
}
//��OV7660�Ĵ���
u8 OV_ReadReg(u8 regID, u8 *regDat)
{
	//ͨ��д�������üĴ�����ַ
	SCCB_Start();
	if(SCCB_Write(0x42)==0)//д��ַ
	{
		SCCB_Stop();//����SCCB ����ֹͣ��������
		return 1;//���󷵻�
	}
	Delay_Nus(10);
  	if(SCCB_Write(regID)==0)//������ID
	{
		SCCB_Stop();//����SCCB ����ֹͣ��������
		return 2;//���󷵻�
	}
	SCCB_Stop();//����SCCB ����ֹͣ��������	
	Delay_Nus(10);	
	//���üĴ�����ַ�󣬲��Ƕ�
	SCCB_Start();
	if(SCCB_Write(0x43)==0)//����ַ
	{
		SCCB_Stop();//����SCCB ����ֹͣ��������
		return 3;//���󷵻�
	}
	Delay_Nus(10);
  	*regDat=SCCB_Read();//���ض�����ֵ
  	noAck();//����NACK����
  	SCCB_Stop();//����SCCB ����ֹͣ��������
  	return 0;//�ɹ�����
}

void OV7670_HW(u16 hstart,u16 vstart,u16 hstop,u16 vstop)
{
	u8 v;		
	OV_WriteReg(0x17,(hstart>>3)&0xff);//HSTART
	OV_WriteReg(0x18,(hstop>>3)&0xff);//HSTOP
	OV_ReadReg(0x32,&v);
	v=(v&0xc0)|((hstop&0x7)<<3)|(hstart&0x7);
	OV_WriteReg(0x32,v);//HREF
	
	OV_WriteReg(0x19,(vstart>>2)&0xff);//VSTART ��ʼ��8λ
	OV_WriteReg(0x1a,(vstop>>2)&0xff);//VSTOP	������8λ
	OV_ReadReg(0x03,&v);
	v=(v&0xf0)|((vstop&0x3)<<2)|(vstart&0x3);	
	OV_WriteReg(0x03,v);//VREF																 
	OV_WriteReg(0x11,0x00);
}


void OV7670_config_window(u16 startx,u16 starty,u16 width,u16 height)
{ 
	u16 endx=(startx+width*2)%784;
	u16 endy=(starty+height*2);
	u8 x_reg,y_reg;
	u8 temp; 
	OV_ReadReg(0x32,&x_reg);
	x_reg&=0xC0; 
	OV_ReadReg(0x03,&y_reg);
	y_reg &=0xF0;
	
	//Set HREF 
	temp=x_reg|((endx&0x7)<<3)|(startx&0x7);
	OV_WriteReg(0x32,temp);
	temp=(startx&0x7F8)>>3; 
	OV_WriteReg(0x17,temp);
	temp=(endx&0x7F8)>>3; 
	OV_WriteReg(0x18,temp); 
	
	//Set VREF 
	temp=y_reg|((endy&0x3)<<2)|(starty&0x3);
	OV_WriteReg(0x03,temp);
	temp=(starty&0x3FC)>>2; 
	OV_WriteReg(0x19,temp);
	temp=(endy&0x3FC)>>2; 
	OV_WriteReg(0x1A,temp);
}


