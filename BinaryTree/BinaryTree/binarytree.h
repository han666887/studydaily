#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef char BTDatatype;
typedef struct BinaryTreeNode {
	BTDatatype val;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//创建树
BTNode* BTCreat(BTDatatype* str, int sz, int* pi);

//销毁树
void BTDistory(BTNode* bt);

//二叉树节点个数
int BTNodeSize(BTNode* bt);

//二叉树叶子节点的个数
int BTLeafSize(BTNode* bt);

//第k层节点个数
int BTKSize(BTNode* bt,int k);

//查找值为x的节点
BTNode* BTFind(BTNode* bt,BTDatatype x);

//前序遍历
void BTPrevOrder(BTNode* bt);

//中序遍历
void BTMidOrder(BTNode* bt);

//后续遍历
void BTPostOrder(BTNode* bt);

//层序遍历
void BTLevelOrder(BTNode* bt);

//判断二叉树是否为完全二叉树
int BTComplete(BTNode* bt);