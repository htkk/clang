#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED

typedef struct _myTime{
    int year;
    int month;
    int day;
}MyTime;

typedef struct _hero{
    char name[50];  //名称
    char sex;       //性别
    char job[20];   //职业
    int life;       //生命值
    double speed;   //攻速
    char abillity[30];  //特殊能力
    MyTime pubtime; //上线时间
}Hero;

void Show();    //显示详细信息

#endif // HERO_H_INCLUDED
