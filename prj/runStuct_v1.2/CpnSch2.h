/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : CpnSch2.h
* Author       : pxf
* Version      : v1.0
* Created on   : 2020/01/01 13:18:37
* Description  : CpnSch2类及接口声明头文件
* Others       : 
* History      : 200101 pxf 初次建立
***************************************************************************/

#ifndef CPNSCH2_H_
#define CPNSCH2_H_

/*头文件包含*/
#include "./oopc_v1.02/oopc.h"

/***********************************************************
* 接口定义
***********************************************************/
/*接口声明
***********************************************/
//INF(get){
//  uint16(*get)(void);
//};
//TODO

/***********************************************************
* CpnSch2类定义
***********************************************************/
/*CpnSch2类声明
***********************************************/
CL(CpnSch2){
    hCpnSch2 self;
    hCpnSch2 (*init)(hCpnSch2 cthis);

    // CpnSch2类参数
    //TODO

    // CpnSch2类功能函数
    void (*run)(hCpnSch2 cthis);
    void (*tick)(hCpnSch2 cthis);
    void (*now)(hCpnSch2 cthis);
    void (*delay)(hCpnSch2 cthis);
    void (*addTask)(hCpnSch2 cthis);
    void (*delTask)(hCpnSch2 cthis);
    //TODO
};

#endif /*CPNSCH2_H_*/

/**************************** Copyright(C) pxf ****************************/
