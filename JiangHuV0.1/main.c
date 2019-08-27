#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Game.h"
#include "GameLib.h"


extern int X, Y;
int main()
{
    Init();
    int key;   //接收到的用户按键
    SetTitle("笑傲江湖 V0.1");
    SetColor(11 ,0);
    ShowWelcome();
    ShowMap();
    ShowInfomation();
    ShowMainMenu();
    /*
    while(1){
        fflush(stdin);
        key = getch();
        fflush(stdin);
        printf("%d\n",key);
    }*/

    while(1){
        fflush(stdin);
        key = getch();
        fflush(stdin);
        if(key == '1' || key == '2' || key == '3' || key == '4' || key == '5'){
            //printf("1-5之间的游戏菜单");
            ProcessMainMenu(key);//处理用户的菜单选项
            continue;
        }
        else if(key == 75){//左
            X--;
        }
        else if(key == 72){//上
            Y--;
        }
        else if(key == 77){//右
            X++;
        }
        else if(key == 80){//下
            Y++;
        }
        if(X > 7) X = 0;
        if(X < 0) X = 7;
        if(Y > 7) Y = 0;
        if(Y < 0) Y = 7;

        ShowMap();

    }
    return 0;
}
