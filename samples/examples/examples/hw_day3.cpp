#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mystrcpy(char * to, char * from) {
	int i = 0;
	while (from[i] != '\0') {
		to[i] = from[i];
		i++;
	}
	to[i] = '\0';
}

int mystrcmp(char * str1, char * str2) {
	int i = 0;

	int result =0;
	while (str1[i] != '\0') {
		if (str1[i] < str2[i]) {
			result = -1;
			break;
		}
		else if (str1[i] > str2[i]) {
			result = 1;
			break;
		}
		else
		{
			result = 0;
			i++;
		}
	}
	if (result) return result;
	if (str2[i] != '\0') {
		result = -1;
	}
	return result;

}

char * mystrcat(char * str1, char * str2) {
	int str_len = 0;
	while (str1[str_len] != '\0')
	{
		str_len ++;
	}
	int str2_len = 0;
	while (str2[str2_len] != '\0')
	{
		str1[str_len] = str2[str2_len];
		str_len++;
		str2_len++;
	}
	str1[str_len] = '\0';

	return str1;
}

size_t mystrlen(char * str) {
	unsigned int length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return length;
}

void print_word(char * str) {
	int count = 0;
	char flg = 'E'; // E空位 W 单词位
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ') {
			printf("%c", str[i]);
			flg = 'W';
		}
		else {
			if (flg == 'W') {
				printf("\n");
			}
			flg = 'E';
		}
		i ++;
	}
}
size_t word_count(char * str) {
	int count = 0;
	char flg = 'E'; // E空位 W 单词位
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ') {
			if (flg = 'E') {
				count++;
			}
			else {
				flg = 'W';
			}
		}
		else {
			flg = 'E';
		}
		i++;
	}
	return count;
}


void main() {
	char from[100] = "abcde\0";
	char to[] = "abcdef\0";
	/*strcpy(to, from);
	printf("%s", to);*/

	/*int resu = strcmp(from, to);
	printf("%d", resu);*/

	//char * c = strcat(from, to);
	/*char * c = mystrcat(from, to);
	printf("%s", from);*/

	char c[] = "\0";
	scanf("%s\n", c);
	//gets_s(c);
	printf("%d\n", word_count(c));
	print_word(c);

}