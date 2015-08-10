//#include "G32_timer_cap.h"
//#include "stm32f10x_it.h"
//#include "usart.h"
///*****************************************************
//REMAP        |   00    |   01    |   10    |   11    |
//*****************************************************|
//TIM2_CH1_ETR |   PA0   |PA15(JTDI)| (PA0)  |(PA15)   |
//TIM2_CH2     |   PA1   |PB3(JTDO) | (PA1)  |(PB3 )   |
//TIM2_CH3     |        PA2        |    (PB10)(!36)    |
//TIM2_CH4     |        PA3        |    (PB11)(!36)    |
//*****************************************************|
//TIM3_CH1     |   PA6   |PB4(JNTRST)|       |(PC6)(64 100 144)|
//TIM3_CH2     |   PA7   |   PB5   |         |(PC7)    |
//TIM3_CH3     |        PB0        |         |(PC8)    |
//TIM3_CH4     |        PB1        |         |(PC9)    |
//*****************************************************|
//TIM4_CH1     |   PB6   |(PD12)(100 144)|   |         |
//TIM4_CH2     |   PB7   |(PD13)(100 144)|   |         |
//TIM4_CH3     |   PB8   |(PD14)(100 144)|   |         |
//TIM4_CH4     |   PB9   |(PD15)(100 144)|   |         |
//*****************************************************|
//TIM5_CH1     |   PA0   |                             |
//TIM5_CH2     |   PA1   |                             |
//TIM5_CH3     |   PA2   |                             |
//TIM5_CH4     |   PA3   |                             |
//*****************************************************|
//TIM8_ETR     |   PA0   |                             |
//TIM8_CH1     |   PC6   |                             |
//TIM8_CH2     |   PC7   |                             |
//TIM8_CH3     |   PC8   |                             |
//TIM8_CH4     |   PC9   |                             |
//TIM8_BKIN    |   PA6   |                             |
//TIM8_CH1N    |   PA7   |                             |
//TIM8_CH2N    |   PB0   |                             |
//TIM8_CH3N    |   PB1   |                             |
//*****************************************************|
//TIM1_ETR     |        PA12       |   PE7 (100 144)   |
//TIM1_CH1     |        PA8        |   PE9 (100 144)   |
//TIM1_CH2     |        PA9 (Tx)   |   PE11(100 144)   |
//TIM1_CH3     |        PA10(Rx)   |   PE13(100 144)   |
//TIM1_CH4     |        PA11(CANRx)|   PE14(100 144)   |
//TIM1_BKIN    |PB12(!36)|   PA6   |   PE15(100 144)   |
//TIM1_CH1N    |PB13(!36)|   PA7   |   PE8 (100 144)   |
//TIM1_CH2N    |PB14(!36)|   PB0   |   PE10(100 144)   |
//TIM1_CH3N    |PB15(!36)|   PB1   |   PE12(100 144)   |
//*****************************************************/
////例
///*************************************************************************************************/
/////*
////#include "G32_timer_cap.h"
////int main(void)
////{
////    /***变量***/
////    u32 temp = 0;
////    /***延时初始化***/
////    //Clock_Enable();
////    SystemInit();
////    delay_init();
////    NVIC_Configuration();
////    /***串口x初始化***/
////    uart_init(38400);
////    uart2_init(38400);
////    /***捕获***/
////    TIM5_Cap_Init(0XFFFF, 72 - 1);
////    while (1)
////    {
////        delay_ms(10);
////        if (TIM5CH1_CAPTURE_STA & 0X80) //成功捕获到了一次上升沿
////        {
////            temp = TIM5CH1_CAPTURE_STA & 0X3F;
////            temp *= 65536; //溢出时间总和
////            temp += TIM5CH1_CAPTURE_VAL; //得到总的高电平时间
////            USART_OUT(USART1, "HIGH高:%d us\r\n", temp); //打印总的高点平时间
////            TIM5CH1_CAPTURE_STA = 0; //开启下一次捕获
////        }
////    }
////}
////*/

////测高电平时间
///*****************************************************************************************************************************/
//void TIM5_Cap_IRQ(void);
////定时器5通道1输入捕获配置
//void TIM5_Cap_Init(u16 arr, u16 psc)
//{
//    GPIO_InitTypeDef GPIO_InitStructure;
//    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//    NVIC_InitTypeDef NVIC_InitStructure;
//    TIM_ICInitTypeDef  TIM5_ICInitStructure;

//    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);   //使能TIM5时钟
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  //使能GPIOA时钟

//    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;  //PA0 清除之前设置
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0 输入
//    GPIO_Init(GPIOA, &GPIO_InitStructure);
//    GPIO_ResetBits(GPIOA, GPIO_Pin_0);                       //PA0 下拉

//    //初始化定时器5 TIM5
//    TIM_TimeBaseStructure.TIM_Period = arr; //设定计数器自动重装值
//    TIM_TimeBaseStructure.TIM_Prescaler = psc;  //预分频器
//    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
//    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
//    TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位

//    //初始化TIM5输入捕获参数
//    TIM5_ICInitStructure.TIM_Channel = TIM_Channel_1; //CC1S=01     选择输入端 IC1映射到TI1上
//    TIM5_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;    //上升沿捕获
//    TIM5_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //映射到TI1上
//    TIM5_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;   //配置输入分频,不分频
//    TIM5_ICInitStructure.TIM_ICFilter = 0x00;//IC1F=0000 配置输入滤波器 不滤波
//    TIM_ICInit(TIM5, &TIM5_ICInitStructure);

//    //中断分组初始化
//    NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;                     //TIM3中断
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; //先占优先级2级
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;              //从优先级0级
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                     //IRQ通道被使能
//    NVIC_Init(&NVIC_InitStructure); //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器

//    TIM_ITConfig(TIM5, TIM_IT_Update | TIM_IT_CC1, ENABLE);     //允许更新中断 ,允许CC1IE捕获中断

//    TIM_Cmd(TIM5, ENABLE ); //使能定时器5
//    TIM5_IRQ = TIM5_Cap_IRQ;
//}


//u8  TIM5_CAPTURE_STA[4] = {0};//输入捕获状态
//u16 TIM5_CAPTURE_VAL[4];    //输入捕获值

//////定时器5中断服务程序
////void TIM5_Cap_IRQ(void)
////{
////    if ((TIM5_CAPTURE_STA[0] & 0X80) == 0) //还未成功捕获
////    {
////        if (TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)
////        {
////            u8 i=0
////            if (TIM5_CAPTURE_STA[i] & 0X40)
////            {
////                if ((TIM5_CAPTURE_STA[i] & 0X3F) == 0X3F) //高电平太长了
////                {
////                    TIM5_CAPTURE_STA[i] |= 0X80; //标记成功捕获了一次
////                    TIM5_CAPTURE_VAL[i] = 0XFFFF;
////                }
////                else TIM5_CAPTURE_STA[i]++;
////            }
////        }
////        if (TIM_GetITStatus(TIM5, TIM_IT_CC1) != RESET)//捕获1发生捕获事件
////        {
////            u8 i = 0;
////            if (TIM5_CAPTURE_STA[i] & 0X40)     //捕获到一个下降沿
////            {
////                TIM5_CAPTURE_STA[i] |= 0X80;    //标记成功捕获到一次上升沿
////                TIM5_CAPTURE_VAL[i] = TIM_GetCapture1(TIM5);
////                TIM_OC1PolarityConfig(TIM5, TIM_ICPolarity_Rising); //CC1P=0 设置为上升沿捕获
////            }
////            else                                //还未开始,第一次捕获上升沿
////            {
////                TIM5_CAPTURE_STA[i] = 0;        //清空
////                TIM5_CAPTURE_VAL[i] = 0;
////                TIM_SetCounter(TIM5, 0);
////                TIM5_CAPTURE_STA[i] |= 0X40;    //标记捕获到了上升沿
////                TIM_OC1PolarityConfig(TIM5, TIM_ICPolarity_Falling);    //CC1P=1 设置为下降沿捕获
////            }
////        }
////        if (TIM_GetITStatus(TIM5, TIM_IT_CC2) != RESET)//捕获1发生捕获事件
////        {
////            u8 i = 1;
////            if (TIM5_CAPTURE_STA[i] & 0X40)     //捕获到一个下降沿
////            {
////                TIM5_CAPTURE_STA[i] |= 0X80;    //标记成功捕获到一次上升沿
////                TIM5_CAPTURE_VAL[i] = TIM_GetCapture2(TIM5);
////                TIM_OC2PolarityConfig(TIM5, TIM_ICPolarity_Rising); //CC1P=0 设置为上升沿捕获
////            }
////            else                                //还未开始,第一次捕获上升沿
////            {
////                TIM5_CAPTURE_STA[i] = 0;        //清空
////                TIM5_CAPTURE_VAL[i] = 0;
////                TIM_SetCounter(TIM5, 0);
////                TIM5_CAPTURE_STA[i] |= 0X40;    //标记捕获到了上升沿
////                TIM_OC2PolarityConfig(TIM5, TIM_ICPolarity_Falling);    //CC1P=1 设置为下降沿捕获
////            }
////        }
////        if (TIM_GetITStatus(TIM5, TIM_IT_CC3) != RESET)//捕获1发生捕获事件
////        {
////            u8 i = 0;
////            if (TIM5_CAPTURE_STA[i] & 0X40)     //捕获到一个下降沿
////            {
////                TIM5_CAPTURE_STA[i] |= 0X80;    //标记成功捕获到一次上升沿
////                TIM5_CAPTURE_VAL[i] = TIM_GetCapture3(TIM5);
////                TIM_OC3PolarityConfig(TIM5, TIM_ICPolarity_Rising); //CC1P=0 设置为上升沿捕获
////            }
////            else                                //还未开始,第一次捕获上升沿
////            {
////                TIM5_CAPTURE_STA[i] = 0;        //清空
////                TIM5_CAPTURE_VAL[i] = 0;
////                TIM_SetCounter(TIM5, 0);
////                TIM5_CAPTURE_STA[i] |= 0X40;    //标记捕获到了上升沿
////                TIM_OC3PolarityConfig(TIM5, TIM_ICPolarity_Falling);    //CC1P=1 设置为下降沿捕获
////            }
////        }
////        if (TIM_GetITStatus(TIM5, TIM_IT_CC4) != RESET)//捕获1发生捕获事件
////        {
////            u8 i = 0;
////            if (TIM5_CAPTURE_STA[i] & 0X40)     //捕获到一个下降沿
////            {
////                TIM5_CAPTURE_STA[i] |= 0X80;    //标记成功捕获到一次上升沿
////                TIM5_CAPTURE_VAL[i] = TIM_GetCapture4(TIM5);
////                TIM_OC4PolarityConfig(TIM5, TIM_ICPolarity_Rising); //CC1P=0 设置为上升沿捕获
////            }
////            else                                //还未开始,第一次捕获上升沿
////            {
////                TIM5_CAPTURE_STA[i] = 0;        //清空
////                TIM5_CAPTURE_VAL[i] = 0;
////                TIM_SetCounter(TIM5, 0);
////                TIM5_CAPTURE_STA[i] |= 0X40;    //标记捕获到了上升沿
////                TIM_OC4PolarityConfig(TIM5, TIM_ICPolarity_Falling);    //CC1P=1 设置为下降沿捕获
////            }
////        }
////    }
////    TIM_ClearITPendingBit(TIM5, TIM_IT_CC1 | TIM_IT_CC2 | TIM_IT_CC3 | TIM_IT_CC4 | TIM_IT_Update); //清除中断标志位
////}

////u32 time_high(void)
////{
////    u32 temp;
////    while (1)
////    {
////        if (TIM5CH1_CAPTURE_STA & 0X80) //成功捕获到了一次上升沿
////        {
////            temp = TIM5CH1_CAPTURE_STA & 0X3F;
////            temp *= 65536; //溢出时间总和
////            temp += TIM5CH1_CAPTURE_VAL; //得到总的高电平时间
////            USART_OUT(USART1, "HIGH:&dms %dus\r\n", temp / 1000, temp % 1000); //打印总的高点平时间
////            TIM5CH1_CAPTURE_STA = 0; //开启下一次捕获
////            break;
////        }
////    }
////    return temp;
////}


////测高电平时间
///*****************************************************************************************************************************/



////测两次高电平之间 时间
///***************************************************************************************************************
//void TIM4_3_Cap_Init(u16 arr, u16 psc)
//{
//    GPIO_InitTypeDef GPIO_InitStructure;
//    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
//    NVIC_InitTypeDef                NVIC_InitStructure;
//    TIM_ICInitTypeDef           TIM4_ICInitStructure;

//    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);   //使能TIM5时钟
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);  //使能GPIOA时钟

//    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8;      //PA0 清除之前设置
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0 输入
//    GPIO_Init(GPIOB, &GPIO_InitStructure);
//    GPIO_ResetBits(GPIOB, GPIO_Pin_0);                       //PA0 下拉

//    //初始化定时器5 TIM5
//    TIM_TimeBaseStructure.TIM_Period = arr; //设定计数器自动重装值
//    TIM_TimeBaseStructure.TIM_Prescaler = psc;  //预分频器
//    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
//    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
//    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位

//    //初始化TIM5输入捕获参数
//    TIM4_ICInitStructure.TIM_Channel        = TIM_Channel_3; //CC1S=01     选择输入端 IC1映射到TI1上
//    TIM4_ICInitStructure.TIM_ICPolarity     = TIM_ICPolarity_Rising;        //上升沿捕获
//    TIM4_ICInitStructure.TIM_ICSelection    = TIM_ICSelection_DirectTI;     //映射到TI1上
//    TIM4_ICInitStructure.TIM_ICPrescaler    = TIM_ICPSC_DIV1;                       //配置输入分频,不分频
//    TIM4_ICInitStructure.TIM_ICFilter = 0x00;//IC1F=0000 配置输入滤波器 不滤波
//    TIM_ICInit(TIM4, &TIM4_ICInitStructure);

//    //中断分组初始化
//    NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;                     //TIM3中断
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; //先占优先级2级
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;              //从优先级0级
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                     //IRQ通道被使能
//    NVIC_Init(&NVIC_InitStructure); //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器

//    TIM_ITConfig(TIM4, TIM_IT_Update | TIM_IT_CC3, ENABLE);     //允许更新中断 ,允许CC1IE捕获中断

//    TIM_Cmd(TIM4, ENABLE ); //使能定时器5
//}

//#define TIMxCHx_CAPTURE_STA TIM4CH3_CAPTURE_STA
//#define TIMxCHx_CAPTURE_VAL TIM4CH3_CAPTURE_VAL
//u8  TIMxCHx_CAPTURE_STA = 0;//输入捕获状态
//u16 TIMxCHx_CAPTURE_VAL;    //输入捕获值
//void TIM4_IRQHandler(void)
//{
//    if ((TIMxCHx_CAPTURE_STA & 0X80) == 0) //还未成功捕获
//    {
//        if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
//        {
//            if (TIMxCHx_CAPTURE_STA & 0X40) //已经捕获到高电平了
//            {
//                if ((TIMxCHx_CAPTURE_STA & 0X3F) == 0X3F) //高电平太长了
//                {
//                    TIMxCHx_CAPTURE_STA |= 0X80; //标记成功捕获了一次
//                    TIMxCHx_CAPTURE_VAL = 0XFFFF;
//                }
//                else TIMxCHx_CAPTURE_STA++;
//            }
//        }
//        if (TIM_GetITStatus(TIM4, TIM_IT_CC3) != RESET)//捕获1发生捕获事件
//        {
//            if (TIMxCHx_CAPTURE_STA & 0X40)     //捕获到一个下降沿
//            {
//                TIMxCHx_CAPTURE_STA |= 0X80;    //标记成功捕获到一次上升沿
//                TIMxCHx_CAPTURE_VAL = TIM_GetCapture3(TIM4);
//                //TIM_OC3PolarityConfig(TIM4, TIM_ICPolarity_Rising); //CC1P=0 设置为上升沿捕获
//            }
//            else                                //还未开始,第一次捕获上升沿
//            {
//                TIMxCHx_CAPTURE_STA = 0;        //清空
//                TIMxCHx_CAPTURE_VAL = 0;
//                TIM_SetCounter(TIM4, 0);
//                TIMxCHx_CAPTURE_STA |= 0X40;    //标记捕获到了上升沿
//                //TIM_OC3PolarityConfig(TIM4, TIM_ICPolarity_Falling);    //CC1P=1 设置为下降沿捕获
//            }
//        }
//    }
//    TIM_ClearITPendingBit(TIM4, TIM_IT_CC3 | TIM_IT_Update); //清除中断标志位
//}
//u32 time_high_high(void)
//{
//    u32 temp;
//            while(1)
//            {
//              if (TIM4CH3_CAPTURE_STA & 0X80) //成功捕获到了一次上升沿
//        {
//                        temp=0;
//            temp = TIM4CH3_CAPTURE_STA & 0X3F;
//            temp *= 65536; //溢出时间总和
//            temp += TIM4CH3_CAPTURE_VAL; //得到总的高电平时间
//           // USART_OUT(USART1, "HIGH:%dms %dus\r\n", temp/1000,temp%1000); //打印总的高点平时间
//            TIM4CH3_CAPTURE_STA = 0; //开启下一次捕获
//                    break;
//                }
//            }
//            return temp;
//}
////测两次高电平之间 时间
//***************************************************************************************************************/


