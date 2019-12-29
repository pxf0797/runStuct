/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : CpnSchCfg.h
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/28 14:02:40
* Description  : 
* Others       : 
* History      : 191228 pxf ���ν���
***************************************************************************/

#ifndef CPNSCHCFG_H_
#define CPNSCHCFG_H_

/*ͷ�ļ�����*/

// ÿ����������Դ��32������ÿ������ȼ��������ò�ͬ��������
#define CPN_SCH_LEVEL0_GROUP_NUM_CFG            2U                                      // level0��������������������
#define CPN_SCH_LEVEL1_GROUP_NUM_CFG            2U                                      // level1������������
#define CPN_SCH_LEVEL2_GROUP_NUM_CFG            1U                                      // level2������������
#define CPN_SCH_LEVEL3_GROUP_NUM_CFG            1U                                      // level3������������
#define CPN_SCH_GROUP_TOTAL_NUMS                (CPN_SCH_LEVEL0_GROUP_NUM_CFG  \
                                                + CPN_SCH_LEVEL1_GROUP_NUM_CFG \
                                                + CPN_SCH_LEVEL2_GROUP_NUM_CFG \
                                                + CPN_SCH_LEVEL3_GROUP_NUM_CFG)         // ����������

// �����ܲ�������
#define CPN_SCH_TASK_MEASURE_ENABLE             TRUE                                    // ��������ʱ����� TRUE FALSE
#define CPN_SCH_TASK_TICK_TIME_US               500U                                    // ����ʱ��500US

// �����Ӧ�����־ID
#define CPN_SCH_TASK_BLOCK_ID                   0U                                      // �����ϱ�ID
/*errDefine
***********************************************************************************************************************/
#define CPN_SCH_ADD_TASK_LEVEVL_NOT_EIXST            0x0000U                                 // ��������鲻����
#define CPN_SCH_ADD_TASK_LEVEVL0GROUP_FULL           0x0001U                                 // �㼶����������
#define CPN_SCH_ADD_TASK_LEVEVL1GROUP_FULL           0x0002U                                 // һ������������
#define CPN_SCH_ADD_TASK_LEVEVL2GROUP_FULL           0x0003U                                 // ��������������
#define CPN_SCH_ADD_TASK_LEVEVL3GROUP_FULL           0x0004U                                 // ��������������
/**********************************************************************************************************************/
#define CPN_SCH_DEL_TASK_LEVEVL_NOT_EIXST            0x0010U                                 // ɾ�������鲻����
#define CPN_SCH_DEL_TASK_LEVEVL0GROUP_NOT_EIXST      0x0011U                                 // �㼶�����鲻���ڴ�����
#define CPN_SCH_DEL_TASK_LEVEVL1GROUP_NOT_EIXST      0x0012U                                 // һ�������鲻���ڴ�����
#define CPN_SCH_DEL_TASK_LEVEVL2GROUP_NOT_EIXST      0x0013U                                 // ���������鲻���ڴ�����
#define CPN_SCH_DEL_TASK_LEVEVL3GROUP_NOT_EIXST      0x0014U                                 // ���������鲻���ڴ�����


#endif /*CPNSCHCFG_H_*/

/**************************** Copyright(C) pxf ****************************/
