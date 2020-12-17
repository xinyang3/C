#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LNode {
	int data;
	LNode * next;
}LNode, *pLNode;

typedef struct Stack {
	int size;
	LNode * head;
} Stack, *pStack;

void stack_push(pStack pstack, int data) {
	pLNode pnode = (pLNode)malloc(sizeof(LNode));
	pnode->data = data;
	pnode->next = NULL;

	if (!pstack->head) {
		pstack->head = pnode;
	}
	else {
		pnode->next = pstack->head;
		pstack->head = pnode;
	}
}


void stack_test() {
	Stack stack;
	memset(&stack, 0, sizeof(Stack));
	int data;
	while (scanf("%d", &data)) {
		stack_push(&stack, data);
	}
}

