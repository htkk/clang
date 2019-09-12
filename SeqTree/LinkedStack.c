#include "LinkedStack.h"

/** 初始化链栈 */
void InitLinkedStack(LinkedStack * linkedStack){
    linkedStack->top = NULL;
    linkedStack->length = 0;
}

/** 入栈 */
int Push(LinkedStack * linkedStack, TreeNode * node){
    StackNode * tempNode = (StackNode *)malloc(sizeof(StackNode));
    tempNode->data = node;
    tempNode->next = linkedStack->top;
    linkedStack->top = tempNode;
    linkedStack->length++;
    return 1;
}

/** 出栈 */
int Pop(LinkedStack * linkedStack, TreeNode ** node){
    StackNode * tmpNode;
    if(linkedStack->top == NULL || linkedStack->length == 0){
        return 0;
    }
    //返回栈中的数据域，重点，因为top要被释放，所以存为一个新指针
    *node = linkedStack->top->data;
    tmpNode = linkedStack->top;
    linkedStack->top = tmpNode->next;
    free(tmpNode);
    tmpNode = NULL;
    linkedStack->length--;
    return 1;
}

int IsLinkedStackEmpty(LinkedStack * linkedStack){
    if(linkedStack->top == NULL || linkedStack->length == 0){
        return 1;
    }
    return 0;
}
