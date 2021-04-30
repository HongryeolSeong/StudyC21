#include <stdio.h>
int a = 10, b = 20; // 전역 활용시 스왑가능 but 전역 사용 지양할 것
void swap();

int main()
{
	//int a = 10, b = 20;
	int temp;

	printf("바뀌기전 a, b : %d, %d\n", a, b);

	swap();

	printf("바뀐후 a, b : %d, %d\n", a, b);

	return 0;
}

void swap()
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}