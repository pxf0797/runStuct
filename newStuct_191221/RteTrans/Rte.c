/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : Rte.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/21 11:55:05
* Description  : Rte������ܺ�������Դ�ļ�
* Others       : 
* History      : 191221 pxf ���ν���
***************************************************************************/

/*ͷ�ļ�����*/
#include "./Rte.h"

/***********************************************************
* Rte�ඨ��
***********************************************************/
/*���� : Rte_run(hRte cthis)
* ���� : cthis - Rte��ָ��
* ��� : ��
* ���� : Rte�๦�ܺ���
***********************************************/
void Rte_run(hRte cthis){
    //TODO
}

/*���� : hRte Rte_init(hRte cthis)
* ���� : cthis - Rte��ָ��
* ��� : hRte - cthis/OOPC_NULL
* ���� : Rte���ʼ������
***********************************************/
hRte Rte_init(hRte cthis){
    // ���ܺ�������
    //cthis->run = Rte_run;
    //TODO

    // ��������
    //TODO

    return cthis;
}

/*���� : hRte Rte_ctor(hRte cthis)
* ���� : cthis - Rte��ָ��
* ��� : hRte - cthis/OOPC_NULL
* ���� : Rte�๹�캯��
***********************************************/
CC(Rte){
    cthis->init = Rte_init;
    cthis->run = Rte_run;
    //TODO

    // ��������
    //TODO
    return cthis;
}

/*���� : hRte Rte_dtor(hRte cthis)
* ���� : cthis - Rte��ָ��
* ��� : OOPC_RETURN_DATATYPE - OOPC_TRUE/OOPC_FALSE
* ���� : Rte����������
***********************************************/
CD(Rte){
    return OOPC_TRUE;
}

/**************************** Copyright(C) pxf ****************************/
