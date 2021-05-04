#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char ch;
	int i;

	for (i = 0; i < 6; i++)
	{
		// 입력된 문자가 버퍼에 보관된 상태
		scanf("%c", &ch); // 버퍼의 문자를 하나씩 가져옴
		printf("%c", ch);
	}

	return 0;
}