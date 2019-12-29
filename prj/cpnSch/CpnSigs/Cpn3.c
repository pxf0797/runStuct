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
void serv_Cpn3_serv2(void *buff, uint16 buffLen){
    if(sizeof(uwCpn3Serv2) == buffLen){
        uwCpn3Serv2 = *(uint16*)buff;
    }
}
/*������ӿڴ���
***********************************************/

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
