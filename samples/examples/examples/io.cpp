#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void io() {
	int i, j;
	char c;
	float f;
	scanf("%d", &i);
	printf("i=%d\n", i);
	scanf("%f", &f);
	printf("f=%f\n", f);
	system("pause");
}

void keepScan() {

	int i;

	// scanf �������ƥ�䵽���ݷ��ڻ�����
	// \n �س���ѻ����������ͷ����
	/*while (scanf("%i", &i) != EOF) {

		printf("i=%d\n", i);
	}*/
	// ����ջ�����
	/*while (fflush(stdin), scanf("%i", &i) != EOF) {

		printf("i=%d\n", i);
	}*/

	char c;
	while (scanf("%c", &c) != EOF) {
		printf("c=%c", c);
	}
}