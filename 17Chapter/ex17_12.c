#include <stdio.h>

//struct student
//{
//	int num;
//	double grade;
//};
//typedef struct student Student; // 구조체, 공용체, 열거형 사용시 예약어를 간소화 가능

// 더 간편한 버전
typedef struct {
	int num;
	double grade;
}Student;

void print_data(Student* ps);

int main()
{
	Student s1 = { 315, 4.2 };

	print_data(&s1);

	return 0;
}

void print_data(Student* ps)
{
	printf("학번 : %d\n", ps->num);
	printf("학점 : %.1lf\n", ps->grade);
}