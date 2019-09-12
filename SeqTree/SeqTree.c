#include "SeqTree.h"

/** 初始化空二叉树 */
void InitSeqTree(SeqTree tree){
    //将字符数组中的每个元素都设置为空字符
    for(int i = 0; i < MAX_SIZE; i++){
        tree[i] = '\0';
    }
}

/** 创建完全二叉树，i为数组中的下标 */
void CreateSeqTree(SeqTree tree, int i){
    char ch;
    ch = getchar();
    fflush(stdin);
    //输入^符号表示当前输入节点结束
    if(ch == '^'){
        tree[i] == '\0';
        return;
    }
    tree[i] = ch;
    //某个节点输入完毕后，还需要输入left child, right child
    printf("Left child node:");
    //递归该函数
    CreateSeqTree(tree, 2 * i + 1);
    printf("Right child node:");
    CreateSeqTree(tree, 2 * (i + 1));
}

/** 获取树的长度 */
int GetTreeLength(SeqTree tree){
    int len = 0;
    for(int i = 0; i < MAX_SIZE; i++){
        if(tree[i] != '\0'){
            len++;
        }
    }
    return len;
}

/** 获取树的深度 */
int GetSeqTreeDepth(SeqTree tree){
    //深度为k的二叉树最多有2^k-1个节点
    int depth = 0;  //深度
    int len = GetTreeLength(tree);
    while((int)pow(2, depth) - 1 < len){
        depth++;
    }
    return depth;
}
