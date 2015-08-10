#include "gpio.h"
#include "sys_usart.h"
#include "lcd.h"
#include "ov7670.h"
#include "minos_delay.h"
#include "sys_os.h"
#include "../../../GLIB/PERIPHERAL/NRF24L01/G32_Nrf24l01.h"


#include "../../GLIB/FATFS/exfuns/exfuns.h"
#include "../../GLIB/FATFS/src/ff.h"
#include "../../GLIB/PERIPHERAL/SD/sdio_sdcard.h"
void SYS_INIT(void)
{
    /***延时初始化***/
    delay_init();
    NVIC_Configuration();
    /***串口x初始化***/
    USART1_Configuration(115200);
    USART_NVIC_Configuration(1, 1, 0, 0);
    printf("\r\n USART IS OK !");
    /***LCD初始化***/
//    LCD_Init();
//    while (OV7670_Init())delay_ms(300);
//    delay_ms(1000);
//    TFT_Window(0, 0, 240, 320);
//    DMA_Cmd(DMA2_Stream1, ENABLE);
//    DCMI_Cmd(ENABLE);
//    DCMI_CaptureCmd(ENABLE);
//    while (SD_Init()!= SD_OK)       //检测SD卡
//    {
//        delay_ms(200);
//        printf("      SD ER          ");
//    }
//		printf("      SD OK          ");
}
extern void control(void);

int task_led(void)
{
    _SS

    PD12_OUT;
    while (1)
    {
        static char i = 0;
        WaitX(1400);
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
				control();
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

int task_Sd(void)
{
    _SS
    exfuns_init();          //为fatfs相关变量申请内存
    f_mount(0, fxs[0]);     //挂载SD卡
    while (SD_Init()!= SD_OK)       //检测SD卡
    {
        WaitX(200);
        printf("      SD ER          ");
    }
    printf("      SD OK          ");
		show_sdcard_info();
    /**************测试**************/
 f_open(file, "0://hjk.txt", FA_CREATE_ALWAYS);
 f_close (file);
 f_open(file, "0://123.txt", FA_OPEN_ALWAYS);
 f_open(file, "0://123.txt", FA_WRITE);
 f_write(file, "I Love you!", 12, &bxw);
 f_lseek(file, 20);
 f_write(file, "\n你好", 6, &bxw);
 f_printf(file, "nihao你好nihao");
 f_close(file);
    /**************测试**************/
//    f_open(file, "0://data.txt", FA_OPEN_ALWAYS);
//		//Open data file
//		f_open(file, "0://data.txt", FA_WRITE);
//		f_lseek(file,file->fsize);
    while (1)
    {
        WaitX(5000);

    }
		f_close(file);
    _EE
}
extern int task_Image_Processing(void);
int main(void)
{
    SYS_INIT();
    while (1)
    {
        RunTaskA(task_Image_Processing, 1);
        RunTaskA(task_usart, 2);
//				RunTaskA(task_Sd,3);
        RunTaskA(task_led, 5);
    }
}
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
