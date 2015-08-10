/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_it.h"
void (*TIM1_IRQ)(void);
void (*TIM2_IRQ)(void);
void (*TIM3_IRQ)(void);
void (*TIM4_IRQ)(void);
void (*TIM5_IRQ)(void);
void (*TIM6_IRQ)(void);
void (*TIM7_IRQ)(void);
void (*TIM1_BRK_IRQ)(void);
void (*TIM1_UP_IRQ)(void);
void (*TIM1_TRG_COM_IRQ)(void);
void (*TIM1_CC_IRQ)(void);

void USART1_IRQHandler(void)  //串口中断函数
{
    //ATK_Usart1_IQR();
	//WTH_USART1_IRQHandler();
}
void USART2_IRQHandler(void)  //串口中断函数
{
    //ATK_Usart2_IQR();
		//WTH_USART2_IRQHandler();
}
void USART3_IRQHandler(void)  //串口中断函数
{

}/*
void DMA1_Channel1_IRQHandler(void)
{
    if (DMA_GetITStatus(DMA1_IT_TC1))
    {
        DMA_ClearITPendingBit(DMA1_IT_GL1);
    }
}*/
void TIM1_BRK_IRQHandler(void)
{
    TIM1_BRK_IRQ();
}
void TIM1_UP_IRQHandler(void)
{
    TIM1_UP_IRQ();
}
void TIM1_TRG_COM_IRQHandler(void)
{
    TIM1_TRG_COM_IRQ();
}
void TIM1_CC_IRQHandler(void)
{
    TIM1_CC_IRQ();
}
void TIM2_IRQHandler(void)
{
    if (TIM2->SR & TIM_IT_Update)
    {
        TIM2_IRQ();
        TIM2->SR = ~TIM_FLAG_Update;
    }
}
void TIM3_IRQHandler(void)
{
    if (TIM3->SR & TIM_IT_Update)
    {
        TIM3_IRQ();
        TIM3->SR = ~TIM_FLAG_Update;
    }
}
void TIM4_IRQHandler(void)
{
    if (TIM4->SR & TIM_IT_Update)
    {
        TIM4_IRQ();
        TIM4->SR = ~TIM_FLAG_Update;
    }
}
void TIM5_IRQHandler(void)
{
    if (TIM5->SR & TIM_IT_Update)
    {
        TIM5_IRQ();
        TIM5->SR = ~TIM_FLAG_Update;
    }
}
void TIM6_IRQHandler(void)
{
    if (TIM6->SR & TIM_IT_Update)
    {
        TIM6_IRQ();
        TIM6->SR = ~TIM_FLAG_Update;
    }
}
void TIM7_IRQHandler(void)
{
    if (TIM7->SR & TIM_IT_Update)
    {
        TIM7_IRQ();
        TIM7->SR = ~TIM_FLAG_Update;
    }
}
/*******************************************************************************
* Function Name  : USB_HP_CAN_TX_IRQHandler
* Description    : This function handles USB High Priority or CAN TX interrupts
*                  requests.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USB_HP_CAN1_TX_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : USB_LP_CAN_RX0_IRQHandler
* Description    : This function handles USB Low Priority or CAN RX0 interrupts
*                  requests.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USB_LP_CAN1_RX0_IRQHandler(void)
{
    //ATK_USB_LP_CAN1_RX0_IQR();
}
void USBWakeUp_IRQHandler(void)
{
}
//#include "lcd_dis24.h"

//void DCMI_IRQHandler(void) 
//{
//	if (DCMI_GetITStatus(DCMI_IT_FRAME)) 
//	{
//    LCD_SetCursor(0, 0);
//    LCD_WriteRAM_Prepare();   // Prepare to write GRAM
//		DCMI_ClearFlag(DCMI_IT_FRAME);
//	}
//}
#include "lcd.h"
void DCMI_IRQHandler(void){
  // Przerwanie generowane po odebraniu pelnej ramki
  if(DCMI_GetITStatus(DCMI_IT_FRAME) == SET){
    DCMI_ClearITPendingBit(DCMI_IT_FRAME);
  }
  // Przerwanie generowane przy zmianie stanu sygnalu VSYNC z aktywnego na nieaktywny (VPOL = Low)
  if(DCMI_GetITStatus(DCMI_IT_VSYNC) == SET){
    DCMI_ClearITPendingBit(DCMI_IT_VSYNC);

    while(DMA_GetFlagStatus(DMA2_Stream1,DMA_FLAG_TCIF1) == RESET);
    LCD_SetCursor(0, 0);
    LCD_WriteRAM_Prepare();   // Prepare to write GRAM
  }

  // Przerwanie generowane przy zmianie stanu sygnalu HSYNC z aktywnego na nieaktywny (HPOL = Low)
  if(DCMI_GetITStatus(DCMI_IT_LINE) == SET){
    DCMI_ClearITPendingBit(DCMI_IT_LINE);
  }

  // Przerwanie generowane gdy stare dane (32-bitowe) w rejestrze DCMI_DR
  // nie zostaly calkowicie przeslane przed nadejsciem nowych danych
  if(DCMI_GetITStatus(DCMI_IT_OVF) == SET){
    DCMI_ClearITPendingBit(DCMI_IT_OVF);
  }
}
#include "sys_os.h"
#ifdef OS_CRITICAL_METHOD
u32 SysTick_Time=0;
void SysTick_Handler(void)
{
		SysTick_Time++;if(SysTick_Time>=(OS_TICKS_PER_SEC*60*60))SysTick_Time=0;
    UpdateTimers();
    //RunTask(task5, 5);
}
#endif

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/
