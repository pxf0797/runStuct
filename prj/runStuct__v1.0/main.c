/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : main.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/22 12:58:49
* Description  : 
* Others       : 
* History      : 191222 pxf ���ν���
***************************************************************************/

/*ͷ�ļ�����*/
#include "./main.h"

/*���� : main()
* ���� : ��
* ��� : ��
* ���� : ��
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
