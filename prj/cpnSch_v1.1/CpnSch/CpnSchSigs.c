/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : CpnSchSigs.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/28 21:27:20
* Description  : 
* Others       : 
* History      : 191228 pxf 初次建立
***************************************************************************/

/*头文件包含*/
#include "./CpnSchSigs.h"
#include "../RteSigs/RteSigs.h"

/***********************************************************
* CpnSch类定义
***********************************************************/
/*CpnSch类
***********************************************/
CpnSch clCpnSch;


/***********************************************************
* serv trig 信号接口定义
* 类继承的接口就是触发信号接口，在接口函数中使用触发信号进行触发
***********************************************************/
/*添加任务服务
***********************************************/
void serv_CpnSch_addTask(void *buff){
    clCpnSch.addTask(clCpnSch.self, ((haddTaskParam)buff)->level, ((haddTaskParam)buff)->t, ((haddTaskParam)buff)->prdTick, ((haddTaskParam)buff)->startTick);
}
/*删除任务服务
***********************************************/
void serv_CpnSch_delTask(void *buff){
    clCpnSch.delTask(clCpnSch.self, ((hdelTaskParam)buff)->level, ((hdelTaskParam)buff)->t);
}
/*延时服务
***********************************************/
void serv_CpnSch_delay(void *buff){
    clCpnSch.delay(clCpnSch.self, buff);
}
/*实时服务
***********************************************/
void serv_CpnSch_time(void *buff){
    clCpnSch.time(clCpnSch.self, buff);
}
/*初始化服务
***********************************************/
void serv_CpnSch_init(void){
    CN(CpnSch, &clCpnSch, SchSm, trig_CpnSch_inf_getTime, trig_CpnSch_inf_setErr);
    if(OPRS(clCpnSch) != NULL){}
}
/*运行服务
***********************************************/
void serv_CpnSch_run(void){
    clCpnSch.run(clCpnSch.self);
}
/*步长服务
***********************************************/
void serv_CpnSch_tick(void){
    clCpnSch.tick(clCpnSch.self);
}


/*读取实时接口触发
***********************************************/
void trig_CpnSch_inf_getTime(uint16 *point){
    clRteSynSigs.trig(clRteSynSigs.self, sig_trig_CpnSch_inf_getTime, point);
}
/*错误码接口触发
***********************************************/
void trig_CpnSch_inf_setErr(uint16 id, uint16 code){
    uint32 uwErrCode = (((uint32)id << 16) + code);
    clRteSynSigs.trig(clRteSynSigs.self, sig_trig_CpnSch_inf_setErr, &uwErrCode);
}

/**************************** Copyright(C) pxf ****************************/
