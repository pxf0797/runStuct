/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : CpnSch2.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2020/01/01 13:18:37
* Description  : CpnSch2������ܺ�������Դ�ļ�
* Others       : 
* History      : 200101 pxf ���ν���
***************************************************************************/

/*ͷ�ļ�����*/
#include "./CpnSch2.h"

/***********************************************************
* CpnSch2�ඨ��
***********************************************************/
/*���� : CpnSch2_run(hCpnSch2 cthis)
* ���� : cthis - CpnSch2��ָ��
* ��� : ��
* ���� : CpnSch2�๦�ܺ���
***********************************************/
void CpnSch2_run(hCpnSch2 cthis){
    //TODO
}

/*���� : CpnSch2_tick(hCpnSch2 cthis)
* ���� : cthis - CpnSch2��ָ��
* ��� : ��
* ���� : CpnSch2�๦�ܺ���
***********************************************/
void CpnSch2_tick(hCpnSch2 cthis){
    //TODO
}

/*���� : CpnSch2_now(hCpnSch2 cthis)
* ���� : cthis - CpnSch2��ָ��
* ��� : ��
* ���� : CpnSch2�๦�ܺ���
***********************************************/
void CpnSch2_now(hCpnSch2 cthis){
    //TODO
}

/*���� : CpnSch2_delay(hCpnSch2 cthis)
* ���� : cthis - CpnSch2��ָ��
* ��� : ��
* ���� : CpnSch2�๦�ܺ���
***********************************************/
void CpnSch2_delay(hCpnSch2 cthis){
    //TODO
}

/*���� : CpnSch2_addTask(hCpnSch2 cthis)
* ���� : cthis - CpnSch2��ָ��
* ��� : ��
* ���� : CpnSch2�๦�ܺ���
***********************************************/
void CpnSch2_addTask(hCpnSch2 cthis){
    //TODO
}

/*���� : CpnSch2_delTask(hCpnSch2 cthis)
* ���� : cthis - CpnSch2��ָ��
* ��� : ��
* ���� : CpnSch2�๦�ܺ���
***********************************************/
void CpnSch2_delTask(hCpnSch2 cthis){
    //TODO
}

/*���� : hCpnSch2 CpnSch2_init(hCpnSch2 cthis)
* ���� : cthis - CpnSch2��ָ��
* ��� : hCpnSch2 - cthis/OOPC_NULL
* ���� : CpnSch2���ʼ������
***********************************************/
hCpnSch2 CpnSch2_init(hCpnSch2 cthis){
    // ���ܺ�������
    //cthis->run = CpnSch2_run;
    //TODO

    // ��������
    //TODO

    return cthis;
}

/*���� : hCpnSch2 CpnSch2_ctor(hCpnSch2 cthis)
* ���� : cthis - CpnSch2��ָ��
* ��� : hCpnSch2 - cthis/OOPC_NULL
* ���� : CpnSch2�๹�캯��
***********************************************/
CC(CpnSch2){
    cthis->init = CpnSch2_init;
    cthis->run = CpnSch2_run;
    cthis->tick = CpnSch2_tick;
    cthis->now = CpnSch2_now;
    cthis->delay = CpnSch2_delay;
    cthis->addTask = CpnSch2_addTask;
    cthis->delTask = CpnSch2_delTask;
    //TODO

    // ��������
    //TODO
    return cthis;
}

/*���� : hCpnSch2 CpnSch2_dtor(hCpnSch2 cthis)
* ���� : cthis - CpnSch2��ָ��
* ��� : OOPC_RETURN_DATATYPE - OOPC_TRUE/OOPC_FALSE
* ���� : CpnSch2����������
***********************************************/
CD(CpnSch2){
    return OOPC_TRUE;
}

/**************************** Copyright(C) pxf ****************************/
