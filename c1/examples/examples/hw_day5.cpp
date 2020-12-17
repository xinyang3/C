#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void chars_cat(char * c) {
	char result1[100] = {0};
	char result2[100] = {0 };

	int i = 0, j = 0;
	int index = 0;
	while (c[index] != '\0')
	{
		if (c[index] >= '0' && c[index] <= '9') {
			result1[i++] = c[index];
		}
		else if (c[index] >= 'a' && c[index] <= 'z'){
			result2[j++] = c[index];
		}
		index++;
	}
	strcat(result1, result2);
	printf("%s\n", result1);
}

void chars_replace(char * c) {
	char s[] = "%020";
	
	char result[200] = {0};
	int i = 0, j = 0;

	while (c[i] != '\0') {
		if (c[i] != ' ') {
			result[j++] = c[i];
		}
		else if (c[i] == ' ') {
			strcat(result, s); // 此处自动加了32个字节
			j += 4;
		}
		i++;
	}
	printf("%s\n", result);
}

// 3.删除字符串中指定的字符。 例如 “abcdaefaghiagkl“ 删除‘a’,以后： “bcdefghigkl”
void del_asome_str(char * s, char c, char * result) {
	int j = 0;

	int i = 0;
	while (*(s + i) != '\0') {
		if (*(s + i) != c) {
			*(result + j) = *(s + i);
			j++;
		}
		i++;
	}
	printf("\n");
}

// 4.删除一个数组中重复的元素。例如 1 ,2, 2,2,3,3,3,4,4,5,5,5,6,6,6 
void del_repeat_elem(int * array, int length, int * result) {
	int count = 0;
	
	for (size_t i = 0; i < length; i++)
	{
		bool hastr = false;
		for (size_t j = 0; j < count; j++) {
			if (array[i] == result[j]) {
				hastr = true;
				break;
			}
		}
		if (!hastr) {
			result[count] = array[i];
			count++;
		}
	}
}

// 5.将 字 符 串 中 的 相 邻 的 多 余 空 格 去 掉 ， 
// 例 如 （空 格 用 下 划 线 表”___hello____world___how_are_you__” ->”hello_world_how_are_you”
void del_repeat_space(char * s, char * rs) {
	int i = 0, j = 0;
	while (s[i] != '\0') {
		if (s[i] == ' ') {
			if (j > 0 && rs[j-1] != ' ') {
				rs[j] = s[i];
				j++;
			}
		}
		else {
			rs[j] = s[i];
			j++;
		}
		i++;
	}
}

// 求一个字符串数组的最大值和次大值  void big(char *arr[],int size ,char** big1,char** big2)
void big(char *arr[], int size, char** big1, char** big2) {
	
	*big1 = *arr;
	*big2 = *arr;

	for (size_t i = 1; i < size; i++)
	{
		int rs = strcmp(*(arr + i), *big1);
		if (rs > 0) {
			*big1 = *(arr + i);
		}
		else {
			rs = strcmp(*(arr + i), *big2);
			if (rs > 0) {
				*big2 = *(arr + i);
			}
		}
	}
}

void chars_test() {
	//char s[100] = {};
	/*char c = '\0';

	int i = 0;
	while (scanf("%c", &c) != EOF) {
		s[i++] = c;
	}
	s[i] = '\0';
	printf("%s\n", s);*/

	//chars_cat(s);

	/*char s[100] = {0};
	gets_s(s);
	printf("%s\n", s);*/

	//chars_replace(s);
	//char result[100] = { 0 };
	//del_asome_str(s, 'a', result);

	/*int array[] = { 1 ,2, 2,2,3,3,3,4,4,5,5,5,6,6,6 };
	int result[100] = {0};

	del_repeat_elem(array, sizeof(array) / sizeof(int), result);*/

	/*char rs[100] = { 0 };
	del_repeat_space(s, rs);*/

	char charsb[100][50] = { "acasdawwwwq", "acasdaw1", "amasdaw", "kasdawq", "acasdaw91asd", "acasdawklasdw" };
	char * big1 = (char *) malloc(50 * sizeof(char));
	char * big2 = (char *)malloc(50 * sizeof(char));

	char ** chars = (char **)malloc(50 * 100);
	for (size_t i = 0; i < 6; i++)
	{
		chars[i] = charsb[i];
	}

	char ** cbig1 = &big1;

	big(chars, 6, &big1, &big2);

	puts(big1);
	puts(big2);
}