#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED

/*******************************************
 *  Project:
 *  Function: 实现非递归方式的二叉链表遍历的链栈结构
 *  Description:
 *  Author: 老K
 *******************************************
 *  Copyright 2019 by 老K
********************************************/
#include <stdio.h>
#include "TreeNode.h"

/** 栈节点 */
typedef struct StackNode{
    TreeNode * data;            //数据域
    struct StackNode * next;    //指针域
}StackNode;

typedef struct{
    StackNode * top;    //栈顶指针
    int length;         //栈长度
}LinkedStack;

/** 初始化链栈 */
void InitLinkedStack(LinkedStack * linkedStack);

/** 入栈 */
int Push(LinkedStack * linkedStack, TreeNode * node);

/** 出栈 */
int Pop(LinkedStack * linkedStack, TreeNode ** node);

int IsLinkedStackEmpty(LinkedStack * linkedStack);

#endif // LINKEDSTACK_H_INCLUDED
