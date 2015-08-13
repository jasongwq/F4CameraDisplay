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


const int Gray_ThresholdLDef = 140;//120;
const int Gray_ThresholdHDef = 256;

#define Result_Filter_NUM 20

extern u8 Lcd_MemoryGraybit[];
u8 Lcd_MemoryGraybitLts[OV7670YP / OV7670YF * OV7670XP / OV7670XF];

char flag = 0;

#define Gray_MAX 256
#define Gray_MIN 10

void ImageLst(void)
{
    int i;
    for (i = 0; i < (OV7670XP / OV7670XF * OV7670YP / OV7670YF); ++i)
    {
        *(&Lcd_MemoryGraybitLts[0] + i) = *(&Lcd_MemoryGraybit[0] + i);
    }
}
void ImageFilter(void)
{
    int i, j;
    for (i = 0; i < OV7670XP / OV7670XF; i++)
        for (j = 2; j < OV7670YP / OV7670YF - 2; j++)//-2 防止超出数组边缘
        {
#define Lcd_MemoryGraybitLtsAround(a) Lcd_MemoryGraybitLts[i*(OV7670YP / OV7670YF)+j+(a)]
            Lcd_MemoryGraybitLtsAround(0) = (1 == (Lcd_MemoryGraybitLtsAround(-1) +
                                                   Lcd_MemoryGraybitLtsAround(0) +
                                                   Lcd_MemoryGraybitLtsAround(1) +
                                                   Lcd_MemoryGraybitLtsAround(-2) +
                                                   Lcd_MemoryGraybitLtsAround(2)
                                                  ) / 3);// ? 0 : 1;
#undef Lcd_MemoryGraybitLtsAround
        }
    for (j = 0; j < OV7670YP / OV7670YF; j++)
        for (i = 2; i < OV7670XP / OV7670XF - 2; i++)
        {
#define Lcd_MemoryGraybitLtsAround(a) Lcd_MemoryGraybitLts[(i+(a))*(OV7670YP / OV7670YF)+j]
            Lcd_MemoryGraybitLtsAround(0) = (1 == (Lcd_MemoryGraybitLtsAround(-1) +
                                                   Lcd_MemoryGraybitLtsAround(0) +
                                                   Lcd_MemoryGraybitLtsAround(1) +
                                                   Lcd_MemoryGraybitLtsAround(-2) +
                                                   Lcd_MemoryGraybitLtsAround(2)
                                                  ) / 3);// ? 0 : 1;
#undef Lcd_MemoryGraybitLtsAround
        }
}
void LCDImageDisplay(void)
{
    int k, i;
    {   //图像输出
        LCD_WriteRAM_Prepare();
        for (k = 0; k < OV7670XP / OV7670XF; k++)
            for (i = 0; i < OV7670YP / OV7670YF; i++)
                if (0 == Lcd_MemoryGraybitLts[k * OV7670YP / OV7670YF + i])
                    LCD_WR_Data(0);
                else
                    LCD_WR_Data(0xffff);//黑色
    }
}
void FindPoint(void)
{
//找点
    const int BigpointR = 50/OV7670XF; //要找的圆直径
    int BlackPointCountX = 0;
    int BlackPointCountY = 0;
    int BlackPointCountXMax = 0;
    int BlackPointCountYMax = 0;

    for (vu8 i = OV7670XP / OV7670XF / 2, j = 0; j < OV7670XP / OV7670XF; ++j, i = (j % 2) ? (i - j) : (i + j))
    {
        //printf("\r\n%d", i);
        for (int k = 0; k < OV7670YP / OV7670YF; k++)//从第一行找起 找连续的黑点
        {
            if (0 == Lcd_MemoryGraybitLts[i * OV7670YP / OV7670YF + k])//黑点
            {
                BlackPointCountY ++;
                if (BlackPointCountY > (BigpointR * 2)) //找到连续的黑点(Y轴上)
                {
                    BlackPointCountYMax = k - BlackPointCountY / 2;
                    {   //在Y黑线的中垂线上找X轴上的黑线
                        int BlackPointCountX1 = 0;
                        int BlackPointCountX2 = 0;
                        int q = 0;
                        for (q = i; q >= 0; q--)
                        {   //在Y黑线的中垂线上找X轴上的黑线
                            if (0 == Lcd_MemoryGraybitLts[q * OV7670YP / OV7670YF + BlackPointCountYMax])
                            {
                                BlackPointCountX1 ++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        for (vu8 q = i; q < OV7670XP / OV7670XF; q++)
                        {   //在Y黑线的中垂线上找X轴上的黑线
                            if (0 == Lcd_MemoryGraybitLts[q * OV7670YP / OV7670YF + BlackPointCountYMax])
                            {
                                BlackPointCountX2 ++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        BlackPointCountX = BlackPointCountX1 + BlackPointCountX2;
                        if (BlackPointCountX > (BigpointR * 2)) //找到连续的黑点(X轴上)
                        {
                            BlackPointCountXMax = i + BlackPointCountX2 / 2 - BlackPointCountX1 / 2;

#define Lcd_MemoryGraybitLtsAround(a,b) \
                                                 (Lcd_MemoryGraybitLts[(BlackPointCountXMax+(a))*OV7670YP / OV7670YF\
                                                 +BlackPointCountYMax+(b)])

                            int R = (int)(0.7 * BigpointR); //圆斜对角坐标
                            if ((0 == Lcd_MemoryGraybitLtsAround(+R, +R))
                                    && (0 == Lcd_MemoryGraybitLtsAround(+R, -R))
                                    && (0 == Lcd_MemoryGraybitLtsAround(-R, +R))
                                    && (0 == Lcd_MemoryGraybitLtsAround(-R, -R))
                               )
                            {
                                Draw_Circle(320 - OV7670YP / OV7670YF + BlackPointCountYMax , BlackPointCountXMax , BigpointR);
                                break;
                            }
                            else
                            {
                                BlackPointCountXMax = 0;
                            }
#undef Lcd_MemoryGraybitLtsAround
                        }
                        if (BlackPointCountXMax != 0)
                        {
                            break;
                        }
                        else
                        {
                            BlackPointCountX = 0;
                            BlackPointCountYMax = 0;
                        }
                    }
                    // Draw_Circle(320 - 32 + BlackPointCountYMax , i , 3);
                    // break;
                }
            }
            else
            {
                BlackPointCountY = 0;
            }
        }
        if (BlackPointCountYMax != 0)//如果找到了break
        {
            break;
        }
        else//否则清零计数 开始下一行
        {
            BlackPointCountY = 0;
        }
    }
}
int Ov7670FrameRate = 0;


int task_Image_Processing(void)
{
    _SS
//    PID_ROL.P = 190;
//    PID_ROL.I = 50;
    Gray_Threshold_H = Gray_MAX; //激光 大于 阈值的 为 (1)//首次 值 取大 激光消失
    Gray_Threshold_L = PID_ROL.I; //坐标 小于 阈值的 为 (1)
    Gray_Threshold_L = Gray_ThresholdLDef;
    Gray_Threshold_H = Gray_ThresholdHDef;
    PD12_OUT;

    while (1)
    {
        WaitX(1);
        if (flag == 1)
        {
            Ov7670FrameRate++;
            flag = 0;
            ImageLst();
            TFT_Window(OV7670XP / OV7670XF, 0, OV7670XP / OV7670XF, OV7670YP / OV7670YF);
            LCD_SetCursor(320 - OV7670YP / OV7670YF, OV7670XP / OV7670XF);
            LCDImageDisplay();

            ImageFilter();

            TFT_Window(0, 0, OV7670XP / OV7670XF, OV7670YP / OV7670YF);
            LCD_SetCursor(320 - OV7670YP / OV7670YF, 0);
            LCDImageDisplay();

            FindPoint();
        }
    }
    _EE
}

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






