#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//Calculator_v1.c
//
//Created : 2021-04-28
//Author : ��ȫ��
int main()
{
	int a, b, res;
	char cal;

	printf("ù��° �� �Է��ϼ��� : ");
	scanf("%d", &a);

	printf("�ι�° �� �Է��ϼ��� : ");
	scanf("%d", &b);
	getchar();

	printf("���ϴ� ������ �Է��ϼ��� : ");
	scanf("%c", &cal);

	if (cal == '+')
	{
		res = a + b;
		printf("��� ����� : %d�Դϴ�.", res);
	}
	else if (cal == '-')
	{
		res = a - b;
		printf("��� ����� : %d�Դϴ�.", res);
	}
	else if (cal == '*')
	{
		res = a * b;
		printf("��� ����� : %d�Դϴ�.", res);
	}
	else if (cal == '/')
	{
		res = a / b;
		printf("��� ����� : %d�Դϴ�.", res);
	}

	return 0;
}