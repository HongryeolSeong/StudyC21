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
		printf("���ϴ� �޴� �����ϼ���.");
		scanf(" %c", &cal);

		switch (cal)
		{
		case '+':
			res = sum();
			printf("����� : %d", res);
			break;
		case '-':
			res = minus();
			printf("����� : %d", res);
			break;
		case '*':
			res = multi();
			printf("����� : %d", res);
			break;
		case '/':
			res = divi();
			printf("����� : %d", res);
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
		printf("������ ���� 0�� �Ǹ� �ȵ˴ϴ�.\n");
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

	printf("ù ��° ���ڸ� �Է��ϼ��� : ");
	scanf("%d", &a);
		
	return a;
}

int value2()
{
	int b;
	
	printf("�� ��° ���ڸ� �Է��ϼ��� : ");
	scanf("%d", &b);

	return b;
}