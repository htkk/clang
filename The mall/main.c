#include <stdio.h>
#include <stdlib.h>
#include "Mall.h"

extern Player *Players;
int main()
{
    Init();     //��ʼ����Ϸ����
    printf("\n*********����ǰ***********\n");
    ShowProps();
    ShowPlayers();
    Trade(&Players[1],2);
    Trade(&Players[1],3);
    Trade(&Players[1],4);
    printf("\n*********���׺�***********\n");
    ShowProps();
    ShowPlayers();

    return 0;
}
