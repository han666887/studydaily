#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"

//��ʼ��
void QueueTnit(Queue* q) {
	assert(q);
	q->front = NULL;
	q->rear = NULL;
}

// ����
void QueueDestory(Queue* q) {
	assert(q);
	QNode* cur = q->front;
	while (cur) {
		cur = q->front;
		q->front = q->front->next;
		free(cur);
		cur = q->front;
	}
}
//���
void QueuePush(Queue* q, QDataType x) {
	assert(q);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL) {
		printf("newnode==NULL");
		exit(-1);
	}
	else {
		if (QueueEmpty(q)) {
			q->rear = newnode;
			q->rear->next = NULL;
			q->rear->x = x;
			q->front = newnode;
		}
		else {
			QNode* prev = q->rear;
			q->rear = newnode;
			prev->next = q->rear;
			q->rear->next = NULL;
			q->rear->x = x;
		}
	}
}

//����
void QueuePop(Queue* q) {
	assert(q);
	assert(!QueueEmpty(q));
	if (q->front == q->rear) {
		q->front = q->front->next;
		q->rear = q->rear->next;
	}
	else {
		q->front = q->front->next;
	}
}

//��ӡ
void QueuePrint(Queue* q) {
	assert(q);
	assert(!QueueEmpty(q));
	QNode* cur = q->front;
	while (cur) {
		printf("%p ", cur->x);
		cur = cur->next;
	}
	printf("\n");
}

//��ȡ��ͷԪ��
QDataType QueueFroat(Queue* q) {
	assert(q);
	assert(!QueueEmpty(q));
	return q->front->x;
}

//��ȡ��βԪ��
QDataType QueueBack(Queue* q) {
	assert(q);
	assert(!QueueEmpty(q));
	return q->rear->x;
}

//�����Ƿ�Ϊ��
bool QueueEmpty(Queue* q) {
	assert(q);
	return q->front == NULL;
}

//�ж϶���Ԫ�ظ���
int QueueSize(Queue* q) {
	assert(q);
	assert(!QueueEmpty(q));
	int count = 0;
	QNode* cur = q->front;
	while (cur) {
		count++;
		cur = cur->next;
	}
	return count;
}
