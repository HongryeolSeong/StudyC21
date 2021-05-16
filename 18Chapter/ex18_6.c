#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* fp;
	// 10개의 아스키 문자
	int ary[10] = { 13, 10, 13, 13, 10, 26, 13, 10, 13, 10 };
	int i, res;

	// 아스키 문자들을 바이너리방식으로 a.txt에 출력
	fp = fopen("a.txt", "wb");
	for (i = 0; i < 10; i++)
	{
		fputc(ary[i], fp);
	}
	fclose(fp);

	// a.txt를 텍스트 파일로 읽어오기
	fp = fopen("a.txt", "rt");
	while (1)
	{
		res = fgetc(fp);
		if (res == EOF) break; // 아스키 코드 26 = -1 = EOF = ^Z
		printf("%4d", res);
	}
	fclose(fp);

	return 0;
}