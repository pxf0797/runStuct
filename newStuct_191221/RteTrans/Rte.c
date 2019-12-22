/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : Rte.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/12/21 11:55:05
* Description  : Rte类各功能函数定义源文件
* Others       : 
* History      : 191221 pxf 初次建立
***************************************************************************/

/*头文件包含*/
#include "./Rte.h"

/***********************************************************
* Rte类定义
***********************************************************/
/*名称 : Rte_run(hRte cthis)
* 输入 : cthis - Rte类指针
* 输出 : 无
* 其他 : Rte类功能函数
***********************************************/
void Rte_run(hRte cthis){
    //TODO
}

/*名称 : hRte Rte_init(hRte cthis)
* 输入 : cthis - Rte类指针
* 输出 : hRte - cthis/OOPC_NULL
* 其他 : Rte类初始化函数
***********************************************/
hRte Rte_init(hRte cthis){
    // 功能函数配置
    //cthis->run = Rte_run;
    //TODO

    // 参数配置
    //TODO

    return cthis;
}

/*名称 : hRte Rte_ctor(hRte cthis)
* 输入 : cthis - Rte类指针
* 输出 : hRte - cthis/OOPC_NULL
* 其他 : Rte类构造函数
***********************************************/
CC(Rte){
    cthis->init = Rte_init;
    cthis->run = Rte_run;
    //TODO

    // 参数配置
    //TODO
    return cthis;
}

/*名称 : hRte Rte_dtor(hRte cthis)
* 输入 : cthis - Rte类指针
* 输出 : OOPC_RETURN_DATATYPE - OOPC_TRUE/OOPC_FALSE
* 其他 : Rte类析构函数
***********************************************/
CD(Rte){
    return OOPC_TRUE;
}

/**************************** Copyright(C) pxf ****************************/
