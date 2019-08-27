#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
/******************************************
 * 文件名：Game.h
 * 描  述：定义游戏的一些核心结构和函数
 * 创建人：
 * 日  期：2018-12-12
 * 版  本：0.1
******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/********************游戏的结构类型定义************************/
int X, Y;
//假设当前用户的坐标是3,2

//玩家、地图、装备、怪物

/* 地图结构 */
typedef struct _map{
    int id;         //编号
    char name[30];  //名称
    int minLevel;   //进入最小等级
    COORD coord;    //坐标,需调用windows.h
    char desc[400]; //介绍
}Map;
/* 游戏道具类型枚举：武器、道具、消耗品、卡片、碎片 */
typedef enum _proptype{
    Weapon, Armor, Con, Card, Frag
}PropType;
/* 游戏道具 */
typedef struct _prop{
   int id;              //编号
   char name[30];       //名称
   int leve;            //级别
   int stock;           //库存或背包里的叠加数量
   double price;        //价格
   PropType type;       //类型
   union{//联合-多选
        int minAttakc;     //武器对应攻击力
        int minDefence;    //防具对应防御力
        int minPower;      //消耗品对应能量
   };
   union{//联合-多选
        int maxAttakc;     //武器对应攻击力
        int maxDefence;    //防具对应防御力
        int maxPower;      //消耗品对应能量
   };
   char desc[100];      //功能描述
}Prop;

/*玩家属性*/
typedef struct _player{
    int id;
    char name[30];
    char pass[30];
    int life;       //生命值
    int level;      //级别
    int exp;        //经验值
    int hp;         //血量
    int mp;         //内力
    int mpMax;      //当前级别最大内力值
    int gold;       //金币数量
    //门派
    Prop Weapon;    //武器
    Prop Armor;     //防具
    COORD coord;    //坐标
    //背包
}Player;



void Init();    //初始化数据
void Show();    //显示数据

void ShowWelcome();     //显示欢迎信息
void ShowMap();         //显示地图
void ShowMapInfo();     //显示地图信息
void ShowInfomation();  //显示下方的游戏信息
void ShowMainMenu();    //显示主菜单
/*处理游戏主菜单*/
void ProcessMainMenu(char key);
/*在信息界面显示玩家个人资料*/
void ShowPlayerInfo();
#endif // GAME_H_INCLUDED
