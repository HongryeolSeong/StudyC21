#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct profile
{
	char name[20];
	int age;
	double height;
	char* intro;
};

int main()
{
	struct profile yuni;

	strcpy(yuni.name, "서하윤"); // 배열의 경우 이렇게 써야함.
	yuni.age = 17;
	yuni.height = 164.5;

	yuni.intro = (char*)malloc(80);
	printf("자기소개 : ");
	gets(yuni.intro);

	printf("이름 : %s\n", yuni.name);
	printf("나이 : %d\n", yuni.age);
	printf("키 : %.1lf\n", yuni.height);
	printf("자기소개 : %s\n", yuni.intro);
	free(yuni.intro);

	return 0;
}