#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

enum season { SPRING, SUMMER, FALL, WINTER };

int main()
{
	enum season ss;
	char* pc = NULL;

	scanf("%d", &ss); // 정수값 입력

	switch (ss)
	{
	case SPRING:
		pc = "inline";
		break;
	case SUMMER:
		pc = "swimming";
		break;
	case FALL:
		pc = "trip";
		break;
	case WINTER:
		pc = "skiing";
		break;
	}

	printf("나의 레저 활동 => %s\n", pc);
	printf("%d %d %d %d\n", SPRING, SUMMER, FALL, WINTER);
	// enum의 멤버는 정수값을 가진다. 이웃 멤버와 +1 관계 가짐
	// if FALL = 100 이면 SUMMER = 1, WINTER = 101 이 된다.

	return 0;
}