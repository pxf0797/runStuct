/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : CpnSch2.h
* Author       : pxf
* Version      : v1.0
* Created on   : 2020/01/01 13:18:37
* Description  : CpnSch2�༰�ӿ�����ͷ�ļ�
* Others       : 
* History      : 200101 pxf ���ν���
***************************************************************************/

#ifndef CPNSCH2_H_
#define CPNSCH2_H_

/*ͷ�ļ�����*/
#include "./oopc_v1.02/oopc.h"

/***********************************************************
* �ӿڶ���
***********************************************************/
/*�ӿ�����
***********************************************/
//INF(get){
//  uint16(*get)(void);
//};
//TODO

/***********************************************************
* CpnSch2�ඨ��
***********************************************************/
/*CpnSch2������
***********************************************/
CL(CpnSch2){
    hCpnSch2 self;
    hCpnSch2 (*init)(hCpnSch2 cthis);

    // CpnSch2�����
    //TODO

    // CpnSch2�๦�ܺ���
    void (*run)(hCpnSch2 cthis);
    void (*tick)(hCpnSch2 cthis);
    void (*now)(hCpnSch2 cthis);
    void (*delay)(hCpnSch2 cthis);
    void (*addTask)(hCpnSch2 cthis);
    void (*delTask)(hCpnSch2 cthis);
    //TODO
};

#endif /*CPNSCH2_H_*/

/**************************** Copyright(C) pxf ****************************/
