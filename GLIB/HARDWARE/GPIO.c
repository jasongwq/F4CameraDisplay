#include "GPIO.h"


void My_GPIO_Init(GPIO_TypeDef *GPIOx, u16 pin, u8 mode)
{
    GPIO_InitTypeDef  GPIO_InitStructure;

    if (GPIOx == GPIOA)
    {
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    }
    else if (GPIOx == GPIOB)
    {
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    }
    else if (GPIOx == GPIOC)
    {
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    }
    else if (GPIOx == GPIOD)
    {
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    }
    else if (GPIOx == GPIOE)
    {
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
    }
    else if (GPIOx == GPIOF)
    {
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
    }
    else if (GPIOx == GPIOG)
    {
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);
    }
    else if (GPIOx == GPIOH)
    {
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH, ENABLE);
    }
    else if (GPIOx == GPIOI)
    {
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOI, ENABLE);
    }
    else {}

    if (mode == 1)
    {
        GPIO_InitStructure.GPIO_Pin = pin;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;      // 0x01
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;     // 0x00
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;       // 0x01
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; // 0x03
        GPIO_Init(GPIOx, &GPIO_InitStructure);
    }
    else if (mode == 0) // 默认
    {
        GPIO_InitStructure.GPIO_Pin = pin;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
        GPIO_Init(GPIOx, &GPIO_InitStructure);
    }

}
