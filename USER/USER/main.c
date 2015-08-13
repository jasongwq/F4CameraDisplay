#include "gpio.h"
#include "sys_usart.h"
#include "lcd.h"
#include "ov7670.h"
#include "minos_delay.h"
#include "sys_os.h"
#include "../../../GLIB/PERIPHERAL/NRF24L01/G32_Nrf24l01.h"

void SYS_INIT(void)
{
    /***延时初始化***/
    delay_init();
    NVIC_Configuration();
    /***串口x初始化***/
    USART2_Configuration(256000);
    USART_NVIC_Configuration(2, 1, 0, 0);
    printf("\r\n USART IS OK !");
	  Sys_sPrintf(Printf_USART,"\r\nSys_sPrintf",14);
    /***LCD初始化***/
    LCD_Init();
	  LCD_ShowString(32,24,288,16,16,"HELLHHHHHHHHHHHHHHHHHHHHHHHHHHHO");
    while (OV7670_Init())
		{delay_ms(300);}
    delay_ms(1000);
	  OV7670_Window_Set(10,182,240,320);
	  //OV7670_Window_Set(10,182,240,144);
    //TFT_Window(0, 0, 240, 144);
	  OV7670_Contrast(4);
	  TFT_Window(0, 0, OV7670XP/OV7670XF, OV7670YP/OV7670YF);
	  //TFT_Window(0, 0, 120, 160);

    DMA_Cmd(DMA2_Stream1, ENABLE);
    DCMI_Cmd(ENABLE);
    DCMI_CaptureCmd(ENABLE);
		printf("Init OK          ");
}
extern int Ov7670FrameRate;
int task_led(void)
{
    _SS
    PD12_OUT;
    while (1)
    {
        static char i = 0;
        WaitX(1000);
			//printf("\r\nOv7670FrameRate: %3d", Ov7670FrameRate);
			Ov7670FrameRate=0;
        if (i)
        {
            PDout(12) = 1;
            i = 0;
        }
        else
        {
            i = 1;
            PDout(12) = 0;
        }
    }
    _EE
}
u8 nrf_test[32];

#include "data_transfer.h"
int task_usart(void)
{
    _SS
    /***NRF24L01***/
    Nrf24l01_Init(MODEL_TX, 1);
    if (Nrf24l01_Check())
        printf("\r\n NRF24L01 IS OK !");
    else
        printf("\r\n NRF24L01 ERROR !");

    while (1)
    {
        WaitX(20);
				Data_Exchange();
    }
    _EE
}

extern int task_Image_Processing(void);
extern int task_test(void);

int main(void)
{
    SYS_INIT();
    while (1)
    {
        RunTaskA(task_Image_Processing, 1);
        //RunTaskA(task_usart, 2);
			  //RunTaskA(task_test,3);
        RunTaskA(task_led, 5);
    }
}
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
