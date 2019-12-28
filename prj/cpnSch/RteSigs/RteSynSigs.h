/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : RteSynSigs.h
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/28 23:08:24
* Description  : 
* Others       : 
* History      : 191228 pxf ���ν���
***************************************************************************/

#ifndef RTESYNSIGS_H_
#define RTESYNSIGS_H_

/*ͷ�ļ�����*/
#include "../standType/standType.h"
#include "../Rte/RteAsyn.h"
#include "../Rte/RteSyn.h"
#include "../Rte/TriggerService.h"
#include "../RteSigs.h"

// ���������ź��б�
// �����ź�һ��Ҫ�����봥���ź�һ�µĴ��������������ͣ�����ʶ���С���������������ź�
#define SIGNAL_SERV_LIST_RTESYN(_)                                    \
    _(cpn1_serv1,cpn1_serv1_serv,0)                                   \
    _(cpn1_serv2,cpn1_serv2_serv,sizeof(ulServ2Unpack))               \
    _(cpn1_serv3,cpn1_serv3_serv,sizeof(ucServ3Buff))                 \

// ���������ź��б����ӳ�䣬�����ź�ʱ��Ҫ���������źŵĳ��ȣ�Ĭ��һ�£�����ʱ��Ҫ���б���
// �����ź����Ͷ�����Զ����ڷ����������ͣ�ֻҪ��֤��Сһ��
#define SIGNAL_TRIG_MAP_LIST_RTESYN(_)                                \
    _(cpn2_trig1,cpn1_serv2,sizeof(ulServ2Unpack))                    \
    _(cpn2_trig2,cpn1_serv3,sizeof(ucServ3Buff))                      \
    _(cpn2_trig3,cpn1_serv1,0)                                        \


// ������Ҫע��ķ��񴥷��ź�
#define SYN_SERV_SIGNAL_REGISTER(signal_serv,serv,len)                 SIGNAL_SERV_REGISTER(RteSynSigs,signal_serv,serv,len)
#define SYN_TRIG_SIGNAL_REGISTER(signal_trig,signal_serv,len)          SIGNAL_TRIG_REGISTER(RteSynSigs,signal_trig,signal_serv,len)

// �������񴥷��ź�ӳ��
SIGNAL_SERVTRIG_MAP(RteSynSigs,SIGNAL_SERV_LIST_RTESYN,SIGNAL_TRIG_MAP_LIST_RTESYN);

// ͬ���źų�ʼ������
void RetSynServTrigInit(void);

// ������񴥷���
extern RteSyn clRteSynSigs;

#endif /*RTESYNSIGS_H_*/

/**************************** Copyright(C) pxf ****************************/
