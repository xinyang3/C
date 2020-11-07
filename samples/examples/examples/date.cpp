#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

// 判断闰年
int isRunYear(int year) {
	int rs = 0;
	if ((year % 4 == 0 && year / 100 != 0) || year % 400 == 0) {
		rs = 1;
	}
	return rs;
}
/**
* 获取年的第几天
*/
int getDayOfYear(int year, int month, int day) {
	int days[] = { 31, 28, 31, 30, 31, 30, 31,31, 30, 31, 30, 31 };
	int rdays = 0;
	if (isRunYear(year)) {
		days[1] = 29;
	}

	for (int i = 0; i < month; i++) {
		rdays += days[i];
	}
	rdays += day;
	return rdays;
}

char* getDayOfYear(char * dates) {
	//char date = *dates;
	/*char date[] = "202011107";
	printf("%s", date);*/

	int year = 2020,
		month = 11,
		day = 7;

	int cdays = getDayOfYear(year, month, day);
	printf("today is %d days \n", cdays);
	
	return 0;
}
