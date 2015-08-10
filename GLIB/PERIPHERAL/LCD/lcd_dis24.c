/*
修改自吴添恒 程序




*/
#include "delay.h"
#include "lcd_dis24.h"


#define Bank1_LCD_D    TFT_DATA_ADD
#define Bank1_LCD_C    TFT_REG_ADD   

#define LCD_WR_CMD(x,y);  FSMC_WR_CMD(x,y);


void LCD_WR_REG(unsigned int index)   //写寄存器地址函数
{
	*(__IO uint16_t *) (Bank1_LCD_C)= index;
}
void LCD_WR_Data(unsigned int val)
{   
	*(__IO uint16_t *) (Bank1_LCD_D)= val; 	
}
void TFT_IO_INIT(void)
{
	 BL_Init Rest_Init Set_BL///; Set_C5
}
u32 LCD_RD_data(u16 index)
{
		u32 a;
	
		*(__IO uint16_t *) (Bank1_LCD_C)= index;
		a=*(__IO uint16_t *) (Bank1_LCD_D);// Delay(5);	  
		a=*(__IO uint16_t *) (Bank1_LCD_D);
		return a;
}
static void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
}

void lcd_rst(void){
	  Clr_Rest
    Delay(0xffff);					   
    Set_Rest		 	 
	  Delay(0xffff);	
}

#include "USART.h"

//初始化函数IC：9325
void LCD_Init(void)
{
		u32 i;

		FSMC_LCD_Init();
		TFT_IO_INIT();
		lcd_rst();	 
		Delay(50); 
		LCD_WR_CMD(0x0000, 0x0001);
    delay_ms(50); // delay 50 ms
    printf("LCD ID: %d\r\n",(int)(*(__IO uint16_t *) (Bank1_LCD_D)));//ID:0x9328 (37672)

		LCD_WR_CMD(0x00EC,0x108F);// internal timeing      
		LCD_WR_CMD(0x00EF,0x1234);// ADD        
		//LCD_WR_CMD(0x00e7,0x0010);      
		//LCD_WR_CMD(0x0000,0x0001);//?a???ú2?ê±?ó
		LCD_WR_CMD(0x0001,0x0100);     
		LCD_WR_CMD(0x0002,0x0700);//μ??′?a??                    
		LCD_WR_CMD(0x0003,(1<<3)|(1<<4) ); 	//65K  RGB
		//DRIVE TABLE(??′??÷ 03H)
		//BIT3=AM BIT4:5=ID0:1
		//AM ID0 ID1   FUNCATION
		// 0  0   0	   R->L D->U
		// 1  0   0	   D->U	R->L
		// 0  1   0	   L->R D->U
		// 1  1   0    D->U	L->R
		// 0  0   1	   R->L U->D
		// 1  0   1    U->D	R->L
		// 0  1   1    L->R U->D ?y3￡?íó??a??.
		// 1  1   1	   U->D	L->R
		//LCD_WR_CMD(0x0003,(1<<12)|(3<<4)|(0<<3) );//65K    
		LCD_WR_CMD(0x0004,0x0000);                                   
		LCD_WR_CMD(0x0008,0x0202);	           
		LCD_WR_CMD(0x0009,0x0000);         
		LCD_WR_CMD(0x000a,0x0000);//display setting         
		LCD_WR_CMD(0x000c,0x0001);//display setting          
		LCD_WR_CMD(0x000d,0x0000);//0f3c          
		LCD_WR_CMD(0x000f,0x0000);
		//μ??′????
		LCD_WR_CMD(0x0010,0x0000);   
		LCD_WR_CMD(0x0011,0x0007);
		LCD_WR_CMD(0x0012,0x0000);                                                                 
		LCD_WR_CMD(0x0013,0x0000);                 
		LCD_WR_CMD(0x0007,0x0001);                 
		delay_ms(10); 
		LCD_WR_CMD(0x0010,0x1490);   
		LCD_WR_CMD(0x0011,0x0227);
		delay_ms(10); 
		LCD_WR_CMD(0x0012,0x008A);                  
		delay_ms(10); 
		LCD_WR_CMD(0x0013,0x1a00);   
		LCD_WR_CMD(0x0029,0x0006);
		LCD_WR_CMD(0x002b,0x000d);
		delay_ms(10); 
		LCD_WR_CMD(0x0020,0x0000);                                                            
		LCD_WR_CMD(0x0021,0x0000);           
		delay_ms(10); 
		LCD_WR_CMD(0x0030,0x0000); 
		LCD_WR_CMD(0x0031,0x0604);   
		LCD_WR_CMD(0x0032,0x0305);
		LCD_WR_CMD(0x0035,0x0000);
		LCD_WR_CMD(0x0036,0x0C09); 
		LCD_WR_CMD(0x0037,0x0204);
		LCD_WR_CMD(0x0038,0x0301);        
		LCD_WR_CMD(0x0039,0x0707);     
		LCD_WR_CMD(0x003c,0x0000);
		LCD_WR_CMD(0x003d,0x0a0a);
		delay_ms(10); 
		LCD_WR_CMD(0x0050,0x0000); //????GRAM?eê????? 
		LCD_WR_CMD(0x0051,0x00ef); //????GRAM???1????                    
		LCD_WR_CMD(0x0052,0x0000); //′1?±GRAM?eê?????                    
		LCD_WR_CMD(0x0053,0x013f); //′1?±GRAM???1????  

		LCD_WR_CMD(0x0060,0xa700);        
		LCD_WR_CMD(0x0061,0x0001); 
		LCD_WR_CMD(0x006a,0x0000);
		LCD_WR_CMD(0x0080,0x0000);
		LCD_WR_CMD(0x0081,0x0000);
		LCD_WR_CMD(0x0082,0x0000);
		LCD_WR_CMD(0x0083,0x0000);
		LCD_WR_CMD(0x0084,0x0000);
		LCD_WR_CMD(0x0085,0x0000);

		LCD_WR_CMD(0x0090,0x0010);     
		LCD_WR_CMD(0x0092,0x0600);    
		LCD_WR_CMD(0x0007,0x0133);
		Delay(500000); //等待初始化完全
		LCD_WR_CMD(32, 0);
		LCD_WR_CMD(33, 0x013F);
		*(__IO uint16_t *) (Bank1_LCD_C)= 34;
		for(i=0;i<76800;i++)
		{
		    LCD_WR_Data(0xffff);
		}
		i=0;						
}
void LCD_SetCursor(u16 x, u16 y)
		{
			LCD_WR_CMD(32, x);
  LCD_WR_CMD(33, y);
		}
void LCD_WriteRAM_Prepare(void)
		{LCD_WR_REG(34);
		}

/*  建立一个窗口  */
void TFT_Window(u16 x,u16 y,u16 lenth,u16 wide) 
{
	LCD_WR_CMD(0x0050, x);              // Horizontal GRAM Start Address
	LCD_WR_CMD(0x0051, x+lenth-1); // Horizontal GRAM End Address
	LCD_WR_CMD(0x0052, y);              // Vertical GRAM Start Address
	LCD_WR_CMD(0x0053, y+wide-1);  // Vertical GRAM Start Address
	LCD_WR_CMD(32, x);
  LCD_WR_CMD(33, y);
	LCD_WR_REG(34);
}
/* 填充一个矩形 */
void TFT_CLEAR(u16 x,u16 y,u16 len,u16 wid,u16 z)
{                    
  u32 n;
	TFT_Window(x,y,len,wid);
	for(n=0;n<len*wid;n++)LCD_WR_Data(z);//显示白色 
}   
/* 画点 */
void TFT_DrawPoint(u16 x,u16 y,u16 z)
{ 
  TFT_Window(x,y,1,1);
	LCD_WR_Data(z); 
}
u16 LCD_BGR2RGB(u16 c)
{
	u16  r,g,b,rgb;   
	b=(c>>0)&0x1f;
	g=(c>>5)&0x3f;
	r=(c>>11)&0x1f;	 
	rgb=(b<<11)+(g<<5)+(r<<0);		 
	return(rgb);
} 
/* 获得一个点的颜色值 */
u32 TFT_GetPoint(u16 x,u16 y)
{
  TFT_Window(x,y,1,1); 
  return LCD_BGR2RGB(LCD_RD_data(34)); 
}
/* 显示一张图片 */
void TFT_ShowBmp(u16 x,u16 y,u16 lenth,u16 wide,const u8 *p,u32 n)
{
  u32 i=0; 
	TFT_Window(x,y,lenth,wide);
	for(i=0;i<lenth*wide*2;i+=2)LCD_WR_Data( *(p+i+1)<<8 | *(p+i));
}
 



