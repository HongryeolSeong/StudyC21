#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

enum season { SPRING, SUMMER, FALL, WINTER };

int main()
{
	enum season ss;
	char* pc = NULL;

	scanf("%d", &ss); // ������ �Է�

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

	printf("���� ���� Ȱ�� => %s\n", pc);
	printf("%d %d %d %d\n", SPRING, SUMMER, FALL, WINTER);
	// enum�� ����� �������� ������. �̿� ����� +1 ���� ����
	// if FALL = 100 �̸� SUMMER = 1, WINTER = 101 �� �ȴ�.

	return 0;
}