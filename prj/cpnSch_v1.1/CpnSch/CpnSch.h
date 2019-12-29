/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : CpnSch.h
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/28 14:16:09
* Description  : CpnSch�༰�ӿ�����ͷ�ļ�
* Others       : 
* History      : 191228 pxf ���ν���
***************************************************************************/

#ifndef CPNSCH_H_
#define CPNSCH_H_

/*ͷ�ļ�����*/
#include "../oopc_v1.02/oopc.h"
#include "../standType/standType.h"
#include "./CpnSchCfg.h"
#include "./SchSm.h"

/***********************************************************
* �ӿڶ���
***********************************************************/
/*�ӿ�����
***********************************************/
INF(iTime){
    void (*getTime)(uint16 *point);
};
INF(iErr){
    void (*setErr)(uint16 id, uint16 code);
};

/***********************************************************
* CpnSch�ඨ��
***********************************************************/
/*����ȼ�
***********************************************/
typedef enum{
    level0 = 0,
    level1,
    level2,
    level3
} taskLevel;

/*CpnSch������
***********************************************/
CL(CpnSch){
    hCpnSch self;
    hCpnSch (*init)(hCpnSch cthis, hstaAct SchSm,
            void (*getTime)(uint16 *point),
            void (*setErr)(uint16 id, uint16 code));

    // CpnSch�����
    uint16 usage;            // cpuʹ���ʣ���112��ʾ11.2%
    uint16 currTaskTime;     // ��ǰ����ִ��ʱ��
    uint16 totalTaskTime;    // ������ִ��ʱ��

    // �������״̬��
    SchSmRec SchSmRec;
    hstaAct SchSm;

    // �������������Ҫ�����ã�
    void (*tick)(hCpnSch cthis);
    void (*run)(hCpnSch cthis);
    void (*addTask)(hCpnSch cthis, taskLevel level, task t, uint16 prd, uint16 start);
    void (*delTask)(hCpnSch cthis, taskLevel level, task t);
    void (*delay)(hCpnSch cthis, uint32 *tick);

    // ���������������������������
    void (*time)(hCpnSch cthis, uint16 *point);
    void (*err)(hCpnSch cthis, uint16 code);

    // �ӿں���
    IMPL(iTime);
    IMPL(iErr);
};

#endif /*CPNSCH_H_*/

/**************************** Copyright(C) pxf ****************************/