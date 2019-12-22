/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : main.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/22 12:58:49
* Description  : 
* Others       : 
* History      : 191222 pxf 初次建立
***************************************************************************/

/*头文件包含*/
#include "./main.h"

/*名称 : main()
* 输入 : 无
* 输出 : 无
* 其他 : 无
***********************************************/
void main(void){
	SetGetInit();
	ServTrigInit();

	for(;;){
		SetGetRun();
		ServTrigRun();
	}
}

/**************************** Copyright(C) pxf ****************************/
