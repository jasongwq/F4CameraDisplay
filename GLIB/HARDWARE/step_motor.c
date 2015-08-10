#include "step_motor.h"
#include "GPIO.h"
#include "delay.h"

//A+红色   A-蓝色   B+绿色  B-黑色
//         A     B     C     D     E     F     G     H

// A       1     1     0     0     0     0     0     1
// A-      0     0     0     1     1     1     0     0
// B       0     1     1     1     0     0     0     0
// B-      0     0     0     0     0     1     1     1

// u8 phase[2][8] =
// {
//     {0x09, 0x08, 0x0a, 0x02, 0x06, 0x04, 0x05, 0x01},
//     {0x01, 0x05, 0x04, 0x06, 0x02, 0x0a, 0x08, 0x09}
// };


u16 step_speed = 1;
s16 motor_temp=0;
u8 dir=0;


void step_motor_Init(void)
{
 //   RCC->APB2ENR |= 1 << 2; //使能PORTa时钟
    GPIOA_Init(4, 3,PU);
    GPIOA_Init(1, 3,PU);
    //GPIOA_Init(5, 3,PU);
    //GPIOA_Init(7, 3,PU);

    //TIM5_Int_Init(83,71);
}
// void motor_step(void)//u8 dir)
// {

//     static u8 i;
//     if (motor_temp&&step_speed)
//     {
//         motor_temp--;//if(motor_temp>65500)motor_temp=0;
//         MOTOR0 = (phase[0][i] & 0X01);
//         MOTOR1 = (phase[0][i] & 0X02) >> 1;
//         MOTOR2 = (phase[0][i] & 0X04) >> 2;
//         MOTOR3 = (phase[0][i] & 0X08) >> 3;
//         //     delay_us(1600);   //1500
//         if (dir)i++;
//         else i--;
//         if (i > 100)i = 7;
//         else if (i > 7)i = 0;
// 		if(motor_temp==0)
// 			step_speed=0;
//     }
// }



