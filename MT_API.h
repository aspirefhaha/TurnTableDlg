#ifndef _MT_API_
#define _MT_API_
/*
C�ӿ��ļ�
4.0
*/
#include "stdint.h"
#include <windows.h>
#pragma comment(lib,"MT_API.lib")
#ifdef __cplusplus
#define MT_API extern "C" __declspec( dllexport )
#else
#define MT_API __declspec( dllexport )
#endif

#define R_OK   0
#define RUN_OFF   0
#define RUN_ON   1
#define DIR_NEG   0
#define DIR_POS   1
#define LIMIT_ON   1
#define LIMIT_OFF   0
#define RESOURCE_MOTOR   0x00000001
#define RESOURCE_TTL_IN   0x00000002
#define RESOURCE_TTL_OUT   0x00000004
#define RESOURCE_OPTIC_IN   0x00000008
#define RESOURCE_OPTIC_OUT   0x00000010
#define RESOURCE_AD   0x00000020
#define RESOURCE_OC   0x00000040
#define RESOURCE_LINE   0x00000080
#define RESOURCE_CIRCLE   0x00000100
#define RESOURCE_PLC   0x00000200
#define RESOURCE_STREAM   0x00000400
#define RESOURCE_ENCODER   0x00000800
#define RESOURCE_PWM   0x00001000
#define RESOURCE_T   0x00002000

//**************************************************//
// V4.0 updated 2020-02-23
//**************************************************//
//==================================================
//���л���
//===================================================
//dll�汾
//��ʼ������
MT_API int32_t __stdcall MT_Init(void);

//�رմ���
MT_API int32_t __stdcall MT_DeInit(void);

//��ȡdll�汾��
MT_API int32_t __stdcall MT_Get_Dll_Version(char** sVer);

//�����߳���ʱ��
MT_API int32_t __stdcall MT_Set_Thread_Timeout(uint32_t ms);

//======================================================
//ͨ�ſ�
//======================================================
//�� UART
MT_API int32_t __stdcall MT_Open_UART(char* sCOM);

MT_API int32_t __stdcall MT_Open_UART_Unicode(TCHAR* sCOM);

MT_API int32_t __stdcall MT_M_Open_UART(int32_t ADev,char* sCOM);

MT_API int32_t __stdcall MT_M_Open_UART_Unicode(int32_t ADev,TCHAR* sCOM);

//�ر� UART
MT_API int32_t __stdcall MT_Close_UART(void);

MT_API int32_t __stdcall MT_M_Close_UART(int32_t ADev);

//��USB,��ϵͳ˳��
MT_API int32_t __stdcall MT_Open_USB(void);

MT_API int32_t __stdcall MT_M_Open_USB(int32_t ADev);

//��USB�������к�ָ��
//�ر�USB
MT_API int32_t __stdcall MT_Close_USB(void);

MT_API int32_t __stdcall MT_M_Close_USB(int32_t ADev);

//������
MT_API int32_t __stdcall MT_Open_Net(uint8_t IP0,uint8_t IP1,uint8_t IP2,uint8_t IP3,uint16_t IPPort);

MT_API int32_t __stdcall MT_M_Open_Net(int32_t ADev,uint8_t IP0,uint8_t IP1,uint8_t IP2,uint8_t IP3,uint16_t IPPort);

//�ر�����
MT_API int32_t __stdcall MT_Close_Net(void);

MT_API int32_t __stdcall MT_M_Close_Net(int32_t ADev);

//=====================================================
//�忨���
//=====================================================
//����豸
MT_API int32_t __stdcall MT_Check(void);

MT_API int32_t __stdcall MT_M_Check(int32_t ADev);

//��ȡ��Դģ��
MT_API int32_t __stdcall MT_Get_Product_Resource(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Product_Resource(int32_t ADev,int32_t* pValue);

//��ȡID
MT_API int32_t __stdcall MT_Get_Product_ID(char* sID);

MT_API int32_t __stdcall MT_M_Get_Product_ID(int32_t ADev,char* sID);

//��ȡSN
MT_API int32_t __stdcall MT_Get_Product_SN(char* sSN);

MT_API int32_t __stdcall MT_M_Get_Product_SN(int32_t ADev,char* sSN);

//��ȡSN2
MT_API int32_t __stdcall MT_Get_Product_SN2(uint8_t* sSN);

MT_API int32_t __stdcall MT_M_Get_Product_SN2(int32_t ADev,uint8_t* sSN);

//��ȡSN3
MT_API int32_t __stdcall MT_Get_Product_SN3(char* sSN);

MT_API int32_t __stdcall MT_M_Get_Product_SN3(int32_t ADev,char* sSN);

//��ȡ�̼��汾��
MT_API int32_t __stdcall MT_Get_Product_Version(int32_t* pMajor,int32_t* pMinor);

MT_API int32_t __stdcall MT_M_Get_Product_Version(int32_t ADev,int32_t* pMajor,int32_t* pMinor);

//��ȡ�̼��汾��
MT_API int32_t __stdcall MT_Get_Product_Version2(int32_t* pMajor,int32_t* pMinor,int32_t* pRelease,int32_t* pBuild);

MT_API int32_t __stdcall MT_M_Get_Product_Version2(int32_t ADev,int32_t* pMajor,int32_t* pMinor,int32_t* pRelease,int32_t* pBuild);

//===================================================================
//������
//====================================================================
//����
MT_API int32_t __stdcall MT_Get_Axis_Num(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Num(int32_t ADev,int32_t* pValue);

//��ȡ���ٶ�
MT_API int32_t __stdcall MT_Get_Axis_Acc(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Acc(int32_t ADev,uint16_t AObj,int32_t* pValue);

//���ü��ٶ�
MT_API int32_t __stdcall MT_Set_Axis_Acc(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Acc(int32_t ADev,uint16_t AObj,int32_t Value);

//��ȡ���ٶ�
MT_API int32_t __stdcall MT_Get_Axis_Dec(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Dec(int32_t ADev,uint16_t AObj,int32_t* pValue);

//���ü��ٶ�
MT_API int32_t __stdcall MT_Set_Axis_Dec(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Dec(int32_t ADev,uint16_t AObj,int32_t Value);

//��ȡ����ģʽ
MT_API int32_t __stdcall MT_Get_Axis_Mode(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Mode(int32_t ADev,uint16_t AObj,int32_t* pValue);

//�����ٶ�ģʽ
MT_API int32_t __stdcall MT_Set_Axis_Mode_Velocity(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Axis_Mode_Velocity(int32_t ADev,uint16_t AObj);

//����λ��ģʽ
MT_API int32_t __stdcall MT_Set_Axis_Mode_Position(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Axis_Mode_Position(int32_t ADev,uint16_t AObj);

MT_API int32_t __stdcall MT_Set_Axis_Mode_Position_Open(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Axis_Mode_Position_Open(int32_t ADev,uint16_t AObj);

MT_API int32_t __stdcall MT_Set_Axis_Mode_Position_Close(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Axis_Mode_Position_Close(int32_t ADev,uint16_t AObj);

//��ȡ�ٶ�ģʽĿ���ٶ�
MT_API int32_t __stdcall MT_Get_Axis_Velocity_V_Target(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Velocity_V_Target(int32_t ADev,uint16_t AObj,int32_t* pValue);

//�����ٶ�ģʽĿ���ٶ�
MT_API int32_t __stdcall MT_Set_Axis_Velocity_V_Target_Abs(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Velocity_V_Target_Abs(int32_t ADev,uint16_t AObj,int32_t Value);

//�����ٶ�ģʽĿ���ٶ�
MT_API int32_t __stdcall MT_Set_Axis_Velocity_V_Target_Rel(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Velocity_V_Target_Rel(int32_t ADev,uint16_t AObj,int32_t Value);

//ֹͣ�ٶ�ģʽ
MT_API int32_t __stdcall MT_Set_Axis_Velocity_Stop(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Axis_Velocity_Stop(int32_t ADev,uint16_t AObj);

//��ȡλ��ģʽ����ٶ�
MT_API int32_t __stdcall MT_Get_Axis_Position_V_Max(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Position_V_Max(int32_t ADev,uint16_t AObj,int32_t* pValue);

//����λ��ģʽ����ٶ�
MT_API int32_t __stdcall MT_Set_Axis_Position_V_Max(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Position_V_Max(int32_t ADev,uint16_t AObj,int32_t Value);

//��ȡλ��ģʽĿ��
MT_API int32_t __stdcall MT_Get_Axis_Position_P_Target(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Position_P_Target(int32_t ADev,uint16_t AObj,int32_t* pValue);

//����λ��ģʽĿ��
MT_API int32_t __stdcall MT_Set_Axis_Position_P_Target_Abs(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Position_P_Target_Abs(int32_t ADev,uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_Set_Axis_Position_P_Target_Rel(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Position_P_Target_Rel(int32_t ADev,uint16_t AObj,int32_t Value);

//ֹͣλ��ģʽ
MT_API int32_t __stdcall MT_Set_Axis_Position_Stop(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Axis_Position_Stop(int32_t ADev,uint16_t AObj);

//���ñ���������,���ڼ����ж���
MT_API int32_t __stdcall MT_Set_Axis_Position_Close_Dec_Factor(uint16_t AObj,float AFactor);

MT_API int32_t __stdcall MT_M_Set_Axis_Position_Close_Dec_Factor(int32_t ADev,uint16_t AObj,float AFactor);

//����ֹͣ
MT_API int32_t __stdcall MT_Set_Axis_Halt(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Axis_Halt(int32_t ADev,uint16_t AObj);

MT_API int32_t __stdcall MT_Set_Axis_Halt_All(void);

MT_API int32_t __stdcall MT_M_Set_Axis_Halt_All(int32_t ADev);

//////////////////////////////////////////////////////////////
///  ״̬���
///  //////////////////////////////////////////////////////
//��ȡ��ǰ�ٶ�
MT_API int32_t __stdcall MT_Get_Axis_V_Now(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_V_Now(int32_t ADev,uint16_t AObj,int32_t* pValue);

//��ȡ��ǰ���λ��
MT_API int32_t __stdcall MT_Get_Axis_P_Now(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_P_Now(int32_t ADev,uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_Get_Axis_Software_P_Now(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Software_P_Now(int32_t ADev,uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_Get_Axis_Software_P(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Software_P(int32_t ADev,uint16_t AObj,int32_t* pValue);

//�������λ��
MT_API int32_t __stdcall MT_Set_Axis_P(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_P(int32_t ADev,uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_Set_Axis_Software_P(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Software_P(int32_t ADev,uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_Set_Axis_Software_P_Now(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Software_P_Now(int32_t ADev,uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_Get_Axis_Status(uint16_t AObj,uint8_t* pRun,uint8_t* pDir,uint8_t* pNeg,uint8_t* pPos,uint8_t* pZero,uint8_t* pMode);

MT_API int32_t __stdcall MT_M_Get_Axis_Status(int32_t ADev,uint16_t AObj,uint8_t* pRun,uint8_t* pDir,uint8_t* pNeg,uint8_t* pPos,uint8_t* pZero,uint8_t* pMode);

MT_API int32_t __stdcall MT_Get_Axis_Status2(uint16_t AObj,int32_t* pRun,int32_t* pDir,int32_t* pNeg,int32_t* pPos,int32_t* pZero,int32_t* pMode);

MT_API int32_t __stdcall MT_M_Get_Axis_Status2(int32_t ADev,uint16_t AObj,int32_t* pRun,int32_t* pDir,int32_t* pNeg,int32_t* pPos,int32_t* pZero,int32_t* pMode);

MT_API int32_t __stdcall MT_Get_Axis_Status_Run(uint16_t AObj,int32_t* pRun);

MT_API int32_t __stdcall MT_M_Get_Axis_Status_Run(int32_t ADev,uint16_t AObj,int32_t* pRun);

MT_API int32_t __stdcall MT_Get_Axis_Status_Dir(uint16_t AObj,int32_t* pDir);

MT_API int32_t __stdcall MT_M_Get_Axis_Status_Dir(int32_t ADev,uint16_t AObj,int32_t* pDir);

MT_API int32_t __stdcall MT_Get_Axis_Status_Neg(uint16_t AObj,int32_t* pNeg);

MT_API int32_t __stdcall MT_M_Get_Axis_Status_Neg(int32_t ADev,uint16_t AObj,int32_t* pNeg);

MT_API int32_t __stdcall MT_Get_Axis_Status_Pos(uint16_t AObj,int32_t* pPos);

MT_API int32_t __stdcall MT_M_Get_Axis_Status_Pos(int32_t ADev,uint16_t AObj,int32_t* pPos);

MT_API int32_t __stdcall MT_Get_Axis_Status_Zero(uint16_t AObj,int32_t* pZero);

MT_API int32_t __stdcall MT_M_Get_Axis_Status_Zero(int32_t ADev,uint16_t AObj,int32_t* pZero);

MT_API int32_t __stdcall MT_Get_Axis_Status_Mode(uint16_t AObj,int32_t* pMode);

MT_API int32_t __stdcall MT_M_Get_Axis_Status_Mode(int32_t ADev,uint16_t AObj,int32_t* pMode);

//����0λģʽ
MT_API int32_t __stdcall MT_Set_Axis_Mode_Home(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Axis_Mode_Home(int32_t ADev,uint16_t AObj);

MT_API int32_t __stdcall MT_Set_Axis_Mode_Home_Home_Switch(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Axis_Mode_Home_Home_Switch(int32_t ADev,uint16_t AObj);

MT_API int32_t __stdcall MT_Set_Axis_Mode_Home_Encoder_Index(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Axis_Mode_Home_Encoder_Index(int32_t ADev,uint16_t AObj);

MT_API int32_t __stdcall MT_Set_Axis_Mode_Home_Encoder_Home_Switch(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Axis_Mode_Home_Encoder_Home_Switch(int32_t ADev,uint16_t AObj);

MT_API int32_t __stdcall MT_Set_Axis_Mode_Home_Home_Zero(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Axis_Mode_Home_Home_Zero(int32_t ADev,uint16_t AObj);

//����0λģʽĿ���ٶ�
MT_API int32_t __stdcall MT_Set_Axis_Home_V(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Home_V(int32_t ADev,uint16_t AObj,int32_t Value);

//ֹͣ0λģʽ
MT_API int32_t __stdcall MT_Set_Axis_Home_Stop(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Axis_Home_Stop(int32_t ADev,uint16_t AObj);

//�����λ
//���������λֵ
MT_API int32_t __stdcall MT_Set_Axis_Software_Limit_Neg_Value(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Software_Limit_Neg_Value(int32_t ADev,uint16_t AObj,int32_t Value);

//���������λֵ
MT_API int32_t __stdcall MT_Set_Axis_Software_Limit_Pos_Value(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Software_Limit_Pos_Value(int32_t ADev,uint16_t AObj,int32_t Value);

//ʹ�������λģʽ
MT_API int32_t __stdcall MT_Set_Axis_Software_Limit_Enable(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Axis_Software_Limit_Enable(int32_t ADev,uint16_t AObj);

//ֹͣ�����λģʽ
MT_API int32_t __stdcall MT_Set_Axis_Software_Limit_Disable(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Axis_Software_Limit_Disable(int32_t ADev,uint16_t AObj);

////////////////////////////////////////////////////////////////////////
//�洢��
//��ȡ�洢������
MT_API int32_t __stdcall MT_Get_System_Mem_Len(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_System_Mem_Len(int32_t ADev,int32_t* pValue);

//��ȡ�洢������
MT_API int32_t __stdcall MT_Get_System_Mem_Data(uint16_t AObj,uint8_t* pValue);

MT_API int32_t __stdcall MT_M_Get_System_Mem_Data(int32_t ADev,uint16_t AObj,uint8_t* pValue);

//���ô洢������
MT_API int32_t __stdcall MT_Set_System_Mem_Data(uint16_t AObj,uint8_t Value);

MT_API int32_t __stdcall MT_M_Set_System_Mem_Data(int32_t ADev,uint16_t AObj,uint8_t Value);

//====================================================================
// ϵͳ�����洢��
//======================================================================
// ��ȡ�洢������
MT_API int32_t __stdcall MT_Get_Param_Mem_Len(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Param_Mem_Len(int32_t ADev,int32_t* pValue);

//��ȡ�洢������
MT_API int32_t __stdcall MT_Get_Param_Mem_Data(uint16_t AObj,uint8_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Param_Mem_Data(int32_t ADev,uint16_t AObj,uint8_t* pValue);

//���ô洢������
MT_API int32_t __stdcall MT_Set_Param_Mem_Data(uint16_t AObj,uint8_t Value);

MT_API int32_t __stdcall MT_M_Set_Param_Mem_Data(int32_t ADev,uint16_t AObj,uint8_t Value);

//====================================================================
//�������
//======================================================================
//ͨ����
MT_API int32_t __stdcall MT_Get_Optic_In_Num(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Optic_In_Num(int32_t ADev,int32_t* pValue);

//���㸴�õ������λ����λ
MT_API int32_t __stdcall MT_Get_Optic_In_Basic_Num(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Optic_In_Basic_Num(int32_t ADev,int32_t* pValue);

//��ȡ��ͨ��ֵ
MT_API int32_t __stdcall MT_Get_Optic_In_Single(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Optic_In_Single(int32_t ADev,uint16_t AObj,int32_t* pValue);

//��ȡ����ͨ��ֵ
MT_API int32_t __stdcall MT_Get_Optic_In_All(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Optic_In_All(int32_t ADev,int32_t* pValue);

//====================================================================
//������
//======================================================================
//ͨ����
MT_API int32_t __stdcall MT_Get_Optic_Out_Num(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Optic_Out_Num(int32_t ADev,int32_t* pValue);

//���õ�ͨ��ֵ
MT_API int32_t __stdcall MT_Set_Optic_Out_Single(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Optic_Out_Single(int32_t ADev,uint16_t AObj,int32_t Value);

//��������ͨ��ֵ
MT_API int32_t __stdcall MT_Set_Optic_Out_All(int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Optic_Out_All(int32_t ADev,int32_t Value);

//��ȡ��ͨ��ֵ
MT_API int32_t __stdcall MT_Get_Optic_Out_Single(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Optic_Out_Single(int32_t ADev,uint16_t AObj,int32_t* pValue);

//��ȡ����ͨ��ֵ
MT_API int32_t __stdcall MT_Get_Optic_Out_All(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Optic_Out_All(int32_t ADev,int32_t* pValue);

//====================================================================
//OC���
//======================================================================
//ͨ����
MT_API int32_t __stdcall MT_Get_OC_Out_Num(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_OC_Out_Num(int32_t ADev,int32_t* pValue);

//���õ�ͨ��ֵ
MT_API int32_t __stdcall MT_Set_OC_Out_Single(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_OC_Out_Single(int32_t ADev,uint16_t AObj,int32_t Value);

//��������ͨ��ֵ
MT_API int32_t __stdcall MT_Set_OC_Out_All(int32_t Value);

MT_API int32_t __stdcall MT_M_Set_OC_Out_All(int32_t ADev,int32_t Value);

//��ȡ��ͨ��ֵ
MT_API int32_t __stdcall MT_Get_OC_Out_Single(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_OC_Out_Single(int32_t ADev,uint16_t AObj,int32_t* pValue);

//��ȡ����ͨ��ֵ
MT_API int32_t __stdcall MT_Get_OC_Out_All(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_OC_Out_All(int32_t ADev,int32_t* pValue);

//ֱ�߲岹���
//����ֱ�߲岹���ἰ�ٶ�
MT_API int32_t __stdcall MT_Set_Axis_Line_Axis(uint16_t AObj,int32_t Axis_ID0,int32_t Axis_ID1);

MT_API int32_t __stdcall MT_M_Set_Axis_Line_Axis(int32_t ADev,uint16_t AObj,int32_t Axis_ID0,int32_t Axis_ID1);

//����ֱ�߲岹���ٶ�
MT_API int32_t __stdcall MT_Set_Axis_Line_Acc(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Line_Acc(int32_t ADev,uint16_t AObj,int32_t Value);

//����ֱ�߲岹���ٶ�
MT_API int32_t __stdcall MT_Set_Axis_Line_Dec(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Line_Dec(int32_t ADev,uint16_t AObj,int32_t Value);

//����ֱ�߲岹�ٶ�
MT_API int32_t __stdcall MT_Set_Axis_Line_V(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Line_V(int32_t ADev,uint16_t AObj,int32_t Value);

//����ֱ�߲岹����
MT_API int32_t __stdcall MT_Set_Axis_Line_Run(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Axis_Line_Run(int32_t ADev,uint16_t AObj);

//����ֱ�߲岹ֹͣ
MT_API int32_t __stdcall MT_Set_Axis_Line_Stop(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Axis_Line_Stop(int32_t ADev,uint16_t AObj);

//����ֱ�߲岹��ͣ
MT_API int32_t __stdcall MT_Set_Axis_Line_Halt(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Axis_Line_Halt(int32_t ADev,uint16_t AObj);

//����ֱ�߲岹����ƶ�Ŀ��
MT_API int32_t __stdcall MT_Set_Axis_Line_Rel(uint16_t AObj,int32_t Axis_Target0,int32_t Axis_Target1);

MT_API int32_t __stdcall MT_M_Set_Axis_Line_Rel(int32_t ADev,uint16_t AObj,int32_t Axis_Target0,int32_t Axis_Target1);

//����ֱ�߲岹�����ƶ�Ŀ��
MT_API int32_t __stdcall MT_Set_Axis_Line_Abs(uint16_t AObj,int32_t Axis_Target0,int32_t Axis_Target1);

MT_API int32_t __stdcall MT_M_Set_Axis_Line_Abs(int32_t ADev,uint16_t AObj,int32_t Axis_Target0,int32_t Axis_Target1);

//����ֱ�߲岹����
MT_API int32_t __stdcall MT_Set_Axis_Line_Run_Rel(uint16_t AObj,int32_t Axis_Target0,int32_t Axis_Target1);

MT_API int32_t __stdcall MT_M_Set_Axis_Line_Run_Rel(int32_t ADev,uint16_t AObj,int32_t Axis_Target0,int32_t Axis_Target1);

MT_API int32_t __stdcall MT_Set_Axis_Line_Run_Abs(uint16_t AObj,int32_t Axis_Target0,int32_t Axis_Target1);

MT_API int32_t __stdcall MT_M_Set_Axis_Line_Run_Abs(int32_t ADev,uint16_t AObj,int32_t Axis_Target0,int32_t Axis_Target1);

//��ȡֱ�߲岹ģ��
MT_API int32_t __stdcall MT_Get_Axis_Line_Num(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Line_Num(int32_t ADev,int32_t* pValue);

//�岹�˶�״̬
MT_API int32_t __stdcall MT_Get_Axis_Line_Status(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Line_Status(int32_t ADev,uint16_t AObj,int32_t* pValue);

//�岹��
MT_API int32_t __stdcall MT_Get_Axis_Line_Axis(uint16_t AObj,int32_t* pID0,int32_t* pID1);

MT_API int32_t __stdcall MT_M_Get_Axis_Line_Axis(int32_t ADev,uint16_t AObj,int32_t* pID0,int32_t* pID1);

//�岹���ٶ�
MT_API int32_t __stdcall MT_Get_Axis_Line_Acc(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Line_Acc(int32_t ADev,uint16_t AObj,int32_t* pValue);

//�岹���ٶ�
MT_API int32_t __stdcall MT_Get_Axis_Line_Dec(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Line_Dec(int32_t ADev,uint16_t AObj,int32_t* pValue);

//�岹�ٶ�
MT_API int32_t __stdcall MT_Get_Axis_Line_V(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Line_V(int32_t ADev,uint16_t AObj,int32_t* pValue);

//====================================================================
//AD����
//======================================================================
//ͨ����
MT_API int32_t __stdcall MT_Get_AD_Num(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_AD_Num(int32_t ADev,int32_t* pValue);

//��ȡ��ͨ��ֵ
MT_API int32_t __stdcall MT_Get_AD_Data(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_AD_Data(int32_t ADev,uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_Get_Board_T(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Board_T(int32_t ADev,int32_t* pValue);

//2020 01 05 �ⲿ�¶ȴ�����
MT_API int32_t __stdcall MT_Get_T_Num(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_T_Num(int32_t ADev,int32_t* pValue);

MT_API int32_t __stdcall MT_Get_T_Float(uint16_t AObj,float* pValue);

MT_API int32_t __stdcall MT_M_Get_T_Float(int32_t ADev,uint16_t AObj,float* pValue);

MT_API int32_t __stdcall MT_Get_T(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_T(int32_t ADev,uint16_t AObj,int32_t* pValue);

//2020 01 05 PWM����
MT_API int32_t __stdcall MT_Get_PWM_Num(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_PWM_Num(int32_t ADev,int32_t* pValue);

MT_API int32_t __stdcall MT_Set_PWM_F(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_PWM_F(int32_t ADev,uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_Get_PWM_F(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_PWM_F(int32_t ADev,uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_Set_PWM_F_Float(uint16_t AObj,float Value);

MT_API int32_t __stdcall MT_M_Set_PWM_F_Float(int32_t ADev,uint16_t AObj,float Value);

MT_API int32_t __stdcall MT_Get_PWM_F_Float(uint16_t AObj,float* pValue);

MT_API int32_t __stdcall MT_M_Get_PWM_F_Float(int32_t ADev,uint16_t AObj,float* pValue);

MT_API int32_t __stdcall MT_Set_PWM01(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_PWM01(int32_t ADev,uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_Get_PWM01(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_PWM01(int32_t ADev,uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_Set_PWM001(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_PWM001(int32_t ADev,uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_Get_PWM001(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_PWM001(int32_t ADev,uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_Set_PWM_Float(uint16_t AObj,float Value);

MT_API int32_t __stdcall MT_M_Set_PWM_Float(int32_t ADev,uint16_t AObj,float Value);

MT_API int32_t __stdcall MT_Get_PWM_Float(uint16_t AObj,float* pValue);

MT_API int32_t __stdcall MT_M_Get_PWM_Float(int32_t ADev,uint16_t AObj,float* pValue);

//================================================================
//Բ���岹
//================================================================
//����Բ���岹���ἰ�ٶ�
MT_API int32_t __stdcall MT_Set_Axis_Circle_Axis(uint16_t AObj,int32_t Axis_ID0,int32_t Axis_ID1);

MT_API int32_t __stdcall MT_M_Set_Axis_Circle_Axis(int32_t ADev,uint16_t AObj,int32_t Axis_ID0,int32_t Axis_ID1);

//����Բ���岹���ٶ�
MT_API int32_t __stdcall MT_Set_Axis_Circle_Acc(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Circle_Acc(int32_t ADev,uint16_t AObj,int32_t Value);

//����Բ���岹���ٶ�
MT_API int32_t __stdcall MT_Set_Axis_Circle_Dec(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Circle_Dec(int32_t ADev,uint16_t AObj,int32_t Value);

//����Բ���岹�ٶ�
MT_API int32_t __stdcall MT_Set_Axis_Circle_V(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Circle_V(int32_t ADev,uint16_t AObj,int32_t Value);

//����Բ���岹���� ˳ʱ��  Բ������ģʽ
MT_API int32_t __stdcall MT_Set_Axis_Circle_R_CW_Run_Rel(uint16_t AObj,int32_t AR,int32_t Axis_Target0,int32_t Axis_Target1);

MT_API int32_t __stdcall MT_M_Set_Axis_Circle_R_CW_Run_Rel(int32_t ADev,uint16_t AObj,int32_t AR,int32_t Axis_Target0,int32_t Axis_Target1);

MT_API int32_t __stdcall MT_Set_Axis_Circle_R_CW_Run_Abs(uint16_t AObj,int32_t AR,int32_t Axis_Target0,int32_t Axis_Target1);

MT_API int32_t __stdcall MT_M_Set_Axis_Circle_R_CW_Run_Abs(int32_t ADev,uint16_t AObj,int32_t AR,int32_t Axis_Target0,int32_t Axis_Target1);

//����Բ���岹���� ��ʱ��   Բ������
MT_API int32_t __stdcall MT_Set_Axis_Circle_R_CCW_Run_Rel(uint16_t AObj,int32_t AR,int32_t Axis_Target0,int32_t Axis_Target1);

MT_API int32_t __stdcall MT_M_Set_Axis_Circle_R_CCW_Run_Rel(int32_t ADev,uint16_t AObj,int32_t AR,int32_t Axis_Target0,int32_t Axis_Target1);

MT_API int32_t __stdcall MT_Set_Axis_Circle_R_CCW_Run_Abs(uint16_t AObj,int32_t AR,int32_t Axis_Target0,int32_t Axis_Target1);

MT_API int32_t __stdcall MT_M_Set_Axis_Circle_R_CCW_Run_Abs(int32_t ADev,uint16_t AObj,int32_t AR,int32_t Axis_Target0,int32_t Axis_Target1);

//����Բ���岹ֹͣ
MT_API int32_t __stdcall MT_Set_Axis_Circle_Stop(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Axis_Circle_Stop(int32_t ADev,uint16_t AObj);

//����Բ���岹��ͣ
MT_API int32_t __stdcall MT_Set_Axis_Circle_Halt(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Axis_Circle_Halt(int32_t ADev,uint16_t AObj);

//��ȡԲ���岹ģ��
MT_API int32_t __stdcall MT_Get_Axis_Circle_Num(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Circle_Num(int32_t ADev,int32_t* pValue);

//�岹�˶�״̬
MT_API int32_t __stdcall MT_Get_Axis_Circle_Status(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Circle_Status(int32_t ADev,uint16_t AObj,int32_t* pValue);

//�岹��
MT_API int32_t __stdcall MT_Get_Axis_Circle_Axis(uint16_t AObj,int32_t* pID0,int32_t* pID1);

MT_API int32_t __stdcall MT_M_Get_Axis_Circle_Axis(int32_t ADev,uint16_t AObj,int32_t* pID0,int32_t* pID1);

//�岹���ٶ�
MT_API int32_t __stdcall MT_Get_Axis_Circle_Acc(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Circle_Acc(int32_t ADev,uint16_t AObj,int32_t* pValue);

//�岹���ٶ�
MT_API int32_t __stdcall MT_Get_Axis_Circle_Dec(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Circle_Dec(int32_t ADev,uint16_t AObj,int32_t* pValue);

//�岹�ٶ�
MT_API int32_t __stdcall MT_Get_Axis_Circle_V(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Circle_V(int32_t ADev,uint16_t AObj,int32_t* pValue);

//2014 04 09���䶨�� ������ʼ�ٶ��޸� ���Ӷ�������ֱ�߲岹
MT_API int32_t __stdcall MT_Set_Axis_Home_V_Start(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Home_V_Start(int32_t ADev,uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_Set_Axis_Home_Acc(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Home_Acc(int32_t ADev,uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_Set_Axis_Home_Dec(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Home_Dec(int32_t ADev,uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_Get_Axis_Home_Acc(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Home_Acc(int32_t ADev,uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_Get_Axis_Home_Dec(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Home_Dec(int32_t ADev,uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_Set_Axis_Velocity_V_Start(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Velocity_V_Start(int32_t ADev,uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_Set_Axis_Velocity_Acc(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Velocity_Acc(int32_t ADev,uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_Set_Axis_Velocity_Dec(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Velocity_Dec(int32_t ADev,uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_Get_Axis_Velocity_Acc(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Velocity_Acc(int32_t ADev,uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_Get_Axis_Velocity_Dec(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Velocity_Dec(int32_t ADev,uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_Set_Axis_Position_V_Start(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Position_V_Start(int32_t ADev,uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_Set_Axis_Position_Acc(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Position_Acc(int32_t ADev,uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_Set_Axis_Position_Dec(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Position_Dec(int32_t ADev,uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_Get_Axis_Position_Acc(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Position_Acc(int32_t ADev,uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_Get_Axis_Position_Dec(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Axis_Position_Dec(int32_t ADev,uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_Set_Axis_Line_V_Start(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Line_V_Start(int32_t ADev,uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_Set_Axis_Circle_V_Start(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Axis_Circle_V_Start(int32_t ADev,uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_Set_Axis_Line_X_Run_Rel(uint16_t AObj,int32_t AAxis_Num,int32_t* pAxis,int32_t* pTarget);

MT_API int32_t __stdcall MT_M_Set_Axis_Line_X_Run_Rel(int32_t ADev,uint16_t AObj,int32_t AAxis_Num,int32_t* pAxis,int32_t* pTarget);

MT_API int32_t __stdcall MT_Set_Axis_Line_X_Run_Abs(uint16_t AObj,int32_t AAxis_Num,int32_t* pAxis,int32_t* pTarget);

MT_API int32_t __stdcall MT_M_Set_Axis_Line_X_Run_Abs(int32_t ADev,uint16_t AObj,int32_t AAxis_Num,int32_t* pAxis,int32_t* pTarget);

MT_API int32_t __stdcall MT_Set_Axis_Line_X_Target_Rel(uint16_t AObj,int32_t AAxisID,int32_t ATarget);

MT_API int32_t __stdcall MT_M_Set_Axis_Line_X_Target_Rel(int32_t ADev,uint16_t AObj,int32_t AAxisID,int32_t ATarget);

MT_API int32_t __stdcall MT_Set_Axis_Line_X_Target_Abs(uint16_t AObj,int32_t AAxisID,int32_t ATarget);

MT_API int32_t __stdcall MT_M_Set_Axis_Line_X_Target_Abs(int32_t ADev,uint16_t AObj,int32_t AAxisID,int32_t ATarget);

MT_API int32_t __stdcall MT_Set_Axis_Line_X_Axis(uint16_t AObj,int32_t AAxisID,int32_t AAxis);

MT_API int32_t __stdcall MT_M_Set_Axis_Line_X_Axis(int32_t ADev,uint16_t AObj,int32_t AAxisID,int32_t AAxis);

MT_API int32_t __stdcall MT_Set_Axis_Line_X_Count(uint16_t AObj,int32_t ANum);

MT_API int32_t __stdcall MT_M_Set_Axis_Line_X_Count(int32_t ADev,uint16_t AObj,int32_t ANum);

//PLC��صĺ���
//PLC��ص�ָ����
//�������洢����С
MT_API int32_t __stdcall MT_Get_PLC_Var_Num(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_PLC_Var_Num(int32_t ADev,int32_t* pValue);

//������
MT_API int32_t __stdcall MT_Get_PLC_Var_Data(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_PLC_Var_Data(int32_t ADev,uint16_t AObj,int32_t* pValue);

//д����
MT_API int32_t __stdcall MT_Set_PLC_Var_Data(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_PLC_Var_Data(int32_t ADev,uint16_t AObj,int32_t Value);

//��ͣPLC
MT_API int32_t __stdcall MT_Set_PLC_Pause(void);

MT_API int32_t __stdcall MT_M_Set_PLC_Pause(int32_t ADev);

//ֹͣPLC
MT_API int32_t __stdcall MT_Set_PLC_Stop(void);

MT_API int32_t __stdcall MT_M_Set_PLC_Stop(int32_t ADev);

//����PLC����
MT_API int32_t __stdcall MT_Set_PLC_Run(void);

MT_API int32_t __stdcall MT_M_Set_PLC_Run(int32_t ADev);

//����PLC�������
MT_API int32_t __stdcall MT_Set_PLC_Data(uint16_t AObj,uint8_t Value);

MT_API int32_t __stdcall MT_M_Set_PLC_Data(int32_t ADev,uint16_t AObj,uint8_t Value);

//��ȡPLC��������С
MT_API int32_t __stdcall MT_Get_PLC_Code_Size(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_PLC_Code_Size(int32_t ADev,int32_t* pValue);

//2017 01 30 PLC V6 Add
//��ȡ�������
//PLC������
MT_API int32_t __stdcall MT_Get_PLC_Task_Count(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_PLC_Task_Count(int32_t ADev,int32_t* pValue);

//PLC����״̬
MT_API int32_t __stdcall MT_Get_PLC_Task_Status(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_PLC_Task_Status(int32_t ADev,uint16_t AObj,int32_t* pValue);

//�����ָ�
MT_API int32_t __stdcall MT_Get_PLC_Var_Seg(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_PLC_Var_Seg(int32_t ADev,int32_t* pValue);

//��������
MT_API int32_t __stdcall MT_Get_PLC_Var_Used(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_PLC_Var_Used(int32_t ADev,int32_t* pValue);

//PLC״̬
MT_API int32_t __stdcall MT_Get_PLC_Status(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_PLC_Status(int32_t ADev,int32_t* pValue);

//ȫ��״̬
MT_API int32_t __stdcall MT_Get_PLC_Tasks_Status(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_PLC_Tasks_Status(int32_t ADev,int32_t* pValue);

//Axis Ratio
MT_API int32_t __stdcall MT_Get_PLC_Axis_Ratio(uint16_t AObj,float* pValue);

MT_API int32_t __stdcall MT_M_Get_PLC_Axis_Ratio(int32_t ADev,uint16_t AObj,float* pValue);

MT_API int32_t __stdcall MT_Get_PLC_Encoder_Ratio(uint16_t AObj,float* pValue);

MT_API int32_t __stdcall MT_M_Get_PLC_Encoder_Ratio(int32_t ADev,uint16_t AObj,float* pValue);

//��ָ��ģʽ
//����Stream
MT_API int32_t __stdcall MT_Set_Stream_Run(void);

MT_API int32_t __stdcall MT_M_Set_Stream_Run(int32_t ADev);

//ֹͣStream
MT_API int32_t __stdcall MT_Set_Stream_Stop(void);

MT_API int32_t __stdcall MT_M_Set_Stream_Stop(int32_t ADev);

//��ͣStream
MT_API int32_t __stdcall MT_Set_Stream_Pause(void);

MT_API int32_t __stdcall MT_M_Set_Stream_Pause(int32_t ADev);

//���Stream
MT_API int32_t __stdcall MT_Set_Stream_Clear(void);

MT_API int32_t __stdcall MT_M_Set_Stream_Clear(int32_t ADev);

//��ȡʣ��ռ�
MT_API int32_t __stdcall MT_Get_Stream_Space(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Stream_Space(int32_t ADev,int32_t* pValue);

//��ȡ�ܿռ�
MT_API int32_t __stdcall MT_Get_Stream_Total(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Stream_Total(int32_t ADev,int32_t* pValue);

//��ȡ�ܿռ�
MT_API int32_t __stdcall MT_Get_Stream_Count(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Stream_Count(int32_t ADev,int32_t* pValue);

//����ָ����broadcast�д洢����Stream����
MT_API int32_t __stdcall MT_Set_Stream_Delay(int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Stream_Delay(int32_t ADev,int32_t Value);

//ֱ�߲岹�˶�
//����ֱ�߲岹���ٶ�
MT_API int32_t __stdcall MT_Set_Stream_Line_Acc(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Stream_Line_Acc(int32_t ADev,uint16_t AObj,int32_t Value);

//����ֱ�߲岹���ٶ�
MT_API int32_t __stdcall MT_Set_Stream_Line_Dec(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Stream_Line_Dec(int32_t ADev,uint16_t AObj,int32_t Value);

//����ֱ�߲岹�ٶ�
MT_API int32_t __stdcall MT_Set_Stream_Line_V_Max(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Stream_Line_V_Max(int32_t ADev,uint16_t AObj,int32_t Value);

//����ֱ�߲岹�����ٶ�
MT_API int32_t __stdcall MT_Set_Stream_Line_V_Start(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Stream_Line_V_Start(int32_t ADev,uint16_t AObj,int32_t Value);

//����ֱ�߲岹ֹͣ
MT_API int32_t __stdcall MT_Set_Stream_Line_Stop(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Stream_Line_Stop(int32_t ADev,uint16_t AObj);

//����ֱ�߲岹��ͣ
MT_API int32_t __stdcall MT_Set_Stream_Line_Halt(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Stream_Line_Halt(int32_t ADev,uint16_t AObj);

//����ֱ�߲岹
MT_API int32_t __stdcall MT_Set_Stream_Line_X_Run_Rel(uint16_t AObj,int32_t AAxis_Num,int32_t* pAxis,int32_t* pTarget);

MT_API int32_t __stdcall MT_M_Set_Stream_Line_X_Run_Rel(int32_t ADev,uint16_t AObj,int32_t AAxis_Num,int32_t* pAxis,int32_t* pTarget);

MT_API int32_t __stdcall MT_Set_Stream_Line_X_Run_Abs(uint16_t AObj,int32_t AAxis_Num,int32_t* pAxis,int32_t* pTarget);

MT_API int32_t __stdcall MT_M_Set_Stream_Line_X_Run_Abs(int32_t ADev,uint16_t AObj,int32_t AAxis_Num,int32_t* pAxis,int32_t* pTarget);

//����Բ���岹���ἰ�ٶ�
MT_API int32_t __stdcall MT_Set_Stream_Circle_Axis(uint16_t AObj,int32_t Axis_ID0,int32_t Axis_ID1);

MT_API int32_t __stdcall MT_M_Set_Stream_Circle_Axis(int32_t ADev,uint16_t AObj,int32_t Axis_ID0,int32_t Axis_ID1);

//����Բ���岹���ٶ�
MT_API int32_t __stdcall MT_Set_Stream_Circle_Acc(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Stream_Circle_Acc(int32_t ADev,uint16_t AObj,int32_t Value);

//����Բ���岹���ٶ�
MT_API int32_t __stdcall MT_Set_Stream_Circle_Dec(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Stream_Circle_Dec(int32_t ADev,uint16_t AObj,int32_t Value);

//����Բ���岹�ٶ�
MT_API int32_t __stdcall MT_Set_Stream_Circle_V_Max(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Stream_Circle_V_Max(int32_t ADev,uint16_t AObj,int32_t Value);

//����Բ���岹�����ٶ�
MT_API int32_t __stdcall MT_Set_Stream_Circle_V_Start(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Stream_Circle_V_Start(int32_t ADev,uint16_t AObj,int32_t Value);

//����Բ���岹���� ˳ʱ��  Բ������ģʽ
MT_API int32_t __stdcall MT_Set_Stream_Circle_R_CW_Run_Rel(uint16_t AObj,int32_t AR,int32_t Axis_Target0,int32_t Axis_Target1);

MT_API int32_t __stdcall MT_M_Set_Stream_Circle_R_CW_Run_Rel(int32_t ADev,uint16_t AObj,int32_t AR,int32_t Axis_Target0,int32_t Axis_Target1);

MT_API int32_t __stdcall MT_Set_Stream_Circle_R_CW_Run_Abs(uint16_t AObj,int32_t AR,int32_t Axis_Target0,int32_t Axis_Target1);

MT_API int32_t __stdcall MT_M_Set_Stream_Circle_R_CW_Run_Abs(int32_t ADev,uint16_t AObj,int32_t AR,int32_t Axis_Target0,int32_t Axis_Target1);

//����Բ���岹���� ��ʱ��   Բ������
MT_API int32_t __stdcall MT_Set_Stream_Circle_R_CCW_Run_Rel(uint16_t AObj,int32_t AR,int32_t Axis_Target0,int32_t Axis_Target1);

MT_API int32_t __stdcall MT_M_Set_Stream_Circle_R_CCW_Run_Rel(int32_t ADev,uint16_t AObj,int32_t AR,int32_t Axis_Target0,int32_t Axis_Target1);

MT_API int32_t __stdcall MT_Set_Stream_Circle_R_CCW_Run_Abs(uint16_t AObj,int32_t AR,int32_t Axis_Target0,int32_t Axis_Target1);

MT_API int32_t __stdcall MT_M_Set_Stream_Circle_R_CCW_Run_Abs(int32_t ADev,uint16_t AObj,int32_t AR,int32_t Axis_Target0,int32_t Axis_Target1);

//����Բ���岹ֹͣ
MT_API int32_t __stdcall MT_Set_Stream_Circle_Stop(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Stream_Circle_Stop(int32_t ADev,uint16_t AObj);

//����Բ���岹��ͣ
MT_API int32_t __stdcall MT_Set_Stream_Circle_Halt(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Stream_Circle_Halt(int32_t ADev,uint16_t AObj);

MT_API int32_t __stdcall MT_Set_Stream_Wait_Line(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Stream_Wait_Line(int32_t ADev,uint16_t AObj);

MT_API int32_t __stdcall MT_Set_Stream_Wait_Circle(uint16_t AObj);

MT_API int32_t __stdcall MT_M_Set_Stream_Wait_Circle(int32_t ADev,uint16_t AObj);

//���õ�ͨ��ֵ
MT_API int32_t __stdcall MT_Set_Stream_OC_Out_Single(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Stream_OC_Out_Single(int32_t ADev,uint16_t AObj,int32_t Value);

//��������ͨ��ֵ
MT_API int32_t __stdcall MT_Set_Stream_OC_Out_All(int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Stream_OC_Out_All(int32_t ADev,int32_t Value);

//���õ�ͨ��ֵ
MT_API int32_t __stdcall MT_Set_Stream_Optic_Out_Single(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Stream_Optic_Out_Single(int32_t ADev,uint16_t AObj,int32_t Value);

//��������ͨ��ֵ
MT_API int32_t __stdcall MT_Set_Stream_Optic_Out_All(int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Stream_Optic_Out_All(int32_t ADev,int32_t Value);

//���ٹ���
MT_API int32_t __stdcall MT_Set_Stream_Dec_Enable(void);

MT_API int32_t __stdcall MT_M_Set_Stream_Dec_Enable(int32_t ADev);

MT_API int32_t __stdcall MT_Set_Stream_Dec_Disable(void);

MT_API int32_t __stdcall MT_M_Set_Stream_Dec_Disable(int32_t ADev);

//2016 08 20 ���ӵȴ����빦��
//�ȴ�Optic_In״̬
MT_API int32_t __stdcall MT_Set_Stream_Wait_Optic_In(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Stream_Wait_Optic_In(int32_t ADev,uint16_t AObj,int32_t Value);

//����Stream,������У�鹦��
MT_API int32_t __stdcall MT_Set_Stream_Run_Check(void);

MT_API int32_t __stdcall MT_M_Set_Stream_Run_Check(int32_t ADev);

//2019 09 15 running id for UI
MT_API int32_t __stdcall MT_Set_Stream_Run_ID(int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Stream_Run_ID(int32_t ADev,int32_t Value);

MT_API int32_t __stdcall MT_Get_Stream_Run_ID(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Stream_Run_ID(int32_t ADev,int32_t* pValue);

//����������
MT_API int32_t __stdcall MT_Get_Encoder_Num(int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Encoder_Num(int32_t ADev,int32_t* pValue);

MT_API int32_t __stdcall MT_Get_Encoder_Pos(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Encoder_Pos(int32_t ADev,uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_Set_Encoder_Pos(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Encoder_Pos(int32_t ADev,uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_Set_Encoder_Z_Polarity(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Encoder_Z_Polarity(int32_t ADev,uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_Set_Encoder_Dir_Polarity(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Encoder_Dir_Polarity(int32_t ADev,uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_Get_Encoder_Index_Line_Count(uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_M_Get_Encoder_Index_Line_Count(int32_t ADev,uint16_t AObj,int32_t* pValue);

MT_API int32_t __stdcall MT_Set_Encoder_Over_Enable(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Encoder_Over_Enable(int32_t ADev,uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_Set_Encoder_Over_Max(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Encoder_Over_Max(int32_t ADev,uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_Set_Encoder_Over_Stable(uint16_t AObj,int32_t Value);

MT_API int32_t __stdcall MT_M_Set_Encoder_Over_Stable(int32_t ADev,uint16_t AObj,int32_t Value);

//�������㹫ʽ
//mm to pluse
MT_API int32_t __stdcall MT_Help_Step_Line_Real_To_Steps(double AStepAngle,int32_t ADiv,double APitch,double ALineRatio,double AValue);

MT_API int32_t __stdcall MT_Help_Step_Circle_Real_To_Steps(double AStepAngle,int32_t ADiv,double ACircleRatio,double AValue);

//pluse to mm
MT_API double __stdcall MT_Help_Step_Line_Steps_To_Real(double AStepAngle,int32_t ADiv,double APitch,double ALineRatio,int32_t AValue);

MT_API double __stdcall MT_Help_Step_Circle_Steps_To_Real(double AStepAngle,int32_t ADiv,double ACircleRatio,int32_t AValue);

//Encoder
//����������λ����
MT_API int32_t __stdcall MT_Help_Encoder_Line_Real_To_Steps(double APitch,double ALineRatio,int32_t ALineCount,double AValue);

MT_API int32_t __stdcall MT_Help_Encoder_Circle_Real_To_Steps(double ACircleRatio,int32_t ALineCount,double AValue);

//pluse to mm
MT_API double __stdcall MT_Help_Encoder_Line_Steps_To_Real(double APitch,double ALineRatio,int32_t ALineCount,int32_t AValue);

MT_API double __stdcall MT_Help_Encoder_Circle_Steps_To_Real(double ACircleRatio,int32_t ALineCount,int32_t AValue);

//Grating
//����������λ����
MT_API int32_t __stdcall MT_Help_Grating_Line_Real_To_Steps(double AUnit_um,double AValue);

MT_API int32_t __stdcall MT_Help_Grating_Circle_Real_To_Steps(int32_t ALineCount,double AValue);

//pluse to mm
MT_API double __stdcall MT_Help_Grating_Line_Steps_To_Real(double AUnit_um,int32_t AValue);

MT_API double __stdcall MT_Help_Grating_Circle_Steps_To_Real(int32_t ALineCount,int32_t AValue);

MT_API float __stdcall MT_Help_Encoder_Factor(double AStepAngle,int32_t ADiv,int32_t ALineCount);

//��դ�߰�װ�ڻ�е�ϣ������ת����һ�£���Ҫ���ǻ�е��Ӱ��
MT_API float __stdcall MT_Help_Grating_Line_Factor(double AStepAngle,int32_t ADiv,double APitch,double ALineRatio,double AUnit_um);

MT_API float __stdcall MT_Help_Grating_Circle_Factor(double AStepAngle,int32_t ADiv,double ACircleRatio,int32_t ALineCount);

//�����ڲ���Դ����
#endif

