#include "sys.h"
#include "sys_usart.h"
#include "data_transfer.h"
//#include "bak.h"
#include "../../../GLIB/PERIPHERAL/NRF24L01/G32_Nrf24l01.h"
#include "minos_delay.h"


#define DATA_TRANSFER_USE_USART
#define DATA_TRANSFER_USE_SPI_NRF
#define DATA_TRANSFER_USARTx USART1

u8 Data_Check, Send_Status, Send_Senser, Send_RCData, Send_GpsData, Send_Offset, Send_PID1, Send_PID2, Send_PID3, Send_MotoPwm;
PID PID_ROL, PID_PIT, PID_YAW, PID_ALT, PID_POS, PID_PID_1, PID_PID_2;

void Data_Receive_Anl(u8 *data_buf, u8 num)
{
    vs16 rc_value_temp;
    u8 sum = 0;
//		Sys_sPrintf(Printf_USART,data_buf,num);
		//NRF_TxPacket(data_buf,num);//加上后 会冲突
    for (u8 i = 0; i < (num - 1); i++)
        sum += *(data_buf + i);
    if (!(sum == *(data_buf + num - 1)))       return; //sum
    if (!(*(data_buf) == 0xAA && *(data_buf + 1) == 0xAF))     return; //
    /////////////////////////////////////////////////////////////////////////////////////
    if (*(data_buf + 2) == 0X01)
    {
        if (*(data_buf + 4) == 0X01)
            ;//MPU6050_CalOff_Acc();
        if (*(data_buf + 4) == 0X02)
            ;// MPU6050_CalOff_Gyr();
        if (*(data_buf + 4) == 0X03)
        {
            ;//MPU6050_CalOff_Acc();
            ;//MPU6050_CalOff_Gyr();
        }
        if (*(data_buf + 4) == 0X04)
            ;//Cal_Compass();
        if (*(data_buf + 4) == 0X05)
            ;//MS5611_CalOffset();
    }
    if (*(data_buf + 2) == 0X02)
    {
        if (*(data_buf + 4) == 0X01)
        {
            Send_PID1 = 1;
            Send_PID2 = 1;
            Send_PID3 = 1;
        }
        if (*(data_buf + 4) == 0X02)
            Send_Offset = 1;
    }
    if (*(data_buf + 2) == 0X10)                        //PID1
    {
        PID_ROL.P = (float)((vs16)(*(data_buf + 4) << 8) | *(data_buf + 5));
        PID_ROL.I = (float)((vs16)(*(data_buf + 6) << 8) | *(data_buf + 7));
        PID_ROL.D = (float)((vs16)(*(data_buf + 8) << 8) | *(data_buf + 9));
        PID_PIT.P = (float)((vs16)(*(data_buf + 10) << 8) | *(data_buf + 11));
        PID_PIT.I = (float)((vs16)(*(data_buf + 12) << 8) | *(data_buf + 13));
        PID_PIT.D = (float)((vs16)(*(data_buf + 14) << 8) | *(data_buf + 15));
        PID_YAW.P = (float)((vs16)(*(data_buf + 16) << 8) | *(data_buf + 17));
        PID_YAW.I = (float)((vs16)(*(data_buf + 18) << 8) | *(data_buf + 19));
        PID_YAW.D = (float)((vs16)(*(data_buf + 20) << 8) | *(data_buf + 21));
        //Data_Save(1);
        Send_PID1 = 1;
    }
    if (*(data_buf + 2) == 0X11)                        //PID2
    {
        PID_ALT.P = (float)((vs16)(*(data_buf + 4) << 8) | *(data_buf + 5)) / 1000;
        PID_ALT.I = (float)((vs16)(*(data_buf + 6) << 8) | *(data_buf + 7)) / 100;
        PID_ALT.D = (float)((vs16)(*(data_buf + 8) << 8) | *(data_buf + 9)) / 100;
        PID_POS.P = (float)((vs16)(*(data_buf + 10) << 8) | *(data_buf + 11)) / 100;
        PID_POS.I = (float)((vs16)(*(data_buf + 12) << 8) | *(data_buf + 13)) / 100;
        PID_POS.D = (float)((vs16)(*(data_buf + 14) << 8) | *(data_buf + 15)) / 100;
        PID_PID_1.P = (float)((vs16)(*(data_buf + 16) << 8) | *(data_buf + 17)) / 100;
        PID_PID_1.I = (float)((vs16)(*(data_buf + 18) << 8) | *(data_buf + 19)) / 1000;
        PID_PID_1.D = (float)((vs16)(*(data_buf + 20) << 8) | *(data_buf + 21)) / 100;
        Send_PID2 = 1;
    }
    if (*(data_buf + 2) == 0X12)                        //PID3
    {
        PID_PID_2.P = (float)((vs16)(*(data_buf + 4) << 8) | *(data_buf + 5)) / 100;
        PID_PID_2.I = (float)((vs16)(*(data_buf + 6) << 8) | *(data_buf + 7)) / 100;
        PID_PID_2.D = (float)((vs16)(*(data_buf + 8) << 8) | *(data_buf + 9)) / 100;
        Send_PID3 = 1;
        //Data_Save(1);
    }
    if (*(data_buf + 2) == 0X16)                        //OFFSET
    {
        //          AngleOffset_Rol = (float)((vs16)(*(data_buf+4)<<8)|*(data_buf+5))/1000;
        //          AngleOffset_Pit = (float)((vs16)(*(data_buf+6)<<8)|*(data_buf+7))/1000;
        //          Data_Save();
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////
    if (*(data_buf + 2) == 0x03)                        //
    {

    }
}
u8 data_to_send[120];

//extern s32 Alt_ultrasonic;
//void Data_Send_Status(void)
//{
//    u8 _cnt = 0;
//    data_to_send[_cnt++] = 0xAA;
//    data_to_send[_cnt++] = 0xAA;
//    data_to_send[_cnt++] = 0x01;
//    data_to_send[_cnt++] = 0;
//    vs16 _temp;
////    _temp = (int)(Att_Angle.rol * 100);
//    data_to_send[_cnt++] = BYTE1(_temp);
//    data_to_send[_cnt++] = BYTE0(_temp);
////    _temp = (int)(Att_Angle.pit * 100);
//    data_to_send[_cnt++] = BYTE1(_temp);
//    data_to_send[_cnt++] = BYTE0(_temp);
//    //_temp = (int)(Q_ANGLE.YAW*100);
//    //_temp = (int)(Mag_Heading*100);
////    _temp = (int)(Att_Angle.yaw * 100);
//    data_to_send[_cnt++] = BYTE1(_temp);
//    data_to_send[_cnt++] = BYTE0(_temp);
//    vs32 _temp2;
// //_temp2= Alt_ultrasonic;
//    data_to_send[_cnt++] = BYTE3(_temp2);
//    data_to_send[_cnt++] = BYTE2(_temp2);
//    data_to_send[_cnt++] = BYTE1(_temp2);
//    data_to_send[_cnt++] = BYTE0(_temp2);


//    if (1)           data_to_send[_cnt++] = 0xA0;
//    else if (1)      data_to_send[_cnt++] = 0xA1;

//    data_to_send[3] = _cnt - 4;

//    u8 sum = 0;
//    for (u8 i = 0; i < _cnt; i++)
//        sum += data_to_send[i];
//    data_to_send[_cnt++] = sum;
//#ifdef DATA_TRANSFER_USE_USART
//    Sys_sPrintf(DATA_TRANSFER_USARTx, data_to_send, _cnt);
//#else
//    NRF_TxPacket(data_to_send, _cnt);
//#endif
//}
//extern float rol_i;
//extern s32 Alt_Error;

//void Data_Send_Senser(void)
//{
//    u8 _cnt = 0;
//    data_to_send[_cnt++] = 0xAA;
//    data_to_send[_cnt++] = 0xAA;
//    data_to_send[_cnt++] = 0x02;
//    data_to_send[_cnt++] = 0;
////    data_to_send[_cnt++] = BYTE1(Acc.X);
////    data_to_send[_cnt++] = BYTE0(Acc.X);
////    data_to_send[_cnt++] = BYTE1(Acc.Y);
////    data_to_send[_cnt++] = BYTE0(Acc.Y);
////    data_to_send[_cnt++] = BYTE1(Acc.Z);
////    data_to_send[_cnt++] = BYTE0(Acc.Z);
////    data_to_send[_cnt++] = BYTE1(Gyr.X);
////    data_to_send[_cnt++] = BYTE0(Gyr.X);
////    data_to_send[_cnt++] = BYTE1(Gyr.Y);
////    data_to_send[_cnt++] = BYTE0(Gyr.Y);
////    data_to_send[_cnt++] = BYTE1(Gyr.Z);
////    data_to_send[_cnt++] = BYTE0(Gyr.Z);
//    //    data_to_send[_cnt++] = BYTE1(Mag.X);
//    //    data_to_send[_cnt++] = BYTE0(Mag.X);
//    //    data_to_send[_cnt++] = BYTE1(Mag.Y);
//    //    data_to_send[_cnt++] = BYTE0(Mag.Y);
//    //    data_to_send[_cnt++] = BYTE1(Mag.Z);
//    //    data_to_send[_cnt++] = BYTE0(Mag.Z);
//vs16 _temp;
//    data_to_send[_cnt++] = BYTE1(MOTO1_PWM);
//    data_to_send[_cnt++] = BYTE0(MOTO1_PWM);
//    _temp = (int16_t)Alt_Error;
//    data_to_send[_cnt++] = BYTE1(_temp);
//    data_to_send[_cnt++] = BYTE0(_temp);
//    _temp = (int16_t)rol_i;
//    data_to_send[_cnt++] = BYTE1(_temp);
//    data_to_send[_cnt++] = BYTE0(_temp);

//    data_to_send[3] = _cnt - 4;

//    u8 sum = 0;
//    for (u8 i = 0; i < _cnt; i++)
//        sum += data_to_send[i];
//    data_to_send[_cnt++] = sum;

//#ifdef DATA_TRANSFER_USE_USART
//    Sys_sPrintf(DATA_TRANSFER_USARTx, data_to_send, _cnt);
//#else
//    NRF_TxPacket(data_to_send, _cnt);
//#endif
//}

void Data_Send_PID1(int flag)
{
    u8 _cnt = 0;
    data_to_send[_cnt++] = 0xAA;
		if(flag==1)//发送
			data_to_send[_cnt++] = 0xAF;
		else if(flag==0)//返回 验证
			data_to_send[_cnt++] = 0xAA;

    data_to_send[_cnt++] = 0x10;
    data_to_send[_cnt++] = 0;

    vs16 _temp;
    _temp = PID_ROL.P;
    data_to_send[_cnt++] = BYTE1(_temp);
    data_to_send[_cnt++] = BYTE0(_temp);
    _temp = PID_ROL.I;
    data_to_send[_cnt++] = BYTE1(_temp);
    data_to_send[_cnt++] = BYTE0(_temp);
    _temp = PID_ROL.D;
    data_to_send[_cnt++] = BYTE1(_temp);
    data_to_send[_cnt++] = BYTE0(_temp);
    _temp = PID_PIT.P;
    data_to_send[_cnt++] = BYTE1(_temp);
    data_to_send[_cnt++] = BYTE0(_temp);
    _temp = PID_PIT.I;
    data_to_send[_cnt++] = BYTE1(_temp);
    data_to_send[_cnt++] = BYTE0(_temp);
    _temp = PID_PIT.D;
    data_to_send[_cnt++] = BYTE1(_temp);
    data_to_send[_cnt++] = BYTE0(_temp);
    _temp = PID_YAW.P ;
    data_to_send[_cnt++] = BYTE1(_temp);
    data_to_send[_cnt++] = BYTE0(_temp);
    _temp = PID_YAW.I ;
    data_to_send[_cnt++] = BYTE1(_temp);
    data_to_send[_cnt++] = BYTE0(_temp);
    _temp = PID_YAW.D ;
    data_to_send[_cnt++] = BYTE1(_temp);
    data_to_send[_cnt++] = BYTE0(_temp);

    data_to_send[3] = _cnt - 4;

    u8 sum = 0;
    for (u8 i = 0; i < _cnt; i++)
        sum += data_to_send[i];

    data_to_send[_cnt++] = sum;
if(flag==1)
{
    NRF_TxPacket(data_to_send, _cnt);
}
else
{
#ifdef DATA_TRANSFER_USE_USART
    Sys_sPrintf(DATA_TRANSFER_USARTx, data_to_send, _cnt);
#else
    NRF_TxPacket(data_to_send, _cnt);
#endif
}
}
void Data_Send_PID2(int flag)
{
    u8 _cnt = 0;
    data_to_send[_cnt++] = 0xAA;
		if(flag==1)//发送
			data_to_send[_cnt++] = 0xAF;
		else if(flag==0)//返回 验证
			data_to_send[_cnt++] = 0xAA;
    data_to_send[_cnt++] = 0x11;
    data_to_send[_cnt++] = 0;

    vs16 _temp;
    _temp = PID_ALT.P * 1000;
    data_to_send[_cnt++] = BYTE1(_temp);
    data_to_send[_cnt++] = BYTE0(_temp);
    _temp = PID_ALT.I * 100;
    data_to_send[_cnt++] = BYTE1(_temp);
    data_to_send[_cnt++] = BYTE0(_temp);
    _temp = PID_ALT.D * 100;
    data_to_send[_cnt++] = BYTE1(_temp);
    data_to_send[_cnt++] = BYTE0(_temp);
    _temp = PID_POS.P * 100;
    data_to_send[_cnt++] = BYTE1(_temp);
    data_to_send[_cnt++] = BYTE0(_temp);
    _temp = PID_POS.I * 100;
    data_to_send[_cnt++] = BYTE1(_temp);
    data_to_send[_cnt++] = BYTE0(_temp);
    _temp = PID_POS.D * 100;
    data_to_send[_cnt++] = BYTE1(_temp);
    data_to_send[_cnt++] = BYTE0(_temp);
    _temp = PID_PID_1.P * 100;
    data_to_send[_cnt++] = BYTE1(_temp);
    data_to_send[_cnt++] = BYTE0(_temp);
    _temp = PID_PID_1.I * 1000;
    data_to_send[_cnt++] = BYTE1(_temp);
    data_to_send[_cnt++] = BYTE0(_temp);
    _temp = PID_PID_1.D * 100;
    data_to_send[_cnt++] = BYTE1(_temp);
    data_to_send[_cnt++] = BYTE0(_temp);

    data_to_send[3] = _cnt - 4;

    u8 sum = 0;
    for (u8 i = 0; i < _cnt; i++)
        sum += data_to_send[i];

    data_to_send[_cnt++] = sum;

if(flag==1)
{
    NRF_TxPacket(data_to_send, _cnt);
}
else
{
#ifdef DATA_TRANSFER_USE_USART
    Sys_sPrintf(DATA_TRANSFER_USARTx, data_to_send, _cnt);
#else
    NRF_TxPacket(data_to_send, _cnt);
#endif
}
}
void Data_Send_PID3(int flag)
{
    u8 _cnt = 0;
    data_to_send[_cnt++] = 0xAA;
		if(flag==1)//发送
			data_to_send[_cnt++] = 0xAF;
		else if(flag==0)//返回 验证
			data_to_send[_cnt++] = 0xAA;
    data_to_send[_cnt++] = 0x12;
    data_to_send[_cnt++] = 0;

    vs16 _temp;
    _temp = PID_PID_2.P * 100;
    data_to_send[_cnt++] = BYTE1(_temp);
    data_to_send[_cnt++] = BYTE0(_temp);
    _temp = PID_PID_2.I * 100;
    data_to_send[_cnt++] = BYTE1(_temp);
    data_to_send[_cnt++] = BYTE0(_temp);
    _temp = PID_PID_2.D * 100;
    data_to_send[_cnt++] = BYTE1(_temp);
    data_to_send[_cnt++] = BYTE0(_temp);

    data_to_send[3] = _cnt - 4;

    u8 sum = 0;
    for (u8 i = 0; i < _cnt; i++)
        sum += data_to_send[i];

    data_to_send[_cnt++] = sum;

if(flag==1)
{
    NRF_TxPacket(data_to_send, _cnt);
}
else
{
#ifdef DATA_TRANSFER_USE_USART
    Sys_sPrintf(DATA_TRANSFER_USARTx, data_to_send, _cnt);
#else
    NRF_TxPacket(data_to_send, _cnt);
#endif
}
}
//void Data_Send_RCData(void)
//{
//    u8 _cnt = 0;
//    data_to_send[_cnt++] = 0xAA;
//    data_to_send[_cnt++] = 0xAA;
//    data_to_send[_cnt++] = 0x03;
//    data_to_send[_cnt++] = 0;
//    data_to_send[_cnt++] = BYTE1(Rc_D.THROTTLE);
//    data_to_send[_cnt++] = BYTE0(Rc_D.THROTTLE);
//    data_to_send[_cnt++] = BYTE1(Rc_D.YAW);
//    data_to_send[_cnt++] = BYTE0(Rc_D.YAW);
//    data_to_send[_cnt++] = BYTE1(Rc_D.ROLL);
//    data_to_send[_cnt++] = BYTE0(Rc_D.ROLL);
//    data_to_send[_cnt++] = BYTE1(Rc_D.PITCH);
//    data_to_send[_cnt++] = BYTE0(Rc_D.PITCH);
//    data_to_send[_cnt++] = BYTE1(Rc_D.AUX1);
//    data_to_send[_cnt++] = BYTE0(Rc_D.AUX1);
//    data_to_send[_cnt++] = BYTE1(Rc_D.AUX2);
//    data_to_send[_cnt++] = BYTE0(Rc_D.AUX2);
//    data_to_send[_cnt++] = BYTE1(Rc_D.AUX3);
//    data_to_send[_cnt++] = BYTE0(Rc_D.AUX3);
//    data_to_send[_cnt++] = BYTE1(Rc_D.AUX4);
//    data_to_send[_cnt++] = BYTE0(Rc_D.AUX4);
//    data_to_send[_cnt++] = BYTE1(Rc_D.AUX5);
//    data_to_send[_cnt++] = BYTE0(Rc_D.AUX5);
//    data_to_send[_cnt++] = BYTE1(Rc_D.AUX6);
//    data_to_send[_cnt++] = BYTE0(Rc_D.AUX6);

//    data_to_send[3] = _cnt - 4;

//    u8 sum = 0;
//    for (u8 i = 0; i < _cnt; i++)
//        sum += data_to_send[i];

//    data_to_send[_cnt++] = sum;

//#ifdef DATA_TRANSFER_USE_USART
//    Sys_sPrintf(DATA_TRANSFER_USARTx, data_to_send, _cnt);
//#else
//    NRF_TxPacket(data_to_send, _cnt);
//#endif
//}

//void Data_Send_MotoPWM(void)
//{
//    u8 _cnt = 0;
//    data_to_send[_cnt++] = 0xAA;
//    data_to_send[_cnt++] = 0xAA;
//    data_to_send[_cnt++] = 0x06;
//    data_to_send[_cnt++] = 0;
//    data_to_send[_cnt++] = BYTE1(MOTO1_PWM);
//    data_to_send[_cnt++] = BYTE0(MOTO1_PWM);
//    data_to_send[_cnt++] = BYTE1(MOTO2_PWM);
//    data_to_send[_cnt++] = BYTE0(MOTO2_PWM);
//    data_to_send[_cnt++] = BYTE1(MOTO3_PWM);
//    data_to_send[_cnt++] = BYTE0(MOTO3_PWM);
//    data_to_send[_cnt++] = BYTE1(MOTO4_PWM);
//    data_to_send[_cnt++] = BYTE0(MOTO4_PWM);
//    data_to_send[_cnt++] = BYTE1(MOTO1_PWM);
//    data_to_send[_cnt++] = BYTE0(MOTO1_PWM);
//    data_to_send[_cnt++] = BYTE1(MOTO1_PWM);
//    data_to_send[_cnt++] = BYTE0(MOTO1_PWM);
//    data_to_send[_cnt++] = BYTE1(MOTO1_PWM);
//    data_to_send[_cnt++] = BYTE0(MOTO1_PWM);
//    data_to_send[_cnt++] = BYTE1(MOTO1_PWM);
//    data_to_send[_cnt++] = BYTE0(MOTO1_PWM);

//    data_to_send[3] = _cnt - 4;

//    u8 sum = 0;
//    for (u8 i = 0; i < _cnt; i++)
//        sum += data_to_send[i];

//    data_to_send[_cnt++] = sum;

//#ifdef DATA_TRANSFER_USE_USART
//    Sys_sPrintf(DATA_TRANSFER_USARTx, data_to_send, _cnt);
//#else
//    NRF_TxPacket(data_to_send, _cnt);
//#endif
//}

//Send_Senser = 1;
//Send_Status = 1;
// Send_MotoPwm = 1;
void Data_Exchange(void)
{
#ifdef DATA_TRANSFER_USE_SPI_NRF
    Nrf_Check_Event();//当使用 24l01时 必须 使用此函数 清 寄存器
    u8 sta = Nrf_Get_FIFOSta();//清FIFO
    if ((sta & (1 << 4)) == 0)
        return;
#endif

    if (Send_Status)
    {
        Send_Status = 0;
        //Data_Send_Status();
    }
    else if (Send_GpsData)
    {
        Send_GpsData = 0;
        //Data_Send_GpsData();
    }
    if (Send_Senser)
    {
        Send_Senser = 0;
        //Data_Send_Senser();
    }
    if (Send_PID1==1)
    {
        Send_PID1 = 2;
        Data_Send_PID1(0);
    }
		else if (Send_PID1==2)
    {
        Send_PID1 = 0;
        Data_Send_PID1(1);
    }
		
    else if (Send_PID2==1)
    {
        Send_PID2 = 0;
        Data_Send_PID2(0);
    }
		else if (Send_PID2==2)
    {
        Send_PID2 = 0;
        Data_Send_PID2(1);
    }
    else if (Send_PID3==1)
    {
        Send_PID3 = 0;
        Data_Send_PID3(0);
    }
		else if (Send_PID3==2)
    {
        Send_PID3 = 0;
        Data_Send_PID3(1);
    }
    if (Send_RCData)
    {
        Send_RCData = 0;
        // Data_Send_RCData();
    }
    else if (Send_Offset)
    {
        Send_Offset = 0;
        //Data_Send_OFFSET();
    }
    if (Send_MotoPwm)
    {
        Send_MotoPwm = 0;
        // Data_Send_MotoPWM();
    }
}
