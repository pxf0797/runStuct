/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : Cpn1.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/29 14:52:33
* Description  : 
* Others       : 
* History      : 191229 pxf ���ν���
***************************************************************************/

/*ͷ�ļ�����*/
// #include "./Cpn1.h"
#include "../RteSigs/RteSigs.h"

/***********************************************************
* �����ź�
***********************************************************/
uint8 ucCpn1Send1 = 0xA5;
uint32 ulCpn1Send2 = 0x1234578;
uint8 ucCpn1Send3[3] = {0x11,0x22,0x33};

/***********************************************************
* serv trig �źŽӿڶ���
* ��̳еĽӿھ��Ǵ����źŽӿڣ��ڽӿں�����ʹ�ô����źŽ��д���
***********************************************************/
/*����
***********************************************/
uint16 uwCpn1Serv1 = 0;
void serv_Cpn1_serv1(void){uwCpn1Serv1++;}

uint32 ulCpn1Serv2 = 0;
void serv_Cpn1_serv2(void *buff, uint16 buffLen){
    if(sizeof(ulCpn1Serv2) == buffLen){
        ulCpn1Serv2 = *(uint32*)buff;
    }
}

uint8 ucCpn1Serv3[5] = {0};
void serv_Cpn1_serv3(void *buff, uint16 buffLen){
    if(sizeof(ucCpn1Serv3) == buffLen){
        ucCpn1Serv3[0] = ((uint8*)buff)[0];
        ucCpn1Serv3[1] = ((uint8*)buff)[1];
        ucCpn1Serv3[2] = ((uint8*)buff)[2];
        ucCpn1Serv3[3] = ((uint8*)buff)[3];
        ucCpn1Serv3[4] = ((uint8*)buff)[4];
    }
}
/*������ӿڴ���
***********************************************/


/***********************************************************
* �����������
***********************************************************/
void taskCpn1(void){
    static uint8 setGetCnt = 0;
    setGetCnt++;

    ucCpn1Send1 += setGetCnt;
    ulCpn1Send2 += setGetCnt;
    ucCpn1Send3[0] += setGetCnt;

    clRteAsynSigs.set(clRteAsynSigs.self,sig_set_Cpn1_send1,&ucCpn1Send1,sizeof(ucCpn1Send1));
    clRteAsynSigs.set(clRteAsynSigs.self,sig_set_Cpn1_send2,&ulCpn1Send2,sizeof(ulCpn1Send2));
    clRteAsynSigs.set(clRteAsynSigs.self,sig_set_Cpn1_send3,ucCpn1Send3,sizeof(ucCpn1Send3));
}

/**************************** Copyright(C) pxf ****************************/
