/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4xx_IT_H
#define __STM32F4xx_IT_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void ATK_Usart1_IQR(void);
void ATK_Usart2_IQR(void);
void WTH_USART1_IRQHandler(void);
void WTH_USART2_IRQHandler(void);
void ATK_USB_LP_CAN1_RX0_IQR(void);
extern void (*TIM1_IRQ)(void);
extern void (*TIM2_IRQ)(void);
extern void (*TIM3_IRQ)(void);
extern void (*TIM4_IRQ)(void);
extern void (*TIM5_IRQ)(void);
extern void (*TIM6_IRQ)(void);
extern void (*TIM7_IRQ)(void);
extern void (*TIM1_BRK_IRQ)(void);
extern void (*TIM1_UP_IRQ)(void);
extern void (*TIM1_TRG_COM_IRQ)(void);
extern void (*TIM1_CC_IRQ)(void);

void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void EXTI0_IRQHandler(void);

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_IT_H */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
