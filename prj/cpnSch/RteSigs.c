/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : RteSigs.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/28 23:34:56
* Description  : 
* Others       : 
* History      : 191228 pxf 初次建立
***************************************************************************/

/*头文件包含*/
#include "./RteSigs.h"

// 服务信号预先定义好
uint16 serv1Cnt = 0;
void cpn1_serv1_serv(void){
    serv1Cnt++;
}

uint32 ulServ2Unpack = 0;
void cpn1_serv2_serv(void *buff, uint16 buffLen){
    if(sizeof(ulServ2Unpack) == buffLen){
        ulServ2Unpack = *(uint32*)buff;
    }
}

uint8 ucServ3Buff[5] = {0};
void cpn1_serv3_serv(void *buff, uint16 buffLen){
    if(sizeof(ucServ3Buff) == buffLen){
        ucServ3Buff[0] = ((uint8*)buff)[0];
        ucServ3Buff[1] = ((uint8*)buff)[1];
        ucServ3Buff[2] = ((uint8*)buff)[2];
        ucServ3Buff[3] = ((uint8*)buff)[3];
        ucServ3Buff[4] = ((uint8*)buff)[4];
    }
}


// 信号进行触发
uint32 ulTrig1Pack = 0;
void cpn2_trig1_trig(void *buff, uint16 buffLen)
{
    clRteSynSigs.trig(clRteSynSigs.self, cpn2_trig1, &ulTrig1Pack, sizeof(ulTrig1Pack));
}

uint8 ucTirg2Buff[5] = {0};
void cpn2_trig2_trig(void *buff, uint16 buffLen)
{
    clRteSynSigs.trig(clRteSynSigs.self, cpn2_trig2, ucTirg2Buff, sizeof(ucTirg2Buff));
}

void cpn2_trig3_trig(void)
{
    clRteSynSigs.trig(clRteSynSigs.self, cpn2_trig3, NULL, 0);
}


void ServTrigRun(void)
{
    static uint8 servTrigCnt = 0;
    servTrigCnt++;

    ulTrig1Pack += servTrigCnt;
    ucTirg2Buff[0] += servTrigCnt;

    cpn2_trig1_trig(&ulTrig1Pack,sizeof(ulTrig1Pack));
    cpn2_trig2_trig(ucTirg2Buff,sizeof(ucTirg2Buff));
    cpn2_trig3_trig();
}






// 收发信号
uint8 ucSendChar = 0xA5;
uint32 ulSendLong = 0x1234578;
uint8 ucSendChar3[3] = {0x11,0x22,0x33};
uint8 ucReceiveChar = 0;
uint32 ulReceiveLong = 0;
uint8 ucReceiveChar3[3] = {0};

void SetGetRun(void)
{
    static uint8 setGetCnt = 0;
    setGetCnt++;

    ucSendChar += setGetCnt;
    ulSendLong += setGetCnt;
    ucSendChar3[0] += setGetCnt;

    clRteAsynSigs.set(clRteAsynSigs.self,cpn1_send1,&ucSendChar,sizeof(ucSendChar));
    clRteAsynSigs.set(clRteAsynSigs.self,cpn1_send2,&ulSendLong,sizeof(ulSendLong));
    clRteAsynSigs.set(clRteAsynSigs.self,cpn1_send3,ucSendChar3,sizeof(ucSendChar3));

    clRteAsynSigs.get(clRteAsynSigs.self,cpn2_receive1,&ulReceiveLong,sizeof(ulReceiveLong));
    clRteAsynSigs.get(clRteAsynSigs.self,cpn2_receive2,&ucReceiveChar,sizeof(ucReceiveChar));
    clRteAsynSigs.get(clRteAsynSigs.self,cpn2_receive3,ucReceiveChar3,sizeof(ucReceiveChar3));
}



/**************************** Copyright(C) pxf ****************************/
