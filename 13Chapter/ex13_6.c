#include <stdio.h>

void add_ten(int a);

int main()
{
	int a = 10;

	add_ten(a); // main�� a���� �����Ͽ� add_ten���� ����
	printf("a : %d\n", a);

	return 0;
}

void add_ten(int a) // != main�� a. a�� ���� ���� ����
{
	a = a + 10;
}