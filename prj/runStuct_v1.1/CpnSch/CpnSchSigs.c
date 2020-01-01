/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : CpnSchSigs.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/28 21:27:20
* Description  : 
* Others       : 
* History      : 191228 pxf ���ν���
***************************************************************************/

/*ͷ�ļ�����*/
#include "./CpnSchSigs.h"
#include "../RteSigs/RteSigs.h"

/***********************************************************
* CpnSch�ඨ��
***********************************************************/
/*CpnSch��
***********************************************/
CpnSch clCpnSch;


/***********************************************************
* serv trig �źŽӿڶ���
* ��̳еĽӿھ��Ǵ����źŽӿڣ��ڽӿں�����ʹ�ô����źŽ��д���
***********************************************************/
/*����������
***********************************************/
void serv_CpnSch_addTask(void *buff){
    clCpnSch.addTask(clCpnSch.self, ((haddTaskParam)buff)->level, ((haddTaskParam)buff)->t, ((haddTaskParam)buff)->prdTick, ((haddTaskParam)buff)->startTick);
}
/*ɾ���������
***********************************************/
void serv_CpnSch_delTask(void *buff){
    clCpnSch.delTask(clCpnSch.self, ((hdelTaskParam)buff)->level, ((hdelTaskParam)buff)->t);
}
/*��ʱ����
***********************************************/
void serv_CpnSch_delay(void *buff){
    clCpnSch.delay(clCpnSch.self, buff);
}
/*ʵʱ����
***********************************************/
void serv_CpnSch_now(void *buff){
    clCpnSch.now(clCpnSch.self, buff);
}
/*��ʼ������
***********************************************/
void serv_CpnSch_init(void){
    CN(CpnSch, &clCpnSch, &SchSmRunRec, SchSm, trig_CpnSch_inf_getTime, trig_CpnSch_inf_setErr, trig_CpnSch_inf_initCpn);
    if(OPRS(clCpnSch) != NULL){}
}
/*���з���
***********************************************/
void serv_CpnSch_run(void){
    clCpnSch.run(clCpnSch.self);
}
/*��������
***********************************************/
void serv_CpnSch_tick(void){
    clCpnSch.tick(clCpnSch.self);
}


/*��ȡʵʱ�ӿڴ���
***********************************************/
void trig_CpnSch_inf_getTime(uint16 *point){
    clRteSynSigs.trig(clRteSynSigs.self, sig_trig_CpnSch_inf_getTime, point);
}
/*������ӿڴ���
***********************************************/
void trig_CpnSch_inf_setErr(uint16 id, uint16 code){
    uint32 uwErrCode = (((uint32)id << 16) + code);
    clRteSynSigs.trig(clRteSynSigs.self, sig_trig_CpnSch_inf_setErr, &uwErrCode);
}
/*��ʼ������ӿڴ���
***********************************************/
void trig_CpnSch_inf_initCpn(void){
    clRteSynSigs.trig(clRteSynSigs.self, sig_trig_Cpn1_taskInit, NULL);
    clRteSynSigs.trig(clRteSynSigs.self, sig_trig_Cpn2_taskInit, NULL);
    clRteSynSigs.trig(clRteSynSigs.self, sig_trig_Cpn3_taskInit, NULL);
    clRteSynSigs.trig(clRteSynSigs.self, sig_trig_Cpn4_taskInit, NULL);
}

/**************************** Copyright(C) pxf ****************************/
