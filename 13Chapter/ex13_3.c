#include <stdio.h>

void assign10();
void assign20();

int a;

int main()
{
	printf("함수 호출 전 a 값 : %d\n", a);

	assign10();
	assign20();

	printf("함수 호출 후 a 값 : %d\n", a);

	return 0;
}

void assign10()
{
	// 전역변수 a에 접근하여 값 10을 입력
	a = 10;
}

void assign20()
{
	// 전역변수 a에 영향 못 미침
	int a;

	a = 20;
}