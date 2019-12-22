
typedef unsigned char   uint8;
typedef unsigned short  uint16;

//信号定义
#define SIGNAL_SET_DEFINE(signal_set,len)                       signal_set,                                             //发送信号名称定义
#define SIGNAL_GET_DEFINE(signal_get,len)                       signal_get,                                             //接收信号名称定义
#define SIGNAL_SET_LEN_DEFINE(signal_set,len)                   signal_set##Len = len,                                  //发送信号长度定义
#define SIGNAL_GET_INDEX_MAP_DEFINE(signal_get,signal_set)      signal_get##Map = signal_set,                           //接收信号进行映射
#define SIGNAL_SET_LEN_ADD_DEFINE(signal_set,len)               +signal_set##Len                                        //发送信号长度叠加
#define SIGNAL_SET_REGISTER(name,signal_set,len)                if(signal_set){name##SigSetIndex[signal_set] = (signal_set##Len+name##SigSetIndex[signal_set-1]);}\
                                                                else{name##SigSetIndex[signal_set] = signal_set##Len;}  //发送信号对应长度数组进行注册
#define SIGNAL_GET_REGISTER(name,signal_get,len)                name##SigGetIndex[signal_get] = signal_get##Map;        //接收信号对应长度数组进行注册

//------------------------------------------------------------------------------------------
//建立发送信号索引编号
#define SIGNAL_SET_ENUM(name,list_set) \
enum name##SigSet{\
    list_set(SIGNAL_SET_DEFINE)\
    name##SigSetMax \
};\
extern uint16 name##SigSetIndex[name##SigSetMax]
//建立发送信号对应长度
#define SIGNAL_SET_LEN_MAX(name,list_set)         (0 list_set(SIGNAL_SET_LEN_ADD_DEFINE))
#define SIGNAL_SET_LEN_ENUM(name,list_set) \
enum name##SigSetLen{\
    list_set(SIGNAL_SET_LEN_DEFINE)\
    name##SigSetMaxLen \
};\
extern uint8 name##SigSetBuff[SIGNAL_SET_LEN_MAX(name,list_set)]

//发送信号映射关系
#define SIGNAL_SET_MAP(name,list_set)      \
SIGNAL_SET_ENUM(name,list_set);            \
SIGNAL_SET_LEN_ENUM(name,list_set)

//发送信号存储定义
#define BUFF_SET_DEFINE(name,list_set)      \
uint16 name##SigSetIndex[name##SigSetMax];            \
uint8 name##SigSetBuff[SIGNAL_SET_LEN_MAX(name,list_set)]

//------------------------------------------------------------------------------------------
//建立接收信号索引编号
#define SIGNAL_GET_MAP_ENUM(name,list_get) \
enum name##SigGet{\
    list_get(SIGNAL_GET_DEFINE)\
    name##SigGetMax \
};\
extern uint16 name##SigGetIndex[name##SigGetMax]
//建立接收信号对应长度
#define SIGNAL_GET_INDEX_MAP_ENUM(name,list_get) \
enum name##SigGetMap{\
    list_get(SIGNAL_GET_INDEX_MAP_DEFINE)\
    name##SigGetMapMax \
};\

//接收信号映射关系
#define SIGNAL_GET_MAP(name,list_get)      \
SIGNAL_GET_MAP_ENUM(name,list_get);          \
SIGNAL_GET_INDEX_MAP_ENUM(name,list_get)

//接收信号存储定义
#define BUFF_GET_DEFINE(name,list_get)      \
uint16 name##SigGetIndex[name##SigGetMax]

//------------------------------------------------------------------------------------------
//信号进行注册
#define SIGNALS_REGISTER(list,signal_register)  do{\
        list(signal_register)\
    }while(0)

//信号建立映射
#define SIGNAL_SET_GET_MAP(name,list_set,list_get)      \
SIGNAL_SET_MAP(name,list_set);                     \
SIGNAL_GET_MAP(name,list_get)

//信号存储定义
#define BUFF_SET_GET_DEFINE(name,list_set,list_get)      \
BUFF_SET_DEFINE(name,list_set);                          \
BUFF_GET_DEFINE(name,list_get)

//------------------------------------------------------------------------------------------
// //建立发送信号列表
// #define SIGNAL_SET_LIST(_)     \
//     _(cpn1_send1,1)        \
//     _(cpn1_send2,5) 

// //定义需要注册的发送信号
// #define ASYN_SET_SIGNAL_REGISTER(signal_set,len)    SIGNAL_SET_REGISTER(RteAsyn,signal_set,len)

// //建立发送信号映射
// SIGNAL_SET_MAP(RteAsyn,SIGNAL_SET_LIST);

// //定义发送信号缓存
// BUFF_SET_DEFINE(RteAsyn,SIGNAL_SET_LIST);



//------------------------------------------------------------------------------------------
// //建立接收信号列表
// #define SIGNAL_GET_MAP_LIST(_)         \
//     _(cpn2_receive1,cpn1_send2)        \
//     _(cpn2_receive2,cpn1_send1) 

// //定义需要注册的接收信号
// #define ASYN_GET_SIGNAL_REGISTER(signal_get,len)    SIGNAL_GET_REGISTER(RteAsyn,signal_get,len)

// //建立接收信号映射
// SIGNAL_GET_MAP(RteAsyn,SIGNAL_GET_MAP_LIST);

// //定义接收信号缓存
// BUFF_GET_DEFINE(RteAsyn,SIGNAL_GET_MAP_LIST);




//------------------------------------------------------------------------------------------
//建立发送信号列表
#define SIGNAL_SET_LIST(_)     \
    _(cpn1_send1,1)        \
    _(cpn1_send2,5) 

//建立接收信号列表进行映射
#define SIGNAL_GET_MAP_LIST(_)         \
    _(cpn2_receive1,cpn1_send2)        \
    _(cpn2_receive2,cpn1_send1) 


//定义需要注册的收发信号
#define ASYN_SET_SIGNAL_REGISTER(signal_set,len)    SIGNAL_SET_REGISTER(RteAsyn,signal_set,len)
#define ASYN_GET_SIGNAL_REGISTER(signal_get,len)    SIGNAL_GET_REGISTER(RteAsyn,signal_get,len)





//建立收发信号映射
SIGNAL_SET_GET_MAP(RteAsyn,SIGNAL_SET_LIST,SIGNAL_GET_MAP_LIST);

//定义收发信号缓存
BUFF_SET_GET_DEFINE(RteAsyn,SIGNAL_SET_LIST,SIGNAL_GET_MAP_LIST);



void test(void)
{
    SIGNALS_REGISTER(SIGNAL_SET_LIST,ASYN_SET_SIGNAL_REGISTER);
    SIGNALS_REGISTER(SIGNAL_GET_MAP_LIST,ASYN_GET_SIGNAL_REGISTER);
}
















