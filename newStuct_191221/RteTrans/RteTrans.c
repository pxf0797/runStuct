
typedef unsigned char   uint8;
typedef unsigned short  uint16;

//�źŶ���
#define SIGNAL_SET_DEFINE(signal_set,len)                       signal_set,                                             //�����ź����ƶ���
#define SIGNAL_GET_DEFINE(signal_get,len)                       signal_get,                                             //�����ź����ƶ���
#define SIGNAL_SET_LEN_DEFINE(signal_set,len)                   signal_set##Len = len,                                  //�����źų��ȶ���
#define SIGNAL_GET_INDEX_MAP_DEFINE(signal_get,signal_set)      signal_get##Map = signal_set,                           //�����źŽ���ӳ��
#define SIGNAL_SET_LEN_ADD_DEFINE(signal_set,len)               +signal_set##Len                                        //�����źų��ȵ���
#define SIGNAL_SET_REGISTER(name,signal_set,len)                if(signal_set){name##SigSetIndex[signal_set] = (signal_set##Len+name##SigSetIndex[signal_set-1]);}\
                                                                else{name##SigSetIndex[signal_set] = signal_set##Len;}  //�����źŶ�Ӧ�����������ע��
#define SIGNAL_GET_REGISTER(name,signal_get,len)                name##SigGetIndex[signal_get] = signal_get##Map;        //�����źŶ�Ӧ�����������ע��

//------------------------------------------------------------------------------------------
//���������ź��������
#define SIGNAL_SET_ENUM(name,list_set) \
enum name##SigSet{\
    list_set(SIGNAL_SET_DEFINE)\
    name##SigSetMax \
};\
extern uint16 name##SigSetIndex[name##SigSetMax]
//���������źŶ�Ӧ����
#define SIGNAL_SET_LEN_MAX(name,list_set)         (0 list_set(SIGNAL_SET_LEN_ADD_DEFINE))
#define SIGNAL_SET_LEN_ENUM(name,list_set) \
enum name##SigSetLen{\
    list_set(SIGNAL_SET_LEN_DEFINE)\
    name##SigSetMaxLen \
};\
extern uint8 name##SigSetBuff[SIGNAL_SET_LEN_MAX(name,list_set)]

//�����ź�ӳ���ϵ
#define SIGNAL_SET_MAP(name,list_set)      \
SIGNAL_SET_ENUM(name,list_set);            \
SIGNAL_SET_LEN_ENUM(name,list_set)

//�����źŴ洢����
#define BUFF_SET_DEFINE(name,list_set)      \
uint16 name##SigSetIndex[name##SigSetMax];            \
uint8 name##SigSetBuff[SIGNAL_SET_LEN_MAX(name,list_set)]

//------------------------------------------------------------------------------------------
//���������ź��������
#define SIGNAL_GET_MAP_ENUM(name,list_get) \
enum name##SigGet{\
    list_get(SIGNAL_GET_DEFINE)\
    name##SigGetMax \
};\
extern uint16 name##SigGetIndex[name##SigGetMax]
//���������źŶ�Ӧ����
#define SIGNAL_GET_INDEX_MAP_ENUM(name,list_get) \
enum name##SigGetMap{\
    list_get(SIGNAL_GET_INDEX_MAP_DEFINE)\
    name##SigGetMapMax \
};\

//�����ź�ӳ���ϵ
#define SIGNAL_GET_MAP(name,list_get)      \
SIGNAL_GET_MAP_ENUM(name,list_get);          \
SIGNAL_GET_INDEX_MAP_ENUM(name,list_get)

//�����źŴ洢����
#define BUFF_GET_DEFINE(name,list_get)      \
uint16 name##SigGetIndex[name##SigGetMax]

//------------------------------------------------------------------------------------------
//�źŽ���ע��
#define SIGNALS_REGISTER(list,signal_register)  do{\
        list(signal_register)\
    }while(0)

//�źŽ���ӳ��
#define SIGNAL_SET_GET_MAP(name,list_set,list_get)      \
SIGNAL_SET_MAP(name,list_set);                     \
SIGNAL_GET_MAP(name,list_get)

//�źŴ洢����
#define BUFF_SET_GET_DEFINE(name,list_set,list_get)      \
BUFF_SET_DEFINE(name,list_set);                          \
BUFF_GET_DEFINE(name,list_get)

//------------------------------------------------------------------------------------------
// //���������ź��б�
// #define SIGNAL_SET_LIST(_)     \
//     _(cpn1_send1,1)        \
//     _(cpn1_send2,5) 

// //������Ҫע��ķ����ź�
// #define ASYN_SET_SIGNAL_REGISTER(signal_set,len)    SIGNAL_SET_REGISTER(RteAsyn,signal_set,len)

// //���������ź�ӳ��
// SIGNAL_SET_MAP(RteAsyn,SIGNAL_SET_LIST);

// //���巢���źŻ���
// BUFF_SET_DEFINE(RteAsyn,SIGNAL_SET_LIST);



//------------------------------------------------------------------------------------------
// //���������ź��б�
// #define SIGNAL_GET_MAP_LIST(_)         \
//     _(cpn2_receive1,cpn1_send2)        \
//     _(cpn2_receive2,cpn1_send1) 

// //������Ҫע��Ľ����ź�
// #define ASYN_GET_SIGNAL_REGISTER(signal_get,len)    SIGNAL_GET_REGISTER(RteAsyn,signal_get,len)

// //���������ź�ӳ��
// SIGNAL_GET_MAP(RteAsyn,SIGNAL_GET_MAP_LIST);

// //��������źŻ���
// BUFF_GET_DEFINE(RteAsyn,SIGNAL_GET_MAP_LIST);




//------------------------------------------------------------------------------------------
//���������ź��б�
#define SIGNAL_SET_LIST(_)     \
    _(cpn1_send1,1)        \
    _(cpn1_send2,5) 

//���������ź��б����ӳ��
#define SIGNAL_GET_MAP_LIST(_)         \
    _(cpn2_receive1,cpn1_send2)        \
    _(cpn2_receive2,cpn1_send1) 


//������Ҫע����շ��ź�
#define ASYN_SET_SIGNAL_REGISTER(signal_set,len)    SIGNAL_SET_REGISTER(RteAsyn,signal_set,len)
#define ASYN_GET_SIGNAL_REGISTER(signal_get,len)    SIGNAL_GET_REGISTER(RteAsyn,signal_get,len)





//�����շ��ź�ӳ��
SIGNAL_SET_GET_MAP(RteAsyn,SIGNAL_SET_LIST,SIGNAL_GET_MAP_LIST);

//�����շ��źŻ���
BUFF_SET_GET_DEFINE(RteAsyn,SIGNAL_SET_LIST,SIGNAL_GET_MAP_LIST);



void test(void)
{
    SIGNALS_REGISTER(SIGNAL_SET_LIST,ASYN_SET_SIGNAL_REGISTER);
    SIGNALS_REGISTER(SIGNAL_GET_MAP_LIST,ASYN_GET_SIGNAL_REGISTER);
}
















