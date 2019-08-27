#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataElement.h"
#include "LinkList.h"

ElementType dataArray[] = {
    {1, "扫地僧"},
    {2, "张三丰"},
    {3, "石破天"},
    {4, "乔峰"},
    {5, "段誉"}
};

void TestLinkList();

int main()
{
    TestLinkList();
    return 0;
}

void TestLinkList()
{
    LinkList linkList;
    linkList.length = 0;    //给长度赋默认值，容易忽略的地方
    InitLinkList(&linkList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
    PrintLinkList(&linkList);
    ElementType element;
    element.id = 234;
    element.name = (char *)malloc(10);
    strcpy(element.name, "东方不败");
    InsertLinkList(&linkList, 3, element);
    printf("After insert.\n");
    PrintLinkList(&linkList);
    printf("Get element name:%s\n",GetLinkListElement(&linkList, 4).name);
    printf("After delete element 2.\n");
    DeleteLinkListElement(&linkList, 2);
    PrintLinkList(&linkList);
    printf("Clear linklist:\n");
    ClearLinkList(&linkList);
    PrintLinkList(&linkList);
}
