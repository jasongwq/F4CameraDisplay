#ifndef EASY_TRACER_H
#define EASY_TRACER_H
#include "sys.h"

//唯一的API，用户将识别条件写入Condition指向的结构体中，该函数将返回目标的x，y坐标和长宽
//返回1识别成功，返回1识别失败

u16 RGB_To_Gray(u16 C16);
extern int Point_ColorMatch(int x,int y);


extern int Gray_Threshold_H;
extern int Gray_Threshold_L;
#endif
