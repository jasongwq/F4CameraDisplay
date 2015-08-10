#include "gpio.h"
#include "USART.h"
#include "delay.h"
#include "lcd.h"
#include "ov7670.h"

#if 1==VERSIONSBY
#error 1
#elif 2==VERSIONSBY
//#error 2
#endif

extern u8 Camera_Init(void);
void SYS_INIT(void)
{
    /***延时初始化***/
    delay_init();
		NVIC_Configuration();
    /***串口x初始化***/
    USART2_Configuration(115200);
    USART_NVIC_Configuration(2,1, 0, 0);
    printf("\r\nNRF24L01 IS OK !");
	  
    /***LCD初始化***/
    LCD_Init();
	  LCD_ShowString(10,20,16*10,16,16,"hello lcd");
		while(OV7670_Init())
		{
			delay_ms(300);
			LCD_ShowString(10,36,16*20,16,16,"ov7670 error");
		}
		LCD_ShowString(10,36,16*20,16,16,"ov7670 ok");
		delay_ms(1000);
		Cam_Start();
}
#include "sys_os.h"
int task_led(void)
{
    _SS
    PD12_OUT;
    while (1)
    {
        static char i = 0;
        WaitX(2000);
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
//						{static int i=0;
//						switch(i++)
//{
//case 0:LCD_Clear(RED);break;
//case 2:LCD_Clear(GREEN);break;
//case 4:LCD_Clear(BLUE);break;
//case 6:LCD_Clear(YELLOW);i=0;break;
//}
//						}
        }
    _EE
}
int main(void)
{
    SYS_INIT();
    while (1)
    {
        RunTaskA(task_led, 5);
    }
}


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
