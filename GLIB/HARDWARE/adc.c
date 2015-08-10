#include "adc.h"
#include "delay.h"
#include "G32_timer.h"
#include "stm32_config.h"

/*ADC ����*/
/********************************************************************************
ADCʹ��DMA ����������
����ADת����AD ÿ��ת����ɺ���DMA ��������ת��ֵ��ADC���ݼĴ�����ADC_DR��
��ת�Ƶ�����ADC_ConvertedValue����DMA��ɺ���main��ʹ�õģ�����ADC ת���Ľ����
********************************************************************************/

#define ADC1_DR_Address    ((u32)0x40012400+0x4c)   //�궨��   ADC1 ת���󱣴����ݵĵ�ַ
//0x4c        ADC1_DR �ľ����ַ      STM32�ο��ֲ� P178
//0x40012400  ADC �ļĴ����׵�ַ      STM32�ο��ֲ� P28
__IO uint16_t ADC_ConvertedValue[32];  //����һ������

/********************************************************************************************
������������������ݵ���˼��
core_cm3.h ������ __IO��
#defines __IO volatile     !< defines 'read / write' permissions
volatile ��Ϊָ��ؼ���,ȷ������ָ�������������Ż���ʡ��,��Ҫ��ÿ��ֱ�Ӷ�ֵ.
stdint.h   ������ uint16_t��
typedef  unsigned short int  uint16_t;
ADC_ConvertedValue   ������
********************************************************************************************/
/*
* ��������ADC1_GPIO_Config
* ����  ��ʹ��ADC1��DMA1��ʱ�ӣ���ʼ��PC.01
* ����  : ��
* ���  ����
* ����  ���ڲ�����
*/
static void ADC1_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure; //����ṹ��
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;     //Ҫ���õ�PIN
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; //����IO Ϊ ģ������
//    GPIO_Init(GPIOA, &GPIO_InitStructure);        //����IO

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

/* ��������ADC1_Mode_Config
* ����  ������ADC1�Ĺ���ģʽΪMDAģʽ
* ����  : ��
* ���  ����
* ����  ���ڲ�����
*/
static void ADC1_Mode_Config(void)
{
    ADC_InitTypeDef ADC_InitStructure;
    DMA_InitTypeDef DMA_InitStructure;        //���� DMA �ṹ��
    NVIC_InitTypeDef NVIC_InitStructure;

    /***********************DMA*********************************/
    /* Enable DMA clock */                            //��DMA ʱ��
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);//ע������ʱ����

    /* DMA channel1 configuration */
    DMA_DeInit(DMA1_Channel1); //��DMA ͨ��1�Ĵ��� ��λ          ADC DMA ��Ӧ ͨ��1

    DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_Address;         //DMA�������ַ  ��ADC��ַ
    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)ADC_ConvertedValue;    //DMA�ڴ����ַ  ��Ҫ������ݵĵ�ַ
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;  //������Ϊ���ݴ������Դ
    DMA_InitStructure.DMA_BufferSize = 32;              //DMA �����С
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;//�����ַ����
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;         //DMA_MemoryInc_Disable�ڴ��ַ���� DMA_MemoryInc_Enable�ڴ��ַ�ı�
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord; //�������ݿ��16λ
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;         //�ڴ����ݿ��
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;			//DMA_Mode_Circular;//������ѭ������ģ?      DMA_Mode_Normal
		DMA_InitStructure.DMA_Priority = DMA_Priority_High; //�趨DMAͨ��X �����ȼ�
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;        //DMA ͨ��X û������ �ڴ浽�ڴ洫��
    DMA_Init(DMA1_Channel1, &DMA_InitStructure);        //����DMA ͨ��1 ����
    /*Enable DMA �ж�*/

    /* Enable DMA channel1 IRQ Channel */
    NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    DMA_ClearFlag(DMA1_FLAG_TC1);
    DMA_ClearITPendingBit(DMA1_IT_GL1);

    DMA_ITConfig(DMA1_Channel1, DMA_IT_TC, ENABLE);        //DMA

    /* Enable DMA channel1 */
    DMA_Cmd(DMA1_Channel1, ENABLE);
    /***********************DMA***********************************/

    /***********************ADC***********************************/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE );  //ʹ��ADC1ͨ��ʱ��
    RCC_ADCCLKConfig(RCC_PCLK2_Div8);//����ADC��Ƶ����6 72M/6=12,ADC���ʱ�䲻�ܳ���14M

    ADC_DeInit(ADC1);  //��λADC1,������ ADC1 ��ȫ���Ĵ�������Ϊȱʡֵ

    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;//ADC����ģʽ ����ADCģʽ
    /*���ж��ͨ����Ҫ�ɼ��ź�ʱ�����԰�ADC����Ϊ��һ����˳�����Ը���ͨ������ɨ��ת�����������ɼ���ͨ����ֵ�����ɼ����ͨ�������뿪����ģʽ��*/
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;     //��ֹɨ��ģʽ��ɨ��ģʽ���ڶ�ͨ���ɼ�
    /*����ת��ģʽ����ģʽ�뵥��ת��ģʽ�෴������ת��ģʽADCֻ�ɼ�һ�����ݾ�ֹͣת����������ת��ģʽ������һ��ADCת����ɺ�����������һ��ת��*/
    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//��������ת��ģʽ������ͣ�ؽ���ADCת��
    /*ADC��Ҫ�ڽ��յ������źŲſ�ʼ����ģ��ת������Щ�����źſ������ⲿ�жϴ���(EXTI��)����ʱ��������������Ϊ�ⲿ�����źţ������ʹ���ⲿ�����źſ���ʹ��������ƴ���*/
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T3_TRGO;
		//ADC_ExternalTrigConv_T2_CC2;//ADC_ExternalTrigConv_T2_CC2;//ADC_ExternalTrigConv_None����ʹ���ⲿ������ת��������������ⲿ��������
		//
		//
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;    //ADC�����Ҷ���
    /*����ADC����ת����ͨ����������Ϊ1~16����*/
    ADC_InitStructure.ADC_NbrOfChannel = 1;                   //˳����й���ת����ADCͨ������Ŀ
    ADC_Init(ADC1, &ADC_InitStructure);                       //����ADC_InitStruct��ָ���Ĳ�����ʼ������ADCx�ļĴ���

    /*TCONV = (55.5+12.5)*1/9 ��7.56us */
    //ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1/*ɨ��˳��*/, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 1/*ɨ��˳��*/, ADC_SampleTime_55Cycles5);

    /* Enable ADC1 DMA */
    ADC_DMACmd(ADC1, ENABLE);           //ʹ��ADC1 ��DMA ����

    ADC_Cmd(ADC1, ENABLE);              //ʹ��ָ����ADC1 ע�⣺����ADC_Cmd ֻ��������ADC�������ú󱻵���

    //�ڿ���AD ת��ǰ  ����AD ��У׼
    ADC_ResetCalibration(ADC1); //ʹ�ܸ�λУ׼ /*��λУ׼�Ĵ��� */
    while (ADC_GetResetCalibrationStatus(ADC1)); ///*�ȴ�У׼�Ĵ�����λ��� */

    ADC_StartCalibration(ADC1);  //����ADУ׼
    while (ADC_GetCalibrationStatus(ADC1));  //�ȴ�У׼����

    //ADC_SoftwareStartConvCmd(ADC1, ENABLE);     //ʹ��ָ����ADC1�����ת����������
    /**************************ADC***************************************/
		ADC_ExternalTrigConvCmd(ADC1, ENABLE);
}
/*
 * ��������ADC1_Init
 * ����  ����
 * ����  ����
 * ���  ����
 * ����  ���ⲿ����
 */
void ADC1_Init(void)
{
    ADC1_GPIO_Config(); //ADC1 GPIO ����
    //TIM2_ADC_Init(5000,0);
		//TIM3_Irgo_Init(VOICE_HZ1,VOICE_HZ2);
    ADC1_Mode_Config(); //ADC1 ������ʽ����
}

