#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input_data(int *pn1, int *pn2)
{
	printf("두 정수 입력 : $ ");
	scanf("%d %d", pn1, pn2);
	//num = scanf("%d %d", &n1, &n2); // 초록줄 없애고 싶은경우
}