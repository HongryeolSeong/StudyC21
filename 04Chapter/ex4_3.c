#include <stdio.h>

int main()
{
	int a = 10;
	int b = 10;
	int c = 10;
	int d = 20;

	++a; // ����
	--b; // ����
	c++; // ���� : ���� �� ���� ó��
	d--; // ����

	printf("a : %d\n", a);
	printf("b : %d\n", b);
	printf("c : %d\n", c);
	printf("d : %d", d);


	return 0;
}