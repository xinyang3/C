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
		*head = nplink; // ͷָ��ָ���½ڵ�
		*tail = nplink;
	}
	else { // ͷָ�뷢�����ƶ�
		nplink->next = *head; // Դͷ�ڵ�ָ���ֵ�����½ڵ�next
		*head = nplink; // ͷ�ڵ�ָ���½ڵ� ͷָ�뷢�����ƶ�
	}
	printf("\n");
}

void instert_link_tail(LNode** head, LinkList* tail, int data) {
	LinkList nplink = (LinkList)malloc(sizeof(nplink));
	nplink->data = data;
	//nplink->next = NULL;
	if (*head == NULL) {
		*head = nplink; // ͷָ��ָ���½ڵ�
		*tail = nplink;
	}
	else {
		(*tail)->next = nplink; // βָ�벻�����ƶ�
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