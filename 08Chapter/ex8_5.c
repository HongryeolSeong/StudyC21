#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[80] = "cat";
	char str2[80];

	strcpy(str1, "tiger"); // strcpy(복사결과, 복사대상)
	strcpy(str2, str1); // 보완한 함수 strcpy_s 복사 범위 벗어나면 복사x
	printf("%s, %s\n", str1, str2);

	return 0;
}