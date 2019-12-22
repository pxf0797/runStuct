
typedef unsigned char   uint8;
typedef unsigned short  uint16;

//�źŶ���
#define SIGNAL_SET_DEFINE(signal_set,len)             signal_set,                                  //�ź����ƶ���
#define SIGNAL_SET_LEN_DEFINE(signal_set,len)         signal_set##Len = len,                      //�źų��ȶ���
#define SIGNAL_SET_LEN_ADD_DEFINE(signal_set,len)     +signal_set##Len                            //�źų��ȵ���
#define SIGNAL_SET_REGISTER(name,signal_set,len)      name##SigGetIndex[signal_set] = signal_set##Len;             //�źŶ�Ӧ�����������ע��

//�����ź��������
#define SIGNAL_SET_ENUM(name,list) \
enum name##Sig{\
    list(SIGNAL_SET_DEFINE)\
    name##SigSetMax \
};\
extern uint16 name##SigGetIndex[name##SigSetMax]
//�����źŶ�Ӧ����
#define SIGNAL_LEN_MAX(name,list)         (0 list(SIGNAL_SET_LEN_ADD_DEFINE))
#define SIGNAL_LEN_ENUM(name,list) \
enum name##SigLen{\
    list(SIGNAL_SET_LEN_DEFINE)\
    name##SigMaxLen \
};\
extern uint8 name##SigBuff[SIGNAL_LEN_MAX(name,list)]


//�ź�ӳ���ϵ
#define SIGNAL_SET_MAP(name,list)      \
SIGNAL_SET_ENUM(name,list);            \
SIGNAL_LEN_ENUM(name,list)

//�źŴ洢����
#define BUFF_SET_DEFINE(name,list)      \
uint16 name##SigGetIndex[name##SigSetMax];            \
uint8 name##SigBuff[SIGNAL_LEN_MAX(name,list)]
//�źŽ���ע��
#define SIGNALS_REGISTER(list,signal_register)  do{\
        list(signal_register);\
    }while(0)



// //ע���ź�
// #define ASYN_SIGNAL_REGISTER(signal_set,len)    SIGNAL_SET_REGISTER(RteAsyn,signal_set,len)
// #define ASYN_SIGNALS_REGISTER(list)  do{\
//         list(ASYN_SIGNAL_REGISTER);\
//     }while(0)


//�����ź��б�
#define SIGNAL_LIST(_)     \
    _(cpn1_send1,1)        \
    _(cpn1_send2,5) 

//������Ҫע����б�
#define A_SIGNAL_REGISTER(signal_set,len)    SIGNAL_SET_REGISTER(RteAsyn,signal_set,len)


// SIGNAL_SET_ENUM(RteAsyn,SIGNAL_LIST);
// SIGNAL_LEN_ENUM(RteAsyn,SIGNAL_LIST);
SIGNAL_SET_MAP(RteAsyn,SIGNAL_LIST);

BUFF_SET_DEFINE(RteAsyn,SIGNAL_LIST);


// void test(void)
// {
//     // ASYN_SIGNALS_REGISTER(SIGNAL_LIST);
//     SIGNALS_REGISTER(SIGNAL_LIST,A_SIGNAL_REGISTER);
// }


//��ȡ��ϵ����ӳ��

#define SIGNAL_GET_MAP_DEFINE(signal_get,signal_set)         signal_get##Len = signal_set##Len,  //�����źŽ���ӳ��
#define SIGNAL_GET_REGISTER(name,signal_get,len)            name##SigGetIndex[signal_get] = signal_get##Len;             //�źŶ�Ӧ�����������ע��



//�����ź��б�
#define SIGNAL_GET_MAP_LIST(_)         \
    _(cpn2_receive1,cpn1_send2)        \
    _(cpn2_receive2,cpn1_send1) 

//������Ҫע����б�
#define A_GET_SIGNAL_REGISTER(signal_get,len)    SIGNAL_GET_REGISTER(RteAsyn,signal_get,len)




#define SIGNAL_GET_MAP_ENUM(name,list) \
enum name##SigGet{\
    list(SIGNAL_GET_MAP_DEFINE)\
    name##SigGetMax \
};\
extern uint16 name##SigGetIndex[name##SigGetMax]



SIGNAL_GET_MAP_ENUM(RteAsyn,SIGNAL_GET_MAP_LIST);









void test(void)
{
    // ASYN_SIGNALS_REGISTER(SIGNAL_LIST);
    SIGNALS_REGISTER(SIGNAL_LIST,A_SIGNAL_REGISTER);

    SIGNALS_REGISTER(SIGNAL_GET_MAP_LIST,A_GET_SIGNAL_REGISTER);
}
















