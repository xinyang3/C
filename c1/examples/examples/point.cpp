#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

void p_caculate1() {
	int a[5] = { 1, 2, 3, 4, 5 };

	int r = a == &a[0];

	if (a == &a[0]) {
		printf("a == &a[0]\n");
	}

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

void calcute_2() {
	int a[5] = { 1, 3, 5, 7, 9 };
	int *p;
	p = &a[0];
	int j;

	j = *p++;
	// 相当于 j = *p; p ++;
	//  j=1 *p =3

	j = (*p)++;
	// 相当于j = *p; (*p) ++  
	 // a[0] = 2, *p = 2, j=1
	

	p = &a[1];
	j = *--p;
	// --p; j = *p;
	// a[0] = 1, *p = 1, j =1
	
	p = &a[0];
	j = p[0]++;
	// j = p[0]; p[0] ++ 
	// a[0] = 2, *p = 2; j =1;

	printf("a[0] = %d, *p = %d, j = %d\n", a[0], *p, j);
}

void calcute_3() {
	char a[] = "hello";

	char * p = a;
	a[0] = 'H';
	p[1] = 'E';
	//a = "world";
	printf("%s\n", a);
}


void calcute_array(int (*p)[4] , int length) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < sizeof(p); j++) {
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}
}

void calcute_4() {
	int c[3][4] = { 1, 2, 3, 4, 5, 6, 7,8,9,10,11,12 };
	calcute_array(c, 3);
	//calcute_array_2(c[0]);
}
void calcute_array_2(int * p) {

}
