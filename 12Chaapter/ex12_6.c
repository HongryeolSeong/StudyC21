#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
	int age;
	char name[20];

	printf("���� �Է� : ");
	scanf("%d", &age);
	fgetc(stdin); // getchar(); = scanf("%*c");
	printf("�̸� �Է� : ");
	gets(name);
	printf("���� : %d, �̸� : %s\n", age, name);

	return 0;
}