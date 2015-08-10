#include "EasyTracer.h"
#define min3v(v1, v2, v3)   ((v1)>(v2)? ((v2)>(v3)?(v3):(v2)):((v1)>(v3)?(v3):(v1)))
#define max3v(v1, v2, v3)   ((v1)<(v2)? ((v2)<(v3)?(v3):(v2)):((v1)<(v3)?(v3):(v1)))

//读取RBG格式颜色，唯一需要移植的函数
#define GUI_ReadBit16Point LCD_ReadPoint
//#define GUI_ReadBit16Point Lcd_Memory_ReadPoint
extern unsigned short GUI_ReadBit16Point(unsigned short x, unsigned short y);
extern void LCD_DrawPoint(u16 x, u16 y);

static void ReadColor(unsigned int x, unsigned int y, COLOR_RGB *Rgb)
{
    u16 C16;
    C16 = GUI_ReadBit16Point(x, y);
    //LCD_DrawPoint(x,y);
    Rgb->red   =     (unsigned char)((C16 & 0xf800) >> 8);
    Rgb->green =     (unsigned char)((C16 & 0x07e0) >> 3);
    Rgb->blue  =     (unsigned char)((C16 & 0x001f) << 3);
}

//RGB转HSL
void RGBtoHSL(const COLOR_RGB *Rgb, COLOR_HSL *Hsl)
{
    int h, s, l, maxVal, minVal, difVal;
    int r  = Rgb->red;
    int g  = Rgb->green;
    int b  = Rgb->blue;

    maxVal = max3v(r, g, b);
    minVal = min3v(r, g, b);

    difVal = maxVal - minVal;

    //计算亮度
    l = (maxVal + minVal) * 240 / 255 / 2;

    if (maxVal == minVal) //若r=g=b
    {
        h = 0;
        s = 0;
    }
    else
    {
        //计算色调
        if (maxVal == r)
        {
            if (g >= b)
                h = 40 * (g - b) / (difVal);
            else
                h = 40 * (g - b) / (difVal) + 240;
        }
        else if (maxVal == g)
            h = 40 * (b - r) / (difVal) + 80;
        else if (maxVal == b)
            h = 40 * (r - g) / (difVal) + 160;
        //计算饱和度
        if (l == 0)
            s = 0;
        else if (l <= 120)
            s = (difVal) * 240 / (maxVal + minVal);
        else
            s = (difVal) * 240 / (511 - (maxVal + minVal));
    }
    Hsl->hue =        (unsigned char)(((h > 240) ? 240 : ((h < 0) ? 0 : h)));
    Hsl->saturation = (unsigned char)(((s > 240) ? 240 : ((s < 0) ? 0 : s)));
    Hsl->luminance =  (unsigned char)(((l > 240) ? 240 : ((l < 0) ? 0 : l)));
}

//匹配颜色
int ColorMatch(const COLOR_HSL *Hsl, const TARGET_CONDI *Condition)
{
    if (
        Hsl->hue        >   Condition->H_MIN &&
        Hsl->hue        <   Condition->H_MAX &&
        Hsl->saturation >   Condition->S_MIN &&
        Hsl->saturation <   Condition->S_MAX &&
        Hsl->luminance  >   Condition->L_MIN &&
        Hsl->luminance  <   Condition->L_MAX
    )
        return 1;
    else
        return 0;
}

//搜索腐蚀中心
static int SearchCentre(unsigned int *x, unsigned int *y, const TARGET_CONDI *Condition, const SEARCH_AREA *Area)
{
    unsigned int SpaceX, SpaceY, i, j, k, FailCount = 0;
    COLOR_RGB Rgb;
    COLOR_HSL Hsl;

    SpaceX = Condition->WIDTH_MIN / 3;//x步长
    SpaceY = Condition->HIGHT_MIN / 3;//y步长

    for (i = Area->Y_Start; i < Area->Y_End; i += SpaceY)//从 Y 起始位置到 终点位子 以 y 步长差
    {
        for (j = Area->X_Start; j < Area->X_End; j += SpaceX)//从 x 起始位置到 终点位子 以 x 步长差
        {
            FailCount = 0;
            for (k = 0; k < SpaceX + SpaceY; k++)
            {
                /*
                |****************
                |       |       |
                |       |       |
                |       |       |
                *****************
                |       |       |
                |       |       |
                |       |       |
                *****************/
                //以十字搜索
                if (k < SpaceX)
                    ReadColor(j + k, i + SpaceY / 2, &Rgb);
                else
                    ReadColor(j + SpaceX / 2, i + (k - SpaceX), &Rgb);
                RGBtoHSL(&Rgb, &Hsl);

                if (!ColorMatch(&Hsl, Condition))//如果不匹配
                    FailCount++;//不匹配次数
                if (FailCount > ((SpaceX + SpaceY) >> ALLOW_FAIL_PER))//容错率
                    break;
            }
            if (k == SpaceX + SpaceY)
            {
                *x = j + SpaceX / 2;
                *y = i + SpaceY / 2;
                return 1;
            }
        }
    }
    return 0;
}

//从腐蚀中心向外腐蚀，得到新的腐蚀中心
static int Corrode(unsigned int oldx, unsigned int oldy, const TARGET_CONDI *Condition, RESULT *Resu)
{
    unsigned int Xmin, Xmax, Ymin, Ymax, i, FailCount = 0;
    COLOR_RGB Rgb;
    COLOR_HSL Hsl;

    for (i = oldx; i > IMG_X; i--)
    {
        ReadColor(i, oldy, &Rgb);
        RGBtoHSL(&Rgb, &Hsl);
        if (!ColorMatch(&Hsl, Condition))
            FailCount++;
        if (FailCount > (((Condition->WIDTH_MIN + Condition->WIDTH_MAX) >> 2) >> ALLOW_FAIL_PER))
            break;
    }
    Xmin = i;
    FailCount = 0;

    for (i = oldx; i < IMG_X + IMG_W; i++)
    {
        ReadColor(i, oldy, &Rgb);
        RGBtoHSL(&Rgb, &Hsl);
        if (!ColorMatch(&Hsl, Condition))
            FailCount++;
        if (FailCount > (((Condition->WIDTH_MIN + Condition->WIDTH_MAX) >> 2) >> ALLOW_FAIL_PER))
            break;
    }
    Xmax = i;
    FailCount = 0;

    for (i = oldy; i > IMG_Y; i--)
    {
        ReadColor(oldx, i, &Rgb);
        RGBtoHSL(&Rgb, &Hsl);
        if (!ColorMatch(&Hsl, Condition))
            FailCount++;
        if (FailCount > (((Condition->HIGHT_MIN + Condition->HIGHT_MAX) >> 2) >> ALLOW_FAIL_PER))
            break;
    }
    Ymin = i;
    FailCount = 0;

    for (i = oldy; i < IMG_Y + IMG_H; i++)
    {
        ReadColor(oldx, i, &Rgb);
        RGBtoHSL(&Rgb, &Hsl);
        if (!ColorMatch(&Hsl, Condition))
            FailCount++;
        if (FailCount > (((Condition->HIGHT_MIN + Condition->HIGHT_MAX) >> 2) >> ALLOW_FAIL_PER))
            break;
    }
    Ymax = i;
    FailCount = 0;

    Resu->x = (Xmin + Xmax) / 2;
    Resu->y = (Ymin + Ymax) / 2;
    Resu->w = Xmax - Xmin;
    Resu->h = Ymax - Ymin;

    //如果 左右.上下尺寸 符合查找标准 返回 (1)
    if (((Xmax - Xmin) > (Condition->WIDTH_MIN)) && ((Ymax - Ymin) > (Condition->HIGHT_MIN)) && \
            ((Xmax - Xmin) < (Condition->WIDTH_MAX)) && ((Ymax - Ymin) < (Condition->HIGHT_MAX)) )
        return 1;
    else
        return 0;
}
int Find_Circle(const TARGET_CONDI *Condition, RESULT *Resu)
{
    //static
    unsigned int x0 = 0, y0 = 0; //, flag = 0;
    static SEARCH_AREA Area = {IMG_X, IMG_X + IMG_W, IMG_Y, IMG_Y + IMG_H};
    RESULT Result;
    COLOR_RGB Rgb;
    COLOR_HSL Hsl;
    //    unsigned int Xmin, Xmax, Ymin, Ymax;
    int break_N = 0;
    //    if (flag == 0)
    //    {
    for (int x = Area.X_Start, y = Area.Y_Start; (x0 + x < Area.X_End) && (y0 + y < Area.Y_End); x++, y++)
    {
        //            for (int y = Area.Y_Start; y0 + y < Area.Y_End; y++)
        //            {
        ReadColor(x0 + x, y0 + y, &Rgb);
        RGBtoHSL(&Rgb, &Hsl);
        if (ColorMatch(&Hsl, Condition))break_N++;
        if (break_N > 0)
        {
            //flag = 1;
            break_N = 0;
            x0 = x0 + x;
            y0 = y0 + y;
            break;
        }
    }
    //    }
    //    else
    //    {
    int i, j;
    //        int FailCount = 0;
    j = i = 0;
    for (;;)
    {
        for (;;)
        {
            ReadColor(x0 + (i++), y0 - (j), &Rgb);
            RGBtoHSL(&Rgb, &Hsl);
            if (!ColorMatch(&Hsl, Condition))
            {
                break_N++;
                i--;
            }
            else
                break_N = 0;
            if (break_N > 0 || (y0 - (j) == 0) || (x0 + (i) >= IMG_H))
            {
                break;
            }
        }
        j++;
        ReadColor(x0 + i, y0 - (j), &Rgb);
        RGBtoHSL(&Rgb, &Hsl);
        if (!ColorMatch(&Hsl, Condition))
        {
            break_N++;
        }
        else break_N = 0;
        if (break_N > 1 || (y0 - (j) >= IMG_W) || (x0 + (i) >= IMG_H))
        {
            break_N = 0;
            break;
        }
    }
    //        Xmax = x0 + i;
    //        Ymax = y0 + j;
    //        j = i = 1;
    //        for (;;)
    //        {
    //            for (;;)
    //            {
    //                ReadColor(x0 - (i++), y0 + (j), &Rgb);
    //                RGBtoHSL(&Rgb, &Hsl);
    //                if (!ColorMatch(&Hsl, Condition))break_N++;
    //                if (break_N > 2 || (y0 + (j) >= IMG_W) || (x0 - (i) == IMG_X))
    //                {
    //                    break_N = 0;
    //                    break;
    //                }
    //            }
    //            j++;
    //            if (!ColorMatch(&Hsl, Condition))break_N++;;
    //            if (break_N > 2 || (y0 + (j) >= IMG_W) || (x0 - (i) == IMG_X))
    //            {
    //                break_N = 0;
    //                break;
    //            }
    //        }
    //        Xmin = x0 - i;
    //        Ymin = y0;
    //        Resu->x = (Xmin + Xmax) / 2;
    //        Resu->y = (Xmin + Xmax) / 2;
    //        Resu->w = (-Xmin + Xmax);
    //        Resu->h = (-Ymin + Ymax);
    //
    //    }
    //      flag = 0;
    return 1;
}

//唯一的API，用户将识别条件写入Condition指向的结构体中，该函数将返回目标的x，y坐标和长宽
//返回1识别成功，返回1识别失败
int Trace(const TARGET_CONDI *Condition, RESULT *Resu)
{
    unsigned int i;
    static unsigned int x0, y0, flag = 0;
    static SEARCH_AREA Area = {IMG_X, IMG_X + IMG_W, IMG_Y, IMG_Y + IMG_H};
    RESULT Result;

    if (flag == 0)//首次进入
    {
        //从上次迭代地点寻找
        if (SearchCentre(&x0, &y0, Condition, &Area))//寻找腐蚀中心
            flag = 1;//已找到
        else//没找着
        {
            //从头找起
            Area.X_Start = IMG_X ;
            Area.X_End  = IMG_X + IMG_W;
            Area.Y_Start = IMG_Y ;
            Area.Y_End  = IMG_Y + IMG_H;

            if (SearchCentre(&x0, &y0, Condition, &Area))//再次寻找
            {
                flag = 0;
                return 0;//退出
            }
        }
    }
    Result.x = x0;
    Result.y = y0;

    //多次迭代
    for (i = 0; i < ITERATE_NUM; i++)
        Corrode(Result.x, Result.y, Condition, &Result);//从腐蚀中心向外腐蚀，得到新的腐蚀中心

    //从腐蚀中心向外腐蚀，得到新的腐蚀中心
    if (Corrode(Result.x, Result.y, Condition, &Result))
    {
        x0 = Result.x;
        y0 = Result.y;
        Resu->x = Result.x;
        Resu->y = Result.y;
        Resu->w = Result.w;
        Resu->h = Result.h;
        flag = 1;

        Area.X_Start = Result.x - ((Result.w) >> 1);
        Area.X_End  = Result.x + ((Result.w) >> 1);
        Area.Y_Start = Result.y - ((Result.h) >> 1);
        Area.Y_End  = Result.y + ((Result.h) >> 1);
        return 1;
    }
    else
    {
        flag = 0;
        return 0;
    }
}


//输出 x y 点的 HSL 值 存放于 Point_h, Point_s, Point_l; 中
int Point_h, Point_s, Point_l;
void Point_HSL_lPrintf(u16 x, u16 y)
{
    COLOR_RGB Rgb;
    COLOR_HSL Hsl;
    ReadColor(x, y, &Rgb);
    RGBtoHSL(&Rgb, &Hsl);
    Point_h = Hsl.hue;
    Point_l = Hsl.luminance;
    Point_s = Hsl.saturation;
}
//输入RGB返回0(1)
char RGB_To_Two(u16 C16, const TARGET_CONDI *Condition)
{
    COLOR_RGB Rgb;
    COLOR_HSL Hsl;

    Rgb.red   =     (unsigned char)((C16 & 0xf800) >> 8);
    Rgb.green =     (unsigned char)((C16 & 0x07e0) >> 3);
    Rgb.blue  =     (unsigned char)((C16 & 0x001f) << 3);

    RGBtoHSL(&Rgb, &Hsl);
    return ColorMatch(&Hsl, Condition);
}