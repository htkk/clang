#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED

typedef struct _myTime{
    int year;
    int month;
    int day;
}MyTime;

typedef struct _hero{
    char name[50];  //����
    char sex;       //�Ա�
    char job[20];   //ְҵ
    int life;       //����ֵ
    double speed;   //����
    char abillity[30];  //��������
    MyTime pubtime; //����ʱ��
}Hero;

void Show();    //��ʾ��ϸ��Ϣ

#endif // HERO_H_INCLUDED
