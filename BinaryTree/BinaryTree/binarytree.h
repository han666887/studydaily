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

//������
BTNode* BTCreat(BTDatatype* str, int sz, int* pi);

//������
void BTDistory(BTNode* bt);

//�������ڵ����
int BTNodeSize(BTNode* bt);

//������Ҷ�ӽڵ�ĸ���
int BTLeafSize(BTNode* bt);

//��k��ڵ����
int BTKSize(BTNode* bt,int k);

//����ֵΪx�Ľڵ�
BTNode* BTFind(BTNode* bt,BTDatatype x);

//ǰ�����
void BTPrevOrder(BTNode* bt);

//�������
void BTMidOrder(BTNode* bt);

//��������
void BTPostOrder(BTNode* bt);

//�������
void BTLevelOrder(BTNode* bt);

//�ж϶������Ƿ�Ϊ��ȫ������
int BTComplete(BTNode* bt);