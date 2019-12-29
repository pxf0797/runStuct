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
* 接收信号
***********************************************************/
uint8 ucCpn4Receive1[3] = {0x11,0x2A,0xB3};
uint16 uwCpn4Receive2 = 0xA5A5;

/***********************************************************
* serv trig 信号接口定义
* 类继承的接口就是触发信号接口，在接口函数中使用触发信号进行触发
***********************************************************/
/*添加任务服务
***********************************************/
/*错误码接口触发
***********************************************/
uint16 uwCpn4Trig1 = 0xAA55;
void trig_Cpn4_trig1(void *buff, uint16 buffLen){
    clRteSynSigs.trig(clRteSynSigs.self, sig_trig_Cpn4_trig1, buff, buffLen);
}

void trig_Cpn4_trig2(void){
    clRteSynSigs.trig(clRteSynSigs.self, sig_trig_Cpn4_trig2, NULL, 0);
}

/***********************************************************
* 组件运行任务
***********************************************************/
void taskCpn4(void){
    static uint8 setGetCnt = 0;
    setGetCnt++;

    clRteAsynSigs.get(clRteAsynSigs.self,sig_get_Cpn4_receive1,ucCpn4Receive1,sizeof(ucCpn4Receive1));
    clRteAsynSigs.get(clRteAsynSigs.self,sig_get_Cpn4_receive2,&uwCpn4Receive2,sizeof(uwCpn4Receive2));

    uwCpn4Trig1 += setGetCnt;
    trig_Cpn4_trig1(&uwCpn4Trig1, sizeof(uwCpn4Trig1));
    trig_Cpn4_trig2();
}

/**************************** Copyright(C) pxf ****************************/
