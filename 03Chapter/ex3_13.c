#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a;
	char b;

	printf("정수 하나를 입력하세요 : $ ");
	scanf("%d", &a);

	printf("문자 하나를 입력하세요 : $ ");
	scanf(" %c", &b);

	printf("입력된 값은 %d, %c 입니다.\n", a, b);
	
	return 0;
}