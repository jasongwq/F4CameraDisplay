#ifndef __PWM_H
#define __PWM_H

#include "PWM_comp.h"
#include "stm32f4xx.h" 

/*
   APB2 为 168M
   TIM1 TIM8 TIM9 TIM10 TIM11

   APB1 为 84M
   TIM2 TIM3 TIM4 TIM5 TIM6 TIM7   TIM12 TIM13 TIM14

 */

									// TIM1	   OC1	 OC2   OC3	 OC4
/*** 选择通道 1 **/
//#define TIM1_OC1_USE_PA8	             //	   PA8   PA9   PA10  PA11
#define TIM1_OC1_USE_PE9				 //    PE9   PE11  PE13  PE14
/*** 选择通道 2 **/
//#define TIM1_OC2_USE_PA9	 // PA9 出来的占空比偏低
#define TIM1_OC2_USE_PE11
/*** 选择通道 3 **/
//#define TIM1_OC3_USE_PA10
#define TIM1_OC3_USE_PE13
/*** 选择通道 4 **/
//#define TIM1_OC4_USE_PA11
#define TIM1_OC4_USE_PE14

									 // TIM2    OC1	  OC2   OC3	 OC4
/*** 选择通道 1 **/					
#define TIM2_OC1_USE_PA0	              //	PA0   PA1   PA2  PA3
//#define TIM2_OC1_USE_PA5				  //	PA5
//#define TIM2_OC1_USE_PA15				  //    PA15  PB3   PB10 PB11
/*** 选择通道 2 **/
#define TIM2_OC2_USE_PA1
//#define TIM2_OC2_USE_PB3
/*** 选择通道 3 **/
#define TIM2_OC3_USE_PA2
//#define TIM2_OC3_USE_PB10
/*** 选择通道 4 **/
#define TIM2_OC4_USE_PA3
//#define TIM2_OC4_USE_PB11

									  // TIM3   OC1	 OC2   OC3	 OC4
/*** 选择通道 1 **/
//#define TIM3_OC1_USE_PA6 	              //	PA6  PA7   PB0   PB1
#define TIM3_OC1_USE_PC6				  //	PB4	 PB5
//#define TIM3_OC1_USE_PB4				  //    
/*** 选择通道 2 **/
//#define TIM3_OC2_USE_PA7
//#define TIM3_OC2_USE_PB5
#define TIM3_OC2_USE_PC7
/*** 选择通道 3 **/
//#define TIM3_OC3_USE_PB0
#define TIM3_OC3_USE_PC8
/*** 选择通道 4 **/
#define TIM3_OC4_USE_PC9
//#define TIM3_OC4_USE_PB1					  

									  // TIM4    OC1	 OC2   OC3	 OC4
/*** 选择通道 1 **/
//#define TIM4_OC1_USE_PB6	              //	 PB6     PB7   PB8   PB9				  
#define TIM4_OC1_USE_PD12				  //     PD12    PD13  PD14  PD15
/*** 选择通道 2 **/
//#define TIM4_OC2_USE_PB7
#define TIM4_OC2_USE_PD13
/*** 选择通道 3 **/
//#define TIM4_OC3_USE_PB8
#define TIM4_OC3_USE_PD14
/*** 选择通道 4 **/
//#define TIM4_OC4_USE_PB9
#define TIM4_OC4_USE_PD15


									 // TIM5    OC1	  OC2   OC3	  OC4
/*** 选择通道 1 **/
#define TIM5_OC1_USE_PA0	               //	PA0   PA1   PA2   PA3
//#define TIM5_OC1_USE_PH10				   //   PH10  PH11  PH12  PI13
/*** 选择通道 2 **/
#define TIM5_OC2_USE_PA1
//#define TIM5_OC2_USE_PH11
/*** 选择通道 3 **/
#define TIM5_OC3_USE_PA2
//#define TIM5_OC3_USE_PH12
/*** 选择通道 4 **/
#define TIM5_OC4_USE_PA3
//#define TIM5_OC4_USE_PI13
								     // TIM8    OC1	 OC2   OC3	 OC4
/*** 选择通道 1 **/		//  
#define TIM8_OC1_USE_PC6	               //	PC6  PC7   PC8   PC9
//#define TIM8_OC1_USE_PI5				   //   PI5  PI6   PI7   PI2
/*** 选择通道 2 **/
#define TIM8_OC2_USE_PC7
//#define TIM8_OC2_USE_PI6
/*** 选择通道 3 **/
#define TIM8_OC3_USE_PC8
//#define TIM8_OC3_USE_PI7
/*** 选择通道 4 **/
#define TIM8_OC4_USE_PC9
//#define TIM8_OC4_USE_PI2


								    // TIM9     OC1	 OC2   OC3	 OC4
/*** 选择通道 1 **/
//#define TIM9_OC1_USE_PA2	               //	PE5  PE6
#define TIM9_OC1_USE_PE5				   //   PA2  PA3 
/*** 选择通道 2 **/
//#define TIM9_OC2_USE_PA3
#define TIM9_OC2_USE_PE6

								   // TIM10    OC1	 OC2   OC3	 OC4
/*** 选择通道 1 **/				   
//#define TIM10_OC1_USE_PB8	               //  PB8	
#define TIM10_OC1_USE_PF6				   //  PF6



								   
/*** 选择通道 1 **/				   
//#define TIM11_OC1_USE_PB9				   //  PB9    
#define TIM11_OC1_USE_PF7				   //  PF7

								   // TIM12    OC1	 OC2   OC3	 OC4
/*** 选择通道 1 **/
#define TIM12_OC1_USE_PB14	           //  PB14  PB15
//#define TIM12_OC1_USE_PH6			   //  PH6   PH9
/*** 选择通道 2 **/
#define TIM12_OC2_USE_PB15
//#define TIM12_OC2_USE_PH9


/*** 选择通道 1 **/				  // TIM13     OC1	 OC2   OC3	 OC4
#define TIM13_OC1_USE_PA6				   //  PA6   
//#define TIM13_OC1_USE_PF8				   //  PF8


								 // TIM14      OC1	 OC2   OC3	 OC4
/*** 选择通道 1 **/
#define TIM14_OC1_USE_PA7				   //  PA7 
//#define TIM14_OC1_USE_PF9				   //  PF9


void TIM1_PWM_init(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2 ,u8 OC3 ,u8 OC4);
/*
 *	 TIM1_PWM_init(1,1,1,0);	PA8 PA9 PA10 PA11	  初始化了前三个通道
 */
void TIM1_Change_Period(u16 NoteSet);
void Change_TIM1_OC1_Pulse(u16 Pulse);
void Change_TIM1_OC2_Pulse(u16 Pulse);
void Change_TIM1_OC3_Pulse(u16 Pulse);
void Change_TIM1_OC4_Pulse(u16 Pulse);
void Change_TIM1_OC1_Polarity(u8 i);
void Change_TIM1_OC2_Polarity(u8 i);
void Change_TIM1_OC3_Polarity(u8 i);
void Change_TIM1_OC4_Polarity(u8 i);

void TIM2_PWM_init(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2 ,u8 OC3 ,u8 OC4);
/*
 *	 TIM2_PWM_init(1,1,1,0);	PA0 PA1 PA2 PA3	  初始化了前三个通道
 */
void TIM2_Change_Period(u16 NoteSet);
void Change_TIM2_OC1_Pulse(u16 Pulse);
void Change_TIM2_OC2_Pulse(u16 Pulse);
void Change_TIM2_OC3_Pulse(u16 Pulse);
void Change_TIM2_OC4_Pulse(u16 Pulse);
void Change_TIM2_OC1_Polarity(u8 i);
void Change_TIM2_OC2_Polarity(u8 i);
void Change_TIM2_OC3_Polarity(u8 i);
void Change_TIM2_OC4_Polarity(u8 i);


void TIM3_PWM_init(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2 ,u8 OC3 ,u8 OC4);
/*
 *	 TIM3_PWM_init(1,1,1,0);	PA6 PA7 PB0 PB1	  初始化了前三个通道
 */
void TIM3_Change_Period(u16 NoteSet);
void Change_TIM3_OC1_Pulse(u16 Pulse);
void Change_TIM3_OC2_Pulse(u16 Pulse);
void Change_TIM3_OC3_Pulse(u16 Pulse);
void Change_TIM3_OC4_Pulse(u16 Pulse);
void Change_TIM3_OC1_Polarity(u8 i);
void Change_TIM3_OC2_Polarity(u8 i);
void Change_TIM3_OC3_Polarity(u8 i);
void Change_TIM3_OC4_Polarity(u8 i);


void TIM4_PWM_init(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2 ,u8 OC3 ,u8 OC4);
/*
 *	 TIM4_PWM_init(1,1,1,0);	PB6 PB7 PB8 PB9	  初始化了前三个通道
 */
void TIM4_Change_Period(u16 NoteSet);
void Change_TIM4_OC1_Pulse(u16 Pulse);
void Change_TIM4_OC2_Pulse(u16 Pulse);
void Change_TIM4_OC3_Pulse(u16 Pulse);
void Change_TIM4_OC4_Pulse(u16 Pulse);
void Change_TIM4_OC1_Polarity(u8 i);
void Change_TIM4_OC2_Polarity(u8 i);
void Change_TIM4_OC3_Polarity(u8 i);
void Change_TIM4_OC4_Polarity(u8 i);


void TIM5_PWM_init(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2 ,u8 OC3 ,u8 OC4);
/*
 *	 TIM5_PWM_init(1,1,1,0);	PA0 PA1 PA2 PA3	  初始化了前三个通道
 */
void TIM5_Change_Period(u16 NoteSet);
void Change_TIM5_OC1_Pulse(u16 Pulse);
void Change_TIM5_OC2_Pulse(u16 Pulse);
void Change_TIM5_OC3_Pulse(u16 Pulse);
void Change_TIM5_OC4_Pulse(u16 Pulse);
void Change_TIM5_OC1_Polarity(u8 i);
void Change_TIM5_OC2_Polarity(u8 i);
void Change_TIM5_OC3_Polarity(u8 i);
void Change_TIM5_OC4_Polarity(u8 i);

void TIM8_PWM_init(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2 ,u8 OC3 ,u8 OC4);
/*
 *	 TIM8_PWM_init(36,40000,1,1,1,0);	PC6 PC7 PC8 PC9	  初始化了前三个通道	
 */
void TIM8_Change_Period(u16 NoteSet);
void Change_TIM8_OC1_Pulse(u16 Pulse);					   //	  TIM5_Change_Period(999);
void Change_TIM8_OC2_Pulse(u16 Pulse);					   //	  Change_TIM5_OC1_Pulse(800);	 占空比为80%   频率为 72  KHz
void Change_TIM8_OC3_Pulse(u16 Pulse);					   //	  TIM5_Change_Period(9999);
void Change_TIM8_OC4_Pulse(u16 Pulse);					   //	  Change_TIM5_OC1_Pulse(8000);	 占空比为80%   频率为 7.2 KHz
void Change_TIM8_OC1_Polarity(u8 i);
void Change_TIM8_OC2_Polarity(u8 i);
void Change_TIM8_OC3_Polarity(u8 i);
void Change_TIM8_OC4_Polarity(u8 i);

void TIM9_PWM_init(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2);
void TIM9_Change_Period(u16 NoteSet);
void Change_TIM9_OC1_Pulse(u16 Pulse);					  
void Change_TIM9_OC2_Pulse(u16 Pulse);					  
void Change_TIM9_OC1_Polarity(u8 i);
void Change_TIM9_OC2_Polarity(u8 i);

void TIM10_PWM_init(u16 Prescaler,u16 Period,u8 OC1);
void TIM10_Change_Period(u16 NoteSet);
void Change_TIM10_OC1_Pulse(u16 Pulse);					  
void Change_TIM10_OC1_Polarity(u8 i);

void TIM11_PWM_init(u16 Prescaler,u16 Period,u8 OC1);
void TIM11_Change_Period(u16 NoteSet);
void Change_TIM11_OC1_Pulse(u16 Pulse);					   
void Change_TIM11_OC1_Polarity(u8 i);

void TIM12_PWM_init(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2);
void TIM12_Change_Period(u16 NoteSet);
void Change_TIM12_OC1_Pulse(u16 Pulse);					  
void Change_TIM12_OC2_Pulse(u16 Pulse);					  
void Change_TIM12_OC1_Polarity(u8 i);
void Change_TIM12_OC2_Polarity(u8 i);

void TIM13_PWM_init(u16 Prescaler,u16 Period,u8 OC1);
void TIM13_Change_Period(u16 NoteSet);
void Change_TIM13_OC1_Pulse(u16 Pulse);					  
void Change_TIM13_OC1_Polarity(u8 i);

void TIM14_PWM_init(u16 Prescaler,u16 Period,u8 OC1);
void TIM14_Change_Period(u16 NoteSet);
void Change_TIM14_OC1_Pulse(u16 Pulse);					   
void Change_TIM14_OC1_Polarity(u8 i);

#endif
