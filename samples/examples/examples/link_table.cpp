#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
	int data;
	struct LNode * next;
} LNode, * LinkList;

void instert_link_head(LNode** head, LinkList* tail, int data) {
	LinkList nplink = (LinkList)malloc(sizeof(nplink));
	nplink->data = data;
	nplink->next = NULL;
	if (*head == NULL) {
		*head = nplink; // 头指针指向新节点
		*tail = nplink;
	}
	else { // 头指针发生了移动
		nplink->next = *head; // 源头节点指向的值赋给新节点next
		*head = nplink; // 头节点指向新节点 头指针发生了移动
	}
	printf("\n");
}

void instert_link_tail(LNode** head, LinkList* tail, int data) {
	LinkList nplink = (LinkList)malloc(sizeof(nplink));
	nplink->data = data;
	//nplink->next = NULL;
	if (*head == NULL) {
		*head = nplink; // 头指针指向新节点
		*tail = nplink;
	}
	else {
		(*tail)->next = nplink; // 尾指针不发生移动
		(*tail) = nplink;
	}
}

void link_test() {
	LinkList head, tail, temp;

	head = NULL;
	tail = NULL;
	int i;
	while (scanf("%d", &i) != EOF) {
		//instert_link_head(&head, &tail, i);
		instert_link_tail(&head, &tail, i);
	}
	/*while (head != NULL) {
		printf("%d\t", head->data);
		head = head->next;
	}*/

	while (tail)
	{
		printf("%d\t", tail->data);
		tail = tail->next;
	}

}