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

void sort_maopao(int numbers[]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (numbers[j] > numbers[j + 1]) {
				swap(&numbers[j], &numbers[j+1]);
			}
		}
	}
}


void print(int numbers[]) {
	for (size_t i = 0; i < N; i++)
	{
		printf("%d\t", numbers[i]);
	}
	printf("\n");
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

	sort_maopao(numbers);
	print(numbers);
}