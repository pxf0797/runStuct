/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : SetGet.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/22 07:34:13
* Description  : 
* Others       : 
* History      : 191222 pxf ���ν���
***************************************************************************/

/*ͷ�ļ�����*/
#include "./SetGet.h"
#include "./RteAsyn.h"

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// ��Ҫ��ͷ�ļ��н��ж��壬��Ҫ���������ݣ��ź��б�ע���źź��ź�ӳ��
// ע���ź���Ҫ����Ҫ����һ��ͳһ��ע������

// ���������ź��б�
#define SIGNAL_SET_LIST(_)                \
    _(cpn1_send1,1)                       \
    _(cpn1_send2,4)                       \
    _(cpn1_send3,3)                       \

// ���������ź��б����ӳ�䣬�����ź�ʱ��Ҫ����뷢���źŵĳ��ȣ�Ĭ��һ�£�����ʱ��Ҫ���б���
#define SIGNAL_GET_MAP_LIST(_)            \
    _(cpn2_receive1,cpn1_send2)           \
    _(cpn2_receive2,cpn1_send1)           \
    _(cpn2_receive3,cpn1_send3)           \


// ������Ҫע����շ��ź�
#define ASYN_SET_SIGNAL_REGISTER(signal_set,len)                SIGNAL_SET_REGISTER(RteAsyn,signal_set,len)
#define ASYN_GET_SIGNAL_REGISTER(signal_get,signal_set)         SIGNAL_GET_REGISTER(RteAsyn,signal_get,signal_set)

// �����շ��źŸ���ӳ���ϵ
SIGNAL_SETGET_MAP(RteAsyn,SIGNAL_SET_LIST,SIGNAL_GET_MAP_LIST);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// ��Ҫ��Դ�ļ����ж����ʹ�ã���Ҫ���������ݣ����涨����źŽ���ע��

// �����շ��źŻ���
BUFF_SETGET_DEFINE(RteAsyn,SIGNAL_SET_LIST,SIGNAL_GET_MAP_LIST);

// �����շ���
RteAsyn clRteAsyn;

// �շ��ź�
uint8 ucSendChar = 0xA5;
uint32 ulSendLong = 0x1234578;
uint8 ucSendChar3[3] = {0x11,0x22,0x33};
uint8 ucReceiveChar = 0;
uint32 ulReceiveLong = 0;
uint8 ucReceiveChar3[3] = {0};

void SetGetInit(void)
{
    // ���źŽ���ע��
    SIGNALS_GETSET_REGISTER(SIGNAL_SET_LIST,ASYN_SET_SIGNAL_REGISTER);
    SIGNALS_GETSET_REGISTER(SIGNAL_GET_MAP_LIST,ASYN_GET_SIGNAL_REGISTER);

    // ��ʼ��������
    CN(RteAsyn,&clRteAsyn,RteAsynSigSetBuff,RteAsynSigSetIndex,RteAsynSigGetIndex);

}

void SetGetRun(void)
{
    static uint8 setGetCnt = 0;
    setGetCnt++;

    ucSendChar += setGetCnt;
    ulSendLong += setGetCnt;
    ucSendChar3[0] += setGetCnt;

    clRteAsyn.set(clRteAsyn.self,cpn1_send1,&ucSendChar,sizeof(ucSendChar));
    clRteAsyn.set(clRteAsyn.self,cpn1_send2,&ulSendLong,sizeof(ulSendLong));
    clRteAsyn.set(clRteAsyn.self,cpn1_send3,ucSendChar3,sizeof(ucSendChar3));

    clRteAsyn.get(clRteAsyn.self,cpn2_receive1,&ulReceiveLong,sizeof(ulReceiveLong));
    clRteAsyn.get(clRteAsyn.self,cpn2_receive2,&ucReceiveChar,sizeof(ucReceiveChar));
    clRteAsyn.get(clRteAsyn.self,cpn2_receive3,ucReceiveChar3,sizeof(ucReceiveChar3));
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

/**************************** Copyright(C) pxf ****************************/
