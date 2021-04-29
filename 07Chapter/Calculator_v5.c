#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum();
int minus();
int multi();
int divi();
int value1();
int value2();

int main()
{
	int res;
	char cal;

	while (1)
	{
		printf("원하는 메뉴 선택하세요.");
		scanf(" %c", &cal);

		switch (cal)
		{
		case '+':
			res = sum();
			printf("결과는 : %d", res);
			break;
		case '-':
			res = minus();
			printf("결과는 : %d", res);
			break;
		case '*':
			res = multi();
			printf("결과는 : %d", res);
			break;
		case '/':
			res = divi();
			printf("결과는 : %d", res);
			break;
		case 'q':
			exit(1);
		default:
			break;
		}

		printf("\n");

	}
	
	return 0;
}

int sum()
{
	int a, b, res;

	a = value1();
	b = value2();

	res = a + b;

	return res;
}

int minus()
{
	int a, b, res;

	a = value1();
	b = value2();

	res = a - b;

	return res;
}

int multi()
{
	int a, b, res;

	a = value1();
	b = value2();

	res = a * b;

	return res;
}

int divi()
{
	int a, b;
	int res = 0;

	a = value1();
	b = value2();

	if (b == 0)
	{
		printf("나누는 수는 0이 되면 안됩니다.\n");
	}
	else
	{
		res = a / b;
	}

	return res;
}

int value1()
{
	int a;

	printf("첫 번째 숫자를 입력하세요 : ");
	scanf("%d", &a);
		
	return a;
}

int value2()
{
	int b;
	
	printf("두 번째 숫자를 입력하세요 : ");
	scanf("%d", &b);

	return b;
}