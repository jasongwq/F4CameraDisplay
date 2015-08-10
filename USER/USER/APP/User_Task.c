#include "lcd.h"
#include "math.h"
#include "sys_os.h"
#include "gpio.h"
#include "EasyTracer.h"
#include "USART.h"
#include "data_transfer.h"

#define Result_Filter_NUM 20

extern vu32 Lcd_Memory4[240][320 / 32];
static int Trace_run = -39;//-39 重测//80
int Result_Filter_Tmp[4][20];
char flag = 0;
RESULT result0, result1, result2, result3, result4, result5;
vu32 Lcd_Memory5[240][320 / 32];


TARGET_CONDI traget0 =
{
    /*目标最小-最大色调  */ 20, 200,
    /*目标最小-最大饱和度*/ 0, 30,
    /*目标最小-最大亮度  */ 0, 100,
    /*目标最小宽度-高度  */ 4, 4,
    /*目标最大宽度-高度  */ 15, 15,
    /*图片x-y坐标        */ 0, 0,
    /*图片宽度-高度      */ 160, 120
};
TARGET_CONDI traget5 =
{
    /*目标最小-最大色调  */ 20, 200,
    /*目标最小-最大饱和度*/ 0, 30,
    /*目标最小-最大亮度  */ 0, 100,
    /*目标最小宽度-高度  */ 4, 4,
    /*目标最大宽度-高度  */ 15, 15,
    /*图片x-y坐标        */ 100, 80,
    /*图片宽度-高度      */ 160, 120
};
TARGET_CONDI traget1 =
{
    /*目标最小-最大色调  */ 20, 200,
    /*目标最小-最大饱和度*/ 0, 30,
    /*目标最小-最大亮度  */ 0, 100,
    /*目标最小宽度-高度  */ 4, 4,
    /*目标最大宽度-高度  */ 15, 15,
    /*图片x-y坐标        */ 160, 0,
    /*图片宽度-高度      */ 160, 120
};
TARGET_CONDI traget2 =
{
    /*目标最小-最大色调  */ 20, 200,
    /*目标最小-最大饱和度*/ 0, 30,
    /*目标最小-最大亮度  */ 0, 100,
    /*目标最小宽度-高度  */ 4, 4,
    /*目标最大宽度-高度  */ 15, 15,
    /*图片x-y坐标        */ 0, 120,
    /*图片宽度-高度      */ 160, 120

};
TARGET_CONDI traget3 =
{
    /*目标最小-最大色调  */ 20, 200,
    /*目标最小-最大饱和度*/ 0, 30,
    /*目标最小-最大亮度  */ 0, 100,
    /*目标最小宽度-高度  */ 4, 4,
    /*目标最大宽度-高度  */ 15, 15,
    /*图片x-y坐标        */ 160, 120,
    /*图片宽度-高度      */ 160, 120
};
TARGET_CONDI traget4 =
{
    /*目标最小-最大色调  */ 20, 200,
    /*目标最小-最大饱和度*/ 0, 30,
    /*目标最小-最大亮度  */ 0, 100,
    /*目标最小宽度-高度  */ 2, 2,
    /*目标最大宽度-高度  */ 10, 10,
    /*图片x-y坐标        */ 0, 0,
    /*图片宽度-高度      */ 320, 240
};

int Point_ColorMatch(int x, int y)
{
    LCD_Fast_DrawPoint(x, y, BLUE);
    if (Read_Bit(Lcd_Memory5[y][x / 32], 31 - (x % 32)))
        return 1;
    else
        return 0;
}
void Trace_run1(RESULT *Resu, int Trace_run)
{
    LCD_DrawRectangle(Resu->x - Resu->w / 2, Resu->y - Resu->h / 2, Resu->x + Resu->w / 2, Resu->y + Resu->h / 2);
    Result_Filter_Tmp[0][Trace_run % 20] = Resu->x;
    Result_Filter_Tmp[1][Trace_run % 20] = Resu->y;
    Result_Filter_Tmp[2][Trace_run % 20] = Resu->w;
    Result_Filter_Tmp[3][Trace_run % 20] = Resu->h;
}
void Trace_run2(RESULT *Resu)
{
    int temp = 0;
    for (int i = 0; i < 20; i++)
        temp += Result_Filter_Tmp[0][i];
    Resu->x = temp / 20;
    temp = 0;
    for (int i = 0; i < 20; i++)
        temp += Result_Filter_Tmp[1][i];
    Resu->y = temp / 20;
    temp = 0;
    for (int i = 0; i < 20; i++)
        temp += Result_Filter_Tmp[2][i];
    Resu->w = temp / 20;
    temp = 0;
    for (int i = 0; i < 20; i++)
        temp += Result_Filter_Tmp[3][i];
    Resu->h = temp / 20;
}

//判断一个点是否在 圆内 并指出 在那个八分圆上
/***\
 8|1
  |
          |
          |
7_________|__________2
6         |          3
          |
          |
          |
         5|4
        \***/

//(x,y):中心点
//r    :半径
int  Impact_Point = 0;
int  Set_Impact_Point = 0;

void Judge_Circle(u16 x0, u16 y0, u8 r, int cr)
{
    int a, b;
    int di;
    a = 0; b = r;
    di = 3 - (r << 1);       //判断下个点位置的标志
    while (a <= b)
    {
        LCD_DrawPoint(x0 + a, y0 - b);        //5//1
        LCD_DrawPoint(x0 + b, y0 - a);        //0//2
        LCD_DrawPoint(x0 + b, y0 + a);        //4//3
        LCD_DrawPoint(x0 + a, y0 + b);        //6//4
        LCD_DrawPoint(x0 - a, y0 + b);        //1//5
        LCD_DrawPoint(x0 - b, y0 + a);        //3//6
        LCD_DrawPoint(x0 - b, y0 - a);        //7//7
        LCD_DrawPoint(x0 - a, y0 - b);        //2//8
        if (result4.x == x0 + a)
        {
            if ((result4.y >= y0 - b) && (result4.y <=y0 + b))
                Impact_Point = cr;
        }
        else if (result4.x == x0 - a)
        {
            if ((result4.y >= y0 - b) && (result4.y <=y0 + b))
                Impact_Point = cr;
        }
        else if (result4.x == x0 - b)
        {
            if ((result4.y >= y0 - a) && (result4.y <=y0 + a))
                Impact_Point = cr;
        }
        else if (result4.x == x0 + b)
        {
            if ((result4.y >= y0 - a) && (result4.y <=y0 + a))
                Impact_Point = cr;
        }
        a++;
        //使用Bresenham算法画圆
        if (di < 0)di += 4 * a + 6;
        else
        {
            di += 10 + 4 * (a - b);
            b--;
        }
    }
}
//激光点在 圆内的坐标
      /*|*\
				+
        |
-- + ------- - --
        |
				-
				|
			\*|*/
int Point_X = 0;
int Point_Y = 0;
int Point_Calc = 0;
//目的点在 圆内的坐标
        
      /*|*\
				+
        |
-- + ------- - --
        |
				-
				|
			\*|*/
int Set_x = 0;
int Set_y = 0;
void Calc_SetPoint_X_Y(int Circle_R)
{
    if (Set_Impact_Point != 0 )
    {
        switch (Set_Impact_Point % 10)
        {
        case 0:
            Set_x = 0;
            Set_y = -((1 + 2 * (10 - Set_Impact_Point / 10)) * Circle_R / 6 / 2);
            break;
        case 1:
            Set_x = ((1 + 2 * (10 - Set_Impact_Point / 10)) * Circle_R / 6 / 2 * 707 / 1000);
            Set_y = -Set_x;
            break;
        case 2:
            Set_x = ((1 + 2 * (10 - Set_Impact_Point / 10)) * Circle_R / 6 / 2);
            Set_y = 0;
            break;
        case 3:
            Set_x = ((1 + 2 * (10 - Set_Impact_Point / 10)) * Circle_R / 6 / 2 * 707 / 1000);
            Set_y = Set_x;
            break;
        case 4:
            Set_x = 0;
            Set_y = ((1 + 2 * (10 - Set_Impact_Point / 10)) * Circle_R / 6 / 2);
            break;
        case 5:
            Set_x = -((1 + 2 * (10 - Set_Impact_Point / 10)) * Circle_R / 6 / 2 * 707 / 1000);
            Set_y = -Set_x;
            break;
        case 6:
            Set_x = -((1 + 2 * (10 - Set_Impact_Point / 10)) * Circle_R / 6 / 2);
            Set_y = 0;
            break;
        case 7:
            Set_x = -((1 + 2 * (10 - Set_Impact_Point / 10)) * Circle_R / 6 / 2 * 707 / 1000);
            Set_y = Set_x;
            break;
        }

    }
}
#define Gray_MAX 250
#define Gray_MIN 10


int task_Image_Processing(void)
{
    _SS
    PID_ROL.P = 190;
    PID_ROL.I = 90;
    PID_PIT.D = 100; //圆心
		PID_YAW.P=666;//圆心舵机值X
		PID_YAW.I=379;//Y
    Gray_Threshold_H = Gray_MAX; //激光 大于 阈值的 为 (1)//首次 值 取大 激光消失
    Gray_Threshold_L = PID_ROL.I; //坐标 小于 阈值的 为 (1)

    PD12_OUT;

    while (1)
    {
        static int Circle_R, Circle_X, Circle_Y;
        WaitX(200);
        if (flag == 1)
        {
            vs32 k, j, i;
            flag = 0;
            for (i = 0; i < 2400; ++i)*(&Lcd_Memory5[0][0] + i) = *(&Lcd_Memory4[0][0] + i);
            if (Trace_run < 100)
            {
                LCD_SetCursor(0, 0);
                LCD_WriteRAM_Prepare();
                for (k = 0; k < 240; k++)
                    for (i = 0; i < 10; i++)
                        for (j = 31; j >= 0; j--)
                            if (Read_Bit(Lcd_Memory5[k][i], j))
                                LCD_WR_Data(0);
                            else
                                LCD_WR_Data(0xffff);

                switch (Trace_run)
                {
                case -20: Point_Trace_Init(&traget5);
                    break;
                case 0:  Point_Trace_Init(&traget0);
                    Trace_run2(&result5);
                    break;
                case 20: Point_Trace_Init(&traget1);
                    Trace_run2(&result0);
                    result0.x += result0.w / 2;
                    result0.y += result0.h / 2;
                    break;
                case 40: Point_Trace_Init(&traget2);
                    Trace_run2(&result1);
                    result1.x -= result1.w / 2;
                    result1.y += result1.h / 2;
                    break;
                case 60: Point_Trace_Init(&traget3);
                    Trace_run2(&result2);
                    result2.x += result2.w / 2;
                    result2.y -= result2.h / 2;
                    break;
                case 80: Point_Trace_Init(&traget4); Gray_Threshold_L = Gray_MIN; Gray_Threshold_H = PID_ROL.P; Trace_run++;//激光 大于 阈值的 为 (1)
                    Trace_run2(&result3);
                    result3.x -= result3.w / 2;
                    result3.y -= result3.h / 2;
                    
                    //                    Circle_X = ((result0.x + result2.x) / 2 + (result1.x + result3.x) / 2) / 2;
                    //                    Circle_Y = ((result0.y + result1.y) / 2 + (result2.y + result3.y) / 2) / 2;
///*
                    Circle_R = sqrtf(((((result1.x - result0.x) + (result3.x - result2.x)) / 2) * (((result1.x - result0.x) + (result3.x - result2.x)) / 2)) //X^2
                                     + ((((result2.y - result0.y) + (result3.y - result1.y)) / 2) * (((result2.y - result0.y) + (result3.y - result1.y)) / 2))//Y^2
                                    ) / 2;
										Circle_X = result5.x;
                    Circle_Y = result5.y;
//*/										
//										Circle_R = 0x64;
//                    Circle_X = 0xAF;
//                    Circle_Y = 0x70;
                    if (Circle_X - Circle_R > 0)traget4.IMG_X = Circle_X - Circle_R; else traget4.IMG_X = 0;
                    if (Circle_Y - Circle_R > 0)traget4.IMG_Y = Circle_Y - Circle_R; else traget4.IMG_Y = 0;
                    traget4.IMG_W = Circle_R * 2;
                    traget4.IMG_H = Circle_R * 2;
                    PID_PIT.P = 666;
                    PID_PIT.I = 370;
                    PID_ROL.D = 1;
                    Send_PID1 = 2;
                    break;
                case 81: Trace_run = 100; //激光 大于 阈值的 为 (1)
                    break;
                }
                switch (Trace_run / 20)
                {
                case -1:
                    if (Point_Trace(&traget5, &result5))
                    {
                        Trace_run1(&result5, Trace_run);
                        Trace_run++;
                    } break;
                case 0:
                    if (Point_Trace(&traget0, &result0))
                    {
                        Trace_run1(&result0, (Trace_run + 19) / 2);
                        //printf("\r\n0:%3d,%3d,%3d", result0.x, result0.y, Trace_run);printf(" %3d,%3d", Result_Filter_Tmp[0][Trace_run % 20], Result_Filter_Tmp[1][Trace_run % 20]);
                        Trace_run += 2;
                        if (Trace_run == 21)Trace_run = 20;
                    }
                    break;
                case 1:
                    if (Point_Trace(&traget1, &result1))
                    {
                        Trace_run1(&result1, Trace_run);
                        //printf("\r\n1:%3d,%3d,%3d", result1.x, result1.y, Trace_run);printf(" %3d,%3d", Result_Filter_Tmp[0][Trace_run % 20], Result_Filter_Tmp[1][Trace_run % 20]);
                        Trace_run++;
                    }
                    break;
                case 2:
                    if (Point_Trace(&traget2, &result2))
                    {
                        Trace_run1(&result2, Trace_run);
                        //printf("\r\n2:%3d,%3d,%3d", result2.x, result2.y, Trace_run);printf(" %3d,%3d", Result_Filter_Tmp[0][Trace_run % 20], Result_Filter_Tmp[1][Trace_run % 20]);
                        Trace_run++;
                    }
                    break;
                case 3:
                    if (Point_Trace(&traget3, &result3))
                    {
                        Trace_run1(&result3, Trace_run);
                        //printf("\r\n3:%3d,%3d,%3d", result3.x, result3.y, Trace_run);printf(" %3d,%3d", Result_Filter_Tmp[0][Trace_run % 20], Result_Filter_Tmp[1][Trace_run % 20]);
                        Trace_run++;
                    }
                    break;
                case 4:
                    break;
                }
            }
            else
            {
                if (Point_Trace(&traget4, &result4))
                {
                    //清楚
                    LCD_SetCursor(0, 0);
                    LCD_WriteRAM_Prepare();
                    for (k = 0; k < 240; k++)
                        for (i = 0; i < 10; i++)
                            for (j = 31; j >= 0; j--)
                                LCD_WR_Data(0xffff);
                    //画框
                    LCD_DrawRectangle(result4.x - result4.w / 2, result4.y - result4.h / 2, result4.x + result4.w / 2, result4.y + result4.h / 2);

                    //横线
                    LCD_DrawLine(result0.x, result0.y, result3.x, result3.y);
                    LCD_DrawLine(result1.x, result1.y, result2.x, result2.y);
                    //竖线
                    LCD_DrawLine((result0.x + result2.x) / 2, (result0.y + result2.y) / 2, (result1.x + result3.x) / 2, (result1.y + result3.y) / 2);
                    LCD_DrawLine((result0.x + result1.x) / 2, (result0.y + result1.y) / 2, (result2.x + result3.x) / 2, (result2.y + result3.y) / 2);
                    //圆
                    //画圆 并 判断 环数
                    Impact_Point = 0;
                    Judge_Circle(Circle_X, Circle_Y, Circle_R        , 50); //r30
                    Judge_Circle(Circle_X, Circle_Y, Circle_R * 5 / 6, 60); //r25
                    Judge_Circle(Circle_X, Circle_Y, Circle_R * 4 / 6, 70); //r20
                    Judge_Circle(Circle_X, Circle_Y, Circle_R * 3 / 6, 80); //r15
                    Judge_Circle(Circle_X, Circle_Y, Circle_R * 2 / 6, 90); //r10
                    Judge_Circle(Circle_X, Circle_Y, Circle_R     / 6, 100);//r05
                    //判断位置
                    //如果 未脱靶 即 Impact_Point!=0
                    //判断 激光方位
                    if (Impact_Point != 0)//
                    {
                        Point_X = result4.x - Circle_X;
                        Point_Y = result4.y - Circle_Y;
                        if (Point_Y < 0)
                        {
                            Point_Calc = Point_X * 1000 / Point_Y;
                            if (Point_Calc > 2414)
                                Impact_Point += 6;
                            else if (Point_Calc > 414)
                                Impact_Point += 7;
                            else if (Point_Calc > -414)
                                Impact_Point += 0;
                            else if (Point_Calc > -2414)
                                Impact_Point += 1;
                            else
                                Impact_Point += 2;
                        }
                        else if (Point_Y > 0)
                        {
                            Point_Calc = Point_X * 1000 / Point_Y;
                            if (Point_Calc > 2414)
                                Impact_Point += 2;
                            else if (Point_Calc > 414)
                                Impact_Point += 3;
                            else if (Point_Calc > -414)
                                Impact_Point += 4;
                            else if (Point_Calc > -2414)
                                Impact_Point += 5;
                            else
                                Impact_Point += 6;
                        }
                        else
                        {
                            if (Point_X > 0)
                                Impact_Point += 2;
                            else if (Point_X < 0)
                                Impact_Point += 6;
                            else
                                Impact_Point += 9;
                        }
                    }
                    LCD_ShowNum(5, 5, Impact_Point, 3, 16);

                    
                    Calc_SetPoint_X_Y(Circle_R);

                    // PID_PIT.P=666;
                    // PID_PIT.I=370;
                    // PID_ROL.D=1;
                }
                else
                {
                    LCD_ShowNum(5, 5, 0, 3, 16);
                }
            }
        }
    }
    _EE
}

void control(void)
{
    //积分
    static int Adjust_x_i = 0;
    static int Adjust_y_i = 0;
    static int flag_x_ok = 0;
    static int flag_y_ok = 0;
		if(Set_Impact_Point != PID_PIT.D)
		{
		Adjust_x_i=0;
		Adjust_y_i=0;
		
		Set_Impact_Point = PID_PIT.D;
    }
		if (Impact_Point != 0&&Set_Impact_Point!=0)
		{
        if (Set_Impact_Point != Impact_Point)
        {
            if (Point_X - Set_x > 3)
            {
                Adjust_x_i += 1;
            }
            else if (Point_X - Set_x < -3)
            {
                Adjust_x_i -= 1;
            }
            else
            {
                flag_x_ok = 1; //ok
                //              Adjust_x_i=0;
            }
            if (Point_Y - Set_y > 3)
            {
                Adjust_y_i += 1;
            }
            else if (Point_Y - Set_y < -3)
            {
                Adjust_y_i -= 1;
            }
            else
            {
                flag_y_ok = 1;
                //              Adjust_y_i=0;
            }
            if (!flag_x_ok || !flag_y_ok)
            {
                PID_PIT.P = PID_YAW.P -Set_x*20/100 + Adjust_x_i;
                PID_PIT.I = PID_YAW.I -Set_y*20/100 + Adjust_y_i;
                PID_ROL.D = 1;
                Send_PID1 = 2;
            }
            else
            {
                flag_x_ok = flag_y_ok = 0;
            }
        }
		}

}

int task_test(void)
{
    _SS
    Gray_Threshold_H = 190;//16:56分在200 出点亮度 较高时 180杂点亮度 较低时175杂点 //激光 大于 阈值的 为 (1)//首次 值 取大 激光消失
    Gray_Threshold_L = 80; //65出现定位点 115时 定位点 杂点 淹没 定位点//坐标 小于 阈值的 为 (1)
    while (1)
    {
        if (flag == 1)
        {
            WaitX(1000);
            //WaitX(2000);
            if (Gray_Threshold_L++ > 210)Gray_Threshold_H = 210;
            printf("\r\n %3d", Gray_Threshold_L);
        }
    }
    _EE
}






