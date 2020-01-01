/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : CpnSch2.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2020/01/01 13:18:37
* Description  : CpnSch2类各功能函数定义源文件
* Others       : 
* History      : 200101 pxf 初次建立
***************************************************************************/

/*头文件包含*/
#include "./CpnSch2.h"

/***********************************************************
* CpnSch2类定义
***********************************************************/
/*名称 : CpnSch2_run(hCpnSch2 cthis)
* 输入 : cthis - CpnSch2类指针
* 输出 : 无
* 其他 : CpnSch2类功能函数
***********************************************/
void CpnSch2_run(hCpnSch2 cthis){
    //TODO
}

/*名称 : CpnSch2_tick(hCpnSch2 cthis)
* 输入 : cthis - CpnSch2类指针
* 输出 : 无
* 其他 : CpnSch2类功能函数
***********************************************/
void CpnSch2_tick(hCpnSch2 cthis){
    //TODO
}

/*名称 : CpnSch2_now(hCpnSch2 cthis)
* 输入 : cthis - CpnSch2类指针
* 输出 : 无
* 其他 : CpnSch2类功能函数
***********************************************/
void CpnSch2_now(hCpnSch2 cthis){
    //TODO
}

/*名称 : CpnSch2_delay(hCpnSch2 cthis)
* 输入 : cthis - CpnSch2类指针
* 输出 : 无
* 其他 : CpnSch2类功能函数
***********************************************/
void CpnSch2_delay(hCpnSch2 cthis){
    //TODO
}

/*名称 : CpnSch2_addTask(hCpnSch2 cthis)
* 输入 : cthis - CpnSch2类指针
* 输出 : 无
* 其他 : CpnSch2类功能函数
***********************************************/
void CpnSch2_addTask(hCpnSch2 cthis){
    //TODO
}

/*名称 : CpnSch2_delTask(hCpnSch2 cthis)
* 输入 : cthis - CpnSch2类指针
* 输出 : 无
* 其他 : CpnSch2类功能函数
***********************************************/
void CpnSch2_delTask(hCpnSch2 cthis){
    //TODO
}

/*名称 : hCpnSch2 CpnSch2_init(hCpnSch2 cthis)
* 输入 : cthis - CpnSch2类指针
* 输出 : hCpnSch2 - cthis/OOPC_NULL
* 其他 : CpnSch2类初始化函数
***********************************************/
hCpnSch2 CpnSch2_init(hCpnSch2 cthis){
    // 功能函数配置
    //cthis->run = CpnSch2_run;
    //TODO

    // 参数配置
    //TODO

    return cthis;
}

/*名称 : hCpnSch2 CpnSch2_ctor(hCpnSch2 cthis)
* 输入 : cthis - CpnSch2类指针
* 输出 : hCpnSch2 - cthis/OOPC_NULL
* 其他 : CpnSch2类构造函数
***********************************************/
CC(CpnSch2){
    cthis->init = CpnSch2_init;
    cthis->run = CpnSch2_run;
    cthis->tick = CpnSch2_tick;
    cthis->now = CpnSch2_now;
    cthis->delay = CpnSch2_delay;
    cthis->addTask = CpnSch2_addTask;
    cthis->delTask = CpnSch2_delTask;
    //TODO

    // 参数配置
    //TODO
    return cthis;
}

/*名称 : hCpnSch2 CpnSch2_dtor(hCpnSch2 cthis)
* 输入 : cthis - CpnSch2类指针
* 输出 : OOPC_RETURN_DATATYPE - OOPC_TRUE/OOPC_FALSE
* 其他 : CpnSch2类析构函数
***********************************************/
CD(CpnSch2){
    return OOPC_TRUE;
}

/**************************** Copyright(C) pxf ****************************/
