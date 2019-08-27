#include "Gobang.h"
#include "LinkedStack.h"

/** 初始化/重置棋盘 */
void InitChessBoard() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            ChessBoard[i][j] = "十";
        }
    }
}

void PrintChessBoard() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%s", ChessBoard[i][j]);
        }
        printf("\n");
    }
}
