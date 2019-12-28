/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : CpnSch.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/28 14:16:09
* Description  : CpnSch类各功能函数定义源文件
* Others       : 
* History      : 191228 pxf 初次建立
***************************************************************************/

/*头文件包含*/
#include "./CpnSch.h"

/***********************************************************
* CpnSch类定义
***********************************************************/
/*名称 : CpnSch_tick(hCpnSch cthis)
* 输入 : cthis - CpnSch类指针
* 输出 : 无
* 其他 : CpnSch类功能函数
***********************************************/
void CpnSch_tick(hCpnSch cthis){
    cthis->SchSmRec.ticker++;
}

/*名称 : CpnSch_run(hCpnSch cthis)
* 输入 : cthis - CpnSch类指针
* 输出 : 无
* 其他 : CpnSch类功能函数
***********************************************/
void CpnSch_run(hCpnSch cthis){
    if(cthis->SchSm){
        SMRE(cthis->SchSm, cthis->SchSmRec);
    }
}

/*名称 : CpnSch_time(hCpnSch cthis)
* 输入 : cthis - CpnSch类指针
* 输出 : 无
* 其他 : CpnSch类功能函数
***********************************************/
void CpnSch_time(hCpnSch cthis, uint16 *point){
    cthis->iTime.getTime(point);
}

/*名称 : CpnSch_addTask(hCpnSch cthis)
* 输入 : cthis - CpnSch类指针
* 输出 : 无
* 其他 : CpnSch类功能函数
***********************************************/
void CpnSch_addTask(hCpnSch cthis, taskLevel level, task t, uint16 prd, uint16 start){
    uint32 taskMask = 0;
    uint32 curTask = 0;
    uint16 taskIndex = 0;
    uint16 groupIndex = 0;
    uint16 levelGroupEnd = 0;

    if(level == level0){
        groupIndex = CPN_SCH_LEVEL3_GROUP_NUM_CFG + CPN_SCH_LEVEL2_GROUP_NUM_CFG + CPN_SCH_LEVEL1_GROUP_NUM_CFG;
        levelGroupEnd = groupIndex + CPN_SCH_LEVEL0_GROUP_NUM_CFG;
    }else if(level == level1){
        groupIndex = CPN_SCH_LEVEL3_GROUP_NUM_CFG + CPN_SCH_LEVEL2_GROUP_NUM_CFG;
        levelGroupEnd = groupIndex + CPN_SCH_LEVEL1_GROUP_NUM_CFG;
    }else if(level == level2){
        groupIndex = CPN_SCH_LEVEL3_GROUP_NUM_CFG;
        levelGroupEnd = groupIndex + CPN_SCH_LEVEL2_GROUP_NUM_CFG;
    }else if(level == level3){
        groupIndex = 0;
        levelGroupEnd = groupIndex + CPN_SCH_LEVEL3_GROUP_NUM_CFG;
    }else{
        cthis->err(cthis, CPN_SCH_ADD_TASK_LEVEVL_NOT_EIXST);
        return;
    }

    while(groupIndex < levelGroupEnd){
        taskMask = cthis->SchSmRec.taskGroups.taskMask[groupIndex];
        if(~taskMask){
            groupIndex++;
            // 全部占满则报错
            if(groupIndex >= levelGroupEnd){
                if(level == level0){
                    cthis->err(cthis, CPN_SCH_ADD_TASK_LEVEVL0GROUP_FULL);
                }else if(level == level1){
                    cthis->err(cthis, CPN_SCH_ADD_TASK_LEVEVL1GROUP_FULL);
                }else if(level == level2){
                    cthis->err(cthis, CPN_SCH_ADD_TASK_LEVEVL2GROUP_FULL);
                }else if(level == level3){
                    cthis->err(cthis, CPN_SCH_ADD_TASK_LEVEVL3GROUP_FULL);
                }else{
                    cthis->err(cthis, CPN_SCH_ADD_TASK_LEVEVL_NOT_EIXST);
                }
            }
        }else{
            // 添加新任务
            curTask = (~taskMask);
            curTask = (curTask & (curTask ^ (curTask - 1)));
            taskIndex = log_2n(curTask);
            taskMask |= curTask;

            cthis->SchSmRec.taskGroups.taskGroup[groupIndex][taskIndex] = t;
            cthis->SchSmRec.taskGroups.prdTick[groupIndex][taskIndex] = prd;
            cthis->SchSmRec.taskGroups.startTick[groupIndex][taskIndex] = start;
            break;
        }
    }
}

/*名称 : CpnSch_delTask(hCpnSch cthis)
* 输入 : cthis - CpnSch类指针
* 输出 : 无
* 其他 : CpnSch类功能函数
***********************************************/
void CpnSch_delTask(hCpnSch cthis, taskLevel level, task t){
    uint32 taskMask = 0;
    uint32 curTask = 0;
    uint16 taskIndex = 0;
    uint16 groupIndex = 0;
    uint16 levelGroupEnd = 0;

    if(level == level0){
        groupIndex = CPN_SCH_LEVEL3_GROUP_NUM_CFG + CPN_SCH_LEVEL2_GROUP_NUM_CFG + CPN_SCH_LEVEL1_GROUP_NUM_CFG;
        levelGroupEnd = groupIndex + CPN_SCH_LEVEL0_GROUP_NUM_CFG;
    }else if(level == level1){
        groupIndex = CPN_SCH_LEVEL3_GROUP_NUM_CFG + CPN_SCH_LEVEL2_GROUP_NUM_CFG;
        levelGroupEnd = groupIndex + CPN_SCH_LEVEL1_GROUP_NUM_CFG;
    }else if(level == level2){
        groupIndex = CPN_SCH_LEVEL3_GROUP_NUM_CFG;
        levelGroupEnd = groupIndex + CPN_SCH_LEVEL2_GROUP_NUM_CFG;
    }else if(level == level3){
        groupIndex = 0;
        levelGroupEnd = groupIndex + CPN_SCH_LEVEL3_GROUP_NUM_CFG;
    }else{
        cthis->err(cthis, CPN_SCH_DEL_TASK_LEVEVL_NOT_EIXST);
        return;
    }

    while(groupIndex < levelGroupEnd){
        taskMask = cthis->SchSmRec.taskGroups.taskMask[groupIndex];
        if(!taskMask){
            groupIndex++;
            // 不存在任务组中则报错
            if(groupIndex >= levelGroupEnd){
                if(level == level0){
                    cthis->err(cthis, CPN_SCH_DEL_TASK_LEVEVL0GROUP_NOT_EIXST);
                }else if(level == level1){
                    cthis->err(cthis, CPN_SCH_DEL_TASK_LEVEVL1GROUP_NOT_EIXST);
                }else if(level == level2){
                    cthis->err(cthis, CPN_SCH_DEL_TASK_LEVEVL2GROUP_NOT_EIXST);
                }else if(level == level3){
                    cthis->err(cthis, CPN_SCH_DEL_TASK_LEVEVL3GROUP_NOT_EIXST);
                }else{
                    cthis->err(cthis, CPN_SCH_DEL_TASK_LEVEVL_NOT_EIXST);
                }
            }
        }else{
            // 循环查找任务
            while(taskMask){
                curTask = taskMask;
                curTask = (curTask & (curTask ^ (curTask - 1)));
                taskIndex = log_2n(curTask);
                if(cthis->SchSmRec.taskGroups.taskGroup[groupIndex][taskIndex] == t){
                    cthis->SchSmRec.taskGroups.taskMask[groupIndex] &= (~curTask);
                    cthis->SchSmRec.taskGroups.actMask[groupIndex] &= (~curTask);
                    break;
                }
                // 未找到继续找
                taskMask &= (~curTask);
            }
            // 已找到则直接退出
            if(taskMask){
                break;
            }else{
                groupIndex++;
                // 未找到则报错
                if(groupIndex >= levelGroupEnd){
                    if(level == level0){
                        cthis->err(cthis, CPN_SCH_DEL_TASK_LEVEVL0GROUP_NOT_EIXST);
                    }else if(level == level1){
                        cthis->err(cthis, CPN_SCH_DEL_TASK_LEVEVL1GROUP_NOT_EIXST);
                    }else if(level == level2){
                        cthis->err(cthis, CPN_SCH_DEL_TASK_LEVEVL2GROUP_NOT_EIXST);
                    }else if(level == level3){
                        cthis->err(cthis, CPN_SCH_DEL_TASK_LEVEVL3GROUP_NOT_EIXST);
                    }else{
                        cthis->err(cthis, CPN_SCH_DEL_TASK_LEVEVL_NOT_EIXST);
                    }
                }
            }
        }
    }
}

/*名称 : CpnSch_delay(hCpnSch cthis)
* 输入 : cthis - CpnSch类指针
* 输出 : 无
* 其他 : CpnSch类功能函数
***********************************************/
void CpnSch_delay(hCpnSch cthis, uint32 *tick){
    uint32 tickTemp = 0;
    int16 rtv = 0;

    // 高位为0则认为初始化一个延时
    if(!(*tick & 0xFFFF0000)){
        tickTemp = cthis->SchSmRec.ticker;
        tickTemp = (tickTemp << 16);
        *tick |= tickTemp;
    }

    tickTemp = ((*tick & 0xFFFF0000) >> 16);
    if((cthis->SchSmRec.ticker - tickTemp) >= (*tick & 0x00007FFF)){
        *tick |= 0x00008000;      // 置起延时已到标志
    }
}

/*名称 : CpnSch_err(hCpnSch cthis)
* 输入 : cthis - CpnSch类指针
* 输出 : 无
* 其他 : CpnSch类功能函数
***********************************************/
void CpnSch_err(hCpnSch cthis, uint16 code){
    cthis->iErr.setErr(CPN_SCH_TASK_BLOCK_ID, code);
}

/*名称 : hCpnSch CpnSch_init(hCpnSch cthis)
* 输入 : cthis - CpnSch类指针
* 输出 : hCpnSch - cthis/OOPC_NULL
* 其他 : CpnSch类初始化函数
***********************************************/
hCpnSch CpnSch_init(hCpnSch cthis, hstaAct SchSm,
            void (*getTime)(uint16 *point),
            void (*setErr)(uint16 id, uint16 code)){
    // 功能函数配置
    cthis->iTime.getTime = getTime;
    cthis->iErr.setErr = setErr;

    // 参数配置
    cthis->SchSm = SchSm;

    return cthis;
}

/*名称 : hCpnSch CpnSch_ctor(hCpnSch cthis)
* 输入 : cthis - CpnSch类指针
* 输出 : hCpnSch - cthis/OOPC_NULL
* 其他 : CpnSch类构造函数
***********************************************/
CC(CpnSch){
    cthis->init = CpnSch_init;
    cthis->tick = CpnSch_tick;
    cthis->run = CpnSch_run;
    cthis->time = CpnSch_time;
    cthis->addTask = CpnSch_addTask;
    cthis->delTask = CpnSch_delTask;
    cthis->delay = CpnSch_delay;
    cthis->err = CpnSch_err;
    //TODO

    // 参数配置
    cthis->usage = 0;
    cthis->currTaskTime = 0;
    cthis->totalTaskTime = 0;
    cthis->SchSm = NULL;
    cthis->SchSmRec.next = SchSm_sta_init;

    return cthis;
}

/*名称 : hCpnSch CpnSch_dtor(hCpnSch cthis)
* 输入 : cthis - CpnSch类指针
* 输出 : OOPC_RETURN_DATATYPE - OOPC_TRUE/OOPC_FALSE
* 其他 : CpnSch类析构函数
***********************************************/
CD(CpnSch){
    return OOPC_TRUE;
}

/**************************** Copyright(C) pxf ****************************/
