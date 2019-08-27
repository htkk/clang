#include <stdio.h>
#include "hotel.h"

char hotelNames[4][20] = {
    "万豪酒店",
    "洲际酒店",
    "四季酒店",
    "葡京酒店",

};
int Menu(void){
    int choice, i, result;
    printf("请选择要入住的酒店：\n");
    for(i = 0; i < 4; i++){
        printf("%d~%s\n",i+1,hotelNames[i]);
    }

    printf("请输入您的选择：");
    while((result = scanf("%d",&choice)) != 1 || choice < 1 || choice > 4){
        if(result != 1){
            scanf("%*s");//终止上面执行的scanf
            fflush(stdin);//刷新缓冲区，清除缓存
        }
        printf("输入有误，请重新输入:");
    }
    return choice;
}

int GetNights(void){
    int days;
    printf("请输入要入住的天数：");
    while(scanf("%d",&days) != 1 || days < 1 || days > 365){
        fflush(stdin);
        printf("输入有误，请重新输入：");
    }
    return days;
}

void ShowPrice(int days, double price){
    double total = 0;
    for(int i = 0; i < days; i++){
        total += price;
        price = price * DISCOUNT;
    }
    printf("一共入住%d天，需要花费￥%.2lf元。\n", days, total);
}