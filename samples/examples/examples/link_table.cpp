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

void insert_link_sort(LinkList * head, LinkList * tail, int data) {
	LinkList nplink = (LinkList)calloc(1, sizeof(LNode));
	nplink->data = data;
	nplink->next = NULL;

	LinkList pcur = *head, pre = *head;;

	if (!*head) {
		*head = nplink;
		*tail = nplink;
	}
	else if (data < (*head)->data) // ͷ�ڵ�֮ǰ����
	{
		nplink->next = *head;
		*head = nplink;
	}
	else if (data >= (*head)->data) // ͷ�ڵ�֮��
	{
		while (pcur) // �м�ڵ�
		{
			if (pcur->data > data) {
				pre->next = nplink;
				nplink->next = pcur;
				break;
			}
			pre = pcur;
			pcur = pcur->next;
		}

		if (!pcur) // �����������β
		{
			pre->next = nplink;
			*tail = nplink;
		}
	}
}

void link_delete(LinkList * head, LinkList * tail, int data) {
	if (!*head) {
		printf("%d", "this is empty linklist.");
	}

	LinkList pcur = *head, pre = *head;

	if ((*head)->data == data) {
		*head = pcur->next;
		free(pcur);
		if ((*head)->next == NULL) {
			*tail = NULL;
		}
	}
	else {
		while (pcur) // ������������ data��β�ڵ�
		{
			if (pcur->data == data) {
				pre->next = pcur->next;
				free(pcur);
		
				if (pcur->next == NULL) { // Ϊ�ڵ�ɾ��
					*tail = pre;
				}
				break;
			}
			pre = pcur;
			pcur = pcur->next;
		}
		if (!pcur) { // ��������������
			printf("the data is not exist linkList.");
		}
	}
}

void print_link(LinkList link) {

	while (link)
	{
		printf("%d\t", link->data);
		link = link->next;
	}
}


void link_test() {
	LinkList head, tail, temp;

	head = NULL;
	tail = NULL;
	int i;
	//while (scanf("%d", &i) != EOF) {
	//	//instert_link_head(&head, &tail, i);
	//	//instert_link_tail(&head, &tail, i);
	//}
	/*while (head != NULL) {
		printf("%d\t", head->data);
		head = head->next;
	}*/

	/*while (tail)
	{
		printf("%d\t", tail->data);
		tail = tail->next;
	}*/

	while (scanf("%d", &i) != EOF) {
		insert_link_sort(&head, &tail, i);
		print_link(head);

	}
	printf("������ɾ��\n");
	while (scanf("%d", &i) != EOF)
	{
		// ɾ��
		link_delete(&head, &tail, i);
		print_link(head);
	}
}