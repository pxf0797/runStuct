/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : CpnSchSigs.h
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/28 21:27:20
* Description  : 
* Others       : 
* History      : 191228 pxf 初次建立
***************************************************************************/

#ifndef CPNSCHSIGS_H_
#define CPNSCHSIGS_H_

/*头文件包含*/
#include "../Rte/Rte.h"
#include "./CpnSch.h"

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
typedef struct addTaskParam{
    uint16 level;
    task t;
    uint16 prdTick;
    uint16 startTick;
}addTaskParam, *haddTaskParam;
/*删除任务服务参数
***********************************************/
typedef struct delTaskParam{
    uint16 level;
    task t;
}delTaskParam, *hdelTaskParam;
/*延时服务参数
***********************************************/
typedef uint32 tick;
/*实时服务参数
***********************************************/
typedef uint16 point;


/***********************************************************
* serv trig 信号接口定义
* 类继承的接口就是触发信号接口，在接口函数中使用触发信号进行触发
***********************************************************/
/*添加任务服务
***********************************************/
void serv_CpnSch_addTask(void *buff, uint16 buffLen);
/*删除任务服务
***********************************************/
void serv_CpnSch_delTask(void *buff, uint16 buffLen);
/*延时服务
***********************************************/
void serv_CpnSch_delay(void *buff, uint16 buffLen);
/*实时服务
***********************************************/
void serv_CpnSch_time(void *buff, uint16 buffLen);

/*初始化触发
***********************************************/
void trig_CpnSch_init(void);
/*运行触发
***********************************************/
void trig_CpnSch_run(void);
/*步长触发
***********************************************/
void trig_CpnSch_tick(void);
/*实时触发
***********************************************/
void trig_CpnSch_time(void *buff, uint16 buffLen);


/*读取实时接口触发
***********************************************/
void getTime(uint16 *point);
/*错误码接口触发
***********************************************/
void setErr(uint16 id, uint16 code);


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
#define SIGNAL_SERV_LIST_RTESYN_CPNSCH(_)                                \
    // _(sig_serv_Cpn1_serv1,serv_Cpn1_serv1,0)                          \
    // _(sig_serv_Cpn1_serv2,serv_Cpn1_serv2,sizeof(uint32))             \
    // _(sig_serv_Cpn1_serv3,serv_Cpn1_serv3,sizeof(uint8)*5)

/*触发信号列表
* 配置信号时需要检查服务信号的长度对信号进行映射
***********************************************/
#define SIGNAL_TRIG_MAP_LIST_RTESYN_CPNSCH(_)                      \
    // _(sig_trig_Cpn4_trig1,sig_serv_Cpn3_serv2,sizeof(uint16))         \
    // _(sig_trig_Cpn4_trig2,sig_serv_Cpn3_serv1,0)

/***********************************************************
* 组件运行任务
***********************************************************/
void taskCpnSch(void);

#endif /*CPNSCHSIGS_H_*/

/**************************** Copyright(C) pxf ****************************/
