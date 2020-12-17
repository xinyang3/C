#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
	int data;
	float score = 0.00;
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

void insert_link_sort2(LinkList * head, LinkList * tail, int data) {
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

void link_modify(LinkList head, int number, float score) {
	if (!(head)->next) {
		printf("link is empty.");
	}
	else {
		while (head) {
			if (head->data == number) {
				head->score = score;
				break;
			}
			head = head->next;
		}
	}
}

void print_link(LinkList link) {

	while (link)
	{
		printf("%d\t%f\n", link->data, link->score);
		link = link->next;
	}
}
void print_link2(LinkList link) {

	while (link)
	{
		printf("%d\t", link->data);
		link = link->next;
	}
}

void insert_link_sort3(LinkList ahead, LinkList atail, LinkList bhead) {
	while (bhead)
	{
		insert_link_sort2(&ahead, &atail, bhead->data);

		bhead = bhead->next;
	}
}

// ��������
void link_revert(LinkList ahead, LinkList atail, LinkList bhead, LinkList btail) {
	// ����ͷ�巨
	while (ahead) {
		instert_link_head(&bhead, &btail, ahead->data);
		ahead = ahead->next;
	}
	print_link2(bhead);
}

// ������
int get_link_length(LinkList head) {
	int length = 0;
	LinkList ahead = head;
	while (ahead)
	{
		ahead = ahead->next;
		length++;
	}
	printf("length=%d\n", length);
	return length;
}
// ����Ż�ȡ�ڵ�
void get_link_byIndex(LinkList ahead, int index) {
	int inx = 0;
	while (ahead)
	{
		ahead = ahead->next;
		inx++;
		if (inx == index) {
			printf("%d", ahead->data);
			break;
		}
	}
}

void link_test() {
	LinkList head, tail, temp;

	head = NULL;
	tail = NULL;
	int i = 0;
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
	printf("����lina\n");
	while (scanf("%d", &i) != EOF) {
		insert_link_sort2(&head, &tail, i);
		print_link2(head);
	}
	//printf("����linb\n");
	LinkList bhead = NULL, btail = NULL;
	/*while (scanf("%d", &i) != EOF) {
		insert_link_sort2(&bhead, &btail, i);
		print_link2(bhead);
	}*/
	//insert_link_sort3(head, tail, bhead);
	//print_link2(head);


	//link_revert(head, tail, bhead, btail);
	int length = get_link_length(head);
	get_link_byIndex(head, length - 4);
	//printf("������ɾ��\n");
	//while (scanf("%d", &i) != EOF)
	//{
	//	// ɾ��
	//	link_delete(&head, &tail, i);
	//	print_link(head);
	//}

	/*int number;
	float score;
	printf("�޸ĵ�ѧ��");
	while (scanf("%d %f", &number, &score) != EOF) {
		link_modify(head, number, score);
		print_link(head);
	}*/
}