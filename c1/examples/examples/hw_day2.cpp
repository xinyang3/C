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
// 2 -> 10
void convert_jinzhi_2To_10(char * c) {
	int resu = 0;
	int i = 0;
	int length = 0;
	while (c[length] != '\0')
	{
		length++;
	}
	for (int i = length-1; i >= 0; i--)
	{
		resu += (c[i] - '0') * (1 << (length - 1 - i));
	}
	printf("%d", resu);
}

// 4.	统计一个整数对应的二进制数的1的个数。输入一个整数（可正可负）， 输出该整数的二进制包含1的个数
void count_10To_2(int t) {
	int yushu;
	int resu[] = { 0 };

	int count = 0;
	while (t != 0) {
		yushu = t % 2;
		t = t / 2;

		if (yushu == 1) {
			count++;
		}
	}
	printf("%d", count);
}
// 5 (1)有101个整数，其中有50个数出现了两次，1个数出现了一次， 找出出现了一次的那个数。
typedef struct Number {
	int data;
	int count;
} Number, * PNumber;

void count_number() {
	int array[50] = {100, 100, 1};
	Number numbers[2];
	for (size_t i = 0; i < sizeof(array) / sizeof(int); i++)
	{

		for (size_t j = 0; j < 2; j++)
		{
			if (numbers[j].data == array[i]) {
				numbers[j].count++;
			}
			else
			{
				Number num;
				num.count = 1;
				num.data = array[i];
				numbers[j] = num;
			}
		}
	}

	for (size_t i = 0; i < 2; i++)
	{
		if (numbers[i].count == 1) {
			printf("count one = %d", numbers[i].data);
		}
	}
}

void convert_jinzhi() {
	int d;
	while (scanf("%d", &d) != NULL) {
		//convert_jinzhi_10To2(d);
		count_10To_2(d);
	}

	/*char c[] = {'\0'};
	while (scanf("%s", c) != NULL)
	{
		convert_jinzhi_2To_10(c);
	}*/
}