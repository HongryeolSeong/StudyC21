#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char ch1, ch2;
	
	while (1)
	{
		printf("영문자 하나 입력하세요 : ");
		scanf(" %c", &ch1);

		if (ch1 >= 'a' && ch1 <= 'z')
		{
			ch2 = ch1 - 32;
			printf("대문자 변환 결과는 : %c", ch2);
		}
		else if (ch1 >= 'A' && ch1 <= 'Z')
		{
			ch2 = ch1 + 32;
			printf("소문자 변환 결과는 : %c", ch2);
		}
		else
		{
			printf("오류 : 영문자를 입력하세요.\n");
		}
		printf("\n");
		printf("\n");
	}

	

	return 0;
}