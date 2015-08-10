#include "adc.h"
#include "delay.h"
#include "G32_timer.h"
#include "stm32_config.h"

/*ADC 代码*/
/********************************************************************************
ADC使用DMA 功能描述：
启动AD转换后，AD 每次转换完成后，由DMA 控制器把转换值从ADC数据寄存器（ADC_DR）
中转移到变量ADC_ConvertedValue，当DMA完成后，在main中使用的，就是ADC 转换的结果。
********************************************************************************/

#define ADC1_DR_Address    ((u32)0x40012400+0x4c)   //宏定义   ADC1 转换后保存数据的地址
//0x4c        ADC1_DR 的具体地址      STM32参考手册 P178
//0x40012400  ADC 的寄存器首地址      STM32参考手册 P28
__IO uint16_t ADC_ConvertedValue[32];  //定义一个数据

/********************************************************************************************
分析上面这个定义数据的意思：
core_cm3.h 定义了 __IO：
#defines __IO volatile     !< defines 'read / write' permissions
volatile 作为指令关键字,确保本条指令不会因编译器的优化而省略,且要求每次直接读值.
stdint.h   定义了 uint16_t：
typedef  unsigned short int  uint16_t;
ADC_ConvertedValue   变量名
********************************************************************************************/
/*
* 函数名：ADC1_GPIO_Config
* 描述  ：使能ADC1和DMA1的时钟，初始化PC.01
* 输入  : 无
* 输出  ：无
* 调用  ：内部调用
*/
static void ADC1_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure; //定义结构体
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;     //要设置的PIN
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; //设置IO 为 模拟输入
//    GPIO_Init(GPIOA, &GPIO_InitStructure);        //配置IO

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

/* 函数名：ADC1_Mode_Config
* 描述  ：配置ADC1的工作模式为MDA模式
* 输入  : 无
* 输出  ：无
* 调用  ：内部调用
*/
static void ADC1_Mode_Config(void)
{
    ADC_InitTypeDef ADC_InitStructure;
    DMA_InitTypeDef DMA_InitStructure;        //定义 DMA 结构体
    NVIC_InitTypeDef NVIC_InitStructure;

    /***********************DMA*********************************/
    /* Enable DMA clock */                            //打开DMA 时钟
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);//注意它的时钟树

    /* DMA channel1 configuration */
    DMA_DeInit(DMA1_Channel1); //将DMA 通道1寄存器 复位          ADC DMA 对应 通道1

    DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_Address;         //DMA外设基地址  即ADC地址
    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)ADC_ConvertedValue;    //DMA内存基地址  即要存放数据的地址
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;  //外设作为数据传输的来源
    DMA_InitStructure.DMA_BufferSize = 32;              //DMA 缓存大小
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;//外设地址不变
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;         //DMA_MemoryInc_Disable内存地址不变 DMA_MemoryInc_Enable内存地址改变
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord; //外设数据宽度16位
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;         //内存数据宽度
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;			//DMA_Mode_Circular;//工作在循环缓存模?      DMA_Mode_Normal
		DMA_InitStructure.DMA_Priority = DMA_Priority_High; //设定DMA通道X 的优先级
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;        //DMA 通道X 没有设置 内存到内存传输
    DMA_Init(DMA1_Channel1, &DMA_InitStructure);        //配置DMA 通道1 参数
    /*Enable DMA 中断*/

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
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE );  //使能ADC1通道时钟
    RCC_ADCCLKConfig(RCC_PCLK2_Div8);//设置ADC分频因子6 72M/6=12,ADC最大时间不能超过14M

    ADC_DeInit(ADC1);  //复位ADC1,将外设 ADC1 的全部寄存器重设为缺省值

    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;//ADC工作模式 独立ADC模式
    /*当有多个通道需要采集信号时，可以把ADC配置为按一定的顺序来对各个通道进行扫描转换，即轮流采集各通道的值。若采集多个通道，必须开启此模式。*/
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;     //禁止扫描模式，扫描模式用于多通道采集
    /*连续转换模式，此模式与单次转换模式相反，单次转换模式ADC只采集一次数据就停止转换。而连续转换模式则在上一次ADC转换完成后，立即开启下一次转换*/
    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//开启连续转换模式，即不停地进行ADC转换
    /*ADC需要在接收到触发信号才开始进行模数转换，这些触发信号可以是外部中断触发(EXTI线)、定时器触发。这两个为外部触发信号，如果不使用外部触发信号可以使用软件控制触发*/
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T3_TRGO;
		//ADC_ExternalTrigConv_T2_CC2;//ADC_ExternalTrigConv_T2_CC2;//ADC_ExternalTrigConv_None（不使用外部触发）转换由软件而不是外部触发启动
		//
		//
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;    //ADC数据右对齐
    /*进行ADC数据转换的通道数，可以为1~16个。*/
    ADC_InitStructure.ADC_NbrOfChannel = 1;                   //顺序进行规则转换的ADC通道的数目
    ADC_Init(ADC1, &ADC_InitStructure);                       //根据ADC_InitStruct中指定的参数初始化外设ADCx的寄存器

    /*TCONV = (55.5+12.5)*1/9 ≈7.56us */
    //ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1/*扫描顺序*/, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 1/*扫描顺序*/, ADC_SampleTime_55Cycles5);

    /* Enable ADC1 DMA */
    ADC_DMACmd(ADC1, ENABLE);           //使能ADC1 的DMA 请求

    ADC_Cmd(ADC1, ENABLE);              //使能指定的ADC1 注意：函数ADC_Cmd 只能在其他ADC函数设置后被调用

    //在开启AD 转换前  启动AD 自校准
    ADC_ResetCalibration(ADC1); //使能复位校准 /*复位校准寄存器 */
    while (ADC_GetResetCalibrationStatus(ADC1)); ///*等待校准寄存器复位完成 */

    ADC_StartCalibration(ADC1);  //开启AD校准
    while (ADC_GetCalibrationStatus(ADC1));  //等待校准结束

    //ADC_SoftwareStartConvCmd(ADC1, ENABLE);     //使能指定的ADC1的软件转换启动功能
    /**************************ADC***************************************/
		ADC_ExternalTrigConvCmd(ADC1, ENABLE);
}
/*
 * 函数名：ADC1_Init
 * 描述  ：无
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 */
void ADC1_Init(void)
{
    ADC1_GPIO_Config(); //ADC1 GPIO 设置
    //TIM2_ADC_Init(5000,0);
		//TIM3_Irgo_Init(VOICE_HZ1,VOICE_HZ2);
    ADC1_Mode_Config(); //ADC1 工作方式设置
}

