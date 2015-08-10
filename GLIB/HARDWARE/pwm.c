#include "PWM.h"




static GPIO_InitTypeDef GPIO_InitStructure;


static TIM_TimeBaseInitTypeDef  TIM1_TimeBaseStructure,TIM2_TimeBaseStructure,TIM3_TimeBaseStructure,TIM4_TimeBaseStructure,TIM5_TimeBaseStructure,TIM8_TimeBaseStructure,TIM9_TimeBaseStructure,TIM10_TimeBaseStructure,TIM11_TimeBaseStructure,TIM12_TimeBaseStructure,TIM13_TimeBaseStructure,TIM14_TimeBaseStructure;
static TIM_OCInitTypeDef  TIM1_OCInitStructure,TIM2_OCInitStructure,TIM3_OCInitStructure,TIM4_OCInitStructure,TIM5_OCInitStructure,TIM8_OCInitStructure,TIM9_OCInitStructure,TIM10_OCInitStructure,TIM11_OCInitStructure,TIM12_OCInitStructure,TIM13_OCInitStructure,TIM14_OCInitStructure;
//static TIM_BDTRInitTypeDef TIM8_BDTRInitStructure;


/*******************************************************************************
*					TIM1�ĺ���
*******************************************************************************/
void TIM1_PWM_init(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2 ,u8 OC3 ,u8 OC4)							
{  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

#ifdef TIM1_OC1_USE_PA8
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_TIM1);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM1_OC2_USE_PA9
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_TIM1);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM1_OC3_USE_PA10
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_TIM1);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM1_OC4_USE_PA11
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOA, GPIO_PinSource11, GPIO_AF_TIM1);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif

#ifdef TIM1_OC1_USE_PE9
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOE, GPIO_PinSource9, GPIO_AF_TIM1);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOE, &GPIO_InitStructure);
    }
#endif
#ifdef TIM1_OC2_USE_PE11
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOE, GPIO_PinSource11, GPIO_AF_TIM1);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOE, &GPIO_InitStructure);
    }
#endif
#ifdef TIM1_OC3_USE_PE13
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOE, GPIO_PinSource13, GPIO_AF_TIM1);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOE, &GPIO_InitStructure);
    }
#endif
#ifdef TIM1_OC4_USE_PE14
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOE, GPIO_PinSource14, GPIO_AF_TIM1);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOE, &GPIO_InitStructure);
    }
#endif
    TIM_DeInit(TIM1);												 //��λ��ʱ��8���мĴ���

    /* Time Base configuration */
    TIM1_TimeBaseStructure.TIM_Prescaler = Prescaler-1;						 //Ԥ��Ƶ��Ϊ0,����Ƶ
    TIM1_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //��¦��ʽΪ˳�����ģʽ��������
    TIM1_TimeBaseStructure.TIM_Period = Period-1;					     //���ü��������������س�ֵ
    TIM1_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //����ʱ�ӷָ�ֵ
    TIM1_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //ѭ����������ֵ

    TIM_TimeBaseInit(TIM1,&TIM1_TimeBaseStructure);				     //�����ϲ�����ʼ����ʱ��ʱ�����ģ��
  
    /* Channel 1 Configuration in PWM mode */
    TIM1_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //�����ʽΪPWMģʽ1
 
    TIM1_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //ʹ������Ƚ�״̬
    TIM1_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //ʹ�ܶ�ʱ���������               
    TIM1_OCInitStructure.TIM_Pulse = 5000; 							 //��������
    TIM1_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //����Ƚϼ���Ϊ��
    TIM1_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //�򿪿���״̬ѡ��ر�
  
    /* ��ʼ��TM1ͨ��1*/
    if(OC1==1)TIM_OC1Init(TIM1,&TIM1_OCInitStructure); 		         //�����ϲ�����ʼ��TIM8��ͨ��1
	if(OC2==1)TIM_OC2Init(TIM1,&TIM1_OCInitStructure); 		         //�����ϲ�����ʼ��TIM8��ͨ��2
	if(OC3==1)TIM_OC3Init(TIM1,&TIM1_OCInitStructure); 		         //�����ϲ�����ʼ��TIM8��ͨ��3
	if(OC4==1)TIM_OC4Init(TIM1,&TIM1_OCInitStructure); 		         //�����ϲ�����ʼ��TIM8��ͨ��4
 
    /* TIM1 counter enable */
    TIM_Cmd(TIM1,ENABLE);							   //ʹ�ܶ�ʱ��8

    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM1,ENABLE);				   //ʹ�ܶ�ʱ��8��PWM���	 Ƶ��

}  

void TIM1_Change_Period(u16 NoteSet)
{
     TIM1_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM1,&TIM1_TimeBaseStructure);
}
/*******************************���Ƹ���ͨ��������*****************************************************/
void Change_TIM1_OC1_Pulse(u16 Pulse)
{
     TIM1_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC1Init(TIM1,&TIM1_OCInitStructure);
}
void Change_TIM1_OC2_Pulse(u16 Pulse)
{
     TIM1_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC2Init(TIM1,&TIM1_OCInitStructure);
}
void Change_TIM1_OC3_Pulse(u16 Pulse)
{
     TIM1_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC3Init(TIM1,&TIM1_OCInitStructure);
}
void Change_TIM1_OC4_Pulse(u16 Pulse)
{
     TIM1_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC4Init(TIM1,&TIM1_OCInitStructure);
}
/*********************************��ͨ�����Կ���*****************************************************/
void Change_TIM1_OC1_Polarity(u8 i)
{
     if(i==1)TIM1_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM1_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC1Init(TIM1,&TIM1_OCInitStructure);
}
void Change_TIM1_OC2_Polarity(u8 i)
{
     if(i==1)TIM1_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM1_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC2Init(TIM1,&TIM1_OCInitStructure);
}
void Change_TIM1_OC3_Polarity(u8 i)
{
     if(i==1)TIM1_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM1_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC3Init(TIM1,&TIM1_OCInitStructure);
}
void Change_TIM1_OC4_Polarity(u8 i)
{
     if(i==1)TIM1_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM1_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC4Init(TIM1,&TIM1_OCInitStructure);
}
/*******************************************************************************
*					TIM2�ĺ���
*******************************************************************************/
void TIM2_PWM_init(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2 ,u8 OC3 ,u8 OC4)							  
{  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
#ifdef TIM2_OC1_USE_PA0
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_TIM2);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM2_OC1_USE_PA5
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_TIM2);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM2_OC2_USE_PA1
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_TIM2);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM2_OC3_USE_PA2
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_TIM2);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM2_OC4_USE_PA3
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_TIM2);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM2_OC1_USE_PA15
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource15, GPIO_AF_TIM2);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM2_OC2_USE_PB3
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOB, GPIO_PinSource3, GPIO_AF_TIM2);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
#ifdef TIM2_OC3_USE_PB10
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_TIM2);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
#ifdef TIM2_OC4_USE_PB11
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_TIM2);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
    TIM_DeInit(TIM2);												 //��λ��ʱ��8���мĴ���

    /* Time Base configuration */
    TIM2_TimeBaseStructure.TIM_Prescaler = Prescaler-1;				 //Ԥ��Ƶ��Ϊ0,����Ƶ
    TIM2_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //��¦��ʽΪ˳�����ģʽ��������
    TIM2_TimeBaseStructure.TIM_Period = Period-1;					     //���ü��������������س�ֵ
    TIM2_TimeBaseStructure.TIM_ClockDivision =  TIM_CKD_DIV1;		 //����ʱ�ӷָ�ֵ
    TIM2_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //ѭ����������ֵ

    TIM_TimeBaseInit(TIM2,&TIM2_TimeBaseStructure);				     //�����ϲ�����ʼ����ʱ��ʱ�����ģ��
  
    TIM2_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //�����ʽΪPWMģʽ1
    TIM2_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //ʹ������Ƚ�״̬
    TIM2_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //ʹ�ܶ�ʱ���������               
    TIM2_OCInitStructure.TIM_Pulse = 100; 							 //��������
    TIM2_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //����Ƚϼ���Ϊ��
    TIM2_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //�򿪿���״̬ѡ��ر�
  
    if(OC1==1)TIM_OC1Init(TIM2,&TIM2_OCInitStructure); 		         //�����ϲ�����ʼ��TIM2��ͨ��1
	if(OC2==1)TIM_OC2Init(TIM2,&TIM2_OCInitStructure); 		         //�����ϲ�����ʼ��TIM2��ͨ��2
	if(OC3==1)TIM_OC3Init(TIM2,&TIM2_OCInitStructure); 		         //�����ϲ�����ʼ��TIM2��ͨ��3
	if(OC4==1)TIM_OC4Init(TIM2,&TIM2_OCInitStructure); 		         //�����ϲ�����ʼ��TIM2��ͨ��4
 
    /* TIM2 counter enable */
    TIM_Cmd(TIM2,ENABLE);							   //ʹ�ܶ�ʱ��2

    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM2,ENABLE);				   //ʹ�ܶ�ʱ��2��PWM���	 Ƶ��

}  

void TIM2_Change_Period(u16 NoteSet)
{
     TIM2_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM2,&TIM2_TimeBaseStructure);
}
/*******************************���Ƹ���ͨ��������*****************************************************/
void Change_TIM2_OC1_Pulse(u16 Pulse)
{
     TIM2_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC1Init(TIM2,&TIM2_OCInitStructure);
}
void Change_TIM2_OC2_Pulse(u16 Pulse)
{
     TIM2_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC2Init(TIM2,&TIM2_OCInitStructure);
}
void Change_TIM2_OC3_Pulse(u16 Pulse)
{
     TIM2_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC3Init(TIM2,&TIM2_OCInitStructure);
}
void Change_TIM2_OC4_Pulse(u16 Pulse)
{
     TIM2_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC4Init(TIM2,&TIM2_OCInitStructure);
}
/*********************************��ͨ�����Կ���*****************************************************/
void Change_TIM2_OC1_Polarity(u8 i)
{
     if(i==1)TIM2_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM2_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC1Init(TIM2,&TIM2_OCInitStructure);
}
void Change_TIM2_OC2_Polarity(u8 i)
{
     if(i==1)TIM2_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM2_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC2Init(TIM2,&TIM2_OCInitStructure);
}
void Change_TIM2_OC3_Polarity(u8 i)
{
     if(i==1)TIM2_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM2_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC3Init(TIM2,&TIM2_OCInitStructure);
}
void Change_TIM2_OC4_Polarity(u8 i)
{
     if(i==1)TIM2_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM2_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC4Init(TIM2,&TIM2_OCInitStructure);
}

/*******************************************************************************
*					TIM3�ĺ���
*******************************************************************************/

void TIM3_PWM_init(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2 ,u8 OC3 ,u8 OC4)							   
{  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
#ifdef TIM3_OC1_USE_PA6
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_TIM3);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM3_OC1_USE_PB4
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_TIM3);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
#ifdef TIM3_OC2_USE_PA7
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_TIM3);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM3_OC2_USE_PB5
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_TIM3);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
#ifdef TIM3_OC3_USE_PB0
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOB, GPIO_PinSource0, GPIO_AF_TIM3);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
#ifdef TIM3_OC4_USE_PB1
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOB, GPIO_PinSource1, GPIO_AF_TIM3);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif

#ifdef TIM3_OC1_USE_PC6
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_TIM3);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOC, &GPIO_InitStructure);
    }
#endif
#ifdef TIM3_OC2_USE_PC7
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_TIM3);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOC, &GPIO_InitStructure);
    }
#endif
#ifdef TIM3_OC3_USE_PC8
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_TIM3);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOC, &GPIO_InitStructure);
    }
#endif
#ifdef TIM3_OC4_USE_PC9
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOC, GPIO_PinSource9, GPIO_AF_TIM3);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOC, &GPIO_InitStructure);
    }
#endif


    TIM_DeInit(TIM3);												 //��λ��ʱ��8���мĴ���

    /* Time Base configuration */
    TIM3_TimeBaseStructure.TIM_Prescaler = Prescaler-1;				 //Ԥ��Ƶ��Ϊ0,����Ƶ
    TIM3_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //��¦��ʽΪ˳�����ģʽ��������
    TIM3_TimeBaseStructure.TIM_Period =Period-1;					 //���ü��������������س�ֵ
    TIM3_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //����ʱ�ӷָ�ֵ
    TIM3_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //ѭ����������ֵ
    TIM_TimeBaseInit(TIM3,&TIM3_TimeBaseStructure);				     //�����ϲ�����ʼ����ʱ��ʱ�����ģ��
  
    /* Channel 1 Configuration in PWM mode */
    TIM3_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //�����ʽΪPWMģʽ1 
    TIM3_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //ʹ������Ƚ�״̬
    TIM3_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //ʹ�ܶ�ʱ���������               
    TIM3_OCInitStructure.TIM_Pulse = 100; 							 //��������
    TIM3_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //����Ƚϼ���Ϊ��
    TIM3_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //�򿪿���״̬ѡ��ر�
  
    /* ��ʼ��TM3ͨ��1*/
    if(OC1==1)TIM_OC1Init(TIM3,&TIM3_OCInitStructure); 		         //�����ϲ�����ʼ��TIM3��ͨ��1
	if(OC2==1)TIM_OC2Init(TIM3,&TIM3_OCInitStructure); 		         //�����ϲ�����ʼ��TIM3��ͨ��2
	if(OC3==1)TIM_OC3Init(TIM3,&TIM3_OCInitStructure); 		         //�����ϲ�����ʼ��TIM3��ͨ��3
	if(OC4==1)TIM_OC4Init(TIM3,&TIM3_OCInitStructure); 		         //�����ϲ�����ʼ��TIM3��ͨ��4
 
    /* TIM3 counter enable */
    TIM_Cmd(TIM3,ENABLE);							   //ʹ�ܶ�ʱ��8

    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM3,ENABLE);				   //ʹ�ܶ�ʱ��8��PWM���	 Ƶ��

}  

void TIM3_Change_Period(u16 NoteSet)
{
     TIM3_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM3,&TIM3_TimeBaseStructure);
}
/*******************************���Ƹ���ͨ��������*****************************************************/
void Change_TIM3_OC1_Pulse(u16 Pulse)
{
     TIM3_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC1Init(TIM3,&TIM3_OCInitStructure);
}
void Change_TIM3_OC2_Pulse(u16 Pulse)
{
     TIM3_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC2Init(TIM3,&TIM3_OCInitStructure);
}
void Change_TIM3_OC3_Pulse(u16 Pulse)
{
     TIM3_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC3Init(TIM3,&TIM3_OCInitStructure);
}
void Change_TIM3_OC4_Pulse(u16 Pulse)
{
     TIM3_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC4Init(TIM3,&TIM3_OCInitStructure);
}
/*********************************��ͨ�����Կ���*****************************************************/
void Change_TIM3_OC1_Polarity(u8 i)
{
     if(i==1)TIM3_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM3_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC1Init(TIM3,&TIM3_OCInitStructure);
}
void Change_TIM3_OC2_Polarity(u8 i)
{
     if(i==1)TIM3_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM3_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC2Init(TIM3,&TIM3_OCInitStructure);
}
void Change_TIM3_OC3_Polarity(u8 i)
{
     if(i==1)TIM3_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM3_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC3Init(TIM3,&TIM3_OCInitStructure);
}
void Change_TIM3_OC4_Polarity(u8 i)
{
     if(i==1)TIM3_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM3_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC4Init(TIM3,&TIM3_OCInitStructure);
}


/*******************************************************************************
*					TIM4�ĺ���
*******************************************************************************/
void TIM4_PWM_init(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2 ,u8 OC3 ,u8 OC4)							 
{  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

#ifdef TIM4_OC1_USE_PB6
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_TIM4);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
#ifdef TIM4_OC2_USE_PB7
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_TIM4);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
#ifdef TIM4_OC3_USE_PB8
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_TIM4);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
#ifdef TIM4_OC4_USE_PB9
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_TIM4);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
#ifdef TIM4_OC1_USE_PD12
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOD, &GPIO_InitStructure);
    }
#endif
#ifdef TIM4_OC2_USE_PD13
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOD, &GPIO_InitStructure);
    }
#endif
#ifdef TIM4_OC3_USE_PD14
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_TIM4);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOD, &GPIO_InitStructure);
    }
#endif
#ifdef TIM4_OC4_USE_PD15
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_TIM4);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOD, &GPIO_InitStructure);
    }
#endif

    TIM_DeInit(TIM4);												 //��λ��ʱ��8���мĴ���

    /* Time Base configuration */
    TIM4_TimeBaseStructure.TIM_Prescaler =Prescaler-1;						 //Ԥ��Ƶ��Ϊ0,����Ƶ
    TIM4_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //��¦��ʽΪ˳�����ģʽ��������
    TIM4_TimeBaseStructure.TIM_Period = Period-1;					     //���ü��������������س�ֵ
    TIM4_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //����ʱ�ӷָ�ֵ
    TIM4_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //ѭ����������ֵ

    TIM_TimeBaseInit(TIM4,&TIM4_TimeBaseStructure);				     //�����ϲ�����ʼ����ʱ��ʱ�����ģ��
  
    /* Channel 1 Configuration in PWM mode */
    TIM4_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //�����ʽΪPWMģʽ1
 
    TIM4_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //ʹ������Ƚ�״̬
    TIM4_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //ʹ�ܶ�ʱ���������               
    TIM4_OCInitStructure.TIM_Pulse = 100; 							 //��������
    TIM4_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //����Ƚϼ���Ϊ��
    TIM4_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //�򿪿���״̬ѡ��ر�
  
    /* ��ʼ��TM4ͨ��1*/
    if(OC1==1)TIM_OC1Init(TIM4,&TIM4_OCInitStructure); 		         //�����ϲ�����ʼ��TIM3��ͨ��1
	if(OC2==1)TIM_OC2Init(TIM4,&TIM4_OCInitStructure); 		         //�����ϲ�����ʼ��TIM3��ͨ��2
	if(OC3==1)TIM_OC3Init(TIM4,&TIM4_OCInitStructure); 		         //�����ϲ�����ʼ��TIM3��ͨ��3
	if(OC4==1)TIM_OC4Init(TIM4,&TIM4_OCInitStructure); 		         //�����ϲ�����ʼ��TIM3��ͨ��4
 
    /* TIM4 counter enable */
    TIM_Cmd(TIM4,ENABLE);							   //ʹ�ܶ�ʱ��8

    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM4,ENABLE);				   //ʹ�ܶ�ʱ��8��PWM���	 Ƶ��

}  

void TIM4_Change_Period(u16 NoteSet)
{
     TIM4_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM4,&TIM4_TimeBaseStructure);
}
/*******************************���Ƹ���ͨ��������*****************************************************/
void Change_TIM4_OC1_Pulse(u16 Pulse)
{
     TIM4_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC1Init(TIM4,&TIM4_OCInitStructure);
}
void Change_TIM4_OC2_Pulse(u16 Pulse)
{
     TIM4_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC2Init(TIM4,&TIM4_OCInitStructure);
}
void Change_TIM4_OC3_Pulse(u16 Pulse)
{
     TIM4_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC3Init(TIM4,&TIM4_OCInitStructure);
}
void Change_TIM4_OC4_Pulse(u16 Pulse)
{
     TIM4_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC4Init(TIM4,&TIM4_OCInitStructure);
}
/*********************************��ͨ�����Կ���*****************************************************/
void Change_TIM4_OC1_Polarity(u8 i)
{
     if(i==1)TIM4_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM4_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC1Init(TIM4,&TIM4_OCInitStructure);
}
void Change_TIM4_OC2_Polarity(u8 i)
{
     if(i==1)TIM4_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM4_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC2Init(TIM4,&TIM4_OCInitStructure);
}
void Change_TIM4_OC3_Polarity(u8 i)
{
     if(i==1)TIM4_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM4_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC3Init(TIM4,&TIM4_OCInitStructure);
}
void Change_TIM4_OC4_Polarity(u8 i)
{
     if(i==1)TIM4_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM4_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC4Init(TIM4,&TIM4_OCInitStructure);
}





/*******************************************************************************
*					TIM5�ĺ���
*******************************************************************************/
void TIM5_PWM_init(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2 ,u8 OC3 ,u8 OC4)							  
{  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH | RCC_AHB1Periph_GPIOI, ENABLE);

#ifdef TIM5_OC1_USE_PA0
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_TIM5);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM5_OC2_USE_PA1
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_TIM5);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM5_OC3_USE_PA2
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_TIM5);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM5_OC4_USE_PA3
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_TIM5);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM5_OC1_USE_PH10
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOH, GPIO_PinSource10, GPIO_AF_TIM5);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOH, &GPIO_InitStructure);
    }
#endif
#ifdef TIM5_OC2_USE_PH11
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOH, GPIO_PinSource11, GPIO_AF_TIM5);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOH, &GPIO_InitStructure);
    }
#endif
#ifdef TIM5_OC3_USE_PH12
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOH, GPIO_PinSource12, GPIO_AF_TIM5);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOH, &GPIO_InitStructure);
    }
#endif
#ifdef TIM5_OC4_USE_PI13
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOI, GPIO_PinSource13, GPIO_AF_TIM5);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOI, &GPIO_InitStructure);
    }
#endif


    TIM_DeInit(TIM5);												 //��λ��ʱ��8���мĴ���

    /* Time Base configuration */
    TIM5_TimeBaseStructure.TIM_Prescaler = Prescaler-1;						 //Ԥ��Ƶ��Ϊ0,����Ƶ
    TIM5_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //��¦��ʽΪ˳�����ģʽ��������
    TIM5_TimeBaseStructure.TIM_Period = Period-1;					     //���ü��������������س�ֵ
    TIM5_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //����ʱ�ӷָ�ֵ
    TIM5_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //ѭ����������ֵ

    TIM_TimeBaseInit(TIM5,&TIM5_TimeBaseStructure);				     //�����ϲ�����ʼ����ʱ��ʱ�����ģ��
  
    /* Channel 1 Configuration in PWM mode */
    TIM5_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //�����ʽΪPWMģʽ1
 
    TIM5_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //ʹ������Ƚ�״̬
    TIM5_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //ʹ�ܶ�ʱ���������               
    TIM5_OCInitStructure.TIM_Pulse = 100; 							 //��������
    TIM5_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //����Ƚϼ���Ϊ��
    TIM5_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //�򿪿���״̬ѡ��ر�
  
    /* ��ʼ��TM5ͨ��1*/
    if(OC1==1)TIM_OC1Init(TIM5,&TIM5_OCInitStructure); 		         //�����ϲ�����ʼ��TIM3��ͨ��1
	if(OC2==1)TIM_OC2Init(TIM5,&TIM5_OCInitStructure); 		         //�����ϲ�����ʼ��TIM3��ͨ��2
	if(OC3==1)TIM_OC3Init(TIM5,&TIM5_OCInitStructure); 		         //�����ϲ�����ʼ��TIM3��ͨ��3
	if(OC4==1)TIM_OC4Init(TIM5,&TIM5_OCInitStructure); 		         //�����ϲ�����ʼ��TIM3��ͨ��4
 
    /* TIM5 counter enable */
    TIM_Cmd(TIM5,ENABLE);							   //ʹ�ܶ�ʱ��8

    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM5,ENABLE);				   //ʹ�ܶ�ʱ��8��PWM���	 Ƶ��

}  

void TIM5_Change_Period(u16 NoteSet)
{
     TIM5_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM5,&TIM5_TimeBaseStructure);
}
/*******************************���Ƹ���ͨ��������*****************************************************/
void Change_TIM5_OC1_Pulse(u16 Pulse)
{
     TIM5_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC1Init(TIM5,&TIM5_OCInitStructure);
}
void Change_TIM5_OC2_Pulse(u16 Pulse)
{
     TIM5_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC2Init(TIM5,&TIM5_OCInitStructure);
}
void Change_TIM5_OC3_Pulse(u16 Pulse)
{
     TIM5_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC3Init(TIM5,&TIM5_OCInitStructure);
}
void Change_TIM5_OC4_Pulse(u16 Pulse)
{
     TIM5_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC4Init(TIM5,&TIM5_OCInitStructure);
}
/*********************************��ͨ�����Կ���*****************************************************/
void Change_TIM5_OC1_Polarity(u8 i)
{
     if(i==1)TIM5_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM5_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC1Init(TIM5,&TIM5_OCInitStructure);
}
void Change_TIM5_OC2_Polarity(u8 i)
{
     if(i==1)TIM5_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM5_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC2Init(TIM5,&TIM5_OCInitStructure);
}
void Change_TIM5_OC3_Polarity(u8 i)
{
     if(i==1)TIM5_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM5_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC3Init(TIM5,&TIM5_OCInitStructure);
}
void Change_TIM5_OC4_Polarity(u8 i)
{
     if(i==1)TIM5_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM5_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC4Init(TIM5,&TIM5_OCInitStructure);
}


/*******************************************************************************
*					TIM8�ĺ���
*******************************************************************************/
void TIM8_PWM_init(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2 ,u8 OC3 ,u8 OC4)							  
{  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOI, ENABLE);

#ifdef TIM8_OC1_USE_PC6
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_TIM8);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOC, &GPIO_InitStructure);
    }
#endif
#ifdef TIM8_OC2_USE_PC7
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_TIM8);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOC, &GPIO_InitStructure);
    }
#endif
#ifdef TIM8_OC3_USE_PC8
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_TIM8);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOC, &GPIO_InitStructure);
    }
#endif
#ifdef TIM8_OC4_USE_PC9
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOC, GPIO_PinSource9, GPIO_AF_TIM8);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOC, &GPIO_InitStructure);
    }
#endif

#ifdef TIM8_OC1_USE_PI5
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOI, GPIO_PinSource5, GPIO_AF_TIM8);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOI, &GPIO_InitStructure);
    }
#endif
#ifdef TIM8_OC2_USE_PI6
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOI, GPIO_PinSource6, GPIO_AF_TIM8);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOI, &GPIO_InitStructure);
    }
#endif
#ifdef TIM8_OC3_USE_PI7
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOI, GPIO_PinSource7, GPIO_AF_TIM8);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOI, &GPIO_InitStructure);
    }
#endif
#ifdef TIM8_OC4_USE_PI2
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOI, GPIO_PinSource2, GPIO_AF_TIM8);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOI, &GPIO_InitStructure);
    }
#endif

    TIM_DeInit(TIM8);												 //��λ��ʱ��8���мĴ���

    /* Time Base configuration */
    TIM8_TimeBaseStructure.TIM_Prescaler = Prescaler-1;				 //Ԥ��Ƶ��Ϊ0,����Ƶ
    TIM8_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //��¦��ʽΪ˳�����ģʽ��������
    TIM8_TimeBaseStructure.TIM_Period = Period-1;					 //���ü��������������س�ֵ
    TIM8_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //����ʱ�ӷָ�ֵ
    TIM8_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //ѭ����������ֵ

    TIM_TimeBaseInit(TIM8,&TIM8_TimeBaseStructure);				     //�����ϲ�����ʼ����ʱ��ʱ�����ģ��
  
    /* Channel 1 Configuration in PWM mode */
    TIM8_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //�����ʽΪPWMģʽ1 
    TIM8_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //ʹ������Ƚ�״̬
    TIM8_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //ʹ�ܶ�ʱ���������               
    TIM8_OCInitStructure.TIM_Pulse = 100; 							 //��������
    TIM8_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //����Ƚϼ���Ϊ��
    TIM8_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //�򿪿���״̬ѡ��ر�
  
    /* ��ʼ��TM8ͨ��1*/
    if(OC1==1)TIM_OC1Init(TIM8,&TIM8_OCInitStructure); 		         //�����ϲ�����ʼ��TIM8��ͨ��1
	if(OC2==1)TIM_OC2Init(TIM8,&TIM8_OCInitStructure); 		         //�����ϲ�����ʼ��TIM8��ͨ��2
	if(OC3==1)TIM_OC3Init(TIM8,&TIM8_OCInitStructure); 		         //�����ϲ�����ʼ��TIM8��ͨ��3
	if(OC4==1)TIM_OC4Init(TIM8,&TIM8_OCInitStructure); 		         //�����ϲ�����ʼ��TIM8��ͨ��4
 
    /* TIM8 counter enable */
    TIM_Cmd(TIM8,ENABLE);							   //ʹ�ܶ�ʱ��8
    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM8,ENABLE);				   //ʹ�ܶ�ʱ��8��PWM���	 Ƶ��

}  

void TIM8_Change_Period(u16 NoteSet)
{
     TIM8_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM8,&TIM8_TimeBaseStructure);
}
/*******************************���Ƹ���ͨ��������*****************************************************/
void Change_TIM8_OC1_Pulse(u16 Pulse)
{
     TIM8_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC1Init(TIM8,&TIM8_OCInitStructure);
}
void Change_TIM8_OC2_Pulse(u16 Pulse)
{
     TIM8_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC2Init(TIM8,&TIM8_OCInitStructure);
}
void Change_TIM8_OC3_Pulse(u16 Pulse)
{
     TIM8_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC3Init(TIM8,&TIM8_OCInitStructure);
}
void Change_TIM8_OC4_Pulse(u16 Pulse)
{
     TIM8_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC4Init(TIM8,&TIM8_OCInitStructure);
}
/*********************************��ͨ�����Կ���*****************************************************/
void Change_TIM8_OC1_Polarity(u8 i)
{
     if(i==1)TIM8_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM8_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC1Init(TIM8,&TIM8_OCInitStructure);
}
void Change_TIM8_OC2_Polarity(u8 i)
{
     if(i==1)TIM8_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM8_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC2Init(TIM8,&TIM8_OCInitStructure);
}
void Change_TIM8_OC3_Polarity(u8 i)
{
     if(i==1)TIM8_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM8_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC3Init(TIM8,&TIM8_OCInitStructure);
}
void Change_TIM8_OC4_Polarity(u8 i)
{
     if(i==1)TIM8_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM8_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC4Init(TIM8,&TIM8_OCInitStructure);
}


/*******************************************************************************
*					TIM9�ĺ���
*******************************************************************************/
void TIM9_PWM_init(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2)		
{  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

#ifdef TIM9_OC1_USE_PA2
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_TIM9);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM9_OC2_USE_PA3
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_TIM9);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif

#ifdef TIM9_OC1_USE_PE5
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOE, GPIO_PinSource5, GPIO_AF_TIM9);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOE, &GPIO_InitStructure);
    }
#endif
#ifdef TIM9_OC2_USE_PE6
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOE, GPIO_PinSource6, GPIO_AF_TIM9);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOE, &GPIO_InitStructure);
    }
#endif

    TIM_DeInit(TIM9);												 //��λ��ʱ��8���мĴ���

    /* Time Base configuration */
    TIM9_TimeBaseStructure.TIM_Prescaler = Prescaler-1;				 //Ԥ��Ƶ��Ϊ0,����Ƶ
    TIM9_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //��¦��ʽΪ˳�����ģʽ��������
    TIM9_TimeBaseStructure.TIM_Period = Period-1;					 //���ü��������������س�ֵ
    TIM9_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //����ʱ�ӷָ�ֵ
    TIM9_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //ѭ����������ֵ

    TIM_TimeBaseInit(TIM9,&TIM9_TimeBaseStructure);				     //�����ϲ�����ʼ����ʱ��ʱ�����ģ��
  
    /* Channel 1 Configuration in PWM mode */
    TIM9_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //�����ʽΪPWMģʽ1 
    TIM9_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //ʹ������Ƚ�״̬
    TIM9_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //ʹ�ܶ�ʱ���������               
    TIM9_OCInitStructure.TIM_Pulse = 100; 							 //��������
    TIM9_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //����Ƚϼ���Ϊ��
    TIM9_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //�򿪿���״̬ѡ��ر�
  
    /* ��ʼ��TM9ͨ��1*/
    if(OC1==1)TIM_OC1Init(TIM9,&TIM9_OCInitStructure); 		         //�����ϲ�����ʼ��TIM8��ͨ��1
	if(OC2==1)TIM_OC2Init(TIM9,&TIM9_OCInitStructure); 		         //�����ϲ�����ʼ��TIM8��ͨ��2
 
    /* TIM9 counter enable */
    TIM_Cmd(TIM9,ENABLE);							   //ʹ�ܶ�ʱ��8
    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM9,ENABLE);				   //ʹ�ܶ�ʱ��8��PWM���	 Ƶ��

}  

void TIM9_Change_Period(u16 NoteSet)
{
     TIM9_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM9,&TIM9_TimeBaseStructure);
}
/*******************************���Ƹ���ͨ��������*****************************************************/
void Change_TIM9_OC1_Pulse(u16 Pulse)
{
     TIM9_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC1Init(TIM9,&TIM9_OCInitStructure);
}
void Change_TIM9_OC2_Pulse(u16 Pulse)
{
     TIM9_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC2Init(TIM9,&TIM9_OCInitStructure);
}
/*********************************��ͨ�����Կ���*****************************************************/
void Change_TIM9_OC1_Polarity(u8 i)
{
     if(i==1)TIM9_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM9_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC1Init(TIM9,&TIM9_OCInitStructure);
}
void Change_TIM9_OC2_Polarity(u8 i)
{
     if(i==1)TIM9_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM9_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC2Init(TIM9,&TIM9_OCInitStructure);
}


/*******************************************************************************
*					TIM10�ĺ���
*******************************************************************************/
void TIM10_PWM_init(u16 Prescaler,u16 Period,u8 OC1)			
{  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

#ifdef TIM10_OC1_USE_PB8
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_TIM10);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif

#ifdef TIM10_OC1_USE_PF6
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOF, GPIO_PinSource6, GPIO_AF_TIM10);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOF, &GPIO_InitStructure);
    }
#endif

    TIM_DeInit(TIM10);												 //��λ��ʱ��8���мĴ���

    /* Time Base configuration */
    TIM10_TimeBaseStructure.TIM_Prescaler = Prescaler-1;				 //Ԥ��Ƶ��Ϊ0,����Ƶ
    TIM10_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //��¦��ʽΪ˳�����ģʽ��������
    TIM10_TimeBaseStructure.TIM_Period = Period-1;					 //���ü��������������س�ֵ
    TIM10_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //����ʱ�ӷָ�ֵ
    TIM10_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //ѭ����������ֵ

    TIM_TimeBaseInit(TIM10,&TIM10_TimeBaseStructure);				     //�����ϲ�����ʼ����ʱ��ʱ�����ģ��
  
    /* Channel 1 Configuration in PWM mode */
    TIM10_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //�����ʽΪPWMģʽ1 
    TIM10_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //ʹ������Ƚ�״̬
    TIM10_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //ʹ�ܶ�ʱ���������               
    TIM10_OCInitStructure.TIM_Pulse = 100; 							 //��������
    TIM10_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //����Ƚϼ���Ϊ��
    TIM10_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //�򿪿���״̬ѡ��ر�
  
    /* ��ʼ��TM10ͨ��1*/
    if(OC1==1)TIM_OC1Init(TIM10,&TIM10_OCInitStructure); 		        
 
    /* TIM10 counter enable */
    TIM_Cmd(TIM10,ENABLE);							   //ʹ�ܶ�ʱ��8
    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM10,ENABLE);				   //ʹ�ܶ�ʱ��8��PWM���	 Ƶ��

}  

void TIM10_Change_Period(u16 NoteSet)
{
     TIM10_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM10,&TIM10_TimeBaseStructure);
}
/*******************************���Ƹ���ͨ��������*****************************************************/
void Change_TIM10_OC1_Pulse(u16 Pulse)
{
     TIM10_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC1Init(TIM10,&TIM10_OCInitStructure);
}
/*********************************��ͨ�����Կ���*****************************************************/
void Change_TIM10_OC1_Polarity(u8 i)
{
     if(i==1)TIM10_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM10_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC1Init(TIM10,&TIM10_OCInitStructure);
}



/*******************************************************************************
*					TIM11�ĺ���
*******************************************************************************/
void TIM11_PWM_init(u16 Prescaler,u16 Period,u8 OC1)						
{  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM11, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

#ifdef TIM11_OC1_USE_PB9
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_TIM11);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif

#ifdef TIM11_OC1_USE_PF7
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOF, GPIO_PinSource7, GPIO_AF_TIM11);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOF, &GPIO_InitStructure);
    }
#endif

    TIM_DeInit(TIM11);												 //��λ��ʱ��8���мĴ���

    /* Time Base configuration */
    TIM11_TimeBaseStructure.TIM_Prescaler = Prescaler-1;				 //Ԥ��Ƶ��Ϊ0,����Ƶ
    TIM11_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //��¦��ʽΪ˳�����ģʽ��������
    TIM11_TimeBaseStructure.TIM_Period = Period-1;					 //���ü��������������س�ֵ
    TIM11_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //����ʱ�ӷָ�ֵ
    TIM11_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //ѭ����������ֵ

    TIM_TimeBaseInit(TIM11,&TIM11_TimeBaseStructure);				     //�����ϲ�����ʼ����ʱ��ʱ�����ģ��
  
    /* Channel 1 Configuration in PWM mode */
    TIM11_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //�����ʽΪPWMģʽ1 
    TIM11_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //ʹ������Ƚ�״̬
    TIM11_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //ʹ�ܶ�ʱ���������               
    TIM11_OCInitStructure.TIM_Pulse = 100; 							 //��������
    TIM11_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //����Ƚϼ���Ϊ��
    TIM11_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //�򿪿���״̬ѡ��ر�
  
    /* ��ʼ��TM11ͨ��1*/
    if(OC1==1)TIM_OC1Init(TIM11,&TIM11_OCInitStructure); 		     
 
    /* TIM11 counter enable */
    TIM_Cmd(TIM11,ENABLE);							   //ʹ�ܶ�ʱ��8
    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM11,ENABLE);				   //ʹ�ܶ�ʱ��8��PWM���	 Ƶ��

}  

void TIM11_Change_Period(u16 NoteSet)
{
     TIM11_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM11,&TIM11_TimeBaseStructure);
}
/*******************************���Ƹ���ͨ��������*****************************************************/
void Change_TIM11_OC1_Pulse(u16 Pulse)
{
     TIM11_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC1Init(TIM11,&TIM11_OCInitStructure);
}
/*********************************��ͨ�����Կ���*****************************************************/
void Change_TIM11_OC1_Polarity(u8 i)
{
     if(i==1)TIM11_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM11_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC1Init(TIM11,&TIM11_OCInitStructure);
}
/*******************************************************************************
*					TIM12�ĺ���
*******************************************************************************/
void TIM12_PWM_init(u16 Prescaler,u16 Period,u8 OC1,u8 OC2)			
{  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM12, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH, ENABLE);

#ifdef TIM12_OC1_USE_PB14
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOB, GPIO_PinSource14, GPIO_AF_TIM12);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
#ifdef TIM12_OC1_USE_PH6
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOH, GPIO_PinSource6, GPIO_AF_TIM12);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOH, &GPIO_InitStructure);
    }
#endif
#ifdef TIM12_OC2_USE_PB15
    if(OC2==1)
    {
		GPIO_PinAFConfig(GPIOB, GPIO_PinSource15, GPIO_AF_TIM12);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
#ifdef TIM12_OC2_USE_PH9
    if(OC2==1)
    {
		GPIO_PinAFConfig(GPIOH, GPIO_PinSource9, GPIO_AF_TIM12);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOH, &GPIO_InitStructure);
    }
#endif
    TIM_DeInit(TIM12);												 //��λ��ʱ��8���мĴ���

    /* Time Base configuration */
    TIM12_TimeBaseStructure.TIM_Prescaler = Prescaler-1;				 //Ԥ��Ƶ��Ϊ0,����Ƶ
    TIM12_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //��¦��ʽΪ˳�����ģʽ��������
    TIM12_TimeBaseStructure.TIM_Period = Period-1;					 //���ü��������������س�ֵ
    TIM12_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //����ʱ�ӷָ�ֵ
    TIM12_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //ѭ����������ֵ

    TIM_TimeBaseInit(TIM12,&TIM12_TimeBaseStructure);				     //�����ϲ�����ʼ����ʱ��ʱ�����ģ��
  
    /* Channel 1 Configuration in PWM mode */
    TIM12_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //�����ʽΪPWMģʽ1 
    TIM12_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //ʹ������Ƚ�״̬
    TIM12_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //ʹ�ܶ�ʱ���������               
    TIM12_OCInitStructure.TIM_Pulse = 100; 							 //��������
    TIM12_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //����Ƚϼ���Ϊ��
    TIM12_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //�򿪿���״̬ѡ��ر�
  
    /* ��ʼ��TM12ͨ��1*/
    if(OC1==1)TIM_OC1Init(TIM12,&TIM12_OCInitStructure); 		        
 
    /* TIM12 counter enable */
    TIM_Cmd(TIM12,ENABLE);							   //ʹ�ܶ�ʱ��8
    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM12,ENABLE);				   //ʹ�ܶ�ʱ��8��PWM���	 Ƶ��

}  

void TIM12_Change_Period(u16 NoteSet)
{
     TIM12_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM12,&TIM12_TimeBaseStructure);
}
/*******************************���Ƹ���ͨ��������*****************************************************/
void Change_TIM12_OC1_Pulse(u16 Pulse)
{
     TIM12_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC1Init(TIM12,&TIM12_OCInitStructure);
}
void Change_TIM12_OC2_Pulse(u16 Pulse)
{
     TIM12_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC2Init(TIM12,&TIM12_OCInitStructure);
}
/*********************************��ͨ�����Կ���*****************************************************/
void Change_TIM12_OC1_Polarity(u8 i)
{
     if(i==1)TIM12_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM12_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC1Init(TIM12,&TIM12_OCInitStructure);
}
void Change_TIM12_OC2_Polarity(u8 i)
{
     if(i==1)TIM12_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM12_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC2Init(TIM12,&TIM12_OCInitStructure);
}
/*******************************************************************************
*					TIM13�ĺ���
*******************************************************************************/
void TIM13_PWM_init(u16 Prescaler,u16 Period,u8 OC1)			
{  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM13, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

#ifdef TIM13_OC1_USE_PA6
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_TIM13);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM13_OC1_USE_PF8
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOF, GPIO_PinSource8, GPIO_AF_TIM13);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOF, &GPIO_InitStructure);
    }
#endif
    TIM_DeInit(TIM13);												 //��λ��ʱ��8���мĴ���

    /* Time Base configuration */
    TIM13_TimeBaseStructure.TIM_Prescaler = Prescaler-1;				 //Ԥ��Ƶ��Ϊ0,����Ƶ
    TIM13_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //��¦��ʽΪ˳�����ģʽ��������
    TIM13_TimeBaseStructure.TIM_Period = Period-1;					 //���ü��������������س�ֵ
    TIM13_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //����ʱ�ӷָ�ֵ
    TIM13_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //ѭ����������ֵ

    TIM_TimeBaseInit(TIM13,&TIM13_TimeBaseStructure);				     //�����ϲ�����ʼ����ʱ��ʱ�����ģ��
  
    /* Channel 1 Configuration in PWM mode */
    TIM13_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //�����ʽΪPWMģʽ1 
    TIM13_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //ʹ������Ƚ�״̬
    TIM13_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //ʹ�ܶ�ʱ���������               
    TIM13_OCInitStructure.TIM_Pulse = 100; 							 //��������
    TIM13_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //����Ƚϼ���Ϊ��
    TIM13_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //�򿪿���״̬ѡ��ر�
  
    /* ��ʼ��TM13ͨ��1*/
    if(OC1==1)TIM_OC1Init(TIM13,&TIM13_OCInitStructure); 		        
 
    /* TIM13 counter enable */
    TIM_Cmd(TIM13,ENABLE);							   //ʹ�ܶ�ʱ��13
    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM13,ENABLE);				   //ʹ�ܶ�ʱ��13��PWM���	 Ƶ��

}  

void TIM13_Change_Period(u16 NoteSet)
{
     TIM13_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM13,&TIM13_TimeBaseStructure);
}
/*******************************���Ƹ���ͨ��������*****************************************************/
void Change_TIM13_OC1_Pulse(u16 Pulse)
{
     TIM13_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC1Init(TIM13,&TIM13_OCInitStructure);
}
/*********************************��ͨ�����Կ���*****************************************************/
void Change_TIM13_OC1_Polarity(u8 i)
{
     if(i==1)TIM13_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM13_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC1Init(TIM13,&TIM13_OCInitStructure);
}
/*******************************************************************************
*					TIM14�ĺ���
*******************************************************************************/
void TIM14_PWM_init(u16 Prescaler,u16 Period,u8 OC1)			
{  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

#ifdef TIM14_OC1_USE_PA7
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_TIM14);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM14_OC1_USE_PF9
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOF, GPIO_PinSource9, GPIO_AF_TIM14);					     // ����IO��������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // ģʽΪ����ģʽ  ���溯��ģʽ
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // �����������Ϊ �������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // ѡ��IO����ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // ��������������ϸ��Ϊ ����
		GPIO_Init(GPIOF, &GPIO_InitStructure);
    }
#endif
    TIM_DeInit(TIM14);												 //��λ��ʱ��8���мĴ���

    /* Time Base configuration */
    TIM14_TimeBaseStructure.TIM_Prescaler = Prescaler-1;				 //Ԥ��Ƶ��Ϊ0,����Ƶ
    TIM14_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //��¦��ʽΪ˳�����ģʽ��������
    TIM14_TimeBaseStructure.TIM_Period = Period-1;					 //���ü��������������س�ֵ
    TIM14_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //����ʱ�ӷָ�ֵ
    TIM14_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //ѭ����������ֵ

    TIM_TimeBaseInit(TIM14,&TIM14_TimeBaseStructure);				     //�����ϲ�����ʼ����ʱ��ʱ�����ģ��
  
    /* Channel 1 Configuration in PWM mode */
    TIM14_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //�����ʽΪPWMģʽ1 
    TIM14_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //ʹ������Ƚ�״̬
    TIM14_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //ʹ�ܶ�ʱ���������               
    TIM14_OCInitStructure.TIM_Pulse = 100; 							 //��������
    TIM14_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //����Ƚϼ���Ϊ��
    TIM14_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //�򿪿���״̬ѡ��ر�
  
    /* ��ʼ��TM14ͨ��1*/
    if(OC1==1)TIM_OC1Init(TIM14,&TIM14_OCInitStructure); 		        
 
    /* TIM14 counter enable */
    TIM_Cmd(TIM14,ENABLE);							   //ʹ�ܶ�ʱ��13
    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM14,ENABLE);				   //ʹ�ܶ�ʱ��13��PWM���	 Ƶ��

}  

void TIM14_Change_Period(u16 NoteSet)
{
     TIM14_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM14,&TIM14_TimeBaseStructure);
}
/*******************************���Ƹ���ͨ��������*****************************************************/
void Change_TIM14_OC1_Pulse(u16 Pulse)
{
     TIM14_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC1Init(TIM14,&TIM14_OCInitStructure);
}
/*********************************��ͨ�����Կ���*****************************************************/
void Change_TIM14_OC1_Polarity(u8 i)
{
     if(i==1)TIM14_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM14_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC1Init(TIM14,&TIM14_OCInitStructure);
}
