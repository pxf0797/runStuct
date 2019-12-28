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

/***********************************************************
* CpnSch类定义
***********************************************************/
/*CpnSch类
***********************************************/
CpnSch clCpnSch;

/***********************************************************
* get set 信号接口定义
***********************************************************/
/*发送
***********************************************/




/***********************************************************
* serv trig 信号接口定义
***********************************************************/
/*添加任务服务
***********************************************/
void serv_CpnSch_addTask(void *buff, uint16 buffLen){
    if(sizeof(addTaskParam) == buffLen){
        clCpnSch.addTask(clCpnSch.self, ((haddTaskParam)buff)->level, ((haddTaskParam)buff)->t, ((haddTaskParam)buff)->prdTick, ((haddTaskParam)buff)->startTick);
    }
}
/*删除任务服务
***********************************************/
void serv_CpnSch_delTask(void *buff, uint16 buffLen){
    if(sizeof(delTaskParam) == buffLen){
        clCpnSch.delTask(clCpnSch.self, ((hdelTaskParam)buff)->level, ((hdelTaskParam)buff)->t);
    }
}
/*延时服务
***********************************************/
void serv_CpnSch_delay(void *buff, uint16 buffLen){
    if(sizeof(uint32) == buffLen){
        clCpnSch.delay(clCpnSch.self, buff);
    }
}
/*实时服务
***********************************************/
void serv_CpnSch_time(void *buff, uint16 buffLen){
    if(sizeof(uint16) == buffLen){
        clCpnSch.time(clCpnSch.self, buff);
    }
}
/*初始化服务
***********************************************/
void serv_CpnSch_init(void){
    CN(CpnSch, &clCpnSch, SchSm, getTime, setErr);
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


/*实时触发
***********************************************/
// void trig_CpnSch_time(void *buff, uint16 buffLen){
// }
/*实时触发
***********************************************/
// void trig_CpnSch_err(void *buff, uint16 buffLen){
// }


/***********************************************************
* 接口定义
***********************************************************/
/*读取实时接口
***********************************************/
void getTime(uint16 *point){}
/*发送错误码接口
***********************************************/
void setErr(uint16 id, uint16 code){}

/**************************** Copyright(C) pxf ****************************/
