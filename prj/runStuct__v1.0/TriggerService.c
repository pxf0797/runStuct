/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : TriggerService.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/22 08:25:43
* Description  : 
* Others       : 
* History      : 191222 pxf 初次建立
***************************************************************************/

/*头文件包含*/
#include "./TriggerService.h"
#include "./RteSyn.h"

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 服务信号预先定义好
uint16 serv1Cnt = 0;
void cpn1_serv1_serv(void){
    serv1Cnt++;
}

uint32 ulServ2Unpack = 0;
void cpn1_serv2_serv(void *buff, uint16 buffLen){
    if(sizeof(ulServ2Unpack) == buffLen){
        ulServ2Unpack = *(uint32*)buff;
    }
}

uint8 ucServ3Buff[5] = {0};
void cpn1_serv3_serv(void *buff, uint16 buffLen){
    if(sizeof(ucServ3Buff) == buffLen){
        ucServ3Buff[0] = ((uint8*)buff)[0];
        ucServ3Buff[1] = ((uint8*)buff)[1];
        ucServ3Buff[2] = ((uint8*)buff)[2];
        ucServ3Buff[3] = ((uint8*)buff)[3];
        ucServ3Buff[4] = ((uint8*)buff)[4];
    }
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>



// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 需要在头文件中进行定义，主要有三个内容，信号列表、注册信号和信号映射
// 注册信号主要是需要定义一个统一的注册类型

// 建立服务信号列表
// 服务信号一定要建立与触发信号一致的传输类型数据类型，用于识别大小，而不依赖触发信号
#define SIGNAL_SERV_LIST(_)                                           \
    _(cpn1_serv1,cpn1_serv1_serv,0)                                   \
    _(cpn1_serv2,cpn1_serv2_serv,sizeof(ulServ2Unpack))               \
    _(cpn1_serv3,cpn1_serv3_serv,sizeof(ucServ3Buff))                 \

// 建立触发信号列表进行映射，配置信号时需要检查与服务信号的长度，默认一致，不符时需要进行报错
// 触发信号类型定义可以独立于服务数据类型，只要保证大小一致
#define SIGNAL_TRIG_MAP_LIST(_)                                       \
    _(cpn2_trig1,cpn1_serv2,sizeof(ulServ2Unpack))                    \
    _(cpn2_trig2,cpn1_serv3,sizeof(ucServ3Buff))                      \
    _(cpn2_trig3,cpn1_serv1,0)                                        \


// 定义需要注册的服务触发信号
#define SYN_SERV_SIGNAL_REGISTER(signal_serv,serv,len)                 SIGNAL_SERV_REGISTER(RteSyn,signal_serv,serv,len)
#define SYN_TRIG_SIGNAL_REGISTER(signal_trig,signal_serv,len)          SIGNAL_TRIG_REGISTER(RteSyn,signal_trig,signal_serv,len)

// 建立服务触发信号映射
SIGNAL_SERVTRIG_MAP(RteSyn,SIGNAL_SERV_LIST,SIGNAL_TRIG_MAP_LIST);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 需要在源文件进行定义和使用，主要有两个内容，缓存定义和信号进行注册

// 定义服务触发信号缓存
BUFF_SERVTRIG_DEFINE(RteSyn,SIGNAL_SERV_LIST,SIGNAL_TRIG_MAP_LIST);

// 定义服务触发类
RteSyn clRteSyn;

void ServTrigInit(void)
{
    // 对信号进行注册
    SIGNALS_SERVTRIG_REGISTER(SIGNAL_SERV_LIST,SYN_SERV_SIGNAL_REGISTER);
    SIGNALS_SERVTRIG_REGISTER(SIGNAL_TRIG_MAP_LIST,SYN_TRIG_SIGNAL_REGISTER);

    // 初始化调用类
    CN(RteSyn,&clRteSyn,RteSynSigServParamLen,RteSynSigServBuff,RteSynSigTrigIndex);
}


// 信号进行触发
uint32 ulTrig1Pack = 0;
void cpn2_trig1_trig(void *buff, uint16 buffLen)
{
    clRteSyn.trig(clRteSyn.self, cpn2_trig1, &ulTrig1Pack, sizeof(ulTrig1Pack));
}

uint8 ucTirg2Buff[5] = {0};
void cpn2_trig2_trig(void *buff, uint16 buffLen)
{
    clRteSyn.trig(clRteSyn.self, cpn2_trig2, ucTirg2Buff, sizeof(ucTirg2Buff));
}

void cpn2_trig3_trig(void)
{
    clRteSyn.trig(clRteSyn.self, cpn2_trig3, NULL, 0);
}


void ServTrigRun(void)
{
    static uint8 servTrigCnt = 0;
    servTrigCnt++;

    ulTrig1Pack += servTrigCnt;
    ucTirg2Buff[0] += servTrigCnt;

    cpn2_trig1_trig(&ulTrig1Pack,sizeof(ulTrig1Pack));
    cpn2_trig2_trig(ucTirg2Buff,sizeof(ucTirg2Buff));
    cpn2_trig3_trig();
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>



/**************************** Copyright(C) pxf ****************************/
