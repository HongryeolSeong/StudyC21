#include <stdio.h>

struct student // �޸� �Ҵ�x
{
	int num;
	double grade;
}; // ;�ʼ�

int main()
{
	struct student s1; // ���� ���� ���ÿ� �޸� �Ҵ��

	s1.num = 2;
	s1.grade = 2.7;
	printf("�й� : %d\n", s1.num);
	printf("���� : %.1lf\n", s1.grade);

	return 0;
}