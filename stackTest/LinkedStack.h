#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED

/*******************************************
 *  Project: 链栈示例
 *  Function: 定义链栈数据结构及常用操作
 *  Description:
 *  Author: 老K
 *******************************************
 *  Copyright 2019 by 老K
********************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Element.h"

/** 链栈的节点 */
typedef struct StackNode {
    ChessMan data;           //节点中保存的元素
    struct StackNode * next;    //指向下个节点的指针
}StackNode;

/** 链栈结构 */
typedef struct LinkedStack {
    StackNode * top;            //栈顶指针
    int length;                 //链栈长度
}LinkedStack;

/** 初始化链栈 */
void InitLinkedStack(LinkedStack * linkedStack);

/** 将元素压入链栈 */
int PushLinkedStack(LinkedStack * linkedStack, ChessMan element);

/** 出栈操作 */
int PopLinkedStack(LinkedStack * linkedStack, ChessMan * element);

/** 清空栈 */
void ClearLinkStack(LinkedStack * linkedStack);

/** 销毁栈 */
void DestroyLinkStack(LinkedStack * linkedStack);

#endif // LINKEDSTACK_H_INCLUDED
