/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : RteAsynSigs.h
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/28 23:08:12
* Description  : 
* Others       : 
* History      : 191228 pxf ���ν���
***************************************************************************/

#ifndef RTEASYNSIGS_H_
#define RTEASYNSIGS_H_

/*ͷ�ļ�����*/
#include "../standType/standType.h"
#include "../Rte/RteAsyn.h"
#include "../Rte/RteSyn.h"
#include "../Rte/SetGet.h"

// ���������ź��б�
#define SIGNAL_SET_LIST_RTEASYN(_)        \
    _(cpn1_send1,1)                       \
    _(cpn1_send2,4)                       \
    _(cpn1_send3,3)                       \

// ���������ź��б����ӳ�䣬�����ź�ʱ��Ҫ����뷢���źŵĳ��ȣ�Ĭ��һ�£�����ʱ��Ҫ���б���
#define SIGNAL_GET_MAP_LIST_RTEASYN(_)    \
    _(cpn2_receive1,cpn1_send2)           \
    _(cpn2_receive2,cpn1_send1)           \
    _(cpn2_receive3,cpn1_send3)           \


// ������Ҫע����շ��ź�
#define ASYN_SET_SIGNAL_REGISTER(signal_set,len)                SIGNAL_SET_REGISTER(RteAsynSigs,signal_set,len)
#define ASYN_GET_SIGNAL_REGISTER(signal_get,signal_set)         SIGNAL_GET_REGISTER(RteAsynSigs,signal_get,signal_set)

// �����շ��źŸ���ӳ���ϵ
SIGNAL_SETGET_MAP(RteAsynSigs,SIGNAL_SET_LIST_RTEASYN,SIGNAL_GET_MAP_LIST_RTEASYN);

// �첽�źų�ʼ������
void RteAsynSetGetInit(void);

// �����շ���
extern RteAsyn clRteAsynSigs;

#endif /*RTEASYNSIGS_H_*/

/**************************** Copyright(C) pxf ****************************/
