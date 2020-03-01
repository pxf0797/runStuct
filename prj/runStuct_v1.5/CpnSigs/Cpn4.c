/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : Cpn4.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/29 14:52:41
* Description  : 
* Others       : 
* History      : 191229 pxf 初次建立
***************************************************************************/

/*头文件包含*/
// #include "./Cpn4.h"
#include "../RteSigs/RteSigs.h"

/***********************************************************
* 发送信号
***********************************************************/



/***********************************************************
* 接收信号
***********************************************************/
uint8 ucCpn4Receive1[3] = {0x11,0x2A,0xB3};
uint16 uwCpn4Receive2 = 0xA5A5;



/***********************************************************
* serv trig 信号接口定义
* 类继承的接口就是触发信号接口，在接口函数中使用触发信号进行触发
***********************************************************/
/*服务
***********************************************/
void serv_Cpn4_taskInit(void){
    addTaskParam taskCpn4Param;
    taskCpn4Param.level = level1;
    taskCpn4Param.t = taskCpn4;
    taskCpn4Param.prdTick = 4;//350;
    taskCpn4Param.startTick = 5;//55;
    clRteSynSigs.trig(clRteSynSigs.self, sig_trig_Cpn4_addTask, &taskCpn4Param);
}
/*接口触发
***********************************************/



/***********************************************************
* 组件运行任务
***********************************************************/
uint16 uwCpn4Trig1 = 0xAA55;
void taskCpn4(void){
    static uint8 setGetCnt = 0;
    setGetCnt++;

    clRteAsynSigs.get(clRteAsynSigs.self,sig_get_Cpn4_receive1,ucCpn4Receive1,sizeof(ucCpn4Receive1));
    clRteAsynSigs.get(clRteAsynSigs.self,sig_get_Cpn4_receive2,&uwCpn4Receive2,sizeof(uwCpn4Receive2));

    uwCpn4Trig1 += setGetCnt;
    clRteSynSigs.trig(clRteSynSigs.self, sig_trig_Cpn4_trig1, &uwCpn4Trig1);
    clRteSynSigs.trig(clRteSynSigs.self, sig_trig_Cpn4_trig2, NULL);
}

/**************************** Copyright(C) pxf ****************************/
