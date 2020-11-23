#include <stdio.h>
#include <stdlib.h>

// 从键盘上输入字符，将小写字母转换成大写字母。输入“ctl + z” 结束
void convert_letter() {
	char c;
	while (scanf("%c", &c) != NULL) {
		printf("%c", c - 32);
	}
}


int number_max(int x, int y) {
	return x > y ? x : y;
}
// 1 空 max-number
void character_count_bar(int count_letter, int count_numer, int count_other) {
	int max;
	max = number_max(count_letter, count_numer);
	max = number_max(max, count_other);

	for (size_t i = 0; i < max + 1; i++)
	{
		if (i < max - count_letter) {
			printf("     \t");
		}
		else if (i == max - count_letter) {
			printf("%d\t", count_letter);
		} else {
			
			printf("*****\t");
		}

		if (i < max - count_numer) {
			printf("     \t");
		}else if (i == max - count_numer) {
			printf("%d\t", count_numer);
		}else
		{
			printf("*****\t");
		}

		if (i < max - count_other) {
			printf("     \t");
		}
		else if (i == max - count_other) {
			printf("%d\t", count_other);
		}else
		{
			printf("*****\t");
		}
		printf("\n");
	}
	printf("letter\tnumber\tother\t");
}

//2.	从键盘上输入字符，（1）分别统计一下其中字母，数字，其他字符的个数，
//（2）将统计的字母，数字，其他字符的个数以柱状图的形式打印
void character_count() {
	char c[] = "";

	scanf("%s", c);

	int count_letter = 0,
		count_numer = 0,
		count_other = 0;

	int i = 0;
	while (c[i] != '\0')
	{
		if (c[i] >= 65 && c[i] <= 90 || c[i] >= 97 && c[i] <= 122) {
			count_letter++;
		}
		else if (c[i] >= 48 && c[i] <= 57)
		{
			count_numer++;
		}
		else {
			count_other++;
		}

		i++;
	}
	printf("letter=%d, number=%d, other=%d\n", count_letter, count_numer, count_other);

	character_count_bar(count_letter, count_numer, count_other);
}

void convert_jinzhi_10To2(int t) {
	int yushu, resu[] = { 0 };

	int i = 0;
	while (t != 0) {
		yushu = t % 2;
		t = t / 2;

		resu[i] = yushu;
		i++;
	}

	i--;
	while (i >= 0) {
		printf("%d", resu[i]);
	}

}
void convert_jinzhi() {
	int d;
	while (scanf("%d", &d) != NULL) {
		convert_jinzhi_10To2(d);
	}
}