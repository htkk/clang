#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{

    printf("%.5lf",ceil(33.0001));
    /*
    int money,temp = 0,i = 0,moneys[6],count = 0;
    char unit[10][4] = {"零","壹","贰","叁","肆","伍","陆","柒","捌","玖"};
    printf("请输入数字金额：\n");
    scanf("%d",&money);
    while(money != 0){
        moneys[i] = money % 10;
        money /= 10;
        i++;
        count++;
    }
    for(i=0;i<count/2;i++){
        temp = moneys[i];
        moneys[i] = moneys[count - i - 1];
        moneys[count - i - 1] = temp;
    }
    for(i=0;i<count;i++){
        printf("%d\t%s\n",moneys[i],unit[moneys[i]]);
    }
    */



    return 0;
}
