#include "LinkList.h"

/** 初始化链表 */
void InitLinkList(LinkList * linklist, ElementType * dataArray, int length)
{
    for(int i = 0; i < length; i++){
        InsertLinkList(linklist, i + 1, dataArray[i]);
    }
}

/**
 * 在指定的位置插入元素element
 */
void InsertLinkList(LinkList * linklist, int pos, ElementType element)
{
    //1、创建空节点并为数据域赋值
    Node * node = (Node *)malloc(sizeof(Node));
    node->data = element;
    node->next = NULL;

    //2、找到要插入位置的节点
    if(pos == 1){//如果插入的是第一个元素，执行以下操作
        linklist->next = node;
        linklist->length++;
        return;
    }
    //通过循环找到要插入的节点位置
    Node * currNode = linklist->next;
    for(int i = 1; currNode && i < pos - 1; i++){
        currNode = currNode->next;
    }
    //3、将节点插入并对接前面的节点
    if(currNode){
        node->next = currNode->next;
        currNode->next = node;
        linklist->length++;
    }
}

/** 删除并返回指定位置的元素*/
ElementType DeleteLinkListElement(LinkList * linkLIst, int pos)
{
    ElementType element;    //被删除的元素
    element.id = -999;      //赋一个不可能的值，用来判断是否删除成功
    Node * node = NULL;     //存放当前节点
    //如果pos在第一个位置，把next赋值给头节点，并释放node内存
    if(pos == 1){
        node = linkLIst->next;
        if(node){
            element = node->data;
            linkLIst->next = node->next;
            free(node);
            linkLIst->length--;
        }
        return element;
    }
    //1、找到要删除节点和它的前缀节点
    //2、要删除节点next赋值给前缀节点next
    //3、释放要删除的节点内存
    Node * preNode; //前缀节点
    node = linkLIst->next;
    for(int i = 1; node && i < pos; i++){
        preNode = node;
        node = node->next;
    }
    if(node){
        element = node->data;
        preNode->next = node->next;
        free(node);
        linkLIst->length--;
    }
}

/** 清空链表 */
void ClearLinkList(LinkList * linkList)
{
    Node * node = linkList->next;
    Node * nextNode;
    while(node){
        nextNode = node->next;
        free(node);
        node = nextNode;
    }
    linkList->next = NULL;
    linkList->length = 0;
}

/** 返回pos位置的元素 */
ElementType GetLinkListElement(LinkList * linkList, int pos)
{
    Node * node = linkList->next;
    for(int i = 1; node && i < pos; i++){
        node = node->next;
    }
    return node->data;
}

void PrintLinkList(LinkList * linkList)
{
    Node * node = linkList->next;
    if(!node){
        printf("LinkList is NULL!\n");
        linkList->length = 0;
        return;
    }
    for(int i = 0; i < linkList->length; i++){
        printf("%d\t%s\n", node->data.id, node->data.name);
        node = node->next;
    }
}

int IsLinkListEmpty(LinkList * linkList)
{
    return linkList->length == 0 ? TRUE : FALSE;
}
