#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mall.h"

int propsCount = 0;
int playersCount = 0;

Prop *Props;
Player *Players;

/*��ʼ������*/
void Init(){
    static Prop propArray[] = {
        {1,"˫������",3000,10,"˫������1Сʱ"},
        {2,"���޴�",5000,10,"���һֻ����"},
        {3,"���鵤",2000,10,"�򿪻��99999999����"},
        {4,"õ�廨",10000,10,"�͸����Ի��1000�øж�"},
        {5,"����",1000,10,"����������"},
    };
    propsCount = sizeof(propArray) / sizeof(Prop);
    Props = propArray;

    static Player playerArray[] = {
        {1,"��ǽ�Ⱥ���","111",.gold=50000,.bag.max=10},
        {2,"Ұ��","111",.gold=150000,.bag.max=10},
        {3,"��������","111",.gold=2330000,.bag.max=10},
    };
    playersCount = sizeof(playerArray) / sizeof(Player);
    Players = playerArray;
}

/*�鿴�̳�*/
void ShowProps(){
    int i;
    if(Props == NULL) return;

    printf("%-5s%-14s%-14s%-8s%-20s\n","���","����","����","���","��Ʒ����");

    for(i = 0; i < propsCount; i++){
        printf("%-5d%-14s%-14.2f%-8d%-20s\n",Props[i].id,Props[i].name,Props[i].price,Props[i].stock,Props[i].desc);
    }

}

/*�鿴���*/
void ShowPlayers(){
    int i,j;
    if(Players == NULL) return;
    printf("%-5s%-14s%-12s%-8s\n","���","����","���","��������");
    for(i = 0; i < playersCount; i++){
        printf("%-5d%-14s%-12.2f%-8d\n----------\n����:\n%-14s%-5s\n",Players[i].id,Players[i].name,Players[i].gold,Players[i].bag.count,"��������","����");
        for(j = 0; j < Players[i].bag.count ; j++){
            printf("%-14s%-5d\n",Players[i].bag.props[j].name,Players[i].bag.props[j].stock);
        }
        printf("----------\n");

    }
}

/*���׺���*/
void Trade(Player *player, int propId){
    int i;
    int newIndex = player->bag.count;//������Ʒ����
    Prop *tradeProp = NULL;          //������Ʒָ��
    for(i = 0; i < propsCount; i++){    //�ж���Ʒ�Ƿ����
        if(propId == Props[i].id){
            tradeProp = &Props[i];
            break;
        }
    }
    //�ж���Ʒ���
    if(tradeProp->stock <= 0){
        printf("��Ʒ�Ѹ���������\n");
        return;
    }
    //�ж���ҽ���Ƿ����
    if(player->gold < tradeProp->price){
        printf("����ֹ����\n");
        return;
    }
    //�ж���ұ����Ƿ�����
    if(newIndex >= player->bag.max && player->bag.count != 0){
        printf("���İ����ˣ���ȥ�����°�\n");
        return;
    }

    //��Ʒ���-1����ҽ������
    tradeProp->stock--;
    player->gold -= tradeProp->price;
    //�ж���ұ����Ƿ��и���Ʒ
    for(i = 0; i < newIndex; i++){
        if(player->bag.props[i].id == propId){
            player->bag.props[i].stock++;
            break;
        }
    }
    //û�и���Ʒ���ڱ�������
    if(i == newIndex){
        player->bag.props[newIndex].id = tradeProp->id;
        player->bag.props[newIndex].price = tradeProp->price;
        player->bag.props[newIndex].stock = 1;
        strcpy(player->bag.props[newIndex].name,tradeProp->name);
        strcpy(player->bag.props[newIndex].desc,tradeProp->desc);
        player->bag.count++;
    }
}
