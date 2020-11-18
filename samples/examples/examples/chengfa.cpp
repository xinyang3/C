#include <stdlib.h>
#include <stdio.h>

#define N 9

// 乘法
void print_chengfa() {
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%d*%d=%d\t", j, i, i * j);
		}
		printf("\n");
	}
}

// 菱形
void print_lingxing() {
	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= abs(5 - i); k++) {
			printf(" ");
		}

		int length = 0;
		if (i <= 5) {
			length = 2 * i - 1;
		} else {
			length = 2 * (10 - i) - 1;
		}

		for (int j = 1; j <= length; j++) {
			if (j % 2 == 0) {
				printf(" ");
			} else {
				printf("*");
			}
		}
		printf("\n");

	}
}
// 菱形空心
void print_lingxing_kong() {
	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= abs(5 - i); k++) {
			printf(" ");
		}

		int length = 0;
		if (i <= 5) {
			length = 2 * i - 1;
		}
		else {
			length = 2 * (10 - i) - 1;
		}

		for (int j = 1; j <= length; j++) {
			if (j == 1 || j == length) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");

	}
}

// 两个数组共同元素
void print_array_cmn_element(int * p1, int p1_length, int *p2, int p2_length) {

	for (size_t i = 0; i < p1_length; i++)
	{
		for (size_t j = 0; j < p2_length; j++)
		{
			if (*(p1 + i) ==  *(p2 +j)) {
				printf("%d\t", *(p1 + i));
				continue;
			}
		}
	}

}
// 两个有序数组共同元素
int array_cmn_element_2(int* p1, int p1_length, int* p2, int p2_length, int * result) {
	int i = 0, j = 0, index = 0;
	while (i < p1_length && j < p2_length) {
		if (*(p1 + i) < *(p2 + j)) {
			i++;
		}
		else if (*(p1 + i) > *(p2 + j)){
			j++;
		}
		else {
			printf("%d\t", *(p1 + i));
			*(result + index) = *(p1 + i);
			i++;
			j++;
			index++;
		}
	}
	printf("\n");
	return index;
}
// 三个数组的共同元素
void print_array_cmn_element_3() {
	int p1[] = { 1, 2, 3, 10, 11, 22, 100 };
	int p2[] = { 11, 12, 13, 14, 22 };
	int p3[] = { 9,  22 };
	int result1[] = { 0 },
		result2[] = { 0 },
		result_length = 0;

	result_length = array_cmn_element_2(p1, 6, p2, 5, result1);
	result_length = array_cmn_element_2(p3, 2, result1, result_length, result2);
	for (size_t i = 0; i < result_length; i++)
	{
		printf("%d\t", result2[i]);
	}
}
// n个
void print_array_cmn_element_n() {
	int p[5][10] = { { 1, 2, 3, 10, 11, 22, 100 }, { 11, 12, 13, 14, 22 }, {  11, 22 }, {11,22}, {11,22} };
	int	* result_temp,
		* result = (int *)malloc(4*10);

	int result_length = 10;
	int i = 0;
	
	result_temp = *(p + 1);

	while(i < 5)
	{
		result_length = array_cmn_element_2(*(p + i), 10, result_temp, result_length, result);
		result_temp = result;
		i++;
	}
	for (size_t i = 0; i < result_length; i++)
	{
		printf("result[%d]=%d\t", i, result[i]);
	}
}
void array_cmn_element_call() {
	int p1[] = { 1, 2, 3, 10, 11, 22, 100 };
	int p2[] = { 11, 12, 13, 14, 22 };
	int result [100];
	//array_cmn_element_2(p1, 6,p2, 5, result);
	//print_array_cmn_element_3();
	print_array_cmn_element_n();
}

