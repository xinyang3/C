#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void exchange(int * p1, int *p2) {
	int  tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
// 数组的最大值和次大值
void print_array_max(int *p, int size) {
	for (size_t i = 1; i < size; i++)
	{
		if (*(p + i) > p[0]) {
			exchange(p, p + i);
		} else if (*(p + i) > p[1]) {
			exchange(p + 1, p + i);
		}
	}

	printf("max=%d, less-max=%d", p[0], p[1]);
}
// 元素出现次数超过n / 2，求这个元素
void print_array_num_count(int *p, int size) {
	for (size_t i = 0; i < size; i++)
	{
		int count = 1;
		for (size_t j = i +1; j < size; j++)
		{
			if (*(p + i) == *(p + j)) {
				count++;
				if (count > size / 2) {
					printf("number=%d\n", p[i]);
					break;
				}
			}
		}
	}
}
// 数组中的两个元素x和y使得abs(x - y)值最小
void array_abs_small(int * p, int size) {
	int number1, number2, absValue;

	absValue = abs(*(p) - *(p + 1));
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			if (abs(*(p + i) - *(p + j)) < absValue) {
				absValue = abs(*(p + i) - *(p + j));
				number1 = *(p + i);
				number2 = *(p + j);
			}
		}
	}
	printf("abs(%d - %d) = %d", number1, number2, absValue);
}
// 给定含有1001个元素的数组，其中存放了1-1000之内的整数，只有一个整数是重复的，请找出这个数
void array_find_ducpy() {
	int array[1001] = { 100, 200, 101, 1, 3, 4, 5, 80, 200 };
	int result[1001] = { 0 };
	int repeatNumber = -1;
	for (size_t i = 0; i < sizeof(array) / sizeof(int); i++)
	{
		int item = array[i];
		result[item]++;
		if (result[item] > 1) {
			repeatNumber = item;
			break;
		}
	}
	if (repeatNumber > -1) {
		printf("重复的数是%d\n", repeatNumber);
	}

}
void array_test() {
	//int a[10] = { 10, 200, 100, 200, 11, 200, 200 };
	//print_array_max(a, 10);
	//print_array_num_count(a, 7);

	/*int a[10] = { 10, 20, 101, 200, 100, 50, 99 };
	array_abs_small(a, 7);*/
	array_find_ducpy();
}
