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
u8 Lcd_MemoryGraybitLts[OV7670YP / OV7670YF * OV7670XP / OV7670XF];

int Result_Filter_Tmp[4][20];
char flag = 0;

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
            for (i = 0; i < (OV7670XP / OV7670XF * OV7670YP / OV7670YF); ++i)
            {
                *(&Lcd_MemoryGraybitLts[0] + i) = *(&Lcd_MemoryGraybit[0] + i);
            }
            {
                LCD_SetCursor(320 - 32, 0);
                LCD_WriteRAM_Prepare();
                for (k = 0; k < OV7670XP / OV7670XF; k++)
                    for (i = 0; i < OV7670YP / OV7670YF; i++)
                        if (0 == Lcd_MemoryGraybitLts[k * OV7670YP / OV7670YF + i])
                            LCD_WR_Data(0);
                        else
                            LCD_WR_Data(0xffff);
                {
                    int BlackPointCount = 0;
                    int BlackPointCountMax = 0;
                    for (k = 0; k < OV7670XP / OV7670XF; k++)//从第一行找起 找连续的黑点
                    {
                        for (i = 0; i < OV7670YP / OV7670YF; i++)
                        {
                            if (0 == Lcd_MemoryGraybitLts[k * OV7670YP / OV7670YF + i])
                            {
                                BlackPointCount ++;
                                if (BlackPointCount > 5)//找到连续的黑点
                                {
                                    BlackPointCountMax = i - BlackPointCount / 2;
                                    Draw_Circle(320 - 32 + BlackPointCountMax , k , 3);
                                }
                            }
                            else
                            {
                                BlackPointCount = 0;
                            }
                        }
                        if (BlackPointCountMax != 0)//如果找到了break
                        {
                            break;
                        }
                        else//否则清零计数 开始下一行
                        {
                            BlackPointCount = 0;
                        }
                    }
                }
                //Draw_Circle(320 - 32 + 5, 5, 3);
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






