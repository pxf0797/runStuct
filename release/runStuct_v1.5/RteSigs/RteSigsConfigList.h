/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : RteSigsConfigList.h
* Author       : pxf
* Version      : v1.0
* Created on   : 2020/02/26 10:34:30
* Description  : 
* Others       : 
* History      : 200226 pxf ���ν���
***************************************************************************/

#ifndef RTESIGSCONFIGLIST_H_
#define RTESIGSCONFIGLIST_H_

/*ͷ�ļ�����*/
#include "../Rte/Rte.h"

/*����ź�*/
#include "../Abi/AbiSigs.h"
#include "../CpnSch/CpnSchSigs.h"
// #include "../CpnSigs/Cpn1.h"
// #include "../CpnSigs/Cpn2.h"
// #include "../CpnSigs/Cpn3.h"
// #include "../CpnSigs/Cpn4.h"

/***********************************************************
* get set�ź��б�
***********************************************************/
/*�����ź��б�
***********************************************/
#define SIGNAL_SET_LIST_RTEASYN(_)                         \
        // SIGNAL_SET_LIST_RTEASYN_CPN1(_)                    \
        // SIGNAL_SET_LIST_RTEASYN_CPN3(_)                    \

/*�����ź��б�
* �����ź�ʱ��Ҫ��鷢���źŵĳ��ȶ��źŽ���ӳ��
***********************************************/
#define SIGNAL_GET_MAP_LIST_RTEASYN(_)                     \
        // SIGNAL_GET_MAP_LIST_RTEASYN_CPN2(_)                \
        // SIGNAL_GET_MAP_LIST_RTEASYN_CPN4(_)                \


/***********************************************************
* trig serv�ź��б�
***********************************************************/
/*�����ź��б�
***********************************************/
#define SIGNAL_SERV_LIST_RTESYN(_)                         \
        SIGNAL_SERV_LIST_RTESYN_ABI(_)                     \
        SIGNAL_SERV_LIST_RTESYN_CPNSCH(_)                  \
        // SIGNAL_SERV_LIST_RTESYN_CPN1(_)                    \
        // SIGNAL_SERV_LIST_RTESYN_CPN2(_)                    \
        // SIGNAL_SERV_LIST_RTESYN_CPN3(_)                    \
        // SIGNAL_SERV_LIST_RTESYN_CPN4(_)                    \

/*�����ź��б�
* �����ź�ʱ��Ҫ�������źŵĳ��ȶ��źŽ���ӳ��
***********************************************/
#define SIGNAL_TRIG_MAP_LIST_RTESYN(_)                     \
        SIGNAL_TRIG_MAP_LIST_RTESYN_ABI(_)                 \
        SIGNAL_TRIG_MAP_LIST_RTESYN_CPNSCH(_)              \
        // SIGNAL_TRIG_MAP_LIST_RTESYN_CPN1(_)                \
        // SIGNAL_TRIG_MAP_LIST_RTESYN_CPN2(_)                \
        // SIGNAL_TRIG_MAP_LIST_RTESYN_CPN3(_)                \
        // SIGNAL_TRIG_MAP_LIST_RTESYN_CPN4(_)                \


#endif /*RTESIGSCONFIGLIST_H_*/

/**************************** Copyright(C) pxf ****************************/
