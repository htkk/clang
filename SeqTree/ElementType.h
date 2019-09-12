#ifndef ELEMENTTYPE_H_INCLUDED
#define ELEMENTTYPE_H_INCLUDED

/*******************************************
 *  Project:
 *  Function: 二叉链数据元素
 *  Description:
 *  Author: 老K
 *******************************************
 *  Copyright 2019 by 老K
********************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1024
#define NAME_SIZE 255

/** 数据元素 */
typedef struct{
    int id;
    char name[NAME_SIZE];
}ElementType;


#endif // ELEMENTTYPE_H_INCLUDED
