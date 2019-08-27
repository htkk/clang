#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct _job{
    int id;
    char * name;
    char * desc;

}Job;
typedef struct _abillity{
    int id;
    char * name;
    char * intro;
}Abillity;
typedef struct _pubTime{
    int year;
    int month;
    int day;
}PubTime;
typedef struct _hero{
    int id;
    char * name;        //英雄名称
    char sex;           //性别
    Job job;            //职业
    double hp;          //生命值
    double speed;       //攻速
    Abillity abillity;  //特殊能力
    PubTime pubTime;    //上线时间
}Hero;

void InputHero();
void ShowHero();

#endif // HERO_H_INCLUDED
