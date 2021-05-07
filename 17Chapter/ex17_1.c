#include <stdio.h>

struct student // 메모리 할당x
{
	int num;
	double grade;
}; // ;필수

int main()
{
	struct student s1; // 변수 생성 동시에 메모리 할당됨

	s1.num = 2;
	s1.grade = 2.7;
	printf("학번 : %d\n", s1.num);
	printf("학점 : %.1lf\n", s1.grade);

	return 0;
}