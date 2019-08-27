#include <stdio.h>
#include <stdlib.h>
#include "Mall.h"

extern Player *Players;
int main()
{
    Init();     //初始化游戏数据
    printf("\n*********交易前***********\n");
    ShowProps();
    ShowPlayers();
    Trade(&Players[1],2);
    Trade(&Players[1],3);
    Trade(&Players[1],4);
    printf("\n*********交易后***********\n");
    ShowProps();
    ShowPlayers();

    return 0;
}
