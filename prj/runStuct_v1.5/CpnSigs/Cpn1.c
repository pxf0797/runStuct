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
* 接收信号
***********************************************************/



/***********************************************************
* serv trig 信号接口定义
* 类继承的接口就是触发信号接口，在接口函数中使用触发信号进行触发
***********************************************************/
/*服务
***********************************************/
void serv_Cpn1_taskInit(void){
    addTaskParam taskCpn1Param;
    taskCpn1Param.level = level0;
    taskCpn1Param.t = taskCpn1;
    taskCpn1Param.prdTick = 0;
    taskCpn1Param.startTick = 0;
    clRteSynSigs.trig(clRteSynSigs.self, sig_trig_Cpn1_addTask, &taskCpn1Param);
}

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

/*接口触发
***********************************************/


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

    static tick dealyTime = 100*MS_T;
    static uint16 uwDelTaskStep = 0;
    delTaskParam delTask;
    addTaskParam addTask;

    clRteSynSigs.trig(clRteSynSigs.self,sig_trig_Cpn1_delay,&dealyTime);
    if(IS_TIMEOUT(dealyTime) && (uwDelTaskStep == 0)){
        delTask.level = level1;
        delTask.t = taskCpn2;
        clRteSynSigs.trig(clRteSynSigs.self,sig_trig_Cpn1_delTask,&delTask);
        uwDelTaskStep = 1;

        dealyTime = 10*MS_T;
    }else if(IS_TIMEOUT(dealyTime) && (uwDelTaskStep == 1)){
        delTask.level = level1;
        delTask.t = taskCpn4;
        clRteSynSigs.trig(clRteSynSigs.self,sig_trig_Cpn1_delTask,&delTask);
        uwDelTaskStep = 2;

        dealyTime = 3*MS_T;
    }else if(IS_TIMEOUT(dealyTime) && (uwDelTaskStep == 2)){
        delTask.level = level1;
        delTask.t = taskCpn3;
        clRteSynSigs.trig(clRteSynSigs.self,sig_trig_Cpn1_delTask,&delTask);
        uwDelTaskStep = 3;

        dealyTime = 8*MS_T;
    }else if(IS_TIMEOUT(dealyTime) && (uwDelTaskStep == 3)){
        addTask.level = level1;
        addTask.t = taskCpn4;
        addTask.prdTick = 4;
        addTask.startTick = 2;
        clRteSynSigs.trig(clRteSynSigs.self,sig_trig_Cpn1_addTask,&addTask);
        uwDelTaskStep = 4;

        dealyTime = 5*MS_T;
    }else if(IS_TIMEOUT(dealyTime) && (uwDelTaskStep == 4)){
        addTask.level = level1;
        addTask.t = taskCpn3;
        addTask.prdTick = 3;
        addTask.startTick = 2;
        clRteSynSigs.trig(clRteSynSigs.self,sig_trig_Cpn1_addTask,&addTask);
        uwDelTaskStep = 5;

        dealyTime = 3*MS_T;
    }else if(IS_TIMEOUT(dealyTime) && (uwDelTaskStep == 5)){
        addTask.level = level1;
        addTask.t = taskCpn2;
        addTask.prdTick = 2;
        addTask.startTick = 1;
        clRteSynSigs.trig(clRteSynSigs.self,sig_trig_Cpn1_addTask,&addTask);
        uwDelTaskStep = 6;

        dealyTime = 20*MS_T;
    }else{}
    
}

/**************************** Copyright(C) pxf ****************************/
