/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : main.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/28 23:30:09
* Description  : 
* Others       : 
* History      : 191228 pxf ���ν���
***************************************************************************/

/*ͷ�ļ�����*/
#include "./main.h"

/*���� : main()
* ���� : ��
* ��� : ��
* ���� : ��
***********************************************/
int main(void){
    RteAsynSetGetInit();
	RetSynServTrigInit();

	for(;;){
		// SetGetRun();
		// ServTrigRun();

		taskCpn1();
		taskCpn2();
		taskCpn3();
		taskCpn4();
	}
}





/**************************** Copyright(C) pxf ****************************/
