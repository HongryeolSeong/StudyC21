#include <stdio.h>
int a = 10, b = 20; // ���� Ȱ��� ���Ұ��� but ���� ��� ������ ��
void swap();

int main()
{
	//int a = 10, b = 20;
	int temp;

	printf("�ٲ���� a, b : %d, %d\n", a, b);

	swap();

	printf("�ٲ��� a, b : %d, %d\n", a, b);

	return 0;
}

void swap()
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}