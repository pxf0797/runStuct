/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : RteSigs.h
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/28 23:34:56
* Description  : 
* Others       : 
* History      : 191228 pxf 初次建立
***************************************************************************/

#ifndef RTESIGS_H_
#define RTESIGS_H_

/*头文件包含*/
#include "./standType/standType.h"
#include "./RteSigs/RteAsynSigs.h"
#include "./RteSigs/RteSynSigs.h"
#include "./RteSigs/RteCpnSch.h"

extern uint32 ulServ2Unpack;
extern uint8 ucServ3Buff[5];
void cpn1_serv1_serv(void);
void cpn1_serv2_serv(void *buff, uint16 buffLen);
void cpn1_serv3_serv(void *buff, uint16 buffLen);

extern void ServTrigInit(void);
extern void ServTrigRun(void);

#endif /*RTESIGS_H_*/

/**************************** Copyright(C) pxf ****************************/
