#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct leaf {
	char c;
	leaf * left;
	leaf * right;
} leaf, * pleaf;

// tree¡¥±Ì
void link_tree() {
	char leafs[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'h', 'i', 'j', 'k'};

	pleaf p[N];

	pleaf tree;

	for (size_t i = 0; i < N; i++)
	{
		p[i] = (pleaf)malloc(sizeof(leaf));
		p[i]->c = leafs[i];
		p[i]->left = NULL;
		p[i]->right = NULL;
	}
	tree = p[0];

	for (size_t i = 1; i < N; i++)
	{

		for (size_t j = 0; j < N; j++)
		{
			if (!p[j]->left) {
				p[j]->left = p[i];
				break;
			}
			else if (!p[j]->right) {
				p[j]->right = p[i];
				break;
			}
		}
	}

}