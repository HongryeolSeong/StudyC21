#include <stdio.h>

void add_ten(int* pa);

int main()
{
	int a = 10;

	add_ten(&a); // add_ten에 a의 주소를 번달
	printf("a : %d\n", a);

	return 0;
}

void add_ten(int* pa) // main의 a의 주소를 받음
{
	*pa = *pa + 10;
}