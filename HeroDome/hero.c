#include "hero.h"

Hero heros[] = {
    {"����",'m',"��ʦ",444,10,"��������",{2018,5,12}},
    {"����",'m',"��ʿ",555,20,"�ϵ���",{2017,3,6}},
    {"�ŷ�",'m',"սʿ",666,40,"��ͷ����",{2019,11,23}}
};

void Show(){
    int len = sizeof(heros) / sizeof(Hero);
    for(int i = 0; i < len; i++){
    printf("%s,%c,%s\t%d-%d-%d\n",heros[i].name,heros[i].sex,heros[i].job,heros[i].pubtime.year,heros[i].pubtime.month,heros[i].pubtime.day);
    }
}

