#include "SeqStack.h"

/** 初始化栈 */
void InitSeqStack(SeqStack * seqStack){
    //栈顶指向-1的下标
    seqStack->top = -1;
    //给length赋初值，十分重要！！！！
    seqStack->length = 0;
}

/** 向栈中压入元素，返回压入的结果bool */
int PushSeqStack(SeqStack * seqStack, ElementType element){
    //如果栈满，则返回
    if(seqStack->top >= MAX_SIZE - 1) {
        seqStack->top = MAX_SIZE - 1;
        printf("This stack is fill.\n");
        return FALSE;
    }
    //栈顶指针加1，以便加入新元素
    seqStack->top++;
    //将新插入的元素赋值给栈顶
    seqStack->elements[seqStack->top] = element;
    seqStack->length++;
    return TRUE;
}

/** 出栈，以指针方式返回元素，返回出栈的结果bool */
int PopSeqStack(SeqStack * seqStack, ElementType * element) {
    //判断栈是否为空
    if(seqStack->top <= -1) {
        element = NULL;
        printf("Stack is empty, pop stack fail.\n");
        return FALSE;
    }
    //返回栈顶指向的元素
    *element = seqStack->elements[seqStack->top];
    seqStack->top--;
    seqStack->length--;
    return TRUE;
}

/** 清空栈 */
void ClearSeqStack(SeqStack * seqStack) {
    seqStack->top = -1;
    seqStack->length = 0;
}
