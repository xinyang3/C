#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
	char* name;
	int age;
	int score;
} student, * pstudent;

void struct_test() {
	
	student stu;
	pstudent p;
	p->age;
	stu.age;
}