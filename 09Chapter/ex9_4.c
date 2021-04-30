#include <stdio.h>

int main()
{
	int a = 10, b = 20;
	const int* pa = &a; // 포인터가 가리키는 곳의 데이터를 상수화, pa 간접참조로 a값 못 바꾸게하는 기능
	int* const pb = &b; // 포인터 자체가 상수화

	printf("변수 a 값 : %d\n", *pa);
	pa = &b;
	printf("변수 b 값 : %d\n", *pa);
	pa = &a;
	a = 20;
	printf("변수의 a 값 : %d\n", *pa);
	//*pa = 30; // 불가
	//printf("변수의 a 값 : %d\n", *pa);
	*pb = 10;
	printf("변수 b 값 : %d\n", *pb);
	//pb = &a; // 불가

	return 0;
}