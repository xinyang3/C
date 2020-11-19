#include <stdio.h>
#include <stdlib.h>

typedef struct type_link {
	int data;
	t_pLink next;
} t_link, * t_pLink;

void instert_link_head(t_link ** head, t_pLink * tail, int data) {
	t_pLink nplink = (t_pLink)malloc(sizeof(nplink));
	nplink->data = data;
	if (*head) {
		(*head)->next = nplink;
		(*tail)->next = nplink;
	}
	else {
		nplink->next = (*head)->next;
		(*head)->next = nplink;
	}
}


void link_test() {
	t_link link;
	t_pLink head, tail, temp;

	head = NULL;
	tail = NULL;
	int i;
	while (scanf("%d", &i) != EOF) {
		instert_link_head(&head, &tail, i);
	}

	temp = head;
	while (temp->next != NULL) {
		printf("%d\t", temp->data);
		temp = temp->next;
	}
}