#ifndef STATUSLIB_H_INCLUDED
#define STATUSLIB_H_INCLUDED

/*******************************************
 *  Project: 串string
 *  Function: 定义状态码及宏函数
 *  Description:
 *  Author: 老K
 *******************************************
 *  Copyright 2019 by 老K
********************************************/

#include <stdio.h>
#include <stdlib.h>

/** 状态码 */
#define ERROR 0
#define OK 1

#define TRUE 1
#define FALSE 0

#define EQ 0    //等于
#define GT 1    //大于great than
#define LT -1   //小于less than

//内存溢出
#ifndef _STATUS_H_
    #define OVERFLOW -2     //堆栈上溢，超过所能代表的最大正数
    #define UNDERFLOW -3    //堆栈下溢，超过所能代表的最小负数
#endif // _STATUS_H_

//状态码识别类型
typedef int Status;

#endif // STATUSLIB_H_INCLUDED
