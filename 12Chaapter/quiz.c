#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input_lotto(int* pl, int size);
void print_lotto(int* pl, int size);

int main()
{
	int lotto[6];
	int size = sizeof(lotto) / sizeof(lotto[0]);

	input_lotto(lotto, size);
	print_lotto(lotto, size);

	return 0;
}

void input_lotto(int* pl, int size)
{
	int flag = 0;
	int i = 0;
	int j;
	int temp;

	printf("로또 번호 입력 : \n");

	while (i < size)
	{
		scanf("%d", &temp);
		if (i == 0)
		{
			flag = 1;
		}
		else if (i > 0)
		{
			for (j = 0; j < i; j++)
			{
				if (temp == pl[j])
				{
					printf("중복된 숫자를 입력하지 마시오.\n");
					flag = -1;
					break;
				}
				flag = 1;
			}
		}

		if (flag > 0)
		{
			*(pl + i) = temp;
			i++;
		}
	}
}

void print_lotto(int* pl, int size)
{
	int i;

	printf("로또 번호 출력\n");

	for (i = 0; i < size; i++)
	{
		printf("%d ", *(pl + i));
	}
}