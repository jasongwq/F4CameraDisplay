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
////��
///*************************************************************************************************/
/////*
////#include "G32_timer_cap.h"
////int main(void)
////{
////    /***����***/
////    u32 temp = 0;
////    /***��ʱ��ʼ��***/
////    //Clock_Enable();
////    SystemInit();
////    delay_init();
////    NVIC_Configuration();
////    /***����x��ʼ��***/
////    uart_init(38400);
////    uart2_init(38400);
////    /***����***/
////    TIM5_Cap_Init(0XFFFF, 72 - 1);
////    while (1)
////    {
////        delay_ms(10);
////        if (TIM5CH1_CAPTURE_STA & 0X80) //�ɹ�������һ��������
////        {
////            temp = TIM5CH1_CAPTURE_STA & 0X3F;
////            temp *= 65536; //���ʱ���ܺ�
////            temp += TIM5CH1_CAPTURE_VAL; //�õ��ܵĸߵ�ƽʱ��
////            USART_OUT(USART1, "HIGH��:%d us\r\n", temp); //��ӡ�ܵĸߵ�ƽʱ��
////            TIM5CH1_CAPTURE_STA = 0; //������һ�β���
////        }
////    }
////}
////*/

////��ߵ�ƽʱ��
///*****************************************************************************************************************************/
//void TIM5_Cap_IRQ(void);
////��ʱ��5ͨ��1���벶������
//void TIM5_Cap_Init(u16 arr, u16 psc)
//{
//    GPIO_InitTypeDef GPIO_InitStructure;
//    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//    NVIC_InitTypeDef NVIC_InitStructure;
//    TIM_ICInitTypeDef  TIM5_ICInitStructure;

//    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);   //ʹ��TIM5ʱ��
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  //ʹ��GPIOAʱ��

//    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;  //PA0 ���֮ǰ����
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0 ����
//    GPIO_Init(GPIOA, &GPIO_InitStructure);
//    GPIO_ResetBits(GPIOA, GPIO_Pin_0);                       //PA0 ����

//    //��ʼ����ʱ��5 TIM5
//    TIM_TimeBaseStructure.TIM_Period = arr; //�趨�������Զ���װֵ
//    TIM_TimeBaseStructure.TIM_Prescaler = psc;  //Ԥ��Ƶ��
//    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
//    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
//    TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ

//    //��ʼ��TIM5���벶�����
//    TIM5_ICInitStructure.TIM_Channel = TIM_Channel_1; //CC1S=01     ѡ������� IC1ӳ�䵽TI1��
//    TIM5_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;    //�����ز���
//    TIM5_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //ӳ�䵽TI1��
//    TIM5_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;   //���������Ƶ,����Ƶ
//    TIM5_ICInitStructure.TIM_ICFilter = 0x00;//IC1F=0000 ���������˲��� ���˲�
//    TIM_ICInit(TIM5, &TIM5_ICInitStructure);

//    //�жϷ����ʼ��
//    NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;                     //TIM3�ж�
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; //��ռ���ȼ�2��
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;              //�����ȼ�0��
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                     //IRQͨ����ʹ��
//    NVIC_Init(&NVIC_InitStructure); //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���

//    TIM_ITConfig(TIM5, TIM_IT_Update | TIM_IT_CC1, ENABLE);     //��������ж� ,����CC1IE�����ж�

//    TIM_Cmd(TIM5, ENABLE ); //ʹ�ܶ�ʱ��5
//    TIM5_IRQ = TIM5_Cap_IRQ;
//}


//u8  TIM5_CAPTURE_STA[4] = {0};//���벶��״̬
//u16 TIM5_CAPTURE_VAL[4];    //���벶��ֵ

//////��ʱ��5�жϷ������
////void TIM5_Cap_IRQ(void)
////{
////    if ((TIM5_CAPTURE_STA[0] & 0X80) == 0) //��δ�ɹ�����
////    {
////        if (TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)
////        {
////            u8 i=0
////            if (TIM5_CAPTURE_STA[i] & 0X40)
////            {
////                if ((TIM5_CAPTURE_STA[i] & 0X3F) == 0X3F) //�ߵ�ƽ̫����
////                {
////                    TIM5_CAPTURE_STA[i] |= 0X80; //��ǳɹ�������һ��
////                    TIM5_CAPTURE_VAL[i] = 0XFFFF;
////                }
////                else TIM5_CAPTURE_STA[i]++;
////            }
////        }
////        if (TIM_GetITStatus(TIM5, TIM_IT_CC1) != RESET)//����1���������¼�
////        {
////            u8 i = 0;
////            if (TIM5_CAPTURE_STA[i] & 0X40)     //����һ���½���
////            {
////                TIM5_CAPTURE_STA[i] |= 0X80;    //��ǳɹ�����һ��������
////                TIM5_CAPTURE_VAL[i] = TIM_GetCapture1(TIM5);
////                TIM_OC1PolarityConfig(TIM5, TIM_ICPolarity_Rising); //CC1P=0 ����Ϊ�����ز���
////            }
////            else                                //��δ��ʼ,��һ�β���������
////            {
////                TIM5_CAPTURE_STA[i] = 0;        //���
////                TIM5_CAPTURE_VAL[i] = 0;
////                TIM_SetCounter(TIM5, 0);
////                TIM5_CAPTURE_STA[i] |= 0X40;    //��ǲ�����������
////                TIM_OC1PolarityConfig(TIM5, TIM_ICPolarity_Falling);    //CC1P=1 ����Ϊ�½��ز���
////            }
////        }
////        if (TIM_GetITStatus(TIM5, TIM_IT_CC2) != RESET)//����1���������¼�
////        {
////            u8 i = 1;
////            if (TIM5_CAPTURE_STA[i] & 0X40)     //����һ���½���
////            {
////                TIM5_CAPTURE_STA[i] |= 0X80;    //��ǳɹ�����һ��������
////                TIM5_CAPTURE_VAL[i] = TIM_GetCapture2(TIM5);
////                TIM_OC2PolarityConfig(TIM5, TIM_ICPolarity_Rising); //CC1P=0 ����Ϊ�����ز���
////            }
////            else                                //��δ��ʼ,��һ�β���������
////            {
////                TIM5_CAPTURE_STA[i] = 0;        //���
////                TIM5_CAPTURE_VAL[i] = 0;
////                TIM_SetCounter(TIM5, 0);
////                TIM5_CAPTURE_STA[i] |= 0X40;    //��ǲ�����������
////                TIM_OC2PolarityConfig(TIM5, TIM_ICPolarity_Falling);    //CC1P=1 ����Ϊ�½��ز���
////            }
////        }
////        if (TIM_GetITStatus(TIM5, TIM_IT_CC3) != RESET)//����1���������¼�
////        {
////            u8 i = 0;
////            if (TIM5_CAPTURE_STA[i] & 0X40)     //����һ���½���
////            {
////                TIM5_CAPTURE_STA[i] |= 0X80;    //��ǳɹ�����һ��������
////                TIM5_CAPTURE_VAL[i] = TIM_GetCapture3(TIM5);
////                TIM_OC3PolarityConfig(TIM5, TIM_ICPolarity_Rising); //CC1P=0 ����Ϊ�����ز���
////            }
////            else                                //��δ��ʼ,��һ�β���������
////            {
////                TIM5_CAPTURE_STA[i] = 0;        //���
////                TIM5_CAPTURE_VAL[i] = 0;
////                TIM_SetCounter(TIM5, 0);
////                TIM5_CAPTURE_STA[i] |= 0X40;    //��ǲ�����������
////                TIM_OC3PolarityConfig(TIM5, TIM_ICPolarity_Falling);    //CC1P=1 ����Ϊ�½��ز���
////            }
////        }
////        if (TIM_GetITStatus(TIM5, TIM_IT_CC4) != RESET)//����1���������¼�
////        {
////            u8 i = 0;
////            if (TIM5_CAPTURE_STA[i] & 0X40)     //����һ���½���
////            {
////                TIM5_CAPTURE_STA[i] |= 0X80;    //��ǳɹ�����һ��������
////                TIM5_CAPTURE_VAL[i] = TIM_GetCapture4(TIM5);
////                TIM_OC4PolarityConfig(TIM5, TIM_ICPolarity_Rising); //CC1P=0 ����Ϊ�����ز���
////            }
////            else                                //��δ��ʼ,��һ�β���������
////            {
////                TIM5_CAPTURE_STA[i] = 0;        //���
////                TIM5_CAPTURE_VAL[i] = 0;
////                TIM_SetCounter(TIM5, 0);
////                TIM5_CAPTURE_STA[i] |= 0X40;    //��ǲ�����������
////                TIM_OC4PolarityConfig(TIM5, TIM_ICPolarity_Falling);    //CC1P=1 ����Ϊ�½��ز���
////            }
////        }
////    }
////    TIM_ClearITPendingBit(TIM5, TIM_IT_CC1 | TIM_IT_CC2 | TIM_IT_CC3 | TIM_IT_CC4 | TIM_IT_Update); //����жϱ�־λ
////}

////u32 time_high(void)
////{
////    u32 temp;
////    while (1)
////    {
////        if (TIM5CH1_CAPTURE_STA & 0X80) //�ɹ�������һ��������
////        {
////            temp = TIM5CH1_CAPTURE_STA & 0X3F;
////            temp *= 65536; //���ʱ���ܺ�
////            temp += TIM5CH1_CAPTURE_VAL; //�õ��ܵĸߵ�ƽʱ��
////            USART_OUT(USART1, "HIGH:&dms %dus\r\n", temp / 1000, temp % 1000); //��ӡ�ܵĸߵ�ƽʱ��
////            TIM5CH1_CAPTURE_STA = 0; //������һ�β���
////            break;
////        }
////    }
////    return temp;
////}


////��ߵ�ƽʱ��
///*****************************************************************************************************************************/



////�����θߵ�ƽ֮�� ʱ��
///***************************************************************************************************************
//void TIM4_3_Cap_Init(u16 arr, u16 psc)
//{
//    GPIO_InitTypeDef GPIO_InitStructure;
//    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
//    NVIC_InitTypeDef                NVIC_InitStructure;
//    TIM_ICInitTypeDef           TIM4_ICInitStructure;

//    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);   //ʹ��TIM5ʱ��
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);  //ʹ��GPIOAʱ��

//    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8;      //PA0 ���֮ǰ����
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0 ����
//    GPIO_Init(GPIOB, &GPIO_InitStructure);
//    GPIO_ResetBits(GPIOB, GPIO_Pin_0);                       //PA0 ����

//    //��ʼ����ʱ��5 TIM5
//    TIM_TimeBaseStructure.TIM_Period = arr; //�趨�������Զ���װֵ
//    TIM_TimeBaseStructure.TIM_Prescaler = psc;  //Ԥ��Ƶ��
//    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
//    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
//    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ

//    //��ʼ��TIM5���벶�����
//    TIM4_ICInitStructure.TIM_Channel        = TIM_Channel_3; //CC1S=01     ѡ������� IC1ӳ�䵽TI1��
//    TIM4_ICInitStructure.TIM_ICPolarity     = TIM_ICPolarity_Rising;        //�����ز���
//    TIM4_ICInitStructure.TIM_ICSelection    = TIM_ICSelection_DirectTI;     //ӳ�䵽TI1��
//    TIM4_ICInitStructure.TIM_ICPrescaler    = TIM_ICPSC_DIV1;                       //���������Ƶ,����Ƶ
//    TIM4_ICInitStructure.TIM_ICFilter = 0x00;//IC1F=0000 ���������˲��� ���˲�
//    TIM_ICInit(TIM4, &TIM4_ICInitStructure);

//    //�жϷ����ʼ��
//    NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;                     //TIM3�ж�
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; //��ռ���ȼ�2��
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;              //�����ȼ�0��
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                     //IRQͨ����ʹ��
//    NVIC_Init(&NVIC_InitStructure); //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���

//    TIM_ITConfig(TIM4, TIM_IT_Update | TIM_IT_CC3, ENABLE);     //��������ж� ,����CC1IE�����ж�

//    TIM_Cmd(TIM4, ENABLE ); //ʹ�ܶ�ʱ��5
//}

//#define TIMxCHx_CAPTURE_STA TIM4CH3_CAPTURE_STA
//#define TIMxCHx_CAPTURE_VAL TIM4CH3_CAPTURE_VAL
//u8  TIMxCHx_CAPTURE_STA = 0;//���벶��״̬
//u16 TIMxCHx_CAPTURE_VAL;    //���벶��ֵ
//void TIM4_IRQHandler(void)
//{
//    if ((TIMxCHx_CAPTURE_STA & 0X80) == 0) //��δ�ɹ�����
//    {
//        if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
//        {
//            if (TIMxCHx_CAPTURE_STA & 0X40) //�Ѿ����񵽸ߵ�ƽ��
//            {
//                if ((TIMxCHx_CAPTURE_STA & 0X3F) == 0X3F) //�ߵ�ƽ̫����
//                {
//                    TIMxCHx_CAPTURE_STA |= 0X80; //��ǳɹ�������һ��
//                    TIMxCHx_CAPTURE_VAL = 0XFFFF;
//                }
//                else TIMxCHx_CAPTURE_STA++;
//            }
//        }
//        if (TIM_GetITStatus(TIM4, TIM_IT_CC3) != RESET)//����1���������¼�
//        {
//            if (TIMxCHx_CAPTURE_STA & 0X40)     //����һ���½���
//            {
//                TIMxCHx_CAPTURE_STA |= 0X80;    //��ǳɹ�����һ��������
//                TIMxCHx_CAPTURE_VAL = TIM_GetCapture3(TIM4);
//                //TIM_OC3PolarityConfig(TIM4, TIM_ICPolarity_Rising); //CC1P=0 ����Ϊ�����ز���
//            }
//            else                                //��δ��ʼ,��һ�β���������
//            {
//                TIMxCHx_CAPTURE_STA = 0;        //���
//                TIMxCHx_CAPTURE_VAL = 0;
//                TIM_SetCounter(TIM4, 0);
//                TIMxCHx_CAPTURE_STA |= 0X40;    //��ǲ�����������
//                //TIM_OC3PolarityConfig(TIM4, TIM_ICPolarity_Falling);    //CC1P=1 ����Ϊ�½��ز���
//            }
//        }
//    }
//    TIM_ClearITPendingBit(TIM4, TIM_IT_CC3 | TIM_IT_Update); //����жϱ�־λ
//}
//u32 time_high_high(void)
//{
//    u32 temp;
//            while(1)
//            {
//              if (TIM4CH3_CAPTURE_STA & 0X80) //�ɹ�������һ��������
//        {
//                        temp=0;
//            temp = TIM4CH3_CAPTURE_STA & 0X3F;
//            temp *= 65536; //���ʱ���ܺ�
//            temp += TIM4CH3_CAPTURE_VAL; //�õ��ܵĸߵ�ƽʱ��
//           // USART_OUT(USART1, "HIGH:%dms %dus\r\n", temp/1000,temp%1000); //��ӡ�ܵĸߵ�ƽʱ��
//            TIM4CH3_CAPTURE_STA = 0; //������һ�β���
//                    break;
//                }
//            }
//            return temp;
//}
////�����θߵ�ƽ֮�� ʱ��
//***************************************************************************************************************/


