#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

int go() {
	printf("goto start!\n");

	if (100) {
		goto CASE_ERROR;
	}

	system("pause");
	return 0;


CASE_ERROR: 
	printf("here is goto position.");
}