#include "SequenceList.h"

/**
 * 初始化顺序表
*/

void InitList (SeqList * seqList, ElementType * elemArray, int length)
{
    if(length > MAX_SIZE)
    {
        printf("Length to big, init failed.");
        return;
    }
    seqList->length = 0;
    for(int i = 0; i < length; i++)
    {
        //每次循环都在下标为i的位置插入一个元素
        InsertElement(seqList, i, elemArray[i]);
        //printf("%s\n",elemArray[i].name);
    }

}

/**
 * 向顺序表中的index下标处插入某个元素
*/

void InsertElement (SeqList * seqList, int index, ElementType element)
{
    //检查数组长度
    if(seqList->length + 1 >= MAX_SIZE)
    {
        printf("Array is fill, insert element failed!\n");
        return;
    }

    //检查index是否超出数组长度范围
    if(index < 0 || index >= MAX_SIZE)
    {
        printf("Your index error, Please enter index [0, %d]\n", MAX_SIZE - 1);
        return;
    }
    //检查index是否大于length
    if(index > seqList->length)
    {
        printf("Index big for length!\n");
        return;
    }

    //printf("%d\t%d\n", seqList->length, index);
    for(int i = seqList->length - 1; i >= index; i--)
    {
        seqList->datas[i + 1] = seqList->datas[i];
        //printf("%s\n", seqList->datas[i+1].name);
    }
    //插入元素
    seqList->datas[index] = element;
    //printf("%s\n", seqList->datas[index].name);
    //length+1
    seqList->length++;
}

/**
 * 删除顺序表中指定下标的元素
*/

ElementType * DeleteElement(SeqList * seqList, int index)
{
    //检查index是否超出数组长度范围
    if(index < 0 || index >= MAX_SIZE)
    {
        printf("Your index error, Please enter index [0, %d]\n", MAX_SIZE - 1);
        return NULL;
    }

    //1、找到要删除的元素，并保存起来以便返回
    //给element分配内存空间，以便保存指针的值
    ElementType * element = (ElementType*)malloc(sizeof(ElementType));
    *element = *GetElement(seqList, index);

    //2、从指定位置删除，后面一个元素赋值给前面一个元素
    for(int i = index; i < seqList->length - 1; i++)
    {
        seqList->datas[i] = seqList->datas[i + 1];
    }

    //3、顺序表总长度-1
    seqList->length--;

    //该指针使用完成后一定要进行free操作！！！
    return element;
}

/**
 * 查找顺序表中指定下标的元素
*/

ElementType * GetElement(SeqList * seqList, int index)
{
    //检查index是否超出数组长度范围
    if(index < 0 || index >= MAX_SIZE)
    {
        printf("Your index error, Please enter index [0, %d]\n", MAX_SIZE - 1);
        return NULL;
    }

    //要查找的元素
    ElementType * element;
    element = &seqList->datas[index];
    return element;
}

void PrintList(SeqList * seqList)
{
    for(int i = 0; i < seqList->length; i++){
        printf("%d\t%s\n", seqList->datas[i].id, seqList->datas[i].name);
    }
}
