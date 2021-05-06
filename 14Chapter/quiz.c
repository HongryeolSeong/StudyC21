#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	int flag = 0;
	char str[30];
	int size;
	

	while (1)
	{
		printf("테스트할 단어를 입력하시오. : ");
		scanf("%s", str);
		size = strlen(str);
		printf("배열사이즈는 : %d\n", size);

		char* pa = str;
		char* pb = str + (size - 1);

		for (i = 0; i < size/2; i++)
		{
			if (*pa != *pb)
			{
				flag = -1;
				break;
			}
			else if (*pa == *pb)
			{
				pa++;
				pb--;
			}
			flag = 1;
		}

		if (flag == -1)
		{
			printf("이 단어는 회문이 아닙니다.\n");
		}
		else if (flag == 1)
		{
			printf("이 단어는 회문입니다!!!\n");
		}
	}

	return 0;
}