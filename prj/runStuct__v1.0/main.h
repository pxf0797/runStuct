/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : main.h
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/22 12:58:49
* Description  : 
* Others       : 
* History      : 191222 pxf ���ν���
***************************************************************************/

#ifndef MAIN_H_
#define MAIN_H_

/*ͷ�ļ�����*/
#include "./SetGet.h"
#include "./RteAsyn.h"
#include "./TriggerService.h"
#include "./RteSyn.h"



extern void SetGetInit(void);
extern void SetGetRun(void);
extern void ServTrigInit(void);
extern void ServTrigRun(void);


/*���� : main()
* ���� : ��
* ��� : ��
* ���� : ��
***********************************************/
void main(void);

#endif /*MAIN_H_*/

/**************************** Copyright(C) pxf ****************************/
