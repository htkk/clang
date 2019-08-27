#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED

/*******************************************
 *  Project:
 *  Function:
 *  Description:
 *  Author: 老K
 *******************************************
 *  Copyright 2019 by 老K
********************************************/

#define MAX_SIZE 255
#define TRUE 1
#define FALSE 0
#define WHITE 1
#define BLACK 2

typedef struct {
    int id;
    char * name;
}ElementType;

/** 棋子结构 */
typedef struct {
    int x;      //当前棋子的坐标
    int y;
    int type;   //当前棋子的类型（WHITE/BLACK）
}ChessMan;

#endif // ELEMENT_H_INCLUDED
