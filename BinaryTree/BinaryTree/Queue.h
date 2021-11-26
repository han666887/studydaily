#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

//����
struct BinaryTreeNode;
typedef struct BinaryTreeNode* QDataType;

typedef struct QListNode {
	struct QListNode* next;
	QDataType x;
}QNode;

typedef struct Queue {
	QNode* front;
	QNode* rear;
}Queue;


//��ʼ��
void QueueTnit(Queue* q);

// ����
void QueueDestory(Queue* q);
//���
void QueuePush(Queue* q, QDataType x);

//����
void QueuePop(Queue* q);

//��ӡ
void QueuePrint(Queue* q);

//��ȡ��ͷԪ��
QDataType QueueFroat(Queue* q);

//��ȡ��βԪ��
QDataType QueueBack(Queue* q);

//�����Ƿ�Ϊ��
bool QueueEmpty(Queue* q);
//�ж϶���Ԫ�ظ���
QDataType QueueSize(Queue* q);

