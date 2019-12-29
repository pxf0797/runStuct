/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : Cpn1.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/29 14:52:33
* Description  : 
* Others       : 
* History      : 191229 pxf 初次建立
***************************************************************************/

/*头文件包含*/
// #include "./Cpn1.h"
#include "../RteSigs/RteSigs.h"

/***********************************************************
* 发送信号
***********************************************************/
uint8 ucCpn1Send1 = 0xA5;
uint32 ulCpn1Send2 = 0x1234578;
uint8 ucCpn1Send3[3] = {0x11,0x22,0x33};

/***********************************************************
* serv trig 信号接口定义
* 类继承的接口就是触发信号接口，在接口函数中使用触发信号进行触发
***********************************************************/
/*服务
***********************************************/
uint16 uwCpn1Serv1 = 0;
void serv_Cpn1_serv1(void){uwCpn1Serv1++;}

uint32 ulCpn1Serv2 = 0;
void serv_Cpn1_serv2(void *buff){
    ulCpn1Serv2 = *(uint32*)buff;
}

uint8 ucCpn1Serv3[5] = {0};
void serv_Cpn1_serv3(void *buff){
    ucCpn1Serv3[0] = ((uint8*)buff)[0];
    ucCpn1Serv3[1] = ((uint8*)buff)[1];
    ucCpn1Serv3[2] = ((uint8*)buff)[2];
    ucCpn1Serv3[3] = ((uint8*)buff)[3];
    ucCpn1Serv3[4] = ((uint8*)buff)[4];
}
/*错误码接口触发
***********************************************/


/***********************************************************
* 组件初始化任务
***********************************************************/
void taskCpn1Init(void){
    addTaskParam taskCpn1Param;
    taskCpn1Param.level = level0;
    taskCpn1Param.t = taskCpn1;
    taskCpn1Param.prdTick = 0;
    taskCpn1Param.startTick = 0;
    clRteSynSigs.trig(clRteSynSigs.self, sig_trig_Cpn1_addTask, &taskCpn1Param);
}

/***********************************************************
* 组件运行任务
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
