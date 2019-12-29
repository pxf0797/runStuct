/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : SchSm.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/28 14:24:20
* Description  : ״̬��SchSm���弰��״̬��������Դ�ļ�
* Others       : 
* History      : 191228 pxf ���ν���
***************************************************************************/

/*ͷ�ļ�����*/
#include "./SchSm.h"
#include "./CpnSch.h"

/*״̬��SchSm����
* ����״̬����ش���״̬
***********************************************/
SMDF(SchSm, SCHSM_LIST);
extern CpnSch clCpnSch;

/*���� : SchSm_act_init()
* ���� : SchSmRec - ״̬��¼����ָ��
* ��� : ��
* ���� : ��ʼ״̬��������
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
            hRec->taskGroups[i].startTick[j] = 0;
            hRec->taskGroups[i].prdTick[j] = 0;
            hRec->taskGroups[i].taskGroup[j] = NULL;
        }
        hRec->taskGroups[i].actMask = 0;
        hRec->taskGroups[i].taskMask = 0;
    }

    hRec->next = SchSm_sta_execute;
    hRec->last = SchSm_sta_init;
}

/*���� : SchSm_act_default()
* ���� : SchSmRec - ״̬��¼����ָ��
* ��� : ��
* ���� : Ĭ��״̬��������
***********************************************/
void SchSm_act_default(void *SchSmRec){
    hSchSmRec hRec = (hSchSmRec)SchSmRec;

    // TODO

    hRec->next = SchSm_sta_default;
    hRec->last = SchSm_sta_default;
}

/*���� : SchSm_act_update()
* ���� : SchSmRec - ״̬��¼����ָ��
* ��� : ��
* ���� : ״̬update��������
***********************************************/
void SchSm_act_update(void *SchSmRec){
    hSchSmRec hRec = (hSchSmRec)SchSmRec;
    uint32 taskMask = 0;
    uint32 curTask = 0;
    uint16 taskIndex = 0;
    int16 i = 0;

    for(i = 0; i < hRec->taskGroupNum; i++){
        // ���¸��鼤������
        taskMask = hRec->taskGroups[i].taskMask;
        while(taskMask != 0){
            curTask = (taskMask & (taskMask ^ (taskMask - 1)));
            taskMask ^= curTask;
            taskIndex = log_2n(curTask);

            if((hRec->ticker - hRec->taskGroups[i].startTick[taskIndex]) >= hRec->taskGroups[i].prdTick[taskIndex]){
                // ���¼���״̬�Լ���һ������ʼ����
                hRec->taskGroups[i].actMask |= curTask;
                hRec->taskGroups[i].startTick[taskIndex] += hRec->taskGroups[i].prdTick[taskIndex];
            }
        }
    }

    hRec->next = SchSm_sta_execute;
    hRec->last = SchSm_sta_update;
}

/*���� : SchSm_act_execute()
* ���� : SchSmRec - ״̬��¼����ָ��
* ��� : ��
* ���� : ״̬execute��������
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
        // �鿴�������񣬲�ִ��������ȼ�����
        taskMask = hRec->taskGroups[i].actMask;
        if(taskMask != 0){
            curTask = (taskMask & (taskMask ^ (taskMask - 1)));
            //taskMask ^= curTask;
            //hRec->taskGroups[i].actMask ^= curTask; // �����������ɿؽ��
            hRec->taskGroups[i].actMask &= (~curTask);
            taskIndex = log_2n(curTask);

            // �ж��Ƿ�Ϊһ�������������level0�������������������ȥ��
            if((hRec->taskGroups[i].prdTick[taskIndex] == 0) && (i < (hRec->taskGroupNum - CPN_SCH_LEVEL0_GROUP_NUM_CFG))){
                hRec->taskGroups[i].taskMask &= (~curTask);
            }

            // ִ������
            if(hRec->taskGroups[i].taskGroup[taskIndex]){
                hRec->taskGroups[i].taskGroup[taskIndex]();
            }
            break;
        }
    }

#if (CPN_SCH_TASK_MEASURE_ENABLE == TRUE)
    ((hCpnSch)(hRec->CpnSch))->currTaskTime = taskTimePot;
    ((hCpnSch)(hRec->CpnSch))->time(hRec->CpnSch, &taskTimePot);
    ((hCpnSch)(hRec->CpnSch))->currTaskTime = taskTimePot - ((hCpnSch)(hRec->CpnSch))->currTaskTime;
    // Ŀǰʱ�������ȷ��1us��ʹ���ʾ�ȷ��0.1%
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
    }else if((i >= hRec->taskGroupNum) && (!hRec->taskGroups[hRec->taskGroupNum - 1].actMask)){
        hRec->next = SchSm_sta_updateBgTask;
    }else{
        hRec->next = SchSm_sta_execute;
    }
    hRec->last = SchSm_sta_execute;
}

/*���� : SchSm_act_updateBgTask()
* ���� : SchSmRec - ״̬��¼����ָ��
* ��� : ��
* ���� : ״̬updateBgTask��������
***********************************************/
void SchSm_act_updateBgTask(void *SchSmRec){
    hSchSmRec hRec = (hSchSmRec)SchSmRec;
    int16 i = 0;

    for(i = (hRec->taskGroupNum - CPN_SCH_LEVEL0_GROUP_NUM_CFG); i < hRec->taskGroupNum; i++){
        hRec->taskGroups[i].actMask = hRec->taskGroups[i].taskMask;
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