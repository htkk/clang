#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

#define MAX 6
int main()
{
    int i, j, temp;
    int count = 5;
    int choice;           //选择
    int searchIndex = -1;
    char emperorName[10]; //名号
    char tempName[10];    //临时名
    char names[MAX][10] = {"飞燕","玉环","甄嬛","闵月","gaga"};
    char levelNames[5][10] = {"宫女","贵人","嫔妃","贵妃","皇后"};
    //对应妃子级别
    int levels[MAX] = {1,2,0,0,0,-1};
    //初始好感度
    int loves[MAX] = {100,100,100,100,100,-1};

    printf("查看状态\n");
    printf("%-8s级别\t好感度\n","姓名");
    for(i=0;i<count;i++)
    {
        printf("%-8s%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
    }

    printf("请输入名号:\n");
    scanf("%s",emperorName);
    printf("当前皇帝是%s\n",emperorName);
    printf("1、皇帝下旨选妃：\n");
    printf("2、翻牌:\n");
    printf("3、打入冷宫:\n");
    printf("4、单独召见:\n");
    printf("请选择:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        if(count < MAX)
        {
            //增加宫女
            printf("请输入名字：");
            scanf("%s",names[count]);
            levels[count] = 0;
            loves[count] = 100;
            count++;
        }
        else
        {
            printf("人满为患！\n");
        }
        break;
    case 2:
        printf("要翻谁的牌？\n");
        scanf("%s",tempName);
        for(i=0;i<count;i++)
        {
            if(strcmp(tempName,names[i])==0)
            {
                loves[i] += 10;
                //如果级别大于等于4赋值4，否则加1。
                levels[i] = levels[i] >=4 ? 4 : levels[i]+1;
            }
            else
            {
                loves[i] -= 10;
            }
        }
        break;
    case 3:
        printf("要把谁打入冷宫？\n");
        scanf("%s",tempName);
        for(i=0;i<count;i++)
        {
            if(strcmp(tempName,names[i])==0)
            {
                searchIndex = i;
                break;
            }
        }
        if(-1 == searchIndex)
        {
            printf("虚惊一场。\n");
        }
        else
        {
            for(i=searchIndex;i<count-1;i++)
            {
                //
                strcpy(names[i],names[i+1]);
                loves[i] = loves[i+1];
                levels[i] = levels[i+1];
            }
            count--;
        }
        break;
    case 4:
        printf("4、单独召见:\n");
        break;
    default:
        printf("君无戏言!\n");
    }

    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-i-1;j++)
        {
            if(levels[j]<levels[j+1])
            {
               temp = levels[j];
               levels[j] = levels[j+1];
               levels[j+1] = temp;
               temp = loves[j];
               loves[j] = loves[j+1];
               loves[j+1] = temp;
               strcpy(tempName,names[j]);
               strcpy(names[j],names[j+1]);
               strcpy(names[j+1],tempName);
            }
        }
    }

    printf("------------------------------------");
    printf("查看状态\n");
    printf("%-8s级别\t好感度\n","姓名");
    for(i=0;i<count;i++)
    {
        printf("%-8s%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
    }
    printf("------------------------------------");

    return 0;
}
