#include "LinkedStack.h"

/** 初始化链栈 */
void InitLinkedStack(LinkedStack * linkedStack) {
    linkedStack->top = NULL;
    linkedStack->length = 0;
}

/** 将元素压入链栈 */
int PushLinkedStack(LinkedStack * linkedStack, ChessMan element) {
    //创建一个新节点
    StackNode * newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->data = element;
    //新节点的next指向当前栈顶
    newNode->next = linkedStack->top;
    linkedStack->top = newNode;
    linkedStack->length++;
    return TRUE;
}

/** 出栈操作 */
int PopLinkedStack(LinkedStack * linkedStack, ChessMan * element) {
    if(linkedStack->top == NULL) {
        printf("LinkStack is empty.\n");
        return FALSE;
    }
    //返回栈顶元素
    *element = linkedStack->top->data;
    //记录出栈操作前的栈顶元素
    StackNode * node = linkedStack->top;
    //栈顶指针下移一位
    linkedStack->top = linkedStack->top->next;
    //释放原栈顶空间
    free(node);
    linkedStack->length--;
    return TRUE;
}

/** 清空栈 */
void ClearLinkStack(LinkedStack * linkedStack) {
    StackNode * tempNode;
    while(linkedStack->top) {
        tempNode = linkedStack->top;
        linkedStack->top = linkedStack->top->next;
        free(tempNode);
        linkedStack->length--;
    }
}

/** 销毁栈 */
void DestroyLinkStack(LinkedStack * linkedStack) {
    ClearLinkStack(linkedStack);
    free(linkedStack);
    linkedStack = NULL;
}

