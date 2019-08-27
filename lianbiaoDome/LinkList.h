#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

/*******************************************
 *  Project: 数据结构之链表
 *  Function: 链表抽象数据类型的定义和实现
 *  Description: 每个节点都有后继节点，链表的优点是存储空间利用高效
 *  Author: 老K
 *******************************************
 *  Copyright 2019 by 老K
********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

/** 定义链表的节点，包含数据域和指针域 */
typedef struct Node{
    ElementType data;   //数据域
    struct Node * next; //指针域，指向下个节点
}Node;

/**
 * 头节点
 * 注意：我们在定义链表时，习惯性的会定义头节点，以便统一链表节点的插入和删除操作
 * 头节点也可以称为首元节点，最后一个节点叫做尾元节点
*/
typedef struct LinkList{
    Node * next;    //头指针（如果链表有头节点，next就指向头节点，没有就指向第一个节点）
    int length;     //链表长度，初值为0
}LinkList;

/** 初始化链表 */
void InitLinkList(LinkList * linklist, ElementType * dataArray, int length);

/**
 * 在指定的位置插入元素element
 * @param 链表头节点
 * @param 位置
 * @param 要插入的元素
 */
void InsertLinkList(LinkList * linklist, int pos, ElementType element);

/** 返回pos位置的元素 */
ElementType GetLinkListElement(LinkList * linkList, int pos);

/** 删除并返回指定位置的元素*/
ElementType DeleteLinkListElement(LinkList * linkLIst, int pos);

/** 清空链表 */
void ClearLinkList(LinkList * linkList);

void PrintLinkList(LinkList * linkList);

int IsLinkListEmpty(LinkList * linkList);
#endif // LINKLIST_H_INCLUDED
