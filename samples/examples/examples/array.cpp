#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

// 数组传递 a首元素地址
void arraya(int a[], int length) {
	printf("%d\n", a[2]);
	printf("数组地址的长度=%d", sizeof(a));
}

void arrayInit() {

	int a[] = {1, 2, 3, 4, 5};
	
	printf("%d", a);
	arraya(a, 5);
}

void charArray() {
	char c1[] = "abcdef";
	char c2[] = "abcdef\0m";
	char c3[] = { 'a', ' ', ' ', ' m', '\0' };
	printf("c1 = %s, size = %d\n", c1, sizeof(c1));
	printf("c2 = %s, size = %d\n", c2, sizeof(c2));
	printf("c3 = %s, size = %d\n", c3, sizeof(c3));
	//c1 = abcdef, size = 7
	//c2 = abcdef, size = 9
	//c3 = a  m, size = 5
	
}

void arrayD(int aa[][3], int length, int dd) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < sizeof(aa[i]) / sizeof(int); j++) {
			printf("a[i][j] = %d", aa[i][j]);
		}
	}
	// 修改元素
	aa[0][1] = 1234;
}
// 二维数组
void arrayDinit() {
	int a[][3] = { 1, 2, 3, 1, 2, 3, 1 };
	int b[][3] = { {1, 2}, {1, 2} };
	int d = 123;
	arrayD(a, 3, d);
	// d传递的是值，而非地址，函数内单独又开辟了内存空间
	// a[0][1]发生了修改,因为传递的是数组元素的首地址，操作的是内存中同一份数据
	printf("a[0][1] = %d\n", a[0][1]); // 1234

	charArray();
}
