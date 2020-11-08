#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

void p_caculate1() {
	int a[5] = { 1, 2, 3, 4, 5 };
	int *p;
	p = &a[1];
	int j;
	// exp 1
	//j = *p++; // j = *p; p ++; // exp1 1, 2 1
	
	//j = (*p)++; // j = *p; (*p) ++   // 2, 2, 1

	//j = *--p; // p --; j = *p; // 1, 1, 1

	j = p[0]++; // j = p[0]; p[0] ++ 
	printf("a[0] = %d, *p = %d, j = %d\n", a[0], *p, j); 
	printf("%d", sizeof(int *));

}