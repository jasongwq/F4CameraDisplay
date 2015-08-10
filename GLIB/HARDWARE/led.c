#include "led.h"
//////////////////////////////////////////////////////////////////////////////////
//初始化PB5和PE5为输出口.并使能这两个口的时钟
//LED IO初始化
void LED_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOD, ENABLE); //使能PB,PE端口时钟

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;               //LED0-->PB.5 端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;        //推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;       //IO口速度为50MHz
    GPIO_Init(GPIOB, &GPIO_InitStructure);                  //根据设定参数初始化GPIOB.5

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_6;              //LED1-->PE.5 端口配置, 推挽输出
    GPIO_Init(GPIOD, &GPIO_InitStructure);                  //推挽输出 ，IO口速度为50MHz
		LED1=1;
		LED2=1;
		LED3=1;
}
