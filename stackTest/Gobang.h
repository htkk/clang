#ifndef GOBANG_H_INCLUDED
#define GOBANG_H_INCLUDED

/*******************************************
 *  Project:
 *  Function:
 *  Description:
 *  Author: 老K
 *******************************************
 *  Copyright 2019 by 老K
********************************************/
#include "Element.h"
#define BOARD_SIZE 15

/** 棋盘数组 */
char * ChessBoard[BOARD_SIZE][BOARD_SIZE];

/** 初始化/重置棋盘 */
void InitChessBoard();

void PrintChessBoard();

#endif // GOBANG_H_INCLUDED
