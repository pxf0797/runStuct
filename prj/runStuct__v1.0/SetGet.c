/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : SetGet.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/22 07:34:13
* Description  : 
* Others       : 
* History      : 191222 pxf 初次建立
***************************************************************************/

/*头文件包含*/
#include "./SetGet.h"
#include "./RteAsyn.h"

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 需要在头文件中进行定义，主要有三个内容，信号列表、注册信号和信号映射
// 注册信号主要是需要定义一个统一的注册类型

// 建立发送信号列表
#define SIGNAL_SET_LIST(_)                \
    _(cpn1_send1,1)                       \
    _(cpn1_send2,4)                       \
    _(cpn1_send3,3)                       \

// 建立接收信号列表进行映射，配置信号时需要检查与发送信号的长度，默认一致，不符时需要进行报错
#define SIGNAL_GET_MAP_LIST(_)            \
    _(cpn2_receive1,cpn1_send2)           \
    _(cpn2_receive2,cpn1_send1)           \
    _(cpn2_receive3,cpn1_send3)           \


// 定义需要注册的收发信号
#define ASYN_SET_SIGNAL_REGISTER(signal_set,len)                SIGNAL_SET_REGISTER(RteAsyn,signal_set,len)
#define ASYN_GET_SIGNAL_REGISTER(signal_get,signal_set)         SIGNAL_GET_REGISTER(RteAsyn,signal_get,signal_set)

// 建立收发信号各自映射关系
SIGNAL_SETGET_MAP(RteAsyn,SIGNAL_SET_LIST,SIGNAL_GET_MAP_LIST);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 需要在源文件进行定义和使用，主要有两个内容，缓存定义和信号进行注册

// 定义收发信号缓存
BUFF_SETGET_DEFINE(RteAsyn,SIGNAL_SET_LIST,SIGNAL_GET_MAP_LIST);

// 定义收发类
RteAsyn clRteAsyn;

// 收发信号
uint8 ucSendChar = 0xA5;
uint32 ulSendLong = 0x1234578;
uint8 ucSendChar3[3] = {0x11,0x22,0x33};
uint8 ucReceiveChar = 0;
uint32 ulReceiveLong = 0;
uint8 ucReceiveChar3[3] = {0};

void SetGetInit(void)
{
    // 对信号进行注册
    SIGNALS_GETSET_REGISTER(SIGNAL_SET_LIST,ASYN_SET_SIGNAL_REGISTER);
    SIGNALS_GETSET_REGISTER(SIGNAL_GET_MAP_LIST,ASYN_GET_SIGNAL_REGISTER);

    // 初始化调用类
    CN(RteAsyn,&clRteAsyn,RteAsynSigSetBuff,RteAsynSigSetIndex,RteAsynSigGetIndex);

}

void SetGetRun(void)
{
    static uint8 setGetCnt = 0;
    setGetCnt++;

    ucSendChar += setGetCnt;
    ulSendLong += setGetCnt;
    ucSendChar3[0] += setGetCnt;

    clRteAsyn.set(clRteAsyn.self,cpn1_send1,&ucSendChar,sizeof(ucSendChar));
    clRteAsyn.set(clRteAsyn.self,cpn1_send2,&ulSendLong,sizeof(ulSendLong));
    clRteAsyn.set(clRteAsyn.self,cpn1_send3,ucSendChar3,sizeof(ucSendChar3));

    clRteAsyn.get(clRteAsyn.self,cpn2_receive1,&ulReceiveLong,sizeof(ulReceiveLong));
    clRteAsyn.get(clRteAsyn.self,cpn2_receive2,&ucReceiveChar,sizeof(ucReceiveChar));
    clRteAsyn.get(clRteAsyn.self,cpn2_receive3,ucReceiveChar3,sizeof(ucReceiveChar3));
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

/**************************** Copyright(C) pxf ****************************/
