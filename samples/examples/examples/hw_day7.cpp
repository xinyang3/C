#include <stdio.h>
#include <stdlib.h>

#define STU_LEN  4
typedef struct Student {
	int no;
	char name[20];
	int score1;
	int score2;
	int score3;
	int scores;
	int seq;
	Student * next;
} Student, * pStudent;

typedef struct StudentLink {
	Student * head;
	Student * tail;
} StudentLink,* pStuLink;

// ˳�����
void insert_link_sort(pStuLink pstl, pStudent pstu) {
	//pStudent nplink = (pStudent)calloc(1, sizeof(Student));
	//nplink->data = data;
	pstu->next = NULL;

	pStudent pcur = pstl->head, pre = pstl->head;

	if (!pstl->head) {
		pstl->head = pstu;
		pstl->tail = pstu;
	}
	else if (pstu->no < pstl->head->no) // ͷ�ڵ�֮ǰ����
	{
		pstu->next = pstl->head;
		pstl->head = pstu;
	}
	else if (pstu->no >= pstl->head->no) // ͷ�ڵ�֮��
	{
		while (pcur) // �м�ڵ�
		{
			if (pcur->no > pstu->no) {
				pre->next = pstu;
				pstu->next = pcur;
				break;
			}
			pre = pcur;
			pcur = pcur->next;
		}

		if (!pcur) // �����������β
		{
			pre->next = pstu;
			pstl->tail = pstu;
		}
	}
}

// ˳�����
void print_student_info_asc(pStuLink pstLink) {
	pStudent nhead = pstLink->head;

	while (nhead)
	{	
		printf("no=%d,name=%s,score1=%d,score2=%d,score3=%d,tscore=%d\n", nhead->no, nhead->name, nhead->score1, nhead->score2, nhead->score3, nhead->scores);
		nhead = nhead->next;
	}
}
// ����ѧ�����ѧ��
void print_student_byNo(pStuLink pstLink, int no) {
	pStudent nhead = pstLink->head;
	while (nhead)
	{
		if (nhead->no == no) {
			printf("no=%d,name=%s,score1=%d,score2=%d,score3=%d,tscore=%d\n", nhead->no, nhead->name, nhead->score1, nhead->score2, nhead->score3);
		}
		else {
			nhead = nhead->next;
		}
	}
}
// �����߷�ѧ��
void print_maxScore_student(pStuLink pstLink) {
	pStudent nhead = pstLink->head;
	int no1, maxScore1 = 0;

	while (nhead)
	{
		if (nhead->score1 > maxScore1) {
			maxScore1 = nhead->score1;
			no1 = nhead->no;
		}
		nhead = nhead->next;
	}
	print_student_byNo(pstLink, no1);
}
// ���ƽ����
void print_score_average(pStuLink pstLink) {
	pStudent nhead = pstLink->head;
	int scores = 0;
	while (nhead)
	{
		scores += nhead->score1;
		nhead = nhead->next;
	}
	printf("average_score1=%d\n", scores);
}
void swap2(int * a, int * b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
// �����ܷ����ѧ������
void print_student_byScores(pStuLink pstLink) {
	pStudent nhead = pstLink->head;

	// ����ѧ���ķ���
	int scores[STU_LEN];
	int i = 0;
	while (nhead)
	{
		scores[i] = nhead->scores;
		nhead = nhead->next;
	}
	// �������򰴷�������
	for (size_t i = 0; i < STU_LEN; i++)
	{
		int maxIndex = i;
		for (size_t j = i; j < STU_LEN; j++)
		{
			if (scores[j] > scores[maxIndex]) {
				maxIndex = j;
			}
		}
		swap2(&scores[i], &scores[maxIndex]);
	}
	// ��Ÿ�ֵ
	while (nhead)
	{
		for (size_t i = 0; i < STU_LEN; i++)
		{

			if (nhead->scores == scores[i]) {
				nhead->seq = i+1;
				break;
			}
		}
		nhead = nhead->next;
	}
}
// ˳��¼��ѧ����Ϣ
void student_test() {
	pStuLink pstl = (StudentLink *)malloc(sizeof(StudentLink));
	pstl->head = NULL;
	pstl->tail = NULL;

	int i = 1;
	while (i <= STU_LEN) {
		printf("����ѧ����Ϣ\n");
		pStudent pst = (Student *)malloc(sizeof(Student));
		pst->next = NULL;
		scanf("%d %s %d %d %d", &pst->no, pst->name, &pst->score1, &pst->score2, &pst->score3);
		pst->scores = pst->score1 + pst->score2 + pst->score3;
		// ��ѧ�Ų���
		insert_link_sort(pstl, pst);
		i++;
	}
	// ��ѧ�����
	print_student_info_asc(pstl);
}


void link_tests() {
	student_test();
}