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

	// scanf 用正则把匹配到内容放在缓冲区
	// \n 回车会把缓冲区内容释放清空
	/*while (scanf("%i", &i) != EOF) {

		printf("i=%d\n", i);
	}*/
	// 先清空缓冲区
	/*while (fflush(stdin), scanf("%i", &i) != EOF) {

		printf("i=%d\n", i);
	}*/

	char c;
	while (scanf("%c", &c) != EOF) {
		printf("c=%c", c);
	}
}