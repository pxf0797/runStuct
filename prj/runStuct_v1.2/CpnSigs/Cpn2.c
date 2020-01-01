/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : Cpn2.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/29 14:52:35
* Description  : 
* Others       : 
* History      : 191229 pxf ���ν���
***************************************************************************/

/*ͷ�ļ�����*/
// #include "./Cpn2.h"
#include "../RteSigs/RteSigs.h"

/***********************************************************
* �����ź�
***********************************************************/



/***********************************************************
* �����ź�
***********************************************************/
uint8 ucCpn2Receive1 = 0;
uint32 ulCpn2Receive2 = 0;
uint8 ucCpn2Receive3[3] = {0};



/***********************************************************
* serv trig �źŽӿڶ���
* ��̳еĽӿھ��Ǵ����źŽӿڣ��ڽӿں�����ʹ�ô����źŽ��д���
***********************************************************/
/*����
***********************************************/
void serv_Cpn2_taskInit(void){
    addTaskParam taskCpn2Param;
    taskCpn2Param.level = level1;
    taskCpn2Param.t = taskCpn2;
    taskCpn2Param.prdTick = 2;//250;
    taskCpn2Param.startTick = 1;//35;
    clRteSynSigs.trig(clRteSynSigs.self, sig_trig_Cpn2_addTask, &taskCpn2Param);
}
/*�ӿڴ���
***********************************************/



/***********************************************************
* �����������
***********************************************************/
uint32 ulCpn2Trig1 = 0;
uint8 ucCpn2Trig2[5] = {0x55};
void taskCpn2(void){
    static uint8 setGetCnt = 0;
    setGetCnt++;

    clRteAsynSigs.get(clRteAsynSigs.self,sig_get_Cpn2_receive1,&ulCpn2Receive2,sizeof(ulCpn2Receive2));
    clRteAsynSigs.get(clRteAsynSigs.self,sig_get_Cpn2_receive2,&ucCpn2Receive1,sizeof(ucCpn2Receive1));
    clRteAsynSigs.get(clRteAsynSigs.self,sig_get_Cpn2_receive3,ucCpn2Receive3,sizeof(ucCpn2Receive3));

    ulCpn2Trig1 += setGetCnt;
    ucCpn2Trig2[0] ^= setGetCnt;
    clRteSynSigs.trig(clRteSynSigs.self, sig_trig_Cpn2_trig1, &ulCpn2Trig1);
    clRteSynSigs.trig(clRteSynSigs.self, sig_trig_Cpn2_trig2, ucCpn2Trig2);
    clRteSynSigs.trig(clRteSynSigs.self, sig_trig_Cpn2_trig3, NULL);
}

/**************************** Copyright(C) pxf ****************************/
