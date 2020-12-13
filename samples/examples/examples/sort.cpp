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

void sort_select(int numbers[]) { // �����������

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
			if (numbers[i] < numbers[k]) {  // �ҵ�С�ڵ�λ��
				insert_value = numbers[i];
				for (size_t j = i; j > k; j --) // ��kλ�ÿ�ʼ����Ųһλ
				{
					numbers[j] = numbers[j-1];
				}
				numbers[k] = insert_value;
				break;
			}
		}
	}
}

// 找到轴点
int partition(int A[], int low, int high) {
	int pivot = A[low]; // 随机选取一个当作轴点
	while (low < high) { // 相等时退出
		while (high > low && A[high] > pivot)
		{
			--high;
		}
		A[low] = A[high];
		while (low < high && A[low] < pivot) {
			++low;
		}
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}
// 快排递归
void sort_quick(int A[], int low, int high) {
	if (low < high) {
		int pivotPros = partition(A, low, high);
		sort_quick(A, low, pivotPros - 1);
		sort_quick(A, pivotPros + 1, high);
	}
}

void heapSortAdjust(int A[], int k, int length) {
	int fa = k;
	int son = 2 * k + 1;
	while (son < length) {
		if (A[son < length && son] < A[son + 1]) {
			son++;
		}
		if (A[fa] > A[son]) break; // 父节点最大
		else {
			swap(&A[fa], &A[son]);
			fa = son;
			son *= 2;
		}
	}
}

void sort_heap(int A[], int length) {
	// 调为大堆
	for (int i = length / 2; i >= 0; i--) {
		heapSortAdjust(A, i, length);
	}
	for (int i = N - 1; i > 0; i--) {
		swap(&A[0], &A[i]); // 最大的摘除放在最后
		heapSortAdjust(A, 0, i - 1); // 对第一个重新调整为堆
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
	//sort_quick(numbers, 0, N - 1);
	sort_heap(numbers, N);
	print(numbers);
}