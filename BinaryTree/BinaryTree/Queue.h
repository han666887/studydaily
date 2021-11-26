#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

//声明
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


//初始化
void QueueTnit(Queue* q);

// 销毁
void QueueDestory(Queue* q);
//入队
void QueuePush(Queue* q, QDataType x);

//出队
void QueuePop(Queue* q);

//打印
void QueuePrint(Queue* q);

//获取队头元素
QDataType QueueFroat(Queue* q);

//获取队尾元素
QDataType QueueBack(Queue* q);

//检测队是否为空
bool QueueEmpty(Queue* q);
//判断对例元素个数
QDataType QueueSize(Queue* q);

