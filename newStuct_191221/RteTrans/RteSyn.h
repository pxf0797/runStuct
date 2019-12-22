/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : RteSyn.h
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/22 10:05:34
* Description  : RteSyn�༰�ӿ�����ͷ�ļ�
* Others       : 
* History      : 191222 pxf ���ν���
***************************************************************************/

#ifndef RTESYN_H_
#define RTESYN_H_

/*ͷ�ļ�����*/
#include "./standType/standType.h"
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
* RteSyn�ඨ��
***********************************************************/
/*RteSyn������
***********************************************/
CL(RteSyn){
    hRteSyn self;
    hRteSyn (*init)(hRteSyn cthis, uint16 *serv_paramLen, void **serv_ServBuff, uint16 *trig_index);

    // RteSyn�����
    uint16 *serv_paramLen;
    void **serv_ServBuff;
    uint16 *trig_index;

    // RteSyn�๦�ܺ���
    void (*serv)(hRteSyn cthis, uint16 signal, uint8 *buff, uint16 paramLen);
    void (*trig)(hRteSyn cthis, uint16 signal, uint8 *buff, uint16 paramLen);
    //TODO
};

#endif /*RTESYN_H_*/

/**************************** Copyright(C) pxf ****************************/
