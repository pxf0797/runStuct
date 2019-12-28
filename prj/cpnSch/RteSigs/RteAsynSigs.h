/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : RteAsynSigs.h
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/28 23:08:12
* Description  : 
* Others       : 
* History      : 191228 pxf 初次建立
***************************************************************************/

#ifndef RTEASYNSIGS_H_
#define RTEASYNSIGS_H_

/*头文件包含*/
#include "../standType/standType.h"
#include "../Rte/RteAsyn.h"
#include "../Rte/RteSyn.h"
#include "../Rte/SetGet.h"

// 建立发送信号列表
#define SIGNAL_SET_LIST_RTEASYN(_)        \
    _(cpn1_send1,1)                       \
    _(cpn1_send2,4)                       \
    _(cpn1_send3,3)                       \

// 建立接收信号列表进行映射，配置信号时需要检查与发送信号的长度，默认一致，不符时需要进行报错
#define SIGNAL_GET_MAP_LIST_RTEASYN(_)    \
    _(cpn2_receive1,cpn1_send2)           \
    _(cpn2_receive2,cpn1_send1)           \
    _(cpn2_receive3,cpn1_send3)           \


// 定义需要注册的收发信号
#define ASYN_SET_SIGNAL_REGISTER(signal_set,len)                SIGNAL_SET_REGISTER(RteAsynSigs,signal_set,len)
#define ASYN_GET_SIGNAL_REGISTER(signal_get,signal_set)         SIGNAL_GET_REGISTER(RteAsynSigs,signal_get,signal_set)

// 建立收发信号各自映射关系
SIGNAL_SETGET_MAP(RteAsynSigs,SIGNAL_SET_LIST_RTEASYN,SIGNAL_GET_MAP_LIST_RTEASYN);

// 异步信号初始化函数
void RteAsynSetGetInit(void);

// 定义收发类
extern RteAsyn clRteAsynSigs;

#endif /*RTEASYNSIGS_H_*/

/**************************** Copyright(C) pxf ****************************/
