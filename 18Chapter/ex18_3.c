#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* fp;
	char str[] = "banana";
	int i;

	// 파일 개방 - 쓰기 모드
	fp = fopen("b.txt", "w"); // b.txt가 없는 경우 새로 만듦
	if (fp == NULL)
	{
		printf("파일을 만들지 못했습니다.\n");
		return 1;
	}

	// 파일에 str 출력
	i = 0;
	while (str[i] != '\0') // 널문자를 만날때 까지
	{
		fputc(str[i], fp); // b.txt에 str을 출력
		i++;
	}
	fputc('\n', fp); // 마지막에 개행 대입
	fclose(fp);

	return 0;
}