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

void insert_link_sort2(LinkList * head, LinkList * tail, int data) {
	LinkList nplink = (LinkList)calloc(1, sizeof(LNode));
	nplink->data = data;
	nplink->next = NULL;

	LinkList pcur = *head, pre = *head;;

	if (!*head) {
		*head = nplink;
		*tail = nplink;
	}
	else if (data < (*head)->data) // 头节点之前插入
	{
		nplink->next = *head;
		*head = nplink;
	}
	else if (data >= (*head)->data) // 头节点之后
	{
		while (pcur) // 中间节点
		{
			if (pcur->data > data) {
				pre->next = nplink;
				nplink->next = pcur;
				break;
			}
			pre = pcur;
			pcur = pcur->next;
		}

		if (!pcur) // 遍历到链表结尾
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
		while (pcur) // 数据在链表中 data是尾节点
		{
			if (pcur->data == data) {
				pre->next = pcur->next;
				free(pcur);
		
				if (pcur->next == NULL) { // 为节点删除
					*tail = pre;
				}
				break;
			}
			pre = pcur;
			pcur = pcur->next;
		}
		if (!pcur) { // 不存在在链表中
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

// 链表逆序
void link_revert(LinkList ahead, LinkList atail, LinkList bhead, LinkList btail) {
	// 链表头插法
	while (ahead) {
		instert_link_head(&bhead, &btail, ahead->data);
		ahead = ahead->next;
	}
	print_link2(bhead);
}

// 链表长度
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
// 按序号获取节点
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
	printf("输入lina\n");
	while (scanf("%d", &i) != EOF) {
		insert_link_sort2(&head, &tail, i);
		print_link2(head);
	}
	//printf("输入linb\n");
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
	//printf("链表中删除\n");
	//while (scanf("%d", &i) != EOF)
	//{
	//	// 删除
	//	link_delete(&head, &tail, i);
	//	print_link(head);
	//}

	/*int number;
	float score;
	printf("修改的学分");
	while (scanf("%d %f", &number, &score) != EOF) {
		link_modify(head, number, score);
		print_link(head);
	}*/
}