#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void func(int (*fp)(int, int));
int sum(int a, int b);
int minus(int a, int b);
int multi(int a, int b);

int main()
{
	char sel;

	printf("'+' 두 정수의 합\n");
	printf("'-' 두 정수의 차\n");
	printf("'*' 두 정수의 곱\n");
	printf("원하는 연산을 선택하세요 : ");
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

	printf("두 정수의 값을 입력하세요 : ");
	scanf("%d%d", &a, &b);
	res = fp(a, b);
	printf("결괏값은 : %d\n", res);
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
