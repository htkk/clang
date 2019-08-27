#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mall.h"

int propsCount = 0;
int playersCount = 0;

Prop *Props;
Player *Players;

/*初始化参数*/
void Init(){
    static Prop propArray[] = {
        {1,"双倍经验",3000,10,"双倍经验1小时"},
        {2,"灵兽袋",5000,10,"获得一只宠物"},
        {3,"经验丹",2000,10,"打开获得99999999经验"},
        {4,"玫瑰花",10000,10,"送给异性获得1000好感度"},
        {5,"福袋",1000,10,"获得随机道具"},
    };
    propsCount = sizeof(propArray) / sizeof(Prop);
    Props = propArray;

    static Player playerArray[] = {
        {1,"骑墙等红杏","111",.gold=50000,.bag.max=10},
        {2,"野狼","111",.gold=150000,.bag.max=10},
        {3,"豆浆油条","111",.gold=2330000,.bag.max=10},
    };
    playersCount = sizeof(playerArray) / sizeof(Player);
    Players = playerArray;
}

/*查看商城*/
void ShowProps(){
    int i;
    if(Props == NULL) return;

    printf("%-5s%-14s%-14s%-8s%-20s\n","编号","名称","单价","库存","商品介绍");

    for(i = 0; i < propsCount; i++){
        printf("%-5d%-14s%-14.2f%-8d%-20s\n",Props[i].id,Props[i].name,Props[i].price,Props[i].stock,Props[i].desc);
    }

}

/*查看玩家*/
void ShowPlayers(){
    int i,j;
    if(Players == NULL) return;
    printf("%-5s%-14s%-12s%-8s\n","编号","名称","金币","道具数量");
    for(i = 0; i < playersCount; i++){
        printf("%-5d%-14s%-12.2f%-8d\n----------\n背包:\n%-14s%-5s\n",Players[i].id,Players[i].name,Players[i].gold,Players[i].bag.count,"道具名称","数量");
        for(j = 0; j < Players[i].bag.count ; j++){
            printf("%-14s%-5d\n",Players[i].bag.props[j].name,Players[i].bag.props[j].stock);
        }
        printf("----------\n");

    }
}

/*交易函数*/
void Trade(Player *player, int propId){
    int i;
    int newIndex = player->bag.count;//背包商品总数
    Prop *tradeProp = NULL;          //交易商品指针
    for(i = 0; i < propsCount; i++){    //判断商品是否存在
        if(propId == Props[i].id){
            tradeProp = &Props[i];
            break;
        }
    }
    //判断商品库存
    if(tradeProp->stock <= 0){
        printf("商品已告罄！！！\n");
        return;
    }
    //判断玩家金币是否充足
    if(player->gold < tradeProp->price){
        printf("穷人止步。\n");
        return;
    }
    //判断玩家背包是否已满
    if(newIndex >= player->bag.max && player->bag.count != 0){
        printf("您的包满了，快去清理下吧\n");
        return;
    }

    //商品库存-1，玩家金币消耗
    tradeProp->stock--;
    player->gold -= tradeProp->price;
    //判断玩家背包是否有该商品
    for(i = 0; i < newIndex; i++){
        if(player->bag.props[i].id == propId){
            player->bag.props[i].stock++;
            break;
        }
    }
    //没有该商品就在背包增加
    if(i == newIndex){
        player->bag.props[newIndex].id = tradeProp->id;
        player->bag.props[newIndex].price = tradeProp->price;
        player->bag.props[newIndex].stock = 1;
        strcpy(player->bag.props[newIndex].name,tradeProp->name);
        strcpy(player->bag.props[newIndex].desc,tradeProp->desc);
        player->bag.count++;
    }
}
