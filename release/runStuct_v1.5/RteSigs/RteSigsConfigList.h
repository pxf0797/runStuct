/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : RteSigsConfigList.h
* Author       : pxf
* Version      : v1.0
* Created on   : 2020/02/26 10:34:30
* Description  : 
* Others       : 
* History      : 200226 pxf 初次建立
***************************************************************************/

#ifndef RTESIGSCONFIGLIST_H_
#define RTESIGSCONFIGLIST_H_

/*头文件包含*/
#include "../Rte/Rte.h"

/*组件信号*/
#include "../Abi/AbiSigs.h"
#include "../CpnSch/CpnSchSigs.h"
// #include "../CpnSigs/Cpn1.h"
// #include "../CpnSigs/Cpn2.h"
// #include "../CpnSigs/Cpn3.h"
// #include "../CpnSigs/Cpn4.h"

/***********************************************************
* get set信号列表
***********************************************************/
/*发送信号列表
***********************************************/
#define SIGNAL_SET_LIST_RTEASYN(_)                         \
        // SIGNAL_SET_LIST_RTEASYN_CPN1(_)                    \
        // SIGNAL_SET_LIST_RTEASYN_CPN3(_)                    \

/*接收信号列表
* 配置信号时需要检查发送信号的长度对信号进行映射
***********************************************/
#define SIGNAL_GET_MAP_LIST_RTEASYN(_)                     \
        // SIGNAL_GET_MAP_LIST_RTEASYN_CPN2(_)                \
        // SIGNAL_GET_MAP_LIST_RTEASYN_CPN4(_)                \


/***********************************************************
* trig serv信号列表
***********************************************************/
/*服务信号列表
***********************************************/
#define SIGNAL_SERV_LIST_RTESYN(_)                         \
        SIGNAL_SERV_LIST_RTESYN_ABI(_)                     \
        SIGNAL_SERV_LIST_RTESYN_CPNSCH(_)                  \
        // SIGNAL_SERV_LIST_RTESYN_CPN1(_)                    \
        // SIGNAL_SERV_LIST_RTESYN_CPN2(_)                    \
        // SIGNAL_SERV_LIST_RTESYN_CPN3(_)                    \
        // SIGNAL_SERV_LIST_RTESYN_CPN4(_)                    \

/*触发信号列表
* 配置信号时需要检查服务信号的长度对信号进行映射
***********************************************/
#define SIGNAL_TRIG_MAP_LIST_RTESYN(_)                     \
        SIGNAL_TRIG_MAP_LIST_RTESYN_ABI(_)                 \
        SIGNAL_TRIG_MAP_LIST_RTESYN_CPNSCH(_)              \
        // SIGNAL_TRIG_MAP_LIST_RTESYN_CPN1(_)                \
        // SIGNAL_TRIG_MAP_LIST_RTESYN_CPN2(_)                \
        // SIGNAL_TRIG_MAP_LIST_RTESYN_CPN3(_)                \
        // SIGNAL_TRIG_MAP_LIST_RTESYN_CPN4(_)                \


#endif /*RTESIGSCONFIGLIST_H_*/

/**************************** Copyright(C) pxf ****************************/
