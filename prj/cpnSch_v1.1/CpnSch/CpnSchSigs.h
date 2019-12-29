/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : CpnSchSigs.h
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/28 21:27:20
* Description  : 
* Others       : 
* History      : 191228 pxf ���ν���
***************************************************************************/

#ifndef CPNSCHSIGS_H_
#define CPNSCHSIGS_H_

/*ͷ�ļ�����*/
#include "../Rte/Rte.h"
#include "./CpnSch.h"

/***********************************************************
* get set �������Ͷ���
* һ��ֻ����set���ݣ�get�������õ�ǰͷ�ļ�
* ֻ��Ҫ�ѷ��͵����ݶ���������շ��ӿ�ʹ�õ���ͳһ�ӿڣ�����������
***********************************************************/
/*���Ͳ���
***********************************************/



/***********************************************************
* serv trig �������Ͷ���
* һ��ֻ����serv���ݣ�trig�������õ�ǰͷ�ļ�
***********************************************************/
/*��������������
***********************************************/
typedef struct addTaskParam{
    uint16 level;
    task t;
    uint16 prdTick;
    uint16 startTick;
}addTaskParam, *haddTaskParam;
/*ɾ������������
***********************************************/
typedef struct delTaskParam{
    uint16 level;
    task t;
}delTaskParam, *hdelTaskParam;
/*��ʱ�������
***********************************************/
typedef uint32 tick;
/*ʵʱ�������
***********************************************/
typedef uint16 point;


/***********************************************************
* serv trig �źŽӿڶ���
* ��̳еĽӿھ��Ǵ����źŽӿڣ��ڽӿں�����ʹ�ô����źŽ��д���
***********************************************************/
/*�����������
***********************************************/
void serv_CpnSch_addTask(void *buff);
/*ɾ���������
***********************************************/
void serv_CpnSch_delTask(void *buff);
/*��ʱ����
***********************************************/
void serv_CpnSch_delay(void *buff);
/*ʵʱ����
***********************************************/
void serv_CpnSch_time(void *buff);
/*��ʼ������
***********************************************/
void serv_CpnSch_init(void);
/*���з���
***********************************************/
void serv_CpnSch_run(void);
/*��������
***********************************************/
void serv_CpnSch_tick(void);


/*��ȡʵʱ�ӿڴ���
***********************************************/
void trig_CpnSch_inf_getTime(uint16 *point);
/*������ӿڴ���
***********************************************/
void trig_CpnSch_inf_setErr(uint16 id, uint16 code);


/***********************************************************
* get set�ź��б�
***********************************************************/
/*�����ź��б�
***********************************************/
/*�����ź��б�
* �����ź�ʱ��Ҫ��鷢���źŵĳ��ȶ��źŽ���ӳ��
***********************************************/



/***********************************************************
* trig serv�ź��б�
***********************************************************/
/*�����ź��б�
***********************************************/
#define SIGNAL_SERV_LIST_RTESYN_CPNSCH(_)                          \
    _(sig_serv_CpnSch_addTask,serv_CpnSch_addTask)                 \
    _(sig_serv_CpnSch_delTask,serv_CpnSch_delTask)                 \
    _(sig_serv_CpnSch_delay,serv_CpnSch_delay)                     \
    _(sig_serv_CpnSch_time,serv_CpnSch_time)                       \
    _(sig_serv_CpnSch_init,serv_CpnSch_init)                       \
    _(sig_serv_CpnSch_run,serv_CpnSch_run)                         \
    _(sig_serv_CpnSch_tick,serv_CpnSch_tick)

/*�����ź��б�
* �����ź�ʱ��Ҫ�������źŵĳ��ȶ��źŽ���ӳ��
***********************************************/
#define SIGNAL_TRIG_MAP_LIST_RTESYN_CPNSCH(_)                      \
    _(sig_trig_CpnSch_inf_getTime,sig_serv_Abi_getTime)            \
    _(sig_trig_CpnSch_inf_setErr,sig_serv_Abi_setErr)


/***********************************************************
* �����ʼ������
***********************************************************/
// void taskCpnSchInit(void);

/***********************************************************
* �����������
***********************************************************/
// void taskCpnSch(void);

#endif /*CPNSCHSIGS_H_*/

/**************************** Copyright(C) pxf ****************************/