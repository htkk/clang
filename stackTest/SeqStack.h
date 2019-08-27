#ifndef SEQSTACK_H_INCLUDED
#define SEQSTACK_H_INCLUDED

/*******************************************
 *  Project: 栈与队列示例
 *  Function: 定义顺序栈结构
 *  Description:
 *  Author: 老K
 *******************************************
 *  Copyright 2019 by 老K
********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Element.h"

/** 定义栈的顺序存储方式 */
typedef struct SeqStack {
    ElementType elements[MAX_SIZE];
    int top;
    int length;
}SeqStack;

/** 初始化栈 */
void InitSeqStack(SeqStack * seqStack);

/** 向栈中压入元素，返回压入的结果bool */
int PushSeqStack(SeqStack * seqStack, ElementType element);

/** 出栈，以指针方式返回元素，返回出栈的结果bool */
int PopSeqStack(SeqStack * seqStack, ElementType * element);

/** 清空栈 */
void ClearSeqStack(SeqStack * seqStack);

#endif // SEQSTACK_H_INCLUDED
