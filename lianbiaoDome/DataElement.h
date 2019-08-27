#ifndef DATAELEMENT_H_INCLUDED
#define DATAELEMENT_H_INCLUDED

/*******************************************
 *  Project: 数据结构之线性表
 *  Function: 用来定义数据元素
 *  Description:
 *  Author: 老K
 *******************************************
 *  Copyright 2019 by 老K
********************************************/

#define MAX_SIZE 255
#define TRUE 1
#define FALSE 0

//1、定义数据元素

typedef struct {
    int id;
    char * name;
}ElementType;

//2，定义顺序表结构

typedef struct {
    ElementType datas[MAX_SIZE];    //顺序表中的元素集合
    int length; //当前顺序表中的元素个数
}SeqList;




#endif // DATAELEMENT_H_INCLUDED
