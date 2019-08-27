#ifndef MALL_H_INCLUDED
#define MALL_H_INCLUDED


/*�̳ǽṹ*/
typedef struct _prop{
    int id;             //���
    char name[30];      //����
    double price;       //����
    int stock;          //�����
    char desc[100];     //����
}Prop;

/*��ұ����ṹ*/
typedef struct _bag{
    int playerId;   //��ұ��
    int count;      //��������
    int max;        //��������
    Prop props[10];     //��������
}Bag;

/*��ҽṹ*/
typedef struct _player{
    int id;          //���
    char name[30];   //�û���
    char pass[30];   //����
    Bag bag;        //��ҵı���
    double gold;    //�������
    double sysee;   //Ԫ������
}Player;


void Init();

void ShowProps();

void ShowPlayers();

void Trade(Player *player, int propId);

#endif // MALL_H_INCLUDED
