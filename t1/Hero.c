#include "Hero.h";

Hero heros[5];
Job jobs[] = {
  {1,"战士","坦克"},
  {2,"法师","火力"},
  {3,"道士","辅助"},
};

/*
    int id;
    char * name;        //英雄名称
    char sex;           //性别
    Job job;            //职业
    double hp;          //生命值
    double speed;       //攻速
    Abillity abillity;  //特殊能力
    PubTime pubTime;    //上线时间
    */


void InputHero(){
    //动态录入
    int jobChoice;
    int i,j;
    for(i = 0; i < 3; i++){
        printf("请输入第%d位英雄的信息：", i + 1);
        heros[i].id = i + 1;
        printf("名称:");
        heros[i].name = (char*)malloc(30);
        scanf("%s",heros[i].name);
        fflush(stdin);
        printf("性别:");
        scanf("%c",&heros[i].sex);
        fflush(stdin);
        printf("请选择职业:\n");
        for(j = 0; j < 3 ; j++){
            printf("%d~%s\n",jobs[j].id,jobs[j].name);
        }
        scanf("%d", &jobChoice);
        heros[i].job = jobs[jobChoice - 1];
        printf("%s当前的职业：%s\n",heros[i].name,heros[i].job.name);

    }
}
