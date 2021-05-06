#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_stu(int (*pa)[4]);
void print_sub(int (*pa)[4]);

int main()
{
	int score[5][4];
	int i, j;
	char stu = 'A';

	for (i = 0; i < 5; i++)
	{
		printf("%c�� 4���� ���� �Է� : ", stu++);
		for (j = 0; j < 4; j++)
		{
			scanf("%d", &score[i][j]);
		}
	}
	printf("\n");
	print_stu(score);
	printf("\n");
	print_sub(score);

	return 0;
}

void print_stu(int (*pa)[4])
{
	int i, j;
	int total;
	double avg;
	char stu = 'A';

	for (i = 0; i < 5; i++)
	{
		total = 0;
		for (j = 0; j < 4; j++)
		{
			total += pa[i][j];
		}
		avg = total / 4.0;
		printf("%c�� �� ���� : %d, ��� : %.1lf\n", stu, total, avg);
		stu++;
	}
}

void print_sub(int (*pa)[4])
{
	int i, j;
	int total;
	double avg;

	for (j = 0; j < 4; j++)
	{
		total = 0;

		for (i = 0; i < 5; i++)
		{
			total += pa[i][j];
		}

		avg = total / 5.0;

		printf("%d���� �� ���� : %d, ��� : %.1lf\n", j + 1, total, avg);
	}
}