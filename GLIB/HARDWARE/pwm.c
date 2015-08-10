#include "PWM.h"




static GPIO_InitTypeDef GPIO_InitStructure;


static TIM_TimeBaseInitTypeDef  TIM1_TimeBaseStructure,TIM2_TimeBaseStructure,TIM3_TimeBaseStructure,TIM4_TimeBaseStructure,TIM5_TimeBaseStructure,TIM8_TimeBaseStructure,TIM9_TimeBaseStructure,TIM10_TimeBaseStructure,TIM11_TimeBaseStructure,TIM12_TimeBaseStructure,TIM13_TimeBaseStructure,TIM14_TimeBaseStructure;
static TIM_OCInitTypeDef  TIM1_OCInitStructure,TIM2_OCInitStructure,TIM3_OCInitStructure,TIM4_OCInitStructure,TIM5_OCInitStructure,TIM8_OCInitStructure,TIM9_OCInitStructure,TIM10_OCInitStructure,TIM11_OCInitStructure,TIM12_OCInitStructure,TIM13_OCInitStructure,TIM14_OCInitStructure;
//static TIM_BDTRInitTypeDef TIM8_BDTRInitStructure;


/*******************************************************************************
*					TIM1的函数
*******************************************************************************/
void TIM1_PWM_init(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2 ,u8 OC3 ,u8 OC4)							
{  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

#ifdef TIM1_OC1_USE_PA8
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_TIM1);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM1_OC2_USE_PA9
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_TIM1);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM1_OC3_USE_PA10
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_TIM1);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM1_OC4_USE_PA11
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOA, GPIO_PinSource11, GPIO_AF_TIM1);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif

#ifdef TIM1_OC1_USE_PE9
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOE, GPIO_PinSource9, GPIO_AF_TIM1);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOE, &GPIO_InitStructure);
    }
#endif
#ifdef TIM1_OC2_USE_PE11
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOE, GPIO_PinSource11, GPIO_AF_TIM1);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOE, &GPIO_InitStructure);
    }
#endif
#ifdef TIM1_OC3_USE_PE13
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOE, GPIO_PinSource13, GPIO_AF_TIM1);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOE, &GPIO_InitStructure);
    }
#endif
#ifdef TIM1_OC4_USE_PE14
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOE, GPIO_PinSource14, GPIO_AF_TIM1);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOE, &GPIO_InitStructure);
    }
#endif
    TIM_DeInit(TIM1);												 //复位定时器8所有寄存器

    /* Time Base configuration */
    TIM1_TimeBaseStructure.TIM_Prescaler = Prescaler-1;						 //预分频数为0,不分频
    TIM1_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //计娄方式为顺序计数模式，增大型
    TIM1_TimeBaseStructure.TIM_Period = Period-1;					     //设置计数器溢出后的重载初值
    TIM1_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //配置时钟分隔值
    TIM1_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //循环计数次数值

    TIM_TimeBaseInit(TIM1,&TIM1_TimeBaseStructure);				     //用以上参数初始化定时器时间基础模块
  
    /* Channel 1 Configuration in PWM mode */
    TIM1_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //输出方式为PWM模式1
 
    TIM1_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //使能输出比较状态
    TIM1_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //使能定时器互补输出               
    TIM1_OCInitStructure.TIM_Pulse = 5000; 							 //设置脉宽
    TIM1_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //输出比较极性为高
    TIM1_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //打开空闲状态选择关闭
  
    /* 初始化TM1通道1*/
    if(OC1==1)TIM_OC1Init(TIM1,&TIM1_OCInitStructure); 		         //用以上参数初始化TIM8的通道1
	if(OC2==1)TIM_OC2Init(TIM1,&TIM1_OCInitStructure); 		         //用以上参数初始化TIM8的通道2
	if(OC3==1)TIM_OC3Init(TIM1,&TIM1_OCInitStructure); 		         //用以上参数初始化TIM8的通道3
	if(OC4==1)TIM_OC4Init(TIM1,&TIM1_OCInitStructure); 		         //用以上参数初始化TIM8的通道4
 
    /* TIM1 counter enable */
    TIM_Cmd(TIM1,ENABLE);							   //使能定时器8

    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM1,ENABLE);				   //使能定时器8的PWM输出	 频率

}  

void TIM1_Change_Period(u16 NoteSet)
{
     TIM1_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM1,&TIM1_TimeBaseStructure);
}
/*******************************控制各个通道的脉宽*****************************************************/
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
/*********************************各通道极性控制*****************************************************/
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
*					TIM2的函数
*******************************************************************************/
void TIM2_PWM_init(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2 ,u8 OC3 ,u8 OC4)							  
{  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
#ifdef TIM2_OC1_USE_PA0
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_TIM2);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM2_OC1_USE_PA5
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_TIM2);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM2_OC2_USE_PA1
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_TIM2);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM2_OC3_USE_PA2
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_TIM2);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM2_OC4_USE_PA3
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_TIM2);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM2_OC1_USE_PA15
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource15, GPIO_AF_TIM2);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM2_OC2_USE_PB3
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOB, GPIO_PinSource3, GPIO_AF_TIM2);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
#ifdef TIM2_OC3_USE_PB10
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_TIM2);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
#ifdef TIM2_OC4_USE_PB11
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_TIM2);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
    TIM_DeInit(TIM2);												 //复位定时器8所有寄存器

    /* Time Base configuration */
    TIM2_TimeBaseStructure.TIM_Prescaler = Prescaler-1;				 //预分频数为0,不分频
    TIM2_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //计娄方式为顺序计数模式，增大型
    TIM2_TimeBaseStructure.TIM_Period = Period-1;					     //设置计数器溢出后的重载初值
    TIM2_TimeBaseStructure.TIM_ClockDivision =  TIM_CKD_DIV1;		 //配置时钟分隔值
    TIM2_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //循环计数次数值

    TIM_TimeBaseInit(TIM2,&TIM2_TimeBaseStructure);				     //用以上参数初始化定时器时间基础模块
  
    TIM2_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //输出方式为PWM模式1
    TIM2_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //使能输出比较状态
    TIM2_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //使能定时器互补输出               
    TIM2_OCInitStructure.TIM_Pulse = 100; 							 //设置脉宽
    TIM2_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //输出比较极性为高
    TIM2_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //打开空闲状态选择关闭
  
    if(OC1==1)TIM_OC1Init(TIM2,&TIM2_OCInitStructure); 		         //用以上参数初始化TIM2的通道1
	if(OC2==1)TIM_OC2Init(TIM2,&TIM2_OCInitStructure); 		         //用以上参数初始化TIM2的通道2
	if(OC3==1)TIM_OC3Init(TIM2,&TIM2_OCInitStructure); 		         //用以上参数初始化TIM2的通道3
	if(OC4==1)TIM_OC4Init(TIM2,&TIM2_OCInitStructure); 		         //用以上参数初始化TIM2的通道4
 
    /* TIM2 counter enable */
    TIM_Cmd(TIM2,ENABLE);							   //使能定时器2

    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM2,ENABLE);				   //使能定时器2的PWM输出	 频率

}  

void TIM2_Change_Period(u16 NoteSet)
{
     TIM2_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM2,&TIM2_TimeBaseStructure);
}
/*******************************控制各个通道的脉宽*****************************************************/
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
/*********************************各通道极性控制*****************************************************/
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
*					TIM3的函数
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
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_TIM3);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM3_OC1_USE_PB4
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_TIM3);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
#ifdef TIM3_OC2_USE_PA7
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_TIM3);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM3_OC2_USE_PB5
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_TIM3);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
#ifdef TIM3_OC3_USE_PB0
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOB, GPIO_PinSource0, GPIO_AF_TIM3);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
#ifdef TIM3_OC4_USE_PB1
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOB, GPIO_PinSource1, GPIO_AF_TIM3);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif

#ifdef TIM3_OC1_USE_PC6
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_TIM3);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOC, &GPIO_InitStructure);
    }
#endif
#ifdef TIM3_OC2_USE_PC7
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_TIM3);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOC, &GPIO_InitStructure);
    }
#endif
#ifdef TIM3_OC3_USE_PC8
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_TIM3);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOC, &GPIO_InitStructure);
    }
#endif
#ifdef TIM3_OC4_USE_PC9
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOC, GPIO_PinSource9, GPIO_AF_TIM3);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOC, &GPIO_InitStructure);
    }
#endif


    TIM_DeInit(TIM3);												 //复位定时器8所有寄存器

    /* Time Base configuration */
    TIM3_TimeBaseStructure.TIM_Prescaler = Prescaler-1;				 //预分频数为0,不分频
    TIM3_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //计娄方式为顺序计数模式，增大型
    TIM3_TimeBaseStructure.TIM_Period =Period-1;					 //设置计数器溢出后的重载初值
    TIM3_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //配置时钟分隔值
    TIM3_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //循环计数次数值
    TIM_TimeBaseInit(TIM3,&TIM3_TimeBaseStructure);				     //用以上参数初始化定时器时间基础模块
  
    /* Channel 1 Configuration in PWM mode */
    TIM3_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //输出方式为PWM模式1 
    TIM3_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //使能输出比较状态
    TIM3_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //使能定时器互补输出               
    TIM3_OCInitStructure.TIM_Pulse = 100; 							 //设置脉宽
    TIM3_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //输出比较极性为高
    TIM3_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //打开空闲状态选择关闭
  
    /* 初始化TM3通道1*/
    if(OC1==1)TIM_OC1Init(TIM3,&TIM3_OCInitStructure); 		         //用以上参数初始化TIM3的通道1
	if(OC2==1)TIM_OC2Init(TIM3,&TIM3_OCInitStructure); 		         //用以上参数初始化TIM3的通道2
	if(OC3==1)TIM_OC3Init(TIM3,&TIM3_OCInitStructure); 		         //用以上参数初始化TIM3的通道3
	if(OC4==1)TIM_OC4Init(TIM3,&TIM3_OCInitStructure); 		         //用以上参数初始化TIM3的通道4
 
    /* TIM3 counter enable */
    TIM_Cmd(TIM3,ENABLE);							   //使能定时器8

    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM3,ENABLE);				   //使能定时器8的PWM输出	 频率

}  

void TIM3_Change_Period(u16 NoteSet)
{
     TIM3_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM3,&TIM3_TimeBaseStructure);
}
/*******************************控制各个通道的脉宽*****************************************************/
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
/*********************************各通道极性控制*****************************************************/
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
*					TIM4的函数
*******************************************************************************/
void TIM4_PWM_init(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2 ,u8 OC3 ,u8 OC4)							 
{  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

#ifdef TIM4_OC1_USE_PB6
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_TIM4);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
#ifdef TIM4_OC2_USE_PB7
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_TIM4);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
#ifdef TIM4_OC3_USE_PB8
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_TIM4);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
#ifdef TIM4_OC4_USE_PB9
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_TIM4);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
#ifdef TIM4_OC1_USE_PD12
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOD, &GPIO_InitStructure);
    }
#endif
#ifdef TIM4_OC2_USE_PD13
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOD, &GPIO_InitStructure);
    }
#endif
#ifdef TIM4_OC3_USE_PD14
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_TIM4);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOD, &GPIO_InitStructure);
    }
#endif
#ifdef TIM4_OC4_USE_PD15
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_TIM4);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOD, &GPIO_InitStructure);
    }
#endif

    TIM_DeInit(TIM4);												 //复位定时器8所有寄存器

    /* Time Base configuration */
    TIM4_TimeBaseStructure.TIM_Prescaler =Prescaler-1;						 //预分频数为0,不分频
    TIM4_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //计娄方式为顺序计数模式，增大型
    TIM4_TimeBaseStructure.TIM_Period = Period-1;					     //设置计数器溢出后的重载初值
    TIM4_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //配置时钟分隔值
    TIM4_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //循环计数次数值

    TIM_TimeBaseInit(TIM4,&TIM4_TimeBaseStructure);				     //用以上参数初始化定时器时间基础模块
  
    /* Channel 1 Configuration in PWM mode */
    TIM4_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //输出方式为PWM模式1
 
    TIM4_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //使能输出比较状态
    TIM4_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //使能定时器互补输出               
    TIM4_OCInitStructure.TIM_Pulse = 100; 							 //设置脉宽
    TIM4_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //输出比较极性为高
    TIM4_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //打开空闲状态选择关闭
  
    /* 初始化TM4通道1*/
    if(OC1==1)TIM_OC1Init(TIM4,&TIM4_OCInitStructure); 		         //用以上参数初始化TIM3的通道1
	if(OC2==1)TIM_OC2Init(TIM4,&TIM4_OCInitStructure); 		         //用以上参数初始化TIM3的通道2
	if(OC3==1)TIM_OC3Init(TIM4,&TIM4_OCInitStructure); 		         //用以上参数初始化TIM3的通道3
	if(OC4==1)TIM_OC4Init(TIM4,&TIM4_OCInitStructure); 		         //用以上参数初始化TIM3的通道4
 
    /* TIM4 counter enable */
    TIM_Cmd(TIM4,ENABLE);							   //使能定时器8

    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM4,ENABLE);				   //使能定时器8的PWM输出	 频率

}  

void TIM4_Change_Period(u16 NoteSet)
{
     TIM4_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM4,&TIM4_TimeBaseStructure);
}
/*******************************控制各个通道的脉宽*****************************************************/
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
/*********************************各通道极性控制*****************************************************/
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
*					TIM5的函数
*******************************************************************************/
void TIM5_PWM_init(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2 ,u8 OC3 ,u8 OC4)							  
{  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH | RCC_AHB1Periph_GPIOI, ENABLE);

#ifdef TIM5_OC1_USE_PA0
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_TIM5);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM5_OC2_USE_PA1
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_TIM5);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM5_OC3_USE_PA2
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_TIM5);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM5_OC4_USE_PA3
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_TIM5);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM5_OC1_USE_PH10
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOH, GPIO_PinSource10, GPIO_AF_TIM5);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOH, &GPIO_InitStructure);
    }
#endif
#ifdef TIM5_OC2_USE_PH11
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOH, GPIO_PinSource11, GPIO_AF_TIM5);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOH, &GPIO_InitStructure);
    }
#endif
#ifdef TIM5_OC3_USE_PH12
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOH, GPIO_PinSource12, GPIO_AF_TIM5);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOH, &GPIO_InitStructure);
    }
#endif
#ifdef TIM5_OC4_USE_PI13
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOI, GPIO_PinSource13, GPIO_AF_TIM5);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOI, &GPIO_InitStructure);
    }
#endif


    TIM_DeInit(TIM5);												 //复位定时器8所有寄存器

    /* Time Base configuration */
    TIM5_TimeBaseStructure.TIM_Prescaler = Prescaler-1;						 //预分频数为0,不分频
    TIM5_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //计娄方式为顺序计数模式，增大型
    TIM5_TimeBaseStructure.TIM_Period = Period-1;					     //设置计数器溢出后的重载初值
    TIM5_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //配置时钟分隔值
    TIM5_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //循环计数次数值

    TIM_TimeBaseInit(TIM5,&TIM5_TimeBaseStructure);				     //用以上参数初始化定时器时间基础模块
  
    /* Channel 1 Configuration in PWM mode */
    TIM5_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //输出方式为PWM模式1
 
    TIM5_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //使能输出比较状态
    TIM5_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //使能定时器互补输出               
    TIM5_OCInitStructure.TIM_Pulse = 100; 							 //设置脉宽
    TIM5_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //输出比较极性为高
    TIM5_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //打开空闲状态选择关闭
  
    /* 初始化TM5通道1*/
    if(OC1==1)TIM_OC1Init(TIM5,&TIM5_OCInitStructure); 		         //用以上参数初始化TIM3的通道1
	if(OC2==1)TIM_OC2Init(TIM5,&TIM5_OCInitStructure); 		         //用以上参数初始化TIM3的通道2
	if(OC3==1)TIM_OC3Init(TIM5,&TIM5_OCInitStructure); 		         //用以上参数初始化TIM3的通道3
	if(OC4==1)TIM_OC4Init(TIM5,&TIM5_OCInitStructure); 		         //用以上参数初始化TIM3的通道4
 
    /* TIM5 counter enable */
    TIM_Cmd(TIM5,ENABLE);							   //使能定时器8

    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM5,ENABLE);				   //使能定时器8的PWM输出	 频率

}  

void TIM5_Change_Period(u16 NoteSet)
{
     TIM5_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM5,&TIM5_TimeBaseStructure);
}
/*******************************控制各个通道的脉宽*****************************************************/
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
/*********************************各通道极性控制*****************************************************/
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
*					TIM8的函数
*******************************************************************************/
void TIM8_PWM_init(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2 ,u8 OC3 ,u8 OC4)							  
{  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOI, ENABLE);

#ifdef TIM8_OC1_USE_PC6
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_TIM8);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOC, &GPIO_InitStructure);
    }
#endif
#ifdef TIM8_OC2_USE_PC7
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_TIM8);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOC, &GPIO_InitStructure);
    }
#endif
#ifdef TIM8_OC3_USE_PC8
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_TIM8);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOC, &GPIO_InitStructure);
    }
#endif
#ifdef TIM8_OC4_USE_PC9
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOC, GPIO_PinSource9, GPIO_AF_TIM8);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOC, &GPIO_InitStructure);
    }
#endif

#ifdef TIM8_OC1_USE_PI5
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOI, GPIO_PinSource5, GPIO_AF_TIM8);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOI, &GPIO_InitStructure);
    }
#endif
#ifdef TIM8_OC2_USE_PI6
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOI, GPIO_PinSource6, GPIO_AF_TIM8);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOI, &GPIO_InitStructure);
    }
#endif
#ifdef TIM8_OC3_USE_PI7
	if(OC3==1)
    {
	    GPIO_PinAFConfig(GPIOI, GPIO_PinSource7, GPIO_AF_TIM8);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOI, &GPIO_InitStructure);
    }
#endif
#ifdef TIM8_OC4_USE_PI2
	if(OC4==1)
    {
	    GPIO_PinAFConfig(GPIOI, GPIO_PinSource2, GPIO_AF_TIM8);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOI, &GPIO_InitStructure);
    }
#endif

    TIM_DeInit(TIM8);												 //复位定时器8所有寄存器

    /* Time Base configuration */
    TIM8_TimeBaseStructure.TIM_Prescaler = Prescaler-1;				 //预分频数为0,不分频
    TIM8_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //计娄方式为顺序计数模式，增大型
    TIM8_TimeBaseStructure.TIM_Period = Period-1;					 //设置计数器溢出后的重载初值
    TIM8_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //配置时钟分隔值
    TIM8_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //循环计数次数值

    TIM_TimeBaseInit(TIM8,&TIM8_TimeBaseStructure);				     //用以上参数初始化定时器时间基础模块
  
    /* Channel 1 Configuration in PWM mode */
    TIM8_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //输出方式为PWM模式1 
    TIM8_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //使能输出比较状态
    TIM8_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //使能定时器互补输出               
    TIM8_OCInitStructure.TIM_Pulse = 100; 							 //设置脉宽
    TIM8_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //输出比较极性为高
    TIM8_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //打开空闲状态选择关闭
  
    /* 初始化TM8通道1*/
    if(OC1==1)TIM_OC1Init(TIM8,&TIM8_OCInitStructure); 		         //用以上参数初始化TIM8的通道1
	if(OC2==1)TIM_OC2Init(TIM8,&TIM8_OCInitStructure); 		         //用以上参数初始化TIM8的通道2
	if(OC3==1)TIM_OC3Init(TIM8,&TIM8_OCInitStructure); 		         //用以上参数初始化TIM8的通道3
	if(OC4==1)TIM_OC4Init(TIM8,&TIM8_OCInitStructure); 		         //用以上参数初始化TIM8的通道4
 
    /* TIM8 counter enable */
    TIM_Cmd(TIM8,ENABLE);							   //使能定时器8
    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM8,ENABLE);				   //使能定时器8的PWM输出	 频率

}  

void TIM8_Change_Period(u16 NoteSet)
{
     TIM8_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM8,&TIM8_TimeBaseStructure);
}
/*******************************控制各个通道的脉宽*****************************************************/
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
/*********************************各通道极性控制*****************************************************/
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
*					TIM9的函数
*******************************************************************************/
void TIM9_PWM_init(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2)		
{  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

#ifdef TIM9_OC1_USE_PA2
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_TIM9);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM9_OC2_USE_PA3
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_TIM9);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif

#ifdef TIM9_OC1_USE_PE5
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOE, GPIO_PinSource5, GPIO_AF_TIM9);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOE, &GPIO_InitStructure);
    }
#endif
#ifdef TIM9_OC2_USE_PE6
	if(OC2==1)
    {
	    GPIO_PinAFConfig(GPIOE, GPIO_PinSource6, GPIO_AF_TIM9);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOE, &GPIO_InitStructure);
    }
#endif

    TIM_DeInit(TIM9);												 //复位定时器8所有寄存器

    /* Time Base configuration */
    TIM9_TimeBaseStructure.TIM_Prescaler = Prescaler-1;				 //预分频数为0,不分频
    TIM9_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //计娄方式为顺序计数模式，增大型
    TIM9_TimeBaseStructure.TIM_Period = Period-1;					 //设置计数器溢出后的重载初值
    TIM9_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //配置时钟分隔值
    TIM9_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //循环计数次数值

    TIM_TimeBaseInit(TIM9,&TIM9_TimeBaseStructure);				     //用以上参数初始化定时器时间基础模块
  
    /* Channel 1 Configuration in PWM mode */
    TIM9_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //输出方式为PWM模式1 
    TIM9_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //使能输出比较状态
    TIM9_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //使能定时器互补输出               
    TIM9_OCInitStructure.TIM_Pulse = 100; 							 //设置脉宽
    TIM9_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //输出比较极性为高
    TIM9_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //打开空闲状态选择关闭
  
    /* 初始化TM9通道1*/
    if(OC1==1)TIM_OC1Init(TIM9,&TIM9_OCInitStructure); 		         //用以上参数初始化TIM8的通道1
	if(OC2==1)TIM_OC2Init(TIM9,&TIM9_OCInitStructure); 		         //用以上参数初始化TIM8的通道2
 
    /* TIM9 counter enable */
    TIM_Cmd(TIM9,ENABLE);							   //使能定时器8
    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM9,ENABLE);				   //使能定时器8的PWM输出	 频率

}  

void TIM9_Change_Period(u16 NoteSet)
{
     TIM9_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM9,&TIM9_TimeBaseStructure);
}
/*******************************控制各个通道的脉宽*****************************************************/
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
/*********************************各通道极性控制*****************************************************/
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
*					TIM10的函数
*******************************************************************************/
void TIM10_PWM_init(u16 Prescaler,u16 Period,u8 OC1)			
{  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

#ifdef TIM10_OC1_USE_PB8
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_TIM10);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif

#ifdef TIM10_OC1_USE_PF6
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOF, GPIO_PinSource6, GPIO_AF_TIM10);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOF, &GPIO_InitStructure);
    }
#endif

    TIM_DeInit(TIM10);												 //复位定时器8所有寄存器

    /* Time Base configuration */
    TIM10_TimeBaseStructure.TIM_Prescaler = Prescaler-1;				 //预分频数为0,不分频
    TIM10_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //计娄方式为顺序计数模式，增大型
    TIM10_TimeBaseStructure.TIM_Period = Period-1;					 //设置计数器溢出后的重载初值
    TIM10_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //配置时钟分隔值
    TIM10_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //循环计数次数值

    TIM_TimeBaseInit(TIM10,&TIM10_TimeBaseStructure);				     //用以上参数初始化定时器时间基础模块
  
    /* Channel 1 Configuration in PWM mode */
    TIM10_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //输出方式为PWM模式1 
    TIM10_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //使能输出比较状态
    TIM10_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //使能定时器互补输出               
    TIM10_OCInitStructure.TIM_Pulse = 100; 							 //设置脉宽
    TIM10_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //输出比较极性为高
    TIM10_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //打开空闲状态选择关闭
  
    /* 初始化TM10通道1*/
    if(OC1==1)TIM_OC1Init(TIM10,&TIM10_OCInitStructure); 		        
 
    /* TIM10 counter enable */
    TIM_Cmd(TIM10,ENABLE);							   //使能定时器8
    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM10,ENABLE);				   //使能定时器8的PWM输出	 频率

}  

void TIM10_Change_Period(u16 NoteSet)
{
     TIM10_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM10,&TIM10_TimeBaseStructure);
}
/*******************************控制各个通道的脉宽*****************************************************/
void Change_TIM10_OC1_Pulse(u16 Pulse)
{
     TIM10_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC1Init(TIM10,&TIM10_OCInitStructure);
}
/*********************************各通道极性控制*****************************************************/
void Change_TIM10_OC1_Polarity(u8 i)
{
     if(i==1)TIM10_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM10_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC1Init(TIM10,&TIM10_OCInitStructure);
}



/*******************************************************************************
*					TIM11的函数
*******************************************************************************/
void TIM11_PWM_init(u16 Prescaler,u16 Period,u8 OC1)						
{  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM11, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

#ifdef TIM11_OC1_USE_PB9
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_TIM11);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif

#ifdef TIM11_OC1_USE_PF7
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOF, GPIO_PinSource7, GPIO_AF_TIM11);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOF, &GPIO_InitStructure);
    }
#endif

    TIM_DeInit(TIM11);												 //复位定时器8所有寄存器

    /* Time Base configuration */
    TIM11_TimeBaseStructure.TIM_Prescaler = Prescaler-1;				 //预分频数为0,不分频
    TIM11_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //计娄方式为顺序计数模式，增大型
    TIM11_TimeBaseStructure.TIM_Period = Period-1;					 //设置计数器溢出后的重载初值
    TIM11_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //配置时钟分隔值
    TIM11_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //循环计数次数值

    TIM_TimeBaseInit(TIM11,&TIM11_TimeBaseStructure);				     //用以上参数初始化定时器时间基础模块
  
    /* Channel 1 Configuration in PWM mode */
    TIM11_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //输出方式为PWM模式1 
    TIM11_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //使能输出比较状态
    TIM11_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //使能定时器互补输出               
    TIM11_OCInitStructure.TIM_Pulse = 100; 							 //设置脉宽
    TIM11_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //输出比较极性为高
    TIM11_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //打开空闲状态选择关闭
  
    /* 初始化TM11通道1*/
    if(OC1==1)TIM_OC1Init(TIM11,&TIM11_OCInitStructure); 		     
 
    /* TIM11 counter enable */
    TIM_Cmd(TIM11,ENABLE);							   //使能定时器8
    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM11,ENABLE);				   //使能定时器8的PWM输出	 频率

}  

void TIM11_Change_Period(u16 NoteSet)
{
     TIM11_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM11,&TIM11_TimeBaseStructure);
}
/*******************************控制各个通道的脉宽*****************************************************/
void Change_TIM11_OC1_Pulse(u16 Pulse)
{
     TIM11_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC1Init(TIM11,&TIM11_OCInitStructure);
}
/*********************************各通道极性控制*****************************************************/
void Change_TIM11_OC1_Polarity(u8 i)
{
     if(i==1)TIM11_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM11_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC1Init(TIM11,&TIM11_OCInitStructure);
}
/*******************************************************************************
*					TIM12的函数
*******************************************************************************/
void TIM12_PWM_init(u16 Prescaler,u16 Period,u8 OC1,u8 OC2)			
{  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM12, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH, ENABLE);

#ifdef TIM12_OC1_USE_PB14
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOB, GPIO_PinSource14, GPIO_AF_TIM12);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
#ifdef TIM12_OC1_USE_PH6
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOH, GPIO_PinSource6, GPIO_AF_TIM12);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOH, &GPIO_InitStructure);
    }
#endif
#ifdef TIM12_OC2_USE_PB15
    if(OC2==1)
    {
		GPIO_PinAFConfig(GPIOB, GPIO_PinSource15, GPIO_AF_TIM12);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
#ifdef TIM12_OC2_USE_PH9
    if(OC2==1)
    {
		GPIO_PinAFConfig(GPIOH, GPIO_PinSource9, GPIO_AF_TIM12);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOH, &GPIO_InitStructure);
    }
#endif
    TIM_DeInit(TIM12);												 //复位定时器8所有寄存器

    /* Time Base configuration */
    TIM12_TimeBaseStructure.TIM_Prescaler = Prescaler-1;				 //预分频数为0,不分频
    TIM12_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //计娄方式为顺序计数模式，增大型
    TIM12_TimeBaseStructure.TIM_Period = Period-1;					 //设置计数器溢出后的重载初值
    TIM12_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //配置时钟分隔值
    TIM12_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //循环计数次数值

    TIM_TimeBaseInit(TIM12,&TIM12_TimeBaseStructure);				     //用以上参数初始化定时器时间基础模块
  
    /* Channel 1 Configuration in PWM mode */
    TIM12_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //输出方式为PWM模式1 
    TIM12_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //使能输出比较状态
    TIM12_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //使能定时器互补输出               
    TIM12_OCInitStructure.TIM_Pulse = 100; 							 //设置脉宽
    TIM12_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //输出比较极性为高
    TIM12_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //打开空闲状态选择关闭
  
    /* 初始化TM12通道1*/
    if(OC1==1)TIM_OC1Init(TIM12,&TIM12_OCInitStructure); 		        
 
    /* TIM12 counter enable */
    TIM_Cmd(TIM12,ENABLE);							   //使能定时器8
    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM12,ENABLE);				   //使能定时器8的PWM输出	 频率

}  

void TIM12_Change_Period(u16 NoteSet)
{
     TIM12_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM12,&TIM12_TimeBaseStructure);
}
/*******************************控制各个通道的脉宽*****************************************************/
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
/*********************************各通道极性控制*****************************************************/
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
*					TIM13的函数
*******************************************************************************/
void TIM13_PWM_init(u16 Prescaler,u16 Period,u8 OC1)			
{  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM13, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

#ifdef TIM13_OC1_USE_PA6
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_TIM13);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM13_OC1_USE_PF8
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOF, GPIO_PinSource8, GPIO_AF_TIM13);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOF, &GPIO_InitStructure);
    }
#endif
    TIM_DeInit(TIM13);												 //复位定时器8所有寄存器

    /* Time Base configuration */
    TIM13_TimeBaseStructure.TIM_Prescaler = Prescaler-1;				 //预分频数为0,不分频
    TIM13_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //计娄方式为顺序计数模式，增大型
    TIM13_TimeBaseStructure.TIM_Period = Period-1;					 //设置计数器溢出后的重载初值
    TIM13_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //配置时钟分隔值
    TIM13_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //循环计数次数值

    TIM_TimeBaseInit(TIM13,&TIM13_TimeBaseStructure);				     //用以上参数初始化定时器时间基础模块
  
    /* Channel 1 Configuration in PWM mode */
    TIM13_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //输出方式为PWM模式1 
    TIM13_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //使能输出比较状态
    TIM13_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //使能定时器互补输出               
    TIM13_OCInitStructure.TIM_Pulse = 100; 							 //设置脉宽
    TIM13_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //输出比较极性为高
    TIM13_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //打开空闲状态选择关闭
  
    /* 初始化TM13通道1*/
    if(OC1==1)TIM_OC1Init(TIM13,&TIM13_OCInitStructure); 		        
 
    /* TIM13 counter enable */
    TIM_Cmd(TIM13,ENABLE);							   //使能定时器13
    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM13,ENABLE);				   //使能定时器13的PWM输出	 频率

}  

void TIM13_Change_Period(u16 NoteSet)
{
     TIM13_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM13,&TIM13_TimeBaseStructure);
}
/*******************************控制各个通道的脉宽*****************************************************/
void Change_TIM13_OC1_Pulse(u16 Pulse)
{
     TIM13_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC1Init(TIM13,&TIM13_OCInitStructure);
}
/*********************************各通道极性控制*****************************************************/
void Change_TIM13_OC1_Polarity(u8 i)
{
     if(i==1)TIM13_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM13_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC1Init(TIM13,&TIM13_OCInitStructure);
}
/*******************************************************************************
*					TIM14的函数
*******************************************************************************/
void TIM14_PWM_init(u16 Prescaler,u16 Period,u8 OC1)			
{  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

#ifdef TIM14_OC1_USE_PA7
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_TIM14);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
#ifdef TIM14_OC1_USE_PF9
    if(OC1==1)
    {
		GPIO_PinAFConfig(GPIOF, GPIO_PinSource9, GPIO_AF_TIM14);					     // 备用IO功能配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;					      		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								  // 模式为备用模式  代替函数模式
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  // 具体输出类型为 推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							  // 选择IO最大速度为50MHz
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;								  // 具体上拉下拉的细节为 上拉
		GPIO_Init(GPIOF, &GPIO_InitStructure);
    }
#endif
    TIM_DeInit(TIM14);												 //复位定时器8所有寄存器

    /* Time Base configuration */
    TIM14_TimeBaseStructure.TIM_Prescaler = Prescaler-1;				 //预分频数为0,不分频
    TIM14_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //计娄方式为顺序计数模式，增大型
    TIM14_TimeBaseStructure.TIM_Period = Period-1;					 //设置计数器溢出后的重载初值
    TIM14_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //配置时钟分隔值
    TIM14_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //循环计数次数值

    TIM_TimeBaseInit(TIM14,&TIM14_TimeBaseStructure);				     //用以上参数初始化定时器时间基础模块
  
    /* Channel 1 Configuration in PWM mode */
    TIM14_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //输出方式为PWM模式1 
    TIM14_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //使能输出比较状态
    TIM14_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //使能定时器互补输出               
    TIM14_OCInitStructure.TIM_Pulse = 100; 							 //设置脉宽
    TIM14_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //输出比较极性为高
    TIM14_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //打开空闲状态选择关闭
  
    /* 初始化TM14通道1*/
    if(OC1==1)TIM_OC1Init(TIM14,&TIM14_OCInitStructure); 		        
 
    /* TIM14 counter enable */
    TIM_Cmd(TIM14,ENABLE);							   //使能定时器13
    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM14,ENABLE);				   //使能定时器13的PWM输出	 频率

}  

void TIM14_Change_Period(u16 NoteSet)
{
     TIM14_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM14,&TIM14_TimeBaseStructure);
}
/*******************************控制各个通道的脉宽*****************************************************/
void Change_TIM14_OC1_Pulse(u16 Pulse)
{
     TIM14_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC1Init(TIM14,&TIM14_OCInitStructure);
}
/*********************************各通道极性控制*****************************************************/
void Change_TIM14_OC1_Polarity(u8 i)
{
     if(i==1)TIM14_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM14_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC1Init(TIM14,&TIM14_OCInitStructure);
}
