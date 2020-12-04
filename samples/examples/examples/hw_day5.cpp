#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* chars_cat(char * c) {
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
	return strcat(result1, result2);
}

// 有疑问
char * chars_replace(char * c) {
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
	result[j] = '\0';
	return result;
}


void chars_test() {
	char s[100] = { "hellowa123aaa12aaa\0" };
	/*char c = '\0';

	int i = 0;
	while (scanf("%c", &c) != EOF) {
		s[i++] = c;
	}
	s[i] = '\0';
	printf("%s\n", s);*/

	//char *resu = chars_replace(s);
	
	char * resu = chars_cat(s);

	printf("%s\n", resu);
}