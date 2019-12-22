/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : main.h
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/22 12:58:49
* Description  : 
* Others       : 
* History      : 191222 pxf 初次建立
***************************************************************************/

#ifndef MAIN_H_
#define MAIN_H_

/*头文件包含*/
#include "./SetGet.h"
#include "./RteAsyn.h"
#include "./TriggerService.h"
#include "./RteSyn.h"



extern void SetGetInit(void);
extern void SetGetRun(void);
extern void ServTrigInit(void);
extern void ServTrigRun(void);


/*名称 : main()
* 输入 : 无
* 输出 : 无
* 其他 : 无
***********************************************/
void main(void);

#endif /*MAIN_H_*/

/**************************** Copyright(C) pxf ****************************/
