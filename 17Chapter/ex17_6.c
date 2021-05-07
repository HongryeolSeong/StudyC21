#include <stdio.h>

struct score
{
	int kor;
	int eng;
	int math;
};

int main()
{
	struct score yuni = { 90, 80, 70 };
	struct score* ps = &yuni;

	printf("국어 : %d\n", (*ps).kor); // .연산이 우선 순위이므로 괄호 필수
	printf("영어 : %d\n", ps->eng); // 위와 동
	printf("수학 : %d\n", ps->math);

	return 0;
}