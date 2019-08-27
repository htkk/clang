#ifndef MALL_H_INCLUDED
#define MALL_H_INCLUDED


/*商城结构*/
typedef struct _prop{
    int id;             //编号
    char name[30];      //名称
    double price;       //单价
    int stock;          //库存量
    char desc[100];     //描述
}Prop;

/*玩家背包结构*/
typedef struct _bag{
    int playerId;   //玩家编号
    int count;      //道具数量
    int max;        //背包容量
    Prop props[10];     //道具数组
}Bag;

/*玩家结构*/
typedef struct _player{
    int id;          //编号
    char name[30];   //用户名
    char pass[30];   //密码
    Bag bag;        //玩家的背包
    double gold;    //金币数量
    double sysee;   //元宝数量
}Player;


void Init();

void ShowProps();

void ShowPlayers();

void Trade(Player *player, int propId);

#endif // MALL_H_INCLUDED
