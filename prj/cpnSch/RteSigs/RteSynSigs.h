/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : RteSynSigs.h
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/28 23:08:24
* Description  : 
* Others       : 
* History      : 191228 pxf 初次建立
***************************************************************************/

#ifndef RTESYNSIGS_H_
#define RTESYNSIGS_H_

/*头文件包含*/
#include "../standType/standType.h"
#include "../Rte/RteAsyn.h"
#include "../Rte/RteSyn.h"
#include "../Rte/TriggerService.h"
#include "../RteSigs.h"

// 建立服务信号列表
// 服务信号一定要建立与触发信号一致的传输类型数据类型，用于识别大小，而不依赖触发信号
#define SIGNAL_SERV_LIST_RTESYN(_)                                    \
    _(cpn1_serv1,cpn1_serv1_serv,0)                                   \
    _(cpn1_serv2,cpn1_serv2_serv,sizeof(ulServ2Unpack))               \
    _(cpn1_serv3,cpn1_serv3_serv,sizeof(ucServ3Buff))                 \

// 建立触发信号列表进行映射，配置信号时需要检查与服务信号的长度，默认一致，不符时需要进行报错
// 触发信号类型定义可以独立于服务数据类型，只要保证大小一致
#define SIGNAL_TRIG_MAP_LIST_RTESYN(_)                                \
    _(cpn2_trig1,cpn1_serv2,sizeof(ulServ2Unpack))                    \
    _(cpn2_trig2,cpn1_serv3,sizeof(ucServ3Buff))                      \
    _(cpn2_trig3,cpn1_serv1,0)                                        \


// 定义需要注册的服务触发信号
#define SYN_SERV_SIGNAL_REGISTER(signal_serv,serv,len)                 SIGNAL_SERV_REGISTER(RteSynSigs,signal_serv,serv,len)
#define SYN_TRIG_SIGNAL_REGISTER(signal_trig,signal_serv,len)          SIGNAL_TRIG_REGISTER(RteSynSigs,signal_trig,signal_serv,len)

// 建立服务触发信号映射
SIGNAL_SERVTRIG_MAP(RteSynSigs,SIGNAL_SERV_LIST_RTESYN,SIGNAL_TRIG_MAP_LIST_RTESYN);

// 同步信号初始化函数
void RetSynServTrigInit(void);

// 定义服务触发类
extern RteSyn clRteSynSigs;

#endif /*RTESYNSIGS_H_*/

/**************************** Copyright(C) pxf ****************************/
