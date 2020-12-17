#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int m = 0, n = 0;
int trace[MAX][2] = {};

void print_trace(int trace[][2], int index) {
	for (size_t i = 0; i < index; i++)
	{
		printf("(%d,%d)->", trace[i][0], trace[i][1]);
	}
	printf("\n");
}

void run(int x, int y, int index, int * count) {
	
	trace[index][0] = x;
	trace[index][1] = y;
	index++;

	if (x == m && y == n) {
		(*count)++;
		print_trace(trace, index);
		return;
	}

	if (x < m) {
		run(x + 1, y, index, count); // 递归中改递归方法运行完成在运行下面的
	}
	if (y < n) {
		run(x, y + 1, index, count);
	}

	
}

void zuobiao_test() {
	int trace[100][2] = {};
	int count = 0;
	int t_length = 0;
	printf("输入m, n");
	while (scanf("%d %d", &m, &n) != EOF) {
		trace[MAX][2] = {};
		count = 0;

		run(0, 0, t_length, &count);
		printf("路径条数%d", count);
	}

}

