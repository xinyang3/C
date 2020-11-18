#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

#define N 5

void exchange(int ** a, int **b) {
	int *s = *a;
	*a = *b;
	*b = s;
}

void point_db_exchange() {
	int a = 10, b = 12;

	int* pa = &a,
		* pb = &b;
	
	exchange(&pa, &pb);

	printf("a = %d, b = %d", *pa, *pb);
}

void point_db_ary() {
	char b[5][15] = { "google", "baidu", "tencent", "microsoft", "alibaba" };

	printf("b-size = %d, b1-size = %d", sizeof(b), sizeof(b[1]));

	char* p;
	char** p2 = (char **)malloc(20);

	for (int i = 0; i < sizeof(b) / sizeof(b[1]); i++) {
		*(p2 + i) = b[i];
	}
	
	for (size_t i = 0; i < N; i++)
	{
		puts(p2[i]);
	}

}