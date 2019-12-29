/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : AbiSigs.h
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/29 20:17:54
* Description  : 
* Others       : 
* History      : 191229 pxf 初次建立
***************************************************************************/

#ifndef ABISIGS_H_
#define ABISIGS_H_

/*头文件包含*/
#include "../Rte/Rte.h"

/***********************************************************
* get set 数据类型定义
* 一般只定义set数据，get类型引用当前头文件
* 只需要把发送的数据定义出来，收发接口使用的是统一接口，无其他定义
***********************************************************/
/*发送参数
***********************************************/



/***********************************************************
* serv trig 数据类型定义
* 一般只定义serv数据，trig类型引用当前头文件
***********************************************************/
/*添加任务服务参数
***********************************************/


/***********************************************************
* serv trig 信号接口定义
* 类继承的接口就是触发信号接口，在接口函数中使用触发信号进行触发
***********************************************************/
/*添加任务服务
***********************************************/
void serv_Abi_getTime(void *buff);
void serv_Abi_setErr(void *buff);
/*错误码接口触发
***********************************************/
void trig_Abi_init(void);
void trig_Abi_tick(void);
void trig_Abi_run(void);


/***********************************************************
* get set信号列表
***********************************************************/
/*发送信号列表
***********************************************/
/*接收信号列表
* 配置信号时需要检查发送信号的长度对信号进行映射
***********************************************/



/***********************************************************
* trig serv信号列表
***********************************************************/
/*服务信号列表
***********************************************/
#define SIGNAL_SERV_LIST_RTESYN_ABI(_)                     \
    _(sig_serv_Abi_getTime,serv_Abi_getTime)               \
    _(sig_serv_Abi_setErr,serv_Abi_setErr)
/*触发信号列表
* 配置信号时需要检查服务信号的长度对信号进行映射
***********************************************/
#define SIGNAL_TRIG_MAP_LIST_RTESYN_ABI(_)                 \
    _(sig_trig_Abi_init,sig_serv_CpnSch_init)              \
    _(sig_trig_Abi_tick,sig_serv_CpnSch_tick)              \
    _(sig_trig_Abi_run,sig_serv_CpnSch_run)


/***********************************************************
* 组件初始化任务
***********************************************************/
// void taskCpn1Init(void);

/***********************************************************
* 组件运行任务
***********************************************************/
// void taskCpn1(void);


#endif /*ABISIGS_H_*/

/**************************** Copyright(C) pxf ****************************/
