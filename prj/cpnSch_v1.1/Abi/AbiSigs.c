/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : AbiSigs.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/29 20:17:54
* Description  : 
* Others       : 
* History      : 191229 pxf 初次建立
***************************************************************************/

/*头文件包含*/
#include "./AbiSigs.h"
#include "../RteSigs/RteSigs.h"

/***********************************************************
* serv trig 信号接口定义
* 类继承的接口就是触发信号接口，在接口函数中使用触发信号进行触发
***********************************************************/
/*实时服务
***********************************************/
void serv_Abi_getTime(void *buff){
    *(uint16*)buff = 0;
}
/*错误处理服务
***********************************************/
void serv_Abi_setErr(void *buff){
    uint32 ulErrCode = *(uint32*)buff;
}

/*初始化触发
***********************************************/
void trig_Abi_init(void){
    clRteSynSigs.trig(clRteSynSigs.self, sig_trig_Abi_init, NULL);
}
/*步长触发
***********************************************/
void trig_Abi_tick(void){
    clRteSynSigs.trig(clRteSynSigs.self, sig_trig_Abi_tick, NULL);
}
/*循环运行触发
***********************************************/
void trig_Abi_run(void){
    clRteSynSigs.trig(clRteSynSigs.self, sig_trig_Abi_run, NULL);
}

/**************************** Copyright(C) pxf ****************************/
