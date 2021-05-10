#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a;
	char b;

	//정수 다음 문자를 입력받는경우
	printf("정수 하나를 입력하세요 : ");
	scanf("%d", &a);
	//getchar(); // 버퍼에 있는 문자하나를 불러옴
	printf("문자 하나를 입력하세요 : ");
	scanf(" %c", &b); // getchar안쓰고 " %c"써도 가능

	printf("입력된 값은 %d, %c 입니다.\n", a, b);
	
	return 0;
}