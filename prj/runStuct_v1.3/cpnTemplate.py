#!usr/bin/env python3
#coding: utf-8
#cpnTemplate.py  component

import sys
import datetime
import os
sys.path.append(os.getcwd())
import cTemplate
import classTemplate

class cpnTemplate:
    """文件生成脚本
    使用方法：python cpnTemplate.py path cpnName func_list
    脚本至少需要4个参数，
    路径path，当前路径可以使用/或\，其他路径一定要以非/或\开头，否则生成不了
    cpnName根据需要选取
    func_list是多个参数，目前配置类时至少需要给定1个功能函数"""
    __encoding = 'gb2312' #'utf-8' 'gb2312' ''
    __fileName = ''
    __sourceName = ''
    __headerName = ''
    __filePath = ''
    __func_list = []
    __cTemp_args = ''
    __cTemp = ''
    __classTemp = ''
    #__OopcHeaderPath = 'oopc_v1.02/oopc.h'
    #__StandTypeHeaderPath = 'standType/standType.h'
    __RteHeaderPath = 'Rte/Ret.h'
    __RteSigsHeaderPath = 'RteSigs/RetSigs.h'

    def __init__(self,sys_args):
        """根据输入参数初始化参数

        主要功能：
        1.生成文件名称
        2.生成文件路径
        3.生成函数列表"""
        if sys_args[1] != '/' and sys_args[1] != '\\':
            self.__filePath = sys_args[1]
        else:
            self.__filePath = ''
        self.__fileName = sys_args[2]
        self.__sourceName = sys_args[2] + "Sigs.c"
        self.__headerName = sys_args[2] + 'Sigs.h'
        self.__func_list = sys_args[3:]
        self.__cTemp_args = sys_args[0:3]
        self.__cTemp_args[2] = sys_args[2]+'Cfg'
        self.__cTemp = cTemplate.cTemplate(self.__cTemp_args)
        self.__classTemp = classTemplate.classTemplate(sys_args)
        
    #========================================================
    # 信号专用生成函数
    #--------------------------------------------------------
    def creatSetDataTypeDeclaration(self):
        """发送数据类型声明"""
        comments = ('/***********************************************************\n')
        comments += ('* get set 数据类型定义\n')
        comments += ('* 一般只定义set数据，get类型引用当前头文件\n')
        comments += ('* 只需要把发送的数据定义出来，收发接口使用的是统一接口，无其他定义\n')
        comments += ('* 信号数据类型一般来说都得强制定义一遍，否则很难知道信号对应数据是什么\n')
        comments += ('***********************************************************/\n')
        comments += ('/*发送数据类型\n')
        comments += ('***********************************************/\n')
        return comments
    
    def creatServDataTypeDeclaration(self):
        """服务数据类型声明"""
        comments = ('/***********************************************************\n')
        comments += ('* serv trig 数据类型定义\n')
        comments += ('* 一般只定义serv数据，trig类型引用当前头文件\n')
        comments += ('* 只需要把发送的数据定义出来，收发接口使用的是统一接口，无其他定义\n')
        comments += ('* 信号数据类型一般来说都得强制定义一遍，否则很难知道信号对应数据是什么\n')
        comments += ('***********************************************************/\n')
        comments += ('/*服务数据类型\n')
        comments += ('***********************************************/\n')
        return comments
    
    def creatServTrigInterfaceDeclaration(self):
        """服务触信号接口声明"""
        comments = ('/***********************************************************\n')
        comments += ('* serv trig 信号接口定义\n')
        comments += ('* 类继承的接口就是触发信号接口，在接口函数中使用触发信号进行触发\n')
        comments += ('***********************************************************/\n')
        comments += ('/*组件初始化服务\n')
        comments += ('***********************************************/\n')
        comments += ('void serv_%s_init(void);\n' %self.__fileName)
        for func in self.__func_list:
            comments += ('/*服务\n')
            comments += ('***********************************************/\n')
            comments += ('void serv_%s_%s(void);\n' %(self.__fileName,func))
        comments += ('\n')
        comments += ('/*接口触发\n')
        comments += ('***********************************************/\n')
        comments += ('//void trig_%s_inf_infFunc(void);\n' %self.__fileName)
        return comments
    
    def creatSetGetSigsListDefination(self):
        """发送接收信号列表"""
        maxLen = len('#define SIGNAL_SET_LIST_RTEASYN_%s(_)' %self.__fileName.upper())
        if(maxLen > 60):
            maxLen = maxLen + 1
        else:
            maxLen = 60
        comments = ('/***********************************************************\n')
        comments += ('* get set信号列表\n')
        comments += ('***********************************************************/\n')
        comments += ('/*发送信号列表\n')
        comments += ('***********************************************/\n')
        alignSpaceAmount = maxLen - len('#define SIGNAL_SET_LIST_RTEASYN_%s(_)' %self.__fileName.upper())
        alignSpace = alignSpaceAmount * ' '
        comments += ('#define SIGNAL_SET_LIST_RTEASYN_%s(_)' %self.__fileName.upper())
        comments += alignSpace+'\\\n'
        comments += '\n'
        
        maxLen = len('#define SIGNAL_GET_MAP_LIST_RTEASYN_%s(_)' %self.__fileName.upper())
        if(maxLen > 60):
            maxLen = maxLen + 1
        else:
            maxLen = 60
        comments += ('/*接收信号列表\n')
        comments += ('* 配置信号时需要检查发送信号的长度对信号进行映射\n')
        comments += ('***********************************************/\n')
        alignSpaceAmount = maxLen - len('#define SIGNAL_GET_MAP_LIST_RTEASYN_%s(_)' %self.__fileName.upper())
        alignSpace = alignSpaceAmount * ' '
        comments += ('#define SIGNAL_GET_MAP_LIST_RTEASYN_%s(_)' %self.__fileName.upper())
        comments += alignSpace+'\\\n'
        return comments
    
    def creatServTrigSigsListDefination(self):
        """服务触发信号列表"""
        maxLen = len('#define SIGNAL_SERV_LIST_RTESYN_%s(_)' %self.__fileName.upper())
        sig_len = len('    _(sig_serv_%s_init,serv_%s_init)' %(self.__fileName,self.__fileName))
        if(sig_len > maxLen):
            maxLen = sig_len
        for func in self.__func_list:
            sig_len = len('    _(sig_serv_%s_%s,serv_%s_%s)' %(self.__fileName,func,self.__fileName,func))
            if(sig_len > maxLen):
                maxLen = sig_len
        if(maxLen > 60):
            maxLen = maxLen + 1
        else:
            maxLen = 60
        comments = ('/***********************************************************\n')
        comments += ('* trig serv信号列表\n')
        comments += ('***********************************************************/\n')
        comments += ('/*服务信号列表\n')
        comments += ('***********************************************/\n')
        alignSpaceAmount = maxLen - len('#define SIGNAL_SERV_LIST_RTESYN_%s(_)' %self.__fileName.upper())
        alignSpace = alignSpaceAmount * ' '
        comments += ('#define SIGNAL_SERV_LIST_RTESYN_%s(_)' %self.__fileName.upper())
        comments += alignSpace+'\\\n'
        alignSpaceAmount = maxLen - len('    _(sig_serv_%s_init,serv_%s_init)' %(self.__fileName,self.__fileName))
        alignSpace = alignSpaceAmount * ' '
        comments += ('    _(sig_serv_%s_init,serv_%s_init)' %(self.__fileName,self.__fileName))
        comments += alignSpace+'\\\n'
        for func in self.__func_list:
            alignSpaceAmount = maxLen - len('    _(sig_serv_%s_%s,serv_%s_%s)' %(self.__fileName,func,self.__fileName,func))
            alignSpace = alignSpaceAmount * ' '
            comments += ('    _(sig_serv_%s_%s,serv_%s_%s)' %(self.__fileName,func,self.__fileName,func))
            comments += alignSpace+'\\\n'
        comments += '\n'
        
        maxLen = len('#define SIGNAL_TRIG_MAP_LIST_RTESYN%s(_)' %self.__fileName.upper())
        if(maxLen > 60):
            maxLen = maxLen + 1
        else:
            maxLen = 60
        comments += ('/*触发信号列表\n')
        comments += ('* 配置信号时需要检查服务信号的长度对信号进行映射\n')
        comments += ('***********************************************/\n')
        alignSpaceAmount = maxLen - len('#define SIGNAL_TRIG_MAP_LIST_RTESYN%s(_)' %self.__fileName.upper())
        alignSpace = alignSpaceAmount * ' '
        comments += ('#define SIGNAL_TRIG_MAP_LIST_RTESYN%s(_)' %self.__fileName.upper())
        comments += alignSpace+'\\\n'
        return comments
    
    def creatTaskCpnDeclaration(self):
        """组件运行任务"""
        comments = ('/***********************************************************\n')
        comments += ('* 组件运行任务\n')
        comments += ('***********************************************************/\n')
        comments += ('/*运行任务声明\n')
        comments += ('***********************************************/\n')
        comments += ('void task%s(void);\n' %self.__fileName)
        return comments
    
    def creatCpnClassDefination(self):
        """组件类定义"""
        comments = ('/***********************************************************\n')
        comments += ('* %s类定义\n' %self.__fileName)
        comments += ('***********************************************************/\n')
        comments += ('/*%s类\n' %self.__fileName)
        comments += ('***********************************************/\n')
        comments += ('%s cl%s;' %(self.__fileName,self.__fileName))
        return comments
    
    def creatServTrigInterfaceDefination(self):
        """服务触信号接口声明"""
        comments = ('/***********************************************************\n')
        comments += ('* serv trig 信号接口定义\n')
        comments += ('* 类继承的接口就是触发信号接口，在接口函数中使用触发信号进行触发\n')
        comments += ('***********************************************************/\n')
        comments += ('/*组件初始化服务\n')
        comments += ('***********************************************/\n')
        comments += ('void serv_%s_init(void){\n' %self.__fileName)
        comments += ('    CN(%s,&cl%s);\n' %(self.__fileName,self.__fileName))
        comments += ('    if(OPRS(cl%s) != NULL){}\n' %self.__fileName)
        comments += ('}\n')
        comments += ('\n')
        for func in self.__func_list:
            comments += ('/*服务\n')
            comments += ('***********************************************/\n')
            comments += ('void serv_%s_%s(void){}\n' %(self.__fileName,func))
        comments += ('\n')
        comments += ('/*接口触发\n')
        comments += ('***********************************************/\n')
        comments += ('//void trig_%s_inf_infFunc(void){}\n' %self.__fileName)
        return comments
    #========================================================
    
    
    #========================================================
    # 模板生成源文件及头文件控制函数
    #--------------------------------------------------------
    def createSource(self):
        """生成源文件"""
        fh = open(self.__sourceName,mode = 'w',encoding=self.__encoding)
        self.__cTemp.fileComments2['Description'] = ': '+self.__fileName+'组件信号定义源文件'
        cm = self.__cTemp.generateFileHeadComment2(self.__sourceName)
        cm += ("/*头文件包含*/\n")
        if self.__filePath != '':
            refPath = '../'*len(self.__filePath.split('/'))
        else:
            refPath = './'
        cm += ("#include \"./%s\"\n" %self.__headerName) 
        cm += ('#include \"'+refPath+self.__RteSigsHeaderPath+'\"\n') 
        cm += ("\n"*1)
        cm += self.creatCpnClassDefination()
        cm += ("\n"*3)
        cm += self.creatServTrigInterfaceDefination()
        cm += ("\n"*1)
        cm += self.__cTemp.generateFileEndComment()
        fh.write(cm)
        fh.close()

    def createHeader(self):
        """生成头文件"""
        fh = open(self.__headerName,mode = 'w',encoding=self.__encoding)
        self.__cTemp.fileComments2['Description'] = ': '+self.__fileName+'组件信号声明头文件'
        cm = self.__cTemp.generateFileHeadComment2(self.__headerName)
        cm += "#ifndef %sSIGS_H_\n" %self.__fileName.upper()
        cm += "#define %sSIGS_H_\n" %self.__fileName.upper()
        cm += ("\n/*头文件包含*/\n")
        if self.__filePath != '':
            refPath = '../'*len(self.__filePath.split('/'))
        else:
            refPath = './'
        #cm += ('#include \"'+refPath+self.__StandTypeHeaderPath+'\"\n') 
        cm += ('#include \"'+refPath+self.__RteHeaderPath+'\"\n') 
        cm += ('\n'*1)
        cm += self.creatSetDataTypeDeclaration()
        cm += ('\n'*3)
        cm += self.creatServDataTypeDeclaration()
        cm += ('\n'*3)
        cm += self.creatServTrigInterfaceDeclaration()
        cm += ('\n'*3)
        cm += self.creatSetGetSigsListDefination()
        cm += ('\n'*3)
        cm += self.creatServTrigSigsListDefination()
        cm += ('\n'*3)
        cm += self.creatTaskCpnDeclaration()
        cm += ("\n"*1)
        cm += "#endif /*%sSIGS_H_*/\n\n" %self.__fileName.upper()
        cm += self.__cTemp.generateFileEndComment()
        fh.write(cm)
        fh.close()

    def createTemplate(self):
        """模板生成"""
        self.__cTemp.generateFilePath()
        self.__cTemp.createHeader()
        self.createSource()
        self.createHeader()
        self.__cTemp.backupOriginPath()
        
        #创建组件类
        self.__classTemp.createTemplate()
        
    #========================================================

if __name__ == '__main__':
    if len(sys.argv) <= 3:
        sys.stderr.write("please input no less than 4 parameter !!!")
    else:
        cpn = cpnTemplate(sys.argv)
        cpn.createTemplate()
        
        