#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* fp; // 파일 구조체를 가리키는 포인터

	fp = fopen("a.txt", "r"); // 파일 정보가 담긴 스트림 파일의 버퍼의 주소를 담는 fp
	if (fp == NULL) // 파일이 없는 경우 = 주소가 NULL
	{
		printf("파일이 열리지 않았습니다.\n");
		return 1;
	}
	printf("파일이 열렸습니다.\n");
	fclose(fp);

	return 0;
}