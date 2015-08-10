/*
    ����̳��Ǳˮ�������ˣ������ѧϰ����ƽ�⳵���������������ࡣ
�ڵ��Դ��������ݺ��˲�ʱд��һ�����ڹ��ߣ��������ĩ����
��һ�£����������ϣ���ܶԳ�ѧ��������������
    ���ܱȽϼ򵥣���Ҫ�ǽ��յ�Ƭ����������3���������ݣ���ͼ����ʾ��
������Ƭ�����ͼ����ֽڣ���������Ŀ�ġ���Ƭ�����͵�������0xFF��Ϊ
֡������־��ÿ����������5���ֽڱ�ʾ�������������ĺ�����
    û�о���ȫ����ԣ���������õ���bug�����Է������� :)

                                           СƤ2005
                                           2012.12.08
                                                                    */
/*******************************************************************/
#include "sys.h"
#include "usart.h"
#include "Balance_Show.h"

void uart_transmit(char ch)
{
#if EN_USART_
    while ((USART1->SR & 0X40) == 0); //ѭ������,ֱ���������
    USART1->DR = (char) ch;
#elif EN_USART2_
    while ((USART2->SR & 0X40) == 0)
        ;//ѭ������,ֱ���������
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


