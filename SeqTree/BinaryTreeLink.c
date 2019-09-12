#include "BinaryTreeLink.h"
#include "LinkedStack.h"

/** 静态id */
static int id = 0;

/** 初始化空二叉树 */
void InitBinaryTree(BinaryTree * tree){
    tree->root = NULL;
    tree->depth = 0;
    tree->diameter = 0;
    tree->length = 0;
}

/** 构造二叉树，外部需要事先对节点分配内存 */
int CreateBinaryTree(TreeNode * root){
    //根节点如果为空，就退出
    if(!root) return 0;
    char inputName[NAME_SIZE];
    gets(inputName);
    //用户输入回车表示结束当前子树创建
    if(strcmp(inputName, "\0") == 0) return 0;
    //创建当前节点
    root->data.id = ++id;
    strcpy(root->data.name, inputName);
    //为输入左右节点做准备，为左右节点指针分配内存
    root->left = (TreeNode *)malloc(sizeof(TreeNode));
    root->right = (TreeNode *)malloc(sizeof(TreeNode));
    //分别递归左右子树
    printf("Left node: ");
    if(CreateBinaryTree(root->left) == 0){
        free(root->left);
        root->left = NULL;
    }
    printf("Right node: ");
    if(CreateBinaryTree(root->right) == 0){
        free(root->right);
        root->right = NULL;
    }
    return 1;
}

/** 前序遍历，也叫先根遍历，前序周游。可以记错根-左-右 */
void PreOrderTraverse(TreeNode * node){
    //先访问根节点，然后遍历左子树，最后遍历右子树
    if(node){
        printf("[%d, %s]-", node->data.id, node->data.name);
        PreOrderTraverse(node->left);
        PreOrderTraverse(node->right);
    }
}

/** 中序遍历，也叫中根遍历，可以记错左-根-右 */
void InOrderTraverse(TreeNode * node){
    if(node){
        InOrderTraverse(node->left);
        printf("[%d, %s]-", node->data.id, node->data.name);
        InOrderTraverse(node->right);
    }
}

/** 非递归方式的中序遍历 */
void InOrderTraverse_Re(TreeNode * node){
    /**
     * 根据中序遍历的顺序，对任意节点来讲，优先访问左子节点，而左子节点又可以看作一个根节点
     * 然后继续访问左子节点为空的节点，按照相同的规则访问右子树
     */
     LinkedStack linkedStack;
     InitLinkedStack(&linkedStack);
     TreeNode * root = node;
     //currNode用来保存每个出栈的节点指针
     TreeNode * currNode = (TreeNode *)malloc(sizeof(TreeNode));
     //还需要一个临时指针，用来确保最后释放掉上面分配的内存
     TreeNode * tempNode = (TreeNode *)malloc(sizeof(TreeNode));

     while(root || !IsLinkedStackEmpty(&linkedStack)){
        if(root){
            Push(&linkedStack, root);
            root = root->left;
        }else{
            //难点
            Pop(&linkedStack, &currNode);
            printf("[%d, %s]-", currNode->data.id, currNode->data.name);
            root = currNode->right;
        }
     }
     free(tempNode);
}

/** 模仿用户输入 */
char * nodeNames[] = {"A", "B", "D", "#", "#", "E", "#", "#", "C", "F", "#", "#", "G", "#", "#"};

/** 访问nodeNames数组中的下标 */
static int nodeNameIndex = 0;

/** 测试版创建函数 */
int CreateBinaryTree_Test(TreeNode * root){
    //根节点如果为空，就退出
    if(!root) return 0;
    char inputName[NAME_SIZE];
    //gets(inputName);
    strcpy(inputName, nodeNames[nodeNameIndex++]);
    //用户输入回车表示结束当前子树创建
    if(strcmp(inputName, "#") == 0) return 0;
    //创建当前节点
    root->data.id = ++id;
    strcpy(root->data.name, inputName);
    //为输入左右节点做准备，为左右节点指针分配内存
    root->left = (TreeNode *)malloc(sizeof(TreeNode));
    root->right = (TreeNode *)malloc(sizeof(TreeNode));
    //分别递归左右子树
    printf("Left node: ");
    if(CreateBinaryTree_Test(root->left) == 0){
        free(root->left);
        root->left = NULL;
    }
    printf("Right node: ");
    if(CreateBinaryTree_Test(root->right) == 0){
        free(root->right);
        root->right = NULL;
    }
    return 1;
}


