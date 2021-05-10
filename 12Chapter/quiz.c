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
		printf("�ζ� ��ȣ �Է� : ");
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
					printf("�ߺ��� ���ڸ� �Է����� ���ÿ�.\n");
					flag = -1; // �ߺ��� ���ڰ� �ִٴ� �÷���
					break; // for���� Ż���Ͽ� �ش� ������ ��ȣ �Է����� �ٽ� ���ư�
				}
				flag = 1; // �ߺ��� ���ڰ� ���ٴ� �÷���
			}
		}

		if (flag > 0) // �ߺ��� ���� ���°�� �ζ� �迭�� ��ȣ �Է�
		{
			*(pl + i) = temp;
			i++;
		}
	}
}

void print_lotto(int* pl, int size)
{
	int i;

	printf("�ζ� ��ȣ ���\n");

	for (i = 0; i < size; i++)
	{
		printf("%d ", *(pl + i));
	}
}