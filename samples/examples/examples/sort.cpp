#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SWAP (x, y) {int temp; temp = x; x = y; y = x;}
#define N 10

void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void print(int numbers[]) {
	for (size_t i = 0; i < N; i++)
	{
		printf("%d\t", numbers[i]);
	}
	printf("\n");
}

void sort_maopao(int numbers[]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (numbers[j] > numbers[j + 1]) {
				swap(&numbers[j], &numbers[j+1]);
			}
		}
	}
}

void sort_select(int numbers[]) { // 倒序和正序差别

	int i = 0, j = 0;
	for (i = 0; i < N; i++)
	{
		int position = 0;
		for (j = 0; j < N - i; j++)
		{
			if (numbers[j] > numbers[position]) {
				position = j;
			}
		}
		swap(&numbers[position], &numbers[N- i -1]);
	}
}

//  2 10 8 1 6
void sort_insert(int numbers[]) {

	int insert_value;
	int i;
	for (i = 1; i < N; i ++)
	{
		for (int k = 0; k < i; k++)
		{
			if (numbers[i] < numbers[k]) {  // 找到小于的位置
				insert_value = numbers[i];
				for (size_t j = i; j > k; j --) // 从k位置开始往后挪一位
				{
					numbers[j] = numbers[j-1];
				}
				numbers[k] = insert_value;
				break;
			}
		}
	}
}

void sort() {
	int numbers[N];
	srand(time(NULL));
	for (size_t i = 0; i < N; i++)
	{
		int num =  rand() % 1000;
		numbers[i] = num;
	}
	print(numbers);

	//sort_maopao(numbers);
	//sort_select(numbers);
	sort_insert(numbers);
	print(numbers);
}