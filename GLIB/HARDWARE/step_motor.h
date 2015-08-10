#ifndef __STEP_MOTOR_H
#define __STEP_MOTOR_H	 
#include "sys.h"

//LED端口定义
#define MOTOR0 PAout(4)// A+
#define MOTOR1 PAout(1)// A- 
// #define MOTOR2 PAout(5)// B+ 
// #define MOTOR3 PAout(7)// B+
#define MOTORdir MOTOR1
 

extern unsigned char phase[2][8];
extern u16 step_speed;
extern s16 motor_temp;
extern u8 dir;


void step_motor_Init(void);//初始化
//extern void motor_step(void);//u8 dir);
		 				    
#endif
