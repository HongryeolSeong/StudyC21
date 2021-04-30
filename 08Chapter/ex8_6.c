#include <stdio.h>

int main()
{
	char str[80];

	printf("문자열 입력 : ");
	gets(str); // gets : 띄어쓰기 포함된 문자열 입력
	puts("입력된 문자열 : "); // puts : 자동 개행
	puts(str);

	return 0;
}