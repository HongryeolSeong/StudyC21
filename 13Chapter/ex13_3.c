#include <stdio.h>

void assign10();
void assign20();

int a;

int main()
{
	printf("�Լ� ȣ�� �� a �� : %d\n", a);

	assign10();
	assign20();

	printf("�Լ� ȣ�� �� a �� : %d\n", a);

	return 0;
}

void assign10()
{
	// �������� a�� �����Ͽ� �� 10�� �Է�
	a = 10;
}

void assign20()
{
	// �������� a�� ���� �� ��ħ
	int a;

	a = 20;
}