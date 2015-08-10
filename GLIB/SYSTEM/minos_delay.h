#ifndef __MINOS_DELAY_H
#define __MINOS_DELAY_H
#include "sys.h"
void delay_init(void);
void delay_ms(u16 nms);
void delay_us(u32 nus);
int SysTick_Clock(void);

#endif
