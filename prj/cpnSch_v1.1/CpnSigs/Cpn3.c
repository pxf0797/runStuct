/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : Cpn3.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/29 14:52:38
* Description  : 
* Others       : 
* History      : 191229 pxf ���ν���
***************************************************************************/

/*ͷ�ļ�����*/
// #include "./Cpn3.h"
#include "../RteSigs/RteSigs.h"

/***********************************************************
* �����ź�
***********************************************************/
uint16 uwCpn3Send1 = 0xA5A5;
uint8 ucCpn3Send2[3] = {0x11,0x2A,0xB3};

/***********************************************************
* serv trig �źŽӿڶ���
* ��̳еĽӿھ��Ǵ����źŽӿڣ��ڽӿں�����ʹ�ô����źŽ��д���
***********************************************************/
/*����������
***********************************************/
uint16 uwCpn3Serv1 = 0;
void serv_Cpn3_serv1(void){uwCpn3Serv1++;}

uint16 uwCpn3Serv2 = 0;
void serv_Cpn3_serv2(void *buff){
    uwCpn3Serv2 = *(uint16*)buff;
}
/*������ӿڴ���
***********************************************/

/***********************************************************
* �����ʼ������
***********************************************************/
void taskCpn3Init(void){
    addTaskParam taskCpn3Param;
    taskCpn3Param.level = level1;
    taskCpn3Param.t = taskCpn3;
    taskCpn3Param.prdTick = 350;
    taskCpn3Param.startTick = 55;
    clRteSynSigs.trig(clRteSynSigs.self, sig_trig_Cpn3_addTask, &taskCpn3Param);
}

/***********************************************************
* �����������
***********************************************************/
void taskCpn3(void){
    static uint8 setGetCnt = 0;
    setGetCnt++;

    uwCpn3Send1 += setGetCnt;
    ucCpn3Send2[1] ^= setGetCnt;

    clRteAsynSigs.set(clRteAsynSigs.self,sig_set_Cpn3_send1,&uwCpn3Send1,sizeof(uwCpn3Send1));
    clRteAsynSigs.set(clRteAsynSigs.self,sig_set_Cpn3_send2,ucCpn3Send2,sizeof(ucCpn3Send2));
}

/**************************** Copyright(C) pxf ****************************/
