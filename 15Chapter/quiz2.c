#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void func(int (*fp)(int, int));
int sum(int a, int b);
int minus(int a, int b);
int multi(int a, int b);

int main()
{
	char sel;

	printf("'+' �� ������ ��\n");
	printf("'-' �� ������ ��\n");
	printf("'*' �� ������ ��\n");
	printf("���ϴ� ������ �����ϼ��� : ");
	scanf("%c", &sel);

	switch (sel)
	{
	case '+': func(sum); break;
	case '-': func(minus); break;
	case '*': func(multi); break;
	}

	return 0;
}

void func(int (*fp)(int, int))
{
	int a, b;
	int res;

	printf("�� ������ ���� �Է��ϼ��� : ");
	scanf("%d%d", &a, &b);
	res = fp(a, b);
	printf("�ᱣ���� : %d\n", res);
}

int sum(int a, int b)
{
	return (a + b);
}

int minus(int a, int b)
{
	return (a - b);
}

int multi(int a, int b)
{
	return (a * b);
}
