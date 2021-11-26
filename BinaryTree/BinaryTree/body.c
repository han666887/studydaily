#define _CRT_SECURE_NO_WARNINGS
#include "binarytree.h"
#include "Queue.h"

BTNode* BTNodeCreat(BTDatatype x) {
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL) {
		printf("node==NULL");
		exit(-1);
	}
	node->val = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}

//�������ص�
BTNode* BTCreat(BTDatatype* str, int sz, int* pi) {
	assert(str);
	if (str[*pi] == '#') {
		(*pi)++;
		return NULL;
	}
	BTNode* bt=BTNodeCreat(str[*pi]);
	(*pi)++;
	bt->left = BTCreat(str, sz, pi);
	bt->right = BTCreat(str, sz, pi);
	return bt;
}

//������
void BTDistory(BTNode* bt) {
	if (bt == NULL) {
		return;
	}
	BTDistory(bt->left);
	BTDistory(bt->right);
	free(bt);
	bt = NULL;
}

//�������ڵ����
int BTNodeSize(BTNode* bt) {
	if (bt == NULL) {
		return 0;
	}
	return 1+BTNodeSize(bt->left)+BTNodeSize(bt->right);
}

//������Ҷ�ӽڵ�ĸ���
int BTLeafSize(BTNode* bt) {
	if (bt == NULL) {
		return 0;
	}
	if (bt->left == NULL && bt->right == NULL) {
		return 1;
	}
	return BTLeafSize(bt->left) + BTLeafSize(bt->right);
}

//��k��ڵ����
int BTKSize(BTNode* bt,int k) {
	if (bt == NULL) {
		return 0;
	}
	if (k == 1) {
		return 1;
	}
	return  BTKSize(bt->left, k - 1) + BTKSize(bt->right, k - 1);
}

//����ֵΪx�Ľڵ�
BTNode* BTFind(BTNode* bt,BTDatatype x) {
	if (bt == NULL) {
		return NULL;
	}
	if (bt->val == x) {
		return bt;
	}
	
	BTNode* left=BTFind(bt->left, x);
	if (left) {
		return left;
	}
	BTNode* right=BTFind(bt->right, x);
	if (right) {
		return right;
	}
	return NULL;
}

//ǰ�����
void BTPrevOrder(BTNode* bt) {
	if (bt == NULL) {
		printf("NULL ");
		return;
	}
	printf("%c ", bt->val);
	BTPrevOrder(bt->left);
	BTPrevOrder(bt->right);
}

//�������
void BTMidOrder(BTNode* bt) {
	if (bt == NULL) {
		printf("NULL ");
		return;
	}
	BTMidOrder(bt->left);
	printf("%c ", bt->val);
	BTMidOrder(bt->right);
}

//��������
void BTPostOrder(BTNode* bt) {
	if (bt == NULL) {
		printf("NULL ");
		return;
	}
	BTPostOrder(bt->left);
	BTPostOrder(bt->right);
	printf("%c ", bt->val);
}

//�������
void BTLevelOrder(BTNode* bt) {
	Queue q;
	QueueTnit(&q);
	if (bt == NULL) {
		return;
	}
	QueuePush(&q, bt);
	while (!QueueEmpty(&q)) {
		BTNode* p = QueueFroat(&q);
		if (p == NULL) {
			printf("NULL ");
			QueuePop(&q);
			continue;
		}
		else {
			printf("%c ", p->val);
		}
		QueuePop(&q);
		if (p->left != NULL || p->right != NULL) {
			QueuePush(&q, p->left);
			QueuePush(&q, p->right);
		}
	}
	QueueDestory(&q);
}

//�ж϶������Ƿ�Ϊ��ȫ������
int BTComplete(BTNode* bt) {
	int sz=BTNodeSize(bt);
	int count = 0;
	Queue q;
	QueueTnit(&q);
	if (bt == NULL) {
		exit(-1);
	}
	QueuePush(&q, bt);
	while (!QueueEmpty(&q)) {
		BTNode* p = QueueFroat(&q);
		if (p == NULL) {
			break;
		}
		else {
			count++;
		}
		QueuePop(&q);
		if (p->left != NULL || p->right != NULL) {
			QueuePush(&q, p->left);
			QueuePush(&q, p->right);
		}
	}
	QueueDestory(&q);
	if (count == sz) {
		return 1;
	}
	else {
		return 0;
	}
}
