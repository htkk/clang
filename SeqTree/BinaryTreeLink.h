#ifndef BINARYTREELINK_H_INCLUDED
#define BINARYTREELINK_H_INCLUDED

/*******************************************
 *  Project:
 *  Function: 二叉链表的实现
 *  Description:
 *  Author: 老K
 *******************************************
 *  Copyright 2019 by 老K
********************************************/
#include "TreeNode.h"
#include <string.h>

/** 二叉链表 */
typedef struct{
    TreeNode * root;    //链表的根节点
    int length;         //二叉链表节点总数
    int depth;          //二叉链表的深度
    int diameter;       //直径（从叶节点到叶节点的最长路径）
}BinaryTree;

/** 初始化空二叉树 */
void InitBinaryTree(BinaryTree * tree);

/** 构造二叉树，外部需要事先对节点分配内存 */
int CreateBinaryTree(TreeNode * root);

/** 前序遍历，也叫先根遍历，前序周游。可以记错根-左-右 */
void PreOrderTraverse(TreeNode * node);

/** 中序遍历，也叫中根遍历，可以记错左-根-右 */
void InOrderTraverse(TreeNode * node);

/** 非递归方式的中序遍历 */
void InOrderTraverse_Re(TreeNode * node);

/** 测试版创建函数 */
int CreateBinaryTree_Test(TreeNode * root);

#endif // BINARYTREELINK_H_INCLUDED
