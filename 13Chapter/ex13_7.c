#include <stdio.h>

void add_ten(int* pa);

int main()
{
	int a = 10;

	add_ten(&a); // add_ten�� a�� �ּҸ� ����
	printf("a : %d\n", a);

	return 0;
}

void add_ten(int* pa) // main�� a�� �ּҸ� ����
{
	*pa = *pa + 10;
}