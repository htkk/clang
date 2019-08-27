#include "SeqStack.h"
#include "Gobang.h"
#include "LinkedStack.h"


ElementType dataArray[] = {
    {1, "扫地僧"},
    {2, "张三丰"},
    {3, "石破天"},
    {4, "乔峰"},
    {5, "段誉"}
};

ChessMan chessArray[] = {
    {6, 7, BLACK},
    {7, 7, WHITE},
    {7, 6, BLACK},
    {7, 5, WHITE},
    {6, 8, BLACK},
    {8, 9, WHITE},
    {8, 8, WHITE},
};

void TestSeqStack();

void TestLinkedStack();

int main()
{
    //TestSeqStack();
    TestLinkedStack();
    return 0;
}

void TestSeqStack() {
    SeqStack * stack = (SeqStack*)malloc(sizeof(SeqStack));
    ElementType * element = (ElementType*)malloc(sizeof(ElementType));
    InitSeqStack(stack);
    for(int i = 0; i < 5; i++) {
        printf("Now in stack: %d\t%s\n", dataArray[i].id, dataArray[i].name);
        PushSeqStack(stack, dataArray[i]);
    }
    PopSeqStack(stack, element);
    printf("Now out stack: %d\t%s\n", element->id, element->name);
    //printf("%d\t%d\n", stack->length, stack->top);
    for(int i = 0; i < stack->length; i++) {
        printf("Now inside of stack: %d\t%s\n", stack->elements[i].id, stack->elements[i].name);
    }
    PopSeqStack(stack, element);
    printf("Now out stack: %d\t%s\n", element->id, element->name);
    for(int i = 0; i < stack->length; i++) {
        printf("Now inside of stack: %d\t%s\n", stack->elements[i].id, stack->elements[i].name);
    }
    free(stack);
}

void TestLinkedStack() {
    InitChessBoard();
    PrintChessBoard();
    LinkedStack * linkedStack = (LinkedStack *)malloc(sizeof(LinkedStack));
    //模拟落子过程
    for(int i = 0; i < 7; i++) {
        //记录下每次的落子情况
        PushLinkedStack(linkedStack, chessArray[i]);
        //根据棋子类型修改棋盘
        if(chessArray[i].type == BLACK){
            ChessBoard[chessArray[i].y - 1][chessArray[i].x - 1] = "●";
        }else{
            ChessBoard[chessArray[i].y - 1][chessArray[i].x - 1] = "○";
        }
    }
    printf("落子后：\n");
    PrintChessBoard();

    //自动悔棋
    while(linkedStack->length - 1) {
        printf("按任意键悔棋：\n");
        getchar();
        ChessMan currChess;
        //出栈-悔棋
        PopLinkedStack(linkedStack, &currChess);
        ChessBoard[currChess.y - 1][currChess.x - 1] = "十";
        PrintChessBoard();
    }
}
