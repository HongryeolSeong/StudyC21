#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, i;

	printf("몇 단 구구단을 실행시키겠습니까? : ");
	scanf("%d", &a);

	if (a > 1 && a < 10)
	{
		for (i = 1; i < 10; i++)
		{
			printf("%d * %d = %d\n", a, i, a * i);
		}
	}
	else
	{
		printf("2 ~ 9 사이의 숫자를 입력하세요.\n");
		main();
	}

	return 0;
}