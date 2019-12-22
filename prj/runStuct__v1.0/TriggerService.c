/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : TriggerService.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/22 08:25:43
* Description  : 
* Others       : 
* History      : 191222 pxf ���ν���
***************************************************************************/

/*ͷ�ļ�����*/
#include "./TriggerService.h"
#include "./RteSyn.h"

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// �����ź�Ԥ�ȶ����
uint16 serv1Cnt = 0;
void cpn1_serv1_serv(void){
    serv1Cnt++;
}

uint32 ulServ2Unpack = 0;
void cpn1_serv2_serv(void *buff, uint16 buffLen){
    if(sizeof(ulServ2Unpack) == buffLen){
        ulServ2Unpack = *(uint32*)buff;
    }
}

uint8 ucServ3Buff[5] = {0};
void cpn1_serv3_serv(void *buff, uint16 buffLen){
    if(sizeof(ucServ3Buff) == buffLen){
        ucServ3Buff[0] = ((uint8*)buff)[0];
        ucServ3Buff[1] = ((uint8*)buff)[1];
        ucServ3Buff[2] = ((uint8*)buff)[2];
        ucServ3Buff[3] = ((uint8*)buff)[3];
        ucServ3Buff[4] = ((uint8*)buff)[4];
    }
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>



// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// ��Ҫ��ͷ�ļ��н��ж��壬��Ҫ���������ݣ��ź��б�ע���źź��ź�ӳ��
// ע���ź���Ҫ����Ҫ����һ��ͳһ��ע������

// ���������ź��б�
// �����ź�һ��Ҫ�����봥���ź�һ�µĴ��������������ͣ�����ʶ���С���������������ź�
#define SIGNAL_SERV_LIST(_)                                           \
    _(cpn1_serv1,cpn1_serv1_serv,0)                                   \
    _(cpn1_serv2,cpn1_serv2_serv,sizeof(ulServ2Unpack))               \
    _(cpn1_serv3,cpn1_serv3_serv,sizeof(ucServ3Buff))                 \

// ���������ź��б����ӳ�䣬�����ź�ʱ��Ҫ���������źŵĳ��ȣ�Ĭ��һ�£�����ʱ��Ҫ���б���
// �����ź����Ͷ�����Զ����ڷ����������ͣ�ֻҪ��֤��Сһ��
#define SIGNAL_TRIG_MAP_LIST(_)                                       \
    _(cpn2_trig1,cpn1_serv2,sizeof(ulServ2Unpack))                    \
    _(cpn2_trig2,cpn1_serv3,sizeof(ucServ3Buff))                      \
    _(cpn2_trig3,cpn1_serv1,0)                                        \


// ������Ҫע��ķ��񴥷��ź�
#define SYN_SERV_SIGNAL_REGISTER(signal_serv,serv,len)                 SIGNAL_SERV_REGISTER(RteSyn,signal_serv,serv,len)
#define SYN_TRIG_SIGNAL_REGISTER(signal_trig,signal_serv,len)          SIGNAL_TRIG_REGISTER(RteSyn,signal_trig,signal_serv,len)

// �������񴥷��ź�ӳ��
SIGNAL_SERVTRIG_MAP(RteSyn,SIGNAL_SERV_LIST,SIGNAL_TRIG_MAP_LIST);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// ��Ҫ��Դ�ļ����ж����ʹ�ã���Ҫ���������ݣ����涨����źŽ���ע��

// ������񴥷��źŻ���
BUFF_SERVTRIG_DEFINE(RteSyn,SIGNAL_SERV_LIST,SIGNAL_TRIG_MAP_LIST);

// ������񴥷���
RteSyn clRteSyn;

void ServTrigInit(void)
{
    // ���źŽ���ע��
    SIGNALS_SERVTRIG_REGISTER(SIGNAL_SERV_LIST,SYN_SERV_SIGNAL_REGISTER);
    SIGNALS_SERVTRIG_REGISTER(SIGNAL_TRIG_MAP_LIST,SYN_TRIG_SIGNAL_REGISTER);

    // ��ʼ��������
    CN(RteSyn,&clRteSyn,RteSynSigServParamLen,RteSynSigServBuff,RteSynSigTrigIndex);
}


// �źŽ��д���
uint32 ulTrig1Pack = 0;
void cpn2_trig1_trig(void *buff, uint16 buffLen)
{
    clRteSyn.trig(clRteSyn.self, cpn2_trig1, &ulTrig1Pack, sizeof(ulTrig1Pack));
}

uint8 ucTirg2Buff[5] = {0};
void cpn2_trig2_trig(void *buff, uint16 buffLen)
{
    clRteSyn.trig(clRteSyn.self, cpn2_trig2, ucTirg2Buff, sizeof(ucTirg2Buff));
}

void cpn2_trig3_trig(void)
{
    clRteSyn.trig(clRteSyn.self, cpn2_trig3, NULL, 0);
}


void ServTrigRun(void)
{
    static uint8 servTrigCnt = 0;
    servTrigCnt++;

    ulTrig1Pack += servTrigCnt;
    ucTirg2Buff[0] += servTrigCnt;

    cpn2_trig1_trig(&ulTrig1Pack,sizeof(ulTrig1Pack));
    cpn2_trig2_trig(ucTirg2Buff,sizeof(ucTirg2Buff));
    cpn2_trig3_trig();
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>



/**************************** Copyright(C) pxf ****************************/
