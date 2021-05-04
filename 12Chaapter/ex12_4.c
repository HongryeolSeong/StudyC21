#include <stdio.h>

int main()
{
	char str[80];

	printf("공백이 포함된 문자열 입력 : ");
	gets(str); // 공백 포함된 문자열 입력 가능
	printf("입력한 문자열은 %s입니다.", str);

	return 0;
}