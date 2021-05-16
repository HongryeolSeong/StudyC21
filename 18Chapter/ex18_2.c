#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* fp;
	int ch;

	fp = fopen("a.txt", "r"); // 읽기 개방 모드
	if (fp == NULL)
	{
		printf("파일이 열리지 않았습니다.");
		return 1;
	}

	while (1)
	{
		ch = fgetc(fp); // 파일에서 문자 하나씩 읽어오기
		if (ch == EOF) // 더 이상 읽을 문자가 없는 경우
		{
			break;
		}
		putchar(ch); // 버퍼에 저장된 문자를 화면에 출력
	}
	fclose(fp);

	return 0;
}