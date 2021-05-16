#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* fp; // 파일 구조체를 가리키는 포인터

	// 파일 개방
	// fopen()이 파일은 찾는 기본 위치는 "현재 작업 디렉터리"
	fp = fopen("a.txt", "r"); // 파일 정보가 담긴 스트림 파일의 버퍼의 주소를 담는 fp
	if (fp == NULL) // 파일이 없는 경우 = 주소가 NULL
	{
		printf("파일이 열리지 않았습니다.\n");
		return 1; // 프로그램 종료
	}
	printf("파일이 열렸습니다.\n");

	// 파일 폐쇄
	fclose(fp);

	return 0;
}