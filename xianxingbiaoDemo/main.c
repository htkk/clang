#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

ElementType dataArray[] = {
    {1, "扫地僧"},
    {2, "张三丰"},
    {3, "石破天"},
    {4, "乔峰"},
    {5, "段誉"}
};

void TestSeq();

int main()
{
    TestSeq();
    return 0;
}

void TestSeq()
{
    SeqList seqlist;
    ElementType tmp = {8, "游坦之"};
    ElementType * delElement;
    printf("%d\n",sizeof(dataArray) / sizeof(dataArray[0]));
    InitList(&seqlist, &dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
    InsertElement(&seqlist, 3, tmp);
    PrintList(&seqlist);
    printf("Use delete\n");
    delElement = DeleteElement(&seqlist, 2);
    PrintList(&seqlist);
    printf("Del element:%s\n", delElement->name);
    free(delElement);
}
