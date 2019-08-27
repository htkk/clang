#ifndef SEQUENCELIST_H_INCLUDED
#define SEQUENCELIST_H_INCLUDED

/*******************************************
 *  Project: 数据结构之线性表
 *  Function: 定义顺序表
 *  Description:
 *  Author: 老K
 *******************************************
 *  Copyright 2019 by 老K
********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

/**
 * 初始化顺序表
 * @param seqList  要初始化的顺序表
 * @param elemArray  初始化时要添加的元素内容数组
 * @param length    初始化时要添加的元素个数
*/

void InitList (SeqList * seqList, ElementType * elemArray, int length);

/**
 * 向顺序表中的index下标处插入某个元素
 * @param seqList  顺序表
 * @param index  要插入的下标
 * @param element    要插入的元素
*/

void InsertElement (SeqList * seqList, int index, ElementType element);

/**
 * 删除顺序表中指定下标的元素
 * @param seqList  顺序表
 * @param index  要插入的下标
 * @return 返回删除元素的指针，如果删除失败，返回NULL
*/

ElementType * DeleteElement(SeqList * seqList, int index);

/**
 * 查找顺序表中指定下标的元素
 * @param seqList  顺序表
 * @param index  要插入的下标
 * @return 返回指定下标的元素，如果查找失败，返回NULL，该指针使用完成后一定要进行free操作！！！
*/

ElementType * GetElement(SeqList * seqList, int index);

//打印列表
void PrintList(SeqList * seqList);

#endif // SEQUENCELIST_H_INCLUDED
