#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

/*******************************************
 *  Project:
 *  Function: 树节点
 *  Description:
 *  Author: 老K
 *******************************************
 *  Copyright 2019 by 老K
********************************************/
#include "ElementType.h"

/** 树节点 */
typedef struct treeNode{
    ElementType data;           //数据域
    struct treeNode * left;     //左子树
    struct treeNode * right;    //右子树
}TreeNode;


#endif // TREENODE_H_INCLUDED
