#include <stdio.h>
#include <stdlib.h>
#include "SeqTree.h"
#include "BinaryTreeLink.h"

void TestSeqTree();
void TestBinaryTree();

int main()
{
    //TestSeqTree();
    TestBinaryTree();

    return 0;
}

void TestBinaryTree(){
    BinaryTree tree;
    InitBinaryTree(&tree);
    tree.root = (TreeNode *)malloc(sizeof(TreeNode));
    printf("Please enter root node: ");
    CreateBinaryTree_Test(tree.root);
    printf("\n\nPre order traverse:\n");
    PreOrderTraverse(tree.root);
    printf("\n\nIn order traverse:\n");
    InOrderTraverse(tree.root);
    printf("\n\nIn_re order traverse:\n");
    InOrderTraverse_Re(tree.root);

    free(tree.root);
}

void TestSeqTree(){
    SeqTree tree;
    InitSeqTree(tree);
    printf("Please enter root node:");
    CreateSeqTree(tree, 0);

    for(int i = 0; i < 15; i++){
        printf("%d, ", tree[i]);
    }
    printf("\n");
    printf("Tree's length: %d\n", GetTreeLength(tree));
    printf("Tree's depth: %d\n", GetSeqTreeDepth(tree));
}
