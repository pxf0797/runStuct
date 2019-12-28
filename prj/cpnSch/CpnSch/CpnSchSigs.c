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

/***********************************************************
* CpnSch�ඨ��
***********************************************************/
/*CpnSch��
***********************************************/
CpnSch clCpnSch;

/***********************************************************
* get set �źŽӿڶ���
***********************************************************/
/*����
***********************************************/




/***********************************************************
* serv trig �źŽӿڶ���
***********************************************************/
/*����������
***********************************************/
void serv_CpnSch_addTask(void *buff, uint16 buffLen){
    if(sizeof(addTaskParam) == buffLen){
        clCpnSch.addTask(clCpnSch.self, ((haddTaskParam)buff)->level, ((haddTaskParam)buff)->t, ((haddTaskParam)buff)->prdTick, ((haddTaskParam)buff)->startTick);
    }
}
/*ɾ���������
***********************************************/
void serv_CpnSch_delTask(void *buff, uint16 buffLen){
    if(sizeof(delTaskParam) == buffLen){
        clCpnSch.delTask(clCpnSch.self, ((hdelTaskParam)buff)->level, ((hdelTaskParam)buff)->t);
    }
}
/*��ʱ����
***********************************************/
void serv_CpnSch_delay(void *buff, uint16 buffLen){
    if(sizeof(uint32) == buffLen){
        clCpnSch.delay(clCpnSch.self, buff);
    }
}
/*ʵʱ����
***********************************************/
void serv_CpnSch_time(void *buff, uint16 buffLen){
    if(sizeof(uint16) == buffLen){
        clCpnSch.time(clCpnSch.self, buff);
    }
}
/*��ʼ������
***********************************************/
void serv_CpnSch_init(void){
    CN(CpnSch, &clCpnSch, SchSm, getTime, setErr);
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


/*ʵʱ����
***********************************************/
// void trig_CpnSch_time(void *buff, uint16 buffLen){
// }
/*ʵʱ����
***********************************************/
// void trig_CpnSch_err(void *buff, uint16 buffLen){
// }


/***********************************************************
* �ӿڶ���
***********************************************************/
/*��ȡʵʱ�ӿ�
***********************************************/
void getTime(uint16 *point){}
/*���ʹ�����ӿ�
***********************************************/
void setErr(uint16 id, uint16 code){}

/**************************** Copyright(C) pxf ****************************/
