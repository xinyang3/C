#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QNode {
	int data;
	QNode * next;
} QNode, * PQNode;

typedef struct {
	PQNode head;
	PQNode tail;
} LQueue, * PLQueue;

void queue_insert(PLQueue pq, int data){
	PQNode npnode = (PQNode)malloc(sizeof(QNode));
	npnode->data = data;
	npnode->next = NULL;
	//npnode->next = pq->head; // 新节点指向head?

	if (!pq->tail) {
		pq->tail = npnode;
		pq->head = npnode;
	}
	else { // 尾部插入
		pq->tail->next = npnode;
		pq->tail = npnode;
	}
}

void queue_del(PLQueue pq) {
	PQNode pcur = pq->head;
	pq->head = pcur->next;
	printf("弹出%d", pcur->data); //头部删除
	free(pcur);
}


void queue_test() {
	LQueue lque;
	lque.head = NULL;
	lque.tail = NULL;
	int data;

	while (scanf("%d", &data) != EOF) {
		queue_insert(&lque, data);
	}
}