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
    char * name;        //Ӣ������
    char sex;           //�Ա�
    Job job;            //ְҵ
    double hp;          //����ֵ
    double speed;       //����
    Abillity abillity;  //��������
    PubTime pubTime;    //����ʱ��
}Hero;

void InputHero();
void ShowHero();

#endif // HERO_H_INCLUDED
