#ifndef SEQSTRING_H_INCLUDED
#define SEQSTRING_H_INCLUDED

/*******************************************
 *  Project: 串string
 *  Function: 串的顺序结构实现
 *  Description:
 *  Author: 老K
 *******************************************
 *  Copyright 2019 by 老K
********************************************/
#include "StatusLib.h"
#include <String.h>

/*
#define MAX_SIZE 1024
typedef struct{
    char ch[MAX_SIZE + 1];  //定长方式实现字符串的顺序结构，缺点是占用空间，因为字符串类型最后一位是\0，所以+1
    int length;
}SString
*/

/** 串的堆式顺序存储结构(Heap) */
typedef struct{
    char * ch;      //如果是非空串，那么就按照指定长度分配内存，否则就指向NULL
    int length;     //串的当前长度
}HString;

/** 初始化堆字符串 */
void InitString_HeapString(HString * str);

/** 为串str赋值，值为字符串常量chars */
Status StrAssign_HeapString(HString * str, char * chars);

/** 打印堆字符串 */
void PrintHeapString(HString * str);

/** 将串srcStr中的内容复制到串destStr中 */
Status StrCopy_HeapString(HString * destStr, HString * srcStr);

/** 判断串是否为空 */
Status IsEmpty_HeapString(HString * str);

/** 比较两个堆字符的大小，相等返回0，1<2返回负数，1>2返回正数 */
Status StrCompare_HeapString(HString * str1, HString * str2);

/** 连接串 */
Status Concat_HeapString(HString * destStr, HString * str1, HString * str2);

/** 截取串，从pos处截取len长度的串 */
Status SubString_HeapString(HString * destStr, HString * str, int pos, int len);

/** 返回从pos位置开始的子串child在父串parent中的位置 */
int Index_HeapString(HString * parent, HString * child, int pos);

/** 从pos位置处删除长度len的子串 */
Status StrDelete_HeapString(HString * str, int pos, int len);

/** 向指定位置插入串 */
Status StrInsert_HeapString(HString * str, int pos, HString * insertStr);

/** 将串str中的oldstr替换成newStr */
Status Replace_HeapString(HString * str, HString oldStr, HString newStr);

/** 清空堆字符串 */
Status ClearString_HeapString(HString * str);

/** 使用BF算法返回子串在主串中的位置 */
int BfCompare(HString * parent, HString * child, int pos);

/** KMP算法返回next数组（部分匹配表） */
void Get_Next(HString child, int * next);

/** 使用KMP算法返回子串在主串中的位置 */
int KMPCompare(HString * parent, HString * child, int pos);

#endif // SEQSTRING_H_INCLUDED
