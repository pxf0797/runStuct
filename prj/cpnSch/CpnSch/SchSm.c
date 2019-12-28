/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : SchSm.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/28 14:24:20
* Description  : 状态机SchSm定义及各状态动作定义源文件
* Others       : 
* History      : 191228 pxf 初次建立
***************************************************************************/

/*头文件包含*/
#include "./SchSm.h"
#include "./CpnSch.h"

/*状态机SchSm定义
* 配置状态机相关处理状态
***********************************************/
SMDF(SchSm, SCHSM_LIST);
extern CpnSch clCpnSch;

/*名称 : SchSm_act_init()
* 输入 : SchSmRec - 状态记录参数指针
* 输出 : 无
* 其他 : 初始状态操作函数
***********************************************/
void SchSm_act_init(void *SchSmRec){
    hSchSmRec hRec = (hSchSmRec)SchSmRec;
    int16 i = 0;
    int16 j = 0;

    hRec->ticker = 0;
    hRec->taskGroupNum = CPN_SCH_GROUP_TOTAL_NUMS;
    hRec->CpnSch = &clCpnSch;
    for(i = 0; i < CPN_SCH_GROUP_TOTAL_NUMS; i++){
        for(j = 0; j < 32; j++){
            hRec->taskGroups.startTick[i][j] = 0;
            hRec->taskGroups.prdTick[i][j] = 0;
            hRec->taskGroups.taskGroup[i][j] = NULL;
        }
        hRec->taskGroups.actMask[i] = 0;
        hRec->taskGroups.taskMask[i] = 0;
    }

    hRec->next = SchSm_sta_execute;
    hRec->last = SchSm_sta_init;
}

/*名称 : SchSm_act_default()
* 输入 : SchSmRec - 状态记录参数指针
* 输出 : 无
* 其他 : 默认状态操作函数
***********************************************/
void SchSm_act_default(void *SchSmRec){
    hSchSmRec hRec = (hSchSmRec)SchSmRec;

    // TODO

    hRec->next = SchSm_sta_default;
    hRec->last = SchSm_sta_default;
}

/*名称 : SchSm_act_update()
* 输入 : SchSmRec - 状态记录参数指针
* 输出 : 无
* 其他 : 状态update操作函数
***********************************************/
void SchSm_act_update(void *SchSmRec){
    hSchSmRec hRec = (hSchSmRec)SchSmRec;
    uint32 taskMask = 0;
    uint32 curTask = 0;
    uint16 taskIndex = 0;
    int16 i = 0;

    for(i = 0; i < hRec->taskGroupNum; i++){
        // 更新各组激活任务
        taskMask = hRec->taskGroups.taskMask[i];
        while(taskMask != 0){
            curTask = (taskMask & (taskMask ^ (taskMask - 1)));
            taskMask ^= curTask;
            taskIndex = log_2n(curTask);

            if((hRec->ticker - hRec->taskGroups.startTick[i][taskIndex]) >= hRec->taskGroups.prdTick[i][taskIndex]){
                // 更新激活状态以及下一激活起始节拍
                hRec->taskGroups.actMask[i] |= curTask;
                hRec->taskGroups.startTick[i][taskIndex] += hRec->taskGroups.prdTick[i][taskIndex];
            }
        }
    }

    hRec->next = SchSm_sta_execute;
    hRec->last = SchSm_sta_update;
}

/*名称 : SchSm_act_execute()
* 输入 : SchSmRec - 状态记录参数指针
* 输出 : 无
* 其他 : 状态execute操作函数
***********************************************/
void SchSm_act_execute(void *SchSmRec){
    hSchSmRec hRec = (hSchSmRec)SchSmRec;
    uint32 taskMask = 0;
    uint32 curTask = 0;
    uint16 taskIndex = 0;
    int16 i = 0;
#if (CPN_SCH_TASK_MEASURE_ENABLE == TRUE)
    static uint16 taskTimePot = 0;
    uint16 currUsage = 0;
    ((hCpnSch)(hRec->CpnSch))->time(hRec->CpnSch, &taskTimePot);
#endif

    for(i = 0; i < hRec->taskGroupNum; i++){
        // 查看激活任务，并执行最高优先级任务
        taskMask = hRec->taskGroups.actMask[i];
        if(taskMask != 0){
            curTask = (taskMask & (taskMask ^ (taskMask - 1)));
            //taskMask ^= curTask;
            //hRec->taskGroups.actMask[i] ^= curTask; // 容易引发不可控结果
            hRec->taskGroups.actMask[i] &= (~curTask);
            taskIndex = log_2n(curTask);

            // 判断是否为一次性任务，如果非level0背景任务则把任务掩码去除
            if((hRec->taskGroups.prdTick[i][taskIndex] == 0) && (i < (hRec->taskGroupNum - CPN_SCH_LEVEL0_GROUP_NUM_CFG))){
                hRec->taskGroups.taskMask[i] &= (~curTask);
            }

            // 执行任务
            if(hRec->taskGroups.taskGroup[i][taskIndex]){
                hRec->taskGroups.taskGroup[i][taskIndex]();
            }
            break;
        }
    }

#if (CPN_SCH_TASK_MEASURE_ENABLE == TRUE)
    ((hCpnSch)(hRec->CpnSch))->currTaskTime = taskTimePot;
    ((hCpnSch)(hRec->CpnSch))->time(hRec->CpnSch, &taskTimePot);
    ((hCpnSch)(hRec->CpnSch))->currTaskTime = taskTimePot - ((hCpnSch)(hRec->CpnSch))->currTaskTime;
    // 目前时间测量精确到1us，使用率精确到0.1%
    if(i < (hRec->taskGroupNum - CPN_SCH_LEVEL0_GROUP_NUM_CFG)){
        ((hCpnSch)(hRec->CpnSch))->totalTaskTime += ((hCpnSch)(hRec->CpnSch))->currTaskTime;
    }else{
        if(((hCpnSch)(hRec->CpnSch))->totalTaskTime){
            currUsage = (((hCpnSch)(hRec->CpnSch))->totalTaskTime * 10U / CPN_SCH_TASK_TICK_TIME_US);
            ((hCpnSch)(hRec->CpnSch))->usage = lowpassFilter(currUsage, (uint32)((hCpnSch)(hRec->CpnSch))->usage, 4U);
            ((hCpnSch)(hRec->CpnSch))->totalTaskTime = 0U;
        }
    }
#endif

    if(hRec->ticker != hRec->tickerLast)
    {
        hRec->next = SchSm_sta_update;
    }else if((i >= hRec->taskGroupNum) && (!hRec->taskGroups.actMask[hRec->taskGroupNum - 1])){
        hRec->next = SchSm_sta_updateBgTask;
    }else{
        hRec->next = SchSm_sta_execute;
    }
    hRec->last = SchSm_sta_execute;
}

/*名称 : SchSm_act_updateBgTask()
* 输入 : SchSmRec - 状态记录参数指针
* 输出 : 无
* 其他 : 状态updateBgTask操作函数
***********************************************/
void SchSm_act_updateBgTask(void *SchSmRec){
    hSchSmRec hRec = (hSchSmRec)SchSmRec;
    int16 i = 0;

    for(i = (hRec->taskGroupNum - CPN_SCH_LEVEL0_GROUP_NUM_CFG); i < hRec->taskGroupNum; i++){
        hRec->taskGroups.actMask[i] = hRec->taskGroups.taskMask[i];
    }

    if(hRec->ticker != hRec->tickerLast)
    {
        hRec->next = SchSm_sta_update;
    }else{
        hRec->next = SchSm_sta_execute;
    }
    hRec->last = SchSm_sta_updateBgTask;
}

/**************************** Copyright(C) pxf ****************************/
