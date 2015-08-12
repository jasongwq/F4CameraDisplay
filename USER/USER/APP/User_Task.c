#include "lcd.h"
#include "math.h"
#include "sys_os.h"
#include "gpio.h"
#include "EasyTracer.h"
#include "USART.h"
#include "data_transfer.h"
#include "ov7670.h"

int Gray_Threshold_H = 256;
int Gray_Threshold_L = 180;

#define Result_Filter_NUM 20

//extern vu32 Lcd_Memory4[OV7670XP / OV7670XF][OV7670YP / OV7670YF / 32];
extern u8 Lcd_MemoryGraybit[];
u8 Lcd_MemoryGraybitLts[OV7670YP/OV7670YF*OV7670XP/OV7670XF];

int Result_Filter_Tmp[4][20];
char flag = 0;
RESULT result0, result1, result2, result3, result4, result5;

#define Gray_MAX 256
#define Gray_MIN 10


int task_Image_Processing(void)
{
    _SS
//    PID_ROL.P = 190;
//    PID_ROL.I = 50;
    Gray_Threshold_H = Gray_MAX; //激光 大于 阈值的 为 (1)//首次 值 取大 激光消失
    Gray_Threshold_L = PID_ROL.I; //坐标 小于 阈值的 为 (1)

    PD12_OUT;

    while (1)
    {
        WaitX(1);
        if (flag == 1)
        {
            int k, j, i;
            flag = 0;
//	        TFT_Window(0, 0, 48,32);
//					LCD_SetCursor(0, 0);
//          LCD_WriteRAM_Prepare();
//            for (i = 0; i < (OV7670XP / OV7670XF * OV7670YP / OV7670YF); ++i)
//            {
////                *(&Lcd_MemoryGraybitLts[0] + i) = *(&Lcd_MemoryGraybit[0] + i);
////								u16 tmp=Lcd_MemoryGraybit[i]<<7>>3;
////								LCD_WR_Data(tmp<<11|tmp<<6|tmp);
//							 LCD_WR_Data(0xffff);
//            }
            {
                for (k = 0; k < 24*32; k++)
                     LCD_WR_Data(0);
//                for (k = 0; k < OV7670XP / OV7670XF; k++)
//                    for (i = 0; i < OV7670YP / OV7670YF; i++);
//                        if (Lcd_MemoryGraybit[k * OV7670YP / OV7670YF + i])
//                            LCD_WR_Data(0);
//                        else
//                            LCD_WR_Data(0xffff);
            }
        }
    }
    _EE
}
const int Gray_ThresholdLDef = 140;//120;
const int Gray_ThresholdHDef = 256;
int task_test(void)
{
    _SS
    //WaitX(1000);
    Gray_Threshold_L = Gray_ThresholdLDef;
    Gray_Threshold_H = Gray_ThresholdHDef;
    printf("\r\n %3d", Gray_Threshold_L);
    while (1)
    {
        if (flag == 1)
        {
            WaitX(1000);
            if (Gray_Threshold_L++ > 141)//180)
                Gray_Threshold_L = Gray_ThresholdLDef;
            //printf("\r\n %3d", Gray_Threshold_L);
        }
    }
    _EE
}






