#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

// ���鴫�� a��Ԫ�ص�ַ
void arraya(int a[], int length) {
	printf("%d", a[2]);
}

void arrayInit() {

	int a[] = {1, 2, 3, 4, 5};
	
	printf("%d", a);
	arraya(a, 5);
}