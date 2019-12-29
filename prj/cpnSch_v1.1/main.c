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
	uint16 uwTickCnt = 0;
	
    RteAsynSetGetInit();
	RetSynServTrigInit();

	trig_Abi_init();
	taskCpn1Init();
	taskCpn2Init();
	taskCpn3Init();
	taskCpn4Init();

	for(;;){
		// SetGetRun();
		// ServTrigRun();

		// taskCpn1();
		// taskCpn2();
		// taskCpn3();
		// taskCpn4();

		if(!(uwTickCnt & 0x0003)){
			trig_Abi_tick();
		}
		uwTickCnt++;
		trig_Abi_run();
	}
}





/**************************** Copyright(C) pxf ****************************/
