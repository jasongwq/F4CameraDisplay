#ifndef __TIMER_CAP_H
#define __TIMER_CAP_H
#include "sys.h"
/*****************************************************
REMAP        |   00    |   01    |   10    |   11    |
*****************************************************|
TIM2_CH1_ETR |   PA0   |   PA15  |  (PA0)  |(PA15)   |
TIM2_CH2     |   PA1   |   PB3   |  (PA1)  |(PB3 )   |
TIM2_CH3     |        PA2        |    (PB10)(!36)    |
TIM2_CH4     |        PA3        |    (PB11)(!36)    |
*****************************************************|
TIM3_CH1     |   PA6   |   PB4   |         |(PC6)(64 100 144)|
TIM3_CH2     |   PA7   |   PB5   |         |(PC7)    |
TIM3_CH3     |        PB0        |         |(PC8)    |
TIM3_CH4     |        PB1        |         |(PC9)    |
*****************************************************|
TIM4_CH1     |   PB6   |(PD12)(100 144)|   |         |
TIM4_CH1     |   PB7   |(PD13)(100 144)|   |         |
TIM4_CH1     |   PB8   |(PD14)(100 144)|   |         |
TIM4_CH1     |   PB9   |(PD15)(100 144)|   |         |
*****************************************************/

extern void TIM5_Cap_Init(u16 arr,u16 psc);
u32 time_high(void);

extern void TIM5_2_Cap_Init(u16 arr, u16 psc);

void TIM4_3_Cap_Init(u16 arr, u16 psc);
u32 time_high_high(void);



//extern u8		TIM5CH1_CAPTURE_STA;		    				
//extern u16	TIM5CH1_CAPTURE_VAL;

//extern u8		TIM4CH3_CAPTURE_STA;		    				
//extern u16	TIM4CH3_CAPTURE_VAL;

	
#endif
