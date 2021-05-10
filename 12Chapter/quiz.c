#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input_lotto(int* pl, int size);
void print_lotto(int* pl, int size);

int main()
{
	int lotto[6];
	int size = sizeof(lotto) / sizeof(lotto[0]);

	input_lotto(lotto, size);
	printf("\n");
	print_lotto(lotto, size);

	return 0;
}

void input_lotto(int* pl, int size)
{
	int flag = 0;
	int i = 0;
	int j;
	int temp;


	while (i < size)
	{
		printf("로또 번호 입력 : ");
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
					flag = -1; // 중복된 숫자가 있다는 플래그
					break; // for문을 탈출하여 해당 순서의 번호 입력으로 다시 돌아감
				}
				flag = 1; // 중복된 숫자가 없다는 플래그
			}
		}

		if (flag > 0) // 중복된 숫자 없는경우 로또 배열에 번호 입력
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