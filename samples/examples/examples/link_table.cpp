#include <stdio.h>
#include <stdlib.h>

typedef struct Type_link {
	int data;
	struct Type_link * next;
} t_link, * t_pLink;

void instert_link_head(t_link ** head, t_pLink * tail, int data) {
	t_pLink nplink = (t_pLink)malloc(sizeof(nplink));
	nplink->data = data;
	nplink->next = NULL;
	if (*head) {
		*head = nplink; // 头节点指针指向新节点
		*tail = nplink;
	}
	else {
		nplink->next = *head; // 源头节点指向的值赋给新节点next
		*head = nplink; // 头节点指向新节点
	}
}


void link_test() {
	t_pLink head, tail, temp;

	head = NULL;
	tail = NULL;
	int i;
	while (scanf("%d", &i) != EOF) {
		instert_link_head(&head, &tail, i);
	}

	//temp = head;
	while (head != NULL) {
		printf("%d\t", head->data);
		head = head->next;
	}
}