/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : CpnSch2Sigs.h
* Author       : pxf
* Version      : v1.0
* Created on   : 2020/01/01 13:18:37
* Description  : CpnSch2组件信号声明头文件
* Others       : 
* History      : 200101 pxf 初次建立
***************************************************************************/

#ifndef CPNSCH2SIGS_H_
#define CPNSCH2SIGS_H_

/*头文件包含*/
#include "../Rte/Ret.h"

/***********************************************************
* get set 数据类型定义
* 一般只定义set数据，get类型引用当前头文件
* 只需要把发送的数据定义出来，收发接口使用的是统一接口，无其他定义
* 信号数据类型一般来说都得强制定义一遍，否则很难知道信号对应数据是什么
***********************************************************/
/*发送数据类型
***********************************************/



/***********************************************************
* serv trig 数据类型定义
* 一般只定义serv数据，trig类型引用当前头文件
* 只需要把发送的数据定义出来，收发接口使用的是统一接口，无其他定义
* 信号数据类型一般来说都得强制定义一遍，否则很难知道信号对应数据是什么
***********************************************************/
/*服务数据类型
***********************************************/



/***********************************************************
* serv trig 信号接口定义
* 类继承的接口就是触发信号接口，在接口函数中使用触发信号进行触发
***********************************************************/
/*组件初始化服务
***********************************************/
void serv_CpnSch2_init(void);
/*服务
***********************************************/
void serv_CpnSch2_run(void);
/*服务
***********************************************/
void serv_CpnSch2_tick(void);
/*服务
***********************************************/
void serv_CpnSch2_now(void);
/*服务
***********************************************/
void serv_CpnSch2_delay(void);
/*服务
***********************************************/
void serv_CpnSch2_addTask(void);
/*服务
***********************************************/
void serv_CpnSch2_delTask(void);

/*接口触发
***********************************************/
//void trig_CpnSch2_inf_infFunc(void);



/***********************************************************
* get set信号列表
***********************************************************/
/*发送信号列表
***********************************************/
#define SIGNAL_SET_LIST_RTEASYN_CPNSCH2(_)                  \

/*接收信号列表
* 配置信号时需要检查发送信号的长度对信号进行映射
***********************************************/
#define SIGNAL_GET_MAP_LIST_RTEASYN_CPNSCH2(_)              \



/***********************************************************
* trig serv信号列表
***********************************************************/
/*服务信号列表
***********************************************/
#define SIGNAL_SERV_LIST_RTESYN_CPNSCH2(_)                  \
    _(sig_serv_CpnSch2_init,serv_CpnSch2_init)              \
    _(sig_serv_CpnSch2_run,serv_CpnSch2_run)                \
    _(sig_serv_CpnSch2_tick,serv_CpnSch2_tick)              \
    _(sig_serv_CpnSch2_now,serv_CpnSch2_now)                \
    _(sig_serv_CpnSch2_delay,serv_CpnSch2_delay)            \
    _(sig_serv_CpnSch2_addTask,serv_CpnSch2_addTask)        \
    _(sig_serv_CpnSch2_delTask,serv_CpnSch2_delTask)        \

/*触发信号列表
* 配置信号时需要检查服务信号的长度对信号进行映射
***********************************************/
#define SIGNAL_TRIG_MAP_LIST_RTESYNCPNSCH2(_)               \



/***********************************************************
* 组件运行任务
***********************************************************/
/*运行任务声明
***********************************************/
void taskCpnSch2(void);

#endif /*CPNSCH2SIGS_H_*/

/**************************** Copyright(C) pxf ****************************/
