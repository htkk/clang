#include "Hero.h";

Hero heros[5];
Job jobs[] = {
  {1,"սʿ","̹��"},
  {2,"��ʦ","����"},
  {3,"��ʿ","����"},
};

/*
    int id;
    char * name;        //Ӣ������
    char sex;           //�Ա�
    Job job;            //ְҵ
    double hp;          //����ֵ
    double speed;       //����
    Abillity abillity;  //��������
    PubTime pubTime;    //����ʱ��
    */


void InputHero(){
    //��̬¼��
    int jobChoice;
    int i,j;
    for(i = 0; i < 3; i++){
        printf("�������%dλӢ�۵���Ϣ��", i + 1);
        heros[i].id = i + 1;
        printf("����:");
        heros[i].name = (char*)malloc(30);
        scanf("%s",heros[i].name);
        fflush(stdin);
        printf("�Ա�:");
        scanf("%c",&heros[i].sex);
        fflush(stdin);
        printf("��ѡ��ְҵ:\n");
        for(j = 0; j < 3 ; j++){
            printf("%d~%s\n",jobs[j].id,jobs[j].name);
        }
        scanf("%d", &jobChoice);
        heros[i].job = jobs[jobChoice - 1];
        printf("%s��ǰ��ְҵ��%s\n",heros[i].name,heros[i].job.name);

    }
}
