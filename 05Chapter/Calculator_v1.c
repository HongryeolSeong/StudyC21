#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//Calculator_v1.c
//
//Created : 2021-04-28
//Author : 성홍렬
int main()
{
	int a, b, res;
	char cal;

	printf("첫번째 값 입력하세요 : ");
	scanf("%d", &a);

	printf("두번째 값 입력하세요 : ");
	scanf("%d", &b);
	getchar();

	printf("원하는 연산을 입력하세요 : ");
	scanf("%c", &cal);

	if (cal == '+')
	{
		res = a + b;
		printf("계산 결과는 : %d입니다.", res);
	}
	else if (cal == '-')
	{
		res = a - b;
		printf("계산 결과는 : %d입니다.", res);
	}
	else if (cal == '*')
	{
		res = a * b;
		printf("계산 결과는 : %d입니다.", res);
	}
	else if (cal == '/')
	{
		res = a / b;
		printf("계산 결과는 : %d입니다.", res);
	}

	return 0;
}