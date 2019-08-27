#include "hero.h"

Hero heros[] = {
    {"刘备",'m',"法师",444,10,"唧唧歪歪",{2018,5,12}},
    {"关羽",'m',"道士",555,20,"拖刀计",{2017,3,6}},
    {"张飞",'m',"战士",666,40,"当头棒喝",{2019,11,23}}
};

void Show(){
    int len = sizeof(heros) / sizeof(Hero);
    for(int i = 0; i < len; i++){
    printf("%s,%c,%s\t%d-%d-%d\n",heros[i].name,heros[i].sex,heros[i].job,heros[i].pubtime.year,heros[i].pubtime.month,heros[i].pubtime.day);
    }
}

