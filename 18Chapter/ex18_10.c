#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* fp;
	int age;
	char name[20];

	fp = fopen("a.txt", "r");

	fscanf(fp, "%d", &age);
	while (fgetc(fp) != '\n') {} // 밑의 문제를 해결
	//fgets(name, sizeof(name), fp); // 17"\n"에서 개행 문자가 바로 입력 돼버림
	fscanf(fp, "%s", name);

	printf("나이 : %d, 이름 : %s", age, name);
	fclose(fp);

	return 0;
}