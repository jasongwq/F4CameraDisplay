/*
    在论坛上潜水几个月了，跟大家学习两轮平衡车的制作，获益良多。
在调试传感器数据和滤波时写了一个串口工具，趁这个周末整理
了一下，共享出来，希望能对初学者们有所帮助。
    功能比较简单，主要是接收单片机发送来的3个整型数据，以图形显示。
可以向单片机发送几个字节，用作控制目的。单片机发送的数据以0xFF作为
帧结束标志，每个整型数以5个字节表示，具体参照下面的函数。
    没有经过全面测试，如果你想用但有bug，可以反馈给我 :)

                                           小皮2005
                                           2012.12.08
                                                                    */
/*******************************************************************/
#include "sys.h"
#include "usart.h"
#include "Balance_Show.h"

void uart_transmit(char ch)
{
#if EN_USART_
    while ((USART1->SR & 0X40) == 0); //循环发送,直到发送完毕
    USART1->DR = (char) ch;
#elif EN_USART2_
    while ((USART2->SR & 0X40) == 0)
        ;//循环发送,直到发送完毕
    USART2->DR = (char) ch;
#endif
}

void SeriPush2Bytes(int value)
{
    unsigned char t_char;
    if (value < 0)
    {
        value = -value;
        uart_transmit(0xf0);
    }
    else
			uart_transmit(0xf5);
    t_char = value / 256;
    if (t_char > 127)
			uart_transmit(0x80);
    else
			uart_transmit(0x00);
    uart_transmit(t_char & 0x7f);
    t_char = value % 256;
    if (t_char > 127)
			uart_transmit(0x80);
    else
			uart_transmit(0x00);
    uart_transmit(t_char & 0x7f);
}



void Print_Balance(int data1, int data2, int data3)
{
    SeriPush2Bytes(data1);
    SeriPush2Bytes(data2);
    SeriPush2Bytes(data3);
    uart_transmit(0xff);
}


